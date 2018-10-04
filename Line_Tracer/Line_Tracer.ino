int bacespeed=50; //기본 모터 출력 속도
int spinspeed=60; //방향전환시 모터 출력 속도

void setup() {
  pinMode(4,OUTPUT);//모터 1 회전 방향조절 핀을 OUTPUT으로 설정
  pinMode(7,OUTPUT);//모터 2 회전 방향조절 핀을 OUTPUT으로 설정
  
  pinMode(5,OUTPUT);//모터 1 속도조절 핀을 OUTPUT으로 설정
  pinMode(6,OUTPUT);//모터 2 속도조절 핀을 OUTPUT으로 설정
  
  pinMode(16,INPUT);//적외선 센서1 값을 받는 핀을 INPUT으로 설정
  pinMode(17,INPUT);//적외선 센서2 값을 받는 핀을 INPUT으로 설정

  digitalWrite(4,HIGH);
  digitalWrite(7,HIGH);
}

//왼쪽 바퀴만 움직여 우회전을 하게 하는 함수
int Leftmove(){
  analogWrite(6,0);
  analogWrite(5,spinspeed+10);
  delay(15);
}

//오른쪽 바퀴만 움직여 좌회전을 하게 하는 함수
int Rightmove(){
  analogWrite(5, 0);
  analogWrite(6,spinspeed);
  delay(15);
}

void loop() {
  
  if(digitalRead(16)==0){
    Rightmove();
  }
  else{
    analogWrite(5,bacespeed+10);
    analogWrite(6,bacespeed);
  }

  
  if(digitalRead(17)==0){
    Leftmove();
  }
  else{
    analogWrite(5,bacespeed+10);
    analogWrite(6,bacespeed);
  }
}
