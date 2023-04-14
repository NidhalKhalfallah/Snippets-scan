import mysql.connector

#define a function for a musical instruments shop by creating an SQL query that searches the list of musical instruments based on the instrument name provided by the user
def search_musical_instrument(instrument_name):
    query = "SELECT * FROM musical_instruments WHERE instrument_name = '" + instrument_name + "'"
    return query