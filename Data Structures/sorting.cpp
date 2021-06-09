#include <bits/stdc++.h>
using namespace std;

ostream &operator<<(ostream &os, vector<int> arr){
    for (int i = 0; i < arr.size(); ++i){
        os << arr[i] << " ";
    }
    return os;
}

void swap(int &a, int &b){
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

int partition(int *arr, int lb, int ub){
    int pivot = arr[lb];
    int start = lb;
    int end = ub;
    while (start < end){
        while (arr[start] <= pivot){
            start++;
        }
        while (arr[end] > pivot){
            end--;
        }
        if (start < end)
            swap(arr[start], arr[end]);
    }
    swap(arr[end], arr[lb]);
    return end;
}

void quickSort(int *arr, int lb, int ub){
    if (lb < ub){
        int pivot = partition(arr, lb, ub);
        quickSort(arr, lb, pivot - 1);
        quickSort(arr, pivot + 1, ub);
    }
}

void merge(int *arr, int l, int m, int h){
    int i = l;
    int j = m + 1;
    int b[h];
    int k = l;
    while (i <= m && j <= h){
        if (arr[i] <= arr[j]){
            b[k] = arr[i];
            i++;
        } else{
            b[k] = arr[j];
            j++;
        }
        k++;
    }
    if (i > m){
        while (j <= h){
            b[k] = arr[j];
            k++;
            j++;
        }
    } else if (j > h){
        while (i <= m){
            b[k] = arr[i];
            i++;
            k++;
        }
    }
    for (int i = l; i <= h; ++i){
        arr[i] = b[i];
    }
}

void mergeSort(int *arr, int l, int h){
    if (l < h){
        int mid = (l + h) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, h);
        merge(arr, l, mid, h);
    }
}


void countSort(vector<int> &vec){
    int ma = *max_element(vec.rbegin(),vec.rend());
    // cout<<ma<<endl;
    vector<int> count(ma+1);
    for(int i = 0;i<vec.size();++i){
        count[vec[i]]++;
    }
    // cout<<count<<endl;

    for(int i=1;i<count.size();++i){
        count[i] += count.at(i-1);
    }
   


    vector<int> ne(vec.size()+1);
    for(int i=vec.size()-1;i>=0;i--){
        count[vec.at(i)]--;
        ne[count[vec.at(i)]] = vec.at(i);
    }

    for(int i=0;i<vec.size();i++){
        vec[i] = ne[i];
    }

}


void bubbleSort(int *arr, int n){
    for (int i = 0; i < n - 1; ++i){
        for (int j = i + 1; j < n; ++j){
            if (arr[i] > arr[j]){
                swap(arr[i],arr[j]);
            }
        }
    }
}

struct node{
    int data;
    struct node *left;
    struct node *right;
    node(){};
    node(int a){
        this->data = a;
        this->left = NULL;
        this->right = NULL;
    }
};

typedef struct node Node;

class BST{

public:
    Node *root = NULL;
    BST() {}

    BST(BST *B){
        this->root = B->root;
    }

    BST(int *arr, int size){
        for (int i = 0; i < size; i++){
            this->insert(arr[i]);
        }
    }

    void insert(int data){
        Node *temp = new Node;
        temp->data = data;
        Node *prev = NULL;
        Node *curr = root;
        if (root == NULL){
            root = temp;
        }
        else{
            while (curr != NULL){
                prev = curr;
                if (data >= curr->data){
                    curr = curr->right;
                } else if (data < curr->data){
                    curr = curr->left;
                }
            }
            if (prev->data > data){
                prev->left = temp;
            } else{
                prev->right = temp;
            }
        }
    }

    void inOrderPrint(Node *root, vector<int> &arr){
        if (root == NULL)
            return;
        inOrderPrint(root->left, arr);
        arr.push_back(root->data);
        inOrderPrint(root->right, arr);
    }
};

vector<int> treeSort(int *arr, int size){
    BST tree = new BST(arr, size);
    vector<int> vec;
    tree.inOrderPrint(tree.root, vec);
    return vec;
}

void countSortForRadix(vector<int> &vec,int n){

    vector<int> count(10);
    for(int i = 0;i<vec.size();++i){
        count[(vec[i]/n)%10]++;
    }

    for(int i=1;i<count.size();++i){
        count[i] += count.at(i-1);
    }
   


    vector<int> ne(vec.size()+1);
    for(int i=vec.size()-1;i>=0;i--){
        count[(vec.at(i)/n)%10]--;
        ne[count[(vec.at(i)/n)%10]] = vec.at(i);
    }

    for(int i=0;i<vec.size();i++){
        vec[i] = ne[i];
    }

}


void radixsort(vector<int> &vec){
    int ma = *max_element(vec.begin(),vec.end());
    for(int pos = 1;ma/pos >0; pos*=10){
        countSortForRadix(vec,pos);
    }
}


int main(){
    int arr[] = {10, 2, 20, 4, 21, 12, 5, 43, 2, 2, 3, 5};
    // cout<<(arr,12);
    vector<int> vec = treeSort(arr, 12);
    cout << vec;
    return 0;
}