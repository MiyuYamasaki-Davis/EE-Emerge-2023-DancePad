# Software Design
The project incorporates a randomly generated maze as the game through an algorithm known as a Minimum Spanning Tree, or MST. This algorithm utilizes randomly assigned weights between neighboring nodes, then runs a procedure to connect the nodes based on the smallest weights found. From this, the program is able to create a tree with dangling child nodes that result in dead ends. This solution also guarantees that a single path from any one point to another will always be feasible, no matter the points chosen.

This project was handled by two software programs: Visual Studio 2022 Community Build and Arduino IDE

## Visual Studio 2022
Visual Studio 2022 is an open source IDE that allows utilization of C++/CLI to develop graphics based C++ projects. It was chosen as the optimal coding environment for C++.

## Arduino IDE
Arduino IDE is the coding source for the Arduino Uno board used to fascilitate Analog-to-Digital Conversion for communication between the PCB and computer.

## Minimium Spanning Tree Algorithm Flowchart
![MST](https://github.com/MiyuYamasaki-Davis/EE-Emerge-2023-DancePad/blob/main/pictures/Software/MST(1).png?raw=true)

## Timer Loop Flowchart
![Timer](https://github.com/MiyuYamasaki-Davis/EE-Emerge-2023-DancePad/blob/main/pictures/Software/Timer.png?raw=true)
