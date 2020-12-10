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

#include "rtc.h"
#include "i2c.h"
#include "pic18f4520.h"

volatile char date[10];
volatile char time[10];


unsigned char getd(unsigned char nn)
{
    return ((nn & 0xF0)>>4)+0x30;
}

unsigned char getu(unsigned char nn)
{
    return (nn  & 0x0F)+0x30;
}

//--------------------- Reads time and date information from RTC (PCF8563)
void rtc_r(void) 
{
    unsigned char tmp;

    i2c_start();
    i2c_wb(0xD0);
    i2c_wb(0);

    i2c_start();
    i2c_wb(0xD1);
    tmp= 0x7F & i2c_rb(1); //segundos
    time[5]=':';
    time[6]=getd(tmp);
    time[7]=getu(tmp);
    time[8]=0;

    tmp= 0x7F & i2c_rb(1); //minutos
    time[2]=':';
    time[3]=getd(tmp);
    time[4]=getu(tmp);

    tmp= 0x3F & i2c_rb(1); //horas
    time[0]=getd(tmp);
    time[1]=getu(tmp);

    i2c_rb(1); //dia semana

    tmp= 0x3F & i2c_rb(1); //dia
    date[0]=getd(tmp);
    date[1]=getu(tmp);


    tmp= 0x1F & i2c_rb(1); //mes
    date[2]='/'; 
    date[3]=getd(tmp);
    date[4]=getu(tmp);

    tmp=  i2c_rb(0); //ano
    date[5]='/';
    date[6]=getd(tmp);
    date[7]=getu(tmp);
    date[8]=0;

    i2c_stop();

}

