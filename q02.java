
package JavaS1q2;

import java.io.*;
import java.util.*;

public class q02 {
	private Scanner sc=new Scanner(System.in);
	private ItemList list;
	
	///helper function to input an item
       void registerItem(ItemList list)throws Exception{
            String nm ;
	    int cd, ct = 0;
	    double pr = 0.0;
            sc.nextLine();
	    System.out.print("Input code: ");
	    cd = sc.nextInt();
	    System.out.print("Input count: ");
	    ct = sc.nextInt();
	    System.out.print("Input name: ");
            sc.nextLine();
	    nm = sc.nextLine();
	    System.out.print("Input price: ");
	    pr = sc.nextDouble();
	    Item item= new Item(nm, cd, ct, pr);
            list.addItem(item);
            
        }
        
        void returnItem(ItemList list)throws Exception{
            String nm ;
	    int cd, ct = 0;
	    double pr = 0.0;
            sc.nextLine();
            System.out.print("Input name: ");
	    nm = sc.nextLine();
            System.out.print("Input Item code: ");
	    cd = sc.nextInt();
	    System.out.print("Input number of items returned: ");
	    ct = sc.nextInt();
            Item item= new Item(nm, cd, ct, pr);
            list.addItem(item);  
        }
        

        
	void issueItem(ItemList list)throws Exception{
            String nm ;
	    int cd, ct = 0;
	    double pr = 0.0;
            sc.nextLine();
            System.out.print("Input name: ");
	    nm = sc.nextLine();
            System.out.print("Input Item code: ");
	    cd = sc.nextInt();
	    System.out.print("Input number of items issued: ");
	    ct = sc.nextInt();
            Item item= new Item(nm, cd, ct, pr);
            list.removeItem(item);  
        }
        
        
	///helper function to output an item
	void outputItem(Item i) {
		System.out.println("name: " + i.getName() + "\ncode:" + i.getCode() + "\ncount: " + i.getCount() + "\nprice: " + i.getPrice());
	}
        
        
        
	///friend function to output a list
	void outputList(ItemList list) {
		for(int i = 0; i < list.getCurSize(); ++i) {
			outputItem(list.getList()[i]);
			System.out.println();
		}
	}
	
        
        
	///helper function to check if an item is in list
	int findItem(ItemList list) throws IOException {
            System.out.print("Input code: ");
		int cd = sc.nextInt();
		return list.findItem(cd);
	}
        
        
        void findPrice(ItemList list)throws Exception{
            System.out.print("Input code: ");
		int cd = sc.nextInt();
                list.findPrice(cd);
        }
        
        void findStock(ItemList item)throws Exception{
            System.out.print("Input code: ");
		int cd = sc.nextInt();
                list.findStock(cd);
            
        }
        
        
        public void compare(ItemList list)throws Exception{
            
        double pr;
        System.out.print("Enter Price to compare against : ");
        pr = sc.nextDouble();
        System.out.println("\n Following items have price higher than the query amount : ");
            for(int i = 0; i < list.getCurSize(); ++i){
              if( list.getList()[i].comparePrice(pr))
                  outputItem(list.getList()[i]);
                   
                  }   
                
                
                
            }
        
	///friend function to change rate of an item in list
	void changeRate(ItemList list) throws Exception {
		System.out.print("Input code: ");
		int cd = sc.nextInt();
                System.out.print("Input new price: ");
	        double pr = sc.nextDouble();
                
		int index = list.findItem(cd);
		if(index == -1)
			throw new Exception("unavailable item");
		else
			list.getList()[index].setPrice(pr);
	}
        
        
        
	public static void main(String[] args) {
		int c = 1,ch;
		q02 obj = new q02();
		System.out.println("\nMENU:\n" + "\n<0> exit" + "\n<1> create a new list" + "\n<2> Register an item to list" + "\n<3>Make a transaction"  + "\n<4>Make an enquiry"+ "\n<5> change rate of an item on list" + "\n<6> print items on list");
		do {
			System.out.print("\nenter operation code: ");
			try {
				c =obj.sc.nextInt() ;
				switch(c) {
					case 0: System.out.println("terminating program"); break;
					case 1: int n; System.out.print("enter list size: ");
							n = obj.sc.nextInt() ;
							obj.list = new ItemList(n); break;
					case 2:	obj.registerItem(obj.list); break;
					case 3: 
                                                System.out.print("\n<1> To issue an item"+"\n<2> To return an item"+"\n<0>Return to Main Menu");
                                                do{
                                                    System.out.print("\nEnter choice\n");
                                                  ch=obj.sc.nextInt();
                                                switch(ch){
                                                    case 1 : obj.issueItem(obj.list); break;
                                                    case 2 : obj.returnItem(obj.list); break;
                                                    case 0 : System.out.println("Returning to Main Menu....");
                                                }
                                                }while(ch!=0);
                                            break;
                                                 
					case 4: 
                                                System.out.print("\n<1> To know price of item"+"\n<2> To know stock of item"+"\n<3>To check if item exists in List"+"\n<4> Find items costing more than a given amount");
                                                                                               ch=obj.sc.nextInt();
                                                switch(ch){
                                                    case 1 : obj.findPrice(obj.list); break;
                                                    case 2 : obj.findStock(obj.list); break;
                                                    case 3 : if(obj.findItem(obj.list) == -1) System.out.println("item not found");
							     else System.out.println("item found"); break; 
                                                    case 4:  obj.compare(obj.list); break;    
                                                }
                                            break;
                                            
					case 5: obj.changeRate(obj.list); break;
					case 6: obj.outputList(obj.list); break;
					default: throw new Exception("arguments of invalid type");
				}
			}
			catch(Exception e) {
				System.out.println(e.toString() + ": try again");
			}
		}	while(c != 0);
	}
}
