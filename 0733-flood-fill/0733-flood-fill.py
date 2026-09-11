class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        if image[sr][sc] == color :
            return image
        q = deque()
        org = image[sr][sc]
        image[sr][sc] = color
        q.append((sr,sc))

        rows = [-1,1,0,0]
        cols = [0,0,-1,1]
        while q:
            r, c = q.popleft()
            for i in range (4):
                nr = r + rows[i]
                nc = c + cols[i]
                if 0<= nr<len(image) and 0<= nc<len(image[0]):
                    if(image[nr][nc] == org):
                        image[nr][nc] = color
                        q.append((nr,nc))
        
        return image
