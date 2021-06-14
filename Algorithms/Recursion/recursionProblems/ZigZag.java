package recursionProblems;

import java.util.Scanner;

public class ZigZag {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		System.out.println();
		int n=sc.nextInt();
		pzz(n);

	}

	private static void pzz(int n) {
		
		if(n==0) {
			return;
		}
		
		System.out.println("pre "+n);
		pzz(n-1);
		System.out.println("In "+n);
		pzz(n-1);
		System.out.println("Post "+n);
		
	}

}


/*
 *    .......................(executes when stack is going up)
 *    call()
 *    .......................(while going down)
 *    
 *    Euler diagram
 *    
 *    
 *    0       0          0        0
 *    !       !          !        !
 *     !     !            !     !
 *      !  !                !  !
 *       1                   1
 * 		 !                   !
 *         !                !
 *          !              !
 *           !           !
 *            !        !
 *              !     !
 * 				  2
 */
