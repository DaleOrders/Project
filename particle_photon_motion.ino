
int led1 = D4;

void setup ()
{
    pinMode(led1,OUTPUT);
    
    Particle.subscribe("motiondetected", handler);
}

void handler(const char *event, const char *data) {
    
    
    if(strcmp(event, "motiondetected")==0){
      digitalWrite(led1,HIGH);
      
     else{
            digitalWrite(led1,LOW);
     }
        //led is on for 10 minutes
        delay(600000);
            
    }

}
