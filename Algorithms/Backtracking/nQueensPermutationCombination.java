package Algorithms.Backtracking;

import java.util.Scanner;
class nQueensPermutationCombination {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int totalBoxes = sc.nextInt();
        int totalQueens = sc.nextInt();
        
        System.out.println("Permutation :");
        QueensPermutation(new boolean[totalBoxes],0,totalQueens," ");
        
        System.out.println("Combination :");
        QueensCombination(new boolean[totalBoxes],0,totalQueens," ",-1);

        sc.close();
    }
    public static void QueensPermutation(boolean[] boxes,int qpsf,int tq,String ans)
    {
        if(qpsf == tq)
        {
            System.out.println(ans);
            return;
        }
        for(int i=0;i<boxes.length;i++)
        {
            if(boxes[i] == false){
                boxes[i]=true;
                QueensPermutation(boxes,qpsf+1,tq,ans+"Q"+qpsf+"B"+i+" ");
                boxes[i] = false; //undo operation
            }
        }
    }
    public static void QueensCombination(boolean[] boxes,int qpsf,int tq,String ans,int lastBoxUsed)
    {
        if(qpsf == tq)
        {
            System.out.println(" "+ans);
            return;
        }
        for(int i=lastBoxUsed+1;i<boxes.length;i++)
        {
            if(boxes[i] == false)
            {
                boxes[i] = true;
                QueensCombination(boxes,qpsf+1,tq,ans+"Q"+qpsf+"B"+i+" ",i);
                boxes[i] = false;
            }
        }
    }
}