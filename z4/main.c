#include <msp430x14x.h>
#include "lcd.h"
#include "portyLcd.h"

#define BUTTON1 BIT4&P4IN
#define BUTTON2 BIT5&P4IN
#define BUTTON3 BIT6&P4IN
#define BUTTON4 BIT7&P4IN

unsigned char i;

void InitSpecial() {
  SEND_CMD(CG_RAM_ADDR);
  int spec[5][8] = {{4, 31, 17, 16, 31, 1, 17, 31},{4, 31, 1, 2, 4, 8, 16, 31},{4, 0, 14, 17, 17, 17, 14, 0}
  ,{4, 4, 6, 4, 12, 4, 7, 0},{0, 14, 17, 31, 16, 17, 14, 4}};
  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 8; j++) 
    {
      SEND_CHAR(spec[i][j]);
    }
  }
}

 void main(void)
  {
    /*
    SEND_CHAR(8); //Œ
    SEND_CHAR(1); //¯
    SEND_CHAR(2); //ó
    SEND_CHAR(3); //³
    SEND_CHAR(4); //ê
    */
    
    WDTCTL=WDTPW+WDTHOLD;
    InitPortsLcd();
    InitLCD();
    clearDisplay();
    InitSpecial();
    SEND_CMD(DD_RAM_ADDR);
    SEND_CHAR(1);
    SEND_CHAR('y');
    SEND_CHAR('c');
    SEND_CHAR('z');
    SEND_CHAR('y');
    SEND_CHAR('m');
    SEND_CHAR('y');
    SEND_CMD(DD_RAM_ADDR2);
    SEND_CHAR('s');
    SEND_CHAR('o');
    SEND_CHAR('b');
    SEND_CHAR('i');
    SEND_CHAR('e');
    SEND_CHAR(' ');
    SEND_CHAR('i');
    SEND_CHAR(' ');
    SEND_CHAR('W');
    SEND_CHAR('a');
    SEND_CHAR('m');
    
    while (1>0) {
    SEND_CMD(DATA_ROL_RIGHT);
    Delayx100us(500);
    SEND_CMD(DATA_ROL_RIGHT);
    Delayx100us(1000);
    SEND_CMD(DATA_ROL_LEFT);
    Delayx100us(1000);
    
    }
  }

void ustaw_przyciski() {
  P4DIR &= ~BIT4;
  P4DIR &= ~BIT5;
  P4DIR &= ~BIT6;
  P4DIR &= ~BIT7;
}


/*
#define BUTTON1 BIT4&P4IN
#define BUTTON2 BIT5&P4IN
#define BUTTON3 BIT6&P4IN
#define BUTTON4 BIT7&P4IN

void main( void )
{
  unsigned int i;
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  P1DIR |= BIT6;
  P1DIR |= BIT5;
  P2DIR |= BIT1;
  BCSCTL1 |= XTS + DIVA1 + DIVA0;
  do{IFG1 &= ~OFIFG;
  for(i = 0xFF; i > 0; i--);
  } while((IFG1 & OFIFG));
  WDTCTL = WDTPW + WDTCNTCL + WDTTMSEL +WDTSSEL ;
  IE1 |= WDTIE;
  _EINT();
  for(;;);
}

void ustaw_przyciski() {
  P4DIR &= ~BIT4;
  P4DIR &= ~BIT5;
  P4DIR &= ~BIT6;
  P4DIR &= ~BIT7;
}

#pragma vector=WDT_VECTOR
__interrupt void watchdog_timer(void){
  long int a;
  
  while (1==1){
  if(!(BUTTON1))
  {
    P1OUT ^= BIT6;
  }
  if(!(BUTTON2))
  {
    P1OUT ^= BIT5;
  }
  if(!(BUTTON3))
  {
    P2OUT ^= BIT1;
  }
  }*/
  /*
  long int a;
  long int b;
  long int c;
  for(c=0;c<2;c++){
  for(b=0;b<2;b++){
  for(a=0;a<62500;a++);
  P1OUT ^= BIT6;}
  P1OUT ^= BIT5;}
  P2OUT ^= BIT1;
  */
  /*
  if(!BUTTON1)
  {
    P1OUT ^= BIT6;
  }
  if(!BUTTON2)
  {
    P1OUT ^= BIT5;
  }
  if(!BUTTON3)
  {
    P2OUT ^= BIT1;
  }
  */
//}
  