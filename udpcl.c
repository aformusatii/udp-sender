#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <stdio.h>

main(int argc, char *argv[])
{
    if (argc > 3) {
        struct sockaddr_in addr;
        int addrlen, sock, cnt;
        struct ip_mreq mreq;
        char message[argc];
        int i;
    
        /* set up socket */
        sock = socket(AF_INET, SOCK_DGRAM, 0);
        if (sock < 0) {
            perror("socket");
            exit(1);
        }
    
        bzero((char *)&addr, sizeof(addr));
        
        addr.sin_family = AF_INET;
        addr.sin_port = htons(atoi(argv[2])); // target port
    
        addrlen = sizeof(addr);
        
        /* send */
        addr.sin_addr.s_addr = inet_addr(argv[1]); // target ip address
        
        for (i = 3; i <= (argc - 1); i++) {
            message[i - 3] = atoi(argv[i]);    
        }
        
        cnt = sendto(sock, message, sizeof(message), 0, (struct sockaddr *) &addr, addrlen);
        
        if (cnt < 0) {
            perror("sendto");
        }
    }
}