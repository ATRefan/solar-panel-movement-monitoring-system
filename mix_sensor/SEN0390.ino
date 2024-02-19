void lux_read(){
  lux = myLux.lightStrengthLux();
  luxCal = lux*1.2307-8.6409;
  if (lux<0){
    lux = 0;
  }
  if (luxCal<0){
    luxCal = 0;
  }
}