#include<iostream>
using namespace std;

int recursiveFactorial(int num)
{
    if(num==0)
        return 1;
    return num*recursiveFactorial(num-1);
}

int main()
{
    int num;
    cout<<"Enter the no: ";
    cin>>num;
    cout<<"The factorial of the number is: "<<recursiveFactorial(num);
    return 0;
}
