// We'll say that a number is "teen" if it is in the range 13..19 inclusive. Given 3 int values, return true if 1 or more of them are teen.

// hasTeen(13, 20, 10) → true
// hasTeen(20, 19, 10) → true
// hasTeen(20, 10, 13) → true

public class HasTeen {
    public boolean hasTeen(int a, int b, int c) {
        boolean p, q, r;

        p = a >= 13 && a <= 19;
        q = b >= 13 && b <= 19;
        r = c >= 13 && c <= 19;

        if (p || q || r) {
            return true;
        }
        return false;
    }
}
