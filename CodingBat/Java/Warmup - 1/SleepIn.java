/**
 * The parameter weekday is true if it is a weekday, and the parameter vacation
 * is true if we are on vacation. We sleep in if it is not a weekday or we're on
 * vacation. Return true if we sleep in.
 * 
 * sleepIn(false, false) → true sleepIn(true, false) → false sleepIn(false,
 * true) → true
 */

public class SleepIn {
    public boolean parrotTrouble(boolean talking, int hour) {
        return (talking && (hour < 7 || hour > 20));
    }
}
