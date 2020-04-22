unsigned long tempo0 = 0;
unsigned long tempo0002 = 1L * 1L * 2L * 1000L; // 2 segundos
unsigned long tempo0005 = 1L * 1L * 5L * 1000L; // 5 segundos
unsigned long tempo00010 = 1L * 1L * 10L * 1000L; // 10 segundos
unsigned long tempo00015 = 1L * 1L * 15L * 1000L; // 15 segundos
unsigned long tempo002 = 1L * 2L * 60L * 1000L; // 2 minutos
unsigned long tempo005 = 1L * 5L * 60L * 1000L; // 5 minutos
unsigned long tempo010 = 1L * 10L * 60L * 1000L; // 10 minutos
unsigned long tempo015 = 1L * 15L * 60L * 1000L; // 15 minutos
unsigned long tempo030 = 1L * 30L * 60L * 1000L; // 30 minutos
unsigned long tempo1 = 1L * 60L * 60L * 1000L; // 1 horas
unsigned long tempo2 = 2L * 60L * 60L * 1000L; // 2 horas
unsigned long tempo3 = 3L * 60L * 60L * 1000L; // 3 horas
unsigned long tempo4 = 4L * 60L * 60L * 1000L; // 4 horas
unsigned long tempo5 = 5L * 60L * 60L * 1000L; // 5 horas
unsigned long tempo6 = 6L * 60L * 60L * 1000L; // 6 horas
unsigned long tempo7 = 7L * 60L * 60L * 1000L; // 7 horas
unsigned long tempo8 = 8L * 60L * 60L * 1000L; // 8 horas
unsigned long tempo9 = 9L * 60L * 60L * 1000L; // 9 horas
unsigned long tempo10 = 10L * 60L * 60L * 1000L; // 10 horas
unsigned long tempo11 = 11L * 60L * 60L * 1000L; // 11 horas
unsigned long tempo12 = 12L * 60L * 60L * 1000L; // 12 horas
unsigned long tempo42 = 42L * 60L * 60L * 1000L; // 42 horas
 
//Porta ligada ao pino IN1 do modulo
int rele = 13;
int leitura = 0;
  
void setup()
{
  //Define pinos para o rele como saida
  Serial.begin(9600);//Maior taxa de transferencia de dados
  pinMode(rele, OUTPUT); 
 
}
   
void loop(){
  
  int  time = 0;
   //Inicio do sistema, começa com o backup deconectado pelo sistema pelo tempo programado
  digitalWrite(rele, HIGH);  //Desliga Backup
  Serial.println("rele Desligado");
  delay(tempo00010);//Tempo Backup desconectado fisicamente
  
  while(time <= tempo030){//tempo de abertura
   char leitura = Serial.read();
   digitalWrite(rele, LOW); //Liga Backup
   Serial.println("Lendo Sensor");
   
   
   //Analise de sensores Ransonwere abertura
    if(leitura == '1'){
          digitalWrite(rele, HIGH);  //Liga rele 1
          //Serial.println("rele fora do loop desligado");
          delay(tempo12);
           break;
          }
   time++;// contador
}
digitalWrite(rele, HIGH);  //Liga rele 1
delay(tempo42);  
  
  
  /*
  digitalWrite(rele, LOW); //Liga Backup
  delay(tempo0005);//Tempo para Analise de sensores, espera sinal ou pula
  Serial.println("rele Ligado");
          if(leitura == '1'){
          digitalWrite(rele, HIGH);  //Liga rele 1
          Serial.println("rele fora do loop desligado");
          delay(tempo005);
          }
  delay(tempo00015);//Tempo de Abertura para fazer Backup
  */
}
