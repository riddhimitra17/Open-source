#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define size 100
	int arr[size];
	int tp=-1;
	void push(int x)
	{
		if (tp==(size-1))
		{
			cout<<"Stack Overflow!"<<endl;
			return;
		}
		else
		{
	 	  tp++;
		  arr[tp]=x;
	    }
    }
    void pop()
    {
    	if (tp==-1)
    	{
    		cout<<"Stack Underflow!"<<endl;
    		return;
		}
		else
		{
			tp--;
		}
	}
	int top()
	{
		return arr[tp];
	}
	void print()
	{
		cout<<" stack is:";
		for(int i=0; i<=tp; i++)
		{
			cout<<arr[i]<<" ";
		
		}
		cout<<endl;
	}
	int main()
	{
		push(2);
		push(3);
		push(4);
		push(5);
		print();
		pop();
		cout<<"After popping";
		print();
		push(6);
		cout<<"After pushing";
		print();
	}
