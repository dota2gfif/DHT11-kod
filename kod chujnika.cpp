#include "DHT.h"
#include "TFT_eSPI.h"
#include "Seeed_FS.h"
#include "SD/Seeed_SD.h"

#define DHTPIN 2     // Pin, do którego podłączony jest czujnik DHT11
#define DHTTYPE DHT11 // Typ czujnika

DHT dht(DHTPIN, DHTTYPE);
TFT_eSPI tft = TFT_eSPI();

void setup() {
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE);
  dht.begin();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  tft.fillScreen(TFT_BLACK);
  tft.setCursor(0, 0);
  tft.printf("Temperatura: %.1f C\n", t);
  tft.printf("Wilgotnosc: %.1f %%", h);

  delay(2000);
}
