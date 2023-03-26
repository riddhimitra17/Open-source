/*
Name: Suvodeep Das
Section: B
Roll No: 90
Enrollment No: 12020002002129
Routine Management System
Subject Code: PCCS391
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
typedef std::vector<std::string> StringVector;
using namespace std; 

string getPeriod(int, int);

int main(){
	
	cout<<"-------------------------Routine Management System-------------------------\n\n";

int n, m, maxlength=0;
cout<<"Enter Number of days: \n(Mon-Sat:6, Mon-Fri:5) \n";
cin>>n;
cout<<"\nEnter Number of periods for each day: \n";
cin>>m;
std::vector<StringVector> index[n];
StringVector info[n+1][m+1];

cout<<"\nEnter The timings and intervals of periods\n";
string time;
for(int j=0; j<=m; j++)
  {

    cout<<"\nEnter interval of Period: "<<j<<"   : ";
    getline(cin,time);

    info[0][j].resize(time.length());
    info[0][j].push_back(time);
    
  }

string st="day//time";
info[0][0].resize(st.length());
info[0][0].push_back(st);

for(int i=0;i<=n;i++){
         
         for(int j=0; j<=m; j++)
           {           

             if(j==0){
                 switch (i){
                     case 0:{break;}
                     case 1:{string str= "Monday";
                     info[i][j].resize(str.length());
                     info[i][j].push_back(str);
                     std::cout<<"\nEnter Periods for "<<str;
                     break;
                     }
                     case 2:{string str= "Tuesday";
                     info[i][j].resize(str.length());
                     info[i][j].push_back(str);
                     std::cout<<"\nEnter Periods for "<<str;
                     break;
                     }
                     case 3:{string str= "Wednesday";
                     info[i][j].resize(str.length());
                     info[i][j].push_back(str);
                     std::cout<<"\nEnter Periods for "<<str;
                     break;
                     }
                     case 4:{string str= "Thursday";
                     info[i][j].resize(str.length());
                     info[i][j].push_back(str);
                     std::cout<<"\nEnter Periods for "<<str;
                     break;
                     }
                     case 5:{string str= "Friday";
                     info[i][j].resize(str.length());
                     info[i][j].push_back(str);
                     std::cout<<"\nEnter Periods for "<<str;
                     break;
                     }
                     case 6:{string str= "Saturday";
                     info[i][j].resize(str.length());
                     info[i][j].push_back(str);
                     std::cout<<"\nEnter Periods for "<<str;
                     break;
                     }
                     

                     default:{break;}
                     
                    }

                }

                else if(j>0 && i>0)
                {
                    cout<<"\nPeriod name "<<j;
                    string strn = getPeriod(i,j);// code for entering period name. will add a function>> getPeriod()
                    info[i][j].resize(strn.length());
                    info[i][j].push_back(strn);
                }  

            }
    }
    
    cout<<endl;
    for(int o=0; o<=196;o++){
    	cout<<"=-";
	}


    for(int i=0;i<=n;i++){

        cout<<"\n\n"<<endl;

        for(int j=0; j<=m; j++)
           {
            for(int k=0; k<info[i][j].size(); k++){

                string temp=info[i][j][k];

                std::cout<<temp;
            
            }
            


            cout<<setw(20);

	
        }
        cout<<endl;
    } 
    return 0;

}
string getPeriod(int x, int y){

    string strx;
    cout<<"\nEnter the period name for cell "<<x<<","<<y<<"  -> ";
    getline(cin,strx);

    return strx;


}




