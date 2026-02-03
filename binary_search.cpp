#include <iostream>
using namespace std;
int binarySearch(int *,int,int);

int main()
{   
    int n;
    int target;

    cout << "Enter no. of elements: ";
    cin >> n;

    int *p = new int[n];

    cout << "Enter the array elements: \n";
    for (int i = 0; i < n; i++)
        cin >> p[i];

    cout << "Now enter the target value: ";
    cin >> target;

    int res = binarySearch(p,n,target);

    if (res != -1)
        cout << "Target value found at index " << res << "\n";    
    else
        cout << "Target value not found in the array...\n";

    delete[] p;
    return 0;
}

int binarySearch(int *x,int a,int t) 
{
    int low = 0,high = (a - 1);
    int found;
    int mid = (low + high) / 2; 

    
    if(t == x[mid]) 
        return mid;
    

    while (low <= high)
    {
        if(t < x[mid])
        {
            high = mid - 1;
            mid = (low + high) / 2;
            
            if(t == x[mid]) {
                found = 1;
                break;
            }
        }

        else
        {
            low = mid + 1;
            mid = (low + high) / 2;

            if(t == x[mid]) {
                found = 1;
                break;
            }
        }        
    }

    if (found != 1) 
        return -1;
    else
        return mid;
}