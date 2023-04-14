def extract_substring(length: int, string: str) -> str:
  #Extract a substring of given length from the string
  if len(string) < length:
    return string
  else:
    return string[:length]