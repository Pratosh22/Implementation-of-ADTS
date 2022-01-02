#include <iostream>
using namespace std;

int partition(int a[], int s, int e)
{
    int i = s;
    int pivot = a[e];
    for (int j = s; j <= e - 1; j++)
    {
        if (a[j] < pivot)
        {
            swap(a[i], a[j]);
            i++;
        }
    }
    swap(a[i],a[e]);
    return i;
}
void quicksort(int a[], int s, int e)
{
    if (s >= e)
    {
        return;
    }
    else
    {
        int p = partition(a, s, e);
        quicksort(a, s, p - 1);
        quicksort(a, p + 1, e);
    }
}
int main(){
    int a[]={4,3,1,2};
    quicksort(a,0,3);
 
   for(int i=0;i<4;i++){
       cout<<a[i]<<" ";
   }
}
