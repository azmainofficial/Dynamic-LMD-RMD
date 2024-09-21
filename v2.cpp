#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

string trim(const string &str) {
    size_t first = str.find_first_not_of(" \t\n\r\f\v");
    size_t last = str.find_last_not_of(" \t\n\r\f\v");
    return (first == string::npos || last == string::npos) ? "" : str.substr(first, last - first + 1);
}

bool isNonTerminal(const string &str, const vector<string> &nonTerminals) {
    for (const string &nonTerminal : nonTerminals) {
        if (str == nonTerminal) return true;
    }
    return false;
}

bool deriveLeft(string current, const string &inputString, const vector<string> &nonTerminals, const vector<vector<string>> &terminals, vector<string> &steps) {

    steps.push_back(current);

    if (current == inputString) {
        return true;
    }
    if (current.size() > inputString.size()) {
        steps.pop_back();  
        return false;
    }


    for (size_t i = 0; i < current.size(); i++) {
        string charStr(1, current[i]);  
        if (isNonTerminal(charStr, nonTerminals)) {
            for (size_t j = 0; j < nonTerminals.size(); j++) {
                if (charStr == nonTerminals[j]) {
                    for (const string &replacement : terminals[j]) {
                        string newDerivation = current.substr(0, i) + replacement + current.substr(i + 1);
                        if (deriveLeft(newDerivation, inputString, nonTerminals, terminals, steps)) {
                            return true; 
                        }
                    }
                }
            }
            steps.pop_back();  
            return false;  
        }
    }

    steps.pop_back(); 
    return false; 
}

bool deriveRight(string current, const string &inputString, const vector<string> &nonTerminals, const vector<vector<string>> &terminals, vector<string> &steps) {

     steps.push_back(current);
    if (current == inputString) {
        return true;
    }

    if (current.size() > inputString.size()) {
        steps.pop_back(); 
        return false;
    }

    for (int i = current.size() - 1; i >= 0; i--) {
        string charStr(1, current[i]);  

        if (isNonTerminal(charStr, nonTerminals)) {
            for (size_t j = 0; j < nonTerminals.size(); j++) {
                if (charStr == nonTerminals[j]) {
                    for (const string &replacement : terminals[j]) {
                        string newDerivation = current.substr(0, i) + replacement + current.substr(i + 1);
                        if (deriveRight(newDerivation, inputString, nonTerminals, terminals, steps)) {
                            return true; 
                        }
                    }
                }
            }
            steps.pop_back(); 
            return false;  
        }
    }

    steps.pop_back();  
    return false; 
}

int main() {
    int n;
    vector<string> nonTerminals;
    vector<vector<string>> terminals; 
    string tempInput;
    string inputString;

    cout << "Enter the number of CFG rules: ";
    cin >> n;
    cin.ignore(); 

    for (int i = 0; i < n; i++) {
        cout << "rule " << i + 1 << ": ";
        getline(cin, tempInput); 

        size_t pos = tempInput.find("->");

        if (pos != string::npos) {
            string nonTerminal = trim(tempInput.substr(0, pos));
            string terminalString = trim(tempInput.substr(pos + 2));

            vector<string> terminalList;
            stringstream ss(terminalString);
            string terminal;
            while (getline(ss, terminal, '|')) {
                terminalList.push_back(trim(terminal)); 
            }

            nonTerminals.push_back(nonTerminal);
            terminals.push_back(terminalList);
        } else {
            cout << "Invalid rule format! Missing '->'.\n";
        }
    }

    cout << "\n\nEnter the Input string: ";
    getline(cin, inputString);

    if (!nonTerminals.empty()) {
        cout << "\nStarting strings from non-terminal '" << nonTerminals[0] << "': ";
        for (const auto &t : terminals[0]) {
            cout << "'" << t << "' ";
        }
        cout << endl;
    }

    vector<string> leftSteps;  
    bool foundLeft = false;
    for (const auto &startingTerminal : terminals[0]) {
        if (deriveLeft(startingTerminal, inputString, nonTerminals, terminals, leftSteps)) {
            foundLeft = true;
            break;
        }
    }

    vector<string> rightSteps;  
    bool foundRight = false;
    for (const auto &startingTerminal : terminals[0]) {
        if (deriveRight(startingTerminal, inputString, nonTerminals, terminals, rightSteps)) {
            foundRight = true;
            break;
        }
    }

    if (foundLeft) {
        cout << "\nLeftmost Derivation steps:" << endl;
        for (size_t i = 0; i < leftSteps.size(); i++) {
            cout << "Step " << i + 1 << ": " << leftSteps[i] << endl;
        }
    } else {
        cout << "\nInput string '" << inputString << "' could not be derived using leftmost derivation." << endl;
    }

    if (foundRight) {
        cout << "\nRightmost Derivation steps:" << endl;
        for (size_t i = 0; i < rightSteps.size(); i++) {
            cout << "Step " << i + 1 << ": " << rightSteps[i] << endl;
        }
    } else {
        cout << "\nInput string '" << inputString << "' could not be derived using rightmost derivation." << endl;
    }

    return 0;
}
