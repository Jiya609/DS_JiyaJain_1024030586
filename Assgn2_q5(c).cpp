#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of lower triangular matrix: ";
    cin >> n;

    int size = n*(n+1)/2; 
    int arr[size];

    cout << "Enter " << size << " elements row by row: ";
    for (int i = 0; i < size; i++) cin >> arr[i];

    cout << "\nLower Triangular Matrix:\n";
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j <= i)
                cout << arr[k++] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }

    return 0;
}
