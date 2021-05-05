
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
