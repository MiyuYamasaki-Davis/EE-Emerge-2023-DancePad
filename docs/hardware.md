# Hardware Design

The project utilizes a comparator circuit in order to determine contact between the plates for the pad controller.

![Comparator]()

By use of this circuit, we are able to cleanly detect a change in voltage through the op amp by directing the voltage flow to a microcontroller that is able to comprehend analog changes and convert it into a digital signal.

# Mechanical Design

The system we use in conjunction with the comparator circuit is a pressure plate-like mechanism. 

![Plate Design]()

By layering copper conductive tape across the plate and alternating a positive connection with a ground connection to every other tape, we can lay the same copper tape across the top plate in the opposite direction to complete the circuitry. The top plate tape acts as a jumper between the positive and negative connections of the tape on the bottom plate. This triggers the comparator circuit to allow a voltage through the op amp, creating an analog signal to be converted.
