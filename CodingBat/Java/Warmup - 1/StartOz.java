// Given a string, return a string made of the first 2 chars (if present), however include first char only if it is 'o' and include the second only if it is 'z', so "ozymandias" yields "oz".

// startOz("ozymandias") → "oz"
// startOz("bzoo") → "z"
// startOz("oxx") → "o"

public class StartOz 
{
    public String startOz(String str) 
    {
        if (str.length() == 1 && str.equals("o")) 
        {
            return str;
        }
        if (str.length() >= 2 && str.substring(0, 2).equals("oz")) 
        {
            return "oz";
        }
        if (str.length() >= 2 && str.charAt(0) == 'o' && str.charAt(1) != 'z') 
        {
            return "o";
        }
        if (str.length() >= 2 && str.charAt(0) != 'o' && str.charAt(1) == 'z') 
        {
            return "z";
        }
        return "";
    }
}
