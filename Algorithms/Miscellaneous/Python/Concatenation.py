class Solution(object):
    def find(self,words):
        Dict = set(words)
        cache = {}
        return [word for word in words if self.Form(word, Dict, cache)]
    def Form(self,word,Dict,cache):
        if word in cache:
            return cache[word]

        for index in range(1,len(word)):
            prefix = word[:index]
            suffix = word[index:]
            if prefix in Dict:
                if suffix in Dict or self.Form(suffix, Dict, cache):
                    cache[word]=True
                    return True
        cache[word]=False
        return False





input1 = input("Enter the input strings separated by comma : ") # user input of strings in list
l = input1.split(",")
print(Solution().find(l))

#OUTPUT TERMINAL
#PS C:\Users\mdine\OneDrive\Desktop\100DaysOfCode\Day11> python Concatenation.py
#Enter the input strings separated by comma : tech,lead,techlead,cat,cats,dog,catsdog
#['techlead', 'catsdog']
