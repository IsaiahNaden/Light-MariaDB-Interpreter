#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;


int main()
{
    ifstream inFile;
    ifstream inFile2;
    ifstream inFile3;

    inFile.open("Sample1.txt");
    vector<string> lines;   // Vector to store lines
    string line;

    if (!inFile.is_open()) // validating file input
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
    cout << "Lines in Sample1:\n";
    for (const string& l : lines) 
    {
        cout << l << "\n";
    }

    ofstream outFile("output1.txt"); //outputting to file
    if (outFile.is_open())
    {
        outFile << lines[0] << endl;
        outFile << lines[1] << endl;
        outFile << endl; // code to add file path from user directory
        cout << "File created and written successfully!";
        cout << endl;
        cout << endl;
        cout << endl;
    }

    else
    {
        cerr << "Error, unable to open file."; 
    }
    
    outFile.close();

    inFile2.open("Sample2.txt");
    vector<string> lines2;
    string line2;

    if (!inFile2.is_open()) // validating file input
    {
        cout << "Error: Could not open the file.\n";
        return 1;
    }

    while (getline(inFile2, line2)) 
    {
        lines2.push_back(line2);
    }

    inFile2.close(); // Close the file

    // Print the lines
    cout << "Lines in Sample2:\n";
    for (const string& l : lines2) 
    {
        cout << l << "\n";
    }

    ofstream outFile2("output2.txt"); //outputting to file
    if (outFile2.is_open())
    {
        outFile2 << lines2[0] << endl;
        outFile2 << lines2[1] << endl;
        outFile2 << endl; // code to add file path from user directory
        cout << "File created and written successfully!";
        cout << endl;
        cout << endl;
        cout << endl;
    }

    else
    {
        cerr << "Error, unable to open file."; 
    }
    
    outFile2.close();

    
    inFile3.open("Sample3.txt");
    vector<string> lines3;
    string line3;

    if (!inFile3.is_open()) // validating file input
    {
        cout << "Error: Could not open the file.\n";
        return 1;
    }

    while (getline(inFile3, line3)) 
    {
        lines3.push_back(line3);
    }

    inFile3.close(); // Close the file

    // Print the lines
    cout << "Lines in Sample3:\n";
    for (const string& l : lines3) 
    {
        cout << l << "\n";
    }

    ofstream outFile3("output3.txt"); //outputting to file
    if (outFile3.is_open())
    {
        outFile3 << lines3[0] << endl;
        outFile3 << lines3[1] << endl;
        outFile3 << endl; // code to add file path from user directory
        cout << "File created and written successfully!";
        cout << endl;
        cout << endl;
        cout << endl;
    }

    else
    {
        cerr << "Error, unable to open file."; 
    }
    
    outFile3.close();

    return 0;
}
