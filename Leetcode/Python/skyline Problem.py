
def skyline(buildings):
	left = min(b[0] for b in buildings)
	right = max(b[1] for b in buildings)
	last_height = None
	output = []
	for i in range(left, right + 1):
		heights = [b[2] for b in buildings if b[0] <= i < b[1]]
		height = max(heights) if heights else 0
		if height != last_height:
			output.append([i, height])
			last_height = height

	return output

if __name__ == "__main__":
	result = skyline([(1,11,5), (2,6,7), (3,13,9), (12,7,16), (14,3,25), (19,18,22), (23,13,29),(24,4,28)])
	print(result)
	

#input = [(1,11,5), (2,6,7), (3,13,9), (12,7,16), (14,3,25), (19,18,22), (23,13,29),(24,4,28)]
#output = [[1, 5], [2, 7], [3, 9], [13, 0]]

#input = [[0,2,3],[2,5,3]]
#output = [[0, 3], [5, 0]]

#input = [[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]
#output = [[2, 10], [3, 15], [7, 12], [12, 0], [15, 10], [20, 8], [24, 0]]
