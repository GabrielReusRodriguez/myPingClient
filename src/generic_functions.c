/**
 * myPing.c  Se ejecuta como ./myPing <hostname>
 * 
 * Author: Gabriel Reus Rodriguez
 * 
 * 
 * */

//#include "./include/globals.h"

int  pingloop;

//Funcion de calculo de checksum. Recibo el buffer valor y el numero len de bytes que ocupa.
unsigned short checksum(void *valor, int len){
    
    unsigned short *buf = (unsigned short *)valor; //Un buffer de 2 bytes.
    unsigned int sum = 0;
    unsigned short result;

    //for ( sum = 0; len >1; len -= 2){
    //Sumamos todo el buffer byte a byte pero un short son 16 bits por lo que avanzamos de 2 en 2 bytes.
    for ( sum = 0; len >1; len -= 2){
        sum += *buf++; //(sum es de )
    }
    //Si nos queda 1 byte, le hacemos cast y lo sumamos.
    if ( len == 1 ) {
        sum += *(unsigned char *)buf;
    }

    sum  = ( sum >> 16 ) + (sum & 0xFFFF);
    sum += ( sum >> 16 );
    result = ~sum;
    return result;
    
}

// Interrupt handler 
void intHandler(int dummy) 
{ 
    pingloop=0; 
} 