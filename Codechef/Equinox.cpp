#include<iostream>
#include<string>

using namespace std;
void print(long AS,long BS){
	
	if(AS > BS){
				cout<<"SARTHAK"<<endl;
			}
	else if(AS == BS){
				cout<<"DRAW"<<endl;
			
			}
			else if(BS > AS){
				cout<<"ANURADHA"<<endl;
			}
}
int main(){
	long t,N,A,B,AS,BS;
	string word;
	string s1="EQUINOX";
	
    cin>>t;
   
	while(t){

		cin>>N>>A>>B;
		 AS=0;
		 BS=0;
		for(int i=0;i<N;i++){
			cin>>word;
			    if(s1.find(word[0])!=-1){
				AS=AS+A;	
				}
				else{
					BS= BS+B;
				}
			}
			print(AS,BS);
			
		
		t--;
}
}
