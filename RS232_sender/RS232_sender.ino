#define BUTTON_SEND 10
#define BUTTON_GREEN 11
#define BUTTON_RED 12
#define DIP_BIT_0 9
#define DIP_BIT_1 8
#define DIP_BIT_2 7
#define DIP_BIT_3 6
#define DIP_BIT_4 5
#define DIP_BIT_5 4
#define DIP_BIT_6 3
#define DIP_BIT_7 2

int byteInput[8] = {0,0,0,0,0,0,0,0};
int inputByte = 0;
int buttonFlag[3];
  
void setup() {
  Serial.begin(9600);
  //Serial.print("start");
  pinMode(DIP_BIT_0, INPUT);
  pinMode(DIP_BIT_1, INPUT);
  pinMode(DIP_BIT_2, INPUT);
  pinMode(DIP_BIT_3, INPUT);
  pinMode(DIP_BIT_4, INPUT);
  pinMode(DIP_BIT_5, INPUT);
  pinMode(DIP_BIT_6, INPUT);
  pinMode(DIP_BIT_7, INPUT);
  pinMode(BUTTON_SEND, INPUT);
}

void loop() {
  for(int i = 0; i < 8; i++){
    byteInput[i] = digitalRead(i + 2);
    inputByte = byteInput[0]*128 + byteInput[1]*64 + byteInput[2]*32 + byteInput[3]*16 + byteInput[4]*8 + byteInput[5]*4 + byteInput[6]*2 + byteInput[7]*1;
  }

  if(digitalRead(BUTTON_SEND) && !buttonFlag[0]){
    buttonFlag[0] = 1;
    Serial.print(inputByte);
  }
  buttonFlag[0] = digitalRead(BUTTON_SEND);

  if(digitalRead(BUTTON_GREEN) && !buttonFlag[1]){
    buttonFlag[1] = 1;
    Serial.print(0);
  }
  buttonFlag[1] = digitalRead(BUTTON_GREEN);
  
  if(digitalRead(BUTTON_RED) && !buttonFlag[2]){
    buttonFlag[2] = 1;
    Serial.print(255);
  }
  buttonFlag[2] = digitalRead(BUTTON_RED);
  
  delay(10);
}
