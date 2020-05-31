int SensorPin = D6;  //  reads data from the sensor


unsigned long starttime;
unsigned long sampletime_ms = 30000;  //30 seconds sampling time
unsigned long triggerOnP2;
unsigned long triggerOffP2;
unsigned long pulseLengthP2;
unsigned long durationP2;
boolean valP2 = HIGH;
boolean triggerP2 = false;
double ratioP2 = 0;  //rate is initally 0
double PM25 = 0; // PM is initally 0

String colour; // tells the color
String category;  // tells the category of air


//check wifi
const uint32_t msRetryTime  =   30000; // stop trying to connect to the internet after 30sec of boot up
SYSTEM_MODE(SEMI_AUTOMATIC)
SYSTEM_THREAD(ENABLED)
// end of Wifi checking

TCPClient client;

#define THINGNAME "AirQualDev" // Name of my device


void setup()
{
  
  pinMode(SensorPin,INPUT);
  starttime = millis();

   Particle.connect();  //if it can't connect to the internet in 30 seconds of booting up it will turn the Wifi off and keep running
     if (!waitFor(Particle.connected, msRetryTime))
    WiFi.off(); // if the wifi comes back it will not turn the wifi on the photon.  You must reset it to get it back on wifi.

    delay(120000); //this delays the sensor for 2 minutes while it warms up

}

void loop(){ 

      valP2 = digitalRead(SensorPin);

     if(valP2 == LOW && triggerP2 == false){
    triggerP2 = true;
    triggerOnP2 = micros();
    }

    if (valP2 == HIGH && triggerP2 == true){
      triggerOffP2 = micros();
      pulseLengthP2 = triggerOffP2 - triggerOnP2;
      durationP2 = durationP2 + pulseLengthP2;
      triggerP2 = false;
     }
    if ((millis() - starttime) > sampletime_ms) {  /

    ratioP2 = durationP2/(sampletime_ms*10.0);  //  percentage 0=>100   Percent of time this pin was triggered during sampling.
    //a higher ratio tells dirtier air. 

    PM25= (ratioP2 * ratioP2 * .1809 + 3.8987 * ratioP2)/100;  //This is the calibration between the ratio and PM25 in ug/m3

    

    if (PM25 < 10)   
    {
        colour = "Green";
        category = "Good";
    }
    if (PM25 < 20 && PM25 > 10) 
    {
        colour = "Cyan";
        category = "Satisfactory";

    }
     if (PM25 < 30 && PM25 > 20) 
    {
        colour = "Blue";
        category = "Moderately satisfactory";
        
    }
     if (PM25 < 40 && PM25 > 30) 
    {
        colour = "Magenta";
        category = "Poor";

    }
     if (PM25 < 100 && PM25 > 40)
    {
        colour = "Red";
        category = "Very poor";

    }
       if (PM25 > 100)  
    {
        colour = "Black";
        category = "Severe";
        
    }

 

    Particle.publish("colour", String(colour));
    delay(2000);
    Particle.publish("PM25", String(PM25));
    delay(2000);
    Particle.publish("ratioP2", String(ratioP2));
    delay(2000);
    Particle.publish("category", String(category));
    delay(2000);

   
    if (client.connect("dweet.io", 80))
    // Go to  http://dweet.io/follow/thingname  to see the results in your browser. change "thingname" to your thingname in the web address.
    {
      client.print("GET /dweet/for/");
      client.print(THINGNAME);
      client.print("?ratioP2=");  
      client.print(ratioP2);
      client.print("&PM25=");  
      client.print(PM25);
      client.println(" HTTP/1.1");
      client.println("Host: dweet.io");
      client.println("Connection: close");
      client.println();
     }
    
    
  
  

      durationP2 = 0;  //resets the lowpulseoccupancy back to zero to start the next sample
      starttime = millis(); // set the start time to what time it is now.
      // go back to the top of the loop and start sampling again

}

}