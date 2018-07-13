/***************************************************
  pantalla 480x320
 ****************************************************/
#include <SPI.h>          // f.k. for Arduino-1.5.2
#include "Adafruit_GFX.h"// Hardware-specific library
#include <MCUFRIEND_kbv.h>
MCUFRIEND_kbv tft;
// Assign human-readable names to some common 16-bit color values:
#define WHITE   0x0000
#define BLACK   0xFFFF
#define CYAN    0xF800
#define DARKCYAN    0x03EF
#define MAGENTA 0x07E0
#define BLUE    0xFFE0
#define RED     0x07FF
#define GREEN   0xF81F
#define YELLOW  0x001F
#define GRAY    0x8410
#define DARKGRAY    0x8888
/*
void drawPixel(uint16_t x, uint16_t y, uint16_t color);
void drawLine(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t color);
void drawFastVLine(uint16_t x0, uint16_t y0, uint16_t length, uint16_t color);
void drawFastHLine(uint8_t x0, uint8_t y0, uint8_t length, uint16_t color);

void drawRect(uint16_t x0, uint16_t y0, uint16_t w, uint16_t h, uint16_t color);
void fillRect(uint16_t x0, uint16_t y0, uint16_t w, uint16_t h, uint16_t color);
void drawCircle(uint16_t x0, uint16_t y0, uint16_t r, uint16_t color);
void fillCircle(uint16_t x0, uint16_t y0, uint16_t r, uint16_t color);

void drawRoundRect(uint16_t x0, uint16_t y0, uint16_t w, uint16_t h, uint16_t radius, uint16_t color);
void fillRoundRect(uint16_t x0, uint16_t y0, uint16_t w, uint16_t h, uint16_t radius, uint16_t color);void drawRoundRect(uint16_t x0, uint16_t y0, uint16_t w, uint16_t h, uint16_t radius, uint16_t color);
void fillRoundRect(uint16_t x0, uint16_t y0, uint16_t w, uint16_t h, uint16_t radius, uint16_t color);

void drawTriangle(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color);
void fillTriangle(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color);
void drawChar(uint16_t x, uint16_t y, char c, uint16_t color, uint16_t bg, uint8_t size);

void setCursor(uint16_t x0, uint16_t y0);
void setTextColor(uint16_t color);
void setTextColor(uint16_t color, uint16_t backgroundcolor);
void setTextSize(uint8_t size);
void setTextWrap(boolean w);

void drawBitmap(int16_t x, int16_t y, uint8_t *bitmap, int16_t w, int16_t h, uint16_t color);
void fillScreen(uint16_t color);void fillScreen(uint16_t color);
void setRotation(uint8_t rotation);

int16_t  x1, y1;
uint16_t w, h;
tft.getTextBounds(string, x, y, &x1, &y1, &w, &h);


#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_TFTLCD.h> // Hardware-specific library
#include <Fonts/FreeSans12pt7b.h>
#include <Fonts/FreeSerif9pt7b.h>
tft.setFont(&FreeSans12pt7b);
tft.setFont();


*/
/***************************************************
 Teclas capacitivas
 ****************************************************/
// include the atmel I2C libs
#include "mpr121.h"
#include "i2c.h"

/***************** SCREEN ***********************/





/***************** MPR121 ***********************/
// Match key inputs with electrode numbers
#define ONE 8
#define TWO 5
#define THREE 2
#define FOUR 7
#define FIVE 4
#define SIX 1
#define SEVEN 6
#define EIGHT 3
#define NINE 0
//extras (not connected to button)
#define ELE9 9
#define ELE10 10
#define ELE11 11
//interupt pin
//int irqPin = 2;  // D2
int irqPin = 19;
char Bpulsado='0'; 
boolean pulso=false;
int cont=0;
String eo;
/* cableado
 *  3.3v  = 3.3v
 *  IRQ   = D2
 *  SLC   = A5
 *  SDA   = A4
 *  ADD   = --
 *  GND   = GND
 */
/***************************************************************************/

////////////////////////////////
boolean      depuradora;
unsigned int animacionDepuradora;
boolean      bombaPH;
unsigned int animacionPH;
unsigned int colorPH;
boolean      bombaCL;
unsigned int animacionCL;
unsigned int colorCL;

void setup() {
  /////////////valores en prueba
  depuradora =  true; 
  animacionDepuradora = 1;
  bombaPH =     false;//true;
  animacionPH = 1;
  colorPH =     GREEN;
  
  bombaCL =     true;
  animacionCL = 1;
  colorCL =     GREEN;
  ////////////////// SERIAL
  Serial.begin(9600);
  uint32_t when = millis();
  //    while (!Serial) ;   //hangs a Leonardo until you connect a Serial
  if (!Serial) delay(5000);           //allow some time for Leonardo

  ////////////////// pantalla
  uint16_t ID = tft.readID(); //
  Serial.print("ID = 0x"); Serial.println(ID, HEX);
  tft.begin(ID);
  tft.setRotation(3);
  tft.fillScreen(BLACK);
  Serial.println("pantalla preparada");

  ////////////////// TECLADO
  //make sure the interrupt pin is an input and pulled high
  pinMode(irqPin, INPUT);
  digitalWrite(irqPin, HIGH);
  i2cInit();
  mpr121QuickConfig();
  // Create and interrupt to trigger when a button
  // is hit, the IRQ pin goes low, and the function getNumber is run. 
  attachInterrupt(4,getNumber,FALLING);
  // prints 'Ready...' when you can start hitting numbers
  Serial.println("Teclado preparado! ...");
}

void loop(void) {
  int pantallaAjustes;
  pantallaAjustes=pantallaAjustes01();
  if (pantallaAjustes == 1){
    ; //pantallaAjustes=pantallaAjustes02();
    }
  pantallaPrincipal();
  /*while (Bpulsado != '6') {
    //parado hasta pulsar tecla     
    //Serial.print(".");
    //delay (1);
    animacion();
  }*/
  while (pulso == false){
  //Serial.print("tecla ");
    animacion();
  }
  // se ha pulsado una tecla ----------------------
  if (Bpulsado=='2'){ 
     depuradora=false; 
     animacionDepuradora=1;
     Serial.println("--2");
  }
  if (Bpulsado=='3'){ 
     bombaPH=false;
     animacionPH=1;
     Serial.println("--3");
  }
  if (Bpulsado=='7'){ 
     bombaCL=false;
     animacionCL=1;
     Serial.println("--7");
  }    
  if (Bpulsado=='9'){ 
     depuradora=true; 
     animacionDepuradora=1;
     bombaPH=true;
     animacionPH=1;
     bombaCL=true;
     animacionCL=1;
     Serial.println("--9");
  }    
  if (Bpulsado=='6'){
    // he pulsado tecla menu voy apantalla ajustes
    //texto (3, WHITE, "MENU", 100, 100);
    //Serial.println("menu");
    pantallaAjustes=pantallaAjustes01();
  } 
  pulso=false;
  Bpulsado=0;
}

/*void loop(void) {
  int pantallaAjustes;
  pantallaAjustes=pantallaAjustes01();
  if (pantallaAjustes == 1){
    ; //pantallaAjustes=pantallaAjustes02();
    }
    pantallaPrincipal();
    delay(5000);
    while (Bpulsado != '6') {
      //parado hasta pulsar tecla menu     
      Serial.print(".");
      delay (1);
      animacion();
  }
}*/

int pantallaAjustes01() {
  tft.fillScreen(BLACK);
  tft.fillRect( 0, 0, 480, 35, BLUE);
  texto (3, WHITE, "AJUSTES                1/3", 5, 5);
  tft.drawFastHLine(0, 35, 480, WHITE);
  tft.fillRect( 0, 35, 480, 35, CYAN);
  texto (3, BLACK, "GENERALES", 5, 40);
  tft.drawFastHLine(0, 70, 480, WHITE);
  //FECHA
  texto (2, WHITE, "dia", 150, 80);
  texto (2, WHITE, "mes", 230, 80);
  texto (2, WHITE, "ano", 310, 80);
  texto (3, WHITE, "FECHA:", 30, 110);
  //HORA
  texto (3, WHITE, "HORA:", 30, 160);
  //VOLUMEN
  tft.drawFastHLine(0, 200, 480, WHITE);
  texto (2, WHITE, "VOLUMEN de la piscina:", 40, 230);
  texto (3, WHITE, "m3", 130, 260);

  
  unsigned int posicionCursor=0;
  unsigned int valor[6]         ={ 25,   8, 2017,  11,  38,  21};
  unsigned int valorNuevo[6]    ={ 25,   8, 2017,  11,  38,  21};
  unsigned int posx[6]          ={150, 230,  310, 150, 200,  60};
  unsigned int posy[6]          ={110, 110,  110, 160, 160, 260};
  unsigned int nCaracteres[6]   ={  2,   2,    4,   2,   2,   2};
  unsigned int maxCaracteres    =5; // 4+1
  unsigned int limiteInferior[6]={  1,   1, 2017,   0,   0,   1};
  unsigned int limiteSuperior[6]={ 31,  12, 3000,  24,  59,  99};
  /////////////////////////////////////////////////////////////////
  char msg[maxCaracteres];
  int i;

  //siguiente
  char siguiente[5]="OK.";
  unsigned int posXsiguiente=380;
  unsigned int posYsiguiente=260;
  boolean boolSiguiente=false;
  texto(4, WHITE, siguiente, posXsiguiente, posYsiguiente);
  
  //FECHA
  Serial.print("sizeof = ");
  Serial.println(sizeof(valor)/sizeof(int));
  for (i=0; i<(sizeof(valor)/sizeof(int)); i++) {
    sprintf (msg, "%i", valor[i]);
    texto (3, WHITE, msg, posx[i], posy[i]);
  } 
  texto (3, WHITE, ":", 180, 160); 
  
  while (true) {
    pulso = false;
    while (pulso == false){
      for (i = 0; i < maxCaracteres; i++) {
        msg[i]=(char)0;
        //Serial.print(msg[i]);
      }
      //Serial.println(i);
      for (i = 0; i < nCaracteres[posicionCursor]; i++) {
        msg[i]='_';
        //Serial.print(msg[i]);
      }
      if (boolSiguiente){
        //tft.fillRect( 210, 190, 110, 45, DARKGRAY);
        tft.fillRoundRect( posXsiguiente-10, posYsiguiente-10, 108, 45, 5, GRAY);
        texto(4, WHITE, siguiente, posXsiguiente, posYsiguiente);
        delay(200);
        texto(4, BLACK, siguiente, posXsiguiente, posYsiguiente);
        delay(200);
      } else {
        texto(3, WHITE, msg, posx[posicionCursor], posy[posicionCursor]+3);
        delay(200);
        texto(3, BLACK, msg, posx[posicionCursor], posy[posicionCursor]+3);
        delay(200);
      }
      
      
     }
     /////////DERECHA
     if (Bpulsado=='7') {
      if (posicionCursor < 5){
        posicionCursor++;
        boolSiguiente=false;
      } else {
         boolSiguiente=true;
         //posicionCursor=sizeof(valor)/sizeof(int);
      }
     }
     
     /////////IZQUIERDA
     if (Bpulsado=='3'){
      if (boolSiguiente){ 
        boolSiguiente=false;
        tft.fillRoundRect( posXsiguiente-10, posYsiguiente-10, 108, 45, 5, GRAY);
        texto(4, WHITE, siguiente, posXsiguiente, posYsiguiente);
      } else{
        posicionCursor--;
      }
     }
     
     /////////ARRIBA
     if (Bpulsado=='2'){
          //borro
          sprintf (msg, "%i", valor[posicionCursor]);
          texto(3, BLACK, msg, posx[posicionCursor], posy[posicionCursor]);
          
          //actualizo
          if (valorNuevo[posicionCursor] < limiteSuperior[posicionCursor]) {
            valor[posicionCursor]++; 
            valorNuevo[posicionCursor]++;
          } else {
            valor[posicionCursor]=limiteInferior[posicionCursor]; 
            valorNuevo[posicionCursor]=limiteInferior[posicionCursor]; ;
          }
                    
          //escribo
          sprintf (msg, "%i", valorNuevo[posicionCursor]);
          texto(3, WHITE, msg, posx[posicionCursor], posy[posicionCursor]);
     }

     /////////ABAJO
     if (Bpulsado=='8'){
          //borro
          sprintf (msg, "%i", valor[posicionCursor]);
          texto(3, BLACK, msg, posx[posicionCursor], posy[posicionCursor]);
          
          //actualizo
          if (valorNuevo[posicionCursor] > limiteInferior[posicionCursor]) {
            valor[posicionCursor]--; 
            valorNuevo[posicionCursor]--;
          } else {
            valor[posicionCursor]=limiteSuperior[posicionCursor]; 
            valorNuevo[posicionCursor]=limiteSuperior[posicionCursor]; ;
          }
                    
          //escribo
          sprintf (msg, "%i", valorNuevo[posicionCursor]);
          texto(3, WHITE, msg, posx[posicionCursor], posy[posicionCursor]);
     }
     /////////////////OK
     if (Bpulsado=='5' and boolSiguiente==true){ 
        tft.fillScreen(BLACK);
        return(1);
     }

     /////////////////ESC
     if (Bpulsado=='9'){ 
        tft.fillScreen(BLACK);
        return(0);
     }
     Bpulsado=='0';
  }
}

void animacion(){
  if (depuradora==true){
    if (animacionDepuradora==1){
      tft.fillRect( 240, 0, 240, 50, GREEN);
      texto (4, BLACK, "BOMBA", 260, 10);
      animacionDepuradora=2;
    }
    else if (animacionDepuradora==2){
      texto (4, GREEN, ">>", 400, 10);
      animacionDepuradora=3;
    }
    else if (animacionDepuradora==3){
      //texto (3, GREEN, "BOMBA", 280, 10);
      texto (4, BLACK, ">", 400, 10);
      animacionDepuradora=4;
    }
    else if (animacionDepuradora==4){
      texto (4, GREEN, ">", 400, 10);
      texto (4, BLACK, ">>", 400, 10);
      animacionDepuradora=2;
    }
    
    if (bombaPH==true){
    //Serial.println("--bombaPH");
      if (animacionPH==true){
        //Serial.println("---animacionPH");
        flechaArriba(180, 120, RED);
        animacionPH=2;
      }
      else if (animacionPH==2){
        flechaArriba(180, 120, BLACK);
        animacionPH=1;
      }
    } else {
        flechaArriba(180, 120, BLACK);
    }

    if (bombaCL==true){
    //Serial.println("--bombaPH");
      if (animacionCL==true){
        //Serial.println("---animacionPH");
        flechaArriba(400, 280, RED);
        animacionCL=2;
      }
      else if (animacionCL==2){
        flechaArriba(400, 280, BLACK);
        animacionCL=1;
      }
    }else {
         flechaArriba(400, 280, BLACK);
    }
  }
  else {   ///en caso de que no este funcionando la depuradora todo de apaga
      //Serial.println("borro");
      tft.fillRect( 240, 0, 240, 50, BLACK);
      flechaArriba(180, 120, BLACK);
      flechaArriba(400, 280, BLACK);
      animacionPH=1;
      bombaCL=false;
      animacionCL=1;
      depuradora=false; 
      animacionDepuradora=1;
  }
  //hora
  //tft.fillScreen(BLACK);
  texto (2, WHITE, "12:23 - 25/8/2017", 20, 20);
  delay(300);
}
void pantallaPrincipal() {
  //dibujo pantalla principal
  tft.drawFastHLine(0, 50, 480, WHITE);
  //PH
  tft.fillCircle(100, 140, 70, colorPH);
  texto (9, BLACK, "88", 55, 110);
  texto (4, BLACK, ".", 90, 150);
  tft.fillCircle(40, 90, 30, BLUE);
  texto (3, WHITE, "PH", 25, 80);
  //TEMP
  tft.fillCircle(370, 140, 70, colorPH);
  texto (9, BLACK, "23", 320, 110);
  tft.fillCircle(430, 90, 30, BLUE);
  texto (2, WHITE, "o", 412, 76);
  texto (3, WHITE, "C", 427, 80);

  //tft.drawLine(240, 0, 240, 210, WHITE);
  tft.drawFastVLine(240, 0, 210, WHITE);
  
  //CLORO 
  tft.fillRoundRect(180, 190, 120, 20, 5, WHITE);
  tft.fillRect( 180, 195, 120, 30, WHITE);
  texto (3, BLACK, "CLORO", 200, 200);
  tft.drawFastHLine(0, 225, 480, WHITE);
  
  texto (2, WHITE, "BAJO", 30, 230);
  tft.fillRect( 30, 250, 100, 20, RED);
  texto (2, WHITE, "OK", 160, 230);
  tft.fillRect( 130, 250, 100, 20, GREEN);
  texto (2, WHITE, "ALTO", 280, 230);
  tft.fillRect( 230, 250, 100, 20, RED);
  
  triangulo(150, 280, BLACK, WHITE);
  texto (2, WHITE, "475 mV", 140, 290);

  return;
}

void texto(int tam, int color, char mensaje[], int x, int y) {
  //char errorMessage = {"choose another option"};
  tft.setCursor(x, y);
  tft.setTextColor(color);
  tft.setTextSize(tam);
  tft.println(mensaje);
}

void flechaArriba(unsigned int x, unsigned int y, int color){
  tft.fillRect( x+15, y-25, 20, 25, color);
  tft.fillTriangle(x, y-25, x+50, y-25, x+25, y-45, color); //tft.color565(0, i*10, i*10)); 
}
void triangulo(unsigned int x, unsigned int y, int color1, int color2){
  tft.fillTriangle(x, y, x+30, y, x+15, y-15, color2); //tft.color565(0, i*10, i*10)); 
  tft.drawTriangle(x, y, x+30, y, x+15, y-15, color1);
}

/**************** interrupciones del touch ****************/
void getNumber()
{
  int touchNumber = 0;
  uint16_t touchstatus;
  char digits;
  
  touchstatus = getTouchStatus();
  
  for (int j=0; j<12; j++)  // Check how many electrodes were pressed
  {
    if ((touchstatus & (1<<j)))
      touchNumber++;
  }
  
  if (touchNumber == 1)
  {
    if (touchstatus & (1<<SEVEN))
    {
      digits = '7';
    }
    else if (touchstatus & (1<<FOUR))
    {
      digits = '4';
    }
    else if (touchstatus & (1<<ONE))
    {
      digits = '1';
    }
    else if (touchstatus & (1<<EIGHT))
    {
      digits = '8';
    }
    else if (touchstatus & (1<<FIVE))
    {
      digits = '5';
    }
    else if (touchstatus & (1<<TWO))
    {
      digits = '2';
    }
    else if (touchstatus & (1<<NINE))
    {
      digits = '9';
    }
    else if (touchstatus & (1<<SIX))
    {
      digits = '6';
    }
    else if (touchstatus & (1<<THREE))
    {
      digits = '3';
    }
    Serial.print("numero: ");
    Serial.println(digits);
    Bpulsado=digits;
    pulso=true;
  }
  
  /*//do nothing if more than one button is pressed, or if all are released
  else if (touchNumber == 0)
    ;
  else
    ;*/
    tft.setTextColor(BLACK);
    tft.setCursor(20, 300);
    tft.setTextSize(2);
    tft.print("has pulsado tecla");
}

/* getTouchStatus() will return a 16-bit value that relates the
current touched status of each button. The LSB represents electrodes
0-7 (bit 0 = electrode 0), and the lowest 4 bits of the MSB
represent electrods 8-11. A 1 means a button is being touched.*/
int getTouchStatus()
{
  int touch;
  
  touch = mpr121Read(0x01) << 8;
  touch |= mpr121Read(0x00);
  
  return touch;
}


double redondearNum(double a, int c){
  return (round(a * pow(10,c))/ pow(10,c));
}



//#define ILI9341_BLACK       0x0000      /*   0,   0,   0 */
//#define ILI9341_NAVY        0x000F      /*   0,   0, 128 */
//#define ILI9341_DARKGREEN   0x03E0      /*   0, 128,   0 */
//#define ILI9341_DARKCYAN    0x03EF      /*   0, 128, 128 */
//#define ILI9341_MAROON      0x7800      /* 128,   0,   0 */
//#define ILI9341_PURPLE      0x780F      /* 128,   0, 128 */
//#define ILI9341_OLIVE       0x7BE0      /* 128, 128,   0 */
//#define ILI9341_LIGHTGREY   0xC618      /* 192, 192, 192 */
//#define ILI9341_DARKGREY    0x7BEF      /* 128, 128, 128 */
//#define ILI9341_BLUE        0x001F      /*   0,   0, 255 */
//#define ILI9341_GREEN       0x07E0      /*   0, 255,   0 */
//#define ILI9341_CYAN        0x07FF      /*   0, 255, 255 */
//#define ILI9341_RED         0xF800      /* 255,   0,   0 */
//#define ILI9341_MAGENTA     0xF81F      /* 255,   0, 255 */
//#define ILI9341_YELLOW      0xFFE0      /* 255, 255,   0 */
//#define ILI9341_WHITE       0xFFFF      /* 255, 255, 255 */
//#define ILI9341_ORANGE      0xFD20      /* 255, 165,   0 */
//#define ILI9341_GREENYELLOW 0xAFE5      /* 173, 255,  47 */
//#define ILI9341_PINK        0xF81F
    /*
    tft.fillScreen(WHITE);
    tft.setTextSize(3);
    tft.setTextColor(BLACK);
    tft.setCursor(140, 140);
    tft.print("EMPIEZO EN BLANCO");
    delay(2000);

    tft.fillScreen(CYAN);
    tft.setCursor(140, 140);
    tft.print("CYAN");
    delay(1000);

    tft.fillScreen(MAGENTA);
    tft.setCursor(140, 140);    
    tft.print("MAGENTA");
    delay(1000);

    tft.fillScreen(BLUE);
    tft.setTextSize(5);
    tft.setCursor(140, 140);    
    tft.print("BLUE");
    delay(1000);

    tft.fillScreen(RED);
    tft.setCursor(140, 140);
    tft.print("RED");
    delay(1000);

    tft.fillScreen(GREEN);
    tft.setCursor(140, 140);  
    tft.print("GREEN");
    delay(1000);

    tft.fillScreen(YELLOW);
    tft.setTextSize(4);
    tft.setCursor(140, 140);   
    tft.print("YELLOW");
    delay(1000);

    tft.fillScreen(GRAY);
    tft.setCursor(140, 140); 
    tft.print("GRAY");
    delay(1000);

    tft.setTextColor(WHITE);
    tft.setCursor(140, 140);
    tft.fillScreen(BLACK);    
    tft.print("NEGROOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO");
    delay(1000);
  */

