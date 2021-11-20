//Queue


#include<iostream>

using namespace std;

typedef struct node
{
	int data;
	struct node *next;
}NODE,*PNODE;

class Queue
{
	private:
		PNODE Head;
		int iSize;
		
	public:
		Queue();
		void Display();
		int Count();
		void Enqueue(int);
		int Dequeue();
};

Queue :: Queue()
{
	Head = NULL;
	iSize = 0;
}

void Queue :: Display()
{
	PNODE temp = Head;
	cout<<"Elemets of queue are\n";
	while(temp != NULL)
	{
		cout<<temp->data<<"\t";
		temp = temp->next;
	}
	cout<<"\n";
}

int Queue :: Count()
{
	return iSize;
}

void Queue :: Enqueue(int iNo)		
{
	PNODE newn = new NODE;
	newn->data = iNo;
	newn->next = NULL;
	
	if(Head == NULL)
	{
		Head = newn;
	}
	else
	{
		PNODE temp = Head;
	
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newn;
	}
	iSize++;
}
	
int Queue :: Dequeue()
{
	if(Head == NULL)
	{
		cout<<"Queue is empty\n";
		return -1;
	}
	else
	{
		int iNo = Head->data;
		PNODE temp = Head;
		Head = Head->next;
		delete temp;
		iSize--;
		
		return iNo;
	}
}

int main()
{
	Queue obj;
	int iChoice = 1 , iNo = 0 , iRet = 0;
	while(iChoice != 0)
	{
		cout<<"Please enter the option\n";
		cout<<"1 : Insert the element\n";
		cout<<"2 : Delete the element\n";
		cout<<"3 : Display the elements\n";
		cout<<"4 : Count the elements\n";
		cout<<"0 : Exit\n";
		cin>>iChoice;
		
		switch(iChoice)
		{
			case 1:
				cout<<"Enter the element :";
				cin>>iNo;
				obj.Enqueue(iNo);
				break;
			
			case 2:
				iRet = obj.Dequeue();
				cout<<"Removed element is : "<<iRet<<"\n";
				break;
				
			case 3:
				obj.Display();
				break;
			
			case 4:
				iRet = obj.Count();
				cout<<"Number of elements are :"<<iRet<<"\n";
				break;
				
			case 0:
				cout<<"Thank you for using application\n";
				break;
			
			default:
				cout<<"Please enter proper value\n";
				break;
		}
	}
	return 0;
}