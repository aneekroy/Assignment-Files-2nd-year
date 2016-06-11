#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include <cctype>

using namespace std;

class DATE{
	

class STUDENT {
	int roll;
	char name[15];
	char course;


		
	
	public:	 char* get_name(void){
			return name;
		}
		int get_item_code(void){
			return item_code;
		}
		int get_rate(void){
			return rate;
		}
		int set_rate(int r=0){
			 rate=r;
		}
		int get_quantity(void){
			return quantity;
		}
		int set_quantity(int q=0){
			this->quantity=q;
		}
		void update(int item_code=0,char *n='\0',int r=0,int q=0)
		{
		this->item_code=item_code;		
		strcpy(name,n);
		rate=r;
		quantity=q;
		}
};

class stock 
{
	item list[100];
	public:
	
	static int no_of_items_in_list;


		/*stock(void){
		
		for(int i=0;i<100;i++)
		{
			list[i].update();
		}

		}*/
		 int check_exists_return_index(int itemcode=0)
		{
			int i=0,flag=0;
			for(i=0;i<=no_of_items_in_list;i++)
				if(list[i].get_item_code()==itemcode)
				{	
					return i;
					flag=1;
				}
			if(flag==0)
				return -1;
		}
				
		void add_to_list(void)
		{
			int item_code;
			char name[15];
			int  rate=0;
			int quantity;
			printf("\nEnter New Item Code to ADD to the List:");
			char choice='Y';int flag=0,f=0,flg=0,index=-1;
			do{
				scanf("%d",&item_code);
				if(item_code>0)
				{	flg=1;
					if((index=(check_exists_return_index(item_code)))!=-1)
					{ 
	
					do{
						printf("\nItem already exists with Item Code %d\n",item_code);
		printf("\nDo You Want to add item with this Item_code to the already existing item in the list ? (Y/N)");
						cin>>choice;
						if(choice=='Y'||choice=='y')
						{
							this->receive(index);//call to receive already added item
							return;
						
						}				
						else if(choice=='N'||choice=='n')
						{
							printf("\nEnter New Item_Code ");
							flg=0;	
							f=1;
						}
						else{
							printf("\nWRONG CHOICE !!! Enter Again :");
							f=0;										
						}
					}while(f!=1);
					}
				else
				{	//Item code does not exists hence new item code has been entered
					flag=0;
					/*do
					{*/
						printf("\nEnter Name of the New Item :");					
						//getline(cin,name);
						//getline(name,15,'\n');
						scanf("%s",name);
						flag=0;
						/*for(int i=0;i<strlen(name);i++)
						{
							if(!isalnum(name[i])){
							printf("\n Name Can only be AlphaNumeric !! Enter Name again !!\n");
							flag=1;	
							break;
							}
						}*/
					//}while(flag!=0);
					flag=0;
					do{
						printf("\nEnter Rate :");
						scanf("%d",&rate);
						if(rate>0)
						{	
							flag=1;
							printf("\nEnter Quantity\n");
							scanf("%d",&quantity);
							if(quantity>=0)
							{
								no_of_items_in_list++;
							this->list[no_of_items_in_list].update(item_code,name,rate,quantity);	
										
							}
							else{
								printf("\nNegative quantity of items NOT allowed\n");
								printf("\nEnter from Start\n");
								return;
							}
						}
						else{
							flag=0;
							printf("\nNegative Rate for Items NOT Allowed Enter Again\n");
						}
					}while(flag==0);
				}
			}
			else
			{
				printf("\nNegative Value for Item_code not allowed Enter Again!!");
				flg=0;
			}
			}while(flg==0);
		return;
		}//End of function add to list

		void rate_change(void)
		{	
			int i=0,rt=0,flag=0,itemcode=0;
			printf("\nEnter ItemCode of Item whose rate is to be updated:");
			do
			{		
				
				scanf("%d",&itemcode);	
				if((i=check_exists_return_index(itemcode))!=-1){flag=1;
					printf("\nEnter the New Rate :\n");
					scanf("%d",&rt);
					do
					{
						if(rt>0){	
							flag=1;	
							list[i].set_rate(rt);
						}
						else
							printf("\nThe rate can NOT be negative!!! Enter again\n");
					}while(flag==0);
				}		
				else
					printf("\nItem Code does NOT exist Enter Again:");			
			}while(flag!=1);
		return;
		}
		void receive(int index=-1)
		{	
			int i=0,rt=0,flag=0,itemcode=0,q=0;
			
			if(index!=-1){
			goto label1;
			i=index;
			}	
			else
			{			
			printf("\nEnter ItemCode of Item which is to be received:");
			do
			{	scanf("%d",&itemcode);	
				if((i=check_exists_return_index(itemcode))!=-1)
				{
					
				label1:	flag=1;
					printf("\nEnter the Quantity  :\n");
					scanf("%d",&rt);
					do
					{
						if(rt>0){	printf("\nThe Quantity is updated !!");
								flag=1;	
								q=this->list[i].get_quantity();
								list[i].set_quantity(q+rt);
							}
						else
							printf("\nThe quantity can NOT be negative!!! Enter again\n");
					}while(flag==0);
				}		
				else
					printf("\nItem Code does NOT exist Enter Again:");			
			}while(flag!=1);
		
			}
		return;
		}
		void issue(int index=-1)
		{	
			int i=0,rt=0,flag=0,itemcode=0,q=0;
			
			if(index!=-1){
			goto label;
			i=index;
			}	
			else
			{									
			printf("\nEnter ItemCode of Item whose rate is to be updated:");
			do
			{		
				
				scanf("%d",&itemcode);	
				if((i=check_exists_return_index(itemcode))!=-1)
				{
					label : 
					flag=1;
					printf("\nEnter the Quantity of Items to be Issued :\n");
					scanf("%d",&rt);
					do
					{
						if(rt<=list[i].get_quantity()){	
							flag=1;	
							q=list[i].get_quantity();
							list[i].set_quantity(q-rt);
			printf("\n %d Quantity of items with name %s and %d Itemcode has been issued",rt,list[i].get_name(),itemcode);
						}
						else
					printf("\nThe Quantity  asked to be Issued is more than existing quantity!!! Enter again\n");
					}while(flag==0);
				}		
				else
					printf("\nItem Code does NOT exist Enter Again:");			
			}while(flag!=1);
			}
		return;
		}
		
		void show_price(void)
		{	
			int i=0,rt=0,flag=0,itemcode=0;
			printf("\nEnter ItemCode of Item whose price is to be displayed:");
			do
			{	scanf("%d",&itemcode);	
				if((i=check_exists_return_index(itemcode))!=-1){flag=1;
printf("\nThe Price of Item with name %s and Itemcode %d is :%d",list[i].get_name(),list[i].get_item_code(),list[i].get_rate());	
			}
				else
					printf("\nItem Code does NOT exist Enter Again:");			
			}while(flag!=1);
		return;
		}
		void show_quantity(void)
		{	
			int i=0,rt=0,flag=0,itemcode=0;
			printf("\nEnter ItemCode of Item whose price is to be displayed:");
			do
			{	scanf("%d",&itemcode);	
				if((i=check_exists_return_index(itemcode))!=-1)
				{
				flag=1;
printf("\nThe Quantity of Item with name %s and Itemcode %d is :%d",list[i].get_name(),list[i].get_item_code(),list[i].get_quantity());
			}
				else
					printf("\nItem Code does NOT exist Enter Again:");			
			}while(flag!=1);
		return;
		}
};

int stock :: no_of_items_in_list=-1;

int main(void){
	int choice=0;
	stock obj;
	do
	{
		printf("\n\n*************************Main Menu*******************************\n\n");
		printf("\nEnter 1 To Add New Item To the List\n");
		printf("\nEnter 2 To Change the Rate of Item Already in the List\n");
		printf("\nEnter 3 To Issue an Item with Respect to ItemCode\n");
		printf("\nEnter 4 To Receive an Item with respect to ItemCode\n");
		printf("\nEnter 5 To display the Price of an item with respect to Itemcode\n");
		printf("\nEnter 6 To display the QuanTity of an Item with respect to Itemcode\n");
		printf("\nEnter -1 To EXIT !!\n");
		printf("**********************************************************************\n\n");
		scanf("%d",&choice);

		switch(choice)
		{	case -1:
				printf("\nEXITING!! Thank You !!");
				break;
			case 1:
				obj.add_to_list();
				break;
			case 2:
				obj.rate_change();
				break;
			case 3:
				obj.issue();
				break;
			case 4:
				obj.receive();
				break;
			case 5:
				obj.show_price();
				break;
			case 6:
				obj.show_quantity();
				break;
			default :
				printf("WRONG CHOICE !!");
				break;
		}
	}while(choice!=-1);
	return 0;
}

