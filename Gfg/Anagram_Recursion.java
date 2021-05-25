class Anagram_Rec
{
    public static String Anagram(String fix , String s)
    {
        int l = s.length();
        if(l==1)
        {
            System.out.println(fix+s);
        }
        else
        {
            char ch;
            for(int x = 0; x < l; x++)
            {
                ch = s.charAt(x);
                String r = s.substring(0,x)+s.substring(x);
                fix = fix+ch;
            }
            return Anagram(fix , s);
        }
        return s;
    }
    public static void main(String args[])
    {
        Anagram_Rec ar = new Anagram_Rec();
        System.out.println(ar.Anagram("abc" , "bac"));
    }
}
        