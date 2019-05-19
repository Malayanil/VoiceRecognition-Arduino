# Voice Recognition Hardware Implementation using Arduino UNO R3

Welcome to the Voice Recognition Project Repository. This project was implemented on hardware, the details are stated below in this READ ME File.

<h3>Index</h3>
<ol>
<li>Introduction</li>
<li>Hardware & Software Requirements</li>
<li>Hardware Assembly</li>
<li>Algorithm and Code</li>
<li>Working Demonstration</li>
<li>Future Scope</li>
</ol>

<hr>

                                                  ---END OF SECTION---

<hr>
 
<h3>1. INTRODUCTION</h3>
<p>
   Voice-biometrics refers to the technology or process of speech processing where voice can be used to verify a personal identity, unobtrusively and invisibly. Like other speechprocessing tools, voice biometrics extract information from the stream of speech to accomplish their work. In our model we are focusing on its ability to recognize what is being said. Voice recognition is a biometric modality that uses an individual’s voice for recognition purposes. Our proposed model or program receives and interprets dictation as well as understands and carries out the spoken command. Voice biometric solutions eliminate the need for PIN based password or interrogation–based authentication methods, or can be used to add another level of security to those systems.
  </p>
 <p>
  The <b>Arduino Uno R3</b> is an open-source microcontroller board based on the Microchip <b>ATmega328P</b> microcontroller and developed by Arduino.cc. The board is equipped with sets of digital and analog input/output pins that may be interfaced to various expansion boards and other circuits.
  </p>
  <p>
 Our model uses this board to control the analog signals passed from the mobile app, named <b>Android Meets Robot</b> to the Arduino via the <b>HC05 Bluetooth module</b>. It is programmed as per the need to fulfill the requirements of a Voice Recognition System fitted in smart homes.</p>
 <p>
We have currently implemented a simpler version of the Home Security System using Voice Recognition and we are aiming to develop it further using Machine Learning to implement only selected users’ voices to be accepted; right now, anyone with the correct “key phrase” can unlock or lock the device.
  </p>
  
<hr>

                                                  ---END OF SECTION---


<hr>
<h3>2. HARDWARE & SOFTWARE REQUIREMENTS</h3>
<p>
  <ol>
    <li>Arduino UNO R3</li>
    <li>HC05 Bluetooth Module</li>
    <li>LCD 16x2 Board</li>
    <li>Jumper Wires</li>
    <li>Bread Board</li>
    <li>LEDs</li>
    <li>Resistor</li>
   <li>Android App: - Android Meets Robots</li>
   <li>Arduino IDE</li>
  </ol>
</p>
<p>
  All the images are representation of the hardware we used.
  <br><img src="https://github.com/Malayanil/VoiceRecognition-Arduino-/blob/master/all.jpg">
  </p>
  <p>The Android Meets Robots App helps us to connect to the Bluetooth Module to send instructions and the Arduino IDE is used to program the Arduino UNO R3 Board according to our needs.</p>
 <hr>
 
                                                  ---END OF SECTION---


 <hr>
 
 <h3>3. HARDWARE ASSEMBLY</h3>
 <p>
 The following connections were done.
<ul>
 <li>Bluetooth Pin RX to Arduino TX</li>
 <li>BT Pin TX to Arduino RX</li>
 <li>BT Pin 5V to Arduino 5V</li>
 <li>BT Pin GND to Arduino GND</li>
 <li>Led1 Positive to Arduino Pin 7</li>
 <li>Led1 Negative to GND</li>
 <li>Led2 Positive to Arduino Pin 8</li>
 <li>Led2 Negative to GND</li>
 <li>Led3 Positive to Arduino Pin 9</li>
 <li>Led3 Negative to GND</li>
 <li>Led4 Positive to Arduino Pin 10</li>
 <li>Led4 Negative to GND</li>
 <li>LCD VSS to Arduino GND</li>
 <li>LCD VDD to Arduino 5V</li>
 <li>LCD RS to Arduino Pin 12</li>
 <li>LCD E to Arduino Pin 11</li>
 <li>LCD V0 to Arduino Pin 6</li>
 <li>LCD A to Arduino 5V</li>
 <li>LCD K to Arduino GND</li>
 <li>LCD RW to Arduino GND</li>
 <li>LCD D0 to D3 Arduino GND</li>
 <li>LCD D4 to Arduino Pin 5</li>
 <li>LCD D5 to Arduino Pin 4</li>
 <li>LCD D6 to Arduino Pin 3</li>
 <li>LCD D7 to Arduino Pin 2</li>
</ul>
 </p>
 
 <hr>
 
                                                  ---END OF SECTION---


 <hr>
 <h3>4. ALGORITHM AND CODE</h3>
<h4>Algorithm</h4><br>
 <p>The algorithm implemented on the working of the hardware is pretty simple and straight-forward. The user has to connect the <b>HC05 Bluetooth Module</b> with the <b>Android Meets Robot App</b> via Bluetooth using a smartphone. The '<b>key phrase</b>' has to be spoken. The App then forwards the voice data to the <b>HC05 Bluetooth Module</b>. Then it is forwarded to the <b>Arduino UNO R3 Board</b>. The program burned to the <b>Arduino UNO R3</b> decides if the data matches the '<b>key phrase</b>' and generates the output accordingly.
</p><br>
 <h4>Code</h4>
 <p>
 The code is uploaded in the file <b>'minor_project.ino'</b>.
</p>
<p>
 The first line indicates the inclusion of <b>LiquidCrystal.h</b> library for use in the Arduino to display in the 16x2 LCD Board. 
 
           #include<LiquidCrystal.h>
 
 A few global variables are defined for varid use in the programming of Arduino.
 
           String voice;
           int
           led1 = 7, //Connect LED 1 To Pin #7
           led2 = 8, //Connect LED 2 To Pin #8
           led3 = 9, //Connect LED 3 To Pin #9
           led4 = 10; //Connect LED 4 To Pin #10
           
 User Defined functions for the key phrases.
 
           void turn_on()
           {
                digitalWrite(led1, HIGH);
                digitalWrite(led2, HIGH);
                digitalWrite(led3, HIGH);
                digitalWrite(led4, HIGH);
           }
           
           void turn_off()
           {
                digitalWrite(led1, LOW);
                digitalWrite(led2, LOW);
                digitalWrite(led3, LOW);
                digitalWrite(led4, LOW);
           }

           const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
   
 The HIGH and LOW parameters specify the switch ON and OFF factors.
 
           void setup() 
           {
            lcd.begin(16,2);
            analogWrite(6,15);

            Serial.begin(9600);
            pinMode(led1, OUTPUT);
            pinMode(led2, OUTPUT);
            pinMode(led3, OUTPUT);
            pinMode(led4, OUTPUT);
            lcd.print("Password Please");
           }
           
Initializing the LCD to display something after the device is powered on and defining the OUTPUT modes for the Arduino.

            void loop() 
            {
              // Print a message to the LCD.

              while (Serial.available()){  //Check if there is an available byte to read
              delay(10); //Delay added to make thing stable
              char c = Serial.read(); //Conduct a serial read
              if (c == '#') {break;} //Exit the loop when the # is detected after the word
              voice += c; //Shorthand for voice = voice + c
              } 
              if (voice.length() > 0) {
                Serial.println(voice);
                lcd.setCursor(0, 1);
            //-----------------------------------------------------------------------//   
              //----------Control Multiple Pins/ LEDs----------// 
                   if(voice == "*turn on") 
                   {
                    turn_on();
                    lcd.clear();
                    lcd.print("Accepted");
                   }  //Turn On All Pins (Call Function)
              else if(voice == "*turn off"){turn_off(); lcd.clear();lcd.print("Accepted");} //Turn Off  All Pins (Call Function)

              //----------Turn On One-By-One----------//
              else if(voice == "*TV on") {digitalWrite(led1, HIGH);lcd.clear();lcd.print("Accepted");}
              else if(voice == "*fan on") {digitalWrite(led2, HIGH);lcd.clear();lcd.print("Accepted");}
              else if(voice == "*computer on") {digitalWrite(led3, HIGH);lcd.clear();lcd.print("Accepted");}
              else if(voice == "*bedroom lights on") {digitalWrite(led4, HIGH);lcd.clear();lcd.print("Accepted");}
              //----------Turn Off One-By-One----------//
              else if(voice == "*TV off") {digitalWrite(led1, LOW);lcd.clear();lcd.print("Accepted");}
              else if(voice == "*fan off") {digitalWrite(led2, LOW);lcd.clear();lcd.print("Accepted");}
              else if(voice == "*computer off") {digitalWrite(led3, LOW);lcd.clear();lcd.print("Accepted");}
              else if(voice == "*bedroom lights off") {digitalWrite(led4, LOW);lcd.clear();lcd.print("Accepted");}
            //-----------------------------------------------------------------------// 
            voice="";}
            delay(2000); //Delay 
            lcd.print("Password Please"); //Reset the LCD display
            }
 
 The comments explain the working of the code.
 </p>
 <hr>
 
                                                  ---END OF SECTION---


 <hr>
 <h3>5. WORKING DEMONSTRATION</h3>
 <p>
 The working demonstration video is uploaded, named as <b>Demonstration.mp4</b>.
 <br>
 Turned On with "Key Phrase": <b>'turn on'</b>.<br>
 <img src="https://github.com/Malayanil/VoiceRecognition-Arduino/blob/master/turn_on.jpeg" height=400 width=300>
 <br>
 Turned Off with "Key Phrase": <b>'turn off'</b>.<br>
 <img src="https://github.com/Malayanil/VoiceRecognition-Arduino/blob/master/turn_off.jpeg" height=400 width=300><br>
 </p>
 
 <hr>
 
                                                  ---END OF SECTION---


 <hr>
 <h3>6. FUTURE SCOPE</h3>
 <p>
 This can be actively implemented in Smart Home Security solutions after being improved with a Machine Learning model design. The Arduino cannot be re-programmed unless a USB is inserted to it and burned accordingly after being fitted into a working device. The bluetooth discovery of the HC05 can be programmed and hidden; providing access to only one client once paired. Moreover, this is cheaper than other alternatives available in the market. Approximate expense of this project was around Rs.800 only.
 </p>
 <hr>
 
                                                  ---END OF SECTION---


<hr>
