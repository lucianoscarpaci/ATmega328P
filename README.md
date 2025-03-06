# A T M E G A 3 2 8 P

![Arduino](https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=arduino&logoColor=white)
![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)

🔒 **Embedded Crypto Projects with Arduino Board**

Welcome to the ATmega328P project repository! This project is all about exploring embedded systems and cryptography using the Arduino platform.

## 📜 Project Overview

This repository contains various projects that demonstrate the capabilities of the ATmega328P microcontroller. Our current project list includes:

- **Blink**: A simple yet essential project to get you started with Arduino programming.
- **GCD**: A project that calculates the greatest common divisor of two numbers.

## 🛠️ Requirements

To get started with this project, you'll need the following:

- **nix-shell**: A powerful tool for managing development environments.

## 🚀 Getting Started

### Installing the AVR Core

Before you can start working with the ATmega328P, you'll need to install the AVR core in the Arduino CLI. Here's how:

1. Start `nix-shell`.
2. Run the following command to install the AVR core:
   ```bash
   arduino-cli core install arduino:avr
   ```

### Automated Compiling and Flashing

Once the core is installed, you can compile and flash your sketch. Navigate to the project directory and run:

```bash
./flash
```

build.hs is the config file that can be edited for new settings.

## 🤝 Contributing

We welcome contributions from the community! If you have ideas for new projects or improvements, feel free to open an issue or submit a pull request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more information.