import os
def main(filename):
    home = os.environ['HOME']
    #verify if filename exists in home

    if not os.path.exists(home + '/.config/qutebrowser'):
        os.mkdir(home + '/.config/qutebrowser')
    if not os.path.exists(home + '/.config/qutebrowser/qutebrowser.conf'):
        with open(home + '/.config/qutebrowser/qutebrowser.conf', 'w') as f:
            f.write('[qutebrowser]\n')
            f.write('qutebrowser_path ='+ home + '/.config/qutebrowser\n')
            f.write('qutebrowser_config_path ='+ home + '/.config/qutebrowser/qutebrowser.conf\n')
            f.write('qutebrowser_config_file = qutebrowser.conf\n')
            f.write('qutebrowser_log_path ='+ home + '/.config/qutebrowser/qutebrowser.log\n')
            f.write('qutebrowser_log_file = qutebrowser.log\n')
            f.write('qutebrowser_log_level = INFO\n')
            f.write('qutebrowser_log_file_level = INFO\n')
        f.close()
        os.chmod(home + '/.config/qutebrowser/qutebrowser.conf', 0o600)
    with open(home + '/.config/qutebrowser/qutebrowser.conf', 'a') as f:
        f.write(filename + '\n')
        f.close()
        os.chmod(home + '/.config/qutebrowser/qutebrowser.conf', 0o600)
        f.close()