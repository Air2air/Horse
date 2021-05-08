
unsigned long previousMillis = 0;

void loop() {
  unsigned long currentMillis = millis();
  runCounter();
  //Stride1(&pt1);
  Stride2(&pt2);
  Stride3(&pt3);
  Stride4(&pt4);

}
