int val1 = 0;
int lastVal1 = 0;

void setup(){
  //Use the same speed as Hairless Midi software
  //Enable Serial
  Serial.begin(9600);
}

void loop(){
  //Reading POT 1
  val1 = analogRead(1)/8; // Divide by 8 to get range of 0-127 for midi
  //if pot changed it's value, we send a MIDI Message
  if (val1 != lastVal1){
    MIDImessage(176,1,val1);
  }
  lastVal1 = val1; //update last value

  //here we add a short delay to help prevent slight fluctuations, knocks on the pots etc. 
  //Adding this helped to prevent my pots from jumpin up or down a value when slightly touched or knocked.
  delay(10);
}

//function to send MIDI MESSAGE
void MIDImessage(byte command, byte data1, byte data2) 
{
   Serial.write(command); //cc ccomand
   Serial.write(data1);  //cc number
   Serial.write(data2); //value
}
