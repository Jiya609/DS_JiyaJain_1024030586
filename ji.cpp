#include <iostream>
using namespace std;

int main() {
    int arr[100], n = 0, choice;

    do {
        cout << "\n——MENU——\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) { 
            cout << "Enter number of elements: ";
            cin >> n;
            cout << "Enter elements: ";
            for (int i = 0; i < n; i++)
                cin >> arr[i];
        }

        else if (choice == 2) { 
            cout << "Array: ";
            for (int i = 0; i < n; i++)
                cout << arr[i] << " ";
            cout << endl;
        }

        else if (choice == 3) {
            int pos, val;
            cout << "Enter position (1 to " << n+1 << "): ";
            cin >> pos;
            cout << "Enter value: ";
            cin >> val;
            for (int i = n; i >= pos; i--)
                arr[i] = arr[i - 1];
            arr[pos - 1] = val;
            n++;
        }

        else if (choice == 4) { 
            int pos;
            cout << "Enter position (1 to " << n << "): ";
            cin >> pos;
            for (int i = pos - 1; i < n - 1; i++)
                arr[i] = arr[i + 1];
            n--;
        }

        else if (choice == 5) { 
            int key, found = 0;
            cout << "Enter value to search: ";
            cin >> key;
            for (int i = 0; i < n; i++) {
                if (arr[i] == key) {
                    cout << "Found at position " << i + 1 << endl;
                    found = 1;
                }
            }
            if (!found)
                cout << "Not found.\n";
        }

        else if (choice == 6) { // EXIT
            cout << "Exiting...\n";
        }

        else {
            cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}
