
public class EveryNth {
    public String everyNth(String str, int n) {
        String s = "";
        for (int i = 0; i < str.length(); i += n) {
            s += str.substring(i, i + 1);
        }

        return s;
    }

}
