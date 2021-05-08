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
