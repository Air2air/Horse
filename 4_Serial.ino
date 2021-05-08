


void Serial_Start(int Leg, int Wait) {
  Serial.print("\nStarting Leg ");
  Serial.print(Leg);
  Serial.print(" and waiting ");
  Serial.print(Wait);
  Serial.println("ms to start.");
}

void Serial_Wait(int Leg, int Wait, int Duration ) {
  Serial.print("Leg ");
  Serial.print(Leg);
  Serial.print(" waited ");
  Serial.print(Wait);
  Serial.print("ms and is HIGH for ");
  Serial.print(Duration);
  Serial.println("ms.");
}

void Serial_Off(int Leg, int Duration) {
  Serial.print("Leg ");
  Serial.print(Leg);
  Serial.print(" went OFF after ");
  Serial.print(Duration);
  Serial.println("ms.");
}
