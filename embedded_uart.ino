//1 light with button count

const int buttonPin = 2;
const int ledPin = 13;

int buttonState = HIGH;
int lastButtonState = HIGH;
int pressCount = 0;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);   
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == LOW) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  if (lastButtonState == HIGH && buttonState == LOW) {
    pressCount++;
    Serial.print("Button pressed: ");
    Serial.println(pressCount);
  }

  lastButtonState = buttonState;

  delay(50);
}

// 3 light with button count

const int buttonPin = 2;

const int redLed = 13;
const int greenLed = 7;
const int yellowLed = 8;

int buttonState = HIGH;
int lastButtonState = HIGH;
int pressCount = 0;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);

  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);

  Serial.begin(9600);

  digitalWrite(redLed, LOW);
  digitalWrite(greenLed, LOW);
  digitalWrite(yellowLed, LOW);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (lastButtonState == HIGH && buttonState == LOW) {
    pressCount++;
    Serial.print("Button pressed: ");
    Serial.println(pressCount);

    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, LOW);
    digitalWrite(yellowLed, LOW);

    int state = pressCount % 3;

    if (state == 1) {
      digitalWrite(redLed, HIGH);
    } else if (state == 2) {
      digitalWrite(greenLed, HIGH);
    } else {
      digitalWrite(yellowLed, HIGH);
    }
  }

  lastButtonState = buttonState;
  delay(50);
}

// Hold

const int buttonPin = 2;
const int ledPin = 13;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}

