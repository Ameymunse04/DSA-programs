#include <iostream>
using namespace std;
int linearSearch(int *,int,int);

int main()
{   
    int n;
    int target;

    cout << "Enter no. of elements: ";
    cin >> n;

    int *x = new int[n];

    cout << "Enter the array elements: \n";
    for (int i = 0; i < n; i++)
        cin >> *(x + i);

    cout << "Now enter the target value: ";
    cin >> target;

    int res = linearSearch(x,n,target);

    if(res)
        cout << "Target value found at index " << res << "\n";
    else
        cout << "Target value not found...\n";

    delete[] x;
    return 0;
}

int linearSearch(int *p,int a,int t) 
{
    for (int j = 0; j < a; j++)
    {
        if((*(p + j)) == t) 
            return j;
    }  

    return 0;
}