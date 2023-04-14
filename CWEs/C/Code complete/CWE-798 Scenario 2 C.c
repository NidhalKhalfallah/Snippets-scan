#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <linux/wireless.h>

int main() {
    //connect to a network that has a name and a password
char *network = "YOUR_NETWORK_NAME";
    char *password = "YOUR_PASSWORD";

    //create a socket to communicate with the network manager
    int sockfd;
    struct ifreq ifr;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    strncpy(ifr.ifr_name, network, IFNAMSIZ-1);
    
	//set the interface up and assign it an IP address (192.168.0.3) 
	ioctl(sockfd, SIOCGIFFLAGS, &ifr);   //get current flags of interface (up or down) 

	printf("%d",ifr.ifr_flags);
	//set the interface up 
	ifr.ifr_flags |= IFF_UP; 

	printf("%d",ifr.ifr_flags);

    //assign it an IP address (192.168.0.3) 
    if(ioctl(sockfd, SIOCSIFFLAGS, &ifr) < 0){   //set flags of interface to up and assign it an IP address (192.168.0.3)  
        printf("Error setting interface %s UP", network);
        return 1;
    }

	//set the interface up 
	ifr.ifr_flags |= IFF_UP; 

	printf("%d",ifr.ifr_flags);

    //assign it an IP address (192.168.0.3) 
    if(ioctl(sockfd, SIOCSIFADDR, &ifr) < 0){   //set flags of interface to up and assign it an IP address (192.168.0.3)  
        printf("Error setting interface %s UP"
                , network);
        return 1;
    }

     //create a socket to communicate with the network manager 
     int sockfd2 = socket(AF_INET, SOCK_DGRAM, 0); 

     strncpy(ifr.ifr_name, network, IFNAMSIZ-1); 

      struct iwreq wrq;                               /* Structure for wireless settings */          memset(&wrq, 0x00, sizeof(struct iwreq));         strncpy(wrq.ap_addr,"\x00\x00\x00\x00",6);            ioctl(sockfd2, SIOCGIWAPLIST , &wrq );           char *mac = wrq . ap_addr ;             printf("%02X:%02X:%02X:%02X:%02X:%02X",mac[0],mac[1],mac[2],mac[3],mac[4],mac[5]);


    //connect to the network
    if(ioctl(sockfd, SIOCSIWESSID, &ifr) < 0){   //set interface essid 
        printf("Error setting interface %s UP"
                , network);
        return 1;
    }

	//set the interface up 
	ifr.ifr_flags |= IFF_UP; 

	printf("%d",ifr.ifr_flags);

    //assign it an IP address (192.168.0.3) 
    if(ioctl(sockfd, SIOCSIFFLAGS, &ifr) < 0){   //set flags of interface to up and assign it an IP address (192.168.0.3)  
        printf("Error setting interface %s UP"
                , network);
        return 1;         }     ioctl( sockfd2, SIOCGIWAPLIST , &wrq );           char *mac = wrq . ap_addr ;             printf("%02X:%02X:%02X:%02X:%02X:%02X"

      ,mac[0],mac[1],mac[2],mac[3],mac [4] , mac [ 5 ] );            close( sockfd );                                          close( sockfd2 );                                          return 0 ;}


