import java.util.*;

/**
 * GFG CIRCULAR TOUR problem solution
 * problem link: https://practice.geeksforgeeks.org/problems/circular-tour/1
 * Sol Time Complexity: O(n)
 * Sol Aux Space: O(1)
 */

// { Driver Code Starts
class First_Circular_tour {
    public void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t > 0) {
            int n = sc.nextInt();
            sc.nextLine();
            String str = sc.nextLine();
            String arr[] = str.split(" ");
            int p[] = new int[n];
            int d[] = new int[n];
            int j = 0;
            int k = 0;
            for (int i = 0; i < 2 * n; i++) {
                if (i % 2 == 0) {
                    p[j] = Integer.parseInt(arr[i]);
                    j++;
                } else {
                    d[k] = Integer.parseInt(arr[i]);
                    k++;
                }
            }

            System.out.println(new CircularTour().tour(p, d));
            t--;
        }
    }
// } Driver Code Ends



// In java function tour() takes two arguments array of petrol
// and array of distance

    private class CircularTour {
        //Function to find starting point where the truck can start to get through
        //the complete circle without exhausting its petrol in between.
        int tour(int petrol[], int distance[]) {

            /**
             * In the distance array we store the difference between the petrol available in current station
             * and distance to the next station.
             * This is what we do in the first for loop below
             */

            for (int i = 0; i < distance.length; i++) {
                distance[i] = petrol[i] - distance[i];
            }

            /**
             * Here we keep track of three things:
             * negativeDistance: the previous distance from start to the station from which we can't complete the circle.
             * positiveDistance: the distance till index i from (negativeDistance end index + 1)
             * startIndex: the index from which we can complete
             */

            int negativeDistance = 0;
            int distanceCovered = 0;
            int startIndex = 0;


            for (int i = 0; i < distance.length; i++) {

                /**
                 * Here we are checking if the distanceCovered + distance[i] >= 0 because
                 * if it is negative then we can't complement the circle from the startIndex
                 */
                if (distanceCovered + distance[i] >= 0) {
                    distanceCovered += distance[i]; //Updating Distance Covered
                } else {
                    if (i == distance.length - 1)
                        return -1;

                    startIndex = i + 1;
                    distanceCovered += distance[i];
                    negativeDistance += distanceCovered; //Updating negative Distance
                    distanceCovered = 0; //Reseting Distance Covered as we will again start from i+1
                }

            }

            /**
             * The negativeDistance holds the distance from 0 to startIndex-1
             * The positiveDistance holds the distance from startIndex to arr.length-1
             * if positiveDistance+negativeDistance>=0 then we can say that startIndex will complete
             * circular tour, else it is impossible
             */
            if (distanceCovered >= Math.abs(negativeDistance))
                return startIndex;
            else
                return -1;
        }
    }

}