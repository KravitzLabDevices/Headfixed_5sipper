
//specify which spout position to dispense
void dispense(int spout) {

  Serial.println("Dispense");

  //dispense (if it is a rewarded trial), specified spout position will actuate corresponding solenoid
  if (spout == 0) {
    digitalWrite(A1, HIGH);
    delay(volume * 10);     // adjust this independently for each infusion type to achieve 2uL volume
    digitalWrite(A1, LOW);
    UpdateDisplay();
  }

  if (spout == 1) {
    digitalWrite(A2, HIGH);
    delay(volume * 10);     // adjust this independently for each infusion type to achieve 2uL volume  
    digitalWrite(A2, LOW);
    UpdateDisplay();
  }

  if (spout == 2) {
    digitalWrite(A3, HIGH);
    delay(volume * 10);     // adjust this independently for each infusion type to achieve 2uL volume
    digitalWrite(A3, LOW);
    UpdateDisplay();
  }

  if (spout == 3) {
    digitalWrite(A4, HIGH);
    delay(volume * 10);     // adjust this independently for each infusion type to achieve 2uL volume
    digitalWrite(A4, LOW);
    UpdateDisplay();
  }

  if (spout == 4) {
    digitalWrite(A5, HIGH);
    delay(volume * 10);     // adjust this independently for each infusion type to achieve 2uL volume
    digitalWrite(A5, LOW);
    UpdateDisplay();
  }
}
