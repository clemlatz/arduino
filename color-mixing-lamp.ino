// Project 03 from Genuino starter kit projects book

const int greenLEDpin = 9;
const int redLEDpin = 10;
const int blueLEDpin = 11;

const int blueSensorPin = A0;
const int greenSensorPin = A1;
const int redSensorPin = A2;

int redValue = 0;
int greenValue = 0;
int blueValue = 0;

int redSensorValue = 0;
int greenSensorValue = 0;
int blueSensorValue = 0;

void setup() {
	Serial.begin(9600);

	pinMode(greenLEDpin, OUTPUT);
	pinMode(redLEDpin, OUTPUT);
	pinMode(blueLEDpin, OUTPUT);
}

void loop() {
	redSensorValue = analogRead(redSensorPin);
	delay(5);
	greenSensorValue = analogRead(greenSensorPin);
	delay(5);
	blueSensorValue = analogRead(blueSensorPin);

	Serial.print("Sensor values: rgb(");
	Serial.print(redSensorValue);
	Serial.print(",");
	Serial.print(greenSensorValue);
	Serial.print(",");
	Serial.print(blueSensorValue);
	Serial.print(") \n");

	redValue = redSensorValue / 4;
	greenValue = greenSensorValue / 4;
	blueValue = blueSensorValue / 4;

	analogWrite(redLEDpin, redValue);
	analogWrite(blueLEDpin, blueValue);
	analogWrite(greenLEDpin, greenValue);
}
