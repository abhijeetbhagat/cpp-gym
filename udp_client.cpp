#include "udp_socket.h"

// Driver code
int main() {
    UdpListenerSocket socket;

    socket.send_to("127.0.0.1", 1150, "yo!");
    printf("Hello message sent.\n");

    return 0;
}
