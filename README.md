# airo-nrf52840-boards
Collection of Arduino-derived microcontroller boards developed at IDLab-AIRO, Ghent University, imec.

## Contents
### Smart Textile
PCB featured on the IDLab-AIRO Smart Textile ([paper](https://doi.org/10.3390/s22010222), [repo](https://github.com/RemkoPr/smart_textile_public)). The PCB connects to a piezoresistive pressure matrix in the textile, reads pressure values and communicates them to a remote host.
### Poly Piezo
Currently unpublished variation of the Smart Textile board.
### Halberd (I/O Coupling)
The Halberd coupling ([paper](https://doi.org/10.48550/arXiv.2309.05792), [repo](https://github.com/RemkoPr/airo-halberd)) is an enhancement of the [Robotiq I/O Coupling](https://blog.robotiq.com/robotiq-i/o-coupling-a-new-cable-management-solution), which is used to mount [Robotiq](https://robotiq.com/) grippers onto [Universal Robots](https://www.universal-robots.com/) robotic arms. It features power safety circuitry, such that the 24V output is disconnected when no gripper is attached, as well as a Nina B301 microcontroller, of which 8 analog pins and 15 digital pins are exposed. There are two I²C interfaces and one SPI interface, supported by specific digital pins. The board has a µUSB connector for convenient programming, a customisable RGB status LED indicator and an external 2.45GHz antenna.

## Installation
In your Arduino IDE, go to File > Preferences. In "Additional Boards Manager URLs", paste the following link:

 `https://raw.githubusercontent.com/RemkoPr/airo-nrf52840-boards/main/package_airo_index.json`
 
 Restart the Arduino IDE. Go to Tools > Board > Boards Manager... and search for the "IDLab-AIRO Boards" package.
 Click Install. You can now compile code for the different IDLab-AIRO boards using the Arduino IDE, as well as upload your sketch directly if the board features a µUSB connector and the Arduino Nano 33 BLE bootloader has been flashed.
 This was tested on Ubuntu 22.04 and Windows 10.

## Extra: Making your own custom Arduino board package
To guide you in your process of providing  a quick-to-install Arduino package for your own custom board, I'll outline the steps I took to create the one in this repo as an example.
The guide is written from a Windows perspective, the process is largely the same on Ubuntu.

***Starting point*** First of all, all boards in this repo feature an nrf52840 microcontroller (µC). This µC is also featured on the Arduino Nano 33 BLE. Hence, I first downloaded the Arduino Mbed OS Boards package
(which includes support for the Arduino Nano 33 BLE) through the Arduino Boards Manager. We will use this package as a starting point.
In the PC's file manager, go to `C:\Users\*username*\AppData\Local\Arduino15\packages\arduino\hardware\mbed_nano\` (Windows) or `~/snap/arduino/85/.arduino15/packages/arduino/hardware/mbed_nano` (Ubuntu, Arduino installed using snap). This folder should contain one or more version folders, e.g. `4.0.8`.
I copied the entire `4.0.8` folder to my repo folder and renamed it `src`. Inside, there are several `.variables` files. I know my custom boards are only related to the Nano 33 BLE, so I keep the `nano.variables` file and remove all others.
In the `platform.txt` file, I simply changed the `name` field from "Arduino Mbed OS Nano Boards" to "IDLab AIRO Boards" and the version field from "4.0.8" to "1.0.0".
In the `variants` folder, I delete the `NANO_RP2040_CONNECT` folder altogether and move the `ARDUINO_NANO33BLE` folder somewhere outside my repo folder. 

***Adding board variants*** For any board I wish to add to my custom package, I will add a copy of the `ARDUINO_NANO33BLE` folder to the `variants` folder and rename it to a name of my choosing, e.g. `IO_COUPLING`. 
Within the `IO_COUPLING` folder, I edit `pins_arduino.h` and `variant.cpp` such that the mapping from microcontroller pins to board GPIO pins, to builtin LEDs, to I2C interfaces, etc., conforms to my physical board PCB design. Do this step by step and follow the structure of the files.
Having added the variant, I exit the `variants` folder and open the `boards.txt` file. Here, I change every "nano33ble" prefix to a name representing my board. When adding a second variant, simply copy all lines at the bottom of the document and again change the prefixes with a different name. Set the .name field to the name of your board and make sure that the .build.variant and .build.board fields are set to the folder name of the variant it refers to (e.g. `IO_COUPLING`).

***Making the package installable from the Arduino IDE*** I moved the `installed.json` file outside of the `src` folder and renamed it `package_airo_index.json`. 
I zipped the entirety of the `src` folder (the folder itself, not only its contents), named it "airo-nrf52840-boards-1.0.0.zip" and put it in my repo's `releases` folder. 
Back in the `package_airo_index.json` file, I changed any names and version numbers to my liking and removed any fields included after toolsDependencies. 
In the url field, I entered "https://github.com/RemkoPr/airo-nrf52840-boards/raw/windows/releases/airo-nrf52840-boards-1.0.0.zip". **Note that this link refers to github raw, which is only updated every couple of minutes. Hence, if during development,
you've changed the .zip file and pushed it, you'll have to wait a while before you can retry installing your package from the IDE.**
I changed archiveFileName to "airo-nrf52840-boards-1.0.0.zip", [performed a SHA-256 checksum](https://docs.precisely.com/docs/sftw/spectrum/ProductUpdateSummary/ProductUpdateSummary/source/about_sha256.html) on the `airo-nrf52840-boards-1.0.0.zip` file in my `releases` folder and entered the result in the checksum field, and added the size in bytes of that same file in the size field. Lastly, in the boards field, I added the names of my custom boards, using the same names as in the boards.txt file from before.
