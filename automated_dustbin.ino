        #include <Servo.h>

// Define the pins for the ultrasonic sensor, LEDs, buzzer, and servo motor
const int trigPin = 13;
const int echoPin = 12;
const int redLedPin = 2;
const int yellowLedPin = 4;
const int greenLedPin = 5;
const int buzzerPin = 7;
const int servoPin = 6;

// Define the distance thresholds
const int fullDistance = 10; // Distance in cm when the dustbin is considered full
const int emptyDistance = 50; // Distance in cm when the dustbin is considered empty

Servo myServo;

void setup() {
  // Initialize the pins as outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  // Attach the servo to the servo pin
  myServo.attach(servoPin);

  // Initialize serial communication for debugging
  Serial.begin(9600);

  // Initialize the servo to close the lid
  closeLid();
}

void loop() {
  // Measure the distance using the ultrasonic sensor
  int distance = measureDistance();

  // Print the distance for debugging
  Serial.print("Distance: ");
  Serial.println(distance);

  // Check the distance and control the LEDs, buzzer, and servo motor accordingly
  if (distance < fullDistance) {
    // Dustbin is full
    digitalWrite(redLedPin, HIGH);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(greenLedPin, LOW);
    tone(buzzerPin, 1000); // Sound the buzzer
    openLid(); // Open the lid
    Serial.println("Dustbin is full");
  } else if (distance < emptyDistance) {
    // Dustbin is partially full
    digitalWrite(redLedPin, LOW);
    digitalWrite(yellowLedPin, HIGH);
    digitalWrite(greenLedPin, LOW);
    noTone(buzzerPin); // Turn off the buzzer
    closeLid(); // Close the lid
    Serial.println("Dustbin is partially full");
  } else {
    // Dustbin is empty
    digitalWrite(redLedPin, LOW);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(greenLedPin, HIGH);
    noTone(buzzerPin); // Turn off the buzzer
    closeLid(); // Close the lid
    Serial.println("Dustbin is empty");
  }

  // Delay for a short period before checking the distance again
  delay(1000);
}

int measureDistance() {
  // Send a 10us pulse to the trig pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the duration of the pulse on the echo pin
  long duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in cm
  int distance = duration * 0.034 / 2;

  return distance;
}

void openLid() {
  // Move the servo to open the lid
  myServo.write(90);
}

void closeLid() {
  // Move the servo to close the lid
  myServo.write(0);
}
