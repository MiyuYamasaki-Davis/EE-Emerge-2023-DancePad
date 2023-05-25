# Encasement and Mechanical Design

The directional pad encasement is made out of wood to minimize cost and create more durability in the frame to allow for all player sizes (children, adults, etc.). 

![Encasement]()

The PCB and microcontroller are protected in the center square and receive inputs from each arrow square. Each arrow square contains two wood pieces with copper tape that face each other on opposing sides (top and bottom), which are connected to a designated comparator circuit via soldered wires. The two wood pieces are separated by foam pieces placed in the corners of the square, preventing contact between the copper tapes when the arrow is unpressed. When the arrow is pressed, the foam compresses and allows contact between the copper tapes, which sends a current and changes the input voltage of its designated comparator circuit

The system we use in conjunction with the comparator circuit is a pressure plate-like mechanism. 

![Plate Design](https://github.com/MiyuYamasaki-Davis/EE-Emerge-2023-DancePad/blob/main/pictures/Encasement/plate.jpg?raw=true)

By layering copper conductive tape across the plate and alternating a positive connection with a ground connection to every other tape, we can lay the same copper tape across the top plate in the opposite direction to complete the circuitry. The top plate tape acts as a jumper between the positive and negative connections of the tape on the bottom plate. This triggers the comparator circuit to allow a voltage through the op amp, creating an analog signal to be converted.
