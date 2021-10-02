// https://www.interviewbit.com/problems/max-min-05542f2f-69aa-4253-9cc7-84eb7bf739c4/
// O(N) Time O(N) Comparisions

int Solution::solve(vector<int> &A) {
    
    int min=A[0],max=A[0];
    for (int i=0;i<A.size();i++){

        if(A[i]<min)
            min=A[i];
        if(A[i]>max)
            max=A[i];
    }
    return min+max;
}
