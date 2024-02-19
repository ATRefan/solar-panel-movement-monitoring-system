#include <LiquidCrystal_I2C.h>
#include <DFRobot_B_LUX_V30B.h>
#include <DallasTemperature.h>
#include <Wire.h>

LiquidCrystal_I2C lcd( 0x27, 20, 4);

//MPU6050
const int MPU_addr=0x68;
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
double x;
double y;
double z;
int minVal=265;
int maxVal=402;

//for x
float  Xt_1t_1 = 0;
float  Pt_1t_1 = 0;

//for y
float  Yt_1t_1 = 0;
float  Pyt_1t_1 = 0;

//universal
int Q = 1;
int R = 100;

int roll, calRoll;
int pitch, calPitch;

//luxmeter
DFRobot_B_LUX_V30B myLux(13,6,5); //6 scl, 5 sda
long lux;
long luxCal;

//DS18B20
#define ONE_WIRE_BUS 4

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

int tempC1;
int tempC2;

float ftemp1;
float ftemp2;

float tpoly1;
float tpoly2;

int rPoly1;
int rPoly2;

void setup() {
  Serial.begin(9600);
  //lcd
  lcd.init();
  lcd.init();
  lcd.backlight();

  //MPU6050
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);

  //SEN0390
  myLux.begin();

  //DS18B20
  sensors.begin();  
  sensors.setResolution(10);

}

void loop() {
   gyro_read();
   lux_read();
   temp_read();
   lcd_display();
   Serial.print("lux normal:");
   Serial.println(lux);
   Serial.print("luxcal");
   Serial.println(luxCal);
   Serial.print("Roll: ");
   Serial.println(roll);
   Serial.print("Pitch");
   Serial.println(pitch);
}

//MAX SUDUT
//TB -30 s/d 30
//US 15 s/d 0