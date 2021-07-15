/*
Problem Statement -> 

A Pythagorean triple is a triple of integer numbers (a,b,c) such that it is possible to form a right triangle 
with the lengths of the first cathetus, the second cathetus and the hypotenuse equal to a, b and c, respectively.
An example of the Pythagorean triple is (3,4,5).

Vasya studies the properties of right triangles, and he uses a formula that determines if some triple of integers 
is Pythagorean. Unfortunately, he has forgotten the exact formula; he remembers only that the formula 
was some equation with squares. So, he came up with the following formula: c = a^2 − b.

Obviously, this is not the right formula to check if a triple of numbers is Pythagorean.
But, to Vasya's surprise, it actually worked on the triple (3,4,5): 5=3^2 − 4, so, according to Vasya's formula,
it is a Pythagorean triple.

When Vasya found the right formula (and understood that his formula is wrong),
he wondered: how many are there triples of integers (a,b,c) with 1 ≤ a ≤ b ≤ c ≤ n such that 
they are Pythagorean both according to his formula and the real definition? He asked you to count these triples.

Input ->

The first line contains one integer t (1 ≤ t ≤ 10^4) — the number of test cases.
Each test case consists of one line containing one integer n (1 ≤ n ≤ 10^9).

Output -> 

For each test case, print one integer — the number of triples of integers (a,b,c) with 1 ≤ a ≤ b ≤ c ≤ n 
such that they are Pythagorean according both to the real definition and to the formula Vasya came up with.

Test Case ->
Input - 

    3
    3
    6
    9

Output - 

    0
    1
    1
*/

/*
Logic ->
a^2 + b^2 = c^2
a^2 = b + c
-------------------
b^2 + b = c^2 - c
b(b+1) = (c-1)c
=> b = c - 1
=> a^2 = 2b + 1
=> a^2 = 2c - 1

Now
c <= n
i.e.  (a^2 + 1)/2 <= n
i.e.  a <= sqrt(2n-1)
and a >= 3

Now just apply brute force to find a for every n
*/


#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T)
    {
        int n;
        cin >> n;
        int a = (int)sqrt(2*n - 1);
        cout << "ans = " << (a-1)/2  << endl;
        T--;
    }
}