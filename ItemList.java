
package JavaS1q2;

public class ItemList {
	private int curSize, ///<member to hold number of items in list
		maxSize; ///<member to hold maximum number of items in list
	private Item list[]; ///<member to hold items in list
	///constructor to initialize data members and validate class invariants
	public ItemList(int n) {
		curSize = 0;
		maxSize = n;
		list = new Item[n];
	}
	///getter function for curSize
	public int getCurSize() {
		return curSize;
	}
	///getter function for maxSize
	public int getMaxSize() {
		return maxSize;
	}
	///getter function for list
	public Item[] getList() {
		return list;
	}
	///setter function to add item to list
	public void addItem(Item item) throws Exception {
		for(int i = 0; i < curSize; ++i)
			if(list[i].getCode() == item.getCode()) {
				list[i].increment(item.getCount());
				return;
			}
		if(curSize < maxSize)
			list[curSize++] = item;
		else
			throw new Exception("list full");
	}
        
	///getter function to remove item from list
	public void removeItem(Item item) throws Exception {
		for(int i = 0; i < curSize; ++i)
			if(list[i].getCode() == item.getCode()) {
				if(item.getCount() < list[i].getCount()) {
					list[i].decrement(item.getCount());
					return;
				}
				else if(item.getCount() == list[i].getCount()) {
					--curSize;
					for(int j = i; j < curSize; ++j)
						list[j] = list[j + 1];
					return;
				}
				else
					throw new Exception("insufficient quantity");
			}
		throw new Exception("unavailable item");
	}
	///member function to find item in list
	public int findItem(int code) {
		for(int i = 0; i < curSize; ++i)
			if(code == list[i].getCode())
				return i;
		return -1;
	}
        
       public void findPrice(int code){
           int q=findItem(code);
           if(q==-1)
                System.out.println("\nItem not in list");
           else{
               System.out.println("\nPrice of given item is : "+list[q].getPrice());
               
           }
           
           
       } 
        
        
       public void findStock(int code){
           int q=findItem(code);
           if(q==-1)
                System.out.println("\nItem not in list");
           else{
               System.out.println("\nStock remaining of given item is : "+list[q].getCount());
               
           }
           
           
       } 
       
       
        
        }
       
       
        
        
