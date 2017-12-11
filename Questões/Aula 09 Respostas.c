// Questao 1 Escreva uma função em C que faz o debounce de botões ligados à porta P1.

#include <msp430g2553.h> // Biblioteca da MSP430 MODELO G2553
#define BTN BIT2         // btn=0000 00010
#define LED1 BIT0        // LED=0000 0001
#define LED2 BIT6         // LED2= 0010 0000
#define LED_DLY 5000      // VaLOR PARA SER DECREMENTADO

void delay( volatile unsigned long int t)
{
	while(t--);
}

int Debounce(int porta_1)
{
if(porta_1 = 1)
 {
     delay(100);		// Houve mudança - aguarda um tempo suficiente para pegar o valor
     if(porta_1 = 1)
       {
          return P1IN & porta_1; // esperou tempo suficiente
        }
    else if(porta_1 = 0)
        {
          return P1IN &~ porta_1;// nao esperou tempo suficiente
         }
  {
  }
 }
 }
  // Questao 2 Escreva um código em C que lê 9 botões multiplexados por 6 pinos, 
//e pisca os LEDs da placa Launchpad de acordo com os botões. Por exemplo, se o primeiro botão é pressionado, 
//os LEDs piscam uma vez; se o segundo botão é pressionado, os LEDs piscam duas vezes; e assim por diante. 
//Se mais de um botão é pressionado, os LEDs não piscam. 

#include< msp430g2553.h >
#define led BIT0
#define entradas (BIT1+BIT2+BIT3)
#define saidas   (BIT4+BIT5+BIT6)
void pisca (volatile unsigned int vezes){
	while ((vezes--)>0){
		P1OUT |= led;
		atraso(0xffff);
		P1OUT &= (~led);
		atraso(0xffff);			
	}
}

int main (void){
	WDTCTL = WDTPW | WDTHOLD;
	P1DIR |= (saidas+led);   // configura as entradas e saídas
	P1OUT = 0;           // inicia-se com o led apagado e saidas da multiplexação em 0
	P1IES &=(~entradas);  // interrupção nas bordas de descida
	P1ES |= entradas;
	_BIS_SR (GIE+LPM4_bits);	
	return 0;
}


interrupt(PORT1_VECTOR) Interrupcao_P1(void){
	if ((P1IN&BIT1)==0){ //está na linha 1 (147)
		P1OUT |= (BIT6 + BIT5) // verifica se está na coluna 1
			if ((P1IN&BIT1)==0){
				pisca(1);
			}		
		P1OUT &= (~saidas);
		P1OUT |= (BIT4 + BIT6) // verifica se está na coluna 2
			if ((P1IN&BIT1)==0){
				pisca(4);
			}
		P1OUT &= (~saidas);
		P1OUT |= (BIT4 + BIT5) // verifica se está na coluna 3
			if ((P1IN&BIT1)==0){
				pisca(7);
			}				
	}
	else if ((P1IN&BIT2)==0){ //está na linha 2 (258)
		P1OUT |= (BIT6 + BIT5) // verifica se está na coluna 1
			if ((P1IN&BIT2)==0){
				pisca(2);
			}		
		P1OUT &= (~saidas);
		P1OUT |= (BIT4 + BIT6) // verifica se está na coluna 2
			if ((P1IN&BIT2)==0){
				pisca(5);
			}
		P1OUT &= (~saidas);
		P1OUT |= (BIT4 + BIT5) // verifica se está na coluna 3
			if ((P1IN&BIT2)==0){
				pisca(8);
			}				
	}
	else {// está na linha 3 (369)
		P1OUT |= (BIT6 + BIT5) // verifica se está na coluna 1
			if ((P1IN&BIT3)==0){
				pisca(3);
			}		
		P1OUT &= (~saidas);
		P1OUT |= (BIT4 + BIT6) // verifica se está na coluna 2
			if ((P1IN&BIT3)==0){
				pisca(6);
			}
		P1OUT &= (~saidas);
		P1OUT |= (BIT4 + BIT5) // verifica se está na coluna 3
			if ((P1IN&BIT3)==0){
				pisca(9);
			}				
	}
}

