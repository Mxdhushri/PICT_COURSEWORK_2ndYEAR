#include <iostream>
using namespace std;
template <class T>
void selection_sort()
{
    T a[5];
    int i, j, min;
    T temp;
    for (i = 0; i < 5; i++)
    {
        cin >> a[i]; 
    }
    for (i = 0; i < 4; i++)
    {
        min = i;
        for (j = i + 1; j < 5; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
    cout << "Sorted Array: " << endl;
    for (i = 0; i < 5; i++)
    {
        cout << a[i] << endl;
    }
}
int main()
{
    int ch;
    do
    {
        cout << "*******SELECTION SORT SYSTEM*******" << endl;
        cout << "---------------MENU----------------" << endl;
        cout << "1. Integer Values" << endl;
        cout << "2. Float Values  " << endl;
        cout << "3. Exit          " << endl;
        cout << "Enter Choice:" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter 5 Integer Elements:" << endl;
            selection_sort<int>();
            break;
        case 2:
            cout << "Enter 5 Float Elements:" << endl;
            selection_sort<float>();
            break;
        case 3:
            cout << "Code has been exited.";
            exit(0);
        default:
            cout << "Invalid choice!!!" << endl;
            break;
        }
    } while (ch != 3);
    return 0;
}