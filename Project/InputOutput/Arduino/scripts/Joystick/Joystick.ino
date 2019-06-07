 /* Read Jostick
  * ------------
  *
  * Reads two analog pins that are supposed to be
  * connected to a jostick made of two potentiometers
  *
  * We send three bytes back to the comp: one header and two
  * with data as signed bytes, this will take the form:
  *     Jxy\r\n
  *
  * x and y are integers and sent in ASCII 
  * 
  * http://www.0j0.org | http://arduino.berlios.de
  * copyleft 2005 DojoDave for DojoCorp
  */

 const int buttonPin = 2; 
 int buttonState = 0;  
 
 int analogPin1 = 0;
 int analogPin2 = 1;
 int analogPin3 = 2;
 int analogPin4 = 3;

 int val1 = 0;
 int val2 = 0;
 int val3 = 0;
 int val4 = 0;


 void setup() {
  pinMode(analogPin1, INPUT);
  pinMode(analogPin2, INPUT);
  pinMode(analogPin3, INPUT);
  pinMode(analogPin4, INPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
 }

 int signMid(int _value, int _negative, int _mid, int _positive)
 {
   int _return = 0;
   
   if (_value < _negative)
	   _return = -1;
   else if (_value > _positive)
	   _return = 1;
   else if (_value == _mid)
	   _return = 0;

   return _return;
 }

 int sign(int _x)
 {
	 return ((_x > 0) - (_x < 0)) || +_x;
 }

 void loop() {
  buttonState = digitalRead(buttonPin);
	val1 = analogRead(analogPin1);
  val2 = analogRead(analogPin2);
  val3 = analogRead(analogPin3);
  val4 = analogRead(analogPin4);
  Serial.println("X: " + String(round(val1/100)) + " | Y: " + String(val2/100)+"        |  X: " + String(round(val3/100)) + " | Y: " + String(val4/100));
  delay(100);
  
  if (buttonState == HIGH) {
    Serial.println("Button pressed");
  }else {
    Serial.println("Button not pressed");
  }
  
 }
