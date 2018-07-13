

#include <LiquidCrystal.h>
#define SAMPLES_FAST_AVERAGE 	64
#define SAMPLES_TO_AVERAGE 		256


LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //Inicializamos la libreria con el numero de los pines a utilizar

int Sensor = A5;  //se declara el pin en el que estara el sensor, refiriendose en ocaciones futuras como variable "sensor"
int ventilador = 6;   //se declara la variable donde se colocara el ventilador
int foco = 7;
float tempC;    //Aqui se van a guardar los datos de la temperatura del sensor
int lectura;
float RawTemp;

void setup(){
	analogReference(INTERNAL);  //usando la referencia interna del arduino, configuramos a este para que opere con 1,1V, limitando la temp. a solo de 0 a 110°C de los 150 que puede medir el LM35
                            //pero sino se hace esto, no se puede obtener la resolucion de 0.1 °C                            
 	lcd.begin(16, 2);         // Configuramos el numero de columnas y filas del LCD. 
   lcd.print("Temperatura: ");  //impresion de mensaje
   lcd.setCursor(0,1);
   lcd.print ("      Grados");
   pinMode (6, OUTPUT);           //el pin del ventilador se declarara como salida
   for (int i= 0; i<SAMPLES_TO_AVERAGE; i++) {
   		lectura = analogRead(Sensor);  //asignacion de lo que se mida en la variable sensor, a la variable lectura
		RawTemp = lectura / 9.31;        //ATENCION, al cambiar la ref analogica del arduino de 5v a 1.1v se tiene que reformular la ec. para obtener la temperatura de tal forma que
                               // se divide 1./1024 = 0.001074V = 1.0742 mV. Si 10mV es igual a 1 grado Celsius, 10 / 1.0742 = ~ 9,31.
                              // Así, por cada cambio de 9,31 en la lectura analógica, hay un grado de cambio de temperatura.

    	//tempC = tempC - (tempC / SAMPLES_TO_AVERAGE) + RawTemp;   // para la primer iteraccion veran que RawTemp vale 0 y que 0 - 0 + tempC toma el primer valor 
		tempC = tempC  + (RawTemp - tempC) / SAMPLES_TO_AVERAGE;
	}


}

void loop()
{
	lectura = analogRead(Sensor);  //asignacion de lo que se mida en la variable sensor, a la variable lectura
	RawTemp = lectura / 9.31;        //ATENCION, al cambiar la ref analogica del arduino de 5v a 1.1v se tiene que reformular la ec. para obtener la temperatura de tal forma que
                               // se divide 1./1024 = 0.001074V = 1.0742 mV. Si 10mV es igual a 1 grado Celsius, 10 / 1.0742 = ~ 9,31.
                              // Así, por cada cambio de 9,31 en la lectura analógica, hay un grado de cambio de temperatura.

    //tempC = tempC - (tempC / SAMPLES_TO_AVERAGE) + RawTemp;   // aca ya trae 256 muestras previas promediadas.
    tempC = tempC  + (RawTemp - tempC) / SAMPLES_TO_AVERAGE;                        
  	
  	lcd.setCursor (0,1);
  	lcd.print(tempC);      //se imprime la temperatura en el display
  
   	if (tempC > 25)   //Si la temperatura es mayor que 25  en este caso se encendera el ventilador para disipar calor... Mich no seas menso "<" es menor que
       	digitalWrite (6, HIGH);
    else          //sino se apagará
      	digitalWrite (6, LOW);
   
   	if (tempC < 20)
      	digitalWrite (7, HIGH);
   	else
      	digitalWrite(7, LOW);
 }