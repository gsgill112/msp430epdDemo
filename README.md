# msp430_2.9EPD_Demo

This is a DEMO of using a 2.9" Epaper Display with an MSP430 Launchpad Platform (ti.com/launchpad)

I have used a 2.9" E Ink Display with the MSP430FR2433 Launchpad; But it can be used for any MSP430 Device (ROM Constraints though) 
The Display updates partially every 500ms and resets every 8 refreshes to avoid Gosting Effect and to keep the display Life Long . Very Long :D 
I have Used the Epd library by Waveshare and modified it to work with the energia platform. 


  * MSP430 Connections :---------------------------
  * -----------------------------------------------
  * EPD-------------MSP430FR2433---------WIRING PIN
  * -----------------------------------------------
  * BUSY----------------P1.2----------------10
  * RST-----------------P1.3----------------9
  * DC------------------P2.7----------------8
  * CS------------------P3.1----------------13
  * CLK-----------------P2.4----------------7
  * DIN/MISO------------P2.6----------------15
  * -----------------------------------------------

  Do visit me on 
  gsgill112.github.io
  and suscribe to my YouTube channel (https://www.youtube.com/channel/UC98erU8wYeEA-VqmTA9etNw?view_as=subscriber) it keeps the creativity going. 


  Copyright (C) TechNERVERS     Nov 12 2018

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documnetation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to  whom the Software is
 furished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS OR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
  
   