unsigned long HIP_PWM_HIGH = PWM_HIGH * Hip_Bias;
unsigned long THIGH_PWM_HIGH = PWM_HIGH * Thigh_Bias;
unsigned long KNEE_PWM_HIGH = PWM_HIGH * Knee_Bias;
unsigned long HOOF_PWM_HIGH = PWM_HIGH * Hoof_Bias;
unsigned long PWM_VAL = 0;

void Analog_Write(unsigned long Leg, int PWM_VAL) {
  Print_Leg(Leg);
  if (PWM_VAL <= 0) {
    analogWrite(Leg, 0);
    if (Print_Serial) {
      Serial.println("PWM BELOW 0");
    }
  }
  else {
    analogWrite(Leg, PWM_VAL);
    if (Print_Serial) {
      Serial.print("PWM ");
      Serial.println(PWM_VAL);
    }
  }
}
