class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        # //set of words
        #//first word in the queue
        # //change char , until word from wordlist found
        # //continue and increase the levels accordingly 
        # //do until endword found, return the count of levels

        # set for O(1) lookup 
        words = set(wordList)
        q = deque()
        q.append(beginWord)

        level = 1

        while q:
            n = len(q)

            for _ in range(n):
                word = q.popleft()
                if word == endWord :
                    return level
                for j in range(len(word)):
                    for ch in "abcdefghijklmnopqrstuvwxyz":
                        new = word[:j] +ch +word[j+1:]

                        if new in words:
                            q.append(new)
                            words.remove(new)
            level += 1
        return 0
        