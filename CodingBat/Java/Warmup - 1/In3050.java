
public class In3050 {
    public boolean in3050(int a, int b) {
        boolean p, q, r, s;
        p = a >= 30 && a <= 40;
        q = a >= 40 && a <= 50;
        r = b >= 30 && b <= 40;
        s = b >= 40 && b <= 50;

        if (p && r || q && s) {
            return true;
        }
        return false;
    }

}
