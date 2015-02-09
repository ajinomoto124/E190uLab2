# E190uLab2
## Lab2 Write-Up
#### Introduction:
Wrote firmware for controller from lab 1

#### Design Methodology:
Given the unusual design of the controller, I attempted to map physical inputs similar to the way they would be handled by an N64 controller.  All of the buttons mounted on the front face of the controller got simple writes to different keys on the keyboard.  The button mounted on top of the controller (similar to the "L" button on a standard controller) was mapped to the right click of a mouse and the button mounted on the back of the controller was mapped to mouse left click.  The right (technically center) analog x and y were mapped to x and y directions of mouse movement and the left  analog x and y were mapped to directional key presses.

#### Testing Methodology:
Before mapping all the buttons and directions to appropriate keys and mouse instructions, I wrote a test file that printed the values retrieved from digital and analog reads of all inputs to the serial.  Because there were so many inputs, the switch mounted on the controller switched the display between showing the inputs that required digital reads and the inputs that required analog reads.  This helped when mapping the buttons to actual keyboard/mouse actions.

After uploading to the arduino, I tested the functionality of the controller on the note application for mac.

#### Results and Discussion
Currently all buttons only output one keystroke when pressed and do not add any additional key strokes when held.  Depending on the game, this may need to be changed.  Luckily this is a simple fix as currently the directional inputs for keys will continuously output keystrokes.

#### Conclusions
Time spend on lab: about 2 hours.
The initial reading in of values took a fairly short amount of time.  The most time consuming part of this lab was adjusting values so the output was correct.  
