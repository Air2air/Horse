
/*--- Biasing ----*/
unsigned long HIP_PWM_HIGH = PWM_HIGH * Hip_Bias;
unsigned long THIGH_PWM_HIGH = PWM_HIGH * Thigh_Bias;
unsigned long KNEE_PWM_HIGH = PWM_HIGH * Knee_Bias;
unsigned long HOOF_PWM_HIGH = PWM_HIGH * Hoof_Bias;

/*--- Ramp Increment ----*/
unsigned long HIP_PWM_INCREMENT = HIP_PWM_HIGH / 8 ;
unsigned long THIGH_PWM_INCREMENT = THIGH_PWM_HIGH / 8 ;
unsigned long KNEE_PWM_INCREMENT = KNEE_PWM_HIGH / 8 ;
unsigned long HOOF_PWM_INCREMENT = HOOF_PWM_HIGH / 8 ;


unsigned long PWM_VAL = 0;


/*--- Analog Write ----*/
void Analog_Write(int Leg, int PWM_VAL) {
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
