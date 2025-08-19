#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key) 
            return mid;   
        else if (arr[mid] > key) 
            high = mid - 1;  
        else 
            low = mid + 1;   
    }
    return -1; 
}

int main() {
    int n, key;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[100];
    cout << "Enter elements in sorted order: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter element to search: ";
    cin >> key;

    int result = binarySearch(arr, n, key);

    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found." << endl;

    return 0;
}
