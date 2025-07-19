#include<bits/stdc++.h>
using namespace std;

bool check(vector<vector<char>>&board, int x, int y)
{
    for(int i=x; i>=0; i--)
    {
        if(board[i][y]=='q') return false;
    }

    int cx=x,cy=y;
    while(cx>=0 && cy>=0)
    {
        if(board[cx][cy]=='q') return false;
        cy--;
        cx--;
    }
    cx=x,cy=y;
    while(cx>=0 && cy<8)
    {
        if(board[cx][cy]=='q') return false;
        cx--;
        cy++;
    }
    return true;
}
int sol(vector<vector<char>>& b,int x)
{
    if(x==8) return 1;
    int ans=0;
    for(int y=0; y< 8 ;y++)
    {
        if(b[x][y]=='.' && check(b,x,y))
        {
            b[x][y]='q';
            ans+=sol(b,x+1);
            b[x][y]='.';
        }
    }
    return ans;
}
int main()
{
    vector<vector<char>> b(8,vector<char>(8));
    for(int i=0; i< 8 ;i++)
    {
        for(int j=0; j< 8 ;j++)
        {
            cin>>b[i][j];
        }
    }
    cout<<sol(b,0)<<endl;
}
