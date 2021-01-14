/*
There are two jugs, a-litres jug and b-litres jug (a,b are positive integers). 
There is a pump with unlimited water. Given a positive integer c,
=> how to get exactly c litres.
**Input
  Unique line contains positive integers a,b,c (1≤a,b,c≤900).
**Output
  Line contains the minimal number of steps to get c litres 
  or -1 if no solution found.
TEST
6 8 4
=> 4
-------------------------------------------
*/
#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
/*
bai toan do nuoc 
A -> B
C muc tieu can do 
dung P l nuoc 
...
6Th
lam day binh a
-------------b
do tu a sang b
------b-----a
lam rong binh a
--------------b
....
bfs ->queue
1 mang luu trang thai -> tranh trung nhau
 
*/
//dinh nghia trang thai moi lan do nc
typedef struct{
	int x,y,step;
}state;

//check xem da duyet trang thai chua?
bool visited[901][901]={false};

int min(int a, int b){
	return a<b? a:b;
}

int waterJugBFS(int a,int b,int c){
	queue<state> q; //queue duyet bfs
	q.push({0,0,0}); // trang thai dau tien
	visited[0][0]=true;
	state p;
	while(!q.empty()){
		p=q.front();
		
		if(p.x==c||p.y==c) return p.step;
		//fill jug a
		if(p.x <a){
			if(!visited[a][p.y]){
				visited[a][p.y]=true;
				q.push({a, p.y, p.step+1});
			}
			//pour b to a
			if(p.y>0){
				int minXy=min(a - p.x, p.y);
				if(!visited[p.x + minXy][p.y - minXy]){
				visited[p.x + minXy][p.y - minXy] = true;
				q.push({p.x+minXy,p.y-minXy, p.step+1});
			}
			
		}
}
	//fill jug b
		if(p.y <b){
			if(!visited[p.x][b]){
				visited[p.x][b]=true;
				q.push({p.x, b, p.step+1});
			}
			//pour b to a
			if(p.x>0){
				int minXy = min(b-p.y, p.x);
				if(!visited[p.x-minXy][p.y+minXy]){
				visited[p.x-minXy][p.y+minXy]=true;
				q.push({p.x-minXy,p.y+minXy, p.step+1});
			}
	}
}
	//empty jug a
		if(p.x >0){
			if(!visited[0][p.y]){
				visited[0][p.y]=true;
				q.push({0, p.y, p.step+1});
			}
		}
    	if(p.y >0){
			if(!visited[p.x][0]){
				visited[p.x][0]=true;
				q.push({p.x, 0, p.step+1});
			}
       }
       q.pop();
    }
    return  -1;
}

int main(){
int a,b,c;
cin>>a>>b>>c;
cout<<waterJugBFS(a,b,c);
return 0;
}
