// Approach
// i will solve this problem using binary search algorithm
// will find maximum number of pages each student should read is minimized.

// CONSTRAINTS
// 1. A book should be allocated completely .allocation of individual pages of books is not allowed
// 2.each student should get atleast one book
// 3. books should be allocated in contiguous manner

#include<bits/stdc++.h>
using namespace std;
 
// this function ll tells us whether maximum number of pages to be alloacted to each student passed by mid is appropriate ot not 
 bool ispossible(vector<int>v,int max_pages,int students){
         int stu=1;
         int sum_of_pages=0;
         for(int i=0;i<v.size();i++){
             sum_of_pages+=v[i];
            //  if sum of pages becomes greater than maximum pages we allocate this book to next student by incrementing stu.
             if(sum_of_pages>max_pages){
                 stu++;
                 sum_of_pages=v[i];
             }
            //  if at any point stu becomes greater tah students available we return false;
            if(stu>students){
                return false;
            }
         }
         return true;
 }

int allocate_minimum_number_of_pages(vector<int>books,int k){
    // not given whether array is sorted or not 
    // so sort it first
    sort(books.begin(),books.end());
    int e=0;
    int s=INT_MIN;
    for(auto x:books){
        s=max(s,x);
        e+=x;
    }
int ans=-1;
    // since we are trying to find minimum number of pages to be allocated so our search space will consists of pages.
    // maximum number of pages that a student can read is sum of all pages of given books i.e. e
     while(s<=e){
         int mid=s+(e-s)/2;
         if(ispossible(books,mid,k)==true){

             ans=mid;
            //  now we need to minimize it 
            // so
            e=mid-1;
         }
         else{
            //  if maximum number of pages to be allocated to each student is not suffiecient to be alloacted among 
            // available students it means we need to increase maximum number of pages that can be alloacted to each student.
            // so
             s=mid+1;
         }
     }
     return ans;
}


int main(){
    int n;
    cout<<" n";
    cin>>n;
    vector<int>pages_in_ith_book;
    for(int i=0;i<n;i++){
        int input;
        cin>>input;
        pages_in_ith_book.push_back(input);
    }
    int no_of_students;
    cout<<"no_of_students ";
    cin>>no_of_students;
    int allocation_possible=allocate_minimum_number_of_pages(pages_in_ith_book,no_of_students);
    cout<<allocation_possible;
}


// input
// int number of books =4;
//  int arr[]:{10,30,40,20};
// HOW?
// now s=40 e=100;
// mid1=(40+100)/2=70; & with 70 as max we can alloacted as 10+20+30-->s1 && 40-->s2
// hence 70 is maximum pages that we can alloacte
// now in order to minimize it we do e=mid-1=69
// mid2=54  && with 54 as max we can alloacted as 10+20-->s1 && 30-->s2 && 40-->s3 but number of students are 2 only 
// so we need to search for answer in right of mid2 s=mid2+1 ===>55
// mid3=55+69/2=62 && with 62 as max we can alloacte as 10+20+30-->s1 && 40-->s2
// hence 62 is camdidate for ans 
// again in order to minimize it we use  e=62-1 =61;
// mid4=61+55/2=58  && with 58 as max we can alloacte as 10+20-->s1 && 30-->s2 && 40-->s3 but number of students are 2 only 
//  so we need to search for answer in right of mid2 s=mid4+1 ===>59
// mid5=59+61/2=60 &&  with 60 as max we can alloacted as 10+20+30-->s1 && 40-->s2


// hence 60 is the optimal solution to our allocation of minimum number of pages problem

// time complexity: O(nlogn)  space complexity : O(1);


