//Second Photon, LED
int led1 = D4;

void setup ()
{
    pinMode(led1,OUTPUT);
    //wait for 10 minutes before 
    Particle.subscribe("motiondetected", handler);
    delay(600000);
}

void handler(const char *event, const char *data) {
    
    
    if(strcmp(event, "motiondetected")==0){
      digitalWrite(led1,HIGH);
      
     else{
            digitalWrite(led1,LOW);
     }
            
    }

}
