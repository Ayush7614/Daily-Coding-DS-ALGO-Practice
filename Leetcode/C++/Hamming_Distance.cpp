class Solution {
public:
    int hammingDistance(int x, int y) {
        int z=x^y;
        int sum=0;
        while(z)
        {
            if(z&1) sum++;
            z=z>>1;
        }
        return sum; // returning the value
        
    }
};