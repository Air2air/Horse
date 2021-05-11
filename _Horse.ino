// #include <Arduino.h>
#include <pt.h>

int HIP = 11;
int THIGH = 10;
int KNEE = 9;
int HOOF = 6;

int Leg = 0;
unsigned long Wait = 0;
unsigned long Duration = 0;


bool Print_Serial = 1;

/* Master PWM */
int PWM_HIGH = 28;
int PWM_LOW = 0;

/* Outer Loop */
unsigned long Stride_Duration = 8250;

/* Ramp */
unsigned long Ramp_Time_Increment = 70;
unsigned long Ramp_PWM_Increment = 0;

/* Hip */
float Hip_Bias = .9;
unsigned long HIP_WAIT = 200;
unsigned long HIP_DURATION = 3000;

/* Thigh */
float Thigh_Bias = 1;
unsigned long THIGH_WAIT = 5000;
unsigned long THIGH_DURATION = 2000;

/* Leg */
float Knee_Bias = 1;
unsigned long KNEE_WAIT = 1000;
unsigned long KNEE_DURATION = 2000;

/* Hoof */
float Hoof_Bias = .5;
unsigned long HOOF_WAIT =1000;
unsigned long HOOF_DURATION = 2000;


static struct pt pt1, pt2, pt3, pt4;

void setup() {
  pinMode(HIP, OUTPUT);
  pinMode(THIGH, OUTPUT);
  pinMode(KNEE, OUTPUT);
  pinMode(HOOF, OUTPUT);

  PT_INIT(&pt1);
  PT_INIT(&pt2);
  PT_INIT(&pt3);
  PT_INIT(&pt4);

  Serial.begin(115200);
  while (! Serial);

  analogWrite(HIP, 0);
  analogWrite(THIGH, 0);
  analogWrite(KNEE, 0);
  analogWrite(HOOF, 0);
}
