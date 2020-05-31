
int sensor = 26;


void setup() {
    
    
}

void loop() {
  delay(3000);
   if (digitalRead(sensor) == HIGH) 
   {
       Particle.publish("motiondetected", "motiondetected", MY_DEVICES);
   }
}















