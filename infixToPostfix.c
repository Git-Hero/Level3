//converts and infix notation terminated by '?' to postfix,characters are separe
//Example
//input :
//2
//A + B + C ?
//A + B - C ?
//output :
//AB+C+
//AB+C-
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#define N 100

typedef struct stack
{
	int top;
	char A[N];
}stack;

bool empty(stack *ps)
{
	if(ps->top==-1)
		return true;
	else
		return false;
}

void push(stack *ps, int x)
{
	if(ps->top==N-1)
	{
		printf("Overflow\n");
		return;
	}
	(ps->top)++;
	ps->A[(ps->top)]=x;
}

char pop(stack *ps)
{
	if(empty(ps))
	{
		printf("Underflow\n");
		return ;
	}
	char a = ps->A[ps->top];
	ps->top--;
	return a;
}

void print(stack *ps,int d)
{
	int t= ps->top;
	while(t>=0)
	{
		if(d)
			printf("%d ",ps->A[t]);
		else
			printf("%c ",ps->A[t]);
		t--;
	}
	printf("\n");
}

bool isoperand(char c)
{
	switch(c)
	{
		case '+' : return true;
		case '-' : return true;
		case '*' : return true;
		case '/' : return true;
		case '^' : return true;
		case '(' : return true;
		case ')' : return true;
		default : return false;
	}
}

int pr ( char a)
{
	int c;

	if(a=='+'||a=='-')
		c=1;
	else if(a=='*'||a=='/')
		c=2;
	return c;
}

bool prcd(char a, char b)
{
	// returns true if precedence of char a is more than that of b
	if (pr(a) >= pr(b)) {
		return true;
	}
	return false;
}

int main()
{
	int z;
	scanf("%d",&z);
	while(z--)
	{
		char a;
		stack s;
		char str[100][100]={'\0'};
		char si[100][100]={'\0'};
		int f=0;
		int o=0;
		s.top=-1;
		int j=0,k=0,i;
		while(1)
		{
			a=getchar();
			if(a==' ')
			{
				j=0;
				k++;
			}
			else if(a=='?')
			{
				break;
			}
			else
			{
				str[k][j++]=a;
			}
		}
		for(i=0;i<k;i++)
		{
			if(!isoperand(str[i][0]))
			{
				strcpy(si[f],str[i]);
				f++;
			}
			else
			{
				if(str[i][0]=='(')
				{
					push(&s,str[i][0]);
				}
				else if(str[i][0]==')')
				{
					while(!empty(&s))
					{
						char t = pop(&s);
						if(t=='(')
							break;
						else
							si[f++][0]=t;
					}
				}
				else
				{
					while(!empty(&s) && prcd(s.A[s.top],str[i][0]))
					{
						char t = pop(&s);
						if(t=='(')
							continue;
						si[f++][0]=t;
						
					}
					push(&s,str[i][0]);
					
				}
			}
		}
		
		while(!empty(&s))
		{
			si[f++][0]=pop(&s);
		}
		
		for(i=0;i<f;i++)
		{
			printf("%s ",si[i]);
		}
		printf("\n");
	}
	return 0;
}//converts and infix notation terminated by '?' to postfix,characters are separe
//Example
//input :
//2
//A + B + C ?
//A + B - C ?
//output :
//AB+C+
//AB+C-
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#define N 100

typedef struct stack
{
	int top;
	char A[N];
}stack;

bool empty(stack *ps)
{
	if(ps->top==-1)
		return true;
	else
		return false;
}

void push(stack *ps, int x)
{
	if(ps->top==N-1)
	{
		printf("Overflow\n");
		return;
	}
	(ps->top)++;
	ps->A[(ps->top)]=x;
}

char pop(stack *ps)
{
	if(empty(ps))
	{
		printf("Underflow\n");
		return ;
	}
	char a = ps->A[ps->top];
	ps->top--;
	return a;
}

void print(stack *ps,int d)
{
	int t= ps->top;
	while(t>=0)
	{
		if(d)
			printf("%d ",ps->A[t]);
		else
			printf("%c ",ps->A[t]);
		t--;
	}
	printf("\n");
}

bool isoperand(char c)
{
	switch(c)
	{
		case '+' : return true;
		case '-' : return true;
		case '*' : return true;
		case '/' : return true;
		case '^' : return true;
		case '(' : return true;
		case ')' : return true;
		default : return false;
	}
}

int pr ( char a)
{
	int c;

	if(a=='+'||a=='-')
		c=1;
	else if(a=='*'||a=='/')
		c=2;
	return c;
}

bool prcd(char a, char b)
{
	// returns true if precedence of char a is more than that of b
	if (pr(a) >= pr(b)) {
		return true;
	}
	return false;
}

int main()
{
	int z;
	scanf("%d",&z);
	while(z--)
	{
		char a;
		stack s;
		char str[100][100]={'\0'};
		char si[100][100]={'\0'};
		int f=0;
		int o=0;
		s.top=-1;
		int j=0,k=0,i;
		while(1)
		{
			a=getchar();
			if(a==' ')
			{
				j=0;
				k++;
			}
			else if(a=='?')
			{
				break;
			}
			else
			{
				str[k][j++]=a;
			}
		}
		for(i=0;i<k;i++)
		{
			if(!isoperand(str[i][0]))
			{
				strcpy(si[f],str[i]);
				f++;
			}
			else
			{
				if(str[i][0]=='(')
				{
					push(&s,str[i][0]);
				}
				else if(str[i][0]==')')
				{
					while(!empty(&s))
					{
						char t = pop(&s);
						if(t=='(')
							break;
						else
							si[f++][0]=t;
					}
				}
				else
				{
					while(!empty(&s) && prcd(s.A[s.top],str[i][0]))
					{
						char t = pop(&s);
						if(t=='(')
							continue;
						si[f++][0]=t;
						
					}
					push(&s,str[i][0]);
					
				}
			}
		}
		
		while(!empty(&s))
		{
			si[f++][0]=pop(&s);
		}
		
		for(i=0;i<f;i++)
		{
			printf("%s ",si[i]);
		}
		printf("\n");
	}
	return 0;
}//converts and infix notation terminated by '?' to postfix,characters are separe
//Example
//input :
//2
//A + B + C ?
//A + B - C ?
//output :
//AB+C+
//AB+C-
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#define N 100

typedef struct stack
{
	int top;
	char A[N];
}stack;

bool empty(stack *ps)
{
	if(ps->top==-1)
		return true;
	else
		return false;
}

void push(stack *ps, int x)
{
	if(ps->top==N-1)
	{
		printf("Overflow\n");
		return;
	}
	(ps->top)++;
	ps->A[(ps->top)]=x;
}

char pop(stack *ps)
{
	if(empty(ps))
	{
		printf("Underflow\n");
		return ;
	}
	char a = ps->A[ps->top];
	ps->top--;
	return a;
}

void print(stack *ps,int d)
{
	int t= ps->top;
	while(t>=0)
	{
		if(d)
			printf("%d ",ps->A[t]);
		else
			printf("%c ",ps->A[t]);
		t--;
	}
	printf("\n");
}

bool isoperand(char c)
{
	switch(c)
	{
		case '+' : return true;
		case '-' : return true;
		case '*' : return true;
		case '/' : return true;
		case '^' : return true;
		case '(' : return true;
		case ')' : return true;
		default : return false;
	}
}

int pr ( char a)
{
	int c;

	if(a=='+'||a=='-')
		c=1;
	else if(a=='*'||a=='/')
		c=2;
	return c;
}

bool prcd(char a, char b)
{
	// returns true if precedence of char a is more than that of b
	if (pr(a) >= pr(b)) {
		return true;
	}
	return false;
}

int main()
{
	int z;
	scanf("%d",&z);
	while(z--)
	{
		char a;
		stack s;
		char str[100][100]={'\0'};
		char si[100][100]={'\0'};
		int f=0;
		int o=0;
		s.top=-1;
		int j=0,k=0,i;
		while(1)
		{
			a=getchar();
			if(a==' ')
			{
				j=0;
				k++;
			}
			else if(a=='?')
			{
				break;
			}
			else
			{
				str[k][j++]=a;
			}
		}
		for(i=0;i<k;i++)
		{
			if(!isoperand(str[i][0]))
			{
				strcpy(si[f],str[i]);
				f++;
			}
			else
			{
				if(str[i][0]=='(')
				{
					push(&s,str[i][0]);
				}
				else if(str[i][0]==')')
				{
					while(!empty(&s))
					{
						char t = pop(&s);
						if(t=='(')
							break;
						else
							si[f++][0]=t;
					}
				}
				else
				{
					while(!empty(&s) && prcd(s.A[s.top],str[i][0]))
					{
						char t = pop(&s);
						if(t=='(')
							continue;
						si[f++][0]=t;
						
					}
					push(&s,str[i][0]);
					
				}
			}
		}
		
		while(!empty(&s))
		{
			si[f++][0]=pop(&s);
		}
		
		for(i=0;i<f;i++)
		{
			printf("%s ",si[i]);
		}
		printf("\n");
	}
	return 0;
}