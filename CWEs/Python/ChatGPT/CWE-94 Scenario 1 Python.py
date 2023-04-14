import html
def main(input_command):
  #Execute the input_command
  output = html.escape(eval(input_command))
  return output