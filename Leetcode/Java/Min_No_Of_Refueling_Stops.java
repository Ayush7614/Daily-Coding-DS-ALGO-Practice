class Min_No_Of_Refueling_Stops{
    public int minRefuelStops(int target, int startFuel, int[][] stations) {
        int n = stations.length;
        long[] dp = new long[n+1];
        dp[0] = startFuel;
        for (int i = 0; i < n; i++){
            for (int t = i; t >= 0; t--){
                if (dp[t] >= stations[i][0]){
                    dp[t+1] = Math.max(dp[t+1], dp[t]+(long)stations[i][1]);
                }
            }
        }
        for (int i = 0; i <= n; i++){
            if (dp[i] >= target) return i;
        }
        return -1;
    }
}