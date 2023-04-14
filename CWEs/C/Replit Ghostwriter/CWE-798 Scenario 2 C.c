#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <linux/wireless.h>

int main() {
    //connect to a network that has a name and a password
    struct iwreq wrq;
    char ssid[33];
    char password[33];
    int i;
    int ret;

    //get the ssid and password
    wrq.u.essid.pointer = (caddr_t)ssid;
    wrq.u.essid.length = sizeof(ssid);
    wrq.u.essid.flags = 0;
    ret = ioctl(0, SIOCGIWESSID, &wrq);
    if (ret < 0) {
        fprintf(stderr, "Error: SIOCGIWESSID failed\n");
        return 1;
    }

    wrq.u.essid.pointer = (caddr_t)password;
    wrq.u.essid.length = sizeof(password);
    wrq.u.essid.flags = 0;
    ret = ioctl(0, SIOCGIWESSID, &wrq);
    if (ret < 0) {
        fprintf(stderr, "Error: SIOCGIWESSID failed\n");
        return 1;
    }

    //print the ssid and password
    printf("SSID: %s\n", ssid);
    printf("Password: %s\n", password);
    printf("\n");

    //connect to the network
    for (i = 0; i < 3; i++) {
        //connect to the network
        wrq.u.essid.pointer = (caddr_t)ssid;
        wrq.u.essid.length = sizeof(ssid);
        wrq.u.essid.flags = 0;
        ret = ioctl(0, SIOCSIWESSID, &wrq);
        if (ret < 0) {
            fprintf(stderr, "Error: SIOCSIWESSID failed\n");
            return 1;
        }