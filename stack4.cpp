#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int top = -1, value = 0;
    int top1 = 1;

    cout << "Enter the Size of Array" << endl;
    int size;
    if(!(cin >> size)) return 0;

    vector<int> arr(size);

    cout << "Enter the values" << endl;

    for(int i = 0; i < size; i++)
    {
        if(top == size - 1)
        {
            cout << "Stack Overflow" << endl;
            break;
        } else 
        {
            cin >> value;
            top++;
            arr[top] = value;
        }
    }

    cout << "Stack After Push:" << endl;
    for(int i = top; i >= 0; i--)
        cout << arr[i] << endl;

    if(top != -1 && arr[top] != top1)
    {
        cout << "Removed Value: " << arr[top] << endl;
        top--;
    }

    cout << "Stack After Removal:" << endl;
    if(top == -1)
        cout << "Stack is Empty" << endl;
    else
        for(int i = top; i >= 0; i--)
            cout << arr[i] << endl;

    return 0;
}