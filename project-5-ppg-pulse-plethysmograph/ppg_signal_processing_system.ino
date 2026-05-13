int analogPin = A3;   // output of the non-inverting amplifier connected to analog pin 3 on arduino board
int val = 0;          // variable created to store the value read

void setup() {
    Serial.begin(1200);      // Setup serial, and set it to 1200 (to read the signal slower)
}

void loop() {
    val = analogRead(analogPin);   // Read the signal arriving in the input pin (A3)
    Serial.println(val);           // Debug and display the value on the serial plotter
}
