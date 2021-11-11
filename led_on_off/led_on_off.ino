// Pin 3: Input for reading the button
// Pin 2: Output for controlling the LED
int buttonPin = 3;
int ledPin = 2;

int buttonValue = 0;
int randomInt = 0;

void setup() {
  // Uncomment to see the debug lines on PC console
  Serial.begin(9600);
  
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}


void loop() {
  // read the button value
  buttonValue = digitalRead(buttonPin);
  //Serial.print("Button: ");
  //Serial.println(buttonValue);

  // Check if button is pressed
  if (buttonValue == 1) {
    
    // Add randomness to the LED on/off decision
    randomInt = random(1, 101);
    Serial.print("RandomInt: ");
    Serial.println(randomInt);
    delay(1000);

    // Control the LED switch (out of 100)
    if (randomInt > 40){
      // Stay on for 3 seconds
      digitalWrite(ledPin, HIGH);
      delay(3000);
    } else {
      // Blink 5 times
      for (int i=0; i<5; i++){
        digitalWrite(ledPin, HIGH);
        delay(500);
        digitalWrite(ledPin, LOW);
        delay(500);
      }
    }

  } else {
    // Keep the LED off until button is pressed
    digitalWrite(ledPin, LOW);
  }
  
}
