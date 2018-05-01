#include <SoftwareSerial.h>
#include <SPI.h>
#include <DMD2.h>
#include <fonts/SystemFont5x7.h>

SoftDMD dmd(1,1);
// Number of P10 panels used X, Y
//DMD_TextBox box(dmd, 2, 1, 32, 16); 
// Set Box (dmd, x, y, Height, Width) 
String inData; // Allocate some space for the string
char inChar=-1; // Where to store the character read
byte index = 0; // Index into array; where to store the character
bool DEBUG = true;   //show more logs
int responseTime = 10; //communication timeout
//Serial1.begin(115200);


void setup() 
{
  // Open serial communications
  Serial.begin(9600);
  dmd.setBrightness(10); // Set brightness 0 - 255 
  dmd.selectFont(SystemFont5x7); // Font used
}

char rx=0;
String str,text,timer;
long timer2,timer3,time_passed=0;
int x,y,z ;
void loop() 
{ // run over and over
  
  while (Serial.available() > 0)
    {
        char recieved = Serial.read();
        inData += recieved; 
            DMD_TextBox box(dmd, 2, 1, 32, 16);
            dmd.begin();
            dmd.clearScreen();
            dmd.fillScreen(true);
            dmd.setBrightness(10);
            box.print(text);
            delay(timer2);
            dmd.clearScreen();
            dmd.fillScreen(true);
            dmd.setBrightness(255); 
            while (time_passed<timer3)
            {
              char *next=text.c_str();
              while(*next) 
              {
                box.print(*next);
                delay(500);
                next++;
              }
              time_passed+=1;
              //delay(time_passed);
              dmd.clearScreen();
              dmd.fillScreen(true);
              dmd.setBrightness(255); 
              dmd.end(); 
              dmd.end();
            }
               
        } 
        
      inData = ""; // Clear recieved buffer
      if (Serial.available()) 
      {
        rx = Serial.read();
      }
      
}

