# 🚦 Density-Based Traffic Light Using AT89C51

## Project Overview

A microcontroller-based **density-dependent traffic light system** developed using the **AT89C51 microcontroller and IR sensors**.

The system detects different levels of traffic using two IR sensors and adjusts the duration of the green traffic signal accordingly. Higher traffic density is assigned a longer green-light duration, while lower traffic conditions receive a shorter duration.

The project was designed and tested in **Proteus 8 Professional** and was also implemented as a physical prototype.

---

## Key Features

- Traffic density detection using two IR sensors
- AT89C51 microcontroller-based control
- Three traffic conditions: no vehicle, low traffic, and high traffic
- Adaptive green-light duration based on detected traffic density
- Red, yellow, and green traffic signal control
- ULN2003A driver IC for LED interfacing
- Embedded C programming
- Proteus simulation and physical prototype implementation
- Debugging and correction of timing logic

---

## Components Used

### Hardware

- **AT89C51 Microcontroller**
- **2 × IR Sensors**
- **ULN2003A Driver IC**
- **Red LED**
- **Yellow LED**
- **Green LED**
- **11.0592 MHz Crystal Oscillator**
- **33 pF Capacitors**
- **10 kΩ Resistor**
- **10 µF Capacitor**
- **Reset Push Button**
- **330 Ω Resistors**
- **5V Power Supply**

### Software

- **Keil uVision** – Embedded C programming and compilation
- **Proteus 8 Professional** – Circuit design and simulation

---

## Traffic Density Logic

Two IR sensors are connected to **Port 1 of the AT89C51**.

| IR1 | IR2 | Traffic Condition | Green-Light Duration |
|-----|-----|-------------------|----------------------|
| 0 | 0 | No Vehicle | Short |
| 1 | 0 | Low Traffic | Medium |
| 1 | 1 | High Traffic | Long |

The microcontroller reads the sensor combination and selects the corresponding green-light timing.

> **Note:** The `01` sensor combination is treated as an invalid condition in the program and is handled as high traffic as a safety condition.

---

## How It Works

1. Two IR sensors detect vehicles at different positions on the road.
2. The sensor outputs are connected to **P1.0 and P1.1** of the AT89C51.
3. The microcontroller reads the digital sensor inputs.
4. The sensor combination is used to determine the traffic density.
5. The AT89C51 selects the appropriate green-light duration.
6. The traffic signal operates through the programmed **Green → Yellow → Red** sequence.
7. The process continuously repeats based on the detected traffic condition.

---

## Programming

The system was programmed in **Embedded C using Keil uVision**.

The program contains separate functions for:

- Reading the IR sensor inputs
- Determining traffic density
- Controlling the green signal
- Controlling the yellow signal
- Controlling the red signal
- Generating timing delays

The traffic density is determined using conditional logic based on the two IR sensor inputs.

---

## Challenges & Debugging

During the initial testing, I implemented the traffic-light timing logic incorrectly. The green-light duration was initially reversed, causing **lower traffic density to receive a longer green-light duration**.

I identified the issue while testing the different IR sensor conditions and corrected the conditional logic and timing values.

After debugging, the system correctly assigned a **longer green-light duration to higher traffic density**.

This gave me practical experience in **embedded C debugging, sensor interfacing, conditional logic, timing control, and microcontroller-based systems**.

---

## Results

- Successfully detected different traffic conditions using two IR sensors.
- Successfully interfaced the IR sensors with the AT89C51.
- Controlled traffic-light LEDs using the AT89C51 and ULN2003A.
- Adjusted green-light duration according to the detected traffic condition.
- Tested and debugged the system using Proteus simulation.
- Developed a physical prototype of the traffic-light system.

---

## Project Images

### Proteus Simulation

![Proteus Circuit](images/proteus-circuit.png)

### Physical Prototype

![Physical Prototype](images/physical-prototype.jpg)

---

## Future Improvements

- Add additional sensors for more accurate traffic-density detection.
- Implement real-time vehicle counting.
- Support multiple roads or traffic lanes.
- Add an LCD display to show the detected traffic density.
- Implement dynamic timing based on actual vehicle count.
- Develop a compact PCB-based version of the system.

---

## Technologies Used

**Microcontroller:** AT89C51  
**Programming Language:** Embedded C  
**IDE:** Keil uVision  
**Simulation:** Proteus 8 Professional  
**Sensors:** IR Sensors  
**Driver IC:** ULN2003A  
**Output:** Red, Yellow & Green LEDs
