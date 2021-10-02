// https://www.interviewbit.com/problems/largest-number/


bool comp( string s1, string s2){
    
    return s1.append(s2) > s2.append(s1);
}
 
string Solution::largestNumber(const vector<int> &A) {
    
    vector<string> vect(A.size());
    string st = "";
    
    for(int i = 0 ; i < A.size() ; i++)
        vect[i] = to_string(A[i]);
        
    sort(vect.begin(),vect.end(),comp);
    
    for( auto x : vect)
        st += x;
    
    int i = 0;
    while( i < st.length()-1 && st[i] == '0')
        i++;
        
    return st.substr(i);
}
