
// Inputs:
// p5
// Outputs:
// led = ~9


int led = 9;

void setup() {
  // Start serial communication so we can send data
  // over the USB connection to our p5js sketch
  Serial.begin(9600);

  // Outputs on these pins
  pinMode(led, OUTPUT);

}

void loop() {
  // wait for data from p5 before doing something
  while (Serial.available()) {

    int input = Serial.parseInt();
    int mval = map(constrain(input,30, 600), 30, 600, 0, 255);
    if (Serial.read() == '\n') {
      analogWrite(led, mval);
  }
}
}