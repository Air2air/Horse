

int countDown = Stride_Duration / 1000;  
unsigned long lastTick = 0;

void runCounter(){

  unsigned long currentMillis = millis();
  
  if(currentMillis - lastTick >= 1000){
    countDown--;
    displayCountdownToSerial(); 
    lastTick += 1000;   
  }  
}

void displayCountdownToSerial(){
  int secs = countDown % 60;
  Serial.print("Remaining = ");
  Serial.print("0:");
  Serial.println(secs);
}
