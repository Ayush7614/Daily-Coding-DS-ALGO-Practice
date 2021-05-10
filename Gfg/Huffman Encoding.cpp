#include<vector>
using namespace std;

struct MinHeapNode {
    char symbol;
    int freq;
    MinHeapNode *left, *right;
    MinHeapNode(char symbol, int freq)
    {
        this->left = this->right = nullptr;
        this->symbol = symbol;
        this->freq = freq;
    }
};

struct compare {
    bool operator()(MinHeapNode *left, MinHeapNode *right)
    {
        return (left->freq > right->freq);    
    }
};

void printHuffCodes(MinHeapNode *root, string str)
{
    if (root == nullptr)
        return;
    
    if (root->symbol != '#') {
        //cout << root->symbol << " " << str << " ";
        cout << str << " ";
    }
    if (root->left) printHuffCodes(root->left, str + '0');
    if (root->right) printHuffCodes(root->right, str + '1');
}

void huffmanEncode(string str, int *freq, int n)
{
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;
    
    for (int i = 0; i < n; i++) {
        minHeap.push(new MinHeapNode(str[i], freq[i]));
        //cout << str[i] << " " << freq[i] << " ";
    }
    
    while (minHeap.size() > 1) {
        MinHeapNode *left = minHeap.top();
        minHeap.pop();
        
        MinHeapNode *right = minHeap.top();
        minHeap.pop();
        
        MinHeapNode *cur = new MinHeapNode('#', left->freq + right->freq);
        cur->left = left;
        cur->right = right;
        //cout << cur->symbol << " " << cur->freq << " ";
        //cout << cur->left->symbol << " " << cur->right->freq << " ";
        //cout << cur->left->symbol << " " << cur->right->freq << " ";
        minHeap.push(cur);
    }
    
    printHuffCodes(minHeap.top(), "");
}

int main()
{
    // Note that size of arr[] is considered 100 according to
    // the constraints mentioned in problem statement.
    int freq[100], x, t, n;
    string str;
 
    // Input the number of test cases you want to run
    cin >> t;
 
    // One by one run for all input test cases
    while (t--)
    {
        cin >> str;
        //cout << str << " " << str.size() << endl;
        // Input the array
        for (int i = 0; i < str.size(); i++) {
            cin >> freq[i];
        }

        // Compute and print result
        huffmanEncode(str, freq, str.size());
        cout << endl;
    }
    return 0;
}
