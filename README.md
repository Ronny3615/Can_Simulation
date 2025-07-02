# 🚗 CAN Protocol Multi-ECU Simulation in C

This is a **real-world simulation** of how multiple ECUs (Electronic Control Units) communicate over a **Controller Area Network (CAN)** — entirely written in **pure C**, with **zero hardware** dependency.  

It’s designed to mimic real embedded systems behavior, including arbitration, CRC validation, error injection, ECU scheduling, and more. Whether you're preparing for interviews, building your resume, or trying to master embedded protocols — this project is a great place to start.

---

## 🔍 What Makes This Project Interesting?

- Simulates **multi-ECU communication** just like a real vehicle network  
- Handles **bit-level error injection** and **data integrity checks** using CRC  
- Implements **round-robin scheduling** to mimic RTOS-like behavior  
- Adds **delay simulation** to create realistic message timing  
- Uses both **terminal output and log file logging**  
- Fully **cross-platform** (Windows/Linux) with a **Makefile** to build/run/clean everything

---

## 🧠 Features

- ✅ Simulated multi-ECU CAN bus communication  
- 🔁 ECU round-robin scheduler  
- 🔐 CRC checksum for data integrity  
- ❌ Randomized bit error simulation (20% chance per ECU)  
- ⏱️ Simulated delay between ECU transmissions using cross-platform timers
- 🧾 Dual logging system: logs to both terminal and `logger.txt`  
- ⚙️ Cross-platform support with `Makefile` (Linux & Windows)

---

## 🗂️ File Overview

| File              | Purpose                                                   |
|-------------------|------------------------------------------------------------|
| `main.c`          | Starts the simulation and sets up ECUs                    |
| `ecu.c / ecu.h`   | Defines ECU behavior and how they send/receive messages   |
| `can.c / can.h`   | Handles CAN arbitration, transmission, and CRC logic      |
| `scheduler.c / .h`| Manages ECU execution using a round-robin scheduler       |
| `error.c / .h`    | Simulates random bit-level errors in ECU messages         |
| `logger.c / .h`   | Logs output to terminal and a file                        |
| `platform.c / .h` | Adds portable delay functions for timing simulation       |
| `Makefile`        | Build script for compile/run/clean                        |

---

## 🛠️ How to Build, Run, and Clean the Project

You can build and run this project using either `make` (recommended) or manual GCC compilation — both work cross-platform.

### ✅ Option 1: Using `make` (Recommended)

If you're on **Linux** or have **Chocolatey installed on Windows**, follow these steps:

```bash

# Compile the project
make

# Run the simulation
make run

# Clean build files
make clean

```

### 💻 Option 2: Manual Compilation Using GCC

If you prefer not to use `make`, you can compile manually using GCC:

```bash
# Compile all C files into an executable
gcc main.c ecu.c can.c scheduler.c error.c logger.c platform.c -o can_sim.exe

# Run the executable (on Windows)
.\can_sim.exe

# Or on Linux/macOS
./can_sim.exe


---

## 📄 Sample Output (Shortened)

==============================
CAN Multi-ECU Simulation Started
==============================

--- Simulation Cycle 1 ---
[ERROR] ECU 3: Injected bit error (simulated).
[Scheduler] ECU 1 scheduled to run...
[TX] ECU 1 Sent Frame - ID: 1, Data: 0xA1, CRC: 0x12
[RX] Frame Received by ECU 1 - CRC OK
...
Simulation Completed.

---

## 💬 What You'll Learn From This

- How CAN arbitration and transmission works

- How CRC helps detect corrupted data

- Realistic error-handling strategies for ECUs

- Task scheduling basics used in embedded systems

- How to simulate hardware-like timing in pure software

- Cross-platform delay handling using standard C libraries

- Writing clean, modular C code for multi-file projects

- Using Makefiles for automation

---

## 💡 Ideas to Take This Further 

- Want to challenge yourself more? Try these:

- Add multi-master arbitration logic

- Simulate ACK and error frames

- Port the logic to STM32 or Embedded Linux

- Build a GUI visualizer for CAN message flow

- Extend to UART/SPI protocol simulation with similar design

---

## 👨‍💻 Author

Rahul Rajendra Hasolkar
🔧 Embedded Systems | MISRA C | AUTOSAR | C Programming
🔗 [LinkedIn →](https://linkedin.com/in/rahulhasolkar)

---

## ⚙️ Tools Used

- 💻 Editor: Visual Studio Code

- 🛠️ Compiler: GCC (MinGW on Windows)

- 🧪 OS: Windows 10/11 + Linux

- 🧾 Automation: Makefile for easy builds

---

## 📝 License

- This project is open-source and intended for educational and learning purposes.
- You're welcome to use, modify, and share — just give credit if you do!

---

🚀 Built with 💻, ☕, and a passion for Embedded Systems.
🔒 No hardware needed. Just C, logic, and curiosity.

---







