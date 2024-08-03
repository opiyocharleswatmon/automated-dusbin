# Smart Dustbin System

This project implements a smart dustbin system using an Arduino board, an ultrasonic sensor, LEDs, a buzzer, and a servo motor. The system detects the level of waste in the dustbin and controls the LEDs, buzzer, and servo motor accordingly.

## Components

- Arduino board (e.g., Arduino Uno)
- Ultrasonic sensor (e.g., HC-SR04)
- LEDs (Red, Yellow, Green)
- Buzzer
- Servo motor
- Jumper wires
- Breadboard (optional)

## Pin Connections

- **Ultrasonic Sensor**:
  - Trig Pin: 13
  - Echo Pin: 12
- **LEDs**:
  - Red LED: 2
  - Yellow LED: 4
  - Green LED: 5
- **Buzzer**: 7
- **Servo Motor**: 6

## Distance Thresholds

- **Full Distance**: 10 cm (Dustbin is considered full)
- **Empty Distance**: 50 cm (Dustbin is considered empty)

## Setup

1. Connect the components to the Arduino board as per the pin connections mentioned above.
2. Upload the provided code to the Arduino board using the Arduino IDE.
3. Open the Serial Monitor in the Arduino IDE to view the debugging information.

## Code Overview

The code initializes the pins, sets up the servo motor, and starts serial communication for debugging. In the main loop, it measures the distance using the ultrasonic sensor and controls the LEDs, buzzer, and servo motor based on the distance.

### Key Functions

- `measureDistance()`: Measures the distance using the ultrasonic sensor and returns the distance in centimeters.
- `openLid()`: Moves the servo motor to open the dustbin lid.
- `closeLid()`: Moves the servo motor to close the dustbin lid.

## Usage

1. Power on the Arduino board.
2. The system will continuously measure the distance and control the LEDs, buzzer, and servo motor based on the distance thresholds.
3. When the dustbin is full (distance < 10 cm), the red LED will turn on, the buzzer will sound, and the lid will open.
4. When the dustbin is partially full (10 cm <= distance < 50 cm), the yellow LED will turn on, the buzzer will be off, and the lid will close.
5. When the dustbin is empty (distance >= 50 cm), the green LED will turn on, the buzzer will be off, and the lid will close.

