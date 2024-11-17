//Towers of hanoi
#include<iostream>
#include<cmath>
using namespace std;
void movedisk(char fromrod,char torod,int disk)
{
	cout<<"Move disk"<<disk<<"from"<<fromrod<<"to"<<torod<<endl;
}
//iterative solution
 void towerofhanoi(int n)
 {
	char src='A',aux='B',dest='C';
	//swap the destination and quxiliary if n is even
	if(n%2==0)
	swap(dest,aux);

int totalmoves=pow(2,n)-1;

for(int i=1;i<=totalmoves;i++)
{
	if(i%3==1)
	{
		if(n%2==1)
		{
			movedisk(src,dest,1);
		}
		else
		{
			movedisk(src,aux,1);
		}
	}
	else if(i%3==2)
	{
		movedisk(src,aux,2);
		
	}
	else if(i%3==0)
	{
		movedisk(aux,dest,3);
	}
}
}

int main()
{
	int n=3;
	cout<<"The sequence of moves invovled in the towers of hanoi are:\n";
	towerofhanoi(n);
	return 0;
}
