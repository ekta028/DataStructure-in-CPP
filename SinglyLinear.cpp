//Singly Linear Linked List in C++


#include<iostream>

using namespace std;

typedef struct node
{
	int data;
	struct node *next;
}NODE,*PNODE;

class SinglyLL
{
	private:
		PNODE Head;
		int iSize;
		
	public:
		SinglyLL()
		{
			Head = NULL;
			iSize = 0;
		}
		
		int Count()
		{
			return iSize;
		}
		
		void InsertFirst(int iValue)
		{
			PNODE newn = NULL;
			newn = new NODE;
			newn->data = iValue;
			newn->next = NULL;
			
			if(Head == NULL)			//LL is empty
			{
				Head = newn;
			}
			else						//LL contains at least one node
			{
				newn->next = Head;
				Head = newn;
			}
			iSize++;
		}
		
		void InsertLast(int iValue)
		{
			PNODE newn = NULL;
			PNODE temp = Head;
			
			newn = new NODE;
			newn->data = iValue;
			newn->next = NULL;
			
			if(Head == NULL)			//LL is empty
			{
				Head = newn;
			}
			else						//LL contains at least one node
			{
				while(temp->next != NULL)
				{
					temp = temp->next;
				}
				temp->next = newn;
			}
			iSize++;
		}
		
		void Display()
		{
			PNODE temp = Head;
			
			while(temp != NULL)
			{
				cout<<temp->data<<"->";
				temp = temp->next;
			}
			cout<<"NULL\n";
		}
		
		void DeleteFirst()
		{
			if(Head != NULL)
			{
				PNODE temp = Head;
				Head = Head -> next;
				delete temp;
				iSize--;
			}
		}
		
		void DeleteLast()
		{
			PNODE temp = Head;
			PNODE target = NULL;
			
			if(Head == NULL)
			{
				return;
			}
			
			else
			if(Head->next == NULL)
			{
				delete Head;
				Head = NULL;
				iSize--;
			}
			else
			{
				while(temp->next->next != NULL)
				{
					temp = temp->next;
				}
				delete(temp->next);
				temp->next = NULL;
				iSize--;	
			}
		}
		
		void InsertAtPosition(int no,int iPos)
		{
			int i = 0;
			PNODE newn = NULL;
			PNODE Temp = Head;
	
			if((iPos < 1) || (iPos > iSize + 1))
			{
				return;
			}
			else
			if(iPos == 1)
			{
				InsertFirst(no);
			}
			else
			if(iPos == iSize + 1)
			{
				InsertLast(no);
			}
			else
			{
				newn = new NODE;
				newn->data = no;
				newn->next = NULL;
			
			for(i = 1 ; i < iPos-1 ; i++)
			{
				Temp = Temp -> next;
			}
			newn->next = Temp->next;
			Temp->next = newn;
			}
			iSize++;
		}	

			void DeleteAtPosition(int iPos)
			{
				int i = 0;
				PNODE Temp = Head;
				PNODE Target = NULL;
	
				if((iPos < 1) || (iPos > iSize))
				{
					return;
				}
	
				if(iPos == 1)
				{
					DeleteFirst();
				}
				else
				if(iPos == iSize)
				{
					DeleteLast();
				}
				else
				{
					for(i = 1 ; i < iPos-1 ; i++)
					{
						Temp = Temp -> next;
					}
					Target = Temp->next;
					Temp->next = Target->next;
					free(Target);
				}
				iSize--;
			}
		
};

int main()
{
	int iChoice = 1 , iNo = 0 , iPos = 0;
	
	SinglyLL obj1;
	
	while(iChoice != 0)
	{
		cout<<"Enter your choice :\n";
		cout<<"1 : Insert at first position\n";
		cout<<"2 : Insert at last position\n";
		cout<<"3 : Insert at given position\n";
		cout<<"4 : Delete first node\n";
		cout<<"5 : Delete last node\n";
		cout<<"6 : Delete node at given position\n";
		cout<<"7 : Display the contents\n";
		cout<<"8 : Count the number of nodes\n";
		cout<<"0 : Exit the application\n";
		cin>>iChoice;
		
		switch(iChoice)
		{
			case 1 :
				cout<<"Enter value to be insert\n";
				cin>>iNo;
				obj1.InsertFirst(iNo);
				break;
				
			case 2 :
				cout<<"Enter value to be insert\n";
				cin>>iNo;
				obj1.InsertLast(iNo);
				break;
			
			case 3 :
				cout<<"Enter value to be insert\n";
				cin>>iNo;
				cout<<"Enter Position\n";
				cin>>iPos;
				obj1.InsertAtPosition(iNo,iPos);
				break;
				
			case 4 :
				obj1.DeleteFirst();
				break;
				
			case 5:
				obj1.DeleteLast();
				break;
				
			case 6:
				cout<<"Enter Position";
				cin>>iPos;
				obj1.DeleteAtPosition(iPos);
				break;
				
			case 7:
				obj1.Display();
				break;
				
			case 8:
				iNo = obj1.Count();
				cout<<"Number of elements are :"<<iNo<<"\n";
				break;
			
			case 0:
				cout<<"Thank you for using the application\n";
				break;
				
			default:
				cout<<"Please enter proper option\n";
				break;	
		}
	}
	return 0;
}
		
	