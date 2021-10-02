// https://www.interviewbit.com/problems/triplets-with-sum-between-given-range/
// O(N) Time O(1) Space

int Solution::solve(vector<string> &A) {

int n=A.size();
double a=stod(A[0]);
double b=stod(A[1]);
double c=stod(A[2]);
 
if(a+b+c>1.0&& a+b+c<2.0)
return 1;
  
for(int i=3;i<n;i++){

if(stod(A[i]) >2.0)
continue;
 
if(a+b+c>1.0&& a+b+c<2.0)
return 1;
 
else if(a+b+c>2.0){
  
  double x=max(a,max(b,c));
  if(x==a)
    a=stod(A[i]);
    
  else if(x==b)
    b=stod(A[i]);        
  else 
    c=stod(A[i]);        
 }
 
 else  if(a+b+c<1.0){
    double x= min(a,min(b,c));  
    if(x==a)
       a=stod(A[i]);
    
    else if(x==b)
       b=stod(A[i]);        
    else 
       c=stod(A[i]); 
 }
 
 if(a+b+c>1.0&& a+b+c<2.0)
    return 1;
    }
 
 return 0;
}
