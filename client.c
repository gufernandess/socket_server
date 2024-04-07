#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 7658

int main(int argc, char const* argv[]) {
  int status, client_fd;
  struct sockaddr_in serv_addr;
  char buffer[1024] = {0};
  char ip_addr[16];

  client_fd = socket(AF_INET, SOCK_STREAM, 0);

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(PORT);

  printf("\nInsira o endereço IP: ");
  fgets(ip_addr, sizeof(ip_addr), stdin);
  ip_addr[strcspn(ip_addr, "\n")] = '\0';

  inet_pton(AF_INET, ip_addr, &serv_addr.sin_addr);

  connect(client_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

  read(client_fd, buffer, 1024 - 1);

  printf("%s\n", buffer);

  close(client_fd);

  return 0;
}
