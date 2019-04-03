#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<iostream>
#include<netdb.h>
#include<cstdlib>
#include<cstdio>
#include<unistd.h>
#include<cstring>

#define  PORT 1150
#define  BUFSIZE 2048
class UdpListenerSocket {
    private:
        sockaddr_in myaddr;      /* our address */
        sockaddr_in remaddr;     /* remote address */
        socklen_t addrlen = sizeof(remaddr);            /* length of addresses */
        int recvlen;                    /* # bytes received */
        int fd;                         /* our socket */
        unsigned char buf[BUFSIZE];     /* receive buffer */

    public:
        UdpListenerSocket();
        ~UdpListenerSocket();

        int bind_to(std::string const& ip);
        void recv_from();
        void send_to(std::string const& ip, int const& port, std::string const& msg);
};

UdpListenerSocket::UdpListenerSocket(){
    if ((fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("cannot create socket\n");
        throw;
    }
}

UdpListenerSocket::~UdpListenerSocket(){
    close(fd);
}

int UdpListenerSocket::bind_to(std::string const& ip) {
    memset((char *)&myaddr, 0, sizeof(myaddr));
    myaddr.sin_family = AF_INET;
    inet_pton(AF_INET, ip.c_str(), &myaddr.sin_addr);
    //myaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    myaddr.sin_port = htons(PORT);

    if (bind(fd, (struct sockaddr *)&myaddr, sizeof(myaddr)) < 0) {
        perror("bind failed");
        return 0;
    }
}

void UdpListenerSocket::recv_from(){
    recvlen = recvfrom(fd, buf, BUFSIZE, 0, (struct sockaddr *)&remaddr, &addrlen);
    printf("received %d bytes\n", recvlen);
    if (recvlen > 0) {
        buf[recvlen] = 0;
        printf("received message: \"%s\"\n", buf);
    }
}

void UdpListenerSocket::send_to(std::string const& ip, int const& port, std::string const& msg){ 
  sockaddr_in remaddr;
  memset((char*)&remaddr, 0, sizeof remaddr);
  remaddr.sin_family = AF_INET;
  inet_pton(AF_INET, ip.c_str(), &remaddr.sin_addr);
  remaddr.sin_port = htons(port);

  sendto(fd, msg.c_str(), msg.size(), MSG_CONFIRM, (sockaddr *)&remaddr, sizeof remaddr);
}
