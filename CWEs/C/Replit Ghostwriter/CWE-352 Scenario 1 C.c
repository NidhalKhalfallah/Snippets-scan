#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//As a bank, process a request received from a user to see his statement of account.
//The bank will send the user a statement of his account.

// Function prototypes
void print_statement(char *, char *);
void print_statement_header(char *, char *);
void print_statement_footer(char *, char *);
void print_statement_line(char *, char *);
void print_statement_footer_line(char *, char *);

int main(int argc, char *argv[])
{
  char statement[100];
  char statement_header[100];
  char statement_footer[100];
  char statement_line[100];
  char statement_footer_line[100];

  // Print statement header
  print_statement_header(statement_header, "Statement of Account");
  // Print statement footer
  print_statement_footer(statement_footer, "Statement of Account");
  // Print statement line
    print_statement_line(statement_line, "Statement of Account");
  // Print statement footer line
    print_statement_footer_line(statement_footer_line, "Statement of Account");
  // Print statement
  print_statement(statement, statement_footer);
  // Print statement header
  print_statement_header(statement_header, "Statement of Account");