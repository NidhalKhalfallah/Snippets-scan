#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <linux/wireless.h>

int main() {
    //connect to a network that has a name and a password
    struct iwreq iwr;
    memset(&iwr, 0, sizeof(iwr));
    strncpy(iwr.ifr_name, "wlan0", sizeof(iwr.ifr_name));
    iwr.u.data.name = &iwr.ifr_name[0];
    iwr.u.data.length = sizeof(iwr.ifr_name);
    iwr.u.data.flags = IW_FLAG_BROADCAST | IW_FLAG_16_BIT_ADDR;
    iwr.u.data.filter_policy = IW_FILTER_TYPE_ACCEPT | IW_FILTER_TYPE_DENY;
    iwr.u.data.class_mask = IW_CLASS_MISCELLANEOUS;
    iwr.u.data.class_esr = IW_CLASS_PERMANENT;
    iwr.u.data.essid = IW_ESSID_NULL;
    iwr.u.essid.length = 0;
    iwr.u.essid.pointer = NULL;
    iwr.u.ap_addr.sa_family = ARPHRD_ETHER;
    iwr.u.ap_addr.sa_data[0] = 0x02;
    iwr.u.ap_addr.sa_data[1] = 0x01;
    iwr.u.ap_addr.sa_data[2] = 0x00;
    iwr.u.ap_addr.sa_data[3] = 0x5e;
    iwr.u.ap_addr.sa_data[4] = 0x00;
    iwr.u.ap_addr.sa_data[5] = 0x5e;
    iwr.u.ap_addr.sa_data[6] = 0x00;
    iwr.u.ap_addr.sa_data[7] = 0x5e;
    iwr.u.ap_addr.sa_data[8] = 0x00;
    iwr.u.ap_addr.sa_data[9] = 0x5e;
    iwr.u.ap_addr.sa_data[10] = 0x00;
    iwr.u.ap_addr.sa_data[11] = 0x5e;
    iwr.u.ap_addr.sa_data[12] = 0x00;
    