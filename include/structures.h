/**
 * myPing.c  Se ejecuta como ./myPing <hostname>
 * 
 * Author: Gabriel Reus Rodriguez
 * 
 * 
 * */


#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <netinet/ip_icmp.h> 
#include "./include/constants.h"

struct ping_pkt{
        struct icmphdr hdr; //Cabecera  icmp
        char msg[PING_PKT_SIZE - sizeof( struct icmphdr )];
    };

    

#endif