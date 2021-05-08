
static int Stride1(struct pt * pt) {
  PT_BEGIN(pt);
  while (1) {
    static unsigned long Start_Time_Marker = millis();
    if (Print_Serial) {
      Serial_Start(LEG_1, LEG_1_WAIT);
    }
    // Go High
    PT_WAIT_UNTIL(pt, millis() - Start_Time_Marker >= LEG_1_GO_HIGH_TIME);
    digitalWrite(Leg, HIGH);
    if (Print_Serial) {
      Serial_Wait(LEG_1, LEG_1_GO_HIGH_TIME, LEG_1_DURATION);
    }
    // Go Off
    PT_WAIT_UNTIL(pt, millis() - Start_Time_Marker >= LEG_1_GO_OFF_TIME);
    digitalWrite(Leg, LOW);
    if (Print_Serial) {
      Serial_Off(LEG_1, LEG_1_GO_OFF_TIME, LEG_1_END_LOOP_TIME );
    }
    // End Loop
    PT_WAIT_UNTIL(pt, millis() - Start_Time_Marker >= LEG_1_END_LOOP_TIME); 
    if (Print_Serial) {
      Serial_End(LEG_1, LEG_1_END_LOOP_TIME);
    }
    PT_END(pt);
  }
}
