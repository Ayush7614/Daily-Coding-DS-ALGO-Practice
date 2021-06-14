package RecursionPractice;

public class mirrorImage {

	public static void main(String[] args) {
		char[] ch= {'h','e','l','l','o'};
		displayCharArr(ch,0);
	}

	private static void displayCharArr(char[] ch,int index) {
		if(index>=ch.length)
		{
			return;
		}
		System.out.print(ch[index]);
		displayCharArr(ch,index+1);
		System.out.print(ch[index]);
		
	}

}
