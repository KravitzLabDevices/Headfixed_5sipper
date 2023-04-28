// Update the OLED display with Trial Number, Timeout, Spout Offset

void UpdateDisplay() {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Trial Number: ");
  display.println(Trial);
  display.print("Offset: ");
  display.println(offset);
  display.print("Timeout: ");
  display.println(random_delay - (millis() - startTimeout) / 1000.0);
  display.print("Spout:");
  display.println(selection);
  display.display();
}
