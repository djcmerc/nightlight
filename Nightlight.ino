 
 float volts = 4.72; // Defining the voltage of the power supply
 int count = 1;
 int x = 0;
 float y = 0;
 
 void setup() {
   //Serial.begin(9600);
   pinMode(1, OUTPUT); // 9 is original pin on arduino
 }
 
 void loop() {

   // Calculates the voltage drop between the resistor and photocell
   float v = (analogRead(3) * volts) / 1024.0;
   
   //Serial.print(v);
   //Serial.print(x);
   //Serial.println(count);

   // Controls the on, off, and dimming conditions of the LED
      // Original was 4.85 based on 5V
   if (v >= 4.48)
   {
      if (count > 0) // 10 seconds = 100 in count since using 100ms delay, 10 sec = 800 count without delay
      {
         count = count + 1;
         delay(100);
        /*
        if (count >= 100)
        {
          count = 0;
        }
        */
        if (count >= 100) // After 10 seconds, LED will dim
        {
          y = 255 - (230 * ((count - 100)) / 100); // FORMULA: (Max Value) - ((Max Value - End Value)*((count - Start Count)/ (End Count - Start Count))
          x = (int) y;
          analogWrite(1, x);
          if (count >= 200) count = 0;
        }
        else {
          analogWrite(1, 255);
        }
     }
     else analogWrite(1, 25);
   }
   else // When exposed to light
   {
      analogWrite(1, 0);
      count = 1;
      delay(100);
   }
 }
