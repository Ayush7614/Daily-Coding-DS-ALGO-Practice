class Solution:
    def countAndSay(self, n):
        if (n == 1):
            return ("1")
        
        s = self.countAndSay(n-1)
        
        ret = ""
        cnt = 1
        i = 1
        while i < len(s) + 1:
            if i < len(s) and s[i] == s[i-1]:
                cnt += 1
            else:
                ret += str(cnt) + str(s[i-1])
                cnt = 1
            i += 1
            
        return (ret)
