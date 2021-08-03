// TEST CASES :-

// Sample Input 1 
// 2
// 3
// 2 1 3
// 3
// 1 1 3

// Sample Output 1 
// 3
// 1
// Explanation
// In first test case, we can make all the elements equal by following operations:

// Take i=1 and M=2 and do A1:=A1mod2=0.
// Take i=2 and M=1 and do A2:=A2mod1=0.
// Take i=3 and M=3 and do A3:=A3mod3=0.

// After these 3 operations we have all the elements equal to zero.
// In second test case, we can perform following operation:

// Choose i=3 and M=2 and do A3:=A3mod2=1.
// After this operation all the elements are 1.



#include<bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long

const int MOD = (int) 1e9 + 7;

void print_1D_vector(vector<int> &data){     
    cout<<"output is\n";
    for(auto i=data.begin();i!=data.end();i++)
        cout<<*(i)<<" ";
    cout<<endl;    
}


void print_2D_vector(vector<vector<double>> &data, int m, int n){
    cout<<"Output :"<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<data[i][j]<<" ";
        }
        cout<<endl;
    }
}

void input_1D_vector(vector<int> &data, int n){
    int num;
    for(int i=0;i<n;i++){
        cin>>num;
        data.push_back(num);
    }
}
void input_2D_vector(vector<vector<double>> &data, int rows, int col){
    double num;
    for(int i = 0; i < rows; i++){
    vector<double> temp;
    for(int j = 0; j < col; j++){
        cin >> num;
        temp.push_back(num);
    }
    data.push_back(temp);
    temp.clear();
    }
}
int gcd(int a, int b){
  if (b == 0)
    return a;
    if(a > b)
        return gcd(b, a % b);
    else
        return gcd(a, b % a);
}
bool isPrime(int n)
{
    // Corner case
    if (n <= 1)
        return false;
  
    // Check from 2 to n-1
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
  
    return true;
}
  
bool isPossible2(int x,int minElement){
    if(x==minElement)
        return true;
    if(minElement<(x+1)/2)
        return true;
    return false;
}

int fnx(){
    int n;
    cin>>n;
    if(n==1)
        return 0;
    vector<int> data;
    input_1D_vector(data,n);
    int minElement = *min_element(data.begin(),data.end());
    int result = 0;
    for(int i=0; i<n; i++){
        if(!isPossible2(data[i],minElement)){
            return n;
        }
        if(data[i] != minElement)
            result++;
    }
    
    return result;
}

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cout<<fnx()<<endl;         
    }
    return 0;
}
