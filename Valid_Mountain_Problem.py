def Valid_Mount(arr:list[int]):
    if len(arr) < 3 :
        return False
    else :
        for i in range(0, len(arr)-1 ):
            if arr[i+1] > arr[i] :
                continue
            else :
                break

        for j in range(i , len(arr)-1 ) :
            if arr[j+1] < arr[j] :
                continue
            else :
                return False

        return True


#Input = [1,2,3,4,4*(-1)]
#Output = True

#Input = [1,2,3,4,5,5] 
#Output = False

#Input = [1,2,3,4,5,4]
#Output = True

#Input = [1,3,2,6,4,7]
#Output = False
