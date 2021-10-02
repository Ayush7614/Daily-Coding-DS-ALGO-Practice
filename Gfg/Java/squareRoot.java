package Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

//square root of an integer
public class squareRoot {
    static int countSquares(int N) {

        int i;


        for( i=1;i<N;i++); {

            int ans = (int)Math.sqrt(N-1);

            return ans;


        }


    }
    public static void main(String args[]) throws IOException {
        BufferedReader read =
                new BufferedReader(new InputStreamReader(System.in));

            int N = Integer.parseInt(read.readLine());

            squareRoot ob = new squareRoot();
            System.out.println(ob.countSquares(N));

    }

}
