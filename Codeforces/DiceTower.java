import java.util.*;
public class DiceTower{
  public static void main(String[] args){
    Scanner s = new Scanner(System.in);
    int n = s.nextInt();
    int x = s.nextInt();
    int a = s.nextInt();
    int b = s.nextInt();
    boolean flag = false;
    for (int i = 1; i < n; i++){
      int c = s.nextInt();
      int d = s.nextInt();
      if (c == x || d == x || c == 7-x || d == 7-x){
        flag = true;
        break;
      }
    }
    if (flag) System.out.println("NO");
    else System.out.println("YES");
  }
}