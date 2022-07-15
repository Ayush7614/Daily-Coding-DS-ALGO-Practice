
    /*

    Given a Binary Tree, find size of the Largest Independent Set(LIS) in it.
    A subset of all tree nodes is an independent set if there is no edge between any two nodes of the subset.

    */


    #include <bits/stdc++.h>
    #include <cstdio>
    #include <cstring>
    #include <cmath>
    #include <cstring>
    #include <chrono>
    #include <complex>
    #define endl "\n"
    #define ll long long int
    #define vi vector<int>
    #define vll vector<ll>
    #define vvi vector < vi >
    #define pii pair<int,int>
    #define pll pair<long long, long long>
    #define mod 1000000007
    #define inf 1000000000000000001;
    #define all(c) c.begin(),c.end()
    #define mp(x,y) make_pair(x,y)
    #define mem(a,val) memset(a,val,sizeof(a))
    #define eb emplace_back
    #define f first
    #define s second
    
    using namespace std;

    class node {

    public:
        int liss;
        int data;
        node *left,*right;

    };


    int LISS(node *root) {

        if(root==NULL) {
            return 0;
        }


        if(root->liss) {
            return root->liss;
        }

        if(root->left==NULL&&root->right==NULL) {
            return (root->liss=1);
        }


        int liss_exc = LISS(root->left)+LISS(root->right);

        int liss_inc=1;

        if(root->left) {
            liss_inc+=LISS(root->left->left)+LISS(root->left->right);
        }

        if(root->right) {
            liss_inc+=LISS(root->right->left)+LISS(root->right->right);
        }


        root->liss=max(liss_inc,liss_exc);

        return root->liss;

    }



    node* newNode(int data) {

            node* temp = new node();
            temp->data=data;
            temp->left=temp->right=NULL;
            temp->liss=0;

            return temp;
    }



    int main()
    {

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif


       
    node *root     = newNode(20);  
    root->left         = newNode(8);  
    root->left->left     = newNode(4);  
    root->left->right     = newNode(12);  
    root->left->right->left = newNode(10);  
    root->left->right->right = newNode(14);  
    root->right         = newNode(22);  
    root->right->right     = newNode(25);  



    cout<<LISS(root);


        return 0;
    }