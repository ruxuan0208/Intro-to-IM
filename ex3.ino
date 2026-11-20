
void setup() {
  // Start serial communication so we can send data
  // over the USB connection to our p5js sketch
  Serial.begin(9600);


  // We'll use the builtin LED as a status output.
  // We can't use the serial monitor since the serial connection is
  // used to communicate to p5js and only one application on the computer
  // can use a serial port at once.
  pinMode(LED_BUILTIN, OUTPUT);


  // Outputs on these pins
  pinMode(leftLedPin, OUTPUT);
  // pinMode(rightLedPin, OUTPUT);


  // Blink them so we can check the wiring
  digitalWrite(leftLedPin, HIGH);
  // digitalWrite(rightLedPin, HIGH);
  delay(1);
  digitalWrite(leftLedPin, LOW);
  // digitalWrite(rightLedPin, LOW);






  // start the handshake
  while (Serial.available() <= 0) {
    digitalWrite(LED_BUILTIN, HIGH); // on/blink while waiting for serial data
    Serial.println("0,0"); // send a starting message
    delay(5);            // wait 1/3 second
    digitalWrite(LED_BUILTIN, LOW);
    delay(5);
  }
}


void loop() {
  // wait for data from p5 before doing something
  while (Serial.available()) {
    digitalWrite(LED_BUILTIN, HIGH); // led on while receiving data


    int left = Serial.parseInt();
    // int right = Serial.parseInt();
 
    if (Serial.read() == '\n') {
     
      digitalWrite(leftLedPin, left);
      // digitalWrite(rightLedPin, right);


    //   //SEND TO P5


      int sensor = analogRead(A0);
      // int mValue = map(sensor,0,1023,-3,3);
      delay(5);
 
      Serial.println(sensor);
    // }
  }
  digitalWrite(LED_BUILTIN, LOW);
}
}
