class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        'transpose the matrix'
        for i in range (0, len(matrix)):
            for j in range (i+1, len(matrix)):
                matrix[i][j] , matrix[j][i] = (matrix[j][i], matrix[i][j])
        

        'reverse the rows'
        for row in matrix: 
            row.reverse()
        