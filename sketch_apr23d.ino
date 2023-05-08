#include "Wire.h"
#include "I2Cdev.h"
#include "MPU6050.h"

MPU6050 mpu;
int16_t ax, ay, az;
int16_t gx, gy, gz;

struct MyData {
  byte X;
  byte Y;
  byte Z;
};

MyData data;

// Calibration variables
const int calibrationTime = 5000; // 5 seconds
int16_t axOffset = 0, ayOffset = 0, azOffset = 0;

void setup()
{
  Serial.begin(9600);
  Wire.begin();
  mpu.initialize();

  // Calibration routine
  Serial.println("Starting calibration...");
  delay(1000);
  for (int i = 0; i < calibrationTime / 10; i++) {
    mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
    axOffset += ax;
    ayOffset += ay;
    azOffset += az;
    delay(10);
  }
  axOffset /= (calibrationTime / 10);
  ayOffset /= (calibrationTime / 10);
  azOffset /= (calibrationTime / 10);
  Serial.print("Calibration done. Ax offset: ");
  Serial.print(axOffset);
  Serial.print(", Ay offset: ");
  Serial.print(ayOffset);
  Serial.print(", Az offset: ");
  Serial.println(azOffset);
}

void loop()
{
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  ax -= axOffset;
  ay -= ayOffset;
  az -= azOffset;
  
  data.X = map(ax, -17000, 17000, 0, 255 );
  data.Y = map(ay, -17000, 17000, 0, 255); 
  data.Z = map(az, -17000, 17000, 0, 255);
  delay(500);
  
  float comp_angle_z = atan2(data.Y, data.Z) * 180.0 / M_PI;
  Serial.print("comp_angle_z: ");
  Serial.println(comp_angle_z);
  
  if(comp_angle_z > 40 && comp_angle_z < 42){
    Serial.println("Normal Breathing");
  }
  else if(comp_angle_z >= 42 && comp_angle_z < 44){
    Serial.println("Rapid Breathing");
  }
  else if(comp_angle_z >= 44 && comp_angle_z < 46){
    Serial.println("Shallow Breathing");
  }
  else if(comp_angle_z >= 46){
    Serial.println("Heavy Breathing");
  }
}


