#include <iostream>

using namespace std;

struct node{
    int value;
    node *right_child = NULL;
    node *left_child = NULL;
};

void showtree(node *root){
    if(root){
        cout << root->value << ' ';
        showtree(root->left_child);
        showtree(root->right_child);
    }
}

void insert_to_tree(int e, node *root){
    node *parent = NULL;
    node *current = root;
    bool flag = false;
    while(current){
        parent = current;
        if(e < current->value){
            current = current->left_child;
            flag = false;
        }else{
            current = current->right_child;
            flag = true;
        }
    }
    node *new_node = new node();
    new_node->value = e;
    if(!flag)
        parent->left_child = new_node;
    else
        parent->right_child = new_node;
}

void remove_from_tree(int e, node *root){
    node *parent = NULL;
    node *current = root;
    bool flag = false;
    while(current && current->value != e){
        parent = current;
        if(e < current->value){
            current = current->left_child;
            flag = false;
        }else{
            current = current->right_child;
            flag = true;
        }
    }
    if(!current){
        cout << "Element does'nt exist in tree" << endl;
        return;
    }
    //#TODO check root removal
    if(!current->left_child && !current->right_child){
        //no child
        free(current);
        if(flag)
            parent->right_child = NULL;
        else
            parent->left_child = NULL;
    }else if(!current->left_child && current->right_child){
        //has right child
        if(flag)
            parent->right_child = current->right_child;
        else
            parent->left_child = current->right_child;
        free(current);
    }else if(current->left_child && !current->right_child){
        //has left child
        if(flag)
            parent->right_child = current->left_child;
        else
            parent->left_child = current->left_child;
        free(current);
    }else{
        //two childs
        //finding first right child that has no left child!!!
        node *y = current->right_child;
        node *y_parent = current;
        bool f = true;
        while(y->left_child){
            f = false;
            y_parent = y;
            y = y->left_child;
        }
        if(f)
            y_parent->right_child = y->right_child;
        else
            y_parent->left_child = y->right_child;
        if(flag)
            parent->right_child = y;
        else
            parent->left_child = y;
        free(current);
    }
}

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
        insert_to_tree(arr[i], root);
    }
    cout << "BST created succesfully!" << endl;
    node *max_node = root;
    while(max_node->right_child != NULL)max_node = max_node->right_child;
    cout << "Max value in tree is : " << max_node->value << endl;
    node *min_node = root;
    while(min_node->left_child != NULL)min_node = min_node->left_child;
    cout << "Min value in tree is : " << min_node->value << endl;
    showtree(root);
    cout << '\n';
    int e;
    do{
        cout << "Enter the element to remove (9733713 to stop!): " ;
        cin >> e;
        if(e == 9733713)break;
        remove_from_tree(e, root);
        showtree(root);
        cout << '\n';
    }while(1);
    return 0;
}
