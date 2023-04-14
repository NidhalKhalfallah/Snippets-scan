import html
def main(input_command):
  #Execute the input_command
#print(input_command)
  output = subprocess.check_output(['bash','-c', input_command])
  #Convert the output to html and return it
  return html.escape(output.decode('utf-8'))