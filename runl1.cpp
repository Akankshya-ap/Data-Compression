#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<fstream>

using namespace std;
int arr[10000];
string encode(string a)
{//cout<<2;
    string b="";
    char c;
    int count1=0;
    int i=0;
    int j=0;
    int x=0;
    int r=0;
    while(a[i]!='\0')
    {//cout<<3;
        c=a[i];r=i;count1=0;
       while(a[++i]!='\0' && c==a[i] )
       {
           count1++;
       }
       b+=c;
       if(count1>2)
       {  // sprintf(c,"%d",count1);
           //b+=c;
           b+=to_string(count1);
           arr[x]=r+1;
           x++;
       }

    }
    b+='\0';
    i=0;

    return b;

}
int main()
{
    string a="wwwwwwwwtttttttiiiiippkkkkkk";
    string b=encode(a);
    //cout<<1;
    int i=0;
    while(b[i]!='\0')
        {cout<<b[i++];//cout<<4;
        }
    return 0;

}
