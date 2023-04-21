//Inter-trial delay, specify low to high range in seconds
void timeout(int low, int high) {
  random_delay = random(low, high);
  startTimeout = millis();
  //print delay
  while (millis() - startTimeout < random_delay*1000) {
    Serial.print("Timeout: ");
    Serial.println(random_delay - (millis() - startTimeout)/1000.0);
    UpdateDisplay();
  }
  Trial++;
}
