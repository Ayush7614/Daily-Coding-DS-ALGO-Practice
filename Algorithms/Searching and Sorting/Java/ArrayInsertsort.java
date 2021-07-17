//Java implementation of Insertion sort of array using call by reference

class ArrayIns
  {
  private long[] a;         
  private int n;       

  //Parameterized Constructor
  public ArrayIns(int max)     
   {
   a = new long[max];         // create the array
   n = 0;            // no items yet
   }

   //Inserting elements into array
  public void insert(long value) 
   {
   a[n] = value;  
   n++;           
   }

   // displays array elements
  public void display()       
   {
   for(int j=0; j<n; j++)    
     System.out.print(a[j] + " ");
   System.out.println("");
   }

  public void insertionSort()
   {
   int in, out;

   for(out=1; out<n; out++)   
     {
     long temp = a[out];      // remove marked item
     in = out;           // start shifts at out
     while(in>0 && a[in-1] >= temp) // until one is smaller,
      {
      a[in] = a[in-1];      // shift item to right
      --in;            // go left one position
      }
     a[in] = temp;         // insert marked item
     } 
   } 

  } 

class ArrayInsertsort
  {
  public static void main(String[] args)
   {
   int maxSize = 100;      // array size
   ArrayIns arr;         // reference to array
   arr = new ArrayIns(maxSize); // create the array

   // insert 10 items
   arr.insert(77);        
   arr.insert(99);
   arr.insert(44);
   arr.insert(55);
   arr.insert(22);
   arr.insert(88);
   arr.insert(11);
   arr.insert(00);
   arr.insert(66);
   arr.insert(33);

   arr.display();        

   arr.insertionSort();  

   arr.display();        
   }

  } 