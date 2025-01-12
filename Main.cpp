#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

int main()
{
    ifstream inFile;
    inFile.open("Sample1.txt");
    vector<string> lines;   // Vector to store lines
    string line;

    if (!inFile.is_open()) 
    {
        cout << "Error: Could not open the file.\n";
        return 1;
    }

    while (getline(inFile, line)) 
    {
        lines.push_back(line);
    }

    inFile.close(); // Close the file

    // Print the lines
    cout << "Lines in the file:\n";
    for (const string& l : lines) 
    {
        cout << l << "\n";
    }

    ofstream outFile("output1.txt");
    if (outFile.is_open())
    {
        outFile << lines[0] << endl;
        outFile << lines[1] << endl;
        outFile << "C:\\Users\\User\\OneDrive - mmu.edu.my\\Documents\\C++\\assignment\\Sample1.txt" << endl;
        cout << "File created and written successfully!";
    }

    else
    {
        cerr << "Error, unable to open file.";
    }
    
    outFile.close();
    return 0;
}