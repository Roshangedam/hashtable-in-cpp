#include<iostream>
#include <stdlib.h>  
#include<string>
#include<stdio.h>

using namespace std;
template <class T>
class BucketList;



template <class T>
class Node{
   
    public :
    string s;
    T t;
    Node<T> * next_;
    Node<T> * prev;
    Node(){
               
        next_=NULL;
       
    }
   
    void getNext(){
         next_=new Node<T>();
        
     }
     bool contain(string s,Node<T> * temp)
     {  
     	if(temp->s==s)
     	{ 
      	   return true;
     	}
     	if(temp->next_==NULL)
     	{  
     	   return false;    	   
     	}    	  
     	else
     	{    	   	   
     	   return contain(s,temp->next_);
     	}
     }
     Node<T> *getKey(string s,Node<T> * temp)
     {  
     	if(temp->s==s)
     	{       	   
      	   return temp; 
     	}
     	while(temp->next_!=NULL)
     	{
     		temp=temp->next_;
           if(temp->s==s)
     	   {  
      	      return temp; 
          	}
     	}
     	return NULL;
     }
     void remove(string s,Node<T> * temp,Node<T> * prev,Node<T> ** frist)
     {    
     	 
     	if(temp->s==s)
     	{ 
     	  if(temp->next_!=NULL&& prev==NULL)
     	  {  
     	  	 *frist= temp->next_;   	  	
     	  }
     	  else
     	  {   
     	  	prev->next_=temp->next_;
     	  }
     	  return;
       	   
     	}
     	if(temp->next_==NULL)
     	{
     		return ;
     	}   	  
     	else{
        prev= temp;  	   
         remove(s,temp->next_,prev,NULL);
     	}
     }
    string toString(Node<T> * temp)
     {  
     	string result;
        x:
     	if(temp->next_!=NULL)
     	{  
     	          
             result.append(" -> ").append(temp->s).append(" ").append(convert(temp->t)); 
             temp=temp->next_; 	   
             goto x;
     	}    	  
     	
     	return result;
     }
    string convert(T a)
    { 
      if(this->s=="")
      {
      	return"";
      }
      	if(typeid(T).name()==typeid(int).name()
      	 || typeid(T).name()==typeid(float).name()
      	 || typeid(T).name()==typeid(double).name()
      	 || typeid(T).name()==typeid(long).name())
	   {        
		    return int2string(a);
			 
	    }
	   else
	   {
	     string r=typeid(a).name();
	     char g=r.at(0);
	     return r.substr(r.find(string(1,g))+1);
	   }
    }
     string int2string(T value)
     {
        char buffer[20];
        sprintf(buffer,"%d",value);
        return string(buffer);
     }
};

template <class T>
class BucketList{

    int   totalBuckets;
    Node<T> ** Buckets_;
    Node<T> * temp[100];
    public:
    BucketList(int Bucket)
    {  
       this->totalBuckets= Bucket;       
       for(int i=0;i<totalBuckets;i++)
       {
         temp[i] = new Node<T>();     
       }
    }
    bool contain(const string &s)
     {  
     	 Node <T> * temp1 ;
         for(int i=0; i<totalBuckets;i++)
         {
           temp1=temp[i];
           if(temp1->contain(s,temp1))
           {
              return true;
           }
         }
         return false;
     }
    int hashV(string theString, int number)
     {
        int sum = 0;
        for(int i=0;i<theString.length();i++)
        {
          sum += int(theString[i]) * 3;
        }
         return sum % number;
      }  
    void insert(const string &s,const T &t)
     {
       
       if(contain(s))
       {
       	 throw new invalid_argument("key value is already inserted");
       }
       Node <T> * temp1 = temp[hashV(s,totalBuckets)];
       checkNext:
       if(temp1->next_==NULL)
       {
       	  temp1->s=s;
          temp1->t=t;
          temp1->getNext();
       }
       else
       {
       	  temp1=temp1->next_;
       	  goto checkNext;
       }       
    }
   
   void remove(const string &s)
     {  
     	 Node <T> * temp1 ;
         for(int i=0; i<totalBuckets;i++)
         {
           temp1=temp[i];
           temp1->remove(s,temp1,NULL,&temp[i]);
           
         }
         
     }
    string toString()
    {
        int i;
   
        string result;
       
        for(i=0;i<totalBuckets;i++)
       {
           
          Node <T> * temp1 = temp[i];
          
          result.append(to_string(i)).append(" ").append(temp1->toString(temp1)).append("\n");    
       }
       
       return result;
    }  
   T operator [](const string &s)const {
   	
   	int i;
       
        for(i=0;i<totalBuckets;i++)
       {          
          Node <T> * temp1 = temp[i]; 
          Node <T> * index=temp1->getKey(s,temp1);
          if(index!=NULL)
          {
          	return index->t;
          }  
          
       }
   		return NULL;
   	}
    
};
/*this data structure contains constructor paramtere constructor gor creating amount of bucket list e.g BucketList<...> (10) will create bucket list for 10 index vallues its support insert values by insert(key,value) pair bool contains(key) method returns true if key present in buket list else it returns false it lso support remove opration and it have overloaded oprator [] for extract value by passing key e.g bucketlist[key] will give vaue of key if it is not present then it will return 0 it have contain(key) method returns true if vlue present else return false and toString() methode for return string representation values*/
