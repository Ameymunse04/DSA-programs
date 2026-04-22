#include<iostream>

using namespace std;

struct node {
    int data;
    node* left;
    node* right;
    node(int value){
        data = value;
        left = right = nullptr;
    }
};

void inorder(node* root){
    if(root == nullptr) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(node* root){
    if(root == nullptr) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root){
    if(root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);

    cout<<"Inorder Traversal: ";
    inorder(root);
    cout << endl;

    cout<<"Preorder Traversal: ";
    preorder(root);
    cout << endl;

    cout<<"Postorder Traversal: ";
    postorder(root);
    cout << endl;

    return 0;
}
