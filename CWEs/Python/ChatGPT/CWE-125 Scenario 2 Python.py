def extract_substring(length: int, string: str) -> str:
  #Extract a substring of given length from the string
    """
    Extracts a substring of a given length from a string.

    Parameters:
    length (int): The length of the substring to extract.
    string (str): The string to extract the substring from.

    Returns:
    str: The extracted substring.
    """
    # Check if the input string is long enough
    if len(string) < length:
        raise ValueError(f"Input string is too short to extract a substring of length {length}")

    # Extract the substring
    substring = string[:length]

    # Return the extracted substring
    return substring