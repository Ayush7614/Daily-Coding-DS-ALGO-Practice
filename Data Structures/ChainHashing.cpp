#include<bits/stdc++.h>

using namespace std;

class ChainHashing
{
private:
    int capacity;
    int sz = 0;
    vector<int>* myhash;
    int hash(int key){
        return key%capacity;
    }
public:
    ChainHashing(){
        capacity = 19;
        myhash = new vector<int>[capacity];
    }
    ChainHashing(int cap){
        capacity = cap;
        myhash = new vector<int>[capacity];
    }
    bool search(int key){
        int h = hash(key);
        for(int i = 0; i < myhash[h].size(); i++){
            if(myhash[h][i] == key){
                return true;
            }
        }
        return false;
    }
    bool insert(int key){
        if(search(key)){
            return false;
        }
        int h = hash(key);
        myhash[h].push_back(key);
        sz++;
        return true;
    }
    bool remove(int key){
        int h = hash(key);
        for(int i = 0; i < myhash[h].size(); i++){
            if(myhash[h][i] == key){
                myhash[h].erase(myhash[h].begin() + i);
                sz--;
                return true;
            }
        }
        return false;
    }
    int size(void){
        return sz;
    }
};

int main() 
{
    int capacity;
    cout << "Enter the capacity of hash table" << endl;
    cin >> capacity;

    ChainHashing hash(capacity);
    cout << "Result of insert 1 is " << (bool)hash.insert(1) << endl; // returns true because it will add 1 successfully in hash table
    cout << "Result of insert 2 is " << (bool)hash.insert(2) << endl; // returns true because it will add 2 successfully in hash table
    cout << "Result of insert 3 is " << (bool)hash.insert(3) << endl; // returns true because it will add 3 successfully in hash table
    cout << "Result of insert 4 is " << (bool)hash.insert(4) << endl; // returns true because it will add 4 successfully in hash table
    cout << "Result of insert 5 is " << (bool)hash.insert(5) << endl; // returns true because it will add 5 successfully in hash table
    cout << "Result of insert 6 is " << (bool)hash.insert(6) << endl; // returns true because it will add 6 successfully in hash table
    cout << "Result of insert 7 is " << (bool)hash.insert(7) << endl; // returns true because it will add 7 successfully in hash table
    cout << "Result of insert 8 is " << (bool)hash.insert(8) << endl; // returns true because it will add 8 successfully in hash table
    cout << "Result of insert 9 is " << (bool)hash.insert(9) << endl; // returns true because it will add 9 successfully in hash table
    cout << "Result of insert 10 is " << (bool)hash.insert(10) << endl; // returns true because it will add 10 successfully in hash table
    cout << "Result of insert 1 is " << (bool)hash.insert(1) << endl << endl; // returns false because it can not add 1 in the hash table as it is already present in the hash table

    cout << "Result of search 1 is " << (bool)hash.search(1) << endl; // returns true because 1 is present in the hash table
    cout << "Result of search 11 is " << (bool)hash.search(11) << endl << endl; // returns false because 11 is not present in the hash table
    
    cout << "Result of size is " << hash.size() << endl << endl; // returns total elements preasents in the hash table

    cout << "Result of remove 10 is " << (bool)hash.remove(10) << endl << endl; // returns true because it will successfully remove 10 from hash table

    cout << "Result of search 10 is " << (bool)hash.search(10) << endl << endl; // returns false because 10 is not present in the hash table

    cout << "Result of size is " << hash.size() << endl << endl; // returns total elements preasents in the hash table

    cout << "Result of remove 12 is " << (bool)hash.remove(12) << endl << endl; // returns false because it can not remove 12 from hash table as it is not present in the hash table

    cout << "Result of size is " << hash.size() << endl << endl; // returns total elements preasents in the hash table
    return 0;
}
