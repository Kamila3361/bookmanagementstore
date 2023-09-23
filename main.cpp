#include<iostream>
#include<string>
#include<string.h>
#include<stdlib.h>

using namespace std;

class book	{
private:
	char *author,*title,*publisher, *sellername;
	float *price;
	int *stock;
public:	
	book()	{
	author= new char[20];
	title=new char[20];
	publisher=new char[20];
  // sellername=username;
	price= new float;
	stock=new int;
	}
	void feeddata();
	void editdata();
	void showdata();
	bool search(char[],char[]);
	void buybook();
  void feedStorageData();
};

void book::feeddata()	{
	cin.ignore();
	cout<<"\nEnter Author Name: ";      cin.getline(author,20);
	cout<<"Enter Title Name: ";       cin.getline(title,20);
	cout<<"Enter Publisher Name: ";   cin.getline(publisher,20);
	cout<<"Enter Price: ";            cin>>*price;
	cout<<"Enter Stock Position: ";   cin>>*stock;   
	
}

void book::editdata()	{
	
	cout<<"\nEnter Author Name: ";      cin.getline(author,20);
	cout<<"Enter Title Name: ";       cin.getline(title,20);
	cout<<"Enter Publisher Name: ";   cin.getline(publisher,20);
	cout<<"Enter Price: ";            cin>>*price;
	cout<<"Enter Stock Position: ";   cin>>*stock;   
	
}

void book::showdata()	{
	cout<<"\nAuthor Name: "<<author;
	cout<<"\nTitle Name: "<<title;
	cout<<"\nPublisher Name: "<<publisher;
	cout<<"\nPrice: "<<*price;
	cout<<"\nStock Position: "<<*stock;   
	cout<<"\n";
}

bool book::search(char tbuy[20],char abuy[20] )	{
	if(strcmp(tbuy,title)==0 && strcmp(abuy,author)==0)
		return true;
	else return false;
		
}

void book::buybook()	{
	int count;
	cout<<"\nEnter Number Of Books to buy: ";
	cin>>count;
	if(count<=*stock)	{
		*stock=*stock-count;
		cout<<"\nBooks Bought Sucessfully";
		cout<<"\nAmount: Rs. "<<(*price)*count;
	}
	else
		cout<<"\nRequired Copies not in Stock";
}


void EnterToTheSystem(int *choice){
  int choice1;
  char username[20];
  cout<<"\n\n\tENTER"
    <<"\n1. As a Seller"
    <<"\n2. As a Buyer"
    <<"\n\nEnter your Choice: ";
  cin>>choice1;
  *choice = choice1;
  cout<<"\nYour user name: ";
  cin.ignore();
  cin.getline(username, 20);
}

void showAllAvailableBooks(book* B[], int i){
  int t;
  for(t=0; t<i; t++){
    cout<<t+1<<" Book:"; 
    B[t]->showdata();
  }
  if(t==0)
    cout<<"\nThere is not any available books";
}

void searchBooks(book* B[], int i, char titlebuy[], char authorbuy[]){
  int t;
  cin.ignore();
  cout<<"\nEnter Title Of Book: "; cin.getline(titlebuy,20);
  cout<<"Enter Author Of Book: ";  cin.getline(authorbuy,20);
  				
  for(t=0;t<i;t++)	{
  	if(B[t]->search(titlebuy,authorbuy))	{
  		cout<<"\nBook Found Successfully";
  		B[t]->showdata();
  		break;
  	}
  }
  if(t==i)
  cout<<"\nThis Book is Not in Stock";
}

int main()	{
	book *B[20];
	int i=0,r,t,choice1, choice2, k=0;
	char titlebuy[20],authorbuy[20], username[20];
  
  EnterToTheSystem(&choice1);
	while(1)	{
    if(choice1==1){
      cout<<"\n\n\t\tMENU"
		  <<"\n1. Entry of New Book"
      <<"\n2. Show All Available Books"
		  <<"\n3. Search For Book"
		  <<"\n4. Edit Details Of Book"
		  <<"\n5. Exit"
		  <<"\n\nEnter your Choice: ";
		  cin>>choice2;

      switch(choice2){
        case 1: B[i] = new book();
				  B[i]->feeddata();
				  i++;	break;

        case 2:
          showAllAvailableBooks(B,i);
          break;

        case 3: 
          searchBooks(B, i, titlebuy, authorbuy);
				  break;

        case 4: cin.ignore();
				  cout<<"\nEnter Title Of Book: "; cin.getline(titlebuy,20);
				  cout<<"Enter Author Of Book: ";  cin.getline(authorbuy,20);
				
				  for(t=0;t<i;t++)	{
					  if(B[t]->search(titlebuy,authorbuy))	{
						  cout<<"\nBook Found Successfully";
						  B[t]->editdata();
						  break;
					  }
				  }
				  if(t==i)
				    cout<<"\nThis Book is Not in Stock";
				  break;

        case 5: 
          EnterToTheSystem(&choice1);
          break;
			  default: cout<<"\nInvalid Choice Entered"; 
      }
    }
    
    else if(choice1==2){
      cout<<"\n\n\t\tMENU"
      <<"\n1. Show All Available Books"
      <<"\n2. Buy Book"
      <<"\n3. Search For Boook"
      <<"\n4. Exit"
      <<"\n\nEnter your Choice: ";
      cin>>choice2;

      switch(choice2) {
        case 1: 
          showAllAvailableBooks(B,i);
          break;

        case 2: cin.ignore();
				  cout<<"\nEnter Title Of Book: "; cin.getline(titlebuy,20);
				  cout<<"Enter Author Of Book: ";  cin.getline(authorbuy,20);
				  for(t=0;t<i;t++)	{
					  if(B[t]->search(titlebuy,authorbuy))	{
						  B[t]->buybook();
						  break;
					  }
				  }
				  if(t==i)
				    cout<<"\nThis Book is Not in Stock";
				  break;

        case 3: 
          searchBooks(B, i, titlebuy, authorbuy);
				  break;

        case 4: 
          EnterToTheSystem(&choice1);
          break;
			  default: cout<<"\nInvalid Choice Entered"; 
      }
    }
	}
	return 0;
}