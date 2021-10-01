#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;


#define ff                first
#define ss                second
#define int               long long
#define pb                push_back
#define mp                make_pair
#define pii               pair<int,int>
#define vi                vector<int>
#define mii               map<int,int>
#define pqb               priority_queue<int>
#define pqs               priority_queue<int,vi,greater<int> >
#define setbits(x)        __builtin_popcountll(x)
#define zrobits(x)        __builtin_ctzll(x)
#define mod               1000000007   //10^9 + 7
#define inf               1e18
#define ps(x,y)           fixed<<setprecision(y)<<x
#define mk(arr,n,type)    type*arr = new type[n]
#define w(x)              int x;cin>>x;while(x--)
#define ti(n)             int n;cin>>n
#define rep(i,n)          for(int i=0;i<(n);++i)
#define repA(i,a,n)       for(int i=a;i<=(n);++i)
#define repD(i,a,n)       for(int i=a;i>=(n);--i)
#define itr(type,it,x)    for(type it = x.begin();it!=x.end();it++)
#define endl              '\n'
#define FIO               ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
mt19937                  rng(chrono::steady_clock::now().time_since_epoch().count());  // to shuffle an array randomly viz. shuffle(arr,arr+n,rng)

typedef tree<int , null_type , less<int> , rb_tree_tag, tree_order_statistics_node_update> PBDS;  //policy based data structure


void c_p_c() {

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif
}

class Node
{
public:
    int data;
    Node* left;
    Node*right;

    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node* buildtree() {
    int d;
    cin >> d;
    Node*root = new Node(d);
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node*f = q.front();
        q.pop();
        int c1, c2;
        cin >> c1 >> c2;
        if (c1 != -1) {
            f->left = new Node(c1);
            q.push(f->left);
        }
        if (c2 != -1) {
            f->right = new Node(c2);
            q.push(f->right);
        }
    }
    return root;
}




void printLeafNodes(Node*root)
{
    if (root == NULL)
        return;

    if (root->right == NULL && root->left == NULL)
        cout << root->data << ' ';

    printLeafNodes(root->left);
    printLeafNodes(root->right);
}


void rightViewUtil(Node* root, int level, int* max_level)
{
    // Base Case
    if (root == NULL)
        return;

    // If this is the first node of its level
    if (*max_level < level) {
        cout << root->data << " ";
        *max_level = level;
    }

    // Recur for right and left subtrees
    rightViewUtil(root->right, level + 1, max_level);
    rightViewUtil(root->left, level + 1, max_level);
}

// A wrapper over rightViewUtil()
void rightView(Node* root)
{
    int max_level = 0;
    rightViewUtil(root, 1, &max_level);
}

void leftViewUtil(Node* root, int level, int* max_level)
{
    // Base Case
    if (root == NULL)
        return;

    // If this is the first node of its level
    if (*max_level < level) {
        cout << root->data << " ";
        *max_level = level;
    }

    // Recur for left and right subtrees
    leftViewUtil(root->left, level + 1, max_level);
    leftViewUtil(root->right, level + 1, max_level);
}

// A wrapper over leftViewUtil()
void leftView(Node* root)
{
    int max_level = 0;
    leftViewUtil(root, 1, &max_level);
}


void printBottomViewUtil(Node * root, int curr, int hd, map <int, pair <int, int>> & m)
{
    // Base case
    if (root == NULL)
        return;

    // If node for a particular
    // horizontal distance is not
    // present, add to the map.
    if (m.find(hd) == m.end())
    {
        m[hd] = make_pair(root -> data, curr);
    }
    // Compare height for already
    // present node at similar horizontal
    // distance
    else
    {
        pair < int, int > p = m[hd];
        if (p.second <= curr)
        {
            m[hd].second = curr;
            m[hd].first = root -> data;
        }
    }

    // Recur for left subtree
    printBottomViewUtil(root -> left, curr + 1, hd - 1, m);

    // Recur for right subtree
    printBottomViewUtil(root -> right, curr + 1, hd + 1, m);
}


void printBottomView(Node * root)
{

    // Map to store Horizontal Distance,
    // Height and Data.
    map < int, pair < int, int > > m;

    printBottomViewUtil(root, 0, 0, m);

    // Prints the values stored by printBottomViewUtil()
    map < int, pair < int, int > > ::iterator it;
    for (it = m.begin(); it != m.end(); ++it)
    {
        pair < int, int > p = it -> second;
        cout << p.first << " ";
    }
}



void fillMap(Node* root, int d, int l, map<int, pair<int, int>> &m) {
    if (root == NULL) return;

    if (m.count(d) == 0) {
        m[d] = make_pair(root->data, l);
    } else if (m[d].second > l) {
        m[d] = make_pair(root->data, l);
    }

    fillMap(root->left, d - 1, l + 1, m);
    fillMap(root->right, d + 1, l + 1, m);
}

// function should print the topView of
// the binary tree
void topView( Node *root) {

    //map to store the pair of node value and its level
    //with respect to the vertical distance from root.
    map<int, pair<int, int>> m;

    //fillmap(root,vectical_distance_from_root,level_of_node,map)
    fillMap(root, 0, 0, m);

    for (auto it = m.begin(); it != m.end(); it++) {
        cout << it->second.first << " ";
    }
}





int32_t main(int32_t argc, char const *argv[]) {

    c_p_c();


    Node* root = buildtree();

    printLeafNodes(root);
    cout << endl;
    rightView(root);
    cout << endl;
    leftView(root);
    cout << endl;
    printBottomView(root);
    cout << endl;
    topView(root);
    cout << endl;
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

/*
INPUT 1:
1 2 3 4 5 -1 6 -1 -1 -1 -1 -1 -1
INPUT 2:
1 2 3 4 5 6  -1 -1 -1 -1 -1 -1 -1
*/