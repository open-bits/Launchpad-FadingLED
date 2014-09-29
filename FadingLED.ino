uint8_t fadeAmount = 5;
volatile int fadeDelay = 30;

void setup()  { 
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  
  pinMode(PUSH1, INPUT_PULLUP);
  pinMode(PUSH2, INPUT_PULLUP);
  attachInterrupt(PUSH1, changeFadeToSlow, CHANGE);
  attachInterrupt(PUSH2, changeFadeToFast, CHANGE);
}

void changeFadeToSlow() {
  fadeDelay = 30;
}

void changeFadeToFast() {
  fadeDelay = 5;
}

void fade(uint8_t ledPin)
{
  // fade in from min to max in increments of 5 points:
  for(int fadeValue = 0; fadeValue <= 255; fadeValue += fadeAmount) { 
    // sets the value (range from 0 to 255):
    analogWrite(ledPin, fadeValue);         
    // wait for 30 milliseconds to see the dimming effect    
    delay(fadeDelay);                            
  } 

  // fade out from max to min in increments of 5 points:
  for(int fadeValue = 255; fadeValue >= 0; fadeValue -= fadeAmount) { 
    // sets the value (range from 0 to 255):
    analogWrite(ledPin, fadeValue);         
    // wait for 30 milliseconds to see the dimming effect    
    delay(fadeDelay);                            
  } 
}

void loop()  { 
  fade(RED_LED);
  fade(GREEN_LED);
  fade(BLUE_LED);
}
