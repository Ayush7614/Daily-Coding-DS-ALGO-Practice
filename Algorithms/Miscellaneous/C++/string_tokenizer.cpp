#include<iostream>
#include<cstring>
using namespace std;

char *mystrtok(char *s,char delim){
    //accept string and deliminator
    static char * input = NULL; //maintians the static state pointer throught out the process
    if(s!=NULL){
         //we are making first call
         input = s;
    }

    //base case - after token has been returned
    if(input==NULL){
        return NULL;
    }

    //start extracting tokens and store them in an array
    char *output = new char[strlen(input)+1];
    int i=0;
    for( ;input[i]!='\0';i++){
        if(input[i]!=delim){
            output[i]= input[i];
        }
        else{
            output[i]='\0';
            input = input + i +1;
            return output;
        }
    }

    //corner case
    output[i]='\0';
    input=NULL;
    return output;
}

int main(){
    char s[100]="Today is a rainy day";

    char *ptr = mystrtok(s,' '); 
    //instead of writing a detailed function for tokenizing we can simply use strtok() as follows
    //char *ptr = strtok(s," ");
    cout<<ptr<<endl; // space is the deliminator here
    //passing the null in next call gives next word
    while(ptr!=NULL){
        ptr = mystrtok(NULL,' ');
        //ptr = strtok(NULL," "); --> for strtok() function.
        cout<<ptr<<endl;
    }
}



/*Output is as follows:
Today
is   
a    
rainy
day
*/