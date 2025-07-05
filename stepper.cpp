#include <Stepper.h>

#define NUM_PLANTS 8
#define STEPS_PER_REV 2048
#define STEPS_PER_POS (STEPS_PER_REV / NUM_PLANTS)

const int stepperPins[4] = {19, 18, 5, 17};
Stepper myStepper(STEPS_PER_REV, stepperPins[0], stepperPins[2], stepperPins[1], stepperPins[3]);

const int sensorPins[NUM_PLANTS] = {32, 33, 34, 35, 36, 39, 25, 26};
const int relayPin = 27;

int moistureThresholds[NUM_PLANTS] = {1800, 1700, 1750, 1600, 1650, 1800, 1700, 1750};

int currentPosition = 0;

void setup() {
  Serial.begin(115200);
  myStepper.setSpeed(10);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH);
}

void loop() {
  for (int i = 0; i < NUM_PLANTS; i++) {
    int moisture = analogRead(sensorPins[i]);
    Serial.print("Plant "); Serial.print(i); Serial.print(" Moisture: "); Serial.println(moisture);

    if (moisture < moistureThresholds[i]) {
      moveToPosition(i);
      digitalWrite(relayPin, LOW);
      while (analogRead(sensorPins[i]) < moistureThresholds[i]) {
        delay(1000);
      }
      digitalWrite(relayPin, HIGH);
      delay(500);
    }
  }
  delay(3600000UL);
}

void moveToPosition(int targetPosition) {
  int diff = targetPosition - currentPosition;
  if (diff == 0) return;
  if (abs(diff) > NUM_PLANTS / 2) {
    if (diff > 0) diff -= NUM_PLANTS;
    else diff += NUM_PLANTS;
  }
  int steps = diff * STEPS_PER_POS;
  myStepper.step(steps);
  currentPosition = targetPosition;
}
