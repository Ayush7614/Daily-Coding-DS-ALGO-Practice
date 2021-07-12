
import java.util.*;
import javafx.util.Pair;
class SolutionApproach{
    public static String minimumWindow(String str, String test) {

        if (str.length() == 0 || test.length() == 0) {
            return "";
        }

        Map<Character, Integer> dic = new HashMap<Character, Integer>();

        for (int i = 0; i < test.length(); i++) {
            int count = dic.getOrDefault(test.charAt(i), 0);
            dic.put(test.charAt(i), count + 1);
        }

        int required = dic.size();

        List<Pair<Integer, Character>> filteredS = new ArrayList<Pair<Integer, Character>>();
        for (int i = 0; i < str.length(); i++) {
            char c = str.charAt(i);
            if (dic.containsKey(c)) {
                filteredS.add(new Pair<Integer, Character>(i, c));
            }
        }

        int l = 0, r = 0, form = 0;
        Map<Character, Integer> windowCounts = new HashMap<Character, Integer>();  
        int[] ans = {-1, 0, 0};
        while (r < filteredS.size()) {
            char c = filteredS.get(r).getValue();
            int count = windowCounts.getOrDefault(c, 0);
            windowCounts.put(c, count + 1);

            if (dic.containsKey(c) && windowCounts.get(c).intValue() == dic.get(c).intValue()) {
                form++;
            }

            while (l <= r && form == required) {
                c = filteredS.get(l).getValue();
                int end = filteredS.get(r).getKey();
                int start = filteredS.get(l).getKey();
                if (ans[0] == -1 || end - start + 1 < ans[0]) {
                    ans[0] = end - start + 1;
                    ans[1] = start;
                    ans[2] = end;
                }

                windowCounts.put(c, windowCounts.get(c) - 1);
                if (dic.containsKey(c) && windowCounts.get(c).intValue() < dic.get(c).intValue()) {
                    form--;
                }
                l++;
            }
            r++;   
        }
        return ans[0] == -1 ? "" : str.substring(ans[1], ans[2] + 1);
    }
    
    public static void main(String[] args){
        Scanner scn=new Scanner(System.in);
        String s=scn.nextLine();
        String t=scn.nextLine();
        System.out.println(minimumWindow(s,t));
        
    }
}


/*

Example1:

Input :
str="ADOBECODEBANC"
test="ABC"

Output:
"BANC"


Example2:

Input:
str="a"
test="a"

Output:
"a"

*/