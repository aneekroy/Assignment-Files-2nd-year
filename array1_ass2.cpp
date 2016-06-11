#include<iostream>

using namespace std;

class array{

	private:
	
		int *arr;
		int size;
	public:
		
		array(int a=0,int value=0){
			int i;
			size=a;
			arr= new int(size);
			for(i=0;i<size;i++)
				arr[i]=value;
		}
		array(const array &a){
			int i;
			size=a.size;
			arr= new int(size);
			for(i=0;i<size;i++)
				arr[i]=a.arr[i];
		}

		array(int *a,int d){
			size=d;
			arr= new int(size);
			for(int h=0;h<size;h++)
				arr[h]=a[h];
		}

		~array() {
			delete arr;
		}

		void display(void);
		

		array operator +(array a){
			int j,k,c;
			c=max(size,a.size);
			array res(c,0);
			if(c==size){
				for(j=0;j<a.size;j++){
					res.arr[j]=arr[j]+a.arr[j];
				}
				for(k=a.size-1;k<c;k++)
					res.arr[k]=arr[k];
			}
			else{
				for(j=0;j<size;j++){
					res.arr[j]=arr[j]+a.arr[j];
				}
				for(k=size-1;k<c;k++)
					res.arr[k]=a.arr[k];
			return *this;
		}
	}
		array operator-(array  a) {
			if(a.size > size) {
				for(int i = 0; i < size; i++)
					a.arr[i] -= arr[i];
				return a;
			}
			else {
				for(int i = 0; i < a.size; i++)
					arr[i] -= a.arr[i];
				this;
			}
			return *this;
		}

		array operator =(array a){

			size=a.size;
			for(int i=0;i<size;i++)
				arr[i]=a.arr[i];
			
			return *this;
		}
		
		
	
			
		int operator [](int i){
			
			if(i<0 || i>size)
				cout<<"\t WRONG CHOICE OF INDEX \n";
			else			
				return(arr[i]);
		}

		friend array operator *(int,array);
		
		array operator *(int x){
	
			for(int i=0;i<size;i++)
				arr[i]*=x;
			return *this;
		}
			
			
};
void array::display(){
	
	cout<<"\t\t THE RESULTANT ARRAY IS: \n";
	for(int j=0;j<size;j++)
		cout<<arr[j]<<" ";
	cout<<endl;
}

array  operator *(int x,array b){
		return(b*x);
}


		

int main(){
	int choice,s,v,s1,v1,m;int choice1,c,c1;array a1;
	while(true){
			cout<<"\n";
			cout<<"\t\t ENTER YOUR CHOICE\n";
			cout<<"\t\t 1. INITIALIZE ARRAY \n";
			cout<<"\t\t 2. ARRAY OPERATIONS\n";
			cout<<"\t\t 3. CONSTANT TYPE OPEARTIONS\n";
			cout<<"\t\t 4.EXIT\n";
			cin>>choice;
			if(choice==4)
				break;
			else{
				switch(choice){
					case 1:cout<<"\t\t1.INITIALIZE ARRAY WITH A SIZE AND VALUE \n";
					       cout<<"\t\t2.INITIALIZE ARRAY WITH ANOTHER OBJECT \n";
					       cout<<"\t\t3.INITIALIZE ARRAY WITH ANOTHER ARRAY \n";
					       cin>>choice1;
						switch(choice1){
					
							case 1: {cout<<"\t\t enter size and value witch which it is to be initialized \n";
								cin>>s>>v;
								a1=array(s,v);
								a1.display();
								break;}
							

							case 2:{cout<<"enter an array object"<<endl;
							       cin>>s>>v;
							       array a2(s,v);
							       a1=a2;
							       a1.display();
								break;
								}
							
							case 3:{int *x,l;
							       cout<<"enter size of array"<<endl;
							       cin>>l;
							       x= new int(l);
							      cout<<"enter the elements of the array with which you want to initialize"<<endl;
								for(int h=0;h<l;h++)
									cin>>x[h];
								array a3(x,l);
								a1=a3;
								a1.display();
								break;}
						
							default: cout<<"wrong input \n";
						}
						break;
					case 2: cout << "\t\t1. Add two arrays(array1 + array2 )" << endl;
						cout << "\t\t2. Subtract two arrays( array1 - array2 )" << endl;
						cout << "\t\t  Enter choice: \n";
						cin>>c;
						switch(c) {
							case 1: {cout<<" enter array b"<<endl;
								cin>>s1>>v1;
								array a4(s1,v1);
								a1 = a4 + a1;
								a1.display(); 
								break;}
							case 2: {cout<<" enter array a and array b"<<endl;
								cin>>s1>>v1;
								array a5(s1,v1);
								a1 = a1 - a5; 
								a1.display();
								break;}
							default : cout<<"Invalid Input";
						}
						break;
						
					case 3:cout<<"\t\t1.FIND AN ELEMENT AT A PARTICULAR LOCATION\n";
					       cout<<"\t\t2.DO A*C(A CONSTANT)\n";
					       cout<<"\t\t3.DO C*A(A CONSTANT)\n";
					       cout<<"\t\tGIVE YOUR CHOICE\n";
						cin>>choice1;
						switch(choice1){
		
							case 1:cout<<"enter the postion in the array to display"<<endl;
							       int i;
							       cin>>i;
							       cout<<a1[i]<<endl;
								break;
		
							case 2:cout<<"\t ENTER THE CONSTANT WITH WHICH TO MULTIPLY\n";
								cin>>c1;
								a1=a1*c1;
								a1.display();
								break;
			
							case 3:cout<<"\t ENTER THE CONSTANT WITH WHICH TO MULTIPLY\n";
								cin>>c1;
								a1=c1*a1;
								a1.display();
								break;
					
							default: cout<<"\t\t wrong choice given \n";
						}
						break;
					default: cout<<"wrong choice"<<endl;
			}
	}
}
return 0;
}
