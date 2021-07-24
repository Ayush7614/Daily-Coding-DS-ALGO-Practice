# Python 3 implementation of interpolation Search


def interpolationSearch(arr,k):
    low=0
    high=len(arr)-1
    mid=0
    
    while (arr[low]<=k) and (arr[high]>=k):
        
        if (arr[high]-arr[low])==0:
            
            return (low+high)//2
            
        mid=low+((k-arr[low])*(high-low))//(arr[high]-arr[low])
        
        if arr[mid]<k:
            
            low=mid+1
            
        elif arr[mid]>k:
            
            high=mid-1
            
        else:
            
            return mid
            
    if arr[low]==k:
        
        return low
        
    else:
        
        return -1




arr=[1,2,2,3,5,6,7,9]
k=9

print(interpolationSearch(arr,k))  #Output 7