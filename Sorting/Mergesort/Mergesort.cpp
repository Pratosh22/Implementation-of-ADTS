#include <iostream>
using namespace std;

void mergearrays(int x[], int y[], int a[], int s, int e)
{
    int mid = (s + e) / 2;
    int i = s;       // used for traversing array x
    int j = mid + 1; // used for traversing array y
    int k = s;       // traversing a
    while (i <= mid && j <= e)
    {
        if (x[i] < y[j])
        {
            a[k] = x[i];
            i++;
            k++;
        }
        else
        {
            a[k] = y[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        a[k] = x[i];
        k++;
        i++;
    }
    while (j <= e)
    {
        a[k] = y[j];
        k++;
        j++;
    }
}

void mergesort(int a[], int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int mid = (s + e) / 2;
    int x[100], y[100];
    for (int i = 0; i <= mid; i++)
    { // mid elements pushed to array x
        x[i] = a[i];
    }
    for (int i = mid + 1; i <= e; i++)
    {
        y[i] = a[i];
    }
    mergesort(x, s, mid);
    mergesort(y, mid + 1, e);
    mergearrays(x, y, a, s, e);
}
int main()
{
    int a[] = {4, 3, 1, 5, 6, 2};
    mergesort(a, 0, 5);
    for (int i = 0; i < 6; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}