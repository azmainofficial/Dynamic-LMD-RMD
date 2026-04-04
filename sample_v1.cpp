#include <iostream>
#include <vector>
#include <string>

using namespace std;

string LeftmostDerivation(string input, const vector<string>& nonTerminals, const vector<string>& terminals) {
    cout << "\nLeftmost Derivation : \n";
    int step = 0;
    
    for (bool replaced = true; replaced; step++) {
        cout << "Iteration " << step + 1 << " -> " << input << endl;
        replaced = false;
        
        for (size_t i = 0; i < input.size(); i++) {
            for (size_t j = 0; j < nonTerminals.size(); j++) {
                if (input[i] == nonTerminals[j][0]) {
                    input = input.substr(0, i) + terminals[j] + input.substr(i + 1);
                    replaced = true;
                    break; 
                }
            }
            if (replaced) break; 
        }
    }

    return input;
}

string RightmostDerivation(string input, const vector<string>& nonTerminals, const vector<string>& terminals) {
    cout << "\nRightmost Derivation : \n";
    int step = 0;
    
    for (bool replaced = true; replaced; step++) {
        cout << "Iteration " << step + 1 << " -> #include <iostream>
#include <vector>
#include <string>

using namespace std;

string LeftmostDerivation(string input, const vector<string>& nonTerminals, const vector<string>& terminals) {
    cout << "\nLeftmost Derivation : \n";
    int step = 0;
    
    for (bool replaced = true; replaced; step++) {
        cout << "step " << step + 1 << " : " << input << endl;
        replaced = false;
        
        for (size_t i = 0; i < input.size(); i++) {
            for (size_t j = 0; j < nonTerminals.size(); j++) {
                if (input[i] == nonTerminals[j][0]) {
                    input = input.substr(0, i) + terminals[j] + input.substr(i + 1);
                    replaced = true;
                    break; 
                }
            }
            if (replaced) break; 
        }
    }

    return input;
}

string RightmostDerivation(string input, const vector<string>& nonTerminals, const vector<string>& terminals) {
    cout << "\nRightmost Derivation : \n";
    int step = 0;
    
    for (bool replaced = true; replaced; step++) {
        cout << "step " << step + 1 << " : " << input << endl;
        replaced = false;
        
        for (size_t i = input.size(); i-- > 0; ) {
            for (size_t j = 0; j < nonTerminals.size(); j++) {
                if (input[i] == nonTerminals[j][0]) {
                    input = input.substr(0, i) + terminals[j] + input.substr(i + 1);
                    replaced = true;
                    break;
                }
            }
            if (replaced) break; 
        }
    }

    return input;
}

int main() {
    int n;
    vector<string> nonTerminals;
    vector<string> terminals;
    string tempInput;

    cout << "Enter the number of cfg rules: ";
    cin >> n;
    cin.ignore(); 

    for (int i = 0; i < n; i++) {
        cout << "rule " << i + 1 << ": ";
        getline(cin, tempInput); 

        size_t pos = tempInput.find("->");
        if (pos != string::npos) {
            string nonTerminal = tempInput.substr(0, pos);
            nonTerminal.erase(nonTerminal.find_last_not_of(" \t\n\r\f\v") + 1); // Trim trailing spaces

            string terminal = tempInput.substr(pos + 2);
            terminal.erase(0, terminal.find_first_not_of(" \t\n\r\f\v")); // Trim leading spaces

            nonTerminals.push_back(nonTerminal);
            terminals.push_back(terminal);
        }
    }

    string startTerminal = terminals[0]; // Assuming the first terminal is the starting symbol

    string leftFinalResult = LeftmostDerivation(startTerminal, nonTerminals, terminals);
    cout << "\nFinal expanded terminal string (Leftmost Derivation): " << leftFinalResult << endl;

    string rightFinalResult = RightmostDerivation(startTerminal, nonTerminals, terminals);
    cout << "\nFinal expanded terminal string (Rightmost Derivation): " << rightFinalResult << endl;

    return 0;
}" << input << endl;
        replaced = false;
        
        for (size_t i = input.size(); i-- > 0; ) {
            for (size_t j = 0; j < nonTerminals.size(); j++) {
                if (input[i] == nonTerminals[j][0]) {
                    input = input.substr(0, i) + terminals[j] + input.substr(i + 1);
                    replaced = true;
                    break;
                }
            }
            if (replaced) break; 
        }
    }

    return input;
}

int main() {
    int n;
    vector<string> nonTerminals;
    vector<string> terminals;
    string tempInput;

    cout << "Enter the number of cfg rules: ";
    cin >> n;
    cin.ignore(); 

    for (int i = 0; i < n; i++) {
        cout << "rule " << i + 1 << ": ";
        getline(cin, tempInput); 

        size_t pos = tempInput.find("->");
        if (pos != string::npos) {
            string nonTerminal = tempInput.substr(0, pos);
            nonTerminal.erase(nonTerminal.find_last_not_of(" \t\n\r\f\v") + 1); // Trim trailing spaces

            string terminal = tempInput.substr(pos + 2);
            terminal.erase(0, terminal.find_first_not_of(" \t\n\r\f\v")); // Trim leading spaces

            nonTerminals.push_back(nonTerminal);
            terminals.push_back(terminal);
        }
    }

    string startTerminal = terminals[0]; // Assuming the first terminal is the starting symbol

LeftmostDerivation(startTerminal, nonTerminals, terminals);
RightmostDerivation(startTerminal, nonTerminals, terminals);

    return 0;
}
