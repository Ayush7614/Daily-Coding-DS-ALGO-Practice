def Valid_Mount(arr:list[int]):
    if len(arr) < 3 :
        return False
    else :
        result = False
        for i in range(0, len(arr)-1 ):
            if arr[i+1] > arr[i] :
                # result = True
                continue
            else :
                break

        for j in range(i , len(arr)-1 ) :
            if arr[j+1] < arr[j] :
                # result = True
                continue
            else :
                # result = False
                return False

        # return result
        return True


print(Valid_Mount([1,2,3,4,4*(-1)])) # True

print(Valid_Mount([1,2,3,4,5,5]))  # False

print(Valid_Mount([1,2,3,4,5,4]))  # True

print(Valid_Mount([1,3,2,6,4,7]))  # False