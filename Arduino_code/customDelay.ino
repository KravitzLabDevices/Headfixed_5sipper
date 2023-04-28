void customDelay(int milliseconds) {
  unsigned long startTime = millis(); // get the current time
  while (millis() - startTime < milliseconds) {
    // do nothing and wait for the specified time
  }
  UpdateDisplay(); //update the OLED display even during delays
}
