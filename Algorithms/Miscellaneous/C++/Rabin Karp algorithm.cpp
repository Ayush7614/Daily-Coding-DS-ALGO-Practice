// Rabin-Karp algorithm in C++

#include<bits/stdc++.h>
using namespace std;
int main (){
   char txt[80], pat[80];
   int q;
   cout<<"Enter the string to be searched : ";
   cin>>txt;
   cout<<"Enter the pattern : ";
   cin>>pat;
   int d = 256;
   cout<<"Enter the prime number : ";
   cin>>q;
   int M = strlen (pat);
   int N = strlen (txt);
   int i, j;
   int p = 0;
   int t = 0;
   int h = 1;
   for (i = 0; i < M - 1; i++)
      h = (h * d) % q;
   for (i = 0; i < M; i++){
      p = (d * p + pat[i]) % q;
      t = (d * t + txt[i]) % q;
   }
   for (i = 0; i <= N - M; i++){
      if (p == t){
         for (j = 0; j < M; j++){
            if (txt[i + j] != pat[j])
            break;
         }
         if (j == M)
            cout<<"Pattern found at index : "<<i<<endl;
      }
      if (i < N - M){
         t = (d * (t - txt[i] * h) + txt[i + M]) % q;
         if (t < 0)
            t = (t + q);
      }
   }
   return 0;
}


/*
Input:
Enter the string to be searched : SUNDAY
Enter the pattern : DAY
Enter the prime number : 13

Output:
Pattern found at index : 3



The time complexity of the searching phase of the Karp-Rabin algorithm is O(mn) (when searching for am in an for instance).
Its expected number of text character comparisons is O(n+m)

*/
  
 
