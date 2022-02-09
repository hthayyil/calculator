void outputDigit(byte selectedDigit, signed char digit, bool decimalpoint) {

  switch (digit) {
    case 0:
	  DrawDigit(selectedDigit,1,1,1,1,1,1,0,decimalpoint);
      break;
    case 1:
	  DrawDigit(selectedDigit,0,1,1,0,0,0,0,decimalpoint);
      break;
    case 2:
	  DrawDigit(selectedDigit,1,1,0,1,1,0,1,decimalpoint);
      break;
    case 3:
	  DrawDigit(selectedDigit,1,1,1,1,0,0,1,decimalpoint);
      break;
    case 4:
	  DrawDigit(selectedDigit,0,1,1,0,0,1,1,decimalpoint);
      break;
    case 5:
	  DrawDigit(selectedDigit,1,0,1,1,0,1,1,decimalpoint);
      break;
    case 6:
	  DrawDigit(selectedDigit,1,0,1,1,1,1,1,decimalpoint);
      break;
    case 7:
	  DrawDigit(selectedDigit,1,1,1,0,0,0,0,decimalpoint);
      break;
    case 8:
	  DrawDigit(selectedDigit,1,1,1,1,1,1,1,decimalpoint);
      break;
    case 9:
	  DrawDigit(selectedDigit,1,1,1,1,0,1,1,decimalpoint);
      break;
    case 10:
	  DrawDigit(selectedDigit,0,0,0,0,0,0,1,decimalpoint);
      break;
    case 99:
	  DrawDigit(selectedDigit,0,0,0,0,0,0,0,decimalpoint);
      break;
    default:
//    allSegmentOff();
	    DrawDigit(selectedDigit,0,0,0,0,0,0,0,0);	
      break;
  }
}


byte readKey() {
  //const char PrintableKeys[19] = "12+E0v-378X654/9^C";
  //char key =  0;
  byte keyR = 255;
  //int upCount = 0;
  //uint16_t piz;

TSPoint p; 
/*
do
 {                                                         //read all data while finger is pressing
 p = ts.getPoint();
  delay(10);
 } 
 while( p.z < MINPRESSURE || p.z > MAXPRESSURE );
 
  // we have some minimum pressure we consider 'valid'
  // pressure of 0 means no pressing!

do
 {
  uint16_t piz = ts.pressure();                                       //check finger is lifted
  if ( piz < MINPRESSURE || piz > MAXPRESSURE ) {upCount++;}  
   else {upCount = 0;} 
   delay(5);            // Try varying this delay
 } 
  while( upCount < 1 ); // and this count for different results.
 */ 
 if (p.z > MINPRESSURE || p.z < MAXPRESSURE) {p = ts.getPoint();delay(200);}
 //p = ts.getPoint();
 //piz = ts.pressure(); 
  // if sharing pins, you'll need to fix the directions of the touchscreen pins
  pinMode(XP, OUTPUT);
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);
  pinMode(YM, OUTPUT);



   
    // scale from 0->1023 to tft.width and tft.height
//    p.x = map(p.x, TS_MINX, TS_MAXX, tft.width(), 0);
//    p.y = map(p.y, TS_MINY, TS_MAXY, tft.height(),0);
    p.x = map(p.x, TS_LEFT, TS_RT, 0, tft.width());
  p.y = map(p.y, TS_TOP, TS_BOT, 0, tft.height());
//    Serial.print("X:");
//    Serial.println(p.x);
//    Serial.print("Y:");
//    Serial.println(p.y);   
  /*  
  tft.setTextColor(WHITE, BLACK);
  tft.setTextSize(1);
  tft.setCursor(72,0);
  tft.print("   ");
  tft.setCursor(72,0);
  tft.print(p.x); 

  tft.setCursor(96,0);
  tft.print("   ");
  tft.setCursor(96,0);
  tft.print(p.y); 

  tft.setCursor(120,0);
  tft.print("    ");
  tft.setCursor(120,0);
  tft.print(piz);
  */ 
    /*
    Serial.print("("); Serial.print(p.x);
    Serial.print(", "); Serial.print(p.y);
    Serial.println(") ");
    */
 
  if (p.y>62 && p.y<106)  //Detecting Buttons on Row 1
  {
    if (p.x>0  && p.x<57) 
    {keyR = 6;}     //x^y
    if (p.x>74 && p.x<112) 
    {keyR = 4;}      //LOG
    if (p.x>137 && p.x<184) 
    {keyR = 3;}      //LN
    if (p.x>200 && p.x<253)
    {keyR = 2;}      //e^x
    if (p.x>260 && p.x<303)
    {keyR = 0;}      //CLR
  }
  
  if (p.y>113 && p.y<160)  //Detecting Buttons on Row 2
  {
    if (p.x>0  && p.x<57) 
    {keyR = 46;}     //SQR (x)
    if (p.x>74 && p.x<112) 
    {keyR = 44;}     //ARC
    if (p.x>137 && p.x<184) 
    {keyR = 43;}     //SIN
    if (p.x>200 && p.x<253)
    {keyR = 42;}     //COS
    if (p.x>260 && p.x<303)
    {keyR = 40;}     //TAN
  }

  if (p.y>167 && p.y<209)  //Detecting Buttons on Row 3
  {
    if (p.x>0  && p.x<57) 
    {keyR = 14;}     // 1/x
    if (p.x>74 && p.x<112) 
    {keyR = 12;}     //x<-->y
    if (p.x>137 && p.x<184) 
    {keyR = 11;}     //R|v
    if (p.x>200 && p.x<253)
    {keyR = 10;}     //STO
    if (p.x>260 && p.x<303)
    {keyR = 8;}      //RCL
  }
  
  if (p.y>216 && p.y<258)  //Detecting Buttons on Row 4
  {
    if (p.x>0  && p.x<120) 
    {keyR = 62;}     //ENTER
    if (p.x>130 && p.x<187) 
    {keyR = 59;}     //CHS
    if (p.x>200 && p.x<247)
    {keyR = 58;}     //EEX
    if (p.x>240 && p.x<300)
    {keyR = 56;}     //CLx
  }

  if (p.y>265 && p.y<315)  //Detecting Buttons on Row 5
  {
    if (p.x>0  && p.x<80) 
    {keyR = 54;}     //-
    if (p.x>85 && p.x<153) 
    {keyR = 52;}     //7
    if (p.x>167 && p.x<230)
    {keyR = 51;}     //8
    if (p.x>242 && p.x<300)
    {keyR = 50;}     //9
  }

  if (p.y>320 && p.y<370)  //Detecting Buttons on Row 6
  {
    if (p.x>0  && p.x<80) 
    {keyR = 22;}     //+
    if (p.x>85 && p.x<153) 
    {keyR = 20;}     //4
    if (p.x>167 && p.x<230)
    {keyR = 19;}     //5
    if (p.x>242 && p.x<300)
    {keyR = 18;}     //6
  }

  if (p.y>374 && p.y<420)  //Detecting Buttons on Row 7
  {
    if (p.x>0  && p.x<80) 
    {keyR = 30;}     //*
    if (p.x>85 && p.x<153) 
    {keyR = 28;}     //1
    if (p.x>167 && p.x<230)
    {keyR = 27;}     //2
    if (p.x>242 && p.x<300)
    {keyR = 26;}     //3
  }

  if (p.y>430 && p.y<464)  //Detecting Buttons on Row 8
  {
    if (p.x>0  && p.x<80) 
    {keyR = 38;}     ///
    if (p.x>85 && p.x<153) 
    {keyR = 36;}     //0
    if (p.x>167 && p.x<230)
    {keyR = 35;}     //.
    if (p.x>242 && p.x<300)
    {keyR = 34;}     //pi
  }
  Serial.print("READING KEY");
  Serial.print(keyR);
  tft.setTextSize(1);
  //tft.setTextColor(WHITE, BLACK);
  tft.setTextColor(BLACK, BLACK);
  tft.setCursor(0,0);
  tft.print("   ");
  tft.setCursor(0,0);
  tft.print(keyR);
  
  return keyR;
}


void DrawDigit(byte Digit, bool a, bool b, bool c, bool d, bool e, bool f, bool g, bool DP)
{

      if ((Digit < -1)||(Digit > 14)) return;
      
      int DigitOffset = (Digit * 15) - 15;
      //tft.fillRect(47+DigitOffset, 28, 15, 26, 0x2145);
      // Color 0x2145 Background black tone
      /*  
      if (a)  {tft.drawFastHLine(49+DigitOffset, 28, 11, RED);tft.drawFastHLine(49+DigitOffset, 29, 11, RED);}
         else {tft.drawFastHLine(49+DigitOffset, 28, 11, DARKRED);tft.drawFastHLine(49+DigitOffset, 29, 11, DARKRED);}
      if (b)  {tft.drawFastVLine(60+DigitOffset, 30, 10, RED); tft.drawFastVLine(61+DigitOffset, 30, 10, RED);}
         else {tft.drawFastVLine(60+DigitOffset, 30, 10, DARKRED); tft.drawFastVLine(61+DigitOffset, 30, 10, DARKRED);}
      if (c)  {tft.drawFastVLine(60+DigitOffset, 42, 10, RED); tft.drawFastVLine(61+DigitOffset, 42, 10, RED);}
         else {tft.drawFastVLine(60+DigitOffset, 42, 10, DARKRED); tft.drawFastVLine(61+DigitOffset, 42, 10, DARKRED);}
      if (d)  {tft.drawFastHLine(49+DigitOffset, 52, 11, RED);tft.drawFastHLine(49+DigitOffset, 53, 11, RED);}
         else {tft.drawFastHLine(49+DigitOffset, 52, 11, DARKRED);tft.drawFastHLine(49+DigitOffset, 53, 11, DARKRED);}
      if (e)  {tft.drawFastVLine(47+DigitOffset, 42, 10, RED); tft.drawFastVLine(48+DigitOffset, 42, 10, RED);}
         else {tft.drawFastVLine(47+DigitOffset, 42, 10, DARKRED); tft.drawFastVLine(48+DigitOffset, 42, 10, DARKRED);}
      if (f)  {tft.drawFastVLine(47+DigitOffset, 30, 10, RED); tft.drawFastVLine(48+DigitOffset, 30, 10, RED);}
         else {tft.drawFastVLine(47+DigitOffset, 30, 10, DARKRED); tft.drawFastVLine(48+DigitOffset, 30, 10, DARKRED);} 
      if (g)  {tft.drawFastHLine(49+DigitOffset, 40, 11, RED);tft.drawFastHLine(49+DigitOffset, 41, 11, RED);}
         else {tft.drawFastHLine(49+DigitOffset, 40, 11, DARKRED);tft.drawFastHLine(49+DigitOffset, 41, 11, DARKRED);}
      if (DP) {tft.drawFastHLine(64+DigitOffset, 52, 2, RED); tft.drawFastHLine(64+DigitOffset, 53, 2, RED);}
         else {tft.drawFastHLine(64+DigitOffset, 52, 2, DARKRED); tft.drawFastHLine(64+DigitOffset, 53, 2, DARKRED);}
      */
      if (a)  {tft.setAddrWindow(26+DigitOffset, 9,  35+DigitOffset,  9);tft.pushColors(red_color_buffer, 10, true);}
         else {tft.setAddrWindow(26+DigitOffset, 9,  35+DigitOffset,  9);tft.pushColors(darkred_color_buffer, 10, true);}
      if (b)  {tft.setAddrWindow(35+DigitOffset, 9,  35+DigitOffset, 17);tft.pushColors(red_color_buffer, 9, true);}
         else {tft.setAddrWindow(35+DigitOffset, 10 , 35+DigitOffset, 17);tft.pushColors(darkred_color_buffer, 8, true);}
      if (c)  {tft.setAddrWindow(35+DigitOffset, 17, 35+DigitOffset, 25);tft.pushColors(red_color_buffer, 9, true);}
         else {tft.setAddrWindow(35+DigitOffset, 17, 35+DigitOffset, 25);tft.pushColors(darkred_color_buffer, 9, true);}
      if (d)  {tft.setAddrWindow(26+DigitOffset, 25, 35+DigitOffset, 25);tft.pushColors(red_color_buffer, 10, true);}
         else {tft.setAddrWindow(26+DigitOffset, 25, 34+DigitOffset, 25);tft.pushColors(darkred_color_buffer, 9, true);}   
      if (e)  {tft.setAddrWindow(26+DigitOffset, 17, 26+DigitOffset, 25);tft.pushColors(red_color_buffer, 9, true);}
         else {tft.setAddrWindow(26+DigitOffset, 17, 26+DigitOffset, 24);tft.pushColors(darkred_color_buffer, 8, true);}
      if (f)  {tft.setAddrWindow(26+DigitOffset, 9,  26+DigitOffset, 17);tft.pushColors(red_color_buffer, 9, true);}
         else {tft.setAddrWindow(26+DigitOffset, 10,  26+DigitOffset, 17);tft.pushColors(darkred_color_buffer, 8, true);}          
      if (g)  {tft.setAddrWindow(26+DigitOffset, 17, 35+DigitOffset, 17);tft.pushColors(red_color_buffer, 10, true);}
         else {tft.setAddrWindow(27+DigitOffset, 17, 34+DigitOffset, 17);tft.pushColors(darkred_color_buffer, 8, true);}     
      if (DP) {tft.setAddrWindow(31+DigitOffset, 22, 32+DigitOffset, 23);tft.pushColors(red_color_buffer, 4, true);}
         else {tft.setAddrWindow(31+DigitOffset, 22, 32+DigitOffset, 23);tft.pushColors(darkred_color_buffer, 4, true);}
   
}



void drawButtons (void)
{

//tft.fillRect (0,34,239,286,0x31A7);
tft.fillRect (0,60,320,420,0x31A7);
/*
tft.drawRect (0,0,238,33,0x31A7);
tft.drawRect (1,1,236,31,0x31A7);
tft.drawRect (2,2,234,29,0x31A7);
*/
//tft.drawRect (0,34,239,286,0xDF3D);
tft.drawRect (0,60,320,420,0xDF3D);
//tft.drawRect (1,35,237,284,0xDF3D);
//tft.drawRect (1,58,318,420,0xDF3D);

  
//int16_t  BUTTON_X = 12;
//int16_t  BUTTON_Y = 44;
//uint16_t BUTTON_W = 34;
//uint16_t BUTTON_H = 25;
//uint16_t BUTTON_SPACING_X = 12;
//uint16_t BUTTON_SPACING_Y = 9;
//uint8_t  BUTTON_TEXTSIZE = 1;

 int16_t  BUTTON_X = 12;
int16_t  BUTTON_Y = 70;
uint16_t BUTTON_W =50;
uint16_t BUTTON_H = 40;
uint16_t BUTTON_SPACING_X = 12;
uint16_t BUTTON_SPACING_Y = 9;
uint8_t  BUTTON_TEXTSIZE = 1;

  // create upper function buttons 3x5
char buttonlabels[18][6] = {"x ", "LOG", "LN", "e ", "CLR", "", "ARC", "SIN", "COS", "TAN", "1/x", "x<>y", "R", "STO", "RCL","","","" };
uint16_t buttoncolors[18] = {0x2104, 0x2104, 0x2104, 0x2104, 0x4455, 
                             0x2104, 0x2104, 0x2104, 0x2104, 0x2104, 
                             0x2104, 0x2104, 0x2104, 0x2104, 0x2104,
                             0x0000, 0x0000, 0x0000};
   buttonlabels[5][0] = 250; //Square Root symbol
   buttonlabels[5][1] = 'x';
   buttonlabels[11][1] = 27; //Left sign
   buttonlabels[11][2] = 26; //Right sign
   buttonlabels[12][1] = 25; //Down sign
   
   
   for (uint8_t row=0; row<3; row++) {
    for (uint8_t col=0; col<5; col++) {
      //buttons[col + row*5].initButtonUL(&tft, BUTTON_X+col*(BUTTON_W+BUTTON_SPACING_X), 
      //           BUTTON_Y+row*(BUTTON_H+BUTTON_SPACING_Y),    // x, y, w, h, outline, fill, text
      //            BUTTON_W, BUTTON_H, WHITE, buttoncolors[col+row*5], WHITE,
      //            buttonlabels[col + row*5], BUTTON_TEXTSIZE); 
      //buttons[col + row*5].drawButton();
      tft.fillRoundRect(BUTTON_X+col*(BUTTON_W+BUTTON_SPACING_X), BUTTON_Y+row*(BUTTON_H+BUTTON_SPACING_Y), BUTTON_W, BUTTON_H, 4, buttoncolors[col+row*5]);
      tft.drawRoundRect(BUTTON_X+col*(BUTTON_W+BUTTON_SPACING_X), BUTTON_Y+row*(BUTTON_H+BUTTON_SPACING_Y), BUTTON_W, BUTTON_H, 4, WHITE);
      tft.setCursor(BUTTON_X+col*(BUTTON_W+BUTTON_SPACING_X) + (BUTTON_W/2) - (strlen(buttonlabels[col + row*5]) * 3 * BUTTON_TEXTSIZE), BUTTON_Y+row*(BUTTON_H+BUTTON_SPACING_Y) + (BUTTON_H/2) - (4 * BUTTON_TEXTSIZE)+2);
      tft.setTextColor(WHITE);
      tft.setTextSize(BUTTON_TEXTSIZE, BUTTON_TEXTSIZE);
      tft.print(buttonlabels[col + row*5]);
      
      tft.setCursor(37,80); //Complete x^y button
      tft.print("y");
      tft.setCursor(224,80); //Complete e^x button
      tft.print("x");
      tft.drawLine(33,138,40,137,WHITE); //Complete Square Root button

    }
  }

  // create "ENTER" button
BUTTON_Y = 217;
BUTTON_W = 109;
uint8_t row=0;
uint8_t col=0;
strcpy(buttonlabels[row], "ENTER");
buttonlabels[row][5] = 24;//Up arrow
strcpy(buttonlabels[1], "");
buttoncolors[row] = 0x4455; 

      tft.fillRoundRect(BUTTON_X+col*(BUTTON_W+BUTTON_SPACING_X), BUTTON_Y+row*(BUTTON_H+BUTTON_SPACING_Y), BUTTON_W, BUTTON_H, 4, buttoncolors[col+row*5]);
      tft.drawRoundRect(BUTTON_X+col*(BUTTON_W+BUTTON_SPACING_X), BUTTON_Y+row*(BUTTON_H+BUTTON_SPACING_Y), BUTTON_W, BUTTON_H, 4, WHITE);
      tft.setCursor(BUTTON_X+col*(BUTTON_W+BUTTON_SPACING_X) + (BUTTON_W/2) - (strlen(buttonlabels[col + row*5]) * 3 * BUTTON_TEXTSIZE), BUTTON_Y+row*(BUTTON_H+BUTTON_SPACING_Y) + (BUTTON_H/2) - (4 * BUTTON_TEXTSIZE)+2);
      tft.setTextColor(WHITE);
      tft.setTextSize(BUTTON_TEXTSIZE, BUTTON_TEXTSIZE);
      tft.print(buttonlabels[col + row*5]);

  // create "CHS", "EEX", "CLx" buttons
BUTTON_X = 135;
BUTTON_W = 50;

strcpy(buttonlabels[0], "CHS");
strcpy(buttonlabels[1], "EEX");
strcpy(buttonlabels[2], "CLx");
buttoncolors[0] = 0x4455; 
buttoncolors[1] = 0x4455; 
buttoncolors[2] = 0x4455; 
   for (uint8_t row=0; row<1; row++) {
    for (uint8_t col=0; col<3; col++) {

      tft.fillRoundRect(BUTTON_X+col*(BUTTON_W+BUTTON_SPACING_X), BUTTON_Y+row*(BUTTON_H+BUTTON_SPACING_Y), BUTTON_W, BUTTON_H, 4, buttoncolors[col+row*5]);
      tft.drawRoundRect(BUTTON_X+col*(BUTTON_W+BUTTON_SPACING_X), BUTTON_Y+row*(BUTTON_H+BUTTON_SPACING_Y), BUTTON_W, BUTTON_H, 4, WHITE);
      tft.setCursor(BUTTON_X+col*(BUTTON_W+BUTTON_SPACING_X) + (BUTTON_W/2) - (strlen(buttonlabels[col + row*5]) * 3 * BUTTON_TEXTSIZE), BUTTON_Y+row*(BUTTON_H+BUTTON_SPACING_Y) + (BUTTON_H/2) - (4 * BUTTON_TEXTSIZE)+2);
      tft.setTextColor(WHITE);
      tft.setTextSize(BUTTON_TEXTSIZE, BUTTON_TEXTSIZE);
      tft.print(buttonlabels[col + row*5]);

    }
  }

  // create "-", "+", "x", "/" buttons
BUTTON_X = 12;
BUTTON_Y = 270;
BUTTON_H = 44;
BUTTON_W = 66;
BUTTON_TEXTSIZE = 2;

strcpy(buttonlabels[0], "-");
strcpy(buttonlabels[5], "+");
strcpy(buttonlabels[10], "x");
//strcpy(buttonlabels[15], "/");
buttonlabels[15][0] = 245; //Divide symbol
buttoncolors[0] = 0x4455; 
buttoncolors[5] = buttoncolors[0]; 
buttoncolors[10] = buttoncolors[0]; 
buttoncolors[15] = buttoncolors[0]; 

   for (uint8_t row=0; row<4; row++) {
    for (uint8_t col=0; col<1; col++) {

      tft.fillRoundRect(BUTTON_X+col*(BUTTON_W+BUTTON_SPACING_X), BUTTON_Y+row*(BUTTON_H+BUTTON_SPACING_Y), BUTTON_W, BUTTON_H, 4, buttoncolors[col+row*5]);
      tft.drawRoundRect(BUTTON_X+col*(BUTTON_W+BUTTON_SPACING_X), BUTTON_Y+row*(BUTTON_H+BUTTON_SPACING_Y), BUTTON_W, BUTTON_H, 4, WHITE);
      tft.setCursor(BUTTON_X+col*(BUTTON_W+BUTTON_SPACING_X) + (BUTTON_W/2) - (strlen(buttonlabels[col + row*5]) * 3 * BUTTON_TEXTSIZE)+2, BUTTON_Y+row*(BUTTON_H+BUTTON_SPACING_Y) + (BUTTON_H/2) - (4 * BUTTON_TEXTSIZE)+2);
      tft.setTextColor(WHITE);
      tft.setTextSize(BUTTON_TEXTSIZE, BUTTON_TEXTSIZE);
      tft.print(buttonlabels[col + row*5]);

    }
  } 

  // create numeric and ".", "pi" buttons
BUTTON_X = 89;
BUTTON_W = 60;
BUTTON_SPACING_X = 18;


strcpy(buttonlabels[0], "7");
strcpy(buttonlabels[1], "8");
strcpy(buttonlabels[2], "9");
strcpy(buttonlabels[5], "4");
strcpy(buttonlabels[6], "5");
strcpy(buttonlabels[7], "6");
strcpy(buttonlabels[10], "1");
strcpy(buttonlabels[11], "2");
strcpy(buttonlabels[12], "3");
strcpy(buttonlabels[15], "0");
strcpy(buttonlabels[16], ".");
//strcpy(buttonlabels[17], "pi");
buttonlabels[17][0] = 226; // pi symbol

buttoncolors[0] = 0xE6F7; 
buttoncolors[1] = buttoncolors[0]; 
buttoncolors[2] = buttoncolors[0]; 
buttoncolors[5] = buttoncolors[0];  
buttoncolors[6] = buttoncolors[0];  
buttoncolors[7] = buttoncolors[0]; 
buttoncolors[10] = buttoncolors[0];  
buttoncolors[11] = buttoncolors[0];  
buttoncolors[12] = buttoncolors[0]; 
buttoncolors[15] = buttoncolors[0];  
buttoncolors[16] = buttoncolors[0];  
buttoncolors[17] = buttoncolors[0];  

   for (uint8_t row=0; row<4; row++) {
    for (uint8_t col=0; col<3; col++) {


      tft.fillRoundRect(BUTTON_X+col*(BUTTON_W+BUTTON_SPACING_X), BUTTON_Y+row*(BUTTON_H+BUTTON_SPACING_Y), BUTTON_W, BUTTON_H, 4, buttoncolors[col+row*5]);
      tft.drawRoundRect(BUTTON_X+col*(BUTTON_W+BUTTON_SPACING_X), BUTTON_Y+row*(BUTTON_H+BUTTON_SPACING_Y), BUTTON_W, BUTTON_H, 4, WHITE);
      tft.setCursor(BUTTON_X+col*(BUTTON_W+BUTTON_SPACING_X) + (BUTTON_W/2) - (strlen(buttonlabels[col + row*5]) * 3 * BUTTON_TEXTSIZE)+2, BUTTON_Y+row*(BUTTON_H+BUTTON_SPACING_Y) + (BUTTON_H/2) - (4 * BUTTON_TEXTSIZE)+2);
      tft.setTextColor(BLACK);
      tft.setTextSize(BUTTON_TEXTSIZE, BUTTON_TEXTSIZE);
      tft.print(buttonlabels[col + row*5]);

    }
  } 
// tft.setCursor (1,310);
// tft.setTextColor(WHITE);
// tft.setTextSize(1);
// tft.print("   H E W L E T T ");
// tft.print((char)248);
// tft.print(" P A C K A R D   35");
// 
}
