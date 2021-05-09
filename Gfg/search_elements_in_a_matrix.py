class Solution:
    def searchMatrix(self, matrix, target):
        
        output = False
        if len(matrix) == 1 and len(matrix[0]) == 1:
            if target == matrix[0][0]:return True 
            else:return False
            
        j = len(matrix[0]) - 1
        for i in range(len(matrix)):
            if target == matrix[i][j]:
                return True
            elif target < matrix[i][j]:
                output = self.search(matrix[i], target)
                break
        return output
    
    def search(self, arr, target):
        beg_index = 0
        end_index = len(arr) - 1
        while beg_index <= end_index :
            mid = (beg_index + end_index ) // 2
            if arr[mid] == target:
                return True
            elif target < arr[mid]:
                end_index = mid - 1
            else:
                beg_index = mid + 1
        return False
