/* 
  Russian Peasant Multiplication Algorithm
  The value of a*b is same as (a*2)*(b/2) if b is even, otherwise the value is same as ((a*2)*(b/2) + a).
*/
#include <iostream>
using namespace std;
 
// A method to multiply two numbers using Russian Peasant method
unsigned int russianPeasantmethod(unsigned int num1, unsigned int num2){
    int res = 0; // initialize result
 
    // While second number doesn't become 1
    while (num2 > 0){
        // If second number becomes odd, add the first number to result
        if (num2 & 1)
            res = res + num1;
 
        // Double the first number and halve the second number
        num1 = num1 << 1;
        num2 = num2 >> 1;
    }
    return res;
}
 
int main(){
    int a, b;
    cout << " Enter two intergers:";
    cin>> a >> b;					//user-input
    cout << russianPeasantmethod(a, b) << endl;		//function call
    return 0;
}
