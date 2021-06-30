import java.util.*;
 class MyClass {
         public static HashMap<String, Integer> sortByValue(HashMap<String, Integer> hm)
    {
        List<Map.Entry<String, Integer> > list =
               new LinkedList<Map.Entry<String, Integer> >(hm.entrySet());
 
        Collections.sort(list, new Comparator<Map.Entry<String, Integer> >() {
            public int compare(Map.Entry<String, Integer> o1,
                               Map.Entry<String, Integer> o2)
            {
                return (o1.getValue()).compareTo(o2.getValue());
            }
        });
         
    
        HashMap<String, Integer> temp = new LinkedHashMap<String, Integer>();
        for (Map.Entry<String, Integer> aa : list) {
            temp.put(aa.getKey(), aa.getValue());
        }
        return temp;
    }
    public static void main(String args[]) {
      Scanner sc=new Scanner(System.in);
      int t=sc.nextInt();
      for(int x=1;x<=t;x++)
      {
           int n=sc.nextInt();
            HashMap<String, Integer> map = new HashMap<>();
            for(int y=0;y<3*n;y++)
            {
            String h=sc.next();
           int s=sc.nextInt();
           if (map.containsKey(h)) {
            int a = map.get(h);
            int c=a+s;
          
           map.put(h, c);}
           else
           {
                map.put(h, s);
           }
            }
              
      
      Map<String, Integer> hm1 = sortByValue(map);
        for (Map.Entry<String, Integer> en : hm1.entrySet()) {
            System.out.print(en.getValue()+" ");
        }
        System.out.println();
    }}
}


// Input
// 3
// 1
// A 1
// B 2
// C 3
// 2
// AA 1
// AB 1
// AB 1
// AC 1
// AC 1
// AD 1
// 1
// Z 100
// Z 100
// Z 100
// Output
// 1 2 3
// 1 1 2 2
// 300