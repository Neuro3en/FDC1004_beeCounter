#include <Wire.h>
#include <FDC1004.h>
int capdac = 0;
int capdac1 = 0;
FDC1004 fdc;

void setup() {
  Wire.begin();
  Serial.begin(250000);
}

void loop() {
//  uint8_t measurement = 0;
//  uint8_t channel = 1;
// // char result[100];
//  fdc.configureMeasurementSingle(measurement, channel, capdac);
//  fdc.triggerSingleMeasurement(measurement, FDC1004_100HZ);
//  delay(15);
//  uint16_t value[2];
//  if (! fdc.readMeasurement(measurement, value)) {
//    int16_t msb = (int16_t) value[0];
//    int32_t capacitance = ((int32_t)457) * ((int32_t)msb); //in attofarads
//    capacitance /= 1000; //in femtofarads
//    capacitance += ((int32_t)3028) * ((int32_t)capdac);
//    Serial.print(capacitance);
//    Serial.print("  ");
//    int16_t upper_bound = 0x4000;
//    int16_t lower_bound = -1 * upper_bound;
//    if (msb > upper_bound) {
//      if (capdac < FDC1004_CAPDAC_MAX) capdac++;
//    } else if (msb < lower_bound) {
//      if (capdac > 0) capdac--;
//    }
//  }
//    delay(20);
    
  uint8_t measurement1 = 1;
  uint8_t channel1 = 1;
//  char result1[100];
  fdc.configureMeasurementSingle(measurement1, channel1, capdac1);
  fdc.triggerSingleMeasurement(measurement1, FDC1004_100HZ);
  delay(11);
  uint16_t value1[2];
  if (! fdc.readMeasurement(measurement1, value1)) {
    int16_t msb1 = (int16_t) value1[0];
    int32_t capacitance1 = ((int32_t)457) * ((int32_t)msb1); //in attofarads
    capacitance1 /= 1000; //in femtofarads
    capacitance1 += ((int32_t)3028) * ((int32_t)capdac1);
    Serial.println(capacitance1);
    int16_t upper_bound1 = 0x4000;
    int16_t lower_bound1 = -1 * upper_bound1;
    if (msb1 > upper_bound1) {
      if (capdac1 < FDC1004_CAPDAC_MAX) capdac1++;
    } else if (msb1 < lower_bound1) {
      if (capdac1 > 0) capdac1--;
    }
  }  
}
