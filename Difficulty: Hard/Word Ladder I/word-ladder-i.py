from collections import deque
class Solution:
	def wordLadderLength(self, startWord, targetWord, wordList):
		#Code here
		word_set = set(wordList)
        
        if targetWord not in word_set:
            return 0
            
        queue = deque([(startWord, 1)])
        
        while queue:
            word, steps = queue.popleft()
            
            if word == targetWord:
                return steps
                
            # Generate all possible transformations
            for i in range(len(word)):
                for ch in 'abcdefghijklmnopqrstuvwxyz':
                    if ch != word[i]:
                        new_word = word[:i] + ch + word[i+1:]
                        if new_word in word_set:
                            word_set.remove(new_word)
                            queue.append((new_word, steps + 1))
                            
        return 0
		    
		  
		