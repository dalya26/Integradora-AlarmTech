#include <Arduino.h>
#include <WiFi.h>
#include <Firebase_ESP_Client.h>
#include "addons/TokenHelper.h"
#include "addons/RTDBHelper.h"
#define API_KEY "AIzaSyBCDH5y86GkwE_pPG5R7J_M8mpWvyBC_QE"
#define DATABASE_URL "https://yul-bd-iot-default-rtdb.firebaseio.com/"
#define WIFI_SSID "INFINITUM4CD9_2.4"
#define WIFI_PASSWORD "gkDry2JEec"

FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

unsigned long sendDataPrevMillis = 0;
int count = 0;
bool signupOK = false;

void connectionWIFI();

void setup() {
Serial.begin(115200);
connectionWIFI();

}
void connectionWIFI(){

WiFi.begin(WIFI_SSID,WIFI_PASSWORD);
Serial.print("CONNECTING TO INTERNET");
while (WiFi.status() != WL_CONNECTED)
{
  Serial.print(" . ");
  delay(300);
}

Serial.println();
Serial.print("CONNECTED WITH IP: ");
Serial.println(WiFi.localIP());
Serial.println();

config.api_key = API_KEY;
config.database_url = DATABASE_URL;

if(Firebase.signUp(&config,&auth,"","")){
  Serial.println("COMPLETE SIGN SUCCESSFULLY");
  signupOK = true;

}else{
  Serial.printf("%s\n",config.signer.signupError.message.c_str());
}
config.token_status_callback = tokenStatusCallback;
Firebase.begin(&config,&auth);
Firebase.reconnectWiFi(true);


}

void loop() {

if(Firebase.ready() && signupOK && (millis() - sendDataPrevMillis > 115200 || sendDataPrevMillis == 0)){
  sendDataPrevMillis = millis();
  if(Firebase.RTDB.setInt(&fbdo, "test/int", count)){
    Serial.println("SUCCESS");
    Serial.println("PATH: " + fbdo.dataPath());
    Serial.println("TYPE: " + fbdo.dataType());
  }else{
    Serial.println("FAILED ");
    Serial.println("WHY REASON: " + fbdo.errorReason());
  }
  count++;
  
}
}