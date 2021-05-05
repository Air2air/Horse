#include <Arduino.h>
#include <pt.h>

#define LEG_1 8
#define LEG_2 9
#define LEG_3 10
#define LEG_4 11

int Leg = 0;
unsigned int Delay_For = 0;
unsigned int Duration = 0;
unsigned int Leg_Off = 0;

unsigned long Time_Taken_Wait = 0;
unsigned long Time_Taken_High = 0;
unsigned long Time_Taken_Off = 0;

/* Outer Loop */
const int Stride_Duration = 10000;


/* Leg 1 */
const int Leg_1_Delay_For = 200;
const int Leg_1_Duration = 2005;

/* Leg 2 */
const int Leg_2_Delay_For = 4000;
const int Leg_2_Duration = 2006;

/* Leg 3 */
const int Leg_3_Delay_For = 1700;
const int Leg_3_Duration = 1813;

/* Leg 4 */
const int Leg_4_Delay_For = 1100;
const int Leg_4_Duration = 1306;



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


static struct pt pt1, pt2, pt3, pt4;

void setup() {
  pinMode(LEG_1, OUTPUT);
  pinMode(LEG_2, OUTPUT);
  pinMode(LEG_3, OUTPUT);
  pinMode(LEG_4, OUTPUT);

  PT_INIT(&pt1);
  PT_INIT(&pt2);
  PT_INIT(&pt3);
  PT_INIT(&pt4);

  Serial.begin(115200);
  while (! Serial);
}

void loop() {
  Stride(&pt1, 1);
  Stride(&pt2, 2);
  Stride(&pt3, 3);
  Stride(&pt4, 4);
}
