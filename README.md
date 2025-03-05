# ATmega328P
Basic Bare-Metal Embedded Crypto Projects

# Projects list

# Requirements list
Nix
Haskell
arduino-cli
# Installing AVR core in arduino-cli
Start nix-shell and install:
```bash 
arduino-cli core install arduino:avr
```
# Compiling the sketch:
In the directory of the project,
To compile:
```bash
arduino-cli compile --fqbn arduino:avr:nano:cpu=atmega328old --output-dir "$PWD/build" \
$PWD/build/build.ino
```

# Flashing the image:
In the directory of the project, 
To Flash:
```bash
arduino-cli upload -p /dev/cu.usbserial-1420 -b arduino:avr:nano:cpu=atmega328old --input-dir "$PWD/build"
```