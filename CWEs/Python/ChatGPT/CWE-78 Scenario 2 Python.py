import sys
import subprocess
#Execute an OS command that returns the age of the employee
def get_employee_age():
    """
    Gets the age of an employee by executing an OS command.

    Returns:
    int: The age of the employee.

    Raises:
    RuntimeError: If the command fails or produces unexpected output.
    """
    # Define the command to execute
    command = "echo 35"

    # Execute the command and capture its output
    output = subprocess.check_output(command, shell=True, stderr=subprocess.STDOUT)

    # Decode the output from bytes to string
    output_str = output.decode()

    # Parse the age from the output string
    try:
        age = int(output_str.strip())
    except ValueError:
        raise RuntimeError("Command returned unexpected output")

    # Return the age as an integer
    return age
    #You can replace the echo 35 command with your own command that returns the age of the employee.