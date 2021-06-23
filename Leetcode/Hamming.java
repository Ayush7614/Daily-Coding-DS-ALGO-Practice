import java.util.Scanner;
class Hamming
{
static int hammingDistance(int x, int y)
{
    int n = x ^ y;
    int setBits = 0;
 
    while (n > 0)
    {
        setBits += n & 1;
        n >>= 1;
    }
 
    return setBits;
}
public static void main(String[] args)
{
    Scanner sc = new Scanner(System.in);
    int x = sc.nextInt();
    int y = sc.nextInt();
    System.out.println(hammingDistance(x, y));
}
}
 
