#include "UR3Message.h"
#include <QtGlobal>
#include <QtCore>
#include <QtEndian>
#include <stdlib.h>


UR3Message::UR3Message()
{
    jointsData.resize(6);
}

UR3Message::~UR3Message()
{

}

CartesianInfoData UR3Message::getCartesianInfoData() const
{
    return cartesianInfoData;
}

static double bytesSwap(double v)
{
    union {
        uint64_t i;
        double d;
    } conv;
    conv.d = v;
#ifndef __apple__
    conv.i = _OSSwapInt64(conv.i);
#else
    conv.i = _byteswap_uint64(conv.i);
#endif
    return conv.d;

}

double doubleSwap( const double inDouble )
{
   double retVal;
   char *doubleToConvert = ( char* ) & inDouble;
   char *returnDouble = ( char* ) & retVal;

   // swap the bytes into a temporary buffer
   returnDouble[0] = doubleToConvert[7];
   returnDouble[1] = doubleToConvert[6];
   returnDouble[2] = doubleToConvert[5];
   returnDouble[3] = doubleToConvert[4];

   returnDouble[4] = doubleToConvert[3];
   returnDouble[5] = doubleToConvert[2];
   returnDouble[6] = doubleToConvert[1];
   returnDouble[7] = doubleToConvert[0];


   return retVal;
}

float floatSwap( const float inFloat )
{
   float retVal;
   char *floatToConvert = ( char* ) & inFloat;
   char *returnFloat = ( char* ) & retVal;

   // swap the bytes into a temporary buffer
   returnFloat[0] = floatToConvert[3];
   returnFloat[1] = floatToConvert[2];
   returnFloat[2] = floatToConvert[1];
   returnFloat[3] = floatToConvert[0];

   return retVal;
}


void UR3Message::setCartesianInfoData(char *data, unsigned int offset)
{
    double tmp;

    memcpy(&tmp,&data[offset], sizeof(tmp));
    this->cartesianInfoData.setX(doubleSwap(tmp));
    offset+=sizeof(tmp);

    memcpy(&tmp,&data[offset], sizeof(tmp));
    this->cartesianInfoData.setY(doubleSwap(tmp));
    offset+=sizeof(tmp);

    memcpy(&tmp,&data[offset], sizeof(tmp));
    this->cartesianInfoData.setZ(doubleSwap(tmp));
    offset+=sizeof(tmp);

    memcpy(&tmp,&data[offset], sizeof(tmp));
    this->cartesianInfoData.setRx(doubleSwap(tmp));
    offset+=sizeof(tmp);

    memcpy(&tmp,&data[offset], sizeof(tmp));
    this->cartesianInfoData.setRy(doubleSwap(tmp));
    offset+=sizeof(tmp);

    memcpy(&tmp,&data[offset], sizeof(tmp));
    this->cartesianInfoData.setRz(doubleSwap(tmp));
    offset+=sizeof(tmp);

    memcpy(&tmp,&data[offset], sizeof(tmp));
    this->cartesianInfoData.setTcpOffsetX(doubleSwap(tmp));
    offset+=sizeof(tmp);

    memcpy(&tmp,&data[offset], sizeof(tmp));
    this->cartesianInfoData.setTcpOffsetY(doubleSwap(tmp));
    offset+=sizeof(tmp);

    memcpy(&tmp,&data[offset], sizeof(tmp));
    this->cartesianInfoData.setTcpOffsetZ(doubleSwap(tmp));
    offset+=sizeof(tmp);

    memcpy(&tmp,&data[offset], sizeof(tmp));
    this->cartesianInfoData.setTcpOffsetRX(doubleSwap(tmp));
    offset+=sizeof(tmp);

    memcpy(&tmp,&data[offset], sizeof(tmp));
    this->cartesianInfoData.setTcpOffsetRY(doubleSwap(tmp));
    offset+=sizeof(tmp);

    memcpy(&tmp,&data[offset], sizeof(tmp));
    this->cartesianInfoData.setTcpOffsetRZ(doubleSwap(tmp));
    offset+=sizeof(tmp);
}

MasterboardData UR3Message::getMasterboardData() const
{
    return masterboardData;
}

void UR3Message::setMasterboardData(char *data, int offset)
{
    int intTemp;
    char charTemp;
    double doubleTemp;
    float floatTemp;
    unsigned char ucharTemp;

    memcpy(&intTemp,&data[offset], sizeof(intTemp));
#ifndef __apple__
     this->masterboardData.setDigitalInputBits(_OSSwapInt64(intTemp));
#else
    this->masterboardData.setDigitalInputBits(_byteswap_ulong(intTemp));
#endif
    offset+=sizeof(intTemp);

    memcpy(&intTemp,&data[offset], sizeof(intTemp));
#ifndef __apple__
    this->masterboardData.setDigitalOutputBits(_OSSwapInt64(intTemp));
#else
    this->masterboardData.setDigitalOutputBits(_byteswap_ulong(intTemp));
#endif
    offset+=sizeof(intTemp);

    memcpy(&charTemp,&data[offset], sizeof(charTemp));
    this->masterboardData.setAnalogInputRange0(charTemp);
    offset+=sizeof(charTemp);

    memcpy(&charTemp,&data[offset], sizeof(charTemp));
    this->masterboardData.setAnalogInputRange1(charTemp);
    offset+=sizeof(charTemp);

    memcpy(&doubleTemp,&data[offset], sizeof(doubleTemp));
    this->masterboardData.setAnalogInput0(doubleSwap(doubleTemp));
    offset+=sizeof(doubleTemp);

    memcpy(&doubleTemp,&data[offset], sizeof(doubleTemp));
    this->masterboardData.setAnalogInput1(doubleSwap(doubleTemp));
    offset+=sizeof(doubleTemp);

    memcpy(&charTemp,&data[offset], sizeof(charTemp));
    this->masterboardData.setAnalogOutputDomain0(charTemp);
    offset+=sizeof(charTemp);

    memcpy(&charTemp,&data[offset], sizeof(charTemp));
    this->masterboardData.setAnalogOutputDomain1(charTemp);
    offset+=sizeof(charTemp);

    memcpy(&doubleTemp,&data[offset], sizeof(doubleTemp));
    this->masterboardData.setAnalogOutput0(doubleSwap(doubleTemp));
    offset+=sizeof(doubleTemp);

    memcpy(&doubleTemp,&data[offset], sizeof(doubleTemp));
    this->masterboardData.setAnalogOutput1(doubleSwap(doubleTemp));
    offset+=sizeof(doubleTemp);

    memcpy(&floatTemp,&data[offset], sizeof(floatTemp));
    this->masterboardData.setMasterBoardTemperature(floatSwap(floatTemp));
    offset+=sizeof(floatTemp);

    memcpy(&floatTemp,&data[offset], sizeof(floatTemp));
    this->masterboardData.setRobotVoltage48V(floatSwap(floatTemp));
    offset+=sizeof(floatTemp);

    memcpy(&floatTemp,&data[offset], sizeof(floatTemp));
    this->masterboardData.setRobotCurrent(floatSwap(floatTemp));
    offset+=sizeof(floatTemp);

    memcpy(&floatTemp,&data[offset], sizeof(floatTemp));
    this->masterboardData.setMasterIOCurrent(floatSwap(floatTemp));
    offset+=sizeof(floatTemp);

    memcpy(&ucharTemp,&data[offset], sizeof(ucharTemp));
    this->masterboardData.setSafetyMode((SafetyMode)ucharTemp);
    offset+=sizeof(charTemp);

    memcpy(&ucharTemp,&data[offset], sizeof(ucharTemp));
    this->masterboardData.setInReducedMode(ucharTemp);
    offset+=sizeof(ucharTemp);


}


ConfigurationData UR3Message::getConfigurationData() const
{
    return configurationData;
}

void UR3Message::setConfigurationData(char *data, unsigned int offset)
{

}


QVector<JointData> UR3Message::getJointsData() const
{
    return jointsData;
}

void UR3Message::setJointsData(char *data, int offset)
{


    for(int i = 0; i<6; i++){

        double doubleTemp;
        float floatTemp;
        unsigned char ucharTemp;

        memcpy(&doubleTemp, &data[offset], sizeof(doubleTemp));
        this->jointsData[i].setActualJointPosition(bytesSwap(doubleTemp));
        offset+=sizeof(doubleTemp);

        memcpy(&doubleTemp, &data[offset], sizeof(doubleTemp));
        this->jointsData[i].setTargetJointPosition(bytesSwap(doubleTemp));
        offset+=sizeof(doubleTemp);

        memcpy(&doubleTemp, &data[offset], sizeof(doubleTemp));
        this->jointsData[i].setActualJointSpeed(bytesSwap(doubleTemp));
        offset+=sizeof(doubleTemp);

        memcpy(&floatTemp, &data[offset], sizeof(floatTemp));
        this->jointsData[i].setActualJointCurrent(floatSwap(floatTemp));
        offset+=sizeof(floatTemp);

        memcpy(&floatTemp, &data[offset], sizeof(floatTemp));
        this->jointsData[i].setActualJointVoltage(floatSwap(floatTemp));
        offset+=sizeof(floatTemp);

        memcpy(&floatTemp, &data[offset], sizeof(floatTemp));
        this->jointsData[i].setActualMotorTemprature(floatSwap(floatTemp));
        offset+=sizeof(floatTemp);

        offset+=sizeof(floatTemp); //offset+ poniewaz nie uzywamy T micro

        memcpy(&ucharTemp, &data[offset], sizeof(ucharTemp));
        this->jointsData[i].setJointMode((JointMode)ucharTemp);
        offset+=sizeof(ucharTemp);
    }
}

ToolData UR3Message::getToolData() const
{
    return toolData;
}

void UR3Message::setToolData(char *data, int offset)
{
    char charTemp;
    double doubleTemp;
    float floatTemp;
    unsigned char ucharTemp;

    memcpy(&charTemp,&data[offset],sizeof charTemp);
    this->toolData.setAnalogInputRange2(charTemp);
    offset+=sizeof charTemp;

    memcpy(&charTemp,&data[offset],sizeof charTemp);
    this->toolData.setAnalogInputRange3(charTemp);
    offset+= sizeof charTemp;

    memcpy(&doubleTemp,&data[offset],sizeof doubleTemp);
    this->toolData.setAnalogInput2(bytesSwap(doubleTemp));
    offset+=sizeof doubleTemp;

    memcpy(&doubleTemp,&data[offset],sizeof doubleTemp);
    this->toolData.setAnalogInput3(bytesSwap(doubleTemp));
    offset+=sizeof doubleTemp;

    memcpy(&floatTemp,&data[offset],sizeof floatTemp);
    this->toolData.setToolVoltage48V(floatSwap(floatTemp));
    offset+=sizeof floatTemp;

    memcpy(&ucharTemp,&data[offset],sizeof ucharTemp);
    this->toolData.setToolOutputVoltage(ucharTemp);
    offset+=sizeof ucharTemp;


    memcpy(&floatTemp,&data[offset],sizeof floatTemp);
    this->toolData.setToolCurrent(floatSwap(floatTemp));
    offset+=sizeof floatTemp;


    memcpy(&floatTemp,&data[offset],sizeof floatTemp);
    this->toolData.setToolTemperature(floatSwap(floatTemp));
    offset+=sizeof floatTemp;

    memcpy(&ucharTemp,&data[offset],sizeof ucharTemp);
    this->toolData.setToolMode((ToolMode)ucharTemp);
    offset+=sizeof ucharTemp;

}


RobotModeData UR3Message::getRobotModeData() const
{
    return robotModeData;
}

void UR3Message::setRobotModeData(char *data, int offset)
{
    uint64_t timestamp;
    unsigned char ucharTemp;
    bool boolTemp;
    double doubleTemp;

    memcpy(&timestamp, &data[offset], sizeof(timestamp));
#ifndef __apple__
    this->robotModeData.setTimestamp(_OSSwapInt64(timestamp));
#else
    this->robotModeData.setTimestamp(_byteswap_uint64(timestamp));
#endif
    offset+=sizeof(timestamp);

    memcpy(&boolTemp,&data[offset], sizeof(boolTemp));
    this->robotModeData.setIsRobotConnected(boolTemp);
    offset+=sizeof(boolTemp);

    memcpy(&boolTemp,&data[offset], sizeof(boolTemp));
    this->robotModeData.setIsRealRobotEnabled(boolTemp);
    offset+=sizeof(boolTemp);

    memcpy(&boolTemp,&data[offset], sizeof(boolTemp));
    this->robotModeData.setIsRobotPowerOn(boolTemp);
    offset+=sizeof(boolTemp);

    memcpy(&boolTemp,&data[offset], sizeof(boolTemp));
    this->robotModeData.setIsEmergencyStopped(boolTemp);
    offset+=sizeof(boolTemp);

    memcpy(&boolTemp,&data[offset], sizeof(boolTemp));
    this->robotModeData.setIsProtectiveStopped(boolTemp);
    offset+=sizeof(boolTemp);

    memcpy(&boolTemp,&data[offset], sizeof(boolTemp));
    this->robotModeData.setIsProgramRunning(boolTemp);
    offset+=sizeof(boolTemp);

    memcpy(&boolTemp,&data[offset], sizeof(boolTemp));
    this->robotModeData.setIsProgramPaused(boolTemp);
    offset+=sizeof(boolTemp);

    memcpy(&ucharTemp,&data[offset], sizeof(ucharTemp));
    //int robotMode = ucharTemp;
    this->robotModeData.setRobotMode((RobotMode)ucharTemp);
    offset+=sizeof(ucharTemp);

    memcpy(&ucharTemp,&data[offset], sizeof(ucharTemp));
    this->robotModeData.setControlMode((ControlMode)ucharTemp);
    offset+=sizeof(ucharTemp);

    memcpy(&doubleTemp,&data[offset], sizeof(doubleTemp));
    this->robotModeData.setSpeedFraction(bytesSwap(doubleTemp));
    offset+=sizeof(doubleTemp);

    memcpy(&doubleTemp,&data[offset], sizeof(doubleTemp));
    this->robotModeData.setSpeedScaling(bytesSwap(doubleTemp));
    offset+=sizeof(doubleTemp);

}


bool RobotModeData::getIsRobotConnected() const
{
    return isRobotConnected;
}

void RobotModeData::setIsRobotConnected(bool value)
{
    isRobotConnected = value;
}

bool RobotModeData::getIsRealRobotEnabled() const
{
    return isRealRobotEnabled;
}

void RobotModeData::setIsRealRobotEnabled(bool value)
{
    isRealRobotEnabled = value;
}

bool RobotModeData::getIsRobotPowerOn() const
{
    return isRobotPowerOn;
}

void RobotModeData::setIsRobotPowerOn(bool value)
{
    isRobotPowerOn = value;
}

bool RobotModeData::getIsEmergencyStopped() const
{
    return isEmergencyStopped;
}

void RobotModeData::setIsEmergencyStopped(bool value)
{
    isEmergencyStopped = value;
}

bool RobotModeData::getIsProtectiveStopped() const
{
    return isProtectiveStopped;
}

void RobotModeData::setIsProtectiveStopped(bool value)
{
    isProtectiveStopped = value;
}

bool RobotModeData::getIsProgramRunning() const
{
    return isProgramRunning;
}

void RobotModeData::setIsProgramRunning(bool value)
{
    isProgramRunning = value;
}

bool RobotModeData::getIsProgramPaused() const
{
    return isProgramPaused;
}

void RobotModeData::setIsProgramPaused(bool value)
{
    isProgramPaused = value;
}

RobotMode RobotModeData::getRobotMode() const
{
    return robotMode;
}

void RobotModeData::setRobotMode(const RobotMode &value)
{
    robotMode = value;
}

ControlMode RobotModeData::getControlMode() const
{
    return controlMode;
}

void RobotModeData::setControlMode(const ControlMode &value)
{
    controlMode = value;
}

double RobotModeData::getSpeedFraction() const
{
    return speedFraction;
}

void RobotModeData::setSpeedFraction(double value)
{
    speedFraction = value;
}

double RobotModeData::getSpeedScaling() const
{
    return speedScaling;
}

void RobotModeData::setSpeedScaling(double value)
{
    speedScaling = value;
}

RobotModeData::RobotModeData()
{

}

RobotModeData::~RobotModeData()
{

}

uint64_t RobotModeData::getTimestamp() const
{
    return timestamp;
}

void RobotModeData::setTimestamp(const uint64_t &value)
{
    timestamp = value;
}



double JointData::getActualJointPosition() const
{
    return actualJointPosition;
}

void JointData::setActualJointPosition(double value)
{
    actualJointPosition = value;
}

double JointData::getTargetJointPosition() const
{
    return targetJointPosition;
}

void JointData::setTargetJointPosition(double value)
{
    targetJointPosition = value;
}

double JointData::getActualJointSpeed() const
{
    return actualJointSpeed;
}

void JointData::setActualJointSpeed(double value)
{
    actualJointSpeed = value;
}

float JointData::getActualJointCurrent() const
{
    return actualJointCurrent;
}

void JointData::setActualJointCurrent(float value)
{
    actualJointCurrent = value;
}

float JointData::getActualJointVoltage() const
{
    return actualJointVoltage;
}

void JointData::setActualJointVoltage(float value)
{
    actualJointVoltage = value;
}

float JointData::getActualMotorTemprature() const
{
    return actualMotorTemprature;
}

void JointData::setActualMotorTemprature(float value)
{
    actualMotorTemprature = value;
}

JointMode JointData::getJointMode() const
{
    return jointMode;
}

void JointData::setJointMode(const JointMode &value)
{
    jointMode = value;
}

JointData::JointData()
{

}

JointData::~JointData()
{

}



char ToolData::getAnalogInputRange3() const
{
    return analogInputRange3;
}

void ToolData::setAnalogInputRange3(char value)
{
    analogInputRange3 = value;
}

double ToolData::getAnalogInput2() const
{
    return analogInput2;
}

void ToolData::setAnalogInput2(double value)
{
    analogInput2 = value;
}

double ToolData::getAnalogInput3() const
{
    return analogInput3;
}

void ToolData::setAnalogInput3(double value)
{
    analogInput3 = value;
}

float ToolData::getToolVoltage48V() const
{
    return toolVoltage48V;
}

void ToolData::setToolVoltage48V(float value)
{
    toolVoltage48V = value;
}

float ToolData::getToolCurrent() const
{
    return toolCurrent;
}

void ToolData::setToolCurrent(float value)
{
    toolCurrent = value;
}

float ToolData::getToolTemperature() const
{
    return toolTemperature;
}

void ToolData::setToolTemperature(float value)
{
    toolTemperature = value;
}

unsigned char ToolData::getToolOutputVoltage() const
{
    return toolOutputVoltage;
}

void ToolData::setToolOutputVoltage(unsigned char value)
{
    toolOutputVoltage = value;
}

ToolMode ToolData::getToolMode() const
{
    return toolMode;
}

void ToolData::setToolMode(const ToolMode &value)
{
    toolMode = value;
}

ToolData::ToolData()
{

}

ToolData::~ToolData()
{

}

char ToolData::getAnalogInputRange2() const
{
    return analogInputRange2;
}

void ToolData::setAnalogInputRange2(char value)
{
    analogInputRange2 = value;
}

MasterboardData::MasterboardData()
{

}

MasterboardData::~MasterboardData()
{

}

int MasterboardData::getDigitalInputBits() const
{
    return digitalInputBits;
}

void MasterboardData::setDigitalInputBits(int value)
{
    digitalInputBits = value;
}

int MasterboardData::getDigitalOutputBits() const
{
    return digitalOutputBits;
}

void MasterboardData::setDigitalOutputBits(int value)
{
    digitalOutputBits = value;
}

char MasterboardData::getAnalogInputRange0() const
{
    return analogInputRange0;
}

void MasterboardData::setAnalogInputRange0(char value)
{
    analogInputRange0 = value;
}

char MasterboardData::getAnalogInputRange1() const
{
    return analogInputRange1;
}

void MasterboardData::setAnalogInputRange1(char value)
{
    analogInputRange1 = value;
}

double MasterboardData::getAnalogInput0() const
{
    return analogInput0;
}

void MasterboardData::setAnalogInput0(double value)
{
    analogInput0 = value;
}

double MasterboardData::getAnalogInput1() const
{
    return analogInput1;
}

void MasterboardData::setAnalogInput1(double value)
{
    analogInput1 = value;
}

char MasterboardData::getAnalogOutputDomain0() const
{
    return analogOutputDomain0;
}

void MasterboardData::setAnalogOutputDomain0(char value)
{
    analogOutputDomain0 = value;
}

char MasterboardData::getAnalogOutputDomain1() const
{
    return analogOutputDomain1;
}

void MasterboardData::setAnalogOutputDomain1(char value)
{
    analogOutputDomain1 = value;
}

double MasterboardData::getAnalogOutput0() const
{
    return analogOutput0;
}

void MasterboardData::setAnalogOutput0(double value)
{
    analogOutput0 = value;
}

double MasterboardData::getAnalogOutput1() const
{
    return analogOutput1;
}

void MasterboardData::setAnalogOutput1(double value)
{
    analogOutput1 = value;
}

float MasterboardData::getMasterBoardTemperature() const
{
    return masterBoardTemperature;
}

void MasterboardData::setMasterBoardTemperature(float value)
{
    masterBoardTemperature = value;
}

float MasterboardData::getRobotVoltage48V() const
{
    return robotVoltage48V;
}

void MasterboardData::setRobotVoltage48V(float value)
{
    robotVoltage48V = value;
}

float MasterboardData::getRobotCurrent() const
{
    return robotCurrent;
}

void MasterboardData::setRobotCurrent(float value)
{
    robotCurrent = value;
}

float MasterboardData::getMasterIOCurrent() const
{
    return masterIOCurrent;
}

void MasterboardData::setMasterIOCurrent(float value)
{
    masterIOCurrent = value;
}

SafetyMode MasterboardData::getSafetyMode() const
{
    return safetyMode;
}

void MasterboardData::setSafetyMode(const SafetyMode &value)
{
    safetyMode = value;
}

char MasterboardData::getEuromap67InterfaceInstalled() const
{
    return euromap67InterfaceInstalled;
}

void MasterboardData::setEuromap67InterfaceInstalled(char value)
{
    euromap67InterfaceInstalled = value;
}

int MasterboardData::getEuromapInputBits() const
{
    return euromapInputBits;
}

void MasterboardData::setEuromapInputBits(int value)
{
    euromapInputBits = value;
}

int MasterboardData::getEuromapOutputBits() const
{
    return euromapOutputBits;
}

void MasterboardData::setEuromapOutputBits(int value)
{
    euromapOutputBits = value;
}

float MasterboardData::getEuromapVoltage() const
{
    return euromapVoltage;
}

void MasterboardData::setEuromapVoltage(float value)
{
    euromapVoltage = value;
}

float MasterboardData::getEuromapCurrent() const
{
    return euromapCurrent;
}

void MasterboardData::setEuromapCurrent(float value)
{
    euromapCurrent = value;
}

unsigned char MasterboardData::getInReducedMode() const
{
    return InReducedMode;
}

void MasterboardData::setInReducedMode(unsigned char value)
{
    InReducedMode = value;
}

double CartesianInfoData::getY() const
{
    return y;
}

void CartesianInfoData::setY(double value)
{
    y = value;
}

double CartesianInfoData::getZ() const
{
    return z;
}

void CartesianInfoData::setZ(double value)
{
    z = value;
}

double CartesianInfoData::getRx() const
{
    return rx;
}

void CartesianInfoData::setRx(double value)
{
    rx = value;
}

double CartesianInfoData::getRy() const
{
    return ry;
}

void CartesianInfoData::setRy(double value)
{
    ry = value;
}

double CartesianInfoData::getRz() const
{
    return rz;
}

void CartesianInfoData::setRz(double value)
{
    rz = value;
}

double CartesianInfoData::getTcpOffsetX() const
{
    return tcpOffsetX;
}

void CartesianInfoData::setTcpOffsetX(double value)
{
    tcpOffsetX = value;
}

double CartesianInfoData::getTcpOffsetY() const
{
    return tcpOffsetY;
}

void CartesianInfoData::setTcpOffsetY(double value)
{
    tcpOffsetY = value;
}

double CartesianInfoData::getTcpOffsetZ() const
{
    return tcpOffsetZ;
}

void CartesianInfoData::setTcpOffsetZ(double value)
{
    tcpOffsetZ = value;
}

double CartesianInfoData::getTcpOffsetRZ() const
{
    return tcpOffsetRZ;
}

void CartesianInfoData::setTcpOffsetRZ(double value)
{
    tcpOffsetRZ = value;
}

double CartesianInfoData::getTcpOffsetRY() const
{
    return tcpOffsetRY;
}

void CartesianInfoData::setTcpOffsetRY(double value)
{
    tcpOffsetRY = value;
}

double CartesianInfoData::getTcpOffsetRX() const
{
    return tcpOffsetRX;
}

void CartesianInfoData::setTcpOffsetRX(double value)
{
    tcpOffsetRX = value;
}

CartesianInfoData::CartesianInfoData()
{

}

CartesianInfoData::~CartesianInfoData()
{

}

double CartesianInfoData::getX() const
{
    return x;
}

void CartesianInfoData::setX(double value)
{
    x = value;
}

double ConfigurationData::getJointMaxLimit() const
{
    return jointMaxLimit;
}

void ConfigurationData::setJointMaxLimit(double value)
{
    jointMaxLimit = value;
}

double ConfigurationData::getJointMaxSpeed() const
{
    return jointMaxSpeed;
}

void ConfigurationData::setJointMaxSpeed(double value)
{
    jointMaxSpeed = value;
}

double ConfigurationData::getJointMaxAcceleration() const
{
    return jointMaxAcceleration;
}

void ConfigurationData::setJointMaxAcceleration(double value)
{
    jointMaxAcceleration = value;
}

double ConfigurationData::getVJointDefault() const
{
    return vJointDefault;
}

void ConfigurationData::setVJointDefault(double value)
{
    vJointDefault = value;
}

double ConfigurationData::getAJointDefault() const
{
    return aJointDefault;
}

void ConfigurationData::setAJointDefault(double value)
{
    aJointDefault = value;
}

double ConfigurationData::getVToolDefault() const
{
    return vToolDefault;
}

void ConfigurationData::setVToolDefault(double value)
{
    vToolDefault = value;
}

double ConfigurationData::getAToolDefault() const
{
    return aToolDefault;
}

void ConfigurationData::setAToolDefault(double value)
{
    aToolDefault = value;
}

double ConfigurationData::getEqRadius() const
{
    return eqRadius;
}

void ConfigurationData::setEqRadius(double value)
{
    eqRadius = value;
}

double ConfigurationData::getDHa() const
{
    return DHa;
}

void ConfigurationData::setDHa(double value)
{
    DHa = value;
}

double ConfigurationData::getDHd() const
{
    return DHd;
}

void ConfigurationData::setDHd(double value)
{
    DHd = value;
}

double ConfigurationData::getDHalpha() const
{
    return DHalpha;
}

void ConfigurationData::setDHalpha(double value)
{
    DHalpha = value;
}

double ConfigurationData::getDHtheta() const
{
    return DHtheta;
}

void ConfigurationData::setDHtheta(double value)
{
    DHtheta = value;
}

int ConfigurationData::getMasterboardVersion() const
{
    return masterboardVersion;
}

void ConfigurationData::setMasterboardVersion(int value)
{
    masterboardVersion = value;
}

int ConfigurationData::getControllerBoxType() const
{
    return controllerBoxType;
}

void ConfigurationData::setControllerBoxType(int value)
{
    controllerBoxType = value;
}

int ConfigurationData::getRobotType() const
{
    return robotType;
}

void ConfigurationData::setRobotType(int value)
{
    robotType = value;
}

int ConfigurationData::getRobotSubType() const
{
    return robotSubType;
}

void ConfigurationData::setRobotSubType(int value)
{
    robotSubType = value;
}

ConfigurationData::ConfigurationData()
{

}

ConfigurationData::~ConfigurationData()
{

}

double ConfigurationData::getJointMinLimit() const
{
    return jointMinLimit;
}

void ConfigurationData::setJointMinLimit(double value)
{
    jointMinLimit = value;
}
