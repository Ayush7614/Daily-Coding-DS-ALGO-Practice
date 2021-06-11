/*
Sereja and Dima play a game. The rules of the game are very simple. The players have n cards in a row. Each card contains a number, all numbers on the cards are distinct. 
The players take turns, Sereja moves first. During his turn a player can take one card: either the leftmost card in a row, or the rightmost one. 
The game ends when there is no more cards. The player who has the maximum sum of numbers on his cards by the end of the game, wins.
Sereja and Dima are being greedy. Each of them chooses the card with the larger number during his move.
Inna is a friend of Sereja and Dima. She knows which strategy the guys are using, so she wants to determine the final score, given the initial state of the game. Help her.
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    
    for(int turns = 0; turns < n; turns++)
    {
        cin >> a[turns];
    }
    
    int sum1 = 0, sum2 = 0;
    int front = 0, back = n-1;
    
    for(int turns = 0; turns < n; turns++)
    {
        int ans = max(a[front], a[back]);
        if(a[front] >= a[back])
        {
            front++;
        }
        else
        {
            back--;
        }
        
        if(turns % 2 == 1)
            sum1 += ans;
        else
            sum2 += ans;
    }
    
    cout << sum2 << " " << sum1;
    return 0;
}

/*
Input:
4
4 1 2 10

Output:
12 5
*/