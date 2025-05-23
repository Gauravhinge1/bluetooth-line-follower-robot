# 🤖 Arduino Line Follower + Obstacle Avoider + Bluetooth-Controlled Robot  
### with Servo-mounted Ultrasonic Sensor for Smart Obstacle Detection

---

## 📋 Project Overview

This robot is built using Arduino UNO and integrates multiple functionalities for intelligent navigation:  
- **Line Following:** Uses IR sensors to follow a black line track.  
- **Obstacle Avoidance:** Ultrasonic sensor mounted on a servo scans left, center, and right to detect obstacles and choose the clearest path.  
- **Bluetooth Control:** HC-05 Bluetooth module allows manual control via smartphone commands.

---

## 🔧 Components Used

- Arduino UNO  
- L298N Motor Driver  
- 2x IR Sensors (for line detection)  
- HC-SR04 Ultrasonic Sensor (mounted on servo)  
- SG90 Servo Motor  
- HC-05 Bluetooth Module  
- Robot Chassis with wheels and battery pack

---

## 🛠️ Features

- Autonomous line following with real-time obstacle detection  
- Servo scanning for obstacle avoidance in three directions  
- Manual override using Bluetooth commands:  
  - `F` = Forward  
  - `B` = Backward  
  - `L` = Turn Left  
  - `R` = Turn Right  
  - `S` = Stop  

---

## 🔌 Circuit Diagram

*(Add your circuit diagram image here)*  
![Circuit Diagram](circuit_diagram.jpg)

---


## 📡 Bluetooth App

Use any serial Bluetooth terminal app (e.g., "Bluetooth Terminal HC-05") on your smartphone to send manual control commands.

---

## 🚀 How to Use

1. Upload robot_control.ino to your Arduino UNO.  
2. Power the robot and make sure Bluetooth is paired.  
3. Start with manual control or autonomous mode (no Bluetooth input).  
4. Watch the robot follow lines and avoid obstacles using servo scanning.

---


