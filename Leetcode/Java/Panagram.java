import javax.swing.plaf.TreeUI;

import jdk.internal.net.http.ResponseSubscribers.TrustedSubscriber;

##Check if Sentence is Pangram (Leetcode)

class Solution {
public boolean checkIfPangram(String sentence) {
HashSet set = new HashSet<>();
for(char ch : sentence.toCharArray()){
set.add(ch);
}
return set.size()==26;
}
}

###Test Case 

"thequickbrownfoxjumpsoverthelazydog"

Output--
True