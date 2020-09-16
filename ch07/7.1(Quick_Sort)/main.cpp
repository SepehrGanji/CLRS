#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void QuickSort(int*, int, int);
int Partition(int*, int, int);

int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0 ; i < n ; i++)cin >> arr[i];
    QuickSort(arr, 0, n);
    for(int i = 0 ; i < n ; i++)cout << arr[i] << ' ';
    return 0;
}

void QuickSort(int* arr, int l, int r){
    if(l >= r)return;
    srand(time(NULL));
    int piv = (rand() % (r - l)) + l;
    // cout << "piv : " << piv << endl;
    int tmp = arr[piv];
    arr[piv] = arr[l];
    arr[l] = tmp;
    int new_piv_position = Partition(arr, l, r);
    QuickSort(arr, l, new_piv_position);
    QuickSort(arr, new_piv_position + 1, r);
}

int Partition(int* arr, int l, int r){
    int i = l + 1;
    int piv_el = arr[l];
    for(int j = l + 1 ; j < r ; j++){
        if(arr[j] < piv_el){
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
        }
    }
    int tmp = arr[i - 1];
    arr[i - 1] = arr[l];
    arr[l] = tmp;
    return (i - 1);
}
