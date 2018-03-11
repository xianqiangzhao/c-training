#include <stdio.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char **args) {

    char *hostname = "css-eblog.com";
    struct addrinfo hints, *res;
    struct in_addr addr;
    int err;

    memset(&hints, 0, sizeof(hints));
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_family = AF_INET;

    if ((err = getaddrinfo(hostname, NULL, &hints, &res)) != 0) {
        printf("error %d\n", err);
        return 1;
    }

    addr.s_addr= ((struct sockaddr_in *)(res->ai_addr))->sin_addr.s_addr;

    printf("ip addres: %s\n", inet_ntoa(addr));

    // 取得した情報を解放
    freeaddrinfo(res);

    return 0;
}