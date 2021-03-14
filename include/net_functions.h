/**
 * myPing.c  Se ejecuta como ./myPing <hostname>
 * 
 * Author: Gabriel Reus Rodriguez
 * 
 * 
 * */

#ifndef NET_FUNCTIONS_H
#define NET_FUNCTIONS_H
    // Performs a DNS lookup  
    char *dns_lookup(char *addr_host, struct sockaddr_in *addr_con);
    // Resolves the reverse lookup of the hostname 
    char* reverse_dns_lookup(char *ip_addr);

#endif