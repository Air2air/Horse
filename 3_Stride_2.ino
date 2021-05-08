
static int Stride2(struct pt * pt) {
  static unsigned long Leg = LEG_2;
  static unsigned long Wait = LEG_2_WAIT;
  static unsigned long Duration = LEG_2_DURATION;
  static unsigned long Start_Time_Marker;
  static unsigned long GoHighTime = Wait;
  static unsigned long GoOffTime = GoHighTime + Duration;
  static unsigned long StayOffTime = Stride_Duration - GoOffTime;
  static unsigned long EndLoopTime = Stride_Duration;
  PT_BEGIN(pt);
  while (1) {
    Start_Time_Marker = millis();
    //Start
    if (Print_Serial) {
      Serial_Start(Leg, Wait);
    }
    // Go High
    PT_WAIT_UNTIL(pt, millis() - Start_Time_Marker >= GoHighTime);
    digitalWrite(Leg, HIGH);
    if (Print_Serial) {
      Serial_Wait(Leg, GoHighTime, Duration);
    }
    // High Duration ended
    PT_WAIT_UNTIL(pt, millis() - Start_Time_Marker >= GoOffTime);
    digitalWrite(Leg, LOW);
    if (Print_Serial) {
      Serial_Off(Leg, GoOffTime, StayOffTime );
    }
    // Stride duration ended
    PT_WAIT_UNTIL(pt, millis() - Start_Time_Marker >= EndLoopTime); // End Loop if stride duration has elapsed
    if (Print_Serial) {
      Serial_End(Leg, EndLoopTime);
    }
    PT_END(pt);
  }
}
