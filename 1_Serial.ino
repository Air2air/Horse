

void Serial_Start(int Leg, int Wait) {
  Serial.print("\nStarting Leg ");
  Serial.print(Leg);
  Serial.print(", waiting ");
  Serial.print(Wait);
  Serial.println(" to start.");
}

void Serial_Wait(int Leg, int Go_PWM_High_Time, int PWM_High, int Duration ) {
  Serial.print("Leg ");
  Serial.print(Leg);
  Serial.print(" going HIGH at ");
  Serial.print(Go_PWM_High_Time);
  Serial.print(" at ");
  Serial.print(PWM_High);
  Serial.print(" PWM for ");
  Serial.println(Duration);
}

void Serial_Off(int Leg, int GoOffTime, int StayOffTime) {
  Serial.print("Leg ");
  Serial.print(Leg);
  Serial.print(" going OFF at ");
  Serial.print(GoOffTime);
  Serial.print(" with ");
  Serial.print(StayOffTime);
  Serial.println(" remaining");
}

void Serial_End(int Leg, int EndLoopTime) {
  Serial.print("Ended Leg ");
  Serial.print(Leg);
  Serial.print(" after ");
  Serial.println(EndLoopTime);
}
