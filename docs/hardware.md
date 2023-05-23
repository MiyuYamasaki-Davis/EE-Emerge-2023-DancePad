# Hardware Design

Our PCB's purpose is to compare two voltages. A threshold voltage and the pressure plate voltage. Once the pressure plate is pressed it becomes higher than the threshold. Therefore registering a press on our sensor. We accomplished this by using a comparator circuit.

![Comparator](https://github.com/MiyuYamasaki-Davis/EE-Emerge-2023-DancePad/blob/main/pictures/Hardware/PCB%20v4%20Final.png?raw=true)

# Mechanical Design

The system we use in conjunction with the comparator circuit is a pressure plate-like mechanism. 

![Plate Design]()

By layering copper conductive tape across the plate and alternating a positive connection with a ground connection to every other tape, we can lay the same copper tape across the top plate in the opposite direction to complete the circuitry. The top plate tape acts as a jumper between the positive and negative connections of the tape on the bottom plate. This triggers the comparator circuit to allow a voltage through the op amp, creating an analog signal to be converted.
