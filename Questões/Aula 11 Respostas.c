
// Questão 1 Defina a função void Atraso(volatile unsigned int x); que fornece um atraso de x milissegundos. 
//Utilize o Timer_A para a contagem de tempo, e assuma que o SMCLK já foi configurado para funcionar a 1 MHz. 
//Esta função poderá ser utilizada diretamente nas outras questões desta prova.

void delay (volatile unsigned int y)
{
TACCR0 = 1000-1;
TACTL |= TACLR;
TACTL = TASSEL_2 + ID_0 + MC_1;
while(y>0)
{
y--;
while((TACTL & TAIFG) == 0);
TACTL &=~TAIFG;
}
TACTL = MC_0;
}

// Questão 2 Pisque os LEDs da Launchpad numa frequência de 100 Hz.
{
TACCR0 = 1000-1;
TACTL |= TACLR;
TACTL = TASSEL_2 + ID_0 + MC_1;
while(x>0)
{
x--;
while((TACTL & TAIFG) == 0);
TACTL &=~TAIFG;
}
TACTL = MC_0;
}

void main(void)
{
volatile int j, y;
WDTCTL = WDTPW + WDTHOLD;
P1DIR = LED1 + LED2;
P1OUT = LED1 + LED2;
y = 10; //10 ms ou 100hz
while(1)
{
P1OUT ^= LED1 + LED2;
atraso(y);
}
}


// Questão 3 Pisque os LEDs da Launchpad numa frequência de 20 Hz.

#include<msp430g2553.h>

void delay(volatile unsigned int y)
{
TACCR0 = 1000-1;
TACTL |= TACLR;
TACTL = TASSEL_2 + ID_0 + MC_1;
while(y>0)
{
y--;
while((TACTL & TAIFG) == 0);
TACTL &=~TAIFG;
}
TACTL = MC_0;
}

void main(void)
{
volatile int j, y;
WDTCTL = WDTPW + WDTHOLD;
P1DIR = LED1 + LED2;
P1OUT = LED1 + LED2;
y = 50; //50ms ou 20hz
while(1)
{
P1OUT ^= LED1 + LED2;
atraso(y);
}
}

// Questão 4 Pisque os LEDs da Launchpad numa frequência de 1 Hz.

#include<msp430g2553.h>

void delay(volatile unsigned int y)
{
TACCR0 = 1000-1;
TACTL |= TACLR;
TACTL = TASSEL_2 + ID_0 + MC_1;
while(y>0)
{
y--;
while((TACTL & TAIFG) == 0);
TACTL &=~TAIFG;
}
TACTL = MC_0;
}

void main(void)
{
volatile int j, y;
WDTCTL = WDTPW + WDTHOLD;
P1DIR =LED1 + LED6;
P1OUT = LED1 + LED6;
y = 1000; //100ms ou 1 Hz
while(1)
{
P1OUT ^= LED1 + LED6;
atraso(y);
}
}

// Questão 5 Pisque os LEDs da Launchpad numa frequência de 0,5 Hz.

#include<msp430g2553.h>

void delay(volatile unsigned int y)
{
TACCR0 = 1000-1;
TACTL |= TACLR;
TACTL = TASSEL_2 + ID_0 + MC_1;
while(y>0)
{
y--;
while((TACTL & TAIFG) == 0);
TACTL &=~TAIFG;
}
TACTL = MC_0;
}

void main(void)
{
volatile int j, y;
WDTCTL = WDTPW + WDTHOLD;
P1DIR = LED1 + LED2;
P1OUT = LED 1 + LED 2;
y = 2000; //0,5 Hz 
while(1)
{
P1OUT ^= LED1 + LED 2;
atraso(y);
}
}

// Questão 6 Repita as questões 2 a 5 usando a interrupção do Timer A para acender ou apagar os LEDs.



// Questão 7 Defina a função void paralelo_para_serial(void); que lê o byte de entrada via porta P1 e transmite os bits serialmente via pino P2.0.
//Comece com um bit em nivel alto, depois os bits na ordem P1.0 - P1.1 - … - P1.7 e termine com um bit em nível baixo. 
//Considere um período de 1 ms entre os bits.

// Questão 8 Faça o programa completo que lê um byte de entrada serialmente via pino P2.0 e transmite este byte via porta P1. 
//O sinal serial começa com um bit em nivel alto, depois os bits na ordem 0-7 e termina com um bit em nível baixo. Os pinos P1.0-P1.7 
//deverão corresponder aos bits 0-7, respectivamente. Considere um período de 1 ms entre os bits.

// Questão 9 Defina a função void ConfigPWM(volatile unsigned int freqs, volatile unsigned char ciclo_de_trabalho); 
//para configurar e ligar o Timer_A em modo de comparação. Considere que o pino P1.6 já foi anteriormente configurado como saída do canal 1 de comparação
//do Timer_A, que somente os valores {100, 200, 300, …, 1000} Hz são válidos para a frequência, que somente os valores {0, 25, 50, 75, 100} % 
//são válidos para o ciclo de trabalho, e que o sinal de clock SMCLK do MSP430 está operando a 1 MHz.