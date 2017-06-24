/* 
 *  Lazy Fidget Spinner
 *  by Rebecca Lindblom 
 *  June 2017
*/

// For motor
// https://cdn.sparkfun.com/assets/resources/4/4/DC_motor_circuits_notes_2up.pdf
int pwmPin = 3; // Chose one pin with ~
int dutyCycle = 100; // For motor PWM, 8 bit value [0,255]

// For button
int buttonPin = 7;
int buttonState = HIGH;
int buttonReading;
int buttonPrevious = LOW;
long timeSinceClick = 0;
long debounce = 200;

void setup() {
  pinMode(pwmPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}


void loop() {
  buttonReading = digitalRead(buttonPin);
  // if the input just went from LOW and HIGH and we've waited long enough
  // to ignore any noise on the circuit, toggle the output pin and remember
  // the timeSinceClick
  // https://www.arduino.cc/en/tutorial/switch
  if (buttonReading == HIGH && buttonPrevious == LOW && millis() - timeSinceClick > debounce) {
    if (buttonState == HIGH)
      buttonState = LOW;
    else
      buttonState = HIGH;
    timeSinceClick = millis();    
  }

  digitalWrite(LED_BUILTIN, buttonState);

  buttonPrevious = buttonReading;

  if (buttonState == HIGH) {
    analogWrite(pwmPin, dutyCycle);
    //digitalWrite(LED_BUILTIN, HIGH);
  } else {
    analogWrite(pwmPin, 0);
  }

}
