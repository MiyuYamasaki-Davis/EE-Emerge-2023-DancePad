# Encasement and Mechanical Design

The directional pad encasement is made out of wood and acrylic to minimize cost and create more durability in the frame to allow for all player sizes (children, adults, etc.). 

![Encasement](https://github.com/MiyuYamasaki-Davis/EE-Emerge-2023-DancePad/blob/main/docs/Pics/case.jpg?raw=true)

The PCB and microcontroller are protected in the center square and receive inputs from each arrow square. Each arrow square contains two wood pieces with copper tape that face each other on opposing sides (top and bottom), which are connected to a designated comparator circuit in our PCB via soldered wires. The two wood pieces are separated by foam pieces placed in corners of the square, preventing contact between the copper tapes when the arrow is unpressed, and creating an open circuit. When the arrow is pressed, the foam compresses and allows contact between the copper tapes, changing the circuit from an open circuit to a closed circuit, and signaling to the comparator circuit that an arrow has been pressed.

The system we use in conjunction with the comparator circuit is a pressure plate-like mechanism. 

![Plate Design PHOTO](https://github.com/MiyuYamasaki-Davis/EE-Emerge-2023-DancePad/blob/main/pictures/Encasement/plate.jpg?raw=true)

By layering copper conductive tape across the plate in an alternating fashion on the bottom plate, and laying the same copper tape across the top plate in the opposite direction, there is a large area that the player can step on in order to complete the circuit. The top plate tape acts as a jumper between the positive and negative connections of the tape on the bottom plate. This triggers the comparator circuit to allow a voltage through the operational amplifier, creating an analog signal to be converted by the arduino, which then communicates with our C++ game, allowing the user to play.
