# Real-Time Autonomous Obstacle Avoidance and Embedded Navigation System 

## Overview  
Designed and developed an intelligent autonomous robotic system using the MSP430G2553 microcontroller for real-time obstacle detection, adaptive navigation, and embedded motion control. The platform integrates analog sensor processing, PWM-driven motor control, and autonomous decision-making logic to navigate dynamically through constrained environments while responding to external conditions.

## Key Features  
- Real-time front and lateral obstacle detection using analog sensors  
- Autonomous path decision-making for forward, left, and right movement  
- PWM-based dual motor speed and directional control using TimerA  
- Ambient light-responsive safety mechanism  
- Embedded C firmware with register-level hardware control  
- Low-power microcontroller implementation for efficient autonomous operation  

## System Functionality  
### Autonomous Navigation Logic:
- Moves forward when the path is unobstructed  
- Detects frontal obstacles and halts motion  
- Evaluates alternate route through lateral sensing  
- Executes adaptive left or right directional correction  
- Stops automatically under low-light environmental conditions  

## Technical Implementation  

### Hardware Platform:
- MSP430G2553 Microcontroller  

### Embedded Modules:
- Analog-to-Digital Conversion (ADC) for sensor acquisition  
- TimerA PWM for motor actuation  
- GPIO-based directional control  
- Delay-cycle calibration for movement precision  

### Sensor Integration:
- Front obstacle sensor  
- Left path sensor  
- Ambient light sensor  

## Development Environment  
- Code Composer Studio (CCS)  
- MSP430 Embedded Libraries  
- Embedded C  

## Engineering Applications  
- Autonomous robotics  
- Smart embedded navigation  
- Industrial automation systems  
- Sensor-driven robotic platforms  
- Edge-based control systems

## Skills Demonstrated  
- Embedded C Programming  
- MSP430 Architecture  
- ADC Configuration and Sensor Processing  
- PWM Motor Control  
- Timer-Based Real-Time Systems  
- Register-Level Firmware Development  
- Autonomous Robotics Logic  
- Hardware-Software Integration  
- Sensor-Based Decision Systems   
