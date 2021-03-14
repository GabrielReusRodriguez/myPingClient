/**
 * myPing.c  Se ejecuta como ./myPing <hostname>
 * 
 * Author: Gabriel Reus Rodriguez
 * 
 * 
 * */

#ifndef ICMP_FUNCTIONS_H
#define ICMP_FUNCTIONS_H

void send_ping(int ping_sockfd, struct sockaddr_in *ping_addr, 
                char *ping_dom, char *ping_ip, char *rev_host) ;
#endif