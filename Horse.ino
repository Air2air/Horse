#include <Arduino.h>
#include <pt.h>

#define LEG_1 8
#define LEG_2 9
#define LEG_3 10
#define LEG_4 11

int Leg = 0;
unsigned long Wait = 0;
unsigned long Duration = 0;
unsigned long Leg_Off = 0;

unsigned long Time_Taken_Wait = 0;
unsigned long Time_Taken_High = 0;
unsigned long Time_Taken_Off = 0;

/* Outer Loop */
unsigned long Stride_Duration = 10000;


/* Leg 1 */
unsigned long Leg_1_Wait = 200;
unsigned long Leg_1_Duration = 2005;

/* Leg 2 */
unsigned long Leg_2_Wait = 4000;
unsigned long Leg_2_Duration = 2006;

/* Leg 3 */
unsigned long Leg_3_Wait = 1700;
unsigned long Leg_3_Duration = 1813;

/* Leg 4 */
unsigned long Leg_4_Wait = 1100;
unsigned long Leg_4_Duration = 1306;

bool Print_Serial = 1;

static int Stride(struct pt * pt, int Leg) {
  
  if (Leg == 1) {
    Wait = Leg_1_Wait;
    Duration = Leg_1_Duration;
  } else if (Leg == 2) {
    Wait = Leg_2_Wait;
    Duration = Leg_2_Duration;
  } else if (Leg == 3) {
    Wait = Leg_3_Wait;
    Duration = Leg_3_Duration;
  } else if (Leg == 4) {
    Wait = Leg_4_Wait;
    Duration = Leg_4_Duration;
  }

  if (millis() <= millis() + Stride_Duration) {

    static unsigned long last_Time_Marker = 0;
    static unsigned long Start_Time = millis();

    PT_BEGIN(pt);

    while (1) {

      if (Print_Serial) {
        Serial_Start(Leg, Wait);
      }

      last_Time_Marker = millis();

      PT_WAIT_UNTIL(pt, millis() - last_Time_Marker > Wait);


      digitalWrite(Leg, HIGH);

      if (Print_Serial) {
        Serial_Wait(Leg, Wait, Duration);
      }

      last_Time_Marker = millis();
      PT_WAIT_UNTIL(pt, millis() - last_Time_Marker > Duration);

      digitalWrite(Leg, LOW);

      if (Print_Serial) {
        Serial_Off(Leg, Duration);
      }

      PT_WAIT_UNTIL(pt, millis() >= Start_Time + Stride_Duration);

      Serial.print("Ending loop for Leg ");
      Serial.println(Leg);

      PT_END(pt);
    }

  }
  return Leg = 0;
}
