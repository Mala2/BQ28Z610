/* My comments */

#include "Charger.h"
#include <Wire.h>
#include <avr/sleep.h>

// Charger object
Charger::Charger() {
}

void Charger::init()  {
  Wire.begin();
}

int Charger::VOLTAGE() {
  int data = 0;
  data = readReg16(BQ28Z610_ADDRESS, BQ28Z610_COMMAND_VOLTAGE);
  return data;
}

int Charger::AtRateTimeToEmpty() {
  int data = 0;
  data = readReg16(BQ28Z610_ADDRESS, BQ28Z610_COMMAND_AT_RATE_TTE);
  return data;
}

int Charger::TEMP() {
  int data = 0;
  data = readReg16(BQ28Z610_ADDRESS, BQ28Z610_COMMAND_TEMP);
  return data;
}

int Charger::CURRENT() {
  int data = 0;
  data = readReg16(BQ28Z610_ADDRESS, BQ28Z610_COMMAND_CURRENT);
  return data;
}

int Charger::RemainingCapacity() {
  int data = 0;
  data = readReg16(BQ28Z610_ADDRESS, BQ28Z610_COMMAND_REM_CAPACITY);
  return data;
}

int Charger::FullChargeCapacity() {
  int data = 0;
  data = readReg16(BQ28Z610_ADDRESS, BQ28Z610_COMMAND_FULL_CAPACITY);
  return data;
}

int Charger::AverageCurrent() {
  int data = 0;
  data = readReg16(BQ28Z610_ADDRESS, BQ28Z610_COMMAND_AVG_CURRENT);
  return data;
}

int Charger::AverageTimeToEmpty() {
  int data = 0;
  data = readReg16(BQ28Z610_ADDRESS, BQ28Z610_COMMAND_AVG_TIME_TO_EMPTY);
  return data;
}

int Charger::AverageTimeToFull() {
  int data = 0;
  data = readReg16(BQ28Z610_ADDRESS, BQ28Z610_COMMAND_AVG_TIME_TO_FULL);
  return data;
}

int Charger::StandbyCurrent() {
  int data = 0;
  data = readReg16(BQ28Z610_ADDRESS, BQ28Z610_COMMAND_STDBY_CURRENT);
  return data;
}

int Charger::StandbyTimeToEmpty() {
  int data = 0;
  data = readReg16(BQ28Z610_ADDRESS, BQ28Z610_COMMAND_STDBY_C_TO_EMPTY);
  return data;
}

int Charger::MaxLoadCurrent() {
  int data = 0;
  data = readReg16(BQ28Z610_ADDRESS, BQ28Z610_COMMAND_MAX_CURRENT);
  return data;
}
int Charger::MaxLoadTimeToEmpty() {
  int data = 0;
  data = readReg16(BQ28Z610_ADDRESS, BQ28Z610_COMMAND_MAX_C_TO_EMPTY);
  return data;
}

int Charger::AveragePower() {
  int data = 0;
  data = readReg16(BQ28Z610_ADDRESS, BQ28Z610_COMMAND_AVG_POWER);
  return data;
}

int Charger::InternalTemperature() {
  int data = 0;
  data = readReg16(BQ28Z610_ADDRESS, BQ28Z610_COMMAND_INT_TEMP);
  return data;
}
int Charger::CycleCount() {
  int data = 0;
  data = readReg16(BQ28Z610_ADDRESS, BQ28Z610_COMMAND_CYCLE_COUNT);
  return data;
}

int Charger::StateOfCharge() {
  int data = 0;
  data = readReg16(BQ28Z610_ADDRESS, BQ28Z610_COMMAND_SOC);
  return data;
}
int Charger::StateOfHealth() {
  int data = 0;
  data = readReg16(BQ28Z610_ADDRESS, BQ28Z610_COMMAND_SOH);
  return data;
}
int Charger::ChargeVoltage() {
  int data = 0;
  data = readReg16(BQ28Z610_ADDRESS, BQ28Z610_COMMAND_CV);
  return data;
}
int Charger::ChargeCurrent() {
  int data = 0;
  data = readReg16(BQ28Z610_ADDRESS, BQ28Z610_COMMAND_CC);
  return data;
}


/*****************************************************************************
 ************************ I2C Read and Write Routines ************************
 *****************************************************************************/


byte Charger::readReg8(int deviceAddress, int regAddress) {
  byte data = 0;
  Wire.beginTransmission(deviceAddress);
  Wire.write(regAddress);
  Wire.endTransmission();
  Wire.requestFrom(deviceAddress, 1);
  data = Wire.read();
  return (data);
}

void Charger::writeReg8(int deviceAddress, int regAddress, byte data) {
  Wire.beginTransmission(deviceAddress);
  Wire.write(regAddress);
  Wire.write(data);
  Wire.endTransmission();
}

void Charger::writeReg16(int deviceAddress, int regAddress, word data) {
  Wire.beginTransmission(deviceAddress);
  Wire.write(regAddress);
  Wire.write(highByte(data));
  Wire.write(lowByte(data));
  Wire.endTransmission();
}


// General function to read 16 bit I2c registers, repeated start enabled. Ignores CRC-8 code sent by LC709203F, works fine without
word Charger::readReg16(int deviceAddress, int regAddress) {
  word data = 0;
  Wire.beginTransmission(deviceAddress);
  Wire.write(regAddress);
  Wire.endTransmission(false);
  Wire.requestFrom(deviceAddress, 2);
  byte lowByteData = Wire.read();
  byte highByteData = Wire.read();
  data = word(highByteData, lowByteData);
  return (data);
}
