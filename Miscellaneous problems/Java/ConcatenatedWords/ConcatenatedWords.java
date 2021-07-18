package Miscellaneous

import java.util.*;

public class ConcatenatedWords {

    private static boolean concatenatedWord(String word, Set<String> layers) {

        if (layers.size() == 0) {
            return false;
        }
        int n = word.length();
        if (n == 0) {
            return false;
        }
        boolean[] dp = new boolean[n + 1];
        dp[0] = true;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (!dp[j]) {
                    continue;
                }
                if (layers.contains(word.substring(j, i))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }

    public List<String> solve(String[] words) {
        List<String> results = new ArrayList<>();
        Set<String> layers = new HashSet<>(Arrays.asList(words));

        for (String word : words) {
            layers.remove(word);
            if (concatenatedWord(word, layers)) {
                results.add(word);
            }
            layers.add(word);
        }
        return results;
    }


}
