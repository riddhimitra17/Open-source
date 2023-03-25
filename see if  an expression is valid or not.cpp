#include <stdio.h>
#include<iostream>
using namespace std;

bool isNumber(char * s){
    bool canDot = true;
    bool canE = false;
    bool canSign = true;
    bool eExists = false;
    int digits = 0;

    int i = 0;
    while (s[i] != '\0')
    {
        switch(s[i])
        {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            {
                i++;
                digits++;
                canSign = false;
                canE = true;
                break;
            }

            case '.':
            {
                if(canDot)
                {
                    canDot = false;
                    canSign = false;
                    i++;
                    break;
                }
                else
                {
                    return false;
                }
            }

            case '+':
            case '-':
            {
                if(canSign)
                {
                    canSign = false;
                    i++;
                    break;
                }
                else
                {
                    return false;
                }
            }

            case 'e':
            case 'E':
            {
                if(canE && !eExists)
                {
                    eExists = true;
                    canSign = true;
                    canDot = false;
                    canE = false;
                    digits = 0;
                    i++;
                    break;
                }
                else
                {
                    return false;  
                }
            }
            default:
                return false;
        }
    }
    if(digits)
        return true;
    else
        return false;

}
int main()
{
  char c[1000];
  cout<<"Enter the number  : "<<endl;
  cin>>c;
  if (isNumber(c))
        cout << "Valid";
    else
        cout << "Invalid";
    return 0;
  
}