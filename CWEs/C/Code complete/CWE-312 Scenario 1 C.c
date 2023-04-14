#include<stdio.h>
#include <sqlite3.h>
#include <sodium.h>
#include <bcrypt.h>

int main(int argc, char* argv[])
{
    //store a password in a cookie
char cookie[200];
    bcrypt_gensalt(10, NULL, (char*)cookie);

    //store the hashed password in a database
    sqlite3 *db;
    int rc = sqlite3_open("passwords.db", &db);

    if(rc) {
        fprintf(stderr, "Can't open database: %s", sqlite3_errmsg(db));
        return(0);
    }

    char *sql = "CREATE TABLE IF NOT EXISTS passwords (username TEXT PRIMARY KEY, password TEXT)";

    rc = sqlite3_exec(db, sql, NULL, 0, NULL);

    if(rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s", sqlite3_errmsg(db));
        return(0);
    }

    //create a cookie that stores the hashed password in database
    char *hashed = (char*)malloc((sizeof(char) * strlen(cookie)) + 1);

    bcrypt_hashpw("password", cookie, hashed);

    printf("%s", hashed);

    //store the cookie in a database
    sql = "INSERT INTO passwords VALUES ('username', 'hashed')";

    rc = sqlite3_exec(db, sql, NULL, 0, NULL);

    if(rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s", sqlite3_errmsg(db));
        return(0);
    }

    sqlite3_close(db);
}

