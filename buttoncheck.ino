/*
  ButtonSetup for arduino game controller
           
 */

// digital pin 2 has a pushbutton attached to it. Give it a name:
int button2 = 2;
int button3 = 3;
int button4 = 4;
int button5 = 5;
int button6 = 6;
int button7 = 7;
int button8 = 8;
int button9 = 9;
int button10 = 10;
int button11 = 11;

// parameters for reading the joystick:
int range = 80;               // output range of X or Y movement
int threshold = range/4;      // resting threshold
int center = range/2;         // resting position value


// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
  pinMode(button5, INPUT_PULLUP);
  pinMode(button6, INPUT_PULLUP);
  pinMode(button7, INPUT_PULLUP);
  pinMode(button8, INPUT_PULLUP);
  pinMode(button9, INPUT_PULLUP);
  pinMode(button10, INPUT_PULLUP);
  pinMode(button11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  
 Mouse.begin();
  Keyboard.begin();
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  int switchState = digitalRead(12);
  
if(switchState == 0){
 
  int buttonLState = analogRead(A4);
  int buttonRState = analogRead(A1);
  
  int lStickY = analogRead(A3);
  int lStickX = analogRead(A5);
  int rStickY = analogRead(A2);
  int rStickX = analogRead(A0);
  
  int button2State = digitalRead(button2);
  int button3State = digitalRead(button3);
  int button4State = digitalRead(button4);
  int button5State = digitalRead(button5);
  int button6State = digitalRead(button6);
  int button7State = digitalRead(button7);
  int button8State = digitalRead(button8);
  int button9State = digitalRead(button9);
  int button10State = digitalRead(button10);
  int button11State = digitalRead(button11);
  
   // read and scale the two axes:
  int xReading = readAxis(A5);
  int yReading = 1024-readAxis(A3);
  int lxReading = readAxis(A0);
  int lyReading = readAxis(A2);
  
  Mouse.move(xReading, yReading, 0);
  
  if (digitalRead(button2) == LOW) { 
    Keyboard.press('h');
  }
  else if (digitalRead(button2) == HIGH){
    Keyboard.release('h');
  }
  if (digitalRead(button3) == LOW) { 
    Keyboard.press('j');
  }
  else if (digitalRead(button3) == HIGH){
    Keyboard.release('j');
  }
  if (digitalRead(button4) == LOW) {
    Keyboard.press('k'); 
  }
  else if (digitalRead(button4) == HIGH) {
    Keyboard.release('k'); 
  }
  if (digitalRead(button5) == LOW) {
    Keyboard.press('i'); 
  }
  else if (digitalRead(button5) == HIGH) {
    Keyboard.release('i'); 
  }
  if (digitalRead(button6) == LOW) {
    Keyboard.press('u'); 
  } 
  else if (digitalRead(button6) == HIGH) {
    Keyboard.release('u'); 
  } 
  if (digitalRead(button7) == LOW) {
    Keyboard.press('y'); 
  }
  else if (digitalRead(button7) == HIGH) {
    Keyboard.release('y'); 
  }
  if (digitalRead(button8) == LOW) {
    Keyboard.press('o'); 
  }
  else if (digitalRead(button8) == HIGH) {
    Keyboard.release('o'); 
  }
  if (digitalRead(button9) == LOW) {
    Keyboard.press('p'); 
  }
  else if (digitalRead(button9) == HIGH) {
    Keyboard.release('p'); 
  }
  if (digitalRead(button10) == LOW) {
     Mouse.click();
  }
  if (digitalRead(button11) == LOW) {
     Mouse.click(MOUSE_RIGHT); 
  }
  if (lxReading < -20) {
    Keyboard.press('KEY_LEFT_ARROW'); 
    Keyboard.release('KEY_LEFT_ARROW'); 
  }
  if (lxReading > 20) {
    Keyboard.press('KEY_RIGHT_ARROW');
    Keyboard.release('KEY_RIGHT_ARROW'); 
  }
  if (lyReading < -20) {
    Keyboard.press('KEY_DOWN_ARROW'); 
    Keyboard.release('KEY_DOWN_ARROW');
  }
  if (lyReading > 20) {
    Keyboard.press('KEY_UP_ARROW');
    Keyboard.release('KEY_UP_ARROW');
  }
  if(buttonLState == LOW){
   Keyboard.press('x'); 
  }
  else if(buttonLState != LOW){
   Keyboard.release('x'); 
  }
  if(buttonRState == LOW){
    Keyboard.press('z');
  }
  else if(buttonRState != LOW){
    Keyboard.release('z');
  }
 
  
  }
  
  delay(10);        // delay in between reads for stability
}
// readaxis taken from example
int readAxis(int thisAxis) { 
  // read the analog input:
  int reading = analogRead(thisAxis);
  
  // map the reading from the analog input range to the output range:
  reading = map(reading, 0, 1023, 0, range);

  // if the output reading is outside from the
  // rest position threshold,  use it:
  int distance = reading - center;

  if (abs(distance) < threshold) {
    distance = 0;
  } 

  // return the distance for this axis:
  return distance;
}




