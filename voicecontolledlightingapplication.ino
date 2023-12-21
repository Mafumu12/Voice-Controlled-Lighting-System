#include <WiFi.h>


#define room1 15
#define room2 5
#define room3 14
const int c =0;
const int f = 5000;
const int res = 8;
const char* ssid = "maf";
const char* password = "12345678";
String voicecommand;
WiFiServer server(80);
WiFiClient client;

String result;

String IncomingRequest()
{

while(client.available())
{
voicecommand = (client.readStringUntil('\r'));
if ((voicecommand.indexOf("HTTP/1.1")>0))
result = voicecommand;
}

return result;
}

void setup() {

voicecommand = "";
pinMode(room1,OUTPUT);
pinMode(room2,OUTPUT);
pinMode(room3,OUTPUT);
Serial.begin(115200);
delay(10);
 
  int status = WL_IDLE_STATUS;

  Serial.println("ESP Connecting to WIFI");
  WiFi.begin(ssid, password);
  while ((!(WiFi.status() == WL_CONNECTED)))
  {
    delay(300);
    Serial.print("..");
    status = WiFi.status();
     Serial.println(get_wifi_status(status));
  }
  Serial.println("");
  Serial.println("ESP CONNECTED TO WiFi");
  Serial.println("THE IP ADDRESS is : ");
  Serial.print((WiFi.localIP()));
server.begin();


}
void decrease_brightness(int roomnumber)
{

 
   ledcSetup(c,f,res);
   ledcAttachPin(roomnumber,c);
  for(int Cycle = 255; Cycle >= 50; Cycle--)
  {
    ledcWrite(c, Cycle);   
  } 
  
  }
  void increase_brightness(int roomnumber)
{

 
   ledcSetup(c,f,res);
   ledcAttachPin(roomnumber,c);
  for(int Cycle = 10; Cycle <= 100; Cycle++)
  {   
    ledcWrite(c, Cycle);
  }
  
  }

void loop() {
  
client = server.available();
if (!client)
return;
while(!client.available())
delay(1);
voicecommand = (IncomingRequest());
voicecommand.remove(0, 5);
voicecommand.remove(voicecommand.length()-9,9);
//turning lights on room1
  if (voicecommand == "first room light on")
{
room_lights_on(room1);
}
 else if (voicecommand == "light on first room")
{
room_lights_on(room1);
}
//turning off lights room 1
 
else if (voicecommand == "first room light off")
{
room_lights_off(room1);
}
 else if (voicecommand == "light off first room")
{
room_lights_off(room1);
}
//turning lights on lights room2
 
else if(voicecommand == "second room light on")
{
room_lights_on(room2);
}
 else if (voicecommand == "light on second room")
{
room_lights_on(room2);
}
//room two light off
 
else if(voicecommand == "second room light off")
{
room_lights_off(room2);
}
else if (voicecommand == "light off second room")
{
room_lights_off(room2);
}
//turning on lights room 3
 
else if(voicecommand == "third room light on")
{
room_lights_on(room3);
}
else if(voicecommand == "light on third room")
{
room_lights_on(room3);
}
//turning off lights room 3
else if (voicecommand == "room three light off")
{
room_lights_off(room3);
}
else if (voicecommand == "light off third room")
{
room_lights_off(room3);
}
 
//ALL OF THE LIGHTS
else if(voicecommand == "lights on")
{
 lights_on(room1);
 lights_on(room2);
 lights_on(room3);
  
  
  }
  else if(voicecommand == "on lights")
{
 lights_on(room1);
 lights_on(room2);
 lights_on(room3);
  
  
  }
  
  else if(voicecommand == "off lights")
{
  lights_off(room1);
  lights_off(room2);
  lights_off(room3);
  
  
  }
  else if(voicecommand == "lights off")
{
  lights_off(room1);
  lights_off(room2);
  lights_off(room3);
  
  
  }
 
  //make the leds blink
 
else if (voicecommand == "first room blink")
{
led_blink(room1);
}
 else if (voicecommand == "blink first room")
{
led_blink(room1);
}
 
else if (voicecommand == "second room blink")
{
led_blink(room2);
}
else if (voicecommand == "blink second room")
{
led_blink(room2);
}
else if (voicecommand == "lights blink")
{
all_led_blink();
 
}
else if (voicecommand == "blink lights")
{
all_led_blink();
 
}
else if (voicecommand == "third room blink")
{
 led_blink(room3);
}
else if (voicecommand == "blink third room")
{
 led_blink(room3);
}
//fading the lights
 
else if(voicecommand == "first room in and out")
{
    fade(room1);
}
else if(voicecommand == "in and out first room")
{
    fade(room1);
}
 
else if(voicecommand == "second room in and out")
{
    fade(room2);
}
else if(voicecommand == "in and out second room")
{
    fade(room2);
}
 
 
else if(voicecommand == "third room in and out")
{
 fade(room3);
}
else if(voicecommand == "in and out third room")
{
 fade(room3);
}
else if(voicecommand == "lights in and out")
{
    fade(room1);
    fade(room2);
    fade(room3);

  
  
  } 
  else if(voicecommand == "in and out lights")
{
    fade(room1);
    fade(room2);
    fade(room3);

  
  
  } 

//brightness controll
 
 Echofeedback(voicecommand);
client.println("HTTP/1.1 200 OK");
client.println("Content-Type: text/html");
client.println("");
client.println("");
client.println("");
client.println("OK");
client.println("");
client.flush();
client.stop();
delay(1);
}
void fade(int roomnumber)
{
  
    ledcSetup(c,f,res);
   ledcAttachPin(roomnumber,c);
  for(int Cycle = 0; Cycle <= 255; Cycle++){   
    
    ledcWrite(c, Cycle);
    delay(20);
  }
  for(int Cycle = 255; Cycle >= 0; Cycle--){
    ledcWrite(c, Cycle);   
    delay(20);

  
  
  } 
  
  
  
  }
  void led_blink(int roomnumber)
  {
    
    for(int i=0;i < 5;i++)
    {
   digitalWrite(roomnumber,HIGH);
delay(1000);
digitalWrite(roomnumber,LOW);
delay(1000);
digitalWrite(roomnumber,HIGH);
      
      
      }
    

 
    }
    void all_led_blink()
    {
      for(int i= 0; i< 5;i++)
      {
digitalWrite(room3,HIGH);
digitalWrite(room1,HIGH);
digitalWrite(room2,HIGH);
delay(1000);
digitalWrite(room3,LOW);
digitalWrite(room2,LOW);
digitalWrite(room1,LOW);
delay(1000);
        
        
        }
      
      

 
      
      }
      void lights_on(int roomnumber)
      {
        
        
        digitalWrite(roomnumber,HIGH);
        
        
        
        }
        void lights_off(int roomnumber)
      {
        
        
        digitalWrite(roomnumber,LOW);
        
        
        
        }
        void room_lights_off(int roomnumber)
        {
          
          digitalWrite(roomnumber,LOW);
          }
          void room_lights_on(int roomnumber)
        {
          
          digitalWrite(roomnumber,HIGH);
          }

      
      
String get_wifi_status(int status)
{
    switch(status)
    {
        case WL_IDLE_STATUS:
        return "WL_IDLE_STATUS";
        case WL_SCAN_COMPLETED:
        return "WL_SCAN_COMPLETED";
        case WL_NO_SSID_AVAIL:
        return "WL_NO_SSID_AVAIL";
        case WL_CONNECT_FAILED:
        return "WL_CONNECT_FAILED";
        case WL_CONNECTION_LOST:
        return "WL_CONNECTION_LOST";
        case WL_CONNECTED:
        return "WL_CONNECTED";
        case WL_DISCONNECTED:
        return "WL_DISCONNECTED";
    }
    }
    void Echofeedback(String echo)
{
  client.println("HTTP/1.1 200 OK ");
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println(echo);
  client.println("</html>");
  client.stop();
  delay(1);
}
 
