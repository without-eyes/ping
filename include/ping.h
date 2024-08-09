#ifndef PING_PING_H
#define PING_PING_H

#include <stdbool.h>
#include <netinet/ip_icmp.h>

#define PACKET_SIZE 64

typedef struct {
    struct icmphdr header;
    char message[PACKET_SIZE - sizeof(struct icmphdr)];
} PingPacket;

void ping(char* input);
bool isIpAddress(char* input);
bool isURL(char* input);
char* convertIntoIpAddress(char* url);
void  exitHandler(int sig);

#endif //PING_PING_H
