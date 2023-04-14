#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define WPA_SUPPLICANT_CONF "/etc/wpa_supplicant/wpa_supplicant.conf"

int connect_wifi(const char *ssid, const char *password) {
    pid_t pid;
    int status;
    int ret = 0;

    pid = fork();
    if (pid == -1) {
        perror("fork");
        return -1;
    } else if (pid == 0) {
        execlp("wpa_supplicant", "wpa_supplicant", "-B", "-Dnl80211", "-c", WPA_SUPPLICANT_CONF, "-i", "wlan0", NULL);
        perror("exec");
        exit(1);
    }

    sleep(1);

    if (waitpid(pid, &status, WNOHANG) == 0) {
        char cmd[256];
        snprintf(cmd, sizeof(cmd), "wpa_cli -i wlan0 scan");
        system(cmd);
        sleep(1);
        snprintf(cmd, sizeof(cmd), "wpa_cli -i wlan0 add_network");
        system(cmd);
        snprintf(cmd, sizeof(cmd), "wpa_cli -i wlan0 set_network 0 ssid '\"%s\"'", ssid);
        system(cmd);
        snprintf(cmd, sizeof(cmd), "wpa_cli -i wlan0 set_network 0 psk '\"%s\"'", password);
        system(cmd);
        snprintf(cmd, sizeof(cmd), "wpa_cli -i wlan0 enable_network 0");
        system(cmd);
        snprintf(cmd, sizeof(cmd), "wpa_cli -i wlan0 save_config");
        system(cmd);
    } else {
        ret = -1;
    }

    return ret;
}

int main() {
    const char *ssid = "MyWifiNetwork";
    const char *password = "MyWifiPassword";
    if (connect_wifi(ssid, password) == 0) {
        printf("Connected to WiFi network successfully.\n");
    } else {
        printf("Failed to connect to WiFi network.\n");
    }
    return 0;
}