void UpdateDisplay() {

  int16_t encoderPosition = ss.getEncoderPosition();
  distance = (encoderPosition - prevPosition) * 4; // transform encoder difference to centimers distance traveled
  if (distance != 0) {
    unsigned long encoderTime = millis();
    timeDifference = (encoderTime - prevTime); // millis and convert back to seconds
    velocity = (distance / timeDifference) * 1000;
    Serial.println(velocity);
    prevPosition = encoderPosition;
    prevTime = encoderTime;
  }

  // Update the OLED display with Trial Number, Wheel Position, Timeout
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Trial Number: ");
  display.println(Trial);
  display.print("Wheel: ");
  display.println(encoderPosition);
  display.print("Velocity: ");
  display.println(velocity);
  display.print("Offset: ");
  display.println(offset);
  display.print("Timeout: ");
  display.println(random_delay - (millis() - startTimeout) / 1000.0);
  display.display();
}
