## C++ MySQL


### USAGE

 Connecting to Database

```C++
    DB::Database *database = new DB::Database("IP", "PORT", "USERNAME", "PASSWORD", "DB_NAME");
```
```C++
    DB::Database *database = new DB::Database();
    database->Connect("IP", "PORT", "USERNAME", "PASSWORD");
    database->SetDatabase("DB_NAME");
```
Closing connection
```C++
    database->Close();
```
 Executing queries

```C++
    database->Execute(" CREATE USER 'example'@'localhost' IDENTIFIED BY 'password';");
```
 Getting data
```C++
    vector<vector<string>> Data;
    Data = database->Execute("SELECT * FROM example", 3 //Column size );
    /*  database->Execute() OUTPUT
       [0] [1] ["exampleName1"] ["SomeData1"]
       [1] [2] ["exampleName2"] ["SomeData2"]
       [2] [3] ["exampleName3"] ["SomeData3"]
       ...
    */
```
Getting data (prepared statement)
```C++
    vector<vector<string>> MyData;
    MyData = database->Get("SELECT * FROM example WHERE id=?", { "I:28" }, 3 //Column size );
    /*  database->Get() OUTPUT
       [0] [28] ["name"] ["username"]
    */
```
```C++
    vector<vector<string>> MyData;
    MyData = database->Get("SELECT * FROM example", 3  //Column size );
    /*  database->Get() OUTPUT
       [0] [1] ["name1"] ["username1"]
       [1] [2] ["name2"] ["username2"]
       [2] [3] ["name3"] ["username3"]
       ...
    */
```
Inserting data (prepared statement)
```C++
    // S: String 
    // I: Integer  
    database->InsertS("example(name,username,age)", { "S:Clotho","S:ClothoQ","I:99" });
```
```C++
    database->Insert("INSERT INTO example(name,username,age) VALUES (?,?,?)", { "S:Clotho","S:ClothoQ","I:99" });
```
 Updating data (prepared statement)
 ```C++
    database->Update("UPDATE example SET name=? WHERE id=?", { "S:NewClotho" , "I:2" });
```
Deleting data(prepared statement)
 ```C++
    database->Delete("DELETE FROM example WHERE id=?", { "I:1" });
```

### Quick Start
```C++
    #include "Database.h"

    using namespace std;
    using namespace DB;
     
    int main(void) {
        vector<vector<string>> MyData;
	   
        Database *database = new Database("IP", "PORT", "USERNAME", "PASSWORD", "DB_NAME");
        
        MyData = database->Get("SELECT * FROM test", 3);
        /* database->Get() OUTPUT
	         [0] [1] ["name1"] ["username1"]
           [1] [2] ["name2"] ["username2"]
           [2] [3] ["name3"] ["username3"]
           ...
        */
	    
        for (int a = 0; a < MyData.size(); a++) {
          for (int c = 0; c < MyData[a].size(); c++) {
             cout << MyData[a][c] + " - ";
          } cout << " " << endl;
        }
    }
```
