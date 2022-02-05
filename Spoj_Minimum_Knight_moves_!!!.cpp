#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF  1e9+1

int vis[8][8];
int level[8][8];
vector<pair<int , int>> movements={
   {-1, 2}, {1,2},
   {-1,-2} , {1,-2},
   {2, -1} , {2,1} ,
   {-2 , -1} , {-2,1}
} ;
int getX(string s){
  return s[0]-'a';
}
int getY(string s){
   return s[1] -'1';
}
bool isValid(int x , int y){
  return x>=0 && y>=0 && x<8 && y<8 ;
}
int bfs(string source , string dest){
   int sx = getX(source);
   int sy = getY(source);
   int dx = getX(dest);
   int dy = getY(dest);
   queue<pair<int , int>> q;
   q.push({sx, sy});
   vis[sx][sy] = 1;
   level[sx][sy] = 0;
   while(!q.empty()){
    pair<int,int> v = q.front();
    q.pop();
    for(auto movement : movements){

      int x = v.first + movement.first;
      int y = v.second + movement.second;
      if(!isValid(x, y)) continue;

        if(!vis[x][y]){
          q.push({x,y});
          vis[x][y] =1;
          level[x][y] = level[sx][sy] + 1;
        }
      
    }
    if(level[dx][dy] != INF)
      break;
   }
   return level[dx][dy];

}
void reset(){
  for(int i=0; i<8; i++){
    for(int j=0; j<8 ; j++){
      level[i][j] = INF;
      vis[i][j] = 0;
    }
  }
}
void solve(){
  reset();
  string s1 ,s2;
  cin>>s1>>s2;
 int ans =  bfs(s1, s2);
   // cout<<ans<<endl;
 for(int i=0; i<8; i++){
   for(int j=0; j< 8 ;j++)
    cout<<level[i][j]<<" ";
  cout<<endl;
 }
cout<<endl;
 }
 
int main() {
  ll t ;
  cin>>t;
  while(t--){
    solve();
  }
   return 0;
} 