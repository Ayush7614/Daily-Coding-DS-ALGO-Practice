class Solution:
    def intersect(self, suy, vin):
        i = 0
        j = 0
        result = []
        while i < len(suy) and j < len(vin):
            if suy[i] == vin[j]:
                result.append(suy[i])
                i += 1
                j += 1
            elif suy[i] < vin[j]:
                i += 1
            else:
                j += 1
        return result
