#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
#include <math.h>

LiquidCrystal lcd(2,3,4,5,6,7);
int GasSensorPin = 0; 
float adcValue = 0; 
float ratio_CO2, Rs_CO2;
double a, b, c;
float approx=2373.315;
float Vout, Rs, count, ratio, GasConc1, GasConc2, GasConc3; 
int ppm, ppm1, ppm2; 

SoftwareSerial gprsSerial(11, 10);
int incomingByte = 0;   // for incoming serial data

void setup (){
   lcdsetup();
   gsmsetup();
}

void loop(){
  lcdloop();
  gsmloop();
}

void lcdsetup()
 
{
 Serial.begin(9600);
  lcd.begin(16,2);
  delay(1000); 
}

void gsmsetup()
{
  gprsSerial.begin(9600);
  Serial.begin(9600);

  Serial.println("Config SIM900...");
 
  delay(2000);
  Serial.println("Done!...");
  gprsSerial.flush();
  Serial.flush();
  //incomingByte = gprsSerial.read();
//  Serial.print("I received: ");
//    while (gprsSerial.available()) {
//      delay(3);  //delay to allow buffer to fill 
//      if (gprsSerial.available() >0) {
//        char c = gprsSerial.read();  //gets one byte from serial buffer
//        readString += c; //makes the string readString
//      } 
  // attach or detach from GPRS service 
  gprsSerial.println("AT");
  //gprsSerial.flush();
  toSerial();
//  gprsSerial.println("ATD+919760566845");
//  toSerial();
  gprsSerial.println("AT+CGATT?");
  delay(100);
  toSerial();

   gprsSerial.println("AT+SAPBR=1,1,\"CONTYPE\",\"GPRS\"");
   delay(2000);
   toSerial();

   gprsSerial.println("AT+SAPBR=1,1,\"APN\",\"tata.docomo.internet\"");
   delay(2000);
   toSerial();

// gprsSerial.println("AT+SAPBR=1,1");
 // delay(2000);
//  toSerial();
  
}

 void gsmloop()
{
   // initialize http service
   gprsSerial.println("AT+HTTPINIT");
   delay(2000); 
   toSerial();

   // set http param value
   gprsSerial.print("AT+HTTPPARA=\"URL\",\"http://bis.iirs.gov.in?stdid=");
    
   gprsSerial.print(ppm);
   gprsSerial.print("&gas1=");
   
   gprsSerial.print(ppm1);
   gprsSerial.println("\"");
   delay(2000);
   toSerial();

   // set http action type 0 = GET, 1 = POST, 2 = HEAD
   gprsSerial.println("AT+HTTPACTION=0");
   delay(6000);
   toSerial();

   // read server response
   gprsSerial.println("AT+HTTPREAD"); 
   delay(1000);
   toSerial();

   gprsSerial.println("");
   gprsSerial.println("AT+HTTPTERM");
   toSerial();
   delay(300);

   gprsSerial.println("");
   delay(10000);
}

void toSerial()
{
  while(gprsSerial.available()!=0)
  {
    Serial.write(gprsSerial.read());
  }
 
}

void lcdloop()

{
  delay(1000);
  adcValue = analogRead (GasSensorPin); 
  Vout = adcValue * (5.032/1023.00); 
  Rs = ((5.0*20.0)/Vout)-20.0;  
  Serial.println(Rs);
  Rs_CO2 = ((5.0*20.0)-(20.0*Vout))/Vout;
  ratio_CO2 = Rs_CO2/approx;
  ratio = Rs/690.0;
  b = pow(ratio,2.50);
  c = pow(ratio,3.75);
  GasConc1 = 168.15*(2.868-ratio)+10;
  ppm = GasConc1;
  GasConc2 = (9.71/b)-8.49;
  ppm1 = GasConc2;
  GasConc3 = 73.15/c; 
  Serial.println(ppm);
  Serial.println(ppm1);
  Serial.println(ppm2);

lcd.setCursor(0,0);
lcd.print("CO2=");
lcd.print(ppm);
lcd.print("ppm");

delay(1000);
lcd.setCursor(0,1);
lcd.print("CO=");
lcd.print(ppm1);
 
lcd.print("ppm");

delay(1000);
//lcd.setCursor(0,1);

lcd.print("Ac=");
lcd.print(ppm2);
lcd.print("ppm");
}
