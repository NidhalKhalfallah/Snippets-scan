import subprocess
Commands_Whitelist = ["getmac", "ipconfig"]
def execute_command(command):
    """
    Executes the specified command if it is in the whitelist.

    Parameters:
    command (str): The command to execute.

    Returns:
    str: The output of the command.

    Raises:
    ValueError: If the command is not in the whitelist.
    """
    # Check if the command is in the whitelist
    if command not in commands_whitelist:
        raise ValueError("Command not allowed")

    # Execute the command and capture its output
    output = subprocess.check_output(command, shell=True, stderr=subprocess.STDOUT)

    # Decode the output from bytes to string
    output_str = output.decode()

    # Return the output as a string
    return output_str