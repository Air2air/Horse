

static int Stride_Thigh(struct pt * pt) {
  static unsigned long PWM_High = THIGH_PWM_HIGH;
  static unsigned long Leg = THIGH;
  static unsigned long Wait = THIGH_WAIT;
  static unsigned long Duration = THIGH_DURATION;
  static unsigned long Start_Time_Marker;
  static unsigned long Go_PWM_High_Time = Wait;
  static unsigned long StartRampTime = Go_PWM_High_Time + Duration;
  static unsigned long GoOffTime;
  static unsigned long Stay_Off_Time;
  static unsigned long This_PWM;
  static unsigned long Next_Ramp_Time;

  PT_BEGIN(pt);
  while (1) {
    Start_Time_Marker = millis();

    //Start
    if (Print_Serial) {
      Serial_Start(Leg, Wait);
    }

    // Go PWM_HIGH
    PT_WAIT_UNTIL(pt, millis() - Start_Time_Marker >= Go_PWM_High_Time);
    Analog_Write(Leg, PWM_High);

    // Ramp Down
    PT_WAIT_UNTIL(pt, millis() - Start_Time_Marker >= StartRampTime);
    Next_Ramp_Time = (StartRampTime + Ramp_Time_Increment);// Different for this first one
    This_PWM = PWM_High - Ramp_PWM_Increment;// Different for this first one
    Analog_Write(Leg, This_PWM);

    PT_WAIT_UNTIL(pt, millis() - Start_Time_Marker >= Next_Ramp_Time);
    Next_Ramp_Time = (Next_Ramp_Time + Ramp_Time_Increment);
    This_PWM = This_PWM - Ramp_PWM_Increment;
    Analog_Write(Leg, This_PWM);

    PT_WAIT_UNTIL(pt, millis() - Start_Time_Marker >= Next_Ramp_Time);
    Next_Ramp_Time = (Next_Ramp_Time + Ramp_Time_Increment);
    This_PWM = This_PWM - Ramp_PWM_Increment;
    Analog_Write(Leg, This_PWM);

    PT_WAIT_UNTIL(pt, millis() - Start_Time_Marker >= Next_Ramp_Time);
    Next_Ramp_Time = (Next_Ramp_Time + Ramp_Time_Increment);
    This_PWM = This_PWM - Ramp_PWM_Increment;
    Analog_Write(Leg, This_PWM);

    PT_WAIT_UNTIL(pt, millis() - Start_Time_Marker >= Next_Ramp_Time);
    Next_Ramp_Time = (Next_Ramp_Time + Ramp_Time_Increment);
    This_PWM = This_PWM - Ramp_PWM_Increment;
    Analog_Write(Leg, This_PWM);

    PT_WAIT_UNTIL(pt, millis() - Start_Time_Marker >= Next_Ramp_Time);
    Next_Ramp_Time = (Next_Ramp_Time + Ramp_Time_Increment);
    This_PWM = This_PWM - Ramp_PWM_Increment;
    Analog_Write(Leg, This_PWM);

    PT_WAIT_UNTIL(pt, millis() - Start_Time_Marker >= Next_Ramp_Time);
    Next_Ramp_Time = (Next_Ramp_Time + Ramp_Time_Increment);
    This_PWM = This_PWM - Ramp_PWM_Increment;
    Analog_Write(Leg, This_PWM);

    PT_WAIT_UNTIL(pt, millis() - Start_Time_Marker >= Next_Ramp_Time);
    Next_Ramp_Time = (Next_Ramp_Time + Ramp_Time_Increment);
    This_PWM = This_PWM - Ramp_PWM_Increment;
    Analog_Write(Leg, This_PWM);

    PT_WAIT_UNTIL(pt, millis() - Start_Time_Marker >= Next_Ramp_Time);
    Next_Ramp_Time = (Next_Ramp_Time + Ramp_Time_Increment);
    This_PWM = This_PWM - Ramp_PWM_Increment;
    Analog_Write(Leg, This_PWM);

    // Ramp Down ended
    PT_WAIT_UNTIL(pt, millis() - Start_Time_Marker >= Next_Ramp_Time);
    GoOffTime = Next_Ramp_Time;
    Stay_Off_Time = Stride_Duration - Next_Ramp_Time;
    Analog_Write(Leg, PWM_LOW);
    if (Print_Serial) {
      Serial_Off(Leg, Next_Ramp_Time, Stay_Off_Time );
    }

    // Stride duration ended
    PT_WAIT_UNTIL(pt, millis() - Start_Time_Marker >= Stride_Duration); // End Loop if stride duration has elapsed
    if (Print_Serial) {
      Serial_End(Leg, Stride_Duration);
    }
    PT_END(pt);
  }
}
