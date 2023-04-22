void customDelay(int milliseconds) {
  unsigned long startTime = millis(); // get the current time
  while (millis() - startTime < milliseconds) {
    // do nothing and wait for the specified time
  }
  display.display(); //update the OLED display even during delays
  analogWrite (A1, velocity * 10); // write our velocity to Bonsai through pin A1
}
