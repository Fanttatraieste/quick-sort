#include <iostream>
using namespace std;

int partition(int v[], int st, int dr)
{
    /* This function takes last element as pivot, places the pivot element at its correct position in sorted array,
    and places all smaller (smaller than pivot) to left of pivot and all greater elements to right of pivot */
    int pivot = v[dr];   //we selected the last element as pivot
    int i = st - 1; // Index of smaller element and indicates the right position of pivot found so far
    for (int j = st; j < dr; j++)
    {
        //if current element is smaller than the pivot
        if (v[j] < pivot)
        {
            i++;  // increment the final position of the pivot
            swap(v[i], v[j]);   //v[i] is technically on the left side of the pivot, while v[j] on the right side (after the swap)
        }
    }
    swap(v[i + 1], v[dr]);   //we move the pivot at it's correct position in the array
    //remember that the pivot was the last element of the sequence
    return (i + 1);   // the pivot's position
}

void quickSort(int v[], int st, int dr)
{
    if (st < dr)
    {
        int pivot = partition(v, st, dr);
        quickSort(v, st, pivot - 1);
        quickSort(v, pivot + 1, dr);
    }
}



int main()
{
    int n, v[100001], i;
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> v[i];
    quickSort(v, 1, n);
    for (i = 1; i <= n; i++)
        cout << v[i] << " ";

    return 0;
}