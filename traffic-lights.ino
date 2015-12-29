// The lit on led changes every time the button is pressed

int switchState = 0;
bool buttonPressed = false;
int ledOn = 3;

void setup()
{
	pinMode(3, OUTPUT); // Red LED
	pinMode(4, OUTPUT); // Yellow LED
	pinMode(5, OUTPUT); // Green LED
	pinMode(2, INPUT);
}

void loop()
{
	digitalWrite(ledOn, HIGH);

	// Get button state
	switchState = digitalRead(2);

	// Button press event
	if (switchState == HIGH and buttonPressed == false) {
		buttonPressed = true;

	// Button release event
	} else if (switchState == LOW and buttonPressed == true) {
		buttonPressed = false;
		digitalWrite(ledOn, LOW);
		ledOn = ledOn + 1;
		if (ledOn == 6) {
			ledOn = 3;
		}
	}
}
