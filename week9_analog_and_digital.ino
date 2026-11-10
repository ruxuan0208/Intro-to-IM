
// setting up read-only variables
const int temp_a = A0;
const int switch_in = 2;
const int led_a = 9;
const int led_d = 13;

void setup() {
  //initialize the variables to correspond to the modes and the data transfer

  pinMode(switch_in, INPUT_PULLUP);
  pinMode(led_a, OUTPUT);
  pinMode(led_d, OUTPUT);
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  //digital input and output
  int switch_state = digitalRead(switch_in);

  if (switch_state == HIGH ){
    digitalWrite(led_d, LOW);
  } else {
    digitalWrite(led_d, HIGH);
  }

  // read the input on analog pin 0:
  int sensorValue = analogRead(temp_a);

  //convert the analog input value to voltage and temperature in celsius 
  //asked gemini for the calculations 
  float voltage = sensorValue * (5.0 / 1023.0);
  float tempC = (voltage - 0.5) * 100.0;

  //print out the value you read:
  Serial.println(sensorValue);

  //map the temp to the analog output range 0 -255 and make the led light up accordingly
  int brightness = map(tempC * 10, 230, 360, 0, 255);
  brightness = constrain(brightness, 0, 255);
  analogWrite(led_a, brightness);

  delay(50);  // delay in between reads for stability

}
