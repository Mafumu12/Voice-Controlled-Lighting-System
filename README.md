# Voice-Controlled-Lighting-System
  ## Problem Definiton
 ### Description
 - The Voice Controlled Lighting system is an automation system that involves the controlling of lights using voice commands with the aid of a mobile device such as a Smartphone or tablet over the internet. The light controlling features it provides are:
    -  Blinking
    -  Fading
    -  Turning on and off
 ### Goal of the project
 - Traditionally the process of controlling lights such as turning a light on or off requires an individual to be physically present at the location of the switch. The position of the switch only favors the physical abilities of an average human being and anyone that does not fit that description e.g. the disabled, is not considered.  The voice controlled lighting system enables us to control lights remotely and puts into consideration anyone with the ability to speak.
  ## Working logic of the system
  - The NODECU-ESP32S development board will be used as a web server  and a microcontroller. To use it as a web server, the microcontroller is connected to a WIFI network as a station. When the microcontroller connects, it collects the WIFI networks IP address. Any device connected to the same WIFI network as the microcontroller is able to access the web server through the IP address obtained.
  - To control the lights:
      - A user records a voice command using a voice recognition application installed 
        on the mobile device.
      - The voice recognition application converts the audio input from the user into a 
        text  and sends it to  the NODEMCU-ESP32S web server via.
      - The text is then compared with the predefined string of voice commands  stored 
        on the microcontroller .
      - If the text matches with the string, it is sent back to the application 
       installed on the mobile device.
      - The application has a Text To Speech recognizer which then converts text to an 
        audio output.
      - The LED lights connected to microcontroller then respond accordingly.
 ### Flow Chart

 ![image](https://github.com/Mafumu12/Voice-Controlled-Lighting-System/assets/89388706/5caff864-197a-4c44-97e5-83bdf5e6f02b)

 ## REQUIREMENTS
 Since this is an embedded system it has the software and 
 hardware part.
 ### SOFTWARE
 - The software part involves the android application 
      which the user needs to record the voice commands. The android application is developed using flutter
 - To program the microcontroller, we use the Arduino IDE with C++
### Hardware
- Jumper wires
- 3 small led lights
- 3 220 ohms resistors
- NODEMCU-ESP32S
- Breadboard
## Methodology
### Steps taken to build the system
- The NODEMCU-ESP32S is first configured as a WIFI station
  Circuit design
- The  small LED lights are connected to the GPIO pins 
  15,5 and 14 of the microcontroller. The longer leg of 
 the led pin is the anode and it is connect in series to a 
 resistor which is then connected to the GPIO pin. The 
 shorter leg is the cathode which connected to the GND pin 
 of the microcontroller.
- The voice commands are predefined and the light controlling features are coded and uploaded to the microcontroller using the Arduino IDE.
- After the hardware is developed, the mobile application is developed. we first start with the front end which the user interface and then we add functionality to it in the back end. 
 


 




 
 

  


   
