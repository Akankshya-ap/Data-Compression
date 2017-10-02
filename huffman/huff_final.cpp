#include<iostream>
#include<stdio.h>
#include<math.h>
#include<fstream>
using namespace std;
struct node
{
int index;
int freq;
char data;
int parent;
}a[200];
void huffman(int m);
void sortt(int j,int m);
void code(int m,int n);
char c[10000];
long x=0,r=0,p=0;
void huffman(int m)
{
    for(int i=0;i<m-1;i+=2)
    {
        sortt(i,m);
        a[i].parent=m;
        a[i+1].parent=-m;
        a[m].freq=a[i].freq+a[i+1].freq;
        a[m].data='\0';
        a[m].index=m;
        //cout<<"\n\n"<<a[m].freq;
        m++;
    }//cout<<"\n2........\n";
    a[m-1].parent=0;
}
void sortt(int j,int m)
{ node temp;
    for(int i=j;i<m;i++)
        {
            for(int k=m-1;k>i;k--)
            {
                if(a[k].freq<a[k-1].freq)
                {
                  temp=a[k];
                  a[k]=a[k-1];
                  a[k-1]=temp;
                }
            }
}}
int main()
{

    int i=0,m=0,j;
    for(i=32;i<127;i++,m++)
    {
       a[m].data=(char)i;
       //cout<<a[m].data<<endl;
       a[m].index=m;
       a[m].parent=0;
       a[m].freq=0;
    }
    fstream fil;
    char c;
   // cout<<endl<<endl;
        fil.open("33.txt");
    while(fil.get(c))
    {
        for(i=0;i<m;i++)
            if(c==a[i].data)
            {//cout<<a[i].data;
                p++;
                     a[i].freq++;
                     break;}
    }
    cout<<endl<<endl;
    for(i=0;i<m;i++)
    {
        if(a[i].freq==0)
        {
            //cout<<a[i].data<<endl;
            for(j=i;j<m-1;j++)
            {
                a[j].data=a[j+1].data;
                a[j].freq=a[j+1].freq;
            }
            m--;i--;
        }
    }

   huffman(m);
   cout<<"\n  Data :: Frequency :: Code\n";
   cout<<m;

    for(i=0;i<2*m-1;i++)

      {//cout<<"\n3....";

         for(int j=0;j<m;j++)
    {

               if(a[i].index==j)
       {
           cout<<"\n  "<<a[i].data<<" :: "<<a[i].freq<<" :: ";
        code(m,a[i].parent);
       }
    }
    }
    /*if(a[i].data=='5')
       {
           cout<<"\n  "<<a[i].data<<" :: "<<a[i].freq<<" :: ";
           cout<<a[i].parent;
        code(m,a[i].parent);
       }}*/
        // code(m,68);
    fil.close();
    cout<<"\n\n\nOriginal::"<<p<<"  Compressed::"<<r<<endl<<endl<<endl;


}
void code(int m,int n)
{
    for(int i=1;i<2*m-1;i++)
    {
        if (a[i].index==fabs(n) )
   {
    //cout<<"\n1.....";
   if(n>0)
    {
       // cout<<"\n2....";
        c[x]='0';
        x++;
        //cout<<endl<<a[i].parent<<endl;
        code(m,a[i].parent);
        x--;

    }
    if(n<0)
    {
       // cout<<"\n3....";
         c[x]='1';
        x++;
               //cout<<endl<<a[i].parent<<endl;

        code(m,a[i].parent);
        x--;
    }}
   else if(n==0)
       {
          // cout<<"4....\t";
          for(int i=0;i<x;i++)
              {cout<<c[i];r++;}
              break;
        }

        }
}

