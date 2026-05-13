// ------ Preamble ------ //
#include <avr/io.h>
#include <util/delay.h>

//--------Functions---------//
static inline void initTimer(void) {
  /*Write code to initialize Timer 1*/
  TCNT1 = 65380;      /* Preload timer: 65535+1-(15625/100) = 65380 (65379.75 rounded) ; for sampling rate of 100 Hz */
  TCCR1B |= (1<< CS12) | (1 << CS10);     //1024 prescaler 
  TIMSK1 = (1 << TOIE1);      // Enable timer overflow interrupt 
}

static inline void initIOPorts(void) {
  /*Write code to initialize the GPIO ports (pins) that you need*/
  DDRB |= (1<<PB5); // Output 1 for Serial Plot. Note: This line is not useful in this case. However, for the ECG it can be used as an input instead (replace 1 with 0). 
}

static inline void initADC(void) {
  /*Write code to initialize the ADC*/
  ADMUX |= (1 << REFS0);      /* Reference voltage on AVCC */
  ADCSRA |= (1 << ADPS2) | (1<<ADPS1) | (1 << ADPS0);     /* ADC prescaler /8 */
  ADCSRA |= (1<< ADEN);   /* Enable ADC */
  ADCSRA |= (1 << ADIE);    /* ADC Interrupt Enable */
  ADCSRA |= (1 << ADATE);        /* Enable Auto-triggering */
  ADCSRB |=  (1 << ADTS2) | (1 << ADTS1) | (0 << ADTS0);    /* ADC Control and Status Register B: Auto Trigger source set to Timer/Counter1 overflow mode */
}

// ------- Interrupt Service Routine --------- //
ISR(TIMER1_OVF_VECT) {
  /* This is the interrupt serive routine for Timer 1 Overflow */
  TCNT1 = 65380;  // Preload Timer
}

ISR(ADC_vect) {
  /* This is the interrupt serive routine for the ADC
    It is executed when the ADC completes a conversion */
  Serial.println(ADC);    // Prints the value of the ADC on Serial Monitor
}

/* You don't need to modify anything in the code below */
int main(void) {

  Serial.begin(9600);     /* Initializing the Serial Port */

  noInterrupts();   // Disables interrupts
  initIOPorts();    // Calling the function defined above
  initTimer();      // Calling the function defined above
  initADC();        // Calling the function defined above
  interrupts();     // Re-enable interrupts

  while (1) {
  }
  return 0;             /* This line is never reached */
}
