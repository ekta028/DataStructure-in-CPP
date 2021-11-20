//Stack


#include<iostream>

using namespace std;

typedef struct node 
{
	int data;
	struct node *next;
}NODE,*PNODE;

class Stack
{
	private:
		PNODE Head;
		int iSize;
		
	public:
		Stack();			
		~Stack();			
		void Push(int);		
		int Pop();			
		int Peek();			
		void Display();
		int Count();
};

Stack :: Stack()
{
	cout<<"Inside counstructor\n";
	this->Head = NULL;
	this->iSize = 0;
}

Stack :: ~Stack()
{
	cout<<"Inside destructor\n";
}

void Stack :: Push(int iNo)		
{
	PNODE newn = new NODE;
	newn->data = iNo;
	newn->next = NULL;
	
	newn->next = Head;
	Head = newn;
	iSize++;
}

int Stack :: Pop()
{
	
	int iRet = -1;
	
	if(iSize == 0)
	{
		cout<<"Stack is empty";
	}
	else
	{
		PNODE temp = Head;
		Head = Head -> next;
		iRet = temp->data;
		delete temp;
	}
	iSize--;
	return iRet;
}

int Stack :: Peek()
{
	if(iSize == 0)
	{
		cout<<"Stack is empty";
		return -1;
	}
	else
	{
		return Head->data;
	}
}

void Stack :: Display()
{
	PNODE temp = Head;
	
	while(temp != NULL)
	{
		cout<<temp->data<<" -> ";
		temp = temp->next;
	}
	cout<<"NULL\n";
}

int Stack :: Count()
{
	return this->iSize;
}

int main()
{
	Stack *sobj = new Stack;			
	int iOption = 1 ,iRet = 0,iNo = 0;
	
	while(iOption != 0)
	{
		cout<<"Please select the option\n";
		cout<<"1 : Push the element\n";
		cout<<"2 : Pop the element\n";
		cout<<"3 : Display the elements\n";
		cout<<"4 : Count number of elements\n";
		cout<<"5 : Peek element\n";
		cout<<"0 : Exit the application\n";
		cin>>iOption;
		
		switch(iOption)
		{
			case 1 :
				cout<<"Enter the element to Push\n";
				cin>>iNo;
				sobj->Push(iNo);
				break;
				
			case 2:
				iRet = sobj->Pop();
				cout<<"Popped element is :"<<iRet<<"\n";
				break;
			
			case 3:
				cout<<"Elemets of stack are\n";
				sobj->Display();
				break;
				
			case 4:
				iRet = sobj->Count();
				cout<<"Number of elements in stack are :"<<iRet<<"\n";
				break;
				
			case 5:
				iRet = sobj->Peek();
				cout<<"Value of top element is :"<<iRet<<"\n";
				break;
				
			case 0:
				cout<<"Thank you for using the application\n";
				delete sobj;  
				break;
				
			default:
				cout<<"Please Enter Proper Number\n";
				break;
		}
	}
	return 0;
}