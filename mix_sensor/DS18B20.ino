void temp_read(){
  sensors.requestTemperatures();
  tempC1 = sensors.getTempCByIndex(0);
  tempC2 = sensors.getTempCByIndex(1);
  ftemp1 = sensors.getTempCByIndex(0);
  ftemp2 = sensors.getTempCByIndex(1);
  
  float dec1 = ftemp1-tempC1;
  float dec2 = ftemp2-tempC2;
  int r1;
  int r2;
  //after calibration
  int calTempPoly1 = tpoly1;
  int calTempPoly2 = tpoly2;

  //get decimal number after calibration
  float rDecPoly1 = tpoly1 - calTempPoly1;
  float rDecPoly2 = tpoly2 - calTempPoly2;

  if(dec1<0.5){
    r1 = tempC1;
  }else if(dec1>=0.5){
    r1 = tempC1+1;
  }
  
  if(dec2<0.5){
    r2 = tempC2;
  }else if(dec2>=0.5){
    r2 = tempC2+1;
  }

  tpoly1 = 0.0003*pow(r1,2) + 0.9845*r1 + 1.192;
  tpoly2 = -0.0002*pow(r2,2) +  1.0281*r2 + 0.559;
  
  //calibrated polynomial
  if(rDecPoly1<0.5){
    rPoly1 = calTempPoly1;
  }else if(rDecPoly1>=0.5){
    rPoly1 = calTempPoly1 + 1;
  }

  if(rDecPoly2<0.5){
    rPoly2 = calTempPoly2;
  }else if(rDecPoly2>=0.5){
    rPoly2 = calTempPoly2 + 1;
  }
}