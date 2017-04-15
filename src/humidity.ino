void setup(){

  Serial.begin(9600);

}

 

int oldV;

void loop() {

  int v = analogRead(0);

  v = smooth(v, 0.99, oldV);

  oldV = v;

  Serial.println(v);

  delay(2);

}

 

int smooth(int data, float filterVal, float smoothedVal) {

  if (filterVal > 1){      // check to make sure param's are within range

    filterVal = .99;

  }

  else if (filterVal <= 0){

    filterVal = 0;

  }

  smoothedVal = (data * (1 - filterVal)) + (smoothedVal  *  filterVal);

  return (int)smoothedVal;

}
