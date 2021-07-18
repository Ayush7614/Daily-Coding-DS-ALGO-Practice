/*
CODE DESCRIPTION:
In Maximum Histogram area code, we are given an integral array where each element represents the height of a bar
in a histogram. The bars are placed in the exact same sequence as given in the array.
We need to find the area of the Maximum rectangular area from the given histogram.*/

#include <stdio.h>
#include <conio.h>

//creating an array stack of size 20
int stack[20];
//initialise variable "top" to -1 indicating empty stack
int top=-1;

//push function adds(pushes) element on top of stack
void push(int t){
  stack[++top]=t;
}

//function to pop-up top of stack
int pop(){
  return stack[top--];
}

//function creates l[i] which will store the index of previous smaller element for ith element of the array.
void left(int a[], int size, int l[]){
    int i;
    // loop works in from left elemnt to right element
    for (i = 0; i < size; i++)
    {
        /*if the stack is not empty and the current element is smaller than element with index stored
        on the top of stack then, we pop the top element*/
        while (top!=-1 && a[stack[top]] >= a[i]){
            pop();
        }

        // if the stack is empty than r[i] = -1
        if (top==-1){
            l[i]=-1;
        }
        // if the stack is not empty than r[i] = element at top of stack
        else{
            l[i]=stack[top];
        }
        // push index i in stack
        push(i);
    }

    // empty the stack again by setting top=-1
    top=-1;
}


// function to creates r[i] which will store the index of next smaller element for ith element of the array.
void right(int a[], int size,int r[]){
    int i;
    // loop works in reverse order i.e, from right to left of array
    for (i = size-1; i >= 0; i--)
    {
      /* if the stack is not empty and the current element is smaller than element with index stored
      on the top of stack then, we pop the top element */
        while (top!=-1 && a[stack[top]] >= a[i]){
            pop();
        }

        // if the stack is empty than r[i] = size
        if (top==-1){
            r[i]=size;
        }
        // if the stack is not empty than r[i] = element at top of stack
        else{
            r[i]=stack[top];
        }
        // push index i in stack
        push(i);
    }
}


// function to find maximum area and return it to main function
int area(int a[],int size){
    int area=0,temp=0,i;
    int l[size],r[size];

    // creating next smaller element index from left array
    left(a,size,l);
    // creating next smaller element index from right array
    right(a,size,r);

    // loop to calculate area for each elementand getting maximum of all
    for ( i = 0; i < size; i++){
        temp=area;
        area=(r[i] - l[i] - 1) * a[i];
        if(area<temp)
        area=temp;
    }

    // return maximum area
    return area;
}


// MAIN FUNCTION
int main(){
    int a[10], i, size,max_area;

    // user input for array size and elements
    printf("Enter the size of array : ");
    scanf("%d",&size);
    printf("Enter elements: ");
    for (i = 0; i < size; i++){
        scanf("%d",&a[i]);
    }

    // get prints maximum area
    max_area=area(a,size);
    printf("\nMaximum rectangular area in Histogram is : %d",max_area);
    return 0;
}

/*
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(n)

OUPUT:
Enter the size of array : 7
Enter elements: 6 2 5 4 5 1 6

Maximum rectangular area in Histogram is : 12
*/
