#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of tri-diagonal matrix: ";
    cin >> n;

    int lower[n-1], diag[n], upper[n-1]; 

    cout << "Enter " << n << " diagonal elements: ";
    for (int i = 0; i < n; i++) cin >> diag[i];

    cout << "Enter " << n-1 << " lower diagonal elements: ";
    for (int i = 0; i < n-1; i++) cin >> lower[i];

    cout << "Enter " << n-1 << " upper diagonal elements: ";
    for (int i = 0; i < n-1; i++) cin >> upper[i];

    cout << "\nTri-diagonal Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                cout << diag[i] << " ";
            else if (i == j+1)
                cout << lower[j] << " ";
            else if (j == i+1)
                cout << upper[i] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }

    return 0;
}
