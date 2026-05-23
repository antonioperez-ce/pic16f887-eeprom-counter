/*Practrica 8
CONTADOR 0 A 99 CON MEMORIA EEPROM
Ceti Colomos
Electronica digital 4
Parcial 2
Diego Antonio Pérez Castellanos
Andrés Manuel Pérez Franco
*/

#INCLUDE <16F887.H>
#USE DELAY(CLOCK=4000000) 
#FUSES INTRC_IO,NOWDT,NOPUT,NOMCLR,NOPROTECT,NOCPD,NOBROWNOUT 
#FUSES NOIESO,NOFCMEN,NOLVP,NODEBUG,NOWRT,BORV21 

#USE FAST_IO(A)
#INCLUDE <LCD1.C>

INT I, J=READ_EEPROM(0X00), AUX, AUX2, CUENTA, Z=0, Y=0, TECLA[16]={1,2,3,10,4,5,6,11,7,8,9,12,14,0,15,13};
LONG VELOCIDAD=0, D1=0, D2=0, D3=0;

VOID MATRICIAL(){
   AUX=0XEF;                                 //Inicializar variable AUX
   CUENTA=0;                                 //Iniciaizar variable CUENTA
   FOR(I=0;I<4;I++)                          //Ciclo para barrido 4 Filas
   {
      AUX=AUX>>1;                               //Desplazamiento Derecha Pilas
      OUTPUT_A((INPUT_A()&0XF0)|(AUX&0X0F));    //Envío de 0 a cada fila
      
      IF(INPUT(PIN_A7)==0)                      //Preguntar por columnas=0
      BREAK;                                    //Se rompe el ciclo al ser verdadero
      CUENTA++;                                 //Se incrementa la cuenta al ser falso
      IF(INPUT(PIN_A6)==0)
      BREAK;
      CUENTA++;
      IF(INPUT(PIN_A5)==0)
      BREAK;
      CUENTA++;
      IF(INPUT(PIN_A4)==0)
      BREAK;
      CUENTA++;
      DELAY_MS(20);                             //Retraso de tiempo de 20ms
   }
}

VOID MAIN(){
   SET_TRIS_A(0XF0);
   SET_TRIS_D(0X00);
   
   LCD_INIT();
   
   PRINTF(LCD_PUTC,"\f");
   PRINTF(LCD_PUTC,"CETI\nCOLOMOS");
   DELAY_MS(500);
   PRINTF(LCD_PUTC,"\f");
   PRINTF(LCD_PUTC,"TGO. EN CONTROL\nAUTOMATICO E INS");
   DELAY_MS(500);
   PRINTF(LCD_PUTC,"\f");
   PRINTF(LCD_PUTC,"ELECTRONICA\nDIGITAL IV");
   DELAY_MS(500);
   PRINTF(LCD_PUTC,"\f");
   PRINTF(LCD_PUTC,"DIEGO PEREZ\n21300606");
   DELAY_MS(500);
   PRINTF(LCD_PUTC,"\f");
   PRINTF(LCD_PUTC,"ANDRES PEREZ\n21300583");
   DELAY_MS(500);
   PRINTF(LCD_PUTC,"\f");
   PRINTF(LCD_PUTC,"CONTADOR 0 A 99\nMEMORIA EEPROM");
   DELAY_MS(500);
   
   WHILE(TRUE){
      WHILE(Z==0){
         MATRICIAL();
         IF(CUENTA==12){
            WHILE(CUENTA<16){
               MATRICIAL();
            }
            Z=1;
            Y=0;
         }
         IF(Y==0&&(CUENTA<3||(CUENTA>3&&CUENTA<7)||(CUENTA>7&&CUENTA<11)||CUENTA==13)){
            AUX2=TECLA[CUENTA];
            WHILE(CUENTA<16){
               MATRICIAL();
            }
            D1=AUX2;
            Y=1;
         }
         IF(Y==1&&(CUENTA<3||(CUENTA>3&&CUENTA<7)||(CUENTA>7&&CUENTA<11)||CUENTA==13)){
            AUX2=TECLA[CUENTA];
            WHILE(CUENTA<16){
               MATRICIAL();
            }
            D2=AUX2;
            Y=2;
         }
         IF(Y==2&&(CUENTA<3||(CUENTA>3&&CUENTA<7)||(CUENTA>7&&CUENTA<11)||CUENTA==13)){
            AUX2=TECLA[CUENTA];
            WHILE(CUENTA<16){
               MATRICIAL();
            }
            D3=AUX2;
            Y=0;
         }
         VELOCIDAD=D1*100+D2*10+D3;
         lcd_gotoxy(1,1);
         PRINTF(LCD_PUTC,"VELOCIDAD CONTEO\n=%03Lu          ",VELOCIDAD);
      }
      MATRICIAL();
      IF(CUENTA==12){
         WHILE(CUENTA<16){
            MATRICIAL();
         }
         Z=0;
         Y=0;
      }
      lcd_gotoxy(1,1);
      PRINTF(LCD_PUTC,"%02u              \n                ",J);
      J++;
      IF(J==100){
         J=0;
      }
      IF(CUENTA==3){
         WHILE(CUENTA<16){
            MATRICIAL();
         }
         WRITE_EEPROM(0X00,J);
         lcd_gotoxy(1,1);
         PRINTF(LCD_PUTC,"VALOR GUARDADO:D\n%02u              ",J);
         DELAY_MS(1000);
      }
      IF(CUENTA==15){
         WHILE(CUENTA<16){
            MATRICIAL();
         }
         //WRITE_EEPROM(0X00,J);
         lcd_gotoxy(1,1);
         PRINTF(LCD_PUTC,"ULTIMO GUARDADO \n%02u              ",READ_EEPROM(0X00));
         DELAY_MS(1000);
      }
      DELAY_MS(VELOCIDAD);
   }
}
