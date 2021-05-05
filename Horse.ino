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
