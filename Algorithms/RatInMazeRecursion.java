/* The question is as follows:-
   For a 3x3 matrix, if the rat is initially at (0,0) position and it wants to reach at 
   position (2,2) then print all the ways in which the rat can reach the endpoint of the maze. 
   The rat can move only in horizontal or vertical directions.

    For example:
    Input:
    Starting row: 0
    Starting col: 0
    Ending row: 2
    Ending col: 2

    Output:
    HHVV
    HVHV
    HVVH
    VHHV
    VHVH
    VVHH
    This solution solves the rat in maze problem in the simplest way and prints all the possible answers. */

import java.util.*;

class RatInMazeRecursion {

    public static void ratInMaze(int sr, int sc, int er, int ec, String ans) {
        // This is the base condition. When the rat has reached its destination
        if(sr == er && sc == ec) {
            System.out.println(ans);
            return;
        }
        // If the rat can move in horizontal direction.
        if(sc < ec) {
            ratInMaze(sr,sc+1,er,ec,ans+"H");
        }
        // If the rat can move in vertical direction.
        if(sr < er) {
            ratInMaze(sr+1,sc,er,ec,ans+"V");
        }
    }

    // Here we take the starting row, starting column, ending row and ending column as the inputs and pass these to 
    // the ratInMaze() function. So we can obtain the answer of any source and desination positions.
    public static void main(String[] args) {
        int sr,sc,er,ec;
        Scanner s = new Scanner(System.in);
        System.out.print("Enter starting row: ");
        sr = s.nextInt();
        System.out.print("Enter starting column: ");
        sc = s.nextInt();
        System.out.print("Enter ending row: ");
        er = s.nextInt();
        System.out.print("Enter ending column: ");
        ec = s.nextInt();
        ratInMaze(sr,sc,er,ec,"");
        s.close();
    }

}