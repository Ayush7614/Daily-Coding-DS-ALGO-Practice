#include <stdio.h>

void towers(int, char, char, char);

int main()
{
    int num;

    printf("Enter the number of disks : ");
    scanf("%d", &num);
    printf("The sequence of moves involved in the Tower of Hanoi are :\n");
    // I am assuming 3 tower
    towers(num, 'A', 'C', 'B');
    return 0;
}
void towers(int num, char start, char last, char middle)
{
    if (num == 1)
    {
        printf("\n Move disk 1 from pole %c to pole %c", start, last);
        return;
    }
    towers(num - 1, start, middle, last);
    printf("\n Move disk %d from pole %c to pole %c", num, start, last);
    towers(num - 1, middle, last, start);
}

// Output --

/*

Enter the number of disks : 6
The sequence of moves involved in the Tower of Hanoi are :

 Move disk 1 from pole A to pole B
 Move disk 2 from pole A to pole C
 Move disk 1 from pole B to pole C
 Move disk 3 from pole A to pole B
 Move disk 1 from pole C to pole A
 Move disk 2 from pole C to pole B
 Move disk 1 from pole A to pole B
 Move disk 4 from pole A to pole C
 Move disk 1 from pole B to pole C
 Move disk 2 from pole B to pole A
 Move disk 1 from pole C to pole A
 Move disk 3 from pole B to pole C
 Move disk 1 from pole A to pole B
 Move disk 2 from pole A to pole C
 Move disk 1 from pole B to pole C
 Move disk 5 from pole A to pole B
 Move disk 1 from pole C to pole A
 Move disk 2 from pole C to pole B
 Move disk 1 from pole A to pole B
 Move disk 3 from pole C to pole A
 Move disk 1 from pole B to pole C
 Move disk 2 from pole B to pole A
 Move disk 1 from pole C to pole A
 Move disk 4 from pole C to pole B
 Move disk 1 from pole A to pole B
 Move disk 2 from pole A to pole C
 Move disk 1 from pole B to pole C
 Move disk 3 from pole A to pole B
 Move disk 1 from pole C to pole A
 Move disk 2 from pole C to pole B
 Move disk 1 from pole A to pole B
 Move disk 6 from pole A to pole C
 Move disk 1 from pole B to pole C
 Move disk 2 from pole B to pole A
 Move disk 1 from pole C to pole A
 Move disk 3 from pole B to pole C
 Move disk 1 from pole A to pole B
 Move disk 2 from pole A to pole C
 Move disk 1 from pole B to pole C
 Move disk 4 from pole B to pole A
 Move disk 1 from pole C to pole A
 Move disk 2 from pole C to pole B
 Move disk 1 from pole A to pole B
 Move disk 3 from pole C to pole A
 Move disk 1 from pole B to pole C
 Move disk 2 from pole B to pole A
 Move disk 1 from pole C to pole A
 Move disk 5 from pole B to pole C
 Move disk 1 from pole A to pole B
 Move disk 2 from pole A to pole C
 Move disk 1 from pole B to pole C
 Move disk 3 from pole A to pole B
 Move disk 1 from pole C to pole A
 Move disk 2 from pole C to pole B
 Move disk 1 from pole A to pole B
 Move disk 4 from pole A to pole C
 Move disk 1 from pole B to pole C
 Move disk 2 from pole B to pole A
 Move disk 1 from pole C to pole A
 Move disk 3 from pole B to pole C
 Move disk 1 from pole A to pole B
 Move disk 2 from pole A to pole C
 Move disk 1 from pole B to pole C
*/