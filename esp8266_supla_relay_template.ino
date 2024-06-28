#include <SPI.h>
#include <SuplaDevice.h>
#define rel D1 //relay location on board
#define STORAGE_OFFSET 100
#include <supla/storage/eeprom.h>
Supla::Eeprom eeprom(STORAGE_OFFSET);

#include <supla/control/relay.h>

auto r1 = new Supla::Control::Relay(D1, false);


// ESP32 based board:
#include <supla/network/esp32_wifi.h>
Supla::ESP32Wifi wifi("ssid", "password");  // change it to match your wifi network

void setup() {
  Serial.begin(115200);

  // Replace the falowing GUID with value that you can retrieve from https://www.supla.org/arduino/get-guid
  char GUID[SUPLA_GUID_SIZE] = {0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0};

  // Replace the following AUTHKEY with value that you can retrieve from: https://www.supla.org/arduino/get-authkey
  char AUTHKEY[SUPLA_AUTHKEY_SIZE] = {0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0};

  SuplaDevice.setName("A Relay");     // here is the name
  SuplaDevice.begin(GUID,              // Global Unique Identifier
                    "svr1.supla.org",  // SUPLA server address
                    "mail@gmail.com",   // Email address used to login to Supla Cloud
                    AUTHKEY);          // Authorization key

  WiFi.softAPdisconnect(true);

}

void loop() {
  SuplaDevice.iterate();
}