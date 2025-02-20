/*variable puls generator
2 pot 
1pushbutton
oled 128x32
dc dc to 6v

make variable pulse with pot on off
output like you want 
a5 scls 13 
a4 sda  12
a6 an1  19
a7 an2  20
a0 pushbutton  is invert 1 is not pressed
a1 output signal 

*/


#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <elapsedMillis.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels


#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define an1 A6//9
#define an2 A7 //a7 =22 oeps
#define pushbutton A0
#define Soutput A1
//timing refresh

elapsedMillis e_scan;
elapsedMillis e_cycletime;
elapsedMillis e_scanio;
int scaninterval = 500;
int scaniointerval = 1000;

//var
String version ="version 2";
int an1value =0;
int an2value =0;
bool bpushbutton = false;
bool boutput = false;
int Ontime = 0;
int Oftime = 0;
int setOntime = 0;
int setOftime = 0;

//verwerken puls
elapsedMillis e_timeElapsed;
bool isOn = false;

void setup() 
{
  //define io
  pinMode(an1,INPUT);
  pinMode(an2,INPUT);
  pinMode(pushbutton,INPUT);
  pinMode(Soutput, OUTPUT);

  digitalWrite(Soutput,LOW);
  
  //serial
  Serial.begin(115200);
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) 
  {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
  delay(1000); // Pause for 2 seconds

  // Clear the buffer
  display.clearDisplay();
  booting();
  display.display();
  delay(2000);
  Serial.println(version);
}

void loop()
{
   //scan io
   if (e_scanio > scaniointerval) 
    {
      read_io();
      e_scanio=0;
    }
  //show values on oled
  if (e_scan > scaninterval) 
   {  display.clearDisplay();
      showdata();
      display.display();

      //check reload time
      bool input =digitalRead(pushbutton);
      if (!input)
      {
        setOntime = Ontime;
        setOftime =Oftime;
        e_timeElapsed = 0;
        digitalWrite(Soutput, LOW);
        //debug
        Serial.println("++++++++++++++++++++++++++++");
        Serial.println("setOntime: " + String(setOntime) + ", setOftime: " + String(setOftime) );
        Serial.println("++++++++++++++++++++++++++++");
      }
      e_scan = 0;
   }
  
  //control output

  if (isOn && (e_timeElapsed >= setOntime ))
  {
    // Turn off after on time has elapsed
    digitalWrite(Soutput, LOW);
    isOn = false;
    e_timeElapsed = 0; // Reset timer
  } 
  else if (!isOn && (e_timeElapsed >= setOftime)) 
  {
    // Turn on after off time has elapsed
    digitalWrite(Soutput, HIGH);
    Serial.println("Output on");
    isOn = true;
    e_timeElapsed = 0; // Reset timer
  }
  
  //debug
  if (e_cycletime > 200)
  {
   Serial.println("--");
   Serial.print("Cycletime:=");
   Serial.println(e_cycletime);
  }
  e_cycletime = 0;
}


void showdata()
 { int randnum1;
   int randnum2;
  randnum1 = random(10, 25);
  randnum2 = random(10, 25);
  display.setTextSize(2);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(0,0);             // Start at top-left corner
  display.print(F("ON_T:"));
  display.print(Ontime);
  display.setCursor(0,15);  
  display.print(F("OF_T:"));
  display.print(Oftime);
 
 }

void booting() 
{
  display.setTextSize(2);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(0,0);             // Start at top-left corner
  display.println(F("Booting..."));
 
}

