// Questão 1 Projete o hardware necessário para o MSP430 controlar um motor DC de 12V e 4A. 
//Utilize transistores bipolares de junção (TBJ) com Vbe = 0,7 V, beta = 100 e Vce(saturação) = 0,2 V. Além disso, considere que Vcc = 3 V para o MSP430, e 
//que este não pode fornecer mais do que 10 mA por porta digital.

Suponha que o transistor suporte a corrente de coletor dada pela carga, que é o motor DC. 
A corrente de coletor necessária = 4 A. Logo a corrente de base será:

Ib = Ic / 100 = 4 / 100 = 40 mA.

Como a corrente de base ultrapassa a corrente que a porta digital pode fornecer, então deve-se utilizar dois transistores,
na forma do par Darlington. Então a corrente de base será:

Ib = Ic / β2 = 4 /10000 = 0,4 mA

O resistor Rb = (Vcc – 2*Vbe)/Ib = (3 – 2*0,7)/0,4*10^(-3) = 4 Kohm

// Questão 2 Projete o hardware necessário para o MSP430 controlar um motor DC de 10V e 1A. 
//Utilize transistores bipolares de junção (TBJ) com Vbe = 0,7 V e beta = 120. Além disso, considere que Vcc = 3,5 V para o MSP430, 
//e que este não pode fornecer mais do que 10 mA por porta digital.

A corrente de coletor Ic é 1A, Logo a corrente de base será:

Ib = Ic/β = 1/120 = 8,33 mA.

Rb = (Vcc-Vbe)/Ib
= (Vcc-Vbe)*β/Ic = ((3,5 - 0,7)*120)/1 = 336 ohm

// Questão 3 Projete o hardware utilizado para controlar 6 LEDs utilizando charlieplexing. 
//Apresente os pinos utilizados no MSP430 e os LEDs, nomeados L1-L6.

// Questão 4 Defina a função void main(void){} para controlar 6 LEDs de uma árvore de natal usando o hardware da questão anterior. 
//Acenda os LEDs de forma que um ser humano veja todos acesos ao mesmo tempo.

	#define bits_cpx (BIT0+BIT1+BIT2)

	int main (void){
		WDTCTL = WDTPW | WDTHOLD;
		P1DIR = 0x0000; //inicia todas as portas como entradas
		P1OUT = 0x0000;
		
		while (1){
			//acende o led 1
			P1DIR |= (BIT1+BIT2); //bits 1 e 2 como saída
			PIOUT |= (BIT1);     //bit 1 em nível alto
			P1OUT &= ~(bits_cpx); //prepara para próximo led
			//acende o led 2
			PIOUT |= (BIT2);   //bit 2 em nível alto
			P1OUT &= ~(bits_cpx); //prepara para próximo led
			P1DIR &= ~(bits_cpx); //prepara para próximo led
			//acende o led 3
			P1DIR |= (BIT1+BIT0); //bits 1 e 0 como saída
			PIOUT |= (BIT0);  //bit 0 em nível alto		
			P1OUT &= ~(bits_cpx); //prepara para próximo led
			//acende o led 4
			PIOUT |= (BIT1); //bit 1 em nível alto		
			P1OUT &= ~(bits_cpx); //prepara para próximo led
			P1DIR &= ~(bits_cpx); //prepara para próximo led
			//acende o led 5
			P1DIR |= (BIT0+BIT2);
			PIOUT |= (BIT1);			
			P1OUT &= ~(bits_cpx);
			//acende o led 6
			PIOUT |= (BIT2);			
			P1OUT &= ~(bits_cpx);
			P1DIR &= ~(bits_cpx); //prepara para próximo led			
		}
		return 0;
	}


// Questão 5 Defina a função void main(void){} para controlar 6 LEDs de uma árvore de natal usando o hardware da questão 3. 
//Acenda os LEDs de forma que um ser humano veja os LEDs L1 e L2 acesos juntos por um tempo, depois os LEDs L3 e L4 juntos, e depois os LEDs L5 e L6 juntos.

int main (void){
		int i;
		WDTCTL = WDTPW | WDTHOLD;
		P1DIR = 0x0000; //inicia todas as portas como entradas
		P1OUT = 0x0000;
		
		while (1){
			for(i=0; i<0x0000; i++){
			//acende o led 1
			P1DIR |= (BIT1+BIT2); //bits 1 e 2 como saída
			PIOUT |= (BIT1);     //bit 1 em nível alto
			P1OUT &= ~(bits_cpx); //prepara para próximo led
			//acende o led 2
			PIOUT |= (BIT2);   //bit 2 em nível alto
			P1OUT &= ~(bits_cpx); //prepara para próximo led
			P1DIR &= ~(bits_cpx); //prepara para próximo led				
			}
			for(i=0; i<0x0000; i++){
			//acende o led 3
			P1DIR |= (BIT1+BIT0); //bits 1 e 0 como saída
			PIOUT |= (BIT0);  //bit 0 em nível alto		
			P1OUT &= ~(bits_cpx); //prepara para próximo led
			//acende o led 4
			PIOUT |= (BIT1); //bit 1 em nível alto		
			P1OUT &= ~(bits_cpx); //prepara para próximo led
			P1DIR &= ~(bits_cpx); //prepara para próximo led
			}
			for(i=0; i<0x0000; i++){
						//acende o led 5
			P1DIR |= (BIT0+BIT2);
			PIOUT |= (BIT1);			
			P1OUT &= ~(bits_cpx);
			//acende o led 6
			PIOUT |= (BIT2);			
			P1OUT &= ~(bits_cpx);
			P1DIR &= ~(bits_cpx); //prepara para próximo led
			}			
		}
		return 0;
	}


// Questão 6 Defina a função void EscreveDigito(volatile char dig); que escreve um dos dígitos 0x0-0xF em um único display de 7 segmentos via porta P1, baseado na figura abaixo. Considere que em outra parte do código os pinos P1.0-P1.6 já foram configurados para corresponderem aos LEDs A-G, e que estes LEDs possuem resistores externos para limitar a corrente.

//        ---  ==> A
//       |   |
// F <== |   | ==> B
//       |   |
//        ---  ==> G
//       |   |
// E <== |   | ==> C
//       |   |
//        ---  ==> D
// Questão 7 Multiplexe 2 displays de 7 segmentos para apresentar a seguinte sequência em loop: 00 - 11 - 22 - 33 - 44 - 55 - 66 - 77 - 88 - 99 - AA - BB - CC - DD - EE - FF