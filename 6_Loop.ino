
unsigned long previousMillis = 0;

void loop() {
  Stride_Hip(&pt1);
  Stride_Thigh(&pt2);
  Stride_Knee(&pt3);
  Stride_Hoof(&pt4);
}
