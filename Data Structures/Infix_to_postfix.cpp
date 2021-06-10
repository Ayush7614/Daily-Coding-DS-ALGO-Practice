#include<iostream>
#include<stdlib.h>
using namespace std;

class stack
{
	char *st;
	int top,capacity,i;
	public:
		stack(int max)
		{
			capacity=max;
			if(capacity<1)
			{
				cout<<"capacity must be >1\n";
				exit(0);
			}
			st=new char[capacity]; 
			top=-1;
		}
		int isempty()			//CHECKING IF STACK IS EMPTY
		{
			return top==-1; 
		}
		void enhancecapacity() 		//INCREASING THE STACK CAPACITY WHEN REQUIRED
		{
			char *tmp=new char[capacity*2]; 
			for(i=0;i<=top;i++)
				tmp[i]=st[i];
			delete []st;
			st=tmp;
			cout<<"stack size is doubled\n";
		}
		void push(char &x)		//PUSHES THE ELEMENTS INTO THE STACK BY CHECKING CAPACITY
		{
			if(top==capacity-1) 
			{
				enhancecapacity();
				capacity*=2; 
			}
			st[++top]=x;
		}
		char pop()				//POPS THE ELEMENTS FROM THE STACK
		{
			if(isempty())
				return -1;
			char x=st[top--]; 
			return x;
		}
		void disp()				//DIAPLAYS THE STACKS
		{
			if(isempty())
				cout<<"empty\n";
			else 
			{
				for(i=top;i>=0;i--)
					cout<<endl;
				cout<<endl;
			}
		}
		char topmost() 			//DISPLAYS THE TOPMOST ELEMENT IN THE STACK
		{
			if(isempty()) 
				return -1;
			return st[top]; 
		}
};

int priority(char ch);
void convert(char *a)
{
	int x,j=0; 
	stack st(20); 			//CREATING A STACK
	char b[20];
	int len=strlen(a);					//CHECKING THE LENGTH OF THE GIVEN EXPRESSION
	for(int i=0;i<len;i++)
	{
		char ch=a[i];
		if(isalpha(ch))					//CHECKING WHETHER THE CHARACTER IS ALPHABET OR NOT
			b[j++]=ch;
		else if(isdigit(ch))			//CHECKING WHETHER THE CHARACTER IS DIGIT OR NOT
			b[j++]=ch; 
		else if(ch=='(')				//CHECKING WHETER THE CHARACTER IS PARANTHESIS
			st.push(ch);
		else if(ch==')')
		{
			while(st.topmost()!='(')	//IF THE CHARACTER IS RIGHT PARANTHESIS THEN POP
				b[j++]=st.pop();		//THE CHARACTETS FROM STACK AND ATTACH AT END OF	
			st.pop();					//EXPRESSION
		}
		else
		{
			while(priority(ch) <= priority(st.topmost())) 		//CHECKING FOR PRIORITY
				b[j++]=st.pop();								//TO PUSH OR POP FROM STACK
			st.push(ch);
		}
	}
	while(!st.isempty()) 
		b[j++]=st.pop();
	b[j]='\0';
	cout<<"postfix expression is : "<<b<<"\n";
}

int priority(char ch)			//CHECKING THE PRIORITY OF ARITHMETIC EXPRESSIONS
{
	switch(ch) {
		case '^':return(5);
		case '*':
		case '/':return(4);		//'*' AND '/' HAVE SAME PRIORITY
		case '+':
		case '-':return(3); 	//'+' AND '-' HAVE SAME PRIORITY
		case '(':return(2); 
		case ')':return(1);
	}	
	return(0);
}

int main()
{
	char p[20];
	cout<<"enter infix expression : ";
	cin>>p;
	convert(p);		//passing infix expression to convert() method
}
