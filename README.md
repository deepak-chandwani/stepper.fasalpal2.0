Stepper Motor + Moisture Sensors + Relay Control

Overview
This project is an automated plant watering system designed to take care of up to 8 plants. It uses a stepper motor to rotate a watering mechanism (such as a spout or tube) to each plant. Each plant has its own soil moisture sensor. If a plant's soil is too dry, the system activates a relay to turn on a water pump or valve until the soil is sufficiently moist.

Features
Supports up to 8 plants (easily configurable)

Individual moisture sensors for each plant

Stepper motor positions the watering spout accurately

Relay control for pump/valve

Configurable moisture thresholds per plant

Serial monitoring of moisture readings

Hardware Required
1 × ESP32 (or compatible microcontroller with enough analog pins)

1 × 28BYJ-48 stepper motor + ULN2003 driver

8 × Capacitive or resistive soil moisture sensors

1 × Relay module (to control pump/valve)

1 × Water pump or solenoid valve

Jumper wires, power supply, tubing, etc.

Pin Connections:

Function	ESP32 Pin
Stepper IN1	19
Stepper IN2	18
Stepper IN3	5
Stepper IN4	17
Moisture Sensor 1	32
Moisture Sensor 2	33
Moisture Sensor 3	34
Moisture Sensor 4	35
Moisture Sensor 5	36
Moisture Sensor 6	39
Moisture Sensor 7	25
Moisture Sensor 8	26
Relay Control	27
How It Works
Initialization:

The system sets up the stepper motor, relay, and serial communication.

Main Loop:

For each plant:

Reads the soil moisture.

If the moisture is below the threshold, moves the watering spout to that plant.

Activates the relay to start watering.

Waits until the sensor reads above the threshold.

Turns off the relay.

Waits 1 hour before repeating the cycle.

Stepper Motor Control:

Calculates the shortest path to the target plant.

Rotates the stepper motor accordingly.

Customization
Number of Plants:
Change #define NUM_PLANTS 8 and update sensorPins and moistureThresholds arrays.

Moisture Thresholds:
Adjust values in moistureThresholds[] for each plant.

Watering Delay:
The system checks every hour (delay(3600000UL);). Change this value as needed.

Usage
Upload the code to your ESP32.

Connect all hardware as per the pin mapping.

Power the system.

Monitor the Serial Output for moisture readings and debug information.

Safety & Notes
Double-check relay wiring to avoid shorts or damage.

Ensure your power supply can handle the pump and stepper motor.

Calibrate moisture sensors for your soil and sensor type.

Test with water only before connecting to plants.
