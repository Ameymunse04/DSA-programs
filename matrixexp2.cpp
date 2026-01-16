#include <iostream>
using namespace std;

int main() {
    int r, c;

    cout << "Enter number of rows and columns: ";
    cin >> r >> c;

    int A[r][c], B[r][c];

    
    cout << "Enter elements of Matrix A:\n";
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin >> A[i][j];

   
    cout << "Enter elements of Matrix B:\n";
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin >> B[i][j];

    
    cout << "\nMatrix Addition:\n";
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++)
            cout << A[i][j] + B[i][j] << " ";
        cout << endl;
    }

    
    cout << "\nMatrix Subtraction (A - B):\n";
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++)
            cout << A[i][j] - B[i][j] << " ";
        cout << endl;
    }

    
    if(r == c) {
        cout << "\nMatrix Multiplication:\n";
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                int sum = 0;
                for(int k = 0; k < c; k++)
                    sum += A[i][k] * B[k][j];
                cout << sum << " ";
            }
            cout << endl;
        }
    } else {
        cout << "\nMatrix multiplication not possible\n";
    }

    
    if(r == 2 && c == 2) {
        float detA = A[0][0]*A[1][1] - A[0][1]*A[1][0];
        float detB = B[0][0]*B[1][1] - B[0][1]*B[1][0];

        if(detA != 0) {
            cout << "\nInverse of Matrix A:\n";
            cout << A[1][1]/detA << " " << -A[0][1]/detA << endl;
            cout << -A[1][0]/detA << " " << A[0][0]/detA << endl;
        } else {
            cout << "\nInverse of Matrix A not possible\n";
        }

        if(detB != 0) {
            cout << "\nInverse of Matrix B:\n";
            cout << B[1][1]/detB << " " << -B[0][1]/detB << endl;
            cout << -B[1][0]/detB << " " << B[0][0]/detB << endl;
        } else {
            cout << "\nInverse of Matrix B not possible\n";
        }
    } else {
        cout << "\nInverse only supported for 2x2 matrices\n";
    }

    return 0;
}