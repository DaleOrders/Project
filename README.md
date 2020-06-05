# Project

Overview 

My project is a multifunctional unit that is designed to offer convenience and efficiently to occupants in the home. It is designed to provide a remote access unit, which can be used to provide a more efficient solution to home automation. Currently the market offers Amazon Alexa and Google home which provide remote access to devices within the home, such a turning your favourite song on through a verbal command. The problem with this system is that they are only configured to work with smart devices that have been specifically designed, and are oftentimes, quite expensive to purchase. This presents a challenge for people like myself who have many devices that are not are not smart and therefore cannot be interfaced with such hardware. For example, my kettle requires that a lever be physically pushed down to turn on. Even with a smart plug, I would not be able to turn the kettle on automatically.

Setup:

Download and setup Raspbian OS using the following instructions https://www.raspberrypi.org/downloads/raspberry-pi-os/

Download and setup Particle Photon using the following instructions https://docs.particle.io/quickstart/photon/

Claim Photon https://docs.particle.io/workshops/photon-maker-kit-workshop/ch1/

Register Rasberry Pi on Particle Cloud using the following instructions https://iotdesignpro.com/projects/how-to-connect-raspberry-pi-with-particle-cloud-for-iot-applications

Register an IFTTT account https://ifttt.com/join

Join https://dweet.io/ or https://thingspeak.com/users/sign_up


User Manual: 

I will detail each component individually as follows:

Motion detected LED light

1. With a PIR motion detector, attach the VCC pin of the PIR to the 5V pin on the Raspberry Pi.
2. Using a female to female wire, attach the GND pin on the PIR detector to the GND pin on the Raspberry pi.
3. Using a female to female wire, attach the data pin to pin 17.
4. Create an IFTTT account and login. Choose to create your own applet, and enter the event details of “motiondetected” and select the Raspberry Pi as your device.
5. Using a female to male wire, attach the positive end (longer end) of the led to D4 on the Argon.
6. Attach the negative end (shorter end) of the led to GND, using a male to female wire.

Compile the code and flash both devices using the particle IDE

Sound Responsive LED Light

1.	Attach the ground pin on the KY-038 microphone to the ground on the breadboard using male to male wire.
2.	Attach the 5V pin on the microphone to the positive on the breadboard using male to male wire.
3.	Attach the data pin to pin 2 on the Arduino using a male to male.
4.	Use male to male wires to connect the GND pin to the negative of the breadboard and the 5V to the positive of the breadboard.
5.	Use a male to male wire to attach pin 4 on the Arduino to the positive end of the LED (longer end).
6.	Use a male to male wire to attach GND on the breadboard to the negative end of the LED (shorter end).
7.	Use the Arduino IDE, and compile and upload the code.

Clap to turn the light on and off.

Air Detection Monitor

1. Make the following attachments using female to female wires and a photon
GND ==> Pin1(GND)
D6 ==> Pin2 (Output)
Vin ==>Pin3(5V)
GND ==> 10k resistor ==> Pin5 (Input)
2. Create a dweet.io account and assign the name of the trigger to the same as what is it your code. 
3. This will use the RESTful API to create an APP that is accessible over the web and presents a graph of real-time air quality within the home.
4. Compile and upload the code to a particle photon.
5. Access real time measurements by going to http://dweet.io/follow/assignedname

Temperature and Humidity Sensor

1.	Attach the wire data pin on the DHT11 to D3 on the Arduino using male to male wire
2.	Attach the GND pin to the GND pin of the on the breadboard using male to male wire
3.	Attach the positive pin on the dht11 to 5V on the Arduino.
4.	On the I2C screen attach, SCL to A5, SDA to A4, GND to GND and VCC to 5V.
5.	Temperature and Humidity will appear on the I2C screen after you compile and upload code to Arduino IDE.

Turn Kettle on remotely

1.	Attach the yellow cord of the motor servo to D9 on the Arduino
2.	Attach the red cord of the motor servo to 5V pin of the Arduino using a male to male wire
3.	Attach the black cord of the motor servo to the GND pin of the Arduino using a male to male wire
4.	Adhere the servo to kettle using tape to keep it in the right position.
5.	Kettle will turn on after you compile and upload code to Arduino IDE.







