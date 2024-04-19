#include <iostream>
using namespace std;

void MaxHeapify(int a[], int i, int n)
{
    int j, temp;
    temp = a[i];
    j = 2 * i;

    while (j <= n)
    {
        if (j < n && a[j + 1] > a[j])
            j = j + 1;

        if (temp > a[j])
            break;

        else if (temp <= a[j])
        {
            a[j / 2] = a[j];
            j = 2 * j;
        }
    }
    a[j / 2] = temp;
    return;
}

void MinHeapify(int a[], int i, int n)
{
    int j, temp;
    temp = a[i];
    j = 2 * i;

    while (j <= n)
    {
        if (j < n && a[j + 1] < a[j])
            j = j + 1;

        if (temp < a[j])
            break;

        else if (temp >= a[j])
        {
            a[j / 2] = a[j];
            j = 2 * j;
        }
    }
    a[j / 2] = temp;
    return;
}

void MaxHeapSort(int a[], int n)
{
    int i, temp;
    for (i = n; i >= 2; i--)
    {

        temp = a[i];
        a[i] = a[1];
        a[1] = temp;

        MaxHeapify(a, 1, i - 1);
    }
}

void MinHeapSort(int a[], int n)
{
    int i, temp;
    for (i = n; i >= 2; i--)
    {

        temp = a[i];
        a[i] = a[1];
        a[1] = temp;

        MinHeapify(a, 1, i - 1);
    }
}

void Build_MaxHeap(int a[], int n)
{
    int i;
    for (i = n / 2; i >= 1; i--)
        MaxHeapify(a, i, n);
}

void Build_MinHeap(int a[], int n)
{
    int i;
    for (i = n / 2; i >= 1; i--)
        MinHeapify(a, i, n);
}

int main()
{
    cout<<"DSAL Practical No. 10 (E-22)"<<endl;
	cout<<"Prepared By : Anshul Singh"<<endl;
    int n, i;
    cout << "\nEnter the number of Students : ";
    cin >> n;
    n++;
    int arr[n];
    for (i = 1; i < n; i++)
    {
        cout << "Enter the marks :  " << i << ": ";
        cin >> arr[i];
    }

    Build_MaxHeap(arr, n - 1);
    MaxHeapSort(arr, n - 1);

    int max, min;
    cout << "\nSorted Data : ASCENDING : ";

    for (i = 1; i < n; i++)
        cout << "->" << arr[i];
    min = arr[1];
    Build_MinHeap(arr, n - 1);
    MinHeapSort(arr, n - 1);
    cout << "\nSorted Data : DESCENDING: ";
    max = arr[1];
    for (i = 1; i < n; i++)
        cout << "->" << arr[i];
    cout << "\nMaximum Marks : " << max << "\nMinimum marks : " << min;
    return 0;
}