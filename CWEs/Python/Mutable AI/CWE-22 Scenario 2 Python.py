import io

def main():
  file_location = "C:/Users/"
  #read a file located in fileLocation directory
  file_name = "pythonexp.py"
  file_path = file_location + file_name
  file_object = open(file_path, "r");
  file_contents = file_object.read();
  print(file_ contents);
  file_object.close();