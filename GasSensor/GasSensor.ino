#define SAMPLE_COUNT    10

#define PRINT_INTERVAL  5 // in secounds

int sensorData_0[SAMPLE_COUNT];
int sensorData_1[SAMPLE_COUNT];
int sensorData_2[SAMPLE_COUNT];
int sensorData_3[SAMPLE_COUNT];
int sensorData_4[SAMPLE_COUNT];

int sensorDataAvg[4]={0};

void setup() {
  Serial.begin(9600);
  Serial.println("StartUp Msg");
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
}

void loop() {
  static int sampleAt=0;
  static long loopMillisAt = millis();
  static long printMillisAt = millis();
  if(millis() > loopMillisAt){
    sensorData_0[sampleAt]=analogRead(A0);
    sensorData_1[sampleAt]=analogRead(A1);
    sensorData_2[sampleAt]=analogRead(A2);
    sensorData_3[sampleAt]=analogRead(A3);
    sensorData_4[sampleAt]=analogRead(A4);
    if(sampleAt == SAMPLE_COUNT){
      int i=0;
      for(i=0;i<4;i++){
        sensorDataAvg[i]=0;
      }
      for(i=0;i<SAMPLE_COUNT;i++){
        sensorDataAvg[0] = sensorDataAvg[0]+sensorData_0[i];
        sensorDataAvg[1] = sensorDataAvg[1]+sensorData_1[i];
        sensorDataAvg[2] = sensorDataAvg[2]+sensorData_2[i];
        sensorDataAvg[3] = sensorDataAvg[3]+sensorData_3[i];
        sensorDataAvg[4] = sensorDataAvg[4]+sensorData_4[i];
      }
      sensorDataAvg[0] = (sensorDataAvg[0]/SAMPLE_COUNT);
      sensorDataAvg[1] = (sensorDataAvg[0]/SAMPLE_COUNT);
      sensorDataAvg[2] = (sensorDataAvg[0]/SAMPLE_COUNT);
      sensorDataAvg[3] = (sensorDataAvg[0]/SAMPLE_COUNT);
      sensorDataAvg[4] = (sensorDataAvg[0]/SAMPLE_COUNT);
      
      sampleAt=0;
    }else{
      sampleAt++;
    }
    loopMillisAt = millis()+100;
  }

  if(millis() > printMillisAt){
    char _buffer[64];
//    sprintf(_buffer, "S0:%04d, S1:%04d, S2:%04d, S3:%04d, S4:%04d", sensorDataAvg[0], sensorDataAvg[1], sensorDataAvg[2], sensorDataAvg[3], sensorDataAvg[4]);
    sprintf(_buffer, "S0:%04d, S1:%04d, S2:%04d, S3:%04d, S4:%04d", analogRead(A0), analogRead(A1), analogRead(A2), analogRead(A3), analogRead(A4));
    Serial.println(_buffer);
    printMillisAt = millis()+(1000*PRINT_INTERVAL);
  }
  
//  Serial.println(analogRead(A0));
}
