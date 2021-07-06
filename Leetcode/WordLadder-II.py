class Solution:
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
        
        #remove the dublicates present in the list
        wordList = set(wordList)
        
        # create a dict and store the beginWord
        layer = {}
        layer[beginWord] = [[beginWord]]
        
        while layer:
            nl = collections.defaultdict(list)
            #check for every word present in the current layer
            for word in layer:
                #if the endWord is found 
                if word == endWord:
                    return layer[word]
                
                for i in range(len(word)):
                    #replacing every character to create a new word 
                    for c in "abcdefghijklmnopqrstuvwxyz":
                        nw = word[:i] + c + word[i+1:]
                        # if we find the newly created word is in the given wordList 
                        if nw in wordList:
                            nl[nw] += [j + [nw] for j in layer[word]]
            
            #remove the word from the wordList that have been found and continue the same operations in the newly made dict to find the next word.
            wordList -= set(nl.keys())
            layer = nl
        #return an empty list if no sequence exists
        return []
        
