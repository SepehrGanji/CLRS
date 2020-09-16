#include <iostream>

using namespace std;

int* mergeSort(int*, int);

int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0 ; i < n ; i++)cin >> arr[i];
    int *sorted = mergeSort(arr, n);
    for(int i = 0 ; i < n ; i++)cout << sorted[i] << ' ';
    return 0;
}

int* mergeSort(int* arr, int n){
    //sorting
    if(n == 1){
        return arr;
    }
    if(n == 2){
        if(arr[0] > arr[1]){
            int tmp = arr[0];
            arr[0] = arr[1];
            arr[1] = tmp;
        }
        return arr;
    }
    int point = n / 2;
    int ln = point;
    int rn = n - point;
    int *larr = new int[ln];
    int *rarr = new int[rn];
    for(int i = 0 ; i < ln ; i++)larr[i] = arr[i];
    for(int i = 0 ; i < rn ; i++)rarr[i] = arr[ln + i];
    int *sorted_left = mergeSort(larr, ln);
    int *sorted_right = mergeSort(rarr, rn);
    //merging
    int i = 0, j = 0;
    int *sorted = new int[n];
    for(int k = 0 ; k < n ; k++){
        if(i < ln && j < rn){
            if(sorted_left[i] < sorted_right[j]){
                sorted[k] = sorted_left[i++];
            }else{
                sorted[k] = sorted_right[j++];
            }
        }else if(i < ln){
            sorted[k] = sorted_left[i++];
        }else{
            sorted[k] = sorted_right[j++];
        }
    }
    return sorted;
}
