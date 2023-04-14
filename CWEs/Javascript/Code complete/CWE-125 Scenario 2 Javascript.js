function extractSubstring(length, string) {
  //In javascript language, Extract a substring of given length from the string
  .
  //If the substring is longer than the string, return the entire string.
  //If length is 0, return an empty string.

  if (length === 0) {
    return "";
  } else if (string.length < length) {
    return string;
  } else {
    var subString = "";

    for (var i = 0; i < length; i++) {
      subString += string[i];
    }

    return subString;

  }

  
}
