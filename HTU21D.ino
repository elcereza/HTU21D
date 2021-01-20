/*-----------------------------------------------------------------------------
* Projeto: HTU21D com Arduino
* Saiba mais: https://elcereza.com/
* Disponibilizado por: https://elcereza.com/
* Editado por: Gustavo Cereza
*----------------------------------------------------------------------------*/

#include "Adafruit_HTU21DF.h"

Adafruit_HTU21DF htu = Adafruit_HTU21DF();

void setup() {
  Serial.begin(9600);
  Serial.println("HTU21D-F test");
  
  if (!htu.begin()) {
    Serial.println("Couldn't find sensor!");
    while (1);
  }
}

void loop() {
  
  float temp = htu.readTemperature();
  float rel_hum = htu.readHumidity() + (-0.15*(25 - temp));

  Serial.print("Temp: "); Serial.print(temp); Serial.print(" C");
  Serial.print("\t\t");
  Serial.print("Humi: "); Serial.print(rel_hum); Serial.println(" \%");
  delay(500);
}
