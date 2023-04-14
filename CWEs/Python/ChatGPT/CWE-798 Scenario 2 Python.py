import wifi
#connect to a network that has a name and a password
def connect_to_network(network_name, password):
    wifi.connect(network_name, auth=(wifi.WIFI_AUTH_WPA2, password))
network_name = "my_wifi_network"
network_password = "my_wifi_password"

connect_to_network(network_name, network_password)