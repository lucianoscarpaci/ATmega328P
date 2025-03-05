🔒 **Embedded Crypto Projects with Arduino Board**

Welcome to the ATmega328P project repository! This project is all about exploring embedded systems and cryptography using the Arduino platform.

## 📜 Project Overview

This repository contains various projects that demonstrate the capabilities of the ATmega328P microcontroller. Our current project list includes:

- **Blink**: A simple yet essential project to get you started with Arduino programming.

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

### Compiling the Sketch

Once the core is installed, you can compile your sketch. Navigate to the project directory and run:

```bash
arduino-cli compile --fqbn arduino:avr:nano:cpu=atmega328old --output-dir "$PWD/build" $PWD/build/build.ino
```

### Flashing the Image

After compiling, you can flash the image to your Arduino board. Use the following command in the project directory:

```bash
arduino-cli upload -p /dev/cu.usbserial-1420 -b arduino:avr:nano:cpu=atmega328old --input-dir "$PWD/build"
```

## 🤝 Contributing

We welcome contributions from the community! If you have ideas for new projects or improvements, feel free to open an issue or submit a pull request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more information.