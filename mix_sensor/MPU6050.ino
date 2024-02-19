void gyro_read(){
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr,14,true);
  AcX=Wire.read()<<8|Wire.read();
  AcY=Wire.read()<<8|Wire.read();
  AcZ=Wire.read()<<8|Wire.read();
  int xAng = map(AcX,minVal,maxVal,-90,90);
  int yAng = map(AcY,minVal,maxVal,-90,90);
  int zAng = map(AcZ,minVal,maxVal,-90,90);
 
  x= RAD_TO_DEG * (atan2(yAng, zAng)+PI);
  y= RAD_TO_DEG * (atan2(-xAng, -zAng)+PI);
  z= RAD_TO_DEG * (atan2(yAng, xAng)+PI);

  //x calibration
  float  Xt_1 = Xt_1t_1;
  float Pt_1 = Pt_1t_1 + Q;
  float Kt = Pt_1 / (Pt_1 + R);
  float Xt = Xt_1 + Kt * (x -Xt_1);
  float Pt = (1-Kt) * Pt_1;
  Xt_1t_1 = Xt;
  Pt_1t_1 = Pt;
  roll = Xt ;
  calRoll = (1.0002*Xt)-179.05;


  //y calibration
  float Yt_1 = Yt_1t_1;
  float Pyt_1 = Pyt_1t_1 + Q;
  float Kyt = Pyt_1 / (Pyt_1 + R);
  float Yt = Yt_1 + Kyt * (y -Yt_1);
  float Pyt = (1-Kyt) * Pyt_1;
  Yt_1t_1 = Yt;
  Pyt_1t_1 = Pyt;
  pitch = Yt;
  calPitch = (Yt*0.9964)-1.7748;
}