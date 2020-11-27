char keypress = '0';
int count = 0;

int speedPWM = 1000;
int potencia = 0;

void main() {

trisc.rc0 = 0;
trisc.rc2 = 0;
portc = 0;


PWM1_Start();
PWM1_Init(2000);

uart1_init(9600);
delay_ms(100);

adcon1 = 0b00001111;


do {

UART1_Write_Text("*********  SISTEMA DA EMPRESA  *********** \r \r");
UART1_Write_Text("Digite (0) para motor desligado \r");
UART1_Write_Text("Digite (1) para motor em 10% \r");
UART1_Write_Text("Digite (2) para motor em 20% \r");
UART1_Write_Text("Digite (a) para motor em 100% \r\r");
UART1_Write_Text("Digite (b) para acender o led \r");
UART1_Write_Text("Digite (c) para apagar o led \r\r");

if (UART1_Data_Ready())
keypress = UART1_Read();

switch(keypress){
case '0':
  potencia = 0;
  PWM1_Set_Duty(potencia);
  UART1_Write_Text("Motor desligado");
  portc.rc2 = 0;
  break;
case '1':
  potencia = (speedPWM * 10);
  PWM1_Set_Duty(potencia);
  UART1_Write_Text("Motor em 10%");
  portc.rc2 = 0;
  break;

case '2':
  potencia = (speedPWM * 9);
  PWM1_Set_Duty(potencia);
  UART1_Write_Text("Motor em 20%");
  portc.rc2 = 0;
  break;

case '3':
  potencia = (speedPWM * 8);
  PWM1_Set_Duty(potencia);
  UART1_Write_Text("Motor em 30%");
  portc.rc0 = 0;
  break;

case 'a':
  potencia = (speedPWM * 1);
  PWM1_Set_Duty(potencia);
  UART1_Write_Text("Motor em 100%");
  portc.rc0 = 0;
  break;

case 'b':
  UART1_Write_Text("LED ACESO");
  portc.rc0 = 1;
  break;

case 'c':
  UART1_Write_Text("LED APAGADO");
  portc.rc0 = 0;
  break;
}


delay_ms(1200);
UART1_Write ('\f');


}while(1);
}
