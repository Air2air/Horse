

static int Stride(struct pt * pt, int Leg)

{
  if (Leg == 1) {
    Delay_For = Leg_1_Delay_For;
    Duration = Leg_1_Duration;
  } else if (Leg == 2) {
    Delay_For = Leg_2_Delay_For;
    Duration = Leg_2_Duration;
  } else if (Leg == 3) {
    Delay_For = Leg_3_Delay_For;
    Duration = Leg_3_Duration;
  } else if (Leg == 4) {
    Delay_For = Leg_4_Delay_For;
    Duration = Leg_4_Duration;
  }

  if (millis() <= millis() + Stride_Duration) {

    static unsigned long last_Time_Marker = 0;
    static unsigned long Start_Time = millis();

    PT_BEGIN(pt);

    while (1) {

      Serial.print("\nStarting Leg ");
      Serial.print(Leg);
      Serial.print(" and waiting ");
      Serial.print(Delay_For);
      Serial.println("ms to start.");

      last_Time_Marker = millis();
      PT_WAIT_UNTIL(pt, millis() - last_Time_Marker > Delay_For);

      digitalWrite(Leg, HIGH);

      Serial.print("Leg ");
      Serial.print(Leg);
      Serial.print(" waited ");
      Serial.print(Delay_For);
      Serial.print("ms and is HIGH for ");
      Serial.print(Duration);
      Serial.println("ms.");

      last_Time_Marker = millis();
      PT_WAIT_UNTIL(pt, millis() - last_Time_Marker > Duration);

      digitalWrite(Leg, LOW);

      Serial.print("Leg ");
      Serial.print(Leg);
      Serial.print(" went OFF after ");
      Serial.print(Duration);
      Serial.println("ms.");

      PT_WAIT_UNTIL(pt, millis() >= Start_Time + Stride_Duration);

      Serial.print("Ending loop for Leg ");
      Serial.println(Leg);

      PT_END(pt);
    }

  }
  return Leg = 0;
}
