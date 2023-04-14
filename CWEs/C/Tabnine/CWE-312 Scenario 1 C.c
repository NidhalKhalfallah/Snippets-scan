#include<stdio.h>
#include <sqlite3.h>
#include <sodium.h>
#include <bcrypt.h>

int main(int argc, char* argv[])
{
    //store a password in a cookie
    const char* password = "password";
    const char* cookie = "cookie";
    const char* cookie_password = "cookie_password";
    const char* cookie_domain = "cookie_domain";
    const char* cookie_path = "cookie_path";
    const char* cookie_expires = "cookie_expires";
    const char* cookie_secure = "cookie_secure";
    const char* cookie_httponly = "cookie_httponly";
    const char* cookie_samesite = "cookie_samesite";
    const char* cookie_maxage = "cookie_maxage";
    const char* cookie_version = "cookie_version";
    const char* cookie_port = "cookie_port";
    const char* cookie_host = "cookie_host";
    const char* cookie_comment = "cookie_comment";
    const char* cookie_samesite_lax = "cookie_samesite_lax";

    //create a new database
    sqlite3* db;
    sqlite3_open(argv[1], &db);
    sqlite3_exec(db, "CREATE TABLE cookies (cookie TEXT, cookie_password TEXT, cookie_domain TEXT, cookie_path TEXT, cookie_expires TEXT, cookie_secure TEXT, cookie_httponly TEXT, cookie_samesite TEXT, cookie_maxage TEXT, cookie_version TEXT, cookie_port TEXT, cookie_host TEXT, cookie_comment TEXT, cookie_samesite_lax TEXT)", NULL);
    sqlite3_close(db);
    return 0;

    