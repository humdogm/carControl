const int motor1Forward = 1; // 1st digital control pin for motor 1, change to the actual pins you guys are using
const int motor1Backward = 2; // 2nd digital control pin for motor 1, motor 1 should be on the left side

const int motor2Forward = 3; // 1st digital control pin for motor 2, motor 2 should be on the right side
const int motor2Backward = 4; // 2nd digital control pin for motor 2

const int irLeft  = 5;  // Analog input pin for left ir sensor
const int irMid   = 6;  // Analog input pin for middle ir sensor
const int irRight = 7;  // Analog input pin for right ir sensor

const int prLeft  = 8 ;  // Analog input pin for left photoresistor
const int prMid   = 9 ;  // Analog input pin for middle photoresistor
const int prRight = 10;  // Analog input pin for right photoresistor

float irSensorVoltage(int pin){
  float irSensorVoltage = analogRead(pin);
  irSensorVoltage *= (5.0/1023.0);        // Arduino reads input pins using a 10 bit ADC, which outputs between 0 and 1023
                                          // This just normalizes that value to an actual voltage and prints it to serial
  Serial.println("irSensorVoltage ");
  Serial.print(pin);
  Serial.print(" = ");
  Serial.print(irSensorVoltage);
  return irSensorVoltage;
}

float photoResistorVoltage(int pin){
  float prSensorVoltage = analogRead(pin);
  prSensorVoltage *= (5.0/1023.0);        // Arduino reads input pins using a 10 bit ADC, which outputs between 0 and 1023
                                          // This just normalizes that value to an actual voltage and prints it to serial
  Serial.println("prSensorVoltage ");
  Serial.print(pin);
  Serial.print(" = ");
  Serial.print(prSensorVoltage);
  return prSensorVoltage;
}

void forward(){
  digitalWrite(motor1Backward, LOW);
  digitalWrite(motor2Backward, LOW);
  digitalWrite(motor1Forward, HIGH); // Sets both motors to move forward
  digitalWrite(motor2Forward, HIGH);
}

void turnLeft(){
  digitalWrite(motor1Forward, LOW);
  digitalWrite(motor2Backward, LOW);
  digitalWrite(motor1Backward, HIGH); // Sets left motor to go backward
  digitalWrite(motor2Forward, HIGH);  // Sets right motor to go forward
}

void turnRight(){
  digitalWrite(motor1Backward, LOW);
  digitalWrite(motor2Forward, LOW);
  digitalWrite(motor1Forward, HIGH);  // Sets left motor to go forward
  digitalWrite(motor2Backward, HIGH); // Sets right motor to go backward
}

void stop(){
  digitalWrite(motor1Backward, LOW);
  digitalWrite(motor2Backward, LOW);
  digitalWrite(motor1Forward, LOW); // Sets all motors to stop
  digitalWrite(motor2Forward, LOW); 
}

void setup() {
  // put your setup code here, to run once:
  
  pinMode(motor1Forward, OUTPUT);
  pinMode(motor1Backward, OUTPUT);

  pinMode(motor2Forward, OUTPUT);
  pinMode(motor2Backward, OUTPUT);

  pinMode(irLeft, INPUT);
  pinMode(irMid, INPUT);
  pinMode(irRight, INPUT);

  pinMode(prLeft, INPUT);
  pinMode(prMid, INPUT);
  pinMode(prRight, INPUT);

Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  float irLeftVoltage = irSensorVoltage(irLeft);  // Every loop, these variables get refreshed, so all we need is some logic for this loop
  float irMidVoltage = irSensorVoltage(irMid);
  float irRightVoltage = irSensorVoltage(irRight);

  float prLeftVoltage = photoResistorVoltage(prLeft);
  float prMidVoltage = photoResistorVoltage(prMid);
  float prRightVoltage = photoResistorVoltage(prRight);
}
