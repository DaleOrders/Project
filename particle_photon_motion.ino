//Second Photon, LED
int led1 = D4;

void setup ()
{
    pinMode(led1,OUTPUT);
    pinMode(buzz,OUTPUT);

    
    Particle.subscribe("motiondetected", handler);
    delay(3000);
}

void handler(const char *event, const char *data) {
    
    if(strcmp(event, "motiondetected")==0){
      digitalWrite(led1,HIGH);
      delay(200);
      digitalWrite(led1,LOW);
      
        
    }

}