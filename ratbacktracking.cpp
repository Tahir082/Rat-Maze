#include<iostream>
#include<stdlib.h>

using namespace std;
void clrscr()
{
    system("cls");
}


void maze(int i, int j, int a[][10])
{

    while(a[i][j]==0)
    {
        if(i>=9 || j>=9 && a[i][j]==0)
        {
            cout<<"\nThe End point has been found!!\n\n";
            cout<<"\n\nThe End Point is: "<<i<<", " <<j;
            cout<<"\n\n\n\n\n\n\n";
            break;
        }
        else if(a[i][j+1]==0)
        {
            cout<<"\nThe object has moved towards " <<i<<", "<<j+1 <<"points\n";
            j++;
        }
        else if(a[i+1][j]==0)
        {
            cout<<"\nThe object has moved towards " <<i+1<<", "<<j <<"points\n";
            i++;
        }

        else if(a[i+1][j]!=0 && a[i-1][j]==0)
        {
            a[i][j]=1;
            cout<<"\nThe object has moved towards " <<i-1<<", "<<j <<"points\n";
            i--;


        }
        else if(a[i][j+1]!=0&& a[i][j-1]==0)
        {
            a[i][j]=1;
            cout<<"\nThe object has moved towards " <<i<<", "<<j-1 <<"points\n";
            j--;



        }
        else
        {
            cout<<"\n\nThe Rat has nowhere to go!!\n\n";
            break;
        }


    }
}

int main()
{
    int a[10][10]=
    {
        {1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,1,1,0,1,0,1},
        {1,1,1,0,1,0,0,0,0,1},
        {1,1,0,0,0,0,1,1,0,0},
        {1,1,0,1,1,1,1,1,0,0},
        {1,1,0,0,0,1,1,1,1,1},
        {1,1,0,0,1,1,1,1,1,1},
        {1,1,1,1,0,1,1,1,0,1},
        {1,1,0,0,0,0,1,0,0,1},
        {1,1,1,1,1,1,1,1,1,1}
    };
    cout<<"\t\t\t****RAT IN A MAZE****\n\n\n\n";
    cout<<"Consider the 0s as path and 1s as blockings:\n\n";
    for(int i=1;i<10;i++)
    {
        for(int j=1;j<10;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<" \n\n";
    }
    int i,j;
    cout<<"\nEnter the starting point of the maze\n\n";
    cout<<"Enter the row point:";
    cin>>i;
    cout<<"\nEnter the column point:";
    cin>>j;

    if(a[i][j]!=0)
    {
        cout<<"\n\nEntered point is a black area!!\n\nTry Again!!\n\n";
        system("pause");
        clrscr();
        main();
    }
    maze(i,j,a);
    cout<<"\n\nWant to Play again?? Press Enter!\n\n";
    system("pause");
    clrscr();
    main();

    return 0;
}
