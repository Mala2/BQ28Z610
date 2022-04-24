/* My comments */

#ifndef charger

#define charger

#if (ARDUINO >=100)
#include "Arduino.h"
#else
#include "WProgram.h"
#endif



#define BQ28Z610_ADDRESS                       0x55 // Please check datasheet ti find the correct ADDRS

#define BQ28Z610_COMMAND_CONTROL               0x00 // Control()
#define BQ28Z610_COMMAND_AT_RATE_TTE           0x04 // AtRateTimeToEmpty()
#define BQ28Z610_COMMAND_TEMP                  0x06 // Temperature()
#define BQ28Z610_COMMAND_VOLTAGE               0x08 // Voltage()
#define BQ28Z610_COMMAND_FLAGS                 0x0A // Flags()
#define BQ28Z610_COMMAND_CURRENT               0x0C // Current()
#define BQ28Z610_COMMAND_REM_CAPACITY          0x10 // RemainingCapacity()
#define BQ28Z610_COMMAND_FULL_CAPACITY         0x12 // FullChargeCapacity()
#define BQ28Z610_COMMAND_AVG_CURRENT           0x14 // AverageCurrent()
#define BQ28Z610_COMMAND_AVG_TIME_TO_EMPTY     0x16 // AverageTimeToEmpty()
#define BQ28Z610_COMMAND_AVG_TIME_TO_FULL      0x18 // AverageTimeToFull()
#define BQ28Z610_COMMAND_STDBY_CURRENT         0x1A // StandbyCurrent()
#define BQ28Z610_COMMAND_STDBY_C_TO_EMPTY      0x1C // StandbyCurrent()
#define BQ28Z610_COMMAND_MAX_CURRENT           0x1E // MaxLoadCurrent()
#define BQ28Z610_COMMAND_MAX_C_TO_EMPTY        0x20 // MaxLoadTimeToEmpty()
#define BQ28Z610_COMMAND_AVG_POWER             0x22 // AveragePower()
#define BQ28Z610_COMMAND_INT_TEMP              0x28 // InternalTemperature()
#define BQ28Z610_COMMAND_CYCLE_COUNT           0x2A // CycleCount()
#define BQ28Z610_COMMAND_SOC                   0x2C // StateOfCharge()
#define BQ28Z610_COMMAND_SOH                   0x2E // StateOfHealth()
#define BQ28Z610_COMMAND_CV                    0x30 // ChargeVoltage()
#define BQ28Z610_COMMAND_CC                    0x32 // ChargeCurrent()


class Charger  {

  public:
    Charger();

    ///////////////////////
    void init();

    int VOLTAGE();
    int AtRateTimeToEmpty();
    int TEMP();
    int CURRENT();
    int RemainingCapacity();
    int FullChargeCapacity();
    int AverageCurrent();
    int AverageTimeToEmpty();
    int AverageTimeToFull();
    int StandbyCurrent();
    int StandbyTimeToEmpty();
    int MaxLoadCurrent();
    int MaxLoadTimeToEmpty();
    int AveragePower();
    int InternalTemperature();
    int CycleCount();
    int StateOfCharge();
    int StateOfHealth();
    int ChargeVoltage();
    int ChargeCurrent();

    //////////////////////

  private:
    byte readReg8(int deviceAddress, int regAddress);
    void writeReg8(int deviceAddress, int regAddress, byte data);
    void writeReg16(int deviceAddress, int regAddress, word data);
    word readReg16(int deviceAddress, int regAddress);

}; // End class in semi-colon...


#endif
