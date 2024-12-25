#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>

long int readValueFromRowColumn(const std::string& filename, int row, int column) {
    std::ifstream file(filename);
    std::string line;
    long int value = 0;
    int currentRow = 1;

    if (file.is_open()) {
        while (std::getline(file, line)) {
            if (currentRow == row) {
                std::stringstream ss(line);
                std::string cell;
                int currentColumn = 1;

                while (std::getline(ss, cell, ',')) {
                    if (currentColumn == column) {
                        try {
                            value = std::stol(cell);
                        } catch (const std::invalid_argument& e) {
                            std::cerr << "Invalid data in row " << row << ", column " << column << ": " << cell << std::endl;
                        } catch (const std::out_of_range& e) {
                            std::cerr << "Data out of range in row " << row << ", column " << column << ": " << cell << std::endl;
                        }
                        return value;
                    }
                    currentColumn++;
                }
            }
            currentRow++;
        }
        file.close();
    } else {
        std::cerr << "Unable to open file." << std::endl;
    }

    return value;
}

std::string getValueByKey(const std::string& filename, const std::string& key) {
    std::ifstream file(filename);
    std::string line;
    std::unordered_map<std::string, std::string> keyValueMap;

    if (file.is_open()) {
        // Read the first row to build the key-value map
        if (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string cell;
            std::vector<std::string> keys;

            while (std::getline(ss, cell, ',')) {
                keys.push_back(cell);
            }

            // Read the second row to map keys to values
            if (std::getline(file, line)) {
                std::stringstream ss(line);
                int index = 0;

                while (std::getline(ss, cell, ',')) {
                    if (index < keys.size()) {
                        keyValueMap[keys[index]] = cell;
                    }
                    index++;
                }
            }
        }
        file.close();
    } else {
        std::cerr << "Unable to open file." << std::endl;
    }

    // Return the value corresponding to the given key
    if (keyValueMap.find(key) != keyValueMap.end()) {
        return keyValueMap[key];
    } else {
        return "Key not found";
    }
}

int main() {
    std::string filename = "data.csv";

    // Example usage of readValueFromRowColumn
    long int value = readValueFromRowColumn(filename, 1, 2);
    std::cout << "Value in row 1, column 2: " << value << std::endl;

    // Example usage of getValueByKey
    std::string key = "someKey"; // Replace with actual key from column 1 of row 1
    std::string result = getValueByKey(filename, key);
    std::cout << "Value for key '" << key << "' in row 2: " << result << std::endl;

    return 0;
}
