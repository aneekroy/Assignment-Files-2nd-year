#include<cstdio>
#include<iostream>
//#include<iostream.h>
//#include<bits/stdc++.h>
#include<cstring>
using namespace std;
class str{

char *p;
int *cp;
public:

str(char *c){
cp=new int;
*cp=1;
p =new char[strlen(c)+1];
strcpy(p,c);
}
str(void){
p=NULL;
}
str(String &t){
cp=t.cp;
p=t.p;
*cp=*cp+1;
}

~str(){
if(p!=NULL)
{
cout<<p;
delete p;
}
}
};
int main(void){
str s1("abc"),s2("def");
str s3(s1);
str s4=s2;
return 0;
}

