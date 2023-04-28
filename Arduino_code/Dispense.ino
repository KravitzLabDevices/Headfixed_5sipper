
//specify which spout position to dispense
void dispense(int selection) {

  Serial.println("Dispense");

  //dispense (if it is a rewarded trial), specified spout position will actuate corresponding solenoid
  if (selection == 1) {
    digitalWrite(A1, HIGH);
    digitalWrite(13, HIGH);
    delay(volume * 10);     // adjust this independently for each infusion type to achieve 2uL volume
    digitalWrite(A1, LOW);
    // Send output to Bonsai via digital pin 13
    digitalWrite(13, LOW);
    UpdateDisplay();

  }

  if (selection == 2) {
    digitalWrite(A2, HIGH);
    digitalWrite(13, HIGH);
    delay(volume * 10);     // adjust this independently for each infusion type to achieve 2uL volume
    digitalWrite(A2, LOW);
    // Send output to Bonsai via digital pin 13
    digitalWrite(13, LOW);
    UpdateDisplay();
  }

  if (selection == 3) {
    digitalWrite(A3, HIGH);
    digitalWrite(13, HIGH);
    delay(volume * 10);     // adjust this independently for each infusion type to achieve 2uL volume
    digitalWrite(A3, LOW);
    // Send output to Bonsai via digital pin 13
    digitalWrite(13, LOW);
    UpdateDisplay();
  }

  if (selection == 4) {
    digitalWrite(A4, HIGH);
    digitalWrite(13, HIGH);
    delay(volume * 10);     // adjust this independently for each infusion type to achieve 2uL volume
    digitalWrite(A4, LOW);
    // Send output to Bonsai via digital pin 13
    digitalWrite(13, LOW);
    UpdateDisplay();
  }

  if (selection == 5) {
    digitalWrite(A5, HIGH);
    digitalWrite(13, HIGH);
    delay(volume * 10);     // adjust this independently for each infusion type to achieve 2uL volume
    digitalWrite(A5, LOW);
    // Send output to Bonsai via digital pin 13
    digitalWrite(13, LOW);
    UpdateDisplay();
  }
}
