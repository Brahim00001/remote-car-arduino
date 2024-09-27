// Motor control pins for L298N
const int ENA = 10;  // Enable pin for Motor 1
const int IN1 = 7;   // IN1 for Motor 1
const int IN2 = 6;   // IN2 for Motor 1
const int ENB = 9;   // Enable pin for Motor 2
const int IN3 = 5;   // IN3 for Motor 2
const int IN4 = 4;   // IN4 for Motor 2

// Bluetooth HC-06
char command = 'S'; // Default command

void setup() {
  // Set motor pins as outputs
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Start serial communication for Bluetooth
  Serial.begin(9600);
}

void loop() {
  // Check if any data received via Bluetooth
  if (Serial.available() > 0) {
    command = Serial.read();  // Read the Bluetooth command
  }

  // Process command and control motors
  switch (command) {
    case 'F': // Move Forward
      forward();
      break;

    case 'B': // Move Backward
      backward();
      break;

    case 'L': // Turn Left
      turnLeft();
      break;

    case 'R': // Turn Right
      turnRight();
      break;

    case 'S': // Stop
      stopMotors();
      break;

    default:
      stopMotors(); // Stop if an unknown command is received
      break;
  }
}

// Function to move forward
void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 255); // Full speed
  analogWrite(ENB, 255);
}

// Function to move backward
void backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 255); // Full speed
  analogWrite(ENB, 255);
}

// Function to turn left
void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 200); // Moderate speed
  analogWrite(ENB, 200);
}

// Function to turn right
void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 200); // Moderate speed
  analogWrite(ENB, 200);
}

// Function to stop motors
void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}
