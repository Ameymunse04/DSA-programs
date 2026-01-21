#include <iostream>
using namespace std;

int main() {
    int arr[50], n, i, choice;
    int sum;
    char ch;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter array elements:\n";
    for(i = 0; i < n; i++) {
        cin >> arr[i];
    }

    do {
        cout << "\n\n--- ARRAY OPERATIONS MENU ---";
        cout << "\n1. Display array";
        cout << "\n2. Sum of elements";
        cout << "\n3. Inverse (Reverse) array";
        cout << "\n4. Insert element";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice) {

            case 1:
                cout << "Array elements: ";
                for(i = 0; i < n; i++)
                    cout << arr[i] << " ";
                break;

            case 2:
                sum = 0;
                for(i = 0; i < n; i++)
                    sum += arr[i];
                cout << "Sum of elements = " << sum;
                break;

            case 3:
                cout << "Inverse (Reversed array): ";
                for(i = n - 1; i >= 0; i--)
                    cout << arr[i] << " ";
                break;

            case 4: {
                int pos, value;
                cout << "Enter position to insert (0 to " << n << "): ";
                cin >> pos;
                cout << "Enter value to insert: ";
                cin >> value;

                for(i = n; i > pos; i--) {
                    arr[i] = arr[i - 1];
                }
                arr[pos] = value;
                n++;

                cout << "Element inserted successfully.";
                break;
            }

            case 5:
                cout << "Exiting program...";
                return 0;

            default:
                cout << "Invalid choice!";
        }

        cout << "\nDo you want to continue? (y/n): ";
        cin >> ch;

    } while(ch == 'y' || ch == 'Y');

    return 0;
}
