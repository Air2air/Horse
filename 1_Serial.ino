

void Print_Leg(int Leg) {
  if (Leg == HIP) {
    Serial.print("Hip ");
  } else if (Leg == THIGH) {
    Serial.print("Thigh ");
  } else if (Leg == KNEE) {
    Serial.print("Knee ");
  } else {
    Serial.print("Hoof ");
  }
}

void Serial_Start(int Leg, int Wait) {
  Serial.print("\n");
  Print_Leg(Leg);
  Serial.print("waiting ");
  Serial.print(Wait);
  Serial.println(" to start.");
}

void Serial_Wait(int Leg, int Go_PWM_High_Time, int PWM_High, int Duration ) {
  Print_Leg(Leg);
  Serial.print("going HIGH at ");
  Serial.print(Go_PWM_High_Time);
  Serial.print(" at ");
  Serial.print(PWM_High);
  Serial.print(" PWM for ");
  Serial.println(Duration);
}



void Serial_Off(int Leg, int GoOffTime, int StayOffTime) {
  Print_Leg(Leg);
  Serial.print("going OFF at ");
  Serial.print(GoOffTime);
  Serial.print(" with ");
  Serial.print(StayOffTime);
  Serial.println(" remaining");
}

void Serial_End(int Leg, int EndLoopTime) {
  Serial.print("Ended ");
  Print_Leg(Leg);
  Serial.print("after ");
  Serial.println(EndLoopTime);
}
