

int countDown = Stride_Duration / 1000;
unsigned long lastTick = 0;

void runCounter() {
  if (Print_Counter) {
    unsigned long currentMillis = millis();

    if (currentMillis - lastTick >= 1000) {
      if (countDown >= 0) countDown--;
      displayCountdownToSerial();
      lastTick += 1000;
    }
  }
}

void displayCountdownToSerial() {
  int secs = countDown % 60;
  Serial.print("Remaining: 0:0");
  Serial.print(secs);
  Serial.println(" secs");
}
