class countEvenDigit_Rec
{
    public int counteven(int n)
    {
        if(n!=0)
        {
            if(n%2==0)
            {
                return 1+counteven(n/10);
            }
            else
            {
                return counteven(n/10);
            }
        }
        else
        {
            return 0;
        }
    }
    public static void main(String args[])
    {
        countEvenDigit_Rec dr = new countEvenDigit_Rec();
        System.out.println(dr.counteven(286532));
    }
}

   