class Solution {
    public boolean arrayStringsAreEqual(String[] word1, String[] word2) {
                 StringBuilder sb1 = new StringBuilder();
                 StringBuilder sb2 = new StringBuilder();
                 for(int i=0; i<word1.length; i++){
                        sb1.append(word1[i]);
                      }
              for(int i=0; i<word2.length; i++){
                    sb2.append(word2[i]);
                   }
           return sb1.toString().equals(sb2.toString())?true:false;
    }
}
 public  void main(String[] args) {
        Solution s1=new Solution();
        String word1[]={"abc","d"};
        String word2[]={"d, abc"};
        s1.arrayStringsAreEqual(word1,word2);
    }
  /*output
   ["ab", "c"]
   ["d", "abc"]
Output
false
Expected
false*/
