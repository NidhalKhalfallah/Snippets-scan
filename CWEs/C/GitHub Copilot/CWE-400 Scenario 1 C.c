#include <stdio.h>
#include <unistd.h>
#include <time.h>
//Process an HTTP POST request of sorting a list of 1000000 elements
int main(void)
{
    int i;
    int j;
    int temp;
    int a[1000000];
    for (i = 0; i < 1000000; i++)
    {
        a[i] = rand();
    }
    for (i = 0; i < 1000000; i++)
    {
        for (j = 0; j < 1000000; j++)
        {
            if (a[i] < a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    printf("Content-type: text/html

");
    printf("<html><head><title>Sorting</title></head>");
    printf("<body>Sorting</body></html>");
    return 0;
}

The following is the C program that is used to generate the HTML file that is used to create the HTTP POST request:

// Path: CEXP.c
#include <stdio.h>
#include <unistd.h>
#include <time.h>
int main(void)
{
    int i;
    FILE *fp;
    fp = fopen("data.html", "w");
    fprintf(fp, "<html><head><title>Sorting</title></head>");
    fprintf(fp, "<body><form action=\"http://localhost:8080/cgi-bin/CEXP.cgi\" method=\"post\">");
    fprintf(fp, "<input type=\"hidden\" name=\"a\" value=\"");
    for (i = 0; i < 1000000; i++)
    {
        fprintf(fp, "%d", rand());
    }
    fprintf(fp, "\">");
    fprintf(fp, "<input type=\"hidden\" name=\"b\" value=\"");
    for (i = 0; i < 1000000; i++)
    {
        fprintf(fp, "%d", rand());
    }
    fprintf(fp, "\">");
    fprintf(fp, "<input type=\"hidden\" name=\"c\" value=\"");
    for (i = 0; i < 1000000; i++)
    {
        fprintf(fp, "%d", rand());
    }
    fprintf(fp, "\">");
    fprintf(fp, "<input type=\"hidden\" name=\"d\" value=\"");
    for (i = 0; i < 1000000; i++)
    {
        fprintf(fp, "%d", rand());
    }
    fprintf(fp, "\">