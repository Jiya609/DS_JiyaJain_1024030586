#include <iostream>
using namespace std;

int main() {
    char ch;

    cout << "Enter an uppercase character: ";
    cin >> ch;

    
    if (ch >= 'A' && ch <= 'Z') {
        ch = ch + 32;  
        cout << "Lowercase: " << ch << endl;
    } else {
        cout << "Not an uppercase letter!" << endl;
    }

    return 0;
}
