# include "HX711.h"

const int sensor1 = PA1;
const int sensor2 = PA2;

const int dt = PB0;
const int sck = PB1;
int initial_value = 0;
HX711 scale;

void setup() {
  Serial.begin(9600);

  sensor1.pinMode(INPUT);
  sensor2.pinMode(INPUT);
  
  scale.begin(dt, sck);
  scale.set_scale(10000);
  initial_value = scale.read_average(5)/250;
}

void loop() {
  float value1 = value1*0.9 + 0.1*scale.read()/250 - initial_value;
  float value2 = analogRead(sensor2);
  float value3 = analogRead(sensor1);
  
  Serial.print(value1);
  Serial.print(",");
  Serial.print(value2);
  Serial.print(",");
  Serial.println(value3);

  delay(200);
}
