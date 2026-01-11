#include<iostream>
using namespace std;

int main()
{
    int i;
    int j;
    for (i=1; i<=10;i++)
    {
        for (j=1;j<=i;j++)
        {
            cout<<"*";
        }
        cout<<"\n";
    }
    return 0;
}