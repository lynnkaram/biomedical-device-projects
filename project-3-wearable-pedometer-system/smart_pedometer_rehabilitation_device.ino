#include <Adafruit_CircuitPlayground.h> //installs the adafruit circuit playground library

int nb_steps = 0; //initializes an integer value which counts the number of steps taken
int step_2 = 0; //initializes the value which will hold the previous value taken from analogRead(A4) and keeps track of it
float total_steps = 10; //Initializes a float value which represents the number of steps the patient must take (assigned by the doctor).
                        // It's a float value because the lights will turn on depending on the percentage of total steps that have been completed.

void setup() {
  Serial.begin(9600); // Initializes the serial communication at a rate of 9600 bits per second
  CircuitPlayground.begin(); // Initializes the circuit playground board
}

void loop(){
  int step_1 = analogRead(A4); // Initializes a variable which reads the analog signal obtained at pin A4
  if (step_1 >> step_2) { // Compares the step taken with the step before. If the current analog value is higher than the one before, then no step will be counted.
                          // If however, the current analog step value is lower than the previous one, then the peak on the plot has passed and a step can therefore be counted
    nb_steps++; // Increases the number steps (increments it by 1)
  }
  step_2 = step_1; // The new value of step_2 is now step_1. This is to make a new comparison.
  Serial.print(nb_steps); //Displays the number of steps taken on the serial monitor (this was used during the testing phase to know if the device was measuring the steps accurately)
  delay(100); //Delay of 100 ms between each measurement taken
  CircuitPlayground.clearPixels(); //No LEDs are turned on in the beginning.

  if ((nb_steps >= 0) && (nb_steps < 0.1*total_steps)) { //If the number of steps is under 10% of the total steps needed, all lights are red
    CircuitPlayground.setPixelColor(0, 255, 0, 0); //Turns LED 0 red
    CircuitPlayground.setPixelColor(1, 255, 0, 0); //Turns LED 1 red
    CircuitPlayground.setPixelColor(2, 255, 0, 0); //Turns LED 2 red
    CircuitPlayground.setPixelColor(3, 255, 0, 0); // ...
    CircuitPlayground.setPixelColor(4, 255, 0, 0);
    CircuitPlayground.setPixelColor(5, 255, 0, 0);
    CircuitPlayground.setPixelColor(6, 255, 0, 0);
    CircuitPlayground.setPixelColor(7, 255, 0, 0);
    CircuitPlayground.setPixelColor(8, 255, 0, 0);
    CircuitPlayground.setPixelColor(9, 255, 0, 0);
  }
  else if ((nb_steps >= (0.1*total_steps)) && (nb_steps < 0.2*total_steps)) { //if the number of steps is more than 10% but under 20% of the total steps needed, one light turns green)
    CircuitPlayground.setPixelColor(0, 0, 255, 0); //Turns LED 0 green
    CircuitPlayground.setPixelColor(1, 255, 0, 0); //Turns LED 1 red
    CircuitPlayground.setPixelColor(2, 255, 0, 0); //Turns LED 2 red
    CircuitPlayground.setPixelColor(3, 255, 0, 0); // ...
    CircuitPlayground.setPixelColor(4, 255, 0, 0);
    CircuitPlayground.setPixelColor(5, 255, 0, 0);
    CircuitPlayground.setPixelColor(6, 255, 0, 0);
    CircuitPlayground.setPixelColor(7, 255, 0, 0);
    CircuitPlayground.setPixelColor(8, 255, 0, 0);
    CircuitPlayground.setPixelColor(9, 255, 0, 0);
  }
  else if ((nb_steps >= (0.2*total_steps)) && (nb_steps < 0.3*total_steps)) { //Over 20% and under 30% of total steps
    CircuitPlayground.setPixelColor(0, 0, 255, 0); //Turns LED 0 green
    CircuitPlayground.setPixelColor(1, 0, 255, 0); //Turns LED 1 green
    CircuitPlayground.setPixelColor(2, 255, 0, 0); //Turns LED 2 red
    CircuitPlayground.setPixelColor(3, 255, 0, 0); //Turns LED 3 red
    CircuitPlayground.setPixelColor(4, 255, 0, 0); // ...
    CircuitPlayground.setPixelColor(5, 255, 0, 0);
    CircuitPlayground.setPixelColor(6, 255, 0, 0);
    CircuitPlayground.setPixelColor(7, 255, 0, 0);
    CircuitPlayground.setPixelColor(8, 255, 0, 0);
    CircuitPlayground.setPixelColor(9, 255, 0, 0);
  }
  else if ((nb_steps >= (0.3*total_steps)) && (nb_steps < 0.4*total_steps)) { //Over 30% and under 40% of total steps
    CircuitPlayground.setPixelColor(0, 0, 255, 0);
    CircuitPlayground.setPixelColor(1, 0, 255, 0);
    CircuitPlayground.setPixelColor(2, 0, 255, 0); // 3 LEDs are green
    CircuitPlayground.setPixelColor(3, 255, 0, 0);
    CircuitPlayground.setPixelColor(4, 255, 0, 0);
    CircuitPlayground.setPixelColor(5, 255, 0, 0);
    CircuitPlayground.setPixelColor(6, 255, 0, 0);
    CircuitPlayground.setPixelColor(7, 255, 0, 0);
    CircuitPlayground.setPixelColor(8, 255, 0, 0);
    CircuitPlayground.setPixelColor(9, 255, 0, 0);
  }
  else if ((nb_steps >= (0.4*total_steps)) && (nb_steps < 0.5*total_steps)) { //Over 40% and under 50% of total steps
    CircuitPlayground.setPixelColor(0, 0, 255, 0);
    CircuitPlayground.setPixelColor(1, 0, 255, 0);
    CircuitPlayground.setPixelColor(2, 0, 255, 0);
    CircuitPlayground.setPixelColor(3, 0, 255, 0); // 4 LEDs are green
    CircuitPlayground.setPixelColor(4, 255, 0, 0);
    CircuitPlayground.setPixelColor(5, 255, 0, 0);
    CircuitPlayground.setPixelColor(6, 255, 0, 0);
    CircuitPlayground.setPixelColor(7, 255, 0, 0);
    CircuitPlayground.setPixelColor(8, 255, 0, 0);
    CircuitPlayground.setPixelColor(9, 255, 0, 0);
  }
  else if ((nb_steps >= (0.5*total_steps)) && (nb_steps < 0.6*total_steps)) { //Over 50% and under 60% of total steps
    CircuitPlayground.setPixelColor(0, 0, 255, 0);
    CircuitPlayground.setPixelColor(1, 0, 255, 0);
    CircuitPlayground.setPixelColor(2, 0, 255, 0);
    CircuitPlayground.setPixelColor(3, 0, 255, 0);
    CircuitPlayground.setPixelColor(4, 0, 255, 0); // 5 LEDs are green
    CircuitPlayground.setPixelColor(5, 255, 0, 0);
    CircuitPlayground.setPixelColor(6, 255, 0, 0);
    CircuitPlayground.setPixelColor(7, 255, 0, 0);
    CircuitPlayground.setPixelColor(8, 255, 0, 0);
    CircuitPlayground.setPixelColor(9, 255, 0, 0);
  }
  else if ((nb_steps >= (0.6*total_steps)) && (nb_steps < 0.7*total_steps)) { //Over 60% and under 70% of total steps
    CircuitPlayground.setPixelColor(0, 0, 255, 0);
    CircuitPlayground.setPixelColor(1, 0, 255, 0);
    CircuitPlayground.setPixelColor(2, 0, 255, 0);
    CircuitPlayground.setPixelColor(3, 0, 255, 0);
    CircuitPlayground.setPixelColor(4, 0, 255, 0);
    CircuitPlayground.setPixelColor(5, 0, 255, 0); // 6 LEDs are green
    CircuitPlayground.setPixelColor(6, 255, 0, 0);
    CircuitPlayground.setPixelColor(7, 255, 0, 0);
    CircuitPlayground.setPixelColor(8, 255, 0, 0);
    CircuitPlayground.setPixelColor(9, 255, 0, 0);
  }
  else if ((nb_steps >= (0.7*total_steps)) && (nb_steps < 0.8*total_steps)) { //Over 70% and under 80% of total steps
    CircuitPlayground.setPixelColor(0, 0, 255, 0);
    CircuitPlayground.setPixelColor(1, 0, 255, 0);
    CircuitPlayground.setPixelColor(2, 0, 255, 0);
    CircuitPlayground.setPixelColor(3, 0, 255, 0);
    CircuitPlayground.setPixelColor(4, 0, 255, 0);
    CircuitPlayground.setPixelColor(5, 0, 255, 0);
    CircuitPlayground.setPixelColor(6, 0, 255, 0); //7 LEDs are green
    CircuitPlayground.setPixelColor(7, 255, 0, 0);
    CircuitPlayground.setPixelColor(8, 255, 0, 0);
    CircuitPlayground.setPixelColor(9, 255, 0, 0);
  }
  else if ((nb_steps >= (0.8*total_steps)) && (nb_steps < 0.9*total_steps)) { //Over 80% and under 90% of total steps
    CircuitPlayground.setPixelColor(0, 0, 255, 0);
    CircuitPlayground.setPixelColor(1, 0, 255, 0);
    CircuitPlayground.setPixelColor(2, 0, 255, 0);
    CircuitPlayground.setPixelColor(3, 0, 255, 0);
    CircuitPlayground.setPixelColor(4, 0, 255, 0);
    CircuitPlayground.setPixelColor(5, 0, 255, 0);
    CircuitPlayground.setPixelColor(6, 0, 255, 0);
    CircuitPlayground.setPixelColor(7, 0, 255, 0); //8 LEDs are green
    CircuitPlayground.setPixelColor(8, 255, 0, 0);
    CircuitPlayground.setPixelColor(9, 255, 0, 0);
  }
  else if ((nb_steps >= (0.9*total_steps)) && (nb_steps < total_steps)) { //Over 90% and under total steps
    CircuitPlayground.setPixelColor(0, 0, 255, 0);
    CircuitPlayground.setPixelColor(1, 0, 255, 0);
    CircuitPlayground.setPixelColor(2, 0, 255, 0);
    CircuitPlayground.setPixelColor(3, 0, 255, 0);
    CircuitPlayground.setPixelColor(4, 0, 255, 0);
    CircuitPlayground.setPixelColor(5, 0, 255, 0);
    CircuitPlayground.setPixelColor(6, 0, 255, 0);
    CircuitPlayground.setPixelColor(7, 0, 255, 0);
    CircuitPlayground.setPixelColor(8, 0, 255, 0); //9 LEDs are green
    CircuitPlayground.setPixelColor(9, 255, 0, 0);
  }
  else if (nb_steps == total_steps) { //total steps completed
    CircuitPlayground.setPixelColor(0, 255, 0, 0);
    CircuitPlayground.setPixelColor(1, 128, 128, 0);
    CircuitPlayground.setPixelColor(2, 0, 255, 0);
    CircuitPlayground.setPixelColor(3, 0, 128, 128);
    CircuitPlayground.setPixelColor(4, 0, 0, 255);
    CircuitPlayground.setPixelColor(5, 0xFF0000);
    CircuitPlayground.setPixelColor(6, 0x808000);
    CircuitPlayground.setPixelColor(7, 0x00FF00);
    CircuitPlayground.setPixelColor(8, 0x008080);
    CircuitPlayground.setPixelColor(9, 0x0000FF);
    //If total steps or more are completed, make a sound
    CircuitPlayground.playTone(500, 100); //plays a sound of 500 Hz for 100 ms
    CircuitPlayground.playTone(700, 100); //plays a sound of 700 Hz for 100 ms
    CircuitPlayground.playTone(900, 100); //plays a sound of 900 Hz for 100 ms
  }
  else if (nb_steps > total_steps) { // more than total steps completed
    CircuitPlayground.setPixelColor(0, 0, 255, 0);
    CircuitPlayground.setPixelColor(1, 0, 255, 0);
    CircuitPlayground.setPixelColor(2, 0, 255, 0);
    CircuitPlayground.setPixelColor(3, 0, 255, 0);
    CircuitPlayground.setPixelColor(4, 0, 255, 0);
    CircuitPlayground.setPixelColor(5, 0, 255, 0);
    CircuitPlayground.setPixelColor(6, 0, 255, 0);
    CircuitPlayground.setPixelColor(7, 0, 255, 0);
    CircuitPlayground.setPixelColor(8, 0, 255, 0);
    CircuitPlayground.setPixelColor(9, 0, 255, 0); //ALL LEDs are green
  }
}
