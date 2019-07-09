#include "UR3Intermediator.h"
#include <QtGlobal>
#include <QtCore>
#include <QtEndian>
#include <QHostAddress>
#include <QDebug>
#include "UR3Message.h"
#include <stdlib.h>
#include <libkern/OSByteOrder.h>

char *strdup (const char *s)
{
    char* d = (char*)malloc(strlen (s) + 1);   // Space for length plus nul
    if (d == NULL) return NULL;          // No memory
    strcpy (d,s);                        // Copy the characters
    return d;                            // Return the new string
}

static double bytesSwap(double v)
{
    union {
        uint64_t i;
        double d;
    } conv;
    conv.d = v;
#ifndef __apple__
    conv.i = OSSwapInt32(conv.i);
#else
    conv.i = htole64(conv.i);
#endif
    return conv.d;

}
static double RoundDouble(double val,int prec)
{
    auto precision = pow(10,prec);
    return round(val * precision) / precision;
}

void UR3Intermediator::MoveToPoint(QVector<double> q, double JointAcceleration, double JointSpeed)
{
    //TODO: nie dziala, zla logika

    CartesianInfoData CurrentCartesianInfo = this->ActualRobotInfo.getCartesianInfoData();
    double x = RoundDouble(CurrentCartesianInfo.getX(),4);
    double y = RoundDouble(CurrentCartesianInfo.getY(),4);
    double z = RoundDouble(CurrentCartesianInfo.getZ(),4);
    double rx = RoundDouble(CurrentCartesianInfo.getRx(),4);
    double ry = RoundDouble(CurrentCartesianInfo.getRy(),4);
    double rz = RoundDouble(CurrentCartesianInfo.getRz(),4);

    QVector<double> cord = QVector<double>({x+(q[0]/1000.0),y+(q[1]/1000.0),z+(q[2]/1000.0),rx,ry,rz});
    MoveL(cord);
}

void UR3Intermediator::MoveJ(QVector<double> JointPosition, double JointAcceleration, double JointSpeed)
{
   // if(_running == true) qDebug()<<"rusza sie";
    CheckIfStillMovejRunning();
    if(_connected && _running==false)
    {
        //TODO :: ZAMIEN NA STRING PARAMETRY PRZEKAZYWANE W FUNKCJI

        QString test = "movej([-0.1, -1.66, 1.71, -1.62, -1.56, 1.19], a=1.0, v=0.1)\n";

        QString command = "movej([" +
                QString::number(JointPosition[0]) + ", " +
                QString::number(JointPosition[1]) + ", " +
                QString::number(JointPosition[2]) + ", " +
                QString::number(JointPosition[3]) + ", " +
                QString::number(JointPosition[4]) + ", " +
                QString::number(JointPosition[5]) + "], " +
                "a=" + QString::number(JointAcceleration)+ ", " +
                "v=" + QString::number(JointSpeed)+ ")\n";

        _socket->write(command.toLatin1().data());
        _socket->waitForBytesWritten();
        _running = true;
        _moveJTargetPos = JointPosition;
        //qDebug()<<"zaczynam ruch";
    }
}

void UR3Intermediator::SpeedJ(QVector<double> qd, double a, double t)
{
    QString command = "speedj([" +
            QString::number(qd[0]) + ", " +
            QString::number(qd[1]) + ", " +
            QString::number(qd[2]) + ", " +
            QString::number(qd[3]) + ", " +
            QString::number(qd[4]) + ", " +
            QString::number(qd[5]) + "], " +
            "a=" + QString::number(a)+ ", " +
            "t=" + QString::number(t)+ ")\n";

    _socket->write(command.toLatin1().data());
    _socket->waitForBytesWritten();

}

void UR3Intermediator::SpeedL(QVector<double> qd, double a, double t)
{QString command = "speedl([" +
            QString::number(qd[0]) + ", " +
            QString::number(qd[1]) + ", " +
            QString::number(qd[2]) + ", " +
            QString::number(qd[3]) + ", " +
            QString::number(qd[4]) + ", " +
            QString::number(qd[5]) + "], " +
            "a=" + QString::number(a)+ ", " +
            "t=" + QString::number(t)+ ")\n";

    _socket->write(command.toLatin1().data());
    _socket->waitForBytesWritten();

}

void UR3Intermediator::SamuraiCut()
{
    MoveJ(QVector<double>({.0,-1.5708,.0,-1.5708,.0,.0}),2.0);
    MoveJ(QVector<double>({1.5962,0,.0,-1.5708,.0,.0}),2.0);
}
position UR3Intermediator::Save()
{
position s;
       CartesianInfoData CurrentCartesianInfo = this->ActualRobotInfo.getCartesianInfoData();

    s.x=(RoundDouble(CurrentCartesianInfo.getX(),4));
    s.y=(RoundDouble(CurrentCartesianInfo.getY(),4));
    s.z=(RoundDouble(CurrentCartesianInfo.getZ(),4));
//    s.push_back(RoundDouble(CurrentCartesianInfo.getRx(),4));
//    s.push_back(RoundDouble(CurrentCartesianInfo.getRy(),4));
//    s.push_back(RoundDouble(CurrentCartesianInfo.getRz(),4));
    return s;
}
void UR3Intermediator::DrawArea(QVector<position>s)
{

    qDebug()<<"Narożnik : "<<s[0].x << ","<<s[0].y<<","<<s[0].z;
    qDebug()<<"Narożnik : "<<s[1].x << ","<<s[1].y<<","<<s[1].z;
    qDebug()<<"Narożnik : "<<s[2].x << ","<<s[2].y<<","<<s[2].z;
    double length=s[0].x-s[1].x;
    double lewa,prawa,przod,tyl,poziom;
    double krawedz=length/8;;
    map<std::string, position>pola;char a = 65;string pole;
    for(int i=0; i<8;i++){
        int n = 1;

        for(int j=0; j<8;j++){
            pole = a + std::to_string(n);
            pola[pole].x =s[0].x+j*krawedz+krawedz/2;
            pola[pole].y =s[0].y+i*krawedz+krawedz/2;
            pola[pole].z =s[0].z;
            n++;

        } a++;
    }


}



void UR3Intermediator::Home()
{
    MoveJ(QVector<double>({.0,-1.5708,.0,-1.5708,.0,.0}));
}


void UR3Intermediator::MoveL(QVector<double> TargetPose, double toolAcceleration, double toolSpeed, double time, double blendRadius)
{
    if(_connected && !_running)
    {
        //TODO :: ZAMIEN NA STRING PARAMETRY PRZEKAZYWANE W FUNKCJI, PRZETESTOWAC NA PRAWIDLOWYCH PZYCJACH


        QString command = "movel([" +
                QString::number(TargetPose[0]) + ", " +
                QString::number(TargetPose[1]) + ", " +
                QString::number(TargetPose[2]) + ", " +
                QString::number(TargetPose[3]) + ", " +
                QString::number(TargetPose[4]) + ", " +
                QString::number(TargetPose[5]) + "], " +
                "a=" + QString::number(toolAcceleration)+ ", " +
                "v=" + QString::number(toolSpeed)+ ", " +
                "t=" + QString::number(time)+", "+
                "r=" + QString::number(blendRadius)+
                ")\n";

        _socket->write(command.toLatin1().data());
        _socket->waitForBytesWritten();
        _moveLTargetPose = TargetPose;
        _running = true;
    }

}

UR3Intermediator::UR3Intermediator():_connected(false), _running(false),Port(30002),IpAddress("192.168.43.139")
{
    this->_socket = new QTcpSocket();
    this->_lastJointPos.resize(6);
    this->_lastJointPos.fill(.0);
    this->_lastPolozenie.resize(6);
    this->_lastPolozenie.fill(.0);

    connect(this->_socket,SIGNAL(readyRead()),this,SLOT(OnSocketNewBytesWritten()));
    connect(this->_socket,SIGNAL(disconnected()),this,SLOT(disconnected()));

}

UR3Intermediator::UR3Intermediator(QString ipAddress, int port):_connected(false), _running(false),Port(port),IpAddress(ipAddress)
{
    this->_socket = new QTcpSocket();
    this->_lastJointPos.resize(6);
    this->_lastJointPos.fill(.0);
    this->_lastPolozenie.resize(6);
    this->_lastPolozenie.fill(.0);

    connect(this->_socket,SIGNAL(readyRead()),this,SLOT(OnSocketNewBytesWritten()));
    connect(this->_socket,SIGNAL(disconnected()),this,SLOT(disconnected()));

}

int UR3Intermediator::getPort() const
{
    return Port;
}

void UR3Intermediator::setPort(int value)
{
    Port = value;
}

QString UR3Intermediator::getIpAddress() const
{
    return IpAddress;
}

void UR3Intermediator::setIpAddress(const QString &value)
{
    IpAddress = value;
}

void UR3Intermediator::GetRobotData()
{
    int32_t size = 0;
    unsigned int offset = 0;
    if(mutex.tryLock())
    {

        //qDebug()<<_DataFlow.data();
        _data = _DataFlow.data();
        memcpy(&size, &_data[offset], sizeof(size));
       // qDebug()<<"Message received of size: "<<_DataFlow.size() << " - "<<_OSSwapInt32(size);
        //if(size==0 || size > 4096) {
         //   _DataFlow.clear();
         //   return;
        //}
#ifndef __apple__
        size = _OSSwapInt32(size);
#else
        size = _byteswap_ulong(size);
#endif

        if(_DataFlow.size()<size)
        {
            mutex.unlock();
            return;
        }

        offset += sizeof(size);
        while(offset<size)
        {
            unsigned char Type;
            memcpy(&Type,&_data[offset],sizeof(Type));
            offset+=sizeof(Type);
            int messageType = Type;
            switch(messageType)
            {
            case ROBOT_MESSAGE:
            {

                break;
            }
            case ROBOT_STATE:
            {
               // qDebug()<<"ROBOT_STATE";
                GetRobotMessage(_data, offset, size);
                break;
            }
            case PROGRAM_STATE_MESSAGE:
            {
                break;
            }

            default:
                offset = size;
                break;
            }

        }
        _DataFlow = _DataFlow.mid(size);
        //MoveJ(QVector<double>({-0.5, -1.26, 1.21, -1.12, -1.76, 1.09}));
      //  qDebug()<<this->ActualRobotInfo.robotModeData.getIsProgramRunning()<<" joint state:"<<this->ActualRobotInfo.jointsData[0].getJointMode();
                /*qDebug()<<this->ActualRobotInfo.cartesianInfoData.getY();
                qDebug()<<this->ActualRobotInfo.cartesianInfoData.getZ();

                qDebug()<<this->ActualRobotInfo.cartesianInfoData.getRx();
                qDebug()<<this->ActualRobotInfo.cartesianInfoData.getRy();
                qDebug()<<this->ActualRobotInfo.cartesianInfoData.getRz();*/
        //MoveL(QVector<double>({-255.0,-194,630.0,0.5,1.9,-1.9}));


        mutex.unlock();
    }

}
void UR3Intermediator::CheckIfStillMovejRunning()
{

//    QVector<JointData> jointsData = this->ActualRobotInfo.getJointsData();
//    double firstJointPos = RoundDouble(jointsData[0].getActualJointPosition(),4);
//    double secondJointPos = RoundDouble(jointsData[1].getActualJointPosition(),4);
//    double thirdJointPos = RoundDouble(jointsData[2].getActualJointPosition(),4);
//    double fourthJointPos = RoundDouble(jointsData[3].getActualJointPosition(),4);
//    double fifthJointPos = RoundDouble(jointsData[4].getActualJointPosition(),4);
//    double sixthJointPos = RoundDouble(jointsData[5].getActualJointPosition(),4);
//    QVector<double> current = QVector<double>
//    ({firstJointPos,secondJointPos,thirdJointPos,fourthJointPos,fifthJointPos,sixthJointPos});
//    QVector<double> target = QVector<double>
//            ({RoundDouble(jointsData[0].getTargetJointPosition(),4),RoundDouble(jointsData[1].getTargetJointPosition(),4),
//             RoundDouble(jointsData[2].getTargetJointPosition(),4),RoundDouble(jointsData[3].getTargetJointPosition(),4),
//             RoundDouble(jointsData[4].getTargetJointPosition(),4),RoundDouble(jointsData[5].getTargetJointPosition(),4)});
//    if(current == _moveJTargetPos)
//    {
//        _running = false;
//        //qDebug()<<"przestal sie ruszac";
//    }
    _running =ActualRobotInfo.robotModeData.getIsProgramRunning();
}

void UR3Intermediator::CheckIfStillMoveLRunning()
{
    CartesianInfoData CurrentCartesianInfo = this->ActualRobotInfo.getCartesianInfoData();

    double x = RoundDouble(CurrentCartesianInfo.getX(),4);
    double y = RoundDouble(CurrentCartesianInfo.getY(),4);
    double z = RoundDouble(CurrentCartesianInfo.getZ(),4);
    double rx = RoundDouble(CurrentCartesianInfo.getRx(),4);
    double ry = RoundDouble(CurrentCartesianInfo.getRy(),4);
    double rz = RoundDouble(CurrentCartesianInfo.getRz(),4);

    QVector<double> current = QVector<double>({x,y,z,rx,ry,rz});

    if(current == _moveLTargetPose){
        _running = false;
    }


}

void UR3Intermediator::CheckJointsPosChanged()
{
    QVector<JointData> jointsData = this->ActualRobotInfo.getJointsData();
    double firstJointPos = RoundDouble(jointsData[0].getActualJointPosition(),4);
    double secondJointPos = RoundDouble(jointsData[1].getActualJointPosition(),4);
    double thirdJointPos = RoundDouble(jointsData[2].getActualJointPosition(),4);
    double fourthJointPos = RoundDouble(jointsData[3].getActualJointPosition(),4);
    double fifthJointPos = RoundDouble(jointsData[4].getActualJointPosition(),4);
    double sixthJointPos = RoundDouble(jointsData[5].getActualJointPosition(),4);
    QVector<double> current = QVector<double>
    ({firstJointPos,secondJointPos,thirdJointPos,fourthJointPos,fifthJointPos,sixthJointPos});

    if(current != _lastJointPos){
        _lastJointPos = current;
        emit newPoseTCP(current, 'p');

    }

}

void UR3Intermediator::CheckPolozenieChanged()
{
    CartesianInfoData CurrentCartesianInfo = this->ActualRobotInfo.getCartesianInfoData();

    double x = RoundDouble(CurrentCartesianInfo.getX(),4);
    double y = RoundDouble(CurrentCartesianInfo.getY(),4);
    double z = RoundDouble(CurrentCartesianInfo.getZ(),4);
    double rx = RoundDouble(CurrentCartesianInfo.getRx(),4);
    double ry = RoundDouble(CurrentCartesianInfo.getRy(),4);
    double rz = RoundDouble(CurrentCartesianInfo.getRz(),4);

    QVector<double> current = QVector<double>({x,y,z,rx,ry,rz});

    if(current !=_lastPolozenie){
        _lastPolozenie = current;
        emit newPoseTCP(current, 't');
    }


}

void UR3Intermediator::GetRobotMessage(char *data, unsigned int &offset, int size)
{
    while(size>offset){
        int sizeOfPackage;
        memcpy(&sizeOfPackage, &data[offset], sizeof(sizeOfPackage));
#ifndef __apple__
        sizeOfPackage = _OSSwapInt32(sizeOfPackage);
#else
        sizeOfPackage = _byteswap_ulong(sizeOfPackage);
#endif


        //sizeOfPackage = qFromBigEndian<int>(sizeOfPackage);
        offset+=sizeof(sizeOfPackage);

        unsigned char packageType;
        memcpy(&packageType, &data[offset], sizeof(packageType));
        offset+=sizeof(packageType);

        switch(packageType){
        case ROBOT_MODE_DATA:
            this->ActualRobotInfo.setRobotModeData(_data, offset);
            if(ActualRobotInfo.robotModeData.getIsEmergencyStopped() || ActualRobotInfo.robotModeData.getIsProtectiveStopped()){

                            _socket->write(QString("end_force_mode()\n").toLatin1().data());
                            _socket->waitForBytesWritten();
                        }
            break;
        case JOINT_DATA:
            this->ActualRobotInfo.setJointsData(_data, offset);
            /*if(_running)
            {
                CheckIfStillMovejRunning();
            }*/
            CheckJointsPosChanged();
            break;
        case TOOL_DATA:
            this->ActualRobotInfo.setToolData(_data,offset);
            break;
        case MASTERBOARD_DATA:
            this->ActualRobotInfo.setMasterboardData(_data, offset);
            break;
        case CARTESIAN_INFO:
            this->ActualRobotInfo.setCartesianInfoData(_data,offset);
            if(_running)
            {
                CheckIfStillMoveLRunning();
            }
            CheckPolozenieChanged();
            break;
        case KINEMATICS_INFO:
            break;
        case CONFIGURATION_DATA:
            break;
        case FORCE_MODE_DATA:
           // qDebug()<<"force mode data";
            break;
        case ADDITIONAL_INFO:
            break;
        case CALIBRATION_DATA:
            break;
        case SAFETY_DATA:
            break;
        }
        offset +=sizeOfPackage - 5; //-5 poniewaz wczesniej przesunalem o sizeofpackage i packagetype
    }

}

void UR3Intermediator::ReadDataFlow()
{
    if(_connected)
    {
            if(mutex.tryLock())
            {
                _DataFlow.push_back( this->_socket->readAll());

                mutex.unlock();
            }

        }
}

bool UR3Intermediator::ConnectToRobot()
{

    if (_connected == false)
    {
        _socket->connectToHost(IpAddress,Port);
        if(_socket->waitForConnected())
        {
            _connected = true;
        }
        else
        {
            _connected = false;
        }
    }
    emit ConnectionAction(this->IpAddress.toLatin1().data(),_connected);
    return _connected;


}

void UR3Intermediator::disconnected()
{
    _connected = false;
    _socket->deleteLater();
    _socket = new QTcpSocket();
    ConnectToRobot();
}

void UR3Intermediator::OnTcpChanged()
{

}

void UR3Intermediator::OnSocketNewBytesWritten()
{
    this->ReadDataFlow();
    GetRobotData();
}
