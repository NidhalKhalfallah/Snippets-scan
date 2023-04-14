def extract_substring(length: int, string: str) -> str:
  #Extract a substring of given length from the string
  #string: string to extract from
  #length: length of substring to extract
  #return: substring
  #Example:
  #>>> extract_substring(3, "abcdefghijklmnopqrstuvwxyz")
  #'def'
  return string[:length]