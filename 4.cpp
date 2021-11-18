//Write a program which accept one number and two position from user and check whether bit at first and bit at second position is on or off.

//Input : 10	iPos1 = 3		iPos2 = 7		Output = Bit is Off
//Input : 10	iPos1 = 2		iPos2 = 4		Output = Bit is On


#include<iostream>
using namespace std;

class Code
{
	public :
		int iNo , iPos1 , iPos2;

	Code()
	{
		iNo = 0;
		iPos1 = 0;
		iPos2 = 0;
	}
	Code(int iValue,int Pos1,int Pos2)
	{
		iNo = iValue;
		iPos1 = Pos1;
		iPos2 = Pos2;
	}
	bool CheckBit()
	{
		unsigned int iMask1 = 0x00000001;
		unsigned int iMask2 = 0x00000001;
		unsigned int iMask = 0;
		unsigned int iResult = 0;
	
		if((iPos1< 1) || (iPos1 > 32) || (iPos2 < 1) || (iPos2 > 32))
		{
			return false;
		}
		iMask1 = iMask1 << (iPos1 - 1);
		iMask2 = iMask2 << (iPos2 - 1);
	
		iMask = iMask1 | iMask2;
		iResult = iNo & iMask;
	
		if(iResult == iMask)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

int main()
{
	unsigned int iValue = 0 , iPos1 = 0 , iPos2 = 0;
	bool bRet = false;
	
	cout<<"Enter number : ";
	cin>>iValue;
	
	cout<<"Enter 1st Position : ";
	cin>>iPos1;
	
	cout<<"Enter 2nd Position : ";
	cin>>iPos2;

	Code obj(iValue,iPos1,iPos2);
	bRet = obj.CheckBit();
	
	if(bRet == true)
	{
		cout<<"Bit is On\n";
	}
	else
	{
		cout<<"Bit is Off\n";
	}
	
	return 0;
}