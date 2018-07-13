/***************************************************
  This is our GFX example for the Adafruit ILI9341 Breakout and Shield
 ****************************************************/
#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"

/***************************************************
 Touch Sense Shield Example using the MPR121 touch sensor IC 
 ****************************************************/
// include the atmel I2C libs
#include "mpr121.h"
#include "i2c.h"

/***************** SCREEN ***********************/
#define TFT_MISO  12
//#define TFT_LED   0 
#define TFT_CLK   13
#define TFT_MOSI  11
#define TFT_DC    9
#define TFT_RST   7
#define TFT_CS    10
// Use hardware SPI (on Uno, #13, #12, #11) and the above for CS/DC
//Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);
// If using the breakout, change pins as desired
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK, TFT_RST, TFT_MISO);





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
int irqPin = 2;  // D2
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
boolean bombaPH;
unsigned int animacionPH;
boolean bombaCL;
unsigned int animacionCL;
boolean depuradora;
unsigned int animacionDepuradora;

void setup() {
  /////////////valores en prueba
  bombaPH=true;
  animacionPH=1;
  bombaCL=true;
  animacionCL=1;
  depuradora=true; 
  animacionDepuradora=1;
  
  Serial.begin(9600);
  Serial.println("Pantalla preparada! ..."); 
  tft.begin();

  //make sure the interrupt pin is an input and pulled high
  pinMode(irqPin, INPUT);
  digitalWrite(irqPin, HIGH);
  i2cInit();
  mpr121QuickConfig();
  // Create and interrupt to trigger when a button
  // is hit, the IRQ pin goes low, and the function getNumber is run. 
  attachInterrupt(0,getNumber,LOW);
  // prints 'Ready...' when you can start hitting numbers
  Serial.println("Teclado preparado! ...");
  tft.setRotation(3);
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
    //texto (3, ILI9341_WHITE, "MENU", 100, 100);
    //Serial.println("menu");
    pantallaAjustes=pantallaAjustes01();
  } 
  pulso=false;
  Bpulsado=0;
}

int pantallaAjustes01() {
  tft.fillScreen(ILI9341_BLACK);
  tft.setRotation(3);
  tft.fillRect( 0, 0, 320, 35, ILI9341_BLUE);
  texto (3, ILI9341_WHITE, "AJUSTES       1/3", 5, 5);
  tft.drawFastHLine(0, 35, 320, ILI9341_WHITE);
  tft.fillRect( 0, 35, 320, 35, ILI9341_DARKCYAN);
  texto (3, ILI9341_BLACK, "GENERALES", 5, 40);
  tft.drawFastHLine(0, 70, 320, ILI9341_WHITE);
  //FECHA
  texto (1, ILI9341_WHITE, "dia", 134, 85);
  texto (1, ILI9341_WHITE, "mes", 184, 85);
  texto (1, ILI9341_WHITE, "ano", 234, 85);
  texto (2, ILI9341_WHITE, "FECHA:", 40, 110);
  //HORA
  texto (2, ILI9341_WHITE, "HORA:", 40, 140);
  //VOLUMEN
  tft.drawFastHLine(0, 165, 320, ILI9341_WHITE);
  texto (2, ILI9341_WHITE, "VOLUMEN:", 40, 180);
  texto (3, ILI9341_WHITE, "m3", 80, 210);

  
  
  unsigned int posicionCursor=0;
  unsigned int valor[6]         ={ 25,   8, 2017,  11,  38,  21};
  unsigned int valorNuevo[6]    ={ 25,   8, 2017,  11,  38,  21};
  unsigned int posx[6]          ={130, 180,  220, 130, 180, 40};
  unsigned int posy[6]          ={100, 100,  100, 130, 130, 210};
  unsigned int nCaracteres[6]   ={  2,   2,    4,   2,   2,   2};
  unsigned int maxCaracteres    =5; // 4+1
  unsigned int limiteInferior[6]={  1,   1, 2000,   0,   0,   1};
  unsigned int limiteSuperior[6]={ 31,  12, 3000,  24,  59,  99};
  /////////////////////////////////////////////////////////////////
  char msg[maxCaracteres];
  int i;

  //siguiente
  char siguiente[5]="OK.";
  boolean boolSiguiente=false;
  texto(4, ILI9341_WHITE, siguiente, 220, 200);
  
  //FECHA
  Serial.print("sizeof = ");
  Serial.println(sizeof(valor)/sizeof(int));
  for (i=0; i<(sizeof(valor)/sizeof(int)); i++) {
    sprintf (msg, "%i", valor[i]);
    texto (3, ILI9341_WHITE, msg, posx[i], posy[i]);
  } 
  texto (3, ILI9341_WHITE, ":", 165, 130); 
  
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
        //tft.fillRect( 210, 190, 110, 45, ILI9341_DARKGREY);
        tft.fillRoundRect( 210, 190, 108, 45, 5, ILI9341_DARKGREY);
        texto(4, ILI9341_WHITE, siguiente, 230, 200);
        delay(200);
        texto(4, ILI9341_BLACK, siguiente, 230, 200);
        delay(200);
      } else {
        texto(3, ILI9341_WHITE, msg, posx[posicionCursor], posy[posicionCursor]+3);
        delay(200);
        texto(3, ILI9341_BLACK, msg, posx[posicionCursor], posy[posicionCursor]+3);
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
        tft.fillRoundRect( 210, 190, 108, 45, 5, ILI9341_BLACK);
        texto(4, ILI9341_WHITE, siguiente, 230, 200);
      } else{
        posicionCursor--;
      }
     }
     
     /////////ARRIBA
     if (Bpulsado=='2'){
          //borro
          sprintf (msg, "%i", valor[posicionCursor]);
          texto(3, ILI9341_BLACK, msg, posx[posicionCursor], posy[posicionCursor]);
          
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
          texto(3, ILI9341_WHITE, msg, posx[posicionCursor], posy[posicionCursor]);
     }

     /////////ABAJO
     if (Bpulsado=='8'){
          //borro
          sprintf (msg, "%i", valor[posicionCursor]);
          texto(3, ILI9341_BLACK, msg, posx[posicionCursor], posy[posicionCursor]);
          
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
          texto(3, ILI9341_WHITE, msg, posx[posicionCursor], posy[posicionCursor]);
     }
     /////////////////OK
     if (Bpulsado=='5' and boolSiguiente==true){ 
        tft.fillScreen(ILI9341_BLACK);
        return(1);
     }

     /////////////////ESC
     if (Bpulsado=='9'){ 
        tft.fillScreen(ILI9341_BLACK);
        return(0);
     }
     Bpulsado=='0';
  }
}

void animacion(){
  if (depuradora==true){
    //Serial.println("-depuradora");
    if (animacionDepuradora==1){
      tft.fillRect( 165, 0, 155, 35, ILI9341_GREEN);
      texto (3, ILI9341_BLACK, "BOMBA", 175, 5);
      animacionDepuradora=2;
    }
    else if (animacionDepuradora==2){
      texto (3, ILI9341_GREEN, ">>", 280, 5);
      animacionDepuradora=3;
    }
    else if (animacionDepuradora==3){
      //texto (3, ILI9341_GREEN, "BOMBA", 280, 5);
      texto (3, ILI9341_BLACK, ">", 280, 5);
      animacionDepuradora=4;
    }
    else if (animacionDepuradora==4){
      texto (3, ILI9341_GREEN, ">", 280, 5);
      texto (3, ILI9341_BLACK, ">>", 280, 5);
      animacionDepuradora=2;
    }
    
    if (bombaPH==true){
    //Serial.println("--bombaPH");
      if (animacionPH==true){
        //Serial.println("---animacionPH");
        flechaArriba(130, 85, ILI9341_RED);
        animacionPH=2;
      }
      else if (animacionPH==2){
        flechaArriba(130, 85, ILI9341_BLACK);
        animacionPH=1;
      }
    } else {
        flechaArriba(130, 85, ILI9341_BLACK);
    }

    if (bombaCL==true){
    //Serial.println("--bombaPH");
      if (animacionCL==true){
        //Serial.println("---animacionPH");
        flechaArriba(260, 220, ILI9341_RED);
        animacionCL=2;
      }
      else if (animacionCL==2){
        flechaArriba(260, 220, ILI9341_BLACK);
        animacionCL=1;
      }
    }else {
         flechaArriba(260, 220, ILI9341_BLACK);
    }
  }
  else {   ///en caso de que no este funcionando la depuradora todo de apaga
      //Serial.println("borro");
      tft.fillRect( 165, 0, 155, 35, ILI9341_BLACK);
      flechaArriba(130, 85, ILI9341_BLACK);
      flechaArriba(260, 220, ILI9341_BLACK);
  }
  delay(300);
}

void pantallaPrincipal() {
  //dibujo pantalla principal
  //hora
  tft.fillScreen(ILI9341_BLACK);
  texto (3, ILI9341_WHITE, "12:23", 15, 10);
  tft.drawFastHLine(0, 35, 320, ILI9341_WHITE);
  //PH
  tft.fillCircle(75,105, 50, ILI9341_GREEN);
  texto (5, ILI9341_BLACK, "72", 45, 90);
  tft.fillCircle(35, 70, 20, ILI9341_BLUE);
  texto (2, ILI9341_WHITE, "PH", 25, 65);
  //TEMP
  tft.fillCircle(240, 105, 50, ILI9341_GREEN);
  texto (5, ILI9341_BLACK, "23", 210, 90);
  tft.fillCircle(275, 70, 20, ILI9341_BLUE);
  texto (1, ILI9341_WHITE, "o", 265, 65);
  texto (2, ILI9341_WHITE, "C", 275, 65);

  tft.drawLine(165, 35, 165, 150, ILI9341_WHITE);
  //CLORO 
  /*tft.fillRect( 125, 140, 70, 20, ILI9341_WHITE);
  texto (2, ILI9341_BLACK, "CLORO", 132, 142);
  tft.drawFastHLine(0, 160, 320, ILI9341_WHITE);*/
  
  tft.fillRoundRect(125, 140, 70, 10, 5, ILI9341_WHITE);
  tft.fillRect( 125, 145, 70, 15, ILI9341_WHITE);
  texto (2, ILI9341_BLACK, "CLORO", 132, 143);
  tft.drawFastHLine(0, 160, 320, ILI9341_WHITE);
  
  texto (1, ILI9341_WHITE, "BAJO", 20, 180);
  tft.fillRect( 20, 190, 70, 20, ILI9341_RED);
  texto (1, ILI9341_WHITE, "OK", 110, 180);
  tft.fillRect( 90, 190, 70, 20, ILI9341_GREEN);
  texto (1, ILI9341_WHITE, "ALTO", 200, 180);
  tft.fillRect( 160, 190, 70, 20, ILI9341_RED);
  triangulo(110,220, ILI9341_BLACK, ILI9341_WHITE);
  texto (2, ILI9341_WHITE, "475 mV", 105, 222);
  return;
}

void flechaArriba(unsigned int x, unsigned int y, int color){
  tft.fillRect( x+10, y-15, 10, 15, color);
  tft.fillTriangle(x, y-15, x+30, y-15, x+15, y-35, color); //tft.color565(0, i*10, i*10)); 
}
void triangulo(unsigned int x, unsigned int y, int color1, int color2){
  tft.fillTriangle(x, y, x+30, y, x+15, y-15, color2); //tft.color565(0, i*10, i*10)); 
  tft.drawTriangle(x, y, x+30, y, x+15, y-15, color1);
}

void pruebaTeclado(){
  int offset=35;
  int x;
  char frase[20];
  //for(x=cont; x<offset; x++) tft.drawLine(cont, x, 239, x, 0xBFFF00);
  tft.drawRect( 0, cont, 239, offset, 0x0F0);
  tft.fillRect( 1, cont+1, 238, offset-2, 0xF00F);
  
  sprintf(frase, " boton: %c", Bpulsado);
  texto(4, 0xF000, frase, 0, cont);
  pulso=false;
  //Serial.println(Bpulsado);
  //Serial.println(frase); 
  Serial.println(cont);
  cont=cont+35;     
  if (cont > 320-offset) { 
    tft.fillScreen(ILI9341_BLACK);
    cont=0;
    }  
}


//texto (tamaño, color, mensaje, posx, poxy, rotar, limpiar)
//limpiar 0=NO, 1=SI
//rotar 0=0, 1=90, 2=180, 3=270
void texto(int tam, int color, char mensaje[], int x, int y) {
  //char errorMessage = {"choose another option"};
  tft.setCursor(x, y);
  tft.setTextColor(color);
  tft.setTextSize(tam);
  tft.println(mensaje);
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
  //do nothing if more than one button is pressed, or if all are released
  else if (touchNumber == 0)
    ;
  else
    ;
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

/*
unsigned long testText() {
  tft.fillScreen(ILI9341_BLACK);
  unsigned long start = micros();
  tft.setCursor(0, 0);
  tft.setTextColor(ILI9341_WHITE);  tft.setTextSize(1);
  tft.println("Hello World!");
  tft.setTextColor(ILI9341_YELLOW); tft.setTextSize(2);
  tft.println(1234.56);
  tft.setTextColor(ILI9341_RED);    tft.setTextSize(3);
  tft.println(0xDEADBEEF, HEX);
  tft.println();
  tft.setTextColor(ILI9341_GREEN);
  tft.setTextSize(5);
  tft.println("Groop");
  tft.setTextSize(2);
  tft.println("I implore thee,");
  tft.setTextSize(1);
  tft.println("my foonting turlingdromes.");
  tft.println("And hooptiously drangle me");
  tft.println("with crinkly bindlewurdles,");
  tft.println("Or I will rend thee");
  tft.println("in the gobberwarts");
  tft.println("with my blurglecruncheon,");
  tft.println("see if I don't!");
  return micros() - start;
}


  unsigned long testFillScreen() {
  unsigned long start = micros();
  tft.fillScreen(ILI9341_BLACK);
  yield();
  tft.fillScreen(ILI9341_RED);
  yield();
  tft.fillScreen(ILI9341_GREEN);
  yield();
  tft.fillScreen(ILI9341_BLUE);
  yield();
  tft.fillScreen(ILI9341_BLACK);
  yield();
  return micros() - start;
}

  unsigned long testLines(uint16_t color) {
  unsigned long start, t;
  int           x1, y1, x2, y2,
                w = tft.width(),
                h = tft.height();

  tft.fillScreen(ILI9341_BLACK);
  yield();
  
  x1 = y1 = 0;
  y2    = h - 1;
  start = micros();
  for(x2=0; x2<w; x2+=6) tft.drawLine(x1, y1, x2, y2, color);
  x2    = w - 1;
  for(y2=0; y2<h; y2+=6) tft.drawLine(x1, y1, x2, y2, color);
  t     = micros() - start; // fillScreen doesn't count against timing

  yield();
  tft.fillScreen(ILI9341_BLACK);
  yield();

  x1    = w - 1;
  y1    = 0;
  y2    = h - 1;
  start = micros();
  for(x2=0; x2<w; x2+=6) tft.drawLine(x1, y1, x2, y2, color);
  x2    = 0;
  for(y2=0; y2<h; y2+=6) tft.drawLine(x1, y1, x2, y2, color);
  t    += micros() - start;

  yield();
  tft.fillScreen(ILI9341_BLACK);
  yield();

  x1    = 0;
  y1    = h - 1;
  y2    = 0;
  start = micros();
  for(x2=0; x2<w; x2+=6) tft.drawLine(x1, y1, x2, y2, color);
  x2    = w - 1;
  for(y2=0; y2<h; y2+=6) tft.drawLine(x1, y1, x2, y2, color);
  t    += micros() - start;

  yield();
  tft.fillScreen(ILI9341_BLACK);
  yield();

  x1    = w - 1;
  y1    = h - 1;
  y2    = 0;
  start = micros();
  for(x2=0; x2<w; x2+=6) tft.drawLine(x1, y1, x2, y2, color);
  x2    = 0;
  for(y2=0; y2<h; y2+=6) tft.drawLine(x1, y1, x2, y2, color);

  yield();
  return micros() - start;
}

unsigned long testFastLines(uint16_t color1, uint16_t color2) {
  unsigned long start;
  int           x, y, w = tft.width(), h = tft.height();

  tft.fillScreen(ILI9341_BLACK);
  start = micros();
  for(y=0; y<h; y+=5) tft.drawFastHLine(0, y, w, color1);
  for(x=0; x<w; x+=5) tft.drawFastVLine(x, 0, h, color2);

  return micros() - start;
}

unsigned long testRects(uint16_t color) {
  unsigned long start;
  int           n, i, i2,
                cx = tft.width()  / 2,
                cy = tft.height() / 2;

  tft.fillScreen(ILI9341_BLACK);
  n     = min(tft.width(), tft.height());
  start = micros();
  for(i=2; i<n; i+=6) {
    i2 = i / 2;
    tft.drawRect(cx-i2, cy-i2, i, i, color);
  }

  return micros() - start;
}

unsigned long testFilledRects(uint16_t color1, uint16_t color2) {
  unsigned long start, t = 0;
  int           n, i, i2,
                cx = tft.width()  / 2 - 1,
                cy = tft.height() / 2 - 1;

  tft.fillScreen(ILI9341_BLACK);
  n = min(tft.width(), tft.height());
  for(i=n; i>0; i-=6) {
    i2    = i / 2;
    start = micros();
    tft.fillRect(cx-i2, cy-i2, i, i, color1);
    t    += micros() - start;
    // Outlines are not included in timing results
    tft.drawRect(cx-i2, cy-i2, i, i, color2);
    yield();
  }

  return t;
}

unsigned long testFilledCircles(uint8_t radius, uint16_t color) {
  unsigned long start;
  int x, y, w = tft.width(), h = tft.height(), r2 = radius * 2;

  tft.fillScreen(ILI9341_BLACK);
  start = micros();
  for(x=radius; x<w; x+=r2) {
    for(y=radius; y<h; y+=r2) {
      tft.fillCircle(x, y, radius, color);
    }
  }

  return micros() - start;
}

unsigned long testCircles(uint8_t radius, uint16_t color) {
  unsigned long start;
  int           x, y, r2 = radius * 2,
                w = tft.width()  + radius,
                h = tft.height() + radius;

  // Screen is not cleared for this one -- this is
  // intentional and does not affect the reported time.
  start = micros();
  for(x=0; x<w; x+=r2) {
    for(y=0; y<h; y+=r2) {
      tft.drawCircle(x, y, radius, color);
    }
  }

  return micros() - start;
}

unsigned long testTriangles() {
  unsigned long start;
  int           n, i, cx = tft.width()  / 2 - 1,
                      cy = tft.height() / 2 - 1;

  tft.fillScreen(ILI9341_BLACK);
  n     = min(cx, cy);
  start = micros();
  for(i=0; i<n; i+=5) {
    tft.drawTriangle(
      cx    , cy - i, // peak
      cx - i, cy + i, // bottom left
      cx + i, cy + i, // bottom right
      tft.color565(i, i, i));
  }

  return micros() - start;
}

unsigned long testFilledTriangles() {
  unsigned long start, t = 0;
  int           i, cx = tft.width()  / 2 - 1,
                   cy = tft.height() / 2 - 1;

  tft.fillScreen(ILI9341_BLACK);
  start = micros();
  for(i=min(cx,cy); i>10; i-=5) {
    start = micros();
    tft.fillTriangle(cx, cy - i, cx - i, cy + i, cx + i, cy + i,
      tft.color565(0, i*10, i*10));
    t += micros() - start;
    tft.drawTriangle(cx, cy - i, cx - i, cy + i, cx + i, cy + i,
      tft.color565(i*10, i*10, 0));
    yield();
  }

  return t;
}

unsigned long testRoundRects() {
  unsigned long start;
  int           w, i, i2,
                cx = tft.width()  / 2 - 1,
                cy = tft.height() / 2 - 1;

  tft.fillScreen(ILI9341_BLACK);
  w     = min(tft.width(), tft.height());
  start = micros();
  for(i=0; i<w; i+=6) {
    i2 = i / 2;
    tft.drawRoundRect(cx-i2, cy-i2, i, i, i/8, tft.color565(i, 0, 0));
  }

  return micros() - start;
}

unsigned long testFilledRoundRects() {
  unsigned long start;
  int           i, i2,
                cx = tft.width()  / 2 - 1,
                cy = tft.height() / 2 - 1;

  tft.fillScreen(ILI9341_BLACK);
  start = micros();
  for(i=min(tft.width(), tft.height()); i>20; i-=6) {
    i2 = i / 2;
    tft.fillRoundRect(cx-i2, cy-i2, i, i, i/8, tft.color565(0, i, 0));
    yield();
  }

  return micros() - start;
}

*/
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


