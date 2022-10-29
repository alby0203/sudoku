#include<iostream>
#include<stdlib.h>
using namespace std;
int possible(int x,int y,int n,int a[][9])
{
  int flag=0;
  for(int i=0;i<9;i=i+1)
    if(a[x][i]==n)
      return 1;
  for(int i=0;i<9;i++)
    if(a[i][y]==n)
      return 1;
  int q,w;
  if(x%3==0)
    w=x;
  else if(x%3==1)
    w=x-1;
  else
    w=x-2;
  if(y%3==0)
    q=y;
  else if(y%3==1)
    q=y-1;
  else
    q=y-2;
  for(int i=0;i<3;i++)
  {
    for(int j=0;j<3;j++)
    {
      if(a[w+i][q+j]==n)
        return 1;
    }
  }
  return 0;
}
int solve(int a[][9]){
  for(int i=0;i<9;i++)
  {
    for(int j=0;j<9;j++){
      if(a[i][j]==0)
      {
        int ans;
        for(int y=1;y<10;y++)
        {
          ans=possible(i,j,y,a);
          if(ans==0){
            a[i][j]=y;
            int gb=solve(a);
            if(gb==1)
              a[i][j]=0;
          }
        }
        if(a[i][j]==0)
        return 1;
        else
        return 0;
      }
    }
  }

}
int main()
{
  int a[9][9];
  for(int i=0;i<9;i++)
    for(int j=0;j<9;j++)
      cin>>a[i][j];
  int h=solve(a);
    cout<<'\n';
    for(int i=0;i<9;i++){
      for(int j=0;j<9;j++){
        cout<<a[i][j]<<' ';
      }
      cout<<'\n';
    }
  }
