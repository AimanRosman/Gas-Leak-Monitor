#define BLYNK_TEMPLATE_ID "TMPLHiYSkiJG"
#define BLYNK_TEMPLATE_NAME "Gas leakage"
#define BLYNK_AUTH_TOKEN "s_In2alsxFWNVXpS9_OMxb4CEB6kV5fH"
#define BLYNK_PRINT Serial

#include <WiFi.h> //use Esp8266WiFi.h for node mcu
#include <BlynkSimpleEsp32.h>   // use BlynkSimpleEsp8266.h for node mcu

char auth[] = BLYNK_AUTH_TOKEN; 
char ssid[] = "WIFI KKTM PJ STUDENT"; // type your wifi name
char pass[] = "pelatihkktmpj"; // type your wifi password

int smokeA0 = 32;
int data = 0;
int sensorThres = 100; 

BlynkTimer timer; 
void sendSensor()
{ 
 int data = analogRead(smokeA0); 
 Blynk.virtualWrite(V0, data); 
 Serial.print("Pin 32: "); 
 Serial.println(data); 
    
 if(data > 20)
  { 
   //Blynk.email("xxxxxxxxx@gmail.com", "Alert", "Gas Leakage Detected!");          
   Blynk.logEvent("gas_alert","Gas Leakage Detected"); 
  }
} 

void setup()
{ 
 pinMode(smokeA0, INPUT); 
 Serial.begin(115200); 
 Blynk.begin(auth, ssid, pass); 
//dht.begin();
 timer.setInterval(2500L, sendSensor);
}

void loop()
{ 
 Blynk.run(); 
 timer.run();
}