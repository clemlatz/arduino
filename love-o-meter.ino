// Project 02 from Genuino starter kit projects book

const int sensorPin = A0;
const float baseTemp = 0.0;

// Read the sensor value, calculate voltage & temperature
float getTemp() {
	int sensorValue = analogRead(sensorPin);
	float sensorVoltage = (sensorValue / 1024.0) * 5.0;
	float temperature = (sensorVoltage - .5) * 100;

	Serial.print("Sensor value: ");
	Serial.print(sensorValue);
	Serial.print(" | temperature: ");
	Serial.print(temperature);
	Serial.print("\n");

	return temperature;
}

void setup() {

	// Initialize connection to computer
	Serial.begin(9600);

	// Initialize each LED's outpu
	for (int pinNumber = 2; pinNumber < 5; pinNumber++) {
		pinMode(pinNumber, OUTPUT);
		digitalWrite(pinNumber, LOW);
	}
}

void loop() {
	// Get temperature from sensor
	float temperature = getTemp();

	// Light up LEDS according to temperature
	if (temperature < baseTemp) {
		digitalWrite(2, LOW);
		digitalWrite(3, LOW);
		digitalWrite(4, LOW);
	} else if (temperature < baseTemp + 5) {
		digitalWrite(2, HIGH);
		digitalWrite(3, LOW);
		digitalWrite(4, LOW);
	} else if (temperature < baseTemp + 10) {
		digitalWrite(2, HIGH);
		digitalWrite(3, HIGH);
		digitalWrite(4, LOW);
	} else {
		digitalWrite(2, HIGH);
		digitalWrite(3, HIGH);
		digitalWrite(4, HIGH);
	}

	delay(100);
}
