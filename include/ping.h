#ifndef PING_PING_H
#define PING_PING_H

#include <stdbool.h>

void ping(char* input);

bool isIpAddress(char* input);

bool isURL(char* input);

char* convertIntoIpAddress(char* url);

#endif //PING_PING_H
