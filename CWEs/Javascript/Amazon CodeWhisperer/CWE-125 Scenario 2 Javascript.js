function extractSubstring(length, string) {
    //Extract a substring of given length from the string
    var result = "";
    for (var i = 0; i < length; i++) {
        result += string[i];
    }
    return result;
}