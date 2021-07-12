def trapping_rainwater(arr,n):
	# max water that can be stored
	total_water=0

	for i in range(1,n-1):
		# max element from left
		left=arr[i]
		for j in range(i):
			left=max(left,arr[j])

		# max element from rightg
		right=arr[i]
		for j in range(i+1,n):
			right=max(right,arr[j])
		# update maximum water
		total_water=total_water+(min(left,right)-arr[i])
	return total_water

if __name__=="__main__":
	array=[]
	n=int(input("size of array ?"))
	for k in range(0,n):
		a=int(input("array elements"))
		array.append(a)

	ans=trapping_rainwater(array,n)
	print(ans)



