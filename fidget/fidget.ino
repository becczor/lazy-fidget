int PWM_pin = 3; // Chose one pin with ~

void setup() {
  // For motor to run
  pinMode( PWM_pin, OUTPUT );
  // For led to blink
  //pinMode(LED_BUILTIN, OUTPUT);
}

int duty_cycle = 150; // 8 it value [0,255]

void loop() {
  analogWrite( PWM_pin, duty_cycle );
  //digitalWrite(LED_BUILTIN, HIGH);
  delay(2000);
  
  analogWrite( PWM_pin, 0 );
  //digitalWrite(LED_BUILTIN, LOW);
  delay(3000);
  
}
