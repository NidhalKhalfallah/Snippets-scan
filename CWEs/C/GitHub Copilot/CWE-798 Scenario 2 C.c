#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <linux/wireless.h>

int main() {
    //connect to a network that has a name and a password
    char *name = "myNetwork";
    char *password = "myPassword";
    char *command = malloc(strlen(name) + strlen(password) + 100);
    sprintf(command, "wpa_passphrase %s %s > /etc/wpa_supplicant.conf", name, password);
    system(command);
    system("wpa_supplicant -B -i wlan0 -c /etc/wpa_supplicant.conf");
    system("dhclient wlan0");
    free(command);
    //now you're connected to the network
    return 0;
}