#include<cstdio.h>
#include<iostream.h>

using namespace std;
 
class time
{
	private:
		int hr;
		int min;
		int sec;
	public:
		time(int a=0,int b=0,int c=0)
		{
			hr=a;
			min=b;
			sec=c;
		}
		void disp12(void)
		{	int flag=0;
			if(hr>=0&&hr<12){
				if(min>=0&&min<60){
					if(sec>=0&&sec<60)
					{
						flag=1;
						printf("The Time in 12Hr format is %d:%d:%d AM",hr,min,sec);
					}}}
	
			else if(hr==12){
				 if(min>=0&&min<60){
					if(sec>=0&&sec<60)
					{
						flag=1;
						printf("The Time in 12Hr format is %d:%d:%d PM",hr,min,sec);
					}
				}
			}
			else if(hr>=12&&hr<24){
				 if(min>=0&&min<60){
					if(sec>=0&&sec<60)
					{
						flag=1;
						printf("The Time in 12Hr format is %d:%d:%d PM",(hr%12),min,sec);
					}
				}
			}
		if(!flag)printf("\nERROR !!!!\n");
		};
		void disp24(void)
		{	int flag=0;
			if(hr>=0&&hr<24){
				if(min>=0&&min<60){
					if(sec>=0&&sec<60)
					{
						flag=1;
						printf("The Time in 12Hr format is %d:%d:%d AM",hr,min,sec);
					}}}
			if(!flag)printf("\nERROR!!!\n");
		}
		void add(int s=0,int m=0,int h=0){
		sec+=s;
		if(sec>=60){
			min+=sec/60;
			sec%=60;
		}
		if(sec<0)
		{
			while(sec<0)
			{
				sec+=60;
				min--;
			}
		}				
		min+=m;
		if(min>=60){
			hr+=min/60;
			min%=60;
		}
		if(min<0)
		{
			while(min<0)
			{
				min+=60;
				hr--;
			}
		}				
		hr+=h;s
		if(hr>=24)
		hrs%=24;		


		void set(char *s,int len)
		{
			
		
