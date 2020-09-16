#include <iostream>

using namespace std;

struct node{
    int value;
    node *right_child = NULL;
    node *left_child = NULL;
};


int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter the elements: ";
    for(int i = 0 ; i < n ; i++)cin >> arr[i];
    cout << "Enter the root idx: ";
    int root_idx;
    cin >> root_idx;
    if(root_idx < 0 || root_idx >= n)return -1;
    node *root = new node();
    root->value = arr[root_idx];
    for(int i = 0 ; i < n ; i++){
        if(i == root_idx)continue;
        node *current = root;
        node *before = NULL;
        int el = arr[i];
        int flag = 0;
        while(current != NULL){
            before = current;
            if(el <= current->value){
                current = current->left_child;
                flag = 0;
            }else{
                current = current->right_child;
                flag = 1;
            }
        }
        node *newnode = new node();
        newnode->value = el;
        if(flag){
            before->right_child = newnode;
        }else{
            before->left_child = newnode;
        }
    }
    cout << "BST created succesfully!" << endl;
    node *max_node = root;
    while(max_node->right_child != NULL)max_node = max_node->right_child;
    cout << "Max value in tree is : " << max_node->value << endl;
    node *min_node = root;
    while(min_node->left_child != NULL)min_node = min_node->left_child;
    cout << "Min value in tree is : " << min_node->value << endl;
    return 0;
}
