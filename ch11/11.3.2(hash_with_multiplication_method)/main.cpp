#include <iostream>
#include <math.h>

using namespace std;

int hash_f(int, int, float);

int main(){
    float A = (sqrt(5) - 1) / 2;
    cout << "Enter the array size: ";
    int n;
    cin >> n;
    cout << "Enter the array: ";
    int *arr = new int[n];
    for(int i = 0 ; i < n ; i++)cin >> arr[i];
    cout << "Enter m(size of hash array): ";
    int m;
    cin >> m;
    for(int i = 0 ; i < n ; i++){
        cout << "Element " << arr[i] << " Hashed into : ";
        cout << hash_f(arr[i], m, A) << endl;
    }
    return 0;
}

int hash_f(int k, int m, float A){
    float mul = k * A;
    int integer = int(mul);
    mul -= integer;
    return abs(int(mul * m));
}
