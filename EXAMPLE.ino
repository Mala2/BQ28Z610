#include "Charger.h"
#include <Wire.h>

// Amplifier
// Instantiate Charger object, name it anything, in this case 'BQ28Z610'
Charger BQ28Z610; 

unsigned long previousMillis = 0;

void setup() {
  Serial.begin(115200);
  BQ28Z610.init();
}

void loop() {

  unsigned long currentMillis = millis();
  if ( currentMillis - previousMillis >= 1000 ) {

    Serial.println("BQ28Z610 Parameter : \n===============================================================");

    ////////////////////**Checking Importnant registers////////////////////

    unsigned int volts = BQ28Z610.VOLTAGE(); 
    unsigned int ARTTE = BQ28Z610.AtRateTimeToEmpty(); 
    unsigned int temp = BQ28Z610.TEMP();
    unsigned int Current = BQ28Z610.CURRENT(); 
    unsigned int Rm = BQ28Z610.RemainingCapacity(); 
    unsigned int FCC = BQ28Z610.FullChargeCapacity(); 
    unsigned int AI = BQ28Z610.AverageCurrent(); 
    unsigned int TTE = BQ28Z610.AverageTimeToEmpty(); 
    unsigned int TTF = BQ28Z610.AverageTimeToFull(); 
    unsigned int SI = BQ28Z610.StandbyCurrent();
    unsigned int STTE = BQ28Z610.StandbyTimeToEmpty(); 
    unsigned int MLI = BQ28Z610.MaxLoadCurrent(); 
    unsigned int MLTTE = BQ28Z610.MaxLoadTimeToEmpty();
    unsigned int AP = BQ28Z610.AveragePower();
    unsigned int INT_TEMP = BQ28Z610.InternalTemperature(); 
    unsigned int CCo = BQ28Z610.CycleCount(); 
    unsigned int SOC = BQ28Z610.StateOfCharge(); 
    unsigned int SOH = BQ28Z610.StateOfHealth(); 
    unsigned int CV = BQ28Z610.ChargeVoltage(); 
    unsigned int CC = BQ28Z610.ChargeCurrent(); 

    // Now print out those values:
    String toPrint = String(volts) + " mV |";
    toPrint +=  " AtRateTimeToEmpty: ";
    toPrint += String(ARTTE) + " S | ";
    toPrint +=  " Temp ";
    toPrint += String(temp / 10) + " F , ";
    toPrint += String(temp / 10 - 273.15) + " C | ";
    toPrint +=  " Current ";
    toPrint += String(Current) + " mA | ";
    toPrint +=  " RemainingCapacity: ";
    toPrint += String(Rm) + " mAh | ";
    toPrint +=  " FullChargeCapacity: ";
    toPrint += String(FCC) + " mAh | ";
    toPrint +=  " AverageCurrent: ";
    toPrint += String(AI) + " mA | ";
    toPrint +=  " AverageTimeToEmpty: ";
    toPrint += String(TTE) + " S | ";  // A value of 65,535 indicates the battery is not being charged.
    toPrint +=  " AverageTimeToFull: ";
    toPrint += String(TTF) + " Min | ";// A value of 65,535 indicates the battery is not being charged.
    toPrint +=  " StandbyCurrent: ";
    toPrint += String(SI) + " Min | ";
    toPrint +=  " StandbyTimeToEmpty: ";
    toPrint += String(STTE) + " Min | ";
    toPrint +=  " MaxLoadCurrent: ";
    toPrint += String(MLI) + " mA | ";
    toPrint +=  " MaxLoadTimeToEmpty: ";
    toPrint += String(MLTTE) + " mAm | ";
    toPrint +=  " AveragePower: ";
    toPrint += String(AP) + " mW | ";
    toPrint +=  " InternalTemperature: ";
    toPrint += String(INT_TEMP / 10) + " F , ";
    toPrint += String(INT_TEMP / 10 - 273.15) + " C | ";
    toPrint +=  " CycleCount: ";
    toPrint += String(CCo) + " Cycle | ";
    toPrint +=  " RelativeStateOfCharge: ";
    toPrint += String(SOC) + " % | ";
    toPrint +=  " StateOfHealth: ";
    toPrint += String(SOH) + " % | ";
    toPrint +=  " ChargeVoltage: ";
    toPrint += String(CV) + " mV | ";
    toPrint +=  " ChargeCurrent: ";
    toPrint += String(CC) + " mA | ";

    Serial.println(toPrint);
    Serial.println(Current, DEC);


    Serial.println();
    previousMillis = currentMillis;

  }
}
