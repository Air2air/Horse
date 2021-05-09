
static int Stride1(struct pt * pt) {
  static unsigned long PWM_High = LEG_1_PWM_HIGH;
  static unsigned long Leg = LEG_1;
  static unsigned long Wait = LEG_1_WAIT;
  static unsigned long Duration = LEG_1_DURATION;
  static unsigned long Start_Time_Marker;
  static unsigned long Go_PWM_High_Time = Wait;
  static unsigned long GoOffTime = Go_PWM_High_Time + Duration;
  static unsigned long StayOffTime = Stride_Duration - GoOffTime;
  static unsigned long EndLoopTime = Stride_Duration;
  PT_BEGIN(pt);
  
  while (1) {

    Start_Time_Marker = millis();
    //Start
    if (Print_Serial) {
      Serial_Start(Leg, Wait);
    }
    // Go PWM_HIGH
    PT_WAIT_UNTIL(pt, millis() - Start_Time_Marker >= Go_PWM_High_Time);
    analogWrite(Leg, PWM_High);
    if (Print_Serial) {
      Serial_Wait(Leg, Go_PWM_High_Time, PWM_High, Duration);
    }
    // PWM_High Duration ended
    PT_WAIT_UNTIL(pt, millis() - Start_Time_Marker >= GoOffTime);
    analogWrite(Leg, PWM_LOW);
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
