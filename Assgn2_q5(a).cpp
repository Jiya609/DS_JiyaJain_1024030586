#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of diagonal matrix: ";
    cin >> n;

    int diag[n];   

    cout << "Enter " << n << " diagonal elements: ";
    for (int i = 0; i < n; i++) {
        cin >> diag[i];
    }

    cout << "\nDiagonal Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                cout << diag[i] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }

    return 0;
}
