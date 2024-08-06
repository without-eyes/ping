#include "../include/ping.h"
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <netdb.h>

/* Example of message:
Pinging google.com [142.251.214.142] with 32 bytes of data:
Reply from 142.251.214.142: bytes=32 time=15ms TTL=58
Reply from 142.251.214.142: bytes=32 time=13ms TTL=58
Reply from 142.251.214.142: bytes=32 time=15ms TTL=58
Reply from 142.251.214.142: bytes=32 time=15ms TTL=58

Ping statistics for 142.251.214.142:
    Packets: Sent = 4, Received = 4, Lost = 0 (0% loss),
Approximate round trip times in milli-seconds:
    Minimum = 13ms, Maximum = 15ms, Average = 14ms
*/

void ping(char* input) {
    char* ip;
    if (isIpAddress(input)) {
        ip = input;
        puts("ip");
    } else if (isURL(input)) {
        ip = convertIntoIpAddress(input);
        printf("url: %s\n", ip);
    } else {
        puts("Bad input!");
        return;
    }

    // send packets(loop of 4(or maybe more) echo requests)
    // mark the time
    // if:
    // 1) host available - receive respond;
    // 2 )host offline or doesn't accept icmp - no reply, inform
    // that it can be indication of network problem;
    // 3) packet doesn't reach the host within certain time -
    // inform of packet loss
    // print message
}

bool isIpAddress(char* input) {
    struct sockaddr_in sa;
    int result = inet_pton(AF_INET, input, &(sa.sin_addr));
    return result != 0;
}

bool isURL(char* input) {
    bool isURL = false;

    while (*input) {
        if (!(isalnum((unsigned char)*input) || strchr("-._~:/?#[]@!$&'()*+,;=%", *input))) {
            return false;
        }

        if (*input == '.') {
            isURL = true;
        }

        input++;
    }

    return isURL;
}

//char* convertIntoIpAddress(char* url) {
//    int hostname = gethostname(url, sizeof(url));
//    if (hostname == -1) return NULL;
//
//    struct hostent *host_entry = gethostbyname(url);
//    if (host_entry == NULL) return NULL;
//
//    char* ipBuffer = inet_ntoa(*((struct in_addr*)host_entry->h_addr_list[0]));
//    return ipBuffer;
//}
