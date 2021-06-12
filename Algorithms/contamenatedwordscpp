#include <bits/stdc++.h>
using namespace std;
void print_vector(vector<auto> v){
   cout << "[";
   for(int i = 0; i<v.size(); i++){
      cout << v[i] << ", ";
   }
   cout << "]"<<endl;
}
struct Node{
   bool isEnd;
   map <char, Node*> child;
   Node(){
      isEnd = false;
   }
};
class Solution {
public:
   bool isPresent(string str, Node* head, int idx, vector <int>& dp){
      if(idx >= str.size())return true;
      if(dp[idx] != -1)return dp[idx];
      Node* curr = head;
      bool ok = false;
      for(int i = idx; i < str.size(); i++){
         char x = str[i];
         if(!curr->child[x]){
            break;
         }else{
            curr = curr->child[x];
         }
         if(curr->isEnd){
            ok |= isPresent(str, head, i + 1, dp);
         }
      }
      return dp[idx] = ok;
   }
   static bool cmp(string s1, string s2){
      return s1.size() < s2.size();
   }
   void insertNode(Node* head, string s){
      Node* curr = head;
      for(int i = 0; i < s.size(); i++){
         char x = s[i];
         if(!curr->child[x]){
            curr->child[x] = new Node();
         }
         curr = curr->child[x];
      }
      curr->isEnd = true;
   }
   vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
      Node* head = new Node();
      sort(words.begin(), words.end(), cmp);
      vector <string> ret;
      for(int i = 0; i < words.size(); i++){
         string curr = words[i];
         if(curr=="")continue;
         vector <int> dp(curr.size(), -1);
         if(isPresent(curr, head, 0, dp)){
            ret.push_back(curr);
         }else{
            insertNode(head, curr);
         }
      }
      return ret;
   }
};
main(){
   Solution ob;
   vector<string> v =    {"cow","cows","cowsgoatcows","goat","goatcowsgoat","hippopotamuses","deer","deercowgoatcow"};
   print_vector(ob.findAllConcatenatedWordsInADict(v));
}