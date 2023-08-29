# airo-nrf52840-boards
Collection of Arduino-derived microcontroller boards developed at IDLab-AIRO, Ghent University, imec.

## Contents
### Smart Textile
PCB featured on the IDLab-AIRO Smart Textile ([paper](https://doi.org/10.3390/s22010222), [repo](https://github.com/RemkoPr/smart_textile_public)). The PCB connects to a piezoresistive pressure matrix in the textile, reads pressure values and communicates them to a remote host.
### Poly Piezo
Currently unpublished variation of the Smart Textile board.
### Halberd (I/O Coupling)
An enhancement of the [Robotiq I/O Coupling](https://blog.robotiq.com/robotiq-i/o-coupling-a-new-cable-management-solution), which is used to mount [Robotiq](https://robotiq.com/) grippers onto [Universal Robots](https://www.universal-robots.com/) robotic arms.

## Installation
In your Arduino IDE, go to File > Preferences. In "Additional Boards Manager URLs", paste the following link:
 ´´´https://raw.githubusercontent.com/RemkoPr/airo-nrf52840-boards/main/package_airo_index.json´´´
 Restart the Arduino IDE. Go to Tools > Board > Boards Manager... and search for the "IDLab-AIRO Boards" package.
 Click Install. You can now compile code for the different IDLab-AIRO boards using the Arduino IDE, as well as upload your sketch directly if the board features a µUSB connector.
