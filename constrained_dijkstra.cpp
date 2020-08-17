
#include<iostream>
#include<math.h>
using namespace std;
int main(){
float g,p;

int i,k,n,m,v1,v2,rob,max,max1;
cin >> g ;
cin >> k ;
cin >> n ;
cin >> m ;
int noe[n+1];
float adjlist[n+1][n+1][3],t[n+1][3][10000],heap[100000][4];
//initialisation
for(i=1;i<=n;i++){
adjlist[i][0][0] = 0;
t[i][0][0] = 0;
noe[i] =0;
t[i][2][0] = 0;
}
max1 = 0;
for(i=0;i<m;i++){
cin >> v1 >> v2 >> p >> rob ;
adjlist[v1][0][0]+=1;
adjlist[v1][v2][0] = -log10(1-p);
adjlist[v1][v2][0] -=0.00001;
adjlist[v1][v2][1] = rob;
adjlist[v1][v2][2] = 1;
if(v2>max1)
max1 = v2;
}

max=max1;

int count = 0,count1;
for(i=1;i<=n;i++){
if(adjlist[1][i][2]==1){
heap[count][0] = 1;
heap[count][1] = i;
heap[count][2] = adjlist[1][i][0];
heap[count][3] = adjlist[1][i][1];
count++;
}
}

int min,index,flag;
int nor = 0;
count1=0;
while(count1!=count){
min = 100000;
for(i=0;i<count;i++){
if(heap[i][2]<min){
min = heap[i][2];
v1 = heap[i][0];
v2 = heap[i][1];
nor = heap[i][3];
index = i;
}
}
if(noe[v2]<=10000){
if(nor<=k){
noe[v2]+=1;
t[v2][0][noe[v2]] = heap[index][2];
t[v2][1][noe[v2]] = v1;
t[v2][2][noe[v2]] = heap[index][3];
heap[index][2] = 100001;
}
else if(nor>k){
heap[index][2] = 100001;
continue;
}
}
for(i=1;i<=n;i++){
if(v2!=max){
if(adjlist[v2][i][2]==1){
if(t[i][2][noe[i]]<=k && (adjlist[v2][i][1] + t[v2][2][noe[v2]] )<=k ){
heap[count][0] = v2;
heap[count][1] = i;
heap[count][2] = adjlist[v2][i][0] + t[v2][0][noe[v2]];
heap[count][3] = adjlist[v2][i][1] + t[v2][2][noe[v2]];
count++;
}
}
}
}

count1=0;
for(i=0 ; i<count ; i++){
if(heap[i][2]>100000)
count1++;
}

}

flag = 0;
for(i=1;i<=noe[max];i++){
if(t[max][0][i]<=g && noe[max]!=0 && t[max][2][i]<=k){
flag = 1;
}
}
if(flag)
cout << "Yes";
else if (flag == 0)
cout << "No";
}

