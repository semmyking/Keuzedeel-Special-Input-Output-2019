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


 
 int analogPin1 = 0;
 int analogPin2 = 1;
 int val1 = 0;
 int val2 = 0;


 void setup() {
  pinMode(analogPin1, INPUT);
  pinMode(analogPin2, INPUT);
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
	val1 = analogRead(analogPin1);
    val2 = analogRead(analogPin2);
  Serial.println("X: " + String(round(val1/100)) + " | Y: " + String(val2/100));
 }

