#include <Mouse.h> // import library which has mouse functions

int analogPin = A0; // assign A0 for Click input
int val0 = 0;       // variable which stores readings of A0

int analogPin1 = A1; // assign A1 for moving UP input
int val1 = 0;        // variable which stores readings of A1

int analogPin2 = A2; // assign A2 for moving DOWN input
int val2 = 0;        // variable which stores reading of A2

int analogPin3 = A3; // assign A3 for moving LEFT input
int val3 = 0;        // variable which stores reading of A3

int analogPin4 = A4; // assign A4 for moving RIGHT input
int val4 = 0;        // variable which stores reading of A4

char xAxis = 0;
char wheel = 0;

// Up movement speeds
char yAxis1 = -15;
char yAxis2 = -80;
char yAxis3 = -100;

// Down movement speeds
char yAxis4 = 15;
char yAxis5 = 80;
char yAxis6 = 100;

char yAxis = 0;

// Left movement speeds
char xAxis1 = -15;
char xAxis2 = -80;
char xAxis3 = -100;

// Right movement speeds
char xAxis4 = 15;
char xAxis5 = 80;
char xAxis6 = 100;

void setup() {
    Serial.begin(9600);
    Mouse.begin(); // initialize the mouse
}

void loop() {

    // CLICK
    val0 = analogRead(A0);

    if (val0 > 13) {
        Mouse.click();
        delay(500);
    }

    // UP AND DOWN CODE

    val1 = analogRead(A1);

    // MOVING UP
    if (val1 > 110) {
        Mouse.move(xAxis, yAxis1, wheel);
        delay(50);

    } else if (val1 > 160) {
        Mouse.move(xAxis, yAxis2, wheel);
        delay(75);

    } else if (val1 > 170) {
        Mouse.move(xAxis, yAxis3, wheel);
        delay(10);
    }

    // MOVING DOWN
    val2 = analogRead(A2);

    if (val2 > 140) {
        Mouse.move(xAxis, yAxis4, wheel);
        delay(50);

    } else if (val2 > 160) {
        Mouse.move(xAxis, yAxis5, wheel);
        delay(75);

    } else if (val2 > 170) {
        Mouse.move(xAxis, yAxis6, wheel);
        delay(10);
    }

    // LEFT AND RIGHT CODE

    val3 = analogRead(A3);

    // MOVING LEFT
    if (val3 > 80) {
        Mouse.move(xAxis1, yAxis, wheel);
        delay(50);

    } else if (val3 > 95) {
        Mouse.move(xAxis2, yAxis, wheel);
        delay(75);

    } else if (val3 > 120) {
        Mouse.move(xAxis3, yAxis, wheel);
        delay(10);
    }

    // MOVING RIGHT
    val4 = analogRead(A4);

    if (val4 > 60) {
        Mouse.move(xAxis4, yAxis, wheel);
        delay(50);

    } else if (val4 > 80) {
        Mouse.move(xAxis5, yAxis, wheel);
        delay(75);

    } else if (val4 > 105) {
        Mouse.move(xAxis6, yAxis, wheel);
        delay(10);

        Mouse.end();
        delay(500);
    }
}
