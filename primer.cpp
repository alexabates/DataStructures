#include <cstdlib>
#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main() {
    string text1, text2;
    
    // Using cin to read a single word
    cout << "Enter a single word: ";
    cin >> text1;
    
    // Clear the input buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignores any extra words that may be inputted from above
    
    // Using getline to read a full line of text
    cout << "Enter a full line of text: ";
    getline(cin, text2);

    cout << "You entered (single word): " << text1 << endl;
    cout << "You entered (full line): " << text2 << endl;

    return 0;
}