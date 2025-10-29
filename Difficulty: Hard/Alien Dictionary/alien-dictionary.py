from collections import deque

class Solution:
    def findOrder(self, words):
        # Create adjacency list for 26 letters
        adj = [[] for _ in range(26)]
        
        # Build graph
        for i in range(len(words) - 1):
            s1 = words[i]
            s2 = words[i + 1]
            length = min(len(s1), len(s2))
            found_diff = False
            for ptr in range(length):
                if s1[ptr] != s2[ptr]:
                    u = ord(s1[ptr]) - ord('a')
                    v = ord(s2[ptr]) - ord('a')
                    adj[u].append(v)
                    found_diff = True
                    break
            # If no difference found and s1 is longer than s2, invalid order
            if not found_diff and len(s1) > len(s2):
                return ""
        
        # Find all unique characters used
        present = [False] * 26
        for word in words:
            for ch in word:
                present[ord(ch) - ord('a')] = True
        unique_chars = sum(present)
        
        # Build indegree array
        indegree = [0] * 26
        for i in range(26):
            for it in adj[i]:
                indegree[it] += 1
        
        # Topological sort BFS
        q = deque()
        for i in range(26):
            if present[i] and indegree[i] == 0:
                q.append(i)
        
        ans = []
        while q:
            node = q.popleft()
            ans.append(node)
            for it in adj[node]:
                indegree[it] -= 1
                if indegree[it] == 0:
                    q.append(it)
        
        # Check if all unique chars are in result (no cycle)
        if len(ans) != unique_chars:
            return ""
        
        # Convert back to characters
        return ''.join(chr(ord('a') + idx) for idx in ans)