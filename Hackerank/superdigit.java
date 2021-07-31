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
