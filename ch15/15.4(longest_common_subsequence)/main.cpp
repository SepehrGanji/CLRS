#include <iostream>

using namespace std;

int LCS(char*, int, char*, int);
void print_LCS(char*, char**, int, int);

int main(){
    int seq1_len, seq2_len;
    cout << "Enter the length of sequences: ";
    cin >> seq1_len >> seq2_len;
    char *seq1 = new char[seq1_len+1];
    char *seq2 = new char[seq2_len+1];
    cout << "Enter the sequences: " << endl;
    cin >> seq1 >> seq2;
    int len = LCS(seq1, seq1_len, seq2, seq2_len);
    cout << "\nlen is " << len << '\n';
    return 0;
}

int LCS(char *s1, int s1_len, char *s2, int s2_len){
    int **c = new int*[s1_len + 1];
    char **t = new char*[s1_len];
    for(int i = 0 ; i <= s1_len ; i++)
        c[i] = new int[s2_len + 1];
    for(int i = 0 ; i < s1_len ; i++)
        t[i] = new char[s2_len];
    for(int i = 0 ; i <= s1_len ; i++)
        c[i][0] = 0;
    for(int j = 0 ; j <= s2_len ; j++)
        c[0][j] = 0;
    for(int i = 1 ; i <= s1_len ; i++){
        for(int j = 1 ; j <= s2_len ; j++){
            if(s1[i-1] == s2[j-1]){
                c[i][j] = c[i-1][j-1] + 1;
                t[i-1][j-1] = 'c';
            }else if(c[i-1][j] > c[i][j-1]){
                c[i][j] = c[i-1][j];
                t[i-1][j-1] = 'u';
            }else{
                c[i][j] = c[i][j-1];
                t[i-1][j-1] = 'l';
            }
        }
    }
    cout << "Longest subseq : ";
    print_LCS(s1, t, s1_len-1, s2_len-1);
    return c[s1_len][s2_len];
}

void print_LCS(char *s1, char **t, int i, int j){
    if(i < 0 or j < 0){
        return;
    }
    if(t[i][j] == 'c'){
        print_LCS(s1, t, i-1, j-1);
        cout << s1[i];
    }else if(t[i][j] == 'u')
        print_LCS(s1, t, i-1, j);
    else
        print_LCS(s1, t, i, j-1);
}
