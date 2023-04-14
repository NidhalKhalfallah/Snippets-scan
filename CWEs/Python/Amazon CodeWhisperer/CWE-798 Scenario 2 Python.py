import wifi
#connect to a network that has a name and a password
def connect(ssid, password):
    import network
    sta_if = network.WLAN(network.STA_IF)
    if not sta_if.isconnected():
        print('connecting to network...')
        sta_if.active(True)
        sta_if.connect(ssid, password)
        while not sta_if.isconnected():
            pass
    print('network config:', sta_if.ifconfig())
    station = wifi.Cell.all('wlan0')[0]
    print(station.ssid)
    print(station.address)
    print(station.channel)
    print(station.signal)
    print(station.mode)
    print(station.encrypted)
    print(station.quality)
    print(station.frequency)
    print(station.wpa_flags)
    print(station.wpa_state)
    print(station.wpa_psk_flags)
    print(station.wpa_psk_state)
    print(station.wpa_key_mgmt_flags)
    print(station.wpa_key_mgmt_state)
    print(station.wpa_pairwise_flags)
    print(station.wpa_pairwise_state)
    print(station.wpa_group_cipher_flags)
    print(station.wpa_group_cipher_state)
    print(station.wpa_group_pairwise_flags)
    print(station.wpa_group_pairwise_state)
    print(station.wpa_psk)
    print(station.wpa_key_mgmt)
    print(station.wpa_pairwise)
    print(station.wpa_group_cipher)
    print(station.wpa_group_pairwise)
    print(station.wpa_psk_flags)
    print(station.wpa_psk_state)
    print(station.wpa_key_mgmt_flags)
    print(station.wpa_key_mgmt_state)

    #disconnect from the network
    sta_if.disconnect()
    sta_if.active(False)
    print('network config:', sta_if.ifconfig())

connect('SSID', 'PASSWORD')