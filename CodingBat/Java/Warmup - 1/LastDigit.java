
public class LastDigit {
    public boolean lastDigit(int a, int b) {
        if (Math.abs(a - b) % 10 == 0) {
            return true;
        }
        return false;
    }

}
