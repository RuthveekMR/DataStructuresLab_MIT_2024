#include<iostream>
#include<math.h>
using namespace std;
int count1=0;
void towers(int numDisks,char source,char dest,char auxiliary)
{
        count1++;
        if(numDisks==1)
        {
                cout<<"Move from "<<source<<" to "<<dest<<endl;
        }
        else
        {
                towers(numDisks-1,source,auxiliary,dest);
                cout<<"Move from "<<source<<" to "<<dest<<endl;
                towers(numDisks-1,auxiliary,dest,source);
        }
}
int main()
{
        int numDisks;
        char source,dest,auxiliary;
        cout<<"Enter number of disks:"<<endl;
        cin>>numDisks;
        cout<<"Enter source, auxiliary and destination towers' name, respectively:"<<endl;
        cin>>source>>auxiliary>>dest;
        towers(numDisks,source,dest,auxiliary);
        cout<<"Number of Moves="<<count1<<endl;                         /*pow(2,numDisks)-1*/
        return 0;
}
