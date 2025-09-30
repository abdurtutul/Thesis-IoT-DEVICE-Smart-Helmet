# IoT Smart Helmet — Blood Alcohol Concentration (BAC) + Accident Detection

**Project:** An IoT based Smart Helmet System Measuring Blood Alcohol Concentration (BAC) for Accident Detection and Notification.  
**Authors:** Abir Ibrahim Bin Monir, Md Salem Ahmed, Kajol, Abdur Rahaman Tutul.  
**Supervisor:** Mahfujur Rahman.  
**Submitted:** 26 January, 2023. fileciteturn1file19

---

## Project Overview
This project implements a low-cost IoT Smart Helmet that:
- Measures Blood Alcohol Concentration (BAC) using an MQ-3 alcohol sensor.
- Detects collisions/accidents using force / vibration (MEMS) sensors.
- Tracks location with a NEO-6M GPS module.
- Sends SMS/calls with location to emergency contacts via a GSM module.
- Prevents vehicle start when intoxication is detected and provides visual/audible alerts. fileciteturn1file10turn1file4

---

## Key Features
- Real-time BAC detection and rider-state classification (safe / caution / blocked).
- Accident detection with automatic SMS + call to preconfigured emergency contacts.
- On-device LCD to display GPS coordinates, BAC, and sensor status.
- Low-cost hardware design and modular components to facilitate prototyping and extension. fileciteturn1file4

---

## Hardware Components
Main components used in the thesis:
- Arduino Uno R3. fileciteturn1file29
- MQ-3 Alcohol Sensor (analog + digital outputs). fileciteturn1file26
- NEO-6M GPS Module. fileciteturn1file30
- Force Sensing Resistor (FSR) / MEMS force sensor.
- SW-420 Vibration Sensor (LM393 based module).
- GSM module (SIM800 / similar) for SMS/call.
- nRF24L01+ (optional) for wireless telemetry.
- 16x2 LCD display, buzzer, LEDs, battery and solar charging (optional). fileciteturn1file34turn1file31

*See the thesis for full spec tables and pinout diagrams.* fileciteturn1file0

---

## How it works (high-level)
1. **Helmet check** — flex/FSR sensor confirms helmet worn.
2. **BAC check** — MQ-3 reads breath alcohol (analog). If reading:
   - Below threshold → green LED (allow start).
   - Between thresholds → orange LED + buzzer warning (caution).
   - Above threshold → red LED + buzzer + block start. fileciteturn1file23
3. **Accident detection** — force/vibration sensor exceeds stored threshold → trigger GPS + GSM.
4. **Emergency notification** — GPS obtains lat/long and GSM sends SMS and calls preconfigured numbers with location and status. fileciteturn1file41

---

## Wiring & Pin Summary (example)
> This is an example wiring mapping — adapt to your hardware and pin availability.

- MQ-3 -> A0 (analog read), VCC 5V, GND.
- SW-420 -> D2 (digital interrupt), VCC 5V, GND.
- FSR -> analog divider -> A1.
- NEO-6M TX -> RX of Arduino (D10 via SoftwareSerial), NEO-6M RX -> TX (D11).
- GSM module TX/RX -> SoftwareSerial pins (D8/D9) + separate power supply.
- LCD -> I2C (SDA/SCL) or 4-bit mode on D4-D7.
- Buzzer -> D3 (PWM), LEDs -> D4/D5/D6 (R/O/G). fileciteturn1file36

Refer to the thesis pinout tables for full details. fileciteturn1file11

---

## Example Arduino Sketch (firmware_example.ino)
A very short, modular example is included in `firmware_example.ino`. This is a starting skeleton — **calibrate thresholds** before using on real hardware.

---

## Experimental Results (summary)
- Accident detection: success rates reported across multiple thresholds (varies per force values). fileciteturn1file17
- Alcohol detection: tested with various volumes; reported detection rates up to 100% for larger samples. Overall accuracy reported ~**92%** in thesis tests. fileciteturn1file16

---

## Licensing & Citation
If you publish this repo, note the original thesis authors and supervisor. If you want, add an open-source license (MIT/Apache) depending on how you want others to use the code and materials.

**Citation (suggested):**  
Monir, A.I.B., Ahmed, M.S., Kajol, Abdur Rahaman Tutul; _An IoT based Smart Helmet System Measuring BAC for Accident Detection and Notification_ — Thesis (American International University-Bangladesh), 26 Jan 2023. fileciteturn1file19

---

## Next steps I can do for you
- Turn this README into the repo's `README.md` file (done — file generated).
- Create the PowerPoint summary (done — file generated).
- Add images (PCB, photos, diagrams) from your files or screenshots and embed them into slides.
- Expand the Arduino firmware into a complete, upload-ready sketch with calibration utilities and GSM/SIM handling.

If you'd like, tell me which additional files (schematics, photos, PCB Eagle/KiCad files, code) you want included in the GitHub repo and I'll add them.  
