int positionShuffle() {
  static int lastPickedNumber = -1; // Declare a static variable to store the last picked number
  int pickedNumber;

  do {
    pickedNumber = random(1, 6); // Generate a random number between 1 and 5 
  } while (pickedNumber == lastPickedNumber); // Keep generating until we get a number different from the last picked number

  lastPickedNumber = pickedNumber; // Store the picked number for the next function call
  return pickedNumber; // Return the picked number
}
