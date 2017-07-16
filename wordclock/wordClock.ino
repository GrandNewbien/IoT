#include <Wire.h>
#include <RTClib.h>
#include <FastLED.h>
#define NUM_LEDS 121
#define DATA_PIN 6

CRGB leds[NUM_LEDS];
RTC_DS3231 rtc;
void setup() {
  delay(3000); // allow time for rtc to boot
//Serial.begin(9600);
//rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));  //Use this to set the time
FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  set_max_power_in_volts_and_milliamps(5, 500); // Use this for testing with a limited power supply (ie, USB)
 if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    
    while (1);
  }

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, lets set the time!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }

}


int color = 5;
int saturation = 255;
int brightness = 150;

int timemonth;
int timeday;
int timehour;
int timemin;
int timesec;

void loop() {
DateTime now = rtc.now();
   timemonth=now.month();
   timeday=now.day();
   timehour=now.hour();
   timemin=now.minute();
   timesec=now.second();
/*
Serial.print("hour: ");
Serial.println(now.hour(), DEC);
Serial.print("Min: ");
Serial.println(now.minute(), DEC);
Serial.print("Second: ");
Serial.println(now.second(), DEC);
*/
FastLED.clear();
displayWords();
FastLED.show();

delay(1000);
color += 1;
}

void displayWords() {

wordITS(); //always on

//********MINUTES********
  if(timemin>57 || timemin<3){
    //show nothing
    }
    
  if (timemin>2 && timemin<8){
    //"five" "past"
    wordFIVE();
    wordPAST();
    }
    
  if (timemin>7 && timemin<13){
    //"ten" "past"
    wordTEN();
    wordPAST();
    } 
     
  if(timemin>12 && timemin<18){
    //"a" "quarter" "past"
    wordA();
    wordQUARTER();
    wordPAST();
    }
    
  if(timemin>17 && timemin<23){
    //"twenty" "past"
    wordTWENTY();
    wordPAST();
    }
    
  if(timemin>22 && timemin<28){
    //"twenty" "five" "past"
    wordTWENTY();
    wordFIVE();
    wordPAST();
    }  
    
  if(timemin>27 && timemin<33){
    //"a" "half" "past"
    wordA();
    wordHALF();
    wordPAST();
    }  
    
  if(timemin>32 && timemin<38){
    //"twenty" "five" "til"
    wordTWENTY();
    wordFIVE();
    wordTIL();
    }  
    
  if(timemin>37 && timemin<43){
    //"twenty" "till"
    wordTWENTY();
    wordTIL();
    }  
    
  if(timemin>42 && timemin<48){
    //"a" "quarter" "til"
    wordA();
    wordQUARTER();
    wordTIL();
    }
    
  if(timemin>47 && timemin<53){
    //"ten" "til"
    wordTEN();
    wordTIL();
    }
    
  if(timemin>52 && timemin<58){
    //"five" "til"
    wordFIVE();
    wordTIL();
    }
    
    //********HOURS********
  if (timehour == 1 || timehour == 13){
    if(timemin>32){
      hourTWO();
      wordOCLOCK();
      }
    else{
      hourONE();
      wordOCLOCK();
        }
    }
    
  if (timehour == 2 || timehour == 14){
    if(timemin>32){
      hourTHREE();
      wordOCLOCK();
      }
    else{
      hourTWO();
      wordOCLOCK();
        }    
    }
    
  if (timehour == 3 || timehour == 15){
    if(timemin>32){
      hourFOUR();
      wordOCLOCK();
      }
    else{
      hourTHREE();
      wordOCLOCK();
        }    
    }
    
  if (timehour == 4 || timehour == 16){
    if(timemin>32){
      hourFIVE();
      wordOCLOCK();
      }
    else{
      hourFOUR();
      wordOCLOCK();
        }    
    }
    
  if (timehour == 5 || timehour == 17){
    if(timemin>32){
      hourSIX();
      wordOCLOCK();
      }
    else{
      hourFIVE();
      wordOCLOCK();
        }    
    }
    
  if (timehour == 6 || timehour == 18){
    if(timemin>32){
      hourSEVEN();
      wordOCLOCK();
      }
    else{
      hourSIX();
      wordOCLOCK();
        }    
    }
    
  if (timehour == 7 || timehour == 19){
    if(timemin>32){
      hourEIGHT();
      wordOCLOCK();
      }
    else{
      hourSEVEN();
      wordOCLOCK();
        }    
    }
    
  if (timehour == 8 || timehour == 20){
    if(timemin>32){
      hourNINE();
      wordOCLOCK();
      }
    else{
      hourEIGHT();
      wordOCLOCK();
        }    
    }
    
  if (timehour == 9 || timehour == 21){
    if(timemin>32){
      hourTEN();
      wordOCLOCK();
      }
    else{
      hourNINE();
      wordOCLOCK();
        }    
    }
    
  if (timehour == 10 || timehour == 22){
    if(timemin>32){
      hourELEVEN();
      wordOCLOCK();
      }
    else{
      hourTEN();
      wordOCLOCK();
        }    
    }
  if (timehour == 11){
    if(timemin>32){
      hourNOON();
      }
    else{
      hourELEVEN();
      wordOCLOCK();
        }    
    }
    
  if (timehour == 12){
    if(timemin>32){
      hourONE();
      wordOCLOCK();
      }
    else{
      hourNOON();
        }
    }
    
  if (timehour == 23){
    if(timemin>32){
      hourMIDNIGHT();
      }
    else{
      hourELEVEN();
      wordOCLOCK();
      }
    }
    
  if (timehour == 0){
    if(timemin>32){
      hourONE();
      wordOCLOCK();
      }
    else{
      hourMIDNIGHT();
        }
    }
    
  //********ANNIVERSARY DATE********
  if (timemonth == 1 && timeday == 26)
    anniversary();
  }
  
  
void wordITS(){
  fill_solid(leds,3,CHSV(color,saturation,brightness));
  }

void wordA(){
  leds[4] = CHSV( color, saturation, brightness);
  }

void wordHALF(){
  fill_solid(leds+6,4,CHSV(color,saturation,brightness));
  }

void wordTEN(){
  fill_solid(leds+18,3,CHSV(color,saturation,brightness));
  }

void wordQUARTER(){
  fill_solid(leds+11,7,CHSV(color,saturation,brightness));
  }
  
void wordTWENTY(){
  fill_solid(leds+22,6,CHSV(color,saturation,brightness));
  }

void wordFIVE(){
  fill_solid(leds+29,4,CHSV(color,saturation,brightness));
  }

void wordWAY(){
  fill_solid(leds+41,3,CHSV(color,saturation,brightness));
  }
  
void wordTIL(){
  fill_solid(leds+38,3,CHSV(color,saturation,brightness));
  }
  
void wordPAST(){
  fill_solid(leds+34,4,CHSV(color,saturation,brightness));
  }
  
void hourSEVEN(){
  fill_solid(leds+45,5,CHSV(color,saturation,brightness));
  }
  
void hourNOON(){
  fill_solid(leds+51,4,CHSV(color,saturation,brightness));
  }
  
void hourMIDNIGHT(){
  fill_solid(leds+66,8,CHSV(color,saturation,brightness));
  }
  
void hourTEN(){
  fill_solid(leds+74,3,CHSV(color,saturation,brightness));
  }
  
void hourFIVE(){
  fill_solid(leds+84,4,CHSV(color,saturation,brightness));
  }
  
void hourNINE(){
  fill_solid(leds+80,4,CHSV(color,saturation,brightness));
  }  
  
void hourTWO(){
  fill_solid(leds+77,3,CHSV(color,saturation,brightness));
  } 
  
void hourELEVEN(){
  fill_solid(leds+88,6,CHSV(color,saturation,brightness));
  } 
  
void hourEIGHT(){
  fill_solid(leds+94,5,CHSV(color,saturation,brightness));
  }
  
void hourONE(){
  fill_solid(leds+107,3,CHSV(color,saturation,brightness));
  }
  
void hourSIX(){
  fill_solid(leds+104,3,CHSV(color,saturation,brightness));
  }    
      
void hourTHREE(){
  fill_solid(leds+99,5,CHSV(color,saturation,brightness));
  }
  
void hourFOUR(){
  fill_solid(leds+110,4,CHSV(color,saturation,brightness));
  }
  
void wordOCLOCK(){
  fill_solid(leds+115,6,CHSV(color,saturation,brightness));
  }
  
void anniversary(){
  int anniversaryColor = color + 50;
  leds[6] = CHSV( anniversaryColor, saturation, brightness);
  leds[15] = CHSV( anniversaryColor, saturation, brightness);
  leds[28] = CHSV( anniversaryColor, saturation, brightness);
  leds[37] = CHSV( anniversaryColor, saturation, brightness);
  leds[50] = CHSV( anniversaryColor, saturation, brightness);
  fill_solid(leds+55,11,CHSV(anniversaryColor,saturation,brightness));
  anniversaryColor += 50;
  }
//date: July 16, 2017

/*  EXAMPLE LED CODE
 *  leds[32] = CHSV( color, saturation, brightness); 
 *  fill_solid(leds+15,7,CHSV(color,saturation,brightness));
 */




