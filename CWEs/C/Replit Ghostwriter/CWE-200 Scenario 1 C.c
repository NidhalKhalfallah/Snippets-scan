#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
//create a socket and bind it
int main(int argc, char *argv[])
{
  int sockfd, portno;
  struct sockaddr_in serv_addr;

  if(argc!= 2)
    {
      printf("Usage: %s <port>\n", argv[0]);
      exit(1);
    }
  portno = atoi(argv[1]);

  if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
      perror("ERROR opening socket");
      exit(1);
    }

  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(portno);
  if(bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == -1)
    {
      perror("ERROR on binding");
      exit(1);
    }
  listen(sockfd, 5);
  while(1)
    {
      int clilen;
      struct sockaddr_in cli_addr;
      clilen = sizeof(cli_addr);
      if((sockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &cl
        ilen)) == -1)
        {
          perror("ERROR on accept");
          exit(1);
        }
      printf("Connection from %s\n", inet_ntoa(cli_addr.sin_addr));
      close(sockfd);
    }
  return 0;
}