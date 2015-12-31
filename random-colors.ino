// Set a LED to a random color 4 times by second

const int greenLEDpin = 9;
const int blueLEDpin = 10;
const int redLEDpin = 11;

int redValue = 100;
int greenValue = 200;
int blueValue = 0;

void setup() {
	Serial.begin(9600);

	pinMode(greenLEDpin, OUTPUT);
	pinMode(redLEDpin, OUTPUT);
	pinMode(blueLEDpin, OUTPUT);
}

void loop() {

	redValue = random(255);
	greenValue = random(255);
	blueValue = random(255);

	analogWrite(redLEDpin, redValue);
	analogWrite(blueLEDpin, blueValue);
	analogWrite(greenLEDpin, greenValue);

	delay(250);
}
