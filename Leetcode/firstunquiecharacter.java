package Leetcode;

import java.util.*;
public class firstunquiecharacter {
    public int firstUniqChar() {
        Scanner sc=new Scanner(System.in);
        System.out.println("enter the word in which you have to find the unquie char");
        String s=sc.nextLine();
        HashMap<Character, Integer> map = new HashMap<Character, Integer>();
        for(int i = 0; i<s.length(); i++){
            char ch = s.charAt(i);
            if(map.containsKey(ch)) map.put(ch, map.get(ch)+1);
            else map.put(ch, 1);
        }
        for(int i=0;i<s.length();i++){
            if(map.get(s.charAt(i)) == 1) return i;
        }
        return -1;
    }
    public static void main(String[] args) {
       
        firstunquiecharacter w;

    }
    
}
