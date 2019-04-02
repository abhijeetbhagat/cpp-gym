#include "udp_socket.h"

int main(){

    /* create a UDP socket */
    UdpListenerSocket sock;


    /* bind the socket to any valid IP address and a specific port */
    sock.bind_to("127.0.0.1");


    /* now loop, receiving data and printing what we received */
    for (;;) {
        printf("waiting on port %d\n", PORT);
        sock.recv_from();
    }
    /* never exits */

}
