#include <iostream>
#include <fstream>
#include <vector>
#include <conio.h>
using namespace std;
static int slength=0;
static int indx=0;
static string sl;
static int li=0;
static string ls;
unsigned long hashFunc(string str)
{
    unsigned long hash = 5381;
    unsigned int size  = str.length();
    unsigned int i     = 0;
    for (i = 0; i < size; i++) {

        hash = ((hash << 5) + hash) + (str[i]); /* hash * 33 + c */
    }

    return hash%10000;
}
vector <string> hashTable[10000];
   

   void search(string s)
    {
        //Compute the index by using the hash function
        int index = hashFunc(s);
        //Search the linked list at that specific index
        for(int i = 0;i < hashTable[index].size();i++)
        {
            if(hashTable[index][i] == s)
            {
                cout << s << " is found! in index " << endl;
                cout<<index<<endl;
                return ;
            }
        }
        cout << s << " is not found!" << endl;
         
    }

    
   void insert(string s)
    {
                // Compute the index using Hash Function
        int index = hashFunc(s);
        // Insert the element in the linked list at the particular index 
        hashTable[index].push_back(s);
        if(slength<s.length())
        {   sl=s;
        	slength=s.length();
        	indx=index;
        }
        ls=s;
        li=index;
        
    }


     void delet(string s)
    {
        //Compute the index by using the hash function
        int index = hashFunc(s);
        //Search the linked list at that specific index
        for(int i = 0;i < hashTable[index].size();i++)
        {
            if(hashTable[index][i] == s)
            {
               hashTable[index][i]="deleted";
                cout << s << " is  found & deleted" << endl;
                return;
            }
        }
        cout << s << " is not found! cannot be deleted" << endl;
    }

 int main()
 { 
   ifstream is;   
   string line;  
   is.open("all.last(5).txt");   
   cout << "inserting file data into hashTable" << endl;   
   while (getline (is,line))  
   {  
    insert(line);
   }  
   cout << "data inserting completed" << endl;   
   is.close();  
   int choice=0;
   
   while(choice!=4)
     {  string s;
     	cout<<"\nlengthiest string~"<<sl<<endl;
     	cout<<"length~"<<slength<<endl;
     	cout<<"index~"<<indx<<endl;
     	cout<<"\nlast inserted strng~"<<ls<<endl;
     	cout<<"index~"<<li<<endl;
     	
     	cout<<"\n------MENU------\n1 -insert\n2 -search\n3 -delete\nenter 4 for exit\n----------------\n->";
     	cin>>choice;
       	 clrscr();
     	switch(choice)
       {  case 1:
       	    cout<<"pls enter last name to insert in hashTable (without space) "<<endl;
       	    cin>>s;
       	    insert(s);
       	    cout<<"inserted"<<endl;
       	    break;
          case 2:
            cout<<"pls enter last name to search into hasTable (without space)  "<<endl;
            cin>>s;
            search(s);
            break;
          case 3:
           cout<<"pls enter last name to delete from hashTable (without space) "<<endl;
            cin>>s;
            delet(s);
            cout<<"deleted"<<endl;
       	    break;
          case 4:
       	    return 0;
         default:
           cout<<"pls enter correct option "<<endl;
      	} 
      }
   
   
    return 0;
  }
