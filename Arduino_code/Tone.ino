/**
   Plays a tone and sends output to Bonsai.
   Tone frequency and duration are specified in the function call.
   Output is sent to Bonsai via digital pin 7.
   The function also updates the display.

   @param frequency The frequency of the tone to be played.
   @param duration The duration of the tone in milliseconds.
*/
void playTone(int frequency, int duration) {

  // Play tone using specified frequency and duration
  tone(12, frequency, duration);

  // Send output to Bonsai via digital pin 13
  digitalWrite(13, HIGH);

  // Delay for duration of tone
  delay(duration);

  // Turn off output to Bonsai
  digitalWrite(13, LOW);

  // Update the OLED display
  UpdateDisplay();

  // Delay before next action
  customDelay(3900);
}


/**
   Generates white noise by playing random tones through a speaker.

   Parameters:
   None

   Returns:
   None
*/
void noise() {
  // Play 50 random tones with a duration of 20 ms
  for (int i = 0; i < 50; i++) {
    // Generate a random frequency between 20 Hz and 200 Hz and play it through pin 12
    tone(12, random(20, 200), 20);
    // Wait for 20 ms before playing the next tone
    customDelay(20);
    // Update the display to show any changes
    UpdateDisplay();
  }
}
