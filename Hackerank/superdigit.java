//super digit in java code

public class superdigit {
    public static void main(String[] args) {
    	//Integer x = 1;
    	Integer x = 99;    	
    	System.out.println(getSuperDigit(x));
    	
    }

	public static Integer getSuperDigit(Integer x) {
		if(x < 10) {
    		return x;
    	} else {
    		Integer digitSum = 0;    		
    		for (char num : x.toString().toCharArray()) {       			
				digitSum += Character.getNumericValue(num);
			}
    		return getSuperDigit(digitSum);
    	}
	}

    
}
//test cases
/* super_digit(9875) = super_digit(9+8+7+5) 
                  = super_digit(29) 
                  = super_digit(2+9)
                  = super_digit(11)
                  = super_digit(1+1)
                  = super_digit(2)
                  = 2.*/
