/*
 Virtual Color Mixer
 
 Este ejemplo lee 3 sensores analógicos y envía sus valores de forma serial.
 Cualquier otra aplicación puede tomar sus valores y cambiar el color de fondo
 de una pantalla.
 
 El circuito:
 * tres sensores analógicos conectados a A0, A1 y A2
 
 creado 2 Dec 2006 por David A. Mellis
 modificado 4 Sep 2010 por Tom Igoe y Scott Fitzgerald
 
 Este ejemplo se encuentra en dominio público.
*/

const int izquierda = A0;	  // sensor que controla el color rojo
const int centro = A2;  // sensor que controla el color verde
const int derecha = A4;	  // sensor que controla el color azul


// variables:
int sensorValue = 0;   // the sensor value
int sensorValue1 = 0;
int sensorValue2 = 0;

int sensorMin= 0;
int sensorMax = 1023;

int sensorMin1 = 0;  // minimum sensor value
int sensorMax1 = 1023;     // maximum sensor value


int sensorMin2 = 0;  // minimum sensor value
int sensorMax2 = 1023;     // maximum sensor value


void setup() {
  Serial.begin(9600);
   while (millis() < 5000) {
    sensorValue = analogRead(izquierda);

    // record the maximum sensor value
    if (sensorValue > sensorMax) {
      sensorMax = sensorValue;
    }

    // record the minimum sensor value
    if (sensorValue < sensorMin) {
      sensorMin = sensorValue;
    }

       // record the maximum sensor value
    if (sensorValue1 > sensorMax1) {
      sensorMax1 = sensorValue1;
    }

    // record the minimum sensor value
    if (sensorValue1 < sensorMin1) {
      sensorMin1 = sensorValue1;
    }

  if (sensorValue2 > sensorMax2) {
      sensorMax2 = sensorValue2;
    }

    // record the minimum sensor value
    if (sensorValue2 < sensorMin2) {
      sensorMin2 = sensorValue2;
    }



  }

}

void loop() {
  // read the sensor:
  sensorValue = analogRead(izquierda);

  // in case the sensor value is outside the range seen during calibration
  sensorValue = constrain(sensorValue, sensorMin, sensorMax);

  // apply the calibration to the sensor reading
  sensorValue = map(sensorValue, sensorMin, sensorMax, 0, 20);

   sensorValue1 = analogRead(centro);

  // in case the sensor value is outside the range seen during calibration
  sensorValue1 = constrain(sensorValue1, sensorMin1, sensorMax1);

  // apply the calibration to the sensor reading
  sensorValue1 = map(sensorValue1, sensorMin1, sensorMax1, 0, 20);

  sensorValue2 = analogRead(derecha);

  // in case the sensor value is outside the range seen during calibration
  sensorValue2 = constrain(sensorValue2, sensorMin2, sensorMax2);

  // apply the calibration to the sensor reading
  sensorValue2 = map(sensorValue2, sensorMin2, sensorMax2, 0, 20);


  Serial.print(sensorValue);
  Serial.print(" ");
  Serial.print(sensorValue1);
  Serial.print(" ");
  Serial.println(sensorValue2);
   delay(1);  // delay in between reads for stability
}
