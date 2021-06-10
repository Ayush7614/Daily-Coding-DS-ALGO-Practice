bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        
        vector<vector<int>>tmp=mat;
        int row=mat.size();
       
         for(int z=0;z<4;z++){   
        
        for(int i=0;i<row;i++){                                           
                    
              int k=row-1-i;
             int r=0;
             for(int j=0;j<row;j++){    
                 tmp[r][k]=mat[i][j];
                 r++;
              }  
        } 
             if(tmp==target) return true;
             mat=tmp;
         } 
        return false;
   }
