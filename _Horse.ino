#include <Arduino.h>
#include <pt.h>

byte LEG_1 = 11;
byte LEG_2 = 10;
byte LEG_3 = 9;
byte LEG_4 = 6;

int Leg = 0;
unsigned long Wait = 0;
unsigned long Duration = 0;


/* Master PWM */
int PWM_HIGH = 60;
int PWM_LOW = 0;

/* Outer Loop */
unsigned long Stride_Duration = 12000;

/* Leg 1 */
float Leg_1_Bias = .1;
unsigned long LEG_1_WAIT = 100;
unsigned long LEG_1_DURATION = 3000;

/* Leg 2 */
float Leg_2_Bias = .9;
unsigned long LEG_2_WAIT = 1000;
unsigned long LEG_2_DURATION = 3000;

/* Leg 3 */
float Leg_3_Bias = .9;
unsigned long LEG_3_WAIT = 3000;
unsigned long LEG_3_DURATION = 3000;

/* Leg 4 */
float Leg_4_Bias = .7;
unsigned long LEG_4_WAIT = 5000;
unsigned long LEG_4_DURATION = 3000;

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

  analogWrite(LEG_1, 0);
  analogWrite(LEG_2, 0);
  analogWrite(LEG_3, 0);
  analogWrite(LEG_4, 0);
}
