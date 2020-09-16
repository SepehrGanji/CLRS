#include <iostream>
#include <climits>

using namespace std;

int max_cutting_price(int, int*, int);

int main(){
    int n;
    cout << "Enter the size of price array: ";
    cin >> n;
    int *price = new int[n];
    cout << "Enter the price array: ";
    for(int i = 0; i < n ;i++)cin >> price[i];
    int l;
    cout << "Enter the length: ";
    cin >> l;
    cout << max_cutting_price(n, price, l);
    return 0;
}

int max_cutting_price(int n, int *price, int l){
    int *r = new int[l + 1];
    r[0] = 0;
    for(int i = 1 ; i <= l ; i++){
        int q = INT_MIN;
        cout << i << endl;
        for(int j = 0 ; j < i ; j++)
            q = max(q, r[j] + price[i - j - 1]);
        r[i] = q;
    }
    return r[l];
}