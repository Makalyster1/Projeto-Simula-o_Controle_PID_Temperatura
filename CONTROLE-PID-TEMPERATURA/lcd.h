/* 
 * File:   main.c
 * 
 * Autor: St�fany Coura Coimbra
 * Matr�cula: 2019008562
 * Universidade Federal de Itajub� - Unifei
 * Campus Itajub�
 * Disciplina: Programa��o Embarcada
 * 
 * PROGRAMA: SIMULA��O DO CONTROLE PID DA TEMPERATURA DE UM PROCESSO
 * 
 * Created on 11 de Junho de 2020, 16:58
 */

#define LENA  PORTEbits.RE1
#define LDAT  PORTEbits.RE2
#define LPORT PORTD


#define L_ON	0x0F
#define L_OFF	0x08
#define L_CLR	0x01
#define L_L1	0x80
#define L_L2	0xC0
#define L_L3	0x90
#define L_L4    0xD0
#define L_CR	0x0F		
#define L_NCR	0x0C	

#define L_CFG   0x38

void lcd_init(void);
void lcd_cmd(unsigned char val); 
void lcd_dat(unsigned char val);
void lcd_str(const char* str);

