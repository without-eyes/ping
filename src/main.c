#include <stdio.h>
#include "../include/ping.h"

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

int main(int argc, char* argv[]) {
    if (argc == 1) {
        ping(argv[0]);
    } else {
        printf("First argument must be equals to 1");
    }

    return 0;
}
