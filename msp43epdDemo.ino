/**
 *  @filename   :   msp430_epd_demo.ino
 *  @revision   :   rev 1.0
 *  @brief      :   2.9" E Ink Display demo on MSP430FR2433 MCU 
 *                  Display updates partially every 500ms and resets every 10 refreshes 
 *                  Uses the Epd library by Waveshare 
 *  @author     :   GS Gill (TechNERVERS) (gsgill.github.io)
 *
 *  Copyright (C) TechNERVERS     Nov 13 2018
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documnetation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to  whom the Software is
 * furished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS OR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

 /**
  * 
  * MSP430 Connections :---------------------------
  * -----------------------------------------------
  * EPD               MSP430FR2433      WIRING PIN
  * -----------------------------------------------
  * BUSY                P1.2                10
  * RST                 P1.3                9
  * DC                  P2.7                8
  * CS                  P3.1                13
  * CLK                 P2.4                7
  * DIN/MISO            P2.6                15
  * -----------------------------------------------
  * 
  */

 /**
  * To Do 
  * 1.  Low power Modes MSP 430 
  * 2.  Low Power Mode 2.9" E_Ink Display
  */

#include "imagedata.h"
#include "epd2in9.h"
#include "epdpaint.h"

 /* Defines */
#define COLORED     0
#define UNCOLORED   1

/* Uncomment to enable Serial Debug */
#define DEBUG 1

/** 
 *  Uncommecnt to display SPLASH image 
 *  NOTE 1x Image is approx 4.5KB So it is not possible 
 *  to fit the text as well as the font in the 15K space.
 */
//#define SPLASH 1


/**
 * Simple function call that refresh the display 
 * Use this function to avoid Gosting of Display.
 */
void epd_refresh(void);
/**
 * Simple function to draw the main frame 
 * after each full refresh 
 */
void dispMainFrame(void);
/**
  * Due to RAM not enough in Arduino UNO, a frame buffer is not allowed.
  * In this case, a smaller image buffer is allocated and you have to 
  * update a partial display several times.
  * 1 byte = 8 pixels, therefore you have to set 8*N pixels at a time.
  * 
  * Objects for Epd Lib access.
  */
unsigned char image[1024];
Paint paint(image, 0, 0);    // width should be the multiple of 8 
Epd epd;

/**
 * Variables Decleration 
 */
int i,j;

/**
 * Wiring Setup Function 
 */
void setup() {
  j=3;
  #ifdef DEBUG
  Serial.begin(9600);
  if (epd.Init(lut_full_update) != 0) {
      Serial.print("e-Paper init failed");
      return;
  } else Serial.print("e-Paper init passed");
  #endif
  
  //epd_refresh();
 
  #ifdef DEBUG
  if (epd.Init(lut_partial_update) != 0) {
      Serial.print("e-Paper init failed");
      return;
  } else Serial.print("e-Paper init passed");
  #endif

  #ifdef SPLASH
  epd.SetFrameMemory(splash_screen);
  epd.DisplayFrame();
  epd.SetFrameMemory(splash_screen);
  epd.DisplayFrame();
  
  delay(1000);
  
  epd_refresh();
  #endif
  
  epd.SetFrameMemory(main_screen);
  epd.DisplayFrame();
  epd.SetFrameMemory(main_screen);
  epd.DisplayFrame();

  /**
   * Setting Basic Parameters and 90Deg rotation so that the text is straight. 
   */
  paint.SetRotate(ROTATE_90);
  paint.SetWidth(25);
  paint.SetHeight(210);

}

void loop() {
  //For simplicity, the arguments are explicit numerical coordinates 
  if (j%2 == 0){
    paint.Clear(UNCOLORED);
    paint.DrawStringAt(0, 4, "  Hello MSP430!", &Font20, COLORED);
    epd.SetFrameMemory(paint.GetImage(), 20, 5+i, paint.GetWidth(), paint.GetHeight());
    epd.DisplayFrame();
  } else {
    paint.Clear(COLORED);
    paint.DrawStringAt(0, 4, "  MSP430 Rocks!", &Font20, UNCOLORED);
    epd.SetFrameMemory(paint.GetImage(), 20, 5+i, paint.GetWidth(), paint.GetHeight());
    epd.DisplayFrame();
  }
  delay(500);

  i+=10;
    
  if(i == 80) {
    i = 0;
    j++;
    if(j==5) j=3;
    epd_refresh();
    dispMainFrame();
  }
}

/**
 * Simple function call that refresh the display 
 * Use this function to avoid Gosting of Display.
 */
void epd_refresh(){
    /** 
   *  there are 2 memory areas embedded in the e-paper display
   *  and once the display s refreshed, the memory area will be auto-toggled,
   *  i.e. the next action of SetFrameMemory will set the other memory area
   *  therefore you have to clear the frame memory twice.
   */
  epd.ClearFrameMemory(0xFF);   // bit set = white, bit reset = black
  epd.DisplayFrame();
  epd.ClearFrameMemory(0xFF);   // bit set = white, bit reset = black
  epd.DisplayFrame();
  epd.ClearFrameMemory(0x00);   // bit set = white, bit reset = black
  epd.DisplayFrame();
  epd.ClearFrameMemory(0x00);   // bit set = white, bit reset = black
  epd.DisplayFrame();
  }
  
/**
 * Simple function to draw the main frame 
 * after each full refresh 
 */
void dispMainFrame(){
  epd.SetFrameMemory(main_screen);
  epd.DisplayFrame();
  epd.SetFrameMemory(main_screen);
  epd.DisplayFrame();
  }
