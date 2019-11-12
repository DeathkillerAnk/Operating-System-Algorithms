#include<iostream>
#include<stdlib.h>
using namespace std;
class sstf_disk
{
    int ref[100];
    int pos,size;
    int find_short(int );
public:
    void getdata();
    void total_move();
};
void sstf_disk::getdata()
{
    cout<<"Enter the current position of head ";
    cin>>pos;
    cout<<"Enter the size of queue : ";
    cin>>size;
    cout<<"Enter the request for tracks : ";
    for(int i=0;i<size;i++)
         cin>>ref[i];
}
int sstf_disk::find_short(int num)
{
    int min=99999,ind,temp;
    for(int i=0;i<size;i++)
    {
        if(ref[i]!=-1)
        {
            temp=abs(num-ref[i]);
            if(min>temp)
            {
                min=temp;
                ind=i;
            }
        }
    }
    return ind;
}
void sstf_disk::total_move()
{
    int num=pos,move=0,ind;
    for(int i=0;i<size;i++)
    {
        ind=find_short(num);
        move+=abs(num-ref[ind]);
        num=ref[ind];
        ref[ind]=-1;
    }
    cout<<"Total head movements : "<<move;
}
int main()
{
    sstf_disk sstf;
    sstf.getdata();
    sstf.total_move();
    return 0;
}