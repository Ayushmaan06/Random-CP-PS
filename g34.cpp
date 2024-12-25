#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>

using namespace std;

// Function to read a value from a specified row and column
long int readValueFromRowColumn(const string &filename, int targetRow, int targetColumn) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file" << endl;
        return -1;
    }

    string line;
    int rowIndex = 1;
    long int value = 0;

    while (getline(file, line)) {
        if (rowIndex == targetRow) {
            stringstream ss(line);
            string cell;
            int columnIndex = 1;

            while (getline(ss, cell, ',')) {
                if (columnIndex == targetColumn) {
                    value = stol(cell); // Convert the string to long int
                    break;
                }
                columnIndex++;
            }
            break;
        }
        rowIndex++;
    }

    file.close();
    return value;
}

// Function to get the value from column 2 based on a key from column 1
string getValueByKey(const string &filename, const string &key) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file" << endl;
        return "";
    }

    string line;
    unordered_map<string, string> keyValueMap;

    while (getline(file, line)) {
        stringstream ss(line);
        string col1, col2;

        if (getline(ss, col1, ',') && getline(ss, col2, ',')) {
            keyValueMap[col1] = col2;
        }
    }

    file.close();

    if (keyValueMap.find(key) != keyValueMap.end()) {
        return keyValueMap[key];
    } else {
        return "Key not found";
    }
}

int main() {
    string filename = "data.csv"; // Replace with your actual file name

    // Example usage of readValueFromRowColumn
    int targetRow = 1;
    int targetColumn = 2;
    long int value = readValueFromRowColumn(filename, targetRow, targetColumn);
    cout << "Value at row " << targetRow << ", column " << targetColumn << " is: " << value << endl;

    // Example usage of getValueByKey
    string key = "qwerty"; // Replace with the actual key you are looking for
    string result = getValueByKey(filename, key);
    cout << "Value for key '" << key << "' is: " << result << endl;

    return 0;
}