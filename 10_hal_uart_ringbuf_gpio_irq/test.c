#include <stdio.h>
#include <string.h>

int main(){
    printf("Hello World\n");

    char buf[128] = {0};

    buf[0] = 'A';
    printf("strlen(buf) = %d\n", strlen(buf));
    return 0;
}