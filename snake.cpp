#include<conio.h>
#include<process.h>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<windows.h>
#include<ctype.h>
#include<fstream>
#include<time.h>
#include<iomanip>
using namespace std;
const char s=' ';
const int kk=890;
int w=0;
const char o=219;
const char vi=254;
int J=0,I=4,n=5,r=20;int a[300]={0,1,2,3,4};//initial snake body coordinate maximum size 300 heipare snake // 
void gotoxy(int x,int y)// 
{
	COORD pos={x,y};//coordinate data type
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);//predefined want to move input cursor
}
void genrand(void)//random position of food;
{
	srand((unsigned)time(0));
	r=rand()%900;// gives random no. beteen 0 and 899
}

void dispch(char A)// display ch

{int t=a[0],i;
 for(i=0;i<n;i++)
 {
 	if(r==a[i])
 	{
	r+=100;// next food durare asiba
	r%=860;// kichi re divide kar smaller than 899
	 continue;
	 }
 }
 gotoxy(r%30,r/30);// corsur r ku palau 
 
 cout<<vi;//sethi food banu

	switch(A)
	{
		
		case('a'):// left chal
		            
					for( i=0;i<n-1;i++)
					a[i]=a[i+1];	
					if(a[n-1]%30==0)
					a[n-1]+=29;// cant coromodate output screen
					else
					a[n-1]--;
					
					
					gotoxy(a[n-1]%30,a[n-1]/30);
					cout<<o;
					
					
					break;
							   
		case('s'):	
					
					
					
					   	
				    for( i=0;i<n-1;i++)
					a[i]=a[i+1];
					 if(a[n-1]>=870)
					a[n-1]%=870;
					else
					a[n-1]+=30;  	
					gotoxy(a[n-1]%30,a[n-1]/30);
					cout<<o;
						   break;
		case('w'):  
							    	 	
                		   			
					for( i=0;i<n-1;i++)
					a[i]=a[i+1];
					if(a[n-1]<30)
					a[n-1]+=870;
					else
					a[n-1]-=30;

					gotoxy(a[n-1]%30,a[n-1]/30);
					cout<<o;break;

		case('d'):
		            
					for( i=0;i<n-1;i++)
					a[i]=a[i+1];		
					if((a[n-1]+1)%30==0)
					a[n-1]-=29;
					else
					a[n-1]++;
					gotoxy(a[n-1]%30,a[n-1]/30);
					cout<<o;
					break;	}
		for(i=0;i<n-1;i++)
		{
			gotoxy(a[i]%30,a[i]/30);
			cout<<o;
		}
		gotoxy(t%30,t/30);
		cout<<s;// tail move karigala sthi pain blank space
		for(i=0;i<n-1;i++)// body touch
		{
			if(a[i]==a[n-1])
			{
				cout<<"\n gameover\n";
				exit(1);
			}
		}
		if(a[n-1]==r)
		{
				switch(A)
	{
		
		case('a'):
		            
						
					if(a[n-1]%30==0)
					a[n]=a[n-1]+29;
					else
					a[n]=a[n-1]-1;
					
					
					gotoxy(a[n]%30,a[n]/30);
					cout<<o;
					
					
					break;
							   
		case('s'):	
					
					
					
					   	
					
					 if(a[n-1]>=870)
					a[n]=a[n-1]%870;
					else
					a[n]=a[n-1]+30;  	
					   	gotoxy(a[n]%30,a[n]/30);
					cout<<o;
						   break;
		case('w'):  
							    	 	
                		   			
					
					if(a[n-1]<30)
					a[n]=a[n-1]+870;
					else
					a[n]=a[n-1]-30;

					gotoxy(a[n]%30,a[n]/30);
					cout<<o;break;

		case('d'):
		            
							
					if((a[n-1]+1)%30==0)
					a[n]=a[n-1]-29;
					else
					a[n]=a[n-1]+1;
					gotoxy(a[n]%30,a[n]/30);
					cout<<o;
					break;	}
			genrand();n++;
			
		}
		
}




int main()
{
	int i;
	char c='O';
	system("color F2");//output colour screen
	gotoxy(I,J);// initial food position
//	cout<<c;
	c='d';
	char key_press;
	int a1=10000;// game to be terminated sanke 10000 thara agaku jiba
	while(a1--) 
	{char a;
	if(kbhit())//kbhit predefine keyboard hit//no waiting// auto input bool return 
	{
		a=getch();// recent keyboard hit value;
	c=a;// most recent dir store kare
		            
}
else
{
	dispch(c);// a pare au dabaeni same dir re gala
	
}
		
		Sleep(40);// speed of snake
						
		
	}
	return 0;getch(); 
}
