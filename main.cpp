#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "esp_ieee802154.h" // Incluez la bibliothèque Zigbee d'Espressif
#include "esp_zigbee_lib.h" // Incluez la bibliothèque Espressif Zigbee SDK

LiquidCrystal_I2C lcd(0x27, 16, 2); // Adresse I2C de l'écran LCD 1602A

void setup() {
  // Initialisez l'écran LCD
  lcd.init();
  lcd.backlight(); // Allumez la rétroéclairage de l'écran

  // Initialisez le module Zigbee ESP32-C6 en suivant les instructions de la documentation
  esp_ieee802154_init(); // Initialisez le module Zigbee
}

void loop() {
  // Lire la valeur du RSSI et du LQI depuis le module Zigbee ESP32-C6
  int rssiValue = lireRSSIDuModuleZigbee();
  int lqiValue = lireLQIDuModuleZigbee();

  // Affichez la valeur du RSSI et du LQI sur l'écran LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Signal RSSI:");
  lcd.print(rssiValue); // Affichez la valeur RSSI
  lcd.setCursor(0, 1);
  lcd.print("LQI:");
  lcd.print(lqiValue); // Affichez la valeur LQI

  // Attendez quelques secondes avant de mettre à jour à nouveau l'affichage
  delay(5000);
}

int lireRSSIDuModuleZigbee() {
  // Utilisez la fonction esp_zigbee_get_rssi() pour lire le RSSI
  int rssi = esp_zigbee_get_rssi();
  
  // Assurez-vous que cette fonction retourne la valeur RSSI en dBm

  // Retournez le RSSI en dBm
  return rssi;
}

int lireLQIDuModuleZigbee() {
  // Utilisez la fonction esp_zigbee_get_lqi() pour lire le LQI
  int lqi = esp_zigbee_get_lqi();
  
  // Assurez-vous que cette fonction retourne la valeur LQI en unités LQI

  // Retournez le LQI en unités LQI
  return lqi;
}
