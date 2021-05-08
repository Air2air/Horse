#include <Arduino.h>
#include <pt.h>

#define LEG_1 8
#define LEG_2 9
#define LEG_3 10
#define LEG_4 11

int Leg = 0;
unsigned long Wait = 0;
unsigned long Duration = 0;
unsigned long LEG_Off = 0;

unsigned long Time_Taken_WAIT = 0;
unsigned long Time_Taken_High = 0;
unsigned long Time_Taken_Off = 0;

/* Outer Loop */
unsigned long Stride_Duration = 10000;


/* Leg 1 */
unsigned long LEG_1_WAIT = 200;
unsigned long LEG_1_DURATION = 2005;


/* Leg 2 */
unsigned long LEG_2_WAIT = 4000;
unsigned long LEG_2_DURATION = 2006;

/* Leg 3 */
unsigned long LEG_3_WAIT = 1700;
unsigned long LEG_3_DURATION = 1813;

/* Leg 4 */
unsigned long LEG_4_WAIT = 1100;
unsigned long LEG_4_DURATION = 1306;

bool Print_Serial = 1;
bool Print_Counter = 0;

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
