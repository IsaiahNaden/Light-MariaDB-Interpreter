#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

// Structure to represent a column
struct Column {
    string name;
    string type; // "INT" or "TEXT"
};

// Structure to represent a table
struct Table {
    string name;
    vector<Column> columns;
    vector<vector<string>> rows;
};

// Database class
class Database {
    string dbName;
    Table table;

public:
    // Create a database
    void createDatabase(const string& name) 
    {
        dbName = name;
        cout << "Database '" << dbName << "' created.\n";
    }

    // Create a table
    void createTable(const string& tableName, const vector<Column>& cols) 
    {
        table.name = tableName;
        table.columns = cols;
        cout << "Table '" << tableName << "' created.\n";
    }

    // Insert a row into the table
    void insertRow(const vector<string>& values)
    {
        table.rows.push_back(values);
        cout << "Row inserted.\n";
    }

    // View the table in CSV mode
    void viewTable() const 
    {
        cout << "Table: " << table.name << "\n";
        // Print column headers
        for (const auto& col : table.columns) 
        {
            cout << col.name << ",";
        }
        cout << "\n";

        // Print rows
        for (const auto& row : table.rows) 
        {
            for (const auto& value : row) 
            {
                cout << value << ",";
            }
            cout << "\n";
        }
    }

    // Write the table to a file in CSV format
    void writeToFile(const string& fileName) const {
        ofstream outFile(fileName);
        if (!outFile) {
            cerr << "Error opening file: " << fileName << "\n";
            return;
        }

        // Write column headers
        for (const auto& col : table.columns) {
            outFile << col.name << ",";
        }
        outFile << "\n";

        // Write rows
        for (const auto& row : table.rows) {
            for (const auto& value : row) {
                outFile << value << ",";
            }
            outFile << "\n";
        }
        outFile.close();
        cout << "Table written to " << fileName << ".\n";
    }
};

int main() 
{
    Database db;

    // Create a database
    db.createDatabase("SampleDB");

    // Define columns for the table
    vector<Column> columns = {
        {"ID", "INT"},
        {"Name", "TEXT"}
    };

    // Create a table
    db.createTable("SampleTable", columns);

    // Insert rows into the table
    db.insertRow({"1", "Alice"});
    db.insertRow({"2", "Bob"});

    // View table in CSV mode
    db.viewTable();

    // Write table to output file
    db.writeToFile("output.csv");

    return 0;
}
