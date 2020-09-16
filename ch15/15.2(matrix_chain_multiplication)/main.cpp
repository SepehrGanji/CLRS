#include <iostream>
#include <climits>

using namespace std;

void compute_min_cost(int*, int);
void print_chain_mul(int**, int, int);

int main(){
    int n = 0;
    cout << "Enter chain length: ";
    cin >> n;
    cout << "Enter matrix dimentions(without repeating)" << endl;
    cout << "For example 3 matrixes 2x3 and 3x5 and 5x6 is 2 3 5 6" << endl;
    int *dim = new int[n + 1];
    for(int i = 0 ; i <= n ; i++)cin >> dim[i];
    compute_min_cost(dim, n);
    return 0;
}

void compute_min_cost(int *dim, int n){
    int **m = new int*[n];//for optimal cost
    int **s = new int*[n];//for constructing the answer
    for(int i = 0 ; i < n ; i++){
        m[i] = new int[n];
        s[i] = new int[n];
    }
    for(int i = 0 ; i < n ; i++)m[i][i] = 0;
    for(int l = 2 ; l <= n ; l++){
        for(int i = 0 ; i <= n - l ; i++){
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for(int k = i ; k < j ; k++){
                int q = m[i][k] + m[k+1][j] + (dim[i] * dim[k+1] * dim[j+1]);
                if(q < m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    print_chain_mul(s, 0, n-1);
    cout << "\nFinalCost : " << m[0][n-1] << endl;
}

void print_chain_mul(int **s, int i, int j){
    if(i == j){
        cout << "A" << i;
        return;
    }
    int k = s[i][j];
    cout << "(";
    print_chain_mul(s, i, k);
    print_chain_mul(s, k+1, j);
    cout << ")";
}
