
public class Max1020 {
    public int max1020(int a, int b) {
        boolean p = a >= 10 && a <= 20;
        boolean q = b >= 10 && b <= 20;

        if (p && !q) {
            return a;
        } else if (!p && q) {
            return b;
        } else if (!p && !q) {
            return 0;
        } else if (p && q && a > b) {
            return a;
        }

        return b;
    }

}
