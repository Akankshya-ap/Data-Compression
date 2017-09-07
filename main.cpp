#include <iostream>
#include<stdio.h>

using namespace std;
struct node
{
    char data;
    int wt;
    node *lchild;
    node *rchild;

};
node *a=new node[100];
node *ptr=a;
node *root=NULL;
void huffman(int m);
    void sortt(int m);
    void huffmantree(node *root);
    char c[10];
int main()
{
    int m;
    cout<<"\nEnter the no of characters \n";
    cin>>m;
     for(int i=0;i<m;i++)
    {
        cout<<"\nEnter data\n ";
        cin>>a[i].data;
        cout<<"\n Enter frequency\n";
        cin>>a[i].wt;
        a[i].lchild=NULL;
        a[i].rchild=NULL;
            }
   huffman(m);

}
void huffman(int m)
{int i;
    for( i=0;i<m;i++)
    {//cout<<m;
        sortt(m);
        cout<<"\n\n"<<(ptr+i)->wt;
        node *temp=new node;
        //cout<<"\n1....";
        temp->wt=a[i].wt+a[i+1].wt;
        //cout<<"2.....";
        temp->data='#';
        //cout<<"3....";
        temp->lchild=(ptr+i);
        temp->rchild=(ptr+i+1);
        //cout<<"4....";
                (ptr+i+1)->data=temp->data;
                (ptr+i+1)->wt=temp->wt;
                                (ptr+i+1)->rchild=temp->rchild;
                                                (ptr+i+1)->lchild=temp->lchild;

        //cout<<"5....";
        delete temp;
        }
        root=(ptr+i-1);
        cout<<"\n\n"<<root->wt;
huffmantree(root);
    }
   void sortt(int m)
    {//cout<<m;
        node *temp=new node;
        //cout<<"6.....\n";
        for(int i=0;i<m;i++)
        {
            for(int j=m-1;j>i;j--)
            {//cout<<a[i]->wt<<a[m-1]->wt;
                if(((ptr+j)->wt)<((ptr+j-1)->wt))
                {//cout<<"HUUU\n";
                    *temp=a[j];
                    a[j]=a[j-1];
                    a[j-1]=*temp;
                   // cout<<(ptr+i)->wt<<"\n";
                }
            }
        }

    }
    int x=0;
    void huffmantree(node* root)
    {
        if(root!=NULL)
        {
           if(root->lchild!=NULL)
           {
             c[x]='0';
             x++;
             huffmantree(root->lchild);
             x--;
           }
           if(root->rchild!=NULL)
           {
               c[x]='1';
               x++;
               huffmantree(root->rchild);
               x--;
           }
            if(root->lchild==NULL || root->rchild==NULL)
          {
               cout<<"\n\n"<<root->data<<":";
            for(int i=0;i<x;i++)
                cout<<c[i];

        }
        }

    }

