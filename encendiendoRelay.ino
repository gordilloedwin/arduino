int luz[]={2,3,4};

void setup(){
  for(int i=0; i<3; i++){
    pinMode(luz[i],OUTPUT);
  }
  Serial.begin(9600);
}

void loop(){
  if(Serial.available()){
    char inByte = Serial.read();
    if(inByte == '1'){
      digitalWrite(luz[0],HIGH);
    }
    if(inByte == '2'){
      digitalWrite(luz[1],HIGH);
    }
    if(inByte == '3'){
      digitalWrite(luz[2],HIGH);
    }
  }
}
