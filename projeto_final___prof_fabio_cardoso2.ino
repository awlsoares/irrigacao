/* TRABALHO FINAL DE INTRODUÇÃO A PROGRAMAÇÃO

Professor Fábio Cardoso.

Alunos: Adam William  2015300001
        Edmar Couto   2015300009
        Marcus André  2015300019
		Yago Teixeira 2015300040

 Código implementado em C++ / Arduino para monitorar a umidade do solo e acionar uma bomba de irrigação de água para manter a umidade adequada. */

// C++ code
// Sistema de monitoramento da umidade no solo

#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>

//Declarando o display LCD
LiquidCrystal_I2C lcd(32, 16, 2);

int sensor = A0;
int led_vermelho = 4;
int led_amarelo = 5;
int led_verde = 6;
int buzzer = 7; 
int bomba_irrigacao = 8;

void setup(){
 
  lcd.begin(16,2);
  Serial.begin(9600);
 
  pinMode(sensor, OUTPUT);
  
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  
  digitalWrite(sensor, LOW);
   
  //Inicializa o display LCD
    lcd.init();
    
  	lcd.backlight();
  	lcd.leftToRight();
    lcd.setCursor(3,0);
    lcd.print("Monitor de");
    lcd.setCursor(0,1);
    lcd.print("Umidade do Solo");
    delay(4000);
}

void loop()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Nivel de Umidade:");
  
    // lê o nível de tensao do pino "sensor"
    int sensorValue = analogRead(sensor);
    
    //Condiçoes para cada nivel de tensao
    if (sensorValue < 4) {
      
      Serial.print(analogRead(sensor));
      Serial.print("\n");
      lcd.setCursor(0,1);
      lcd.print("Solo SECO");
      digitalWrite(led_vermelho,1);
	  digitalWrite(led_amarelo,0);
	  digitalWrite(led_verde,0);
	  digitalWrite(buzzer,1);
      digitalWrite(bomba_irrigacao,1);
      delay(2000);
      digitalWrite(led_vermelho,0);
	  digitalWrite(led_amarelo,0);
	  digitalWrite(led_verde,0);
	  digitalWrite(buzzer,0);
      digitalWrite(bomba_irrigacao,0);
      delay(2000);
      lcd.clear();
      
    }
    if (sensorValue > 4 && sensorValue <=40) {//nivel de tensao entre 60% e 75%

      Serial.print(analogRead(sensor));
      Serial.print("\n");
      lcd.setCursor(0,1);
      lcd.print("Umidade Moderada");
      digitalWrite(led_vermelho,0);
	  digitalWrite(led_amarelo,1);
	  digitalWrite(led_verde,0);
	  digitalWrite(buzzer,0);
      digitalWrite(bomba_irrigacao,0);
      delay(2000);
      lcd.clear();

    }
    
    if (sensorValue > 40) {//nivel de tensao em 100%

      Serial.print(analogRead(sensor));
      Serial.print("\n");
      lcd.setCursor(0,1);
      lcd.print("Solo Umido");
      digitalWrite(led_vermelho,0);
	  digitalWrite(led_amarelo,0);
	  digitalWrite(led_verde,1);
	  digitalWrite(buzzer,0);
      digitalWrite(bomba_irrigacao,0);
      delay(2000);
      lcd.clear();
    }
      delay(10);
}
