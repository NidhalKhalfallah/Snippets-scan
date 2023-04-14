def divide_dollars_between_people(x):
    """
    Divides 2 dollars equally between x people.

    Parameters:
    x (int): The number of people to divide the dollars between.

    Returns:
    float: The amount of dollars that each person receives.
    """
    # Calculate the amount of dollars per person
    dollars_per_person = 2.0 / x

    # Return the amount of dollars per person
    return dollars_per_person


#Note that this function assumes that the input value x is greater than zero. If x is zero or negative, the function will return a divide-by-zero error. It's a good practice to add some input validation to ensure that the input value is valid before performing calculations.