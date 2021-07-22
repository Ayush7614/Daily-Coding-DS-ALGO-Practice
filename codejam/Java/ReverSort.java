package CodeJam;

import java.util.ArrayList;
import java.util.Scanner;

class ReverSortOpertion {

	int a[];
	int length;
	int cost[];

	public ReverSortOpertion(int len, int a[]) {
		this.a = a;
		this.length = len;
		cost = new int[len];

	}

	private int findMin(int start, int a[]) {
		int min = a[start];
		int pos = start;

		for (int i = start + 1; i < a.length; i++) {
			if (a[i] < min) {
				min = a[i];
				pos = i;
			}
		}
		// System.out.println("findMin pos=" + pos);
		return pos;
	}

	private int[] reverse(int start, int end, int a[]) {
		int b[] = new int[a.length];
		int i;
		for (i = 0; i < a.length; i++) {
			b[i] = a[i];
		}
		i = start;
		for (int j = end; j >= start; j--, i++) {
			b[i] = a[j];
		}
		return b;
	}

	private void print() {
		System.out.print("array :");
		for (int i = 0; i < a.length; i++) {
			System.out.print(a[i] + " ");
		}
		System.out.println();
	}

	public int calculateCost() {
		// print();

		for (int i = 0; i < a.length - 1; i++) {

			int minPos = findMin(i, a);
			// print();

			if (minPos > i) {
				a = reverse(i, minPos, a);
				// print();
			}

			int cost = (minPos) - (i) + 1;
			// System.out.println("cost=" + cost);
			this.cost[i] = cost;

		}

		int totalCost = 0;
		for (int i = 0; i < cost.length; i++) {
			totalCost += cost[i];
		}

		return totalCost;
	}
}

public class ReverSort {

	public static void main(String[] args) {

		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		ArrayList<ReverSortOpertion> cases = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			int len = s.nextInt();
			int a[] = new int[len];
			for (int j = 0; j < len; j++) {
				a[j] = s.nextInt();
			}
			ReverSortOpertion opertion = new ReverSortOpertion(len, a);
			cases.add(opertion);
		}

		for (int i = 0; i < n; i++) {
			System.out.println("Case #" + (i + 1) + ": " + cases.get(i).calculateCost());
		}
	}
}



/*
Input:
4
4 2 1 3
2
1 2
7
7 6 5 4 3 2 1
-----------------------
output::
Case #1: 6
Case #2: 1
Case #3: 12
*/

