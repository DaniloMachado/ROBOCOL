//Motores
#define in1 11
#define in2 10
#define in3 9
#define in4 8
//Velocidade dos motores
#define velMotorD 6
#define velMotorE 5
//Variaveis do motor
int velocidade = 140;

//Sensores
#define sensorD A2
#define sensorE A5
#define sensorCentroD A3
#define sensorCentroE A4
//Variaveis dos Sensores
int direito = 0;
int esquerdo = 0;
int centroE = 0;
int centroD = 0;

void setup() {
  //Configuração Sensores
   pinMode(sensorD, INPUT);
   pinMode(sensorE, INPUT);
   pinMode(sensorCentroD, INPUT);
   pinMode(sensorCentroE, INPUT);
  
   //Iniciando Serial
   Serial.begin(9600);
}

void loop() {
    //Definindo Velocidade dos motores
    analogWrite(velMotorD, velocidade);
    analogWrite(velMotorE, velocidade);
    //Lendo A pista
    direito = analogRead(sensorD);
    esquerdo = analogRead(sensorE);
    centroE = analogRead(sensorCentroE);
    centroD = analogRead(sensorCentroD);
    if(centroD > 500 && centroE < 500 && esquerdo < 500 && direito < 500){
      paraFrenteD();
    }else if(centroD < 500 && centroE > 500 && esquerdo < 500 && direito < 500){
      paraFrenteE();
    }else if(centroD < 500 && centroE < 500 && esquerdo < 500 && direito < 500){
      paraFrente();
    }
}
void paraFrenteE(){  
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
}
void paraFrenteD(){  
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
}
void paraFrente(){  
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
}
void paraTras(){  
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
}
void freia(){
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);  
}

