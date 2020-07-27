#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>
#include <FirebaseArduino.h>
#include <ArduinoJson.h>
#include <ESP8266HTTPClient.h>
 
// Set these to run example.
#define FIREBASE_HOST "demo1-858b8.firebaseio.com"
#define FIREBASE_AUTH "bcVTwfhbeAJOvycisbQenrAJpTCiYiRd03V9TSPq"
#define WIFI_SSID "Connecting..."
#define WIFI_PASSWORD "244466666"
 
//String myString;
int s1 = D0;// variable resistor connected
int s2 = D1;
int s3 = D2;
int s4 = D3;
 
int sdata1 = 0;// The variable resistor value will be stored in sdata.
int sdata2 = 0;
int sdata3 = 0;
int sdata4 = 0;
 
void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(s1 ,INPUT);
  pinMode(s2,INPUT);
   pinMode(s3,INPUT);
    pinMode(s4,INPUT);
  // connect to wifi.
  pinMode(A0,OUTPUT);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED)
      {
    Serial.print(".");
    delay(500);
      }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
 

}
 
void loop()
{
  
 
sdata1 = digitalRead(s1);

if(sdata1 == 1)
{
  Serial.println("SLOT 1: UN-PARKED"); 
Firebase.setInt("SENSOR 1 value",sdata1);
}
else
{
    Serial.println("SLOT 1: PARKED"); 
Firebase.setInt("SENSOR 1 value",sdata1);
}
sdata2 = digitalRead(s2);

if(sdata2 == 1)
{
  Serial.println("SLOT 2: UN-PARKED"); 
Firebase.setInt("SENSOR 2 value",sdata2);
}
else
{
    Serial.println("SLOT 2: PARKED"); 
Firebase.setInt("SENSOR 2 value",sdata2);
}
sdata3 = digitalRead(s3);

if(sdata3 == 1)
{
  Serial.println("SLOT 3: UN-PARKED"); 
Firebase.setInt("SENSOR 3 value",sdata3);
}
else
{
    Serial.println("SLOT 3: PARKED"); 
Firebase.setInt("SENSOR 3 value",sdata3);
}
sdata4 = digitalRead(s4);
 
if(sdata4 == 1)
{
  Serial.println("SLOT 4: UN-PARKED"); 
Firebase.setInt("SENSOR 4 value",sdata4);
}
else
{
    Serial.println("SLOT 4: PARKED"); 
Firebase.setInt("SENSOR 4 value",sdata4);
}

delay(150);            
}
