#include <stdio.h>
// lookupSegments[digit][segment] == 1 if digit has that segment switched on
int const lookupSegments[10][7] = {
	{1, 1, 1, 1, 1, 1, 0},
	{0, 1, 1, 0, 0, 0, 0},
	{1, 1, 0, 1, 1, 0, 1},
	{1, 1, 1, 1, 0, 0, 1},
	{0, 1, 1, 0, 0, 1, 1},
	{1, 0, 1, 1, 0, 1, 1},
	{1, 0, 1, 1, 1, 1, 1},
	{1, 1, 1, 0, 0, 0, 0},
	{1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 0, 1, 1},
};
int main(void) {
	int segmentSize;
	printf("Enter Size of Each Segment: ");
	scanf("%d", &segmentSize);
	if(segmentSize < 1) {
		printf("ERROR: Segment size must be >= 1\n");
		return -1;
	}
	int numberToPrint;
	printf("Enter Number to Print: ");
	scanf("%d", &numberToPrint);
	int numDigits = 0;
	for(int i = numberToPrint; i > 0; i /= 10) {
		++numDigits;
	}
	int const numRows = 2 * segmentSize + 3;
	int const numCols = numDigits * (segmentSize + 3);
	// Contains the number representation as a 2D character array
	char buffer[numRows][numCols];
	// Initialize buffer to all spaces
	for(int i = 0; i < numRows; ++i) {
		for (int j = 0; j < numCols; ++j) {
			buffer[i][j] = ' ';		
		}
	}
	for(int i = 0; i < numDigits; ++i) {
		int currentDigit = numberToPrint % 10;
		numberToPrint /= 10;
		int offset = (numDigits - i - 1) * (segmentSize + 3);
		// Horizontal segments ============================================== //
		// Segment A
		if(lookupSegments[currentDigit][0]) {
			for (int j = 0; j < segmentSize; ++j) {
				buffer[0][offset + 1 + j] = '-';
			}
		}
		// Segment D
		if(lookupSegments[currentDigit][3]) {
			for(int j = 0; j < segmentSize; ++j) {
				buffer[numRows - 1][offset + 1 + j] = '-';
			}
		}
		// Segment G	
		if(lookupSegments[currentDigit][6]) {
			for(int j = 0; j < segmentSize; ++j) {
				buffer[segmentSize + 1][offset + 1 + j] = '-';
			}
		}
		// Vertical segments ================================================ //
		// Segment B
		if(lookupSegments[currentDigit][1]) {
			for(int j = 0; j < segmentSize; ++j) {
				buffer[j + 1][offset + 1 + segmentSize] = '|';
			}
		}
		// Segment C
		if(lookupSegments[currentDigit][2]) {
			for(int j = 0; j < segmentSize; ++j) {
				buffer[j + segmentSize + 2][offset + 1 + segmentSize] = '|';
			}
		}
		// Segment E
		if(lookupSegments[currentDigit][4]) {
			for(int j = 0; j < segmentSize; ++j) {
				buffer[j + segmentSize + 2][offset] = '|';
			}
		}
		// Segment F
		if(lookupSegments[currentDigit][5]) {
			for(int j = 0; j < segmentSize; ++j) {
				buffer[j + 1][offset] = '|';
			}
		}
	}
	// Display buffer
	for(int i = 0; i < numRows; ++i) {
		for(int j = 0; j < numCols; ++j) {
			printf("%c", buffer[i][j]);
		}
		printf("\n");
	}
}