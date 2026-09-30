#include <iostream>
#include <sqlite3.h>

using namespace std;

sqlite3 *DB;

void createTable()
{
    string sql =
        "CREATE TABLE IF NOT EXISTS VAULT("
        "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
        "TITLE TEXT NOT NULL,"
        "SECRET TEXT NOT NULL);";

    char *msgError;

    if (sqlite3_exec(DB, sql.c_str(), NULL, 0, &msgError) != SQLITE_OK)
        cout << "Table Creation Failed\n";
    else
        cout << "Table Ready\n";
}

void addRecord()
{
    string title, secret;

    cin.ignore();
    cout << "Enter Title: ";
    getline(cin, title);

    cout << "Enter Secret: ";
    getline(cin, secret);

    string sql =
        "INSERT INTO VAULT (TITLE,SECRET) VALUES('" +
        title + "','" + secret + "');";

    char *msgError;

    if (sqlite3_exec(DB, sql.c_str(), NULL, 0, &msgError) != SQLITE_OK)
        cout << "Insert Failed\n";
    else
        cout << "Record Added\n";
}

static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    for (int i = 0; i < argc; i++)
    {
        cout << azColName[i] << ": "
             << (argv[i] ? argv[i] : "NULL") << endl;
    }
    cout << "------------------\n";
    return 0;
}

void viewRecords()
{
    string sql = "SELECT * FROM VAULT;";

    char *msgError;

    if (sqlite3_exec(DB, sql.c_str(), callback, NULL, &msgError) != SQLITE_OK)
        cout << "Fetch Failed\n";
}

void searchRecord()
{
    int id;
    cout << "Enter ID: ";
    cin >> id;

    string sql =
        "SELECT * FROM VAULT WHERE ID=" +
        to_string(id) + ";";

    char *msgError;

    if (sqlite3_exec(DB, sql.c_str(), callback, NULL, &msgError) != SQLITE_OK)
        cout << "Search Failed\n";
}

void updateRecord()
{
    int id;
    string secret;

    cout << "Enter ID: ";
    cin >> id;

    cin.ignore();

    cout << "Enter New Secret: ";
    getline(cin, secret);

    string sql =
        "UPDATE VAULT SET SECRET='" +
        secret +
        "' WHERE ID=" +
        to_string(id) + ";";

    char *msgError;

    if (sqlite3_exec(DB, sql.c_str(), NULL, 0, &msgError) != SQLITE_OK)
        cout << "Update Failed\n";
    else
        cout << "Record Updated\n";
}

void deleteRecord()
{
    int id;

    cout << "Enter ID: ";
    cin >> id;

    string sql =
        "DELETE FROM VAULT WHERE ID=" +
        to_string(id) + ";";

    char *msgError;

    if (sqlite3_exec(DB, sql.c_str(), NULL, 0, &msgError) != SQLITE_OK)
        cout << "Delete Failed\n";
    else
        cout << "Record Deleted\n";
}

int main()
{
    sqlite3_open("vault.db", &DB);

    createTable();

    int choice;

    do
    {
        cout << "\n===== SECRET VAULT =====\n";
        cout << "1. Add Record\n";
        cout << "2. View Records\n";
        cout << "3. Search Record\n";
        cout << "4. Update Record\n";
        cout << "5. Delete Record\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addRecord();
            break;
        case 2:
            viewRecords();
            break;
        case 3:
            searchRecord();
            break;
        case 4:
            updateRecord();
            break;
        case 5:
            deleteRecord();
            break;
        }

    } while (choice != 0);

    sqlite3_close(DB);

    return 0;
}