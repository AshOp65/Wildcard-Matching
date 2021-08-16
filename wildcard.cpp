#include<bits/stdc++.h>
using namespace std;

 int wildCard(string pattern,string str)
    {
        int n=pattern.size();
        int m= str.size();
        int t[m+1][n+1];
        for(int i=0; i<m+1; i++){
        for(int j=0; j<n+1; j++){
            t[i][j]=0;
        }
        }
        t[0][0]=1;
        for(int j=1; j<n+1; j++){
            if(pattern[j-1]=='*')
            t[0][j]=t[0][j-1];
        }
        for(int i=1; i<m+1; i++){
          for(int j=1; j<n+1; j++){
              if(str[i-1]==pattern[j-1] || pattern[j-1]=='?'){
              t[i][j]=t[i-1][j-1];
              }
              else if(pattern[j-1]=='*'){
                  t[i][j]=t[i-1][j] || t[i][j-1];
              }
              else{
                  t[i][j]=0;
              }
          }
        }
        return t[m][n];
    }
    int main()
{
	freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
	string str, pattern;
	
	cin>>pattern;
	cin>>str;
	int  result = wildCard(pattern , str);
	if(result==1)
	cout<<"Yes";
	else
	cout<<"No";

}