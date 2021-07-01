class Longest_valid_parenthesis{
    public int longestValidParentheses(String s) {
        int n = s.length();
        int[] dp = new int[n];
        int max = 0;
        for (int i = 1; i < s.length(); i++){
            if (s.charAt(i) == ')' && s.charAt(i-1) == '('){
                dp[i] = (i >= 2 ? dp[i-2] : 0)+2;
            } else if (s.charAt(i) == ')' && s.charAt(i-1) == ')'){
                if (i-dp[i-1] > 0 && s.charAt(i-dp[i-1]-1) == '('){
                    dp[i] = dp[i-1] + (i-dp[i-1] >= 2 ? dp[i-dp[i-1]-2] : 0) + 2;
                }
            }
            max = Math.max(max, dp[i]);
        }
        return max;
    }
}