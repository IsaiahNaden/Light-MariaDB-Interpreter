#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <string>
#include <stdexcept>

using namespace std;

// Structures to hold tables and data
struct Table {
    vector<string> columns;  // Column names
    vector<vector<string>> rows;  // Data rows
};

// Store databases with their corresponding tables
map<string, map<string, Table>> databases;

// Function to handle file I/O operations
void readCommandsFromFile(const string &filename) {
    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Error opening file " << filename << endl;
        return;
    }

    string line;
    while (getline(inputFile, line)) {
        cout << "Executing: " << line << endl;
        try {
            // Process commands
            if (line.find("CREATE DATABASE") != string::npos) {
                // Handle CREATE DATABASE
                size_t pos = line.find("CREATE DATABASE") + 16;
                string dbName = line.substr(pos);
                if (databases.find(dbName) != databases.end()) {
                    throw runtime_error("Database already exists.");
                }
                databases[dbName] = {};  // Add the database to the map
            } else if (line.find("CREATE TABLE") != string::npos) {
                // Handle CREATE TABLE
                size_t pos = line.find("CREATE TABLE") + 13;
                string tableName = line.substr(pos, line.find("(") - pos - 1);
                string columnsPart = line.substr(line.find("(") + 1, line.find(")") - line.find("(") - 1);

                vector<string> columns;
                stringstream ss(columnsPart);
                string col;
                while (getline(ss, col, ',')) {
                    columns.push_back(col);
                }

                if (databases.empty()) {
                    throw runtime_error("No database selected.");
                }

                // For simplicity, assuming the first database in the map is the one to use
                databases.begin()->second[tableName].columns = columns;
            } else if (line.find("INSERT INTO") != string::npos) {
                // Handle INSERT INTO
                size_t pos = line.find("INSERT INTO") + 12;
                string tableName = line.substr(pos, line.find(" VALUES") - pos);
                string valuesPart = line.substr(line.find("(") + 1, line.find(")") - line.find("(") - 1);

                vector<string> values;
                stringstream ss(valuesPart);
                string val;
                while (getline(ss, val, ',')) {
                    values.push_back(val);
                }

                if (databases.empty()) {
                    throw runtime_error("No database selected.");
                }

                // For simplicity, assuming the first database and table in the map are the ones to use
                auto &table = databases.begin()->second.begin()->second;
                if (values.size() != table.columns.size()) {
                    throw runtime_error("Number of values does not match number of columns.");
                }
                table.rows.push_back(values);  // Insert into the first table
            } else if (line.find("SELECT * FROM") != string::npos) {
                // Handle SELECT * FROM
                size_t pos = line.find("SELECT * FROM") + 14;
                string tableName = line.substr(pos);

                if (databases.empty()) {
                    throw runtime_error("No database selected.");
                }

                // For simplicity, assuming the first database and table in the map are the ones to use
                auto &table = databases.begin()->second.begin()->second;

                // Display table contents in CSV format
                cout << "Table: " << tableName << endl;
                for (const auto &row : table.rows) {
                    for (size_t i = 0; i < row.size(); ++i) {
                        cout << row[i];
                        if (i != row.size() - 1) cout << ",";
                    }
                    cout << endl;
                }
            } else {
                cerr << "Unknown command: " << line << endl;
            }
        } catch (const runtime_error &e) {
            cerr << "Error: " << e.what() << endl;
        }
    }

    inputFile.close();
}

// Function to write output to a file
void writeResultsToFile(const string &filename) {
    ofstream outputFile(filename);
    if (!outputFile) {
        cerr << "Error opening file for writing: " << filename << endl;
        return;
    }

    // Write the table contents in CSV format
    for (const auto &database : databases) {
        for (const auto &tableEntry : database.second) {
            Table table = tableEntry.second;
            outputFile << "Table: " << tableEntry.first << endl;
            for (const auto &row : table.rows) {
                for (size_t i = 0; i < row.size(); ++i) {
                    outputFile << row[i];
                    if (i != row.size() - 1) outputFile << ",";
                }
                outputFile << endl;
            }
        }
    }

    outputFile.close();
}

// Main function
int main() {
    string inputFileName = "fileInput1.mdb";  // Input file with SQL-like commands
    string outputFileName = "fileOutput1.txt";  // Output file for results

    // Step 1: Read commands from file
    readCommandsFromFile(inputFileName);

    // Step 2: Write the result to output file
    writeResultsToFile(outputFileName);

    return 0;
}

