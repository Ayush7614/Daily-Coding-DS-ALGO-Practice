class Solution {
    public boolean checkIfPangram(String sentence) {
        Map<Integer,Integer> map = new HashMap<Integer,Integer>();
        String alph = "abcdefghijklmnopqrstuvwxyz";
        for (int i = 0 ; i < alph.length(); i++){
            if(!sentence.contains(alph.substring(i,i+1))){
                return false;
            }
        }
        return true;

    }
}


// Example test cases
//
// Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
// Output: true
//
// Input: sentence = "leetcode"
// Output: false
