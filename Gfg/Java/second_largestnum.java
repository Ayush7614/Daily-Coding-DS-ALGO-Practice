 class solution{
   int lar=-1; int sec_lar = -1;
    
    for(int i=0;i<n;i++){
        if(lar<arr[i] && sec_lar<arr[i]){
        sec_lar = lar;
        lar = arr[i];
        }
        
        if(sec_lar<lar && sec_lar<arr[i] && arr[i]!=lar)
        sec_lar = arr[i];
    }
    return sec_lar;
 }
//small class to check  the second largest element in the array
