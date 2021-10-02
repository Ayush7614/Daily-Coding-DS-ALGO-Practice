// https://www.interviewbit.com/problems/add-one-to-number/
// O(N) Time O(1) Space

 vector<int> Solution::plusOne(vector<int> &A) {
  
  int carry = 1,i;
    for( i = A.size()-1; i >= 0 ; i--){
        
        A[i] += carry;
        carry = A[i]/10;
        
        if( A[i] < 10)
            break;
        A[i] = A[i]%10;
    }
    
    while(carry){
        
        if(i > -1){
            A[i] += carry;
            carry = A[i]/10;
            A[i] = A[i]%10;
        }
        
        else{
            A.insert(A.begin(),1);
            return A;
        }
    }
    // to avoid initial zeroes
    i = 0;
    while( A[i] == 0){
        i++;
        A.erase(A.begin());
    }
    return A;
}


