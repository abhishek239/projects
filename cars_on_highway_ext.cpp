#include<iostream>
using namespace std;

struct arr2d{
float m[2][3];
};

int again;
static int possible;
template <class T>
class vehicle{
public:
int r;
vehicle *left,*right;
T toe;
float x; 
float v;
int height;
};


//creating node in regnum tree
template <class T>
vehicle<T>* addvehicle(vehicle<T>** vehicle1,vehicle<T>* temp,int r,float x,T t,float v){
(*vehicle1) = temp;
(*vehicle1)->x = x;
(*vehicle1)->toe = t;
(*vehicle1)->v = v;
(*vehicle1)->left=NULL;
(*vehicle1)->right=NULL;
(*vehicle1)->r = r;
(*vehicle1)->height= 1;
return (*vehicle1);
} 


//right rotation for regnum tree
template <class T>
vehicle<T>* rightrotation1(vehicle<T>* car1){
vehicle<T> *a = car1->left;  
vehicle<T> *b = a->right;  
a->right = car1;  
car1->left = b;

car1->height = 1 + (((height(car1->left))>=(height(car1->right)))?(height(car1->left)):(height(car1->right)));
  
a->height = 1 + (((height(a->left))>=(height(a->right)))?(height(a->left)):(height(a->right)));

return a;
}


//left rotation for regnum tree
template <class T>
vehicle<T>* leftrotation1(vehicle<T>* car1){

vehicle<T> *a = car1->right;  
vehicle<T> *b = a->left;  

a->left = car1;  
car1->right = b;

car1->height = 1 + (((height(car1->left))>=(height(car1->right)))?(height(car1->left)):(height(car1->right)));
  
a->height = 1 + (((height(a->left))>=(height(a->right)))?(height(a->left)):(height(a->right)));

return a;
}


//finding smallest node in a tree rooted at car1 
template <class E>
E* smallest(E* car1){
E *car3 = car1;
if(car3->left != NULL)
car3 = smallest(car3->left);
return car3;
}

//finding largest node in a tree rooted at car1 
template <class G>
G* largest(G* car1){
G *car3 = car1;
if(car3->right!= NULL)
car3 = largest(car3->right);
return car3;
}


template <typename Z>
int height(Z* C)  
{  
if (C == NULL){  
return 0;  }
else{
return C->height;
}  
}  

void swap(float *x,float *y) 
{ 
float temp;
temp = *x;
*x = *y; 
*y = temp; 
} 

class heap{

public:

float time[500][3];
int size;
  
void insert(float t,int r1,int r2) 
{ 
size++; 
int i = size - 1; 
time[i][0] = t; 
time[i][1] = r1;
time[i][2] = r2;
while (i != 0 && time[parent(i)] > time[i]) 
{ 
swap(&(time[i][0]), &(time[parent(i)][0])); 
swap(&(time[i][1]), &(time[parent(i)][1])); 
swap(&(time[i][2]), &(time[parent(i)][2])); 
i = parent(i); 
}

} 
  

arr2d deletemin(arr2d x) 
{  

if (size == 1) 
{ 
size--; 
for(int l=0;l<3;l++)
x.m[0][l] = time[0][l];
return x;
}  
else{
for(int l=0;l<3;l++){
x.m[0][l] = time[0][l];
time[0][l] = time[size-1][l];
} 
size--; 
settleheap(0); 
if(time[0][0]==x.m[0][0])
again=1;
else 
again =0;
return x;
} 
}


int parent(int i){
return (i-1)/2;
} 

int left(int i){
return (2*i + 1);
} 

int right(int i){
return (2*i + 2);
} 



void settleheap(int i) 
{ 
int l = left(i); 
int r = right(i); 
int least = i; 
if (l < size && time[l][0] < time[i][0]) 
least = l; 
if (r < size && time[r][0] < time[least][0]) 
least = r; 
if (least != i) 
{ 
swap(&(time[i][0]), &(time[least][0])); 
swap(&(time[i][1]), &(time[least][1])); 
swap(&(time[i][2]), &(time[least][2])); 
settleheap(least); 
} 
}
 
heap(){
size = 0;
}

};



template <class T>
class regnum{
public:

vehicle<T> *root3;

vehicle<T>* insert(vehicle<T>* vehicle1,vehicle<T>* temp, int r,float x, T t,float v){
if (root3 == NULL){
vehicle<T>* z = addvehicle(&root3,temp,r,x,t,v);
return z;
}
int k;
if(r<(vehicle1->r)){
if(vehicle1->left != NULL){
vehicle1->left = insert(vehicle1->left,temp,r,x,t,v);
}
else{
vehicle1->left = addvehicle(&(vehicle1->left),temp,r,x,t,v);
}
}
else if(r>(vehicle1->r)){
if(vehicle1->right != NULL)
vehicle1->right= insert(vehicle1->right,temp,r,x,t,v);
else {
vehicle1->right = addvehicle(&(vehicle1->right),temp,r,x,t,v);
}
}

else if(r==vehicle1->r){
possible = 0;
return NULL;
}
vehicle1->height = 1 + (((height(vehicle1->left))>=(height(vehicle1->right)))?(height(vehicle1->left)):(height(vehicle1->right)));

int difference = height(vehicle1->left)-height(vehicle1->right);  

if((difference < -1) && (r > vehicle1->right->r)){
vehicle1 = leftrotation1(vehicle1);
}

else if((difference > 1) && (r < vehicle1->left->r)){
vehicle1 = rightrotation1(vehicle1);
}

else if (difference > 1 && r > vehicle1->left->r){
vehicle1->left = leftrotation1(vehicle1->left);
vehicle1 = rightrotation1(vehicle1);
}

else if (difference < -1 && r < vehicle1->right->r){
vehicle1->right = rightrotation1(vehicle1->right);
vehicle1 = leftrotation1(vehicle1);
}

return vehicle1;
}

	
vehicle<T>* remove(vehicle<T>* car1,int r){
//if tree is empty
if (root3 == NULL)
return NULL;

//going to left subtree for deletion
if(r < (car1->r)){
car1->left = remove(car1->left,r);
}

//going to right subtree for deletion
else if( r > (car1->r)){
car1->right = remove(car1->right,r);
}

//if desired node is found 
else if(r == car1->r){
if((car1->left==NULL)&&(car1->right==NULL)){ //node without children
car1=NULL;
}

else if((car1->left==NULL)&&(car1->right!=NULL)){ //node with right child
car1 = car1->right ;
}


else if((car1->left!=NULL)&&(car1->right==NULL)){ //node with left child
car1 = car1->left ;
}

else if((car1->left!=NULL)&&(car1->right!=NULL)){//node with two children
vehicle<T> *car3 = smallest(car1->right);
car1->r = car3->r;
car1->x = car3->x;
car1->toe = car3->toe;
car1->v = car3->v;
car1->right = remove(car1->right,r);
}
}
if(car1==NULL)
return car1;

if(car1 != NULL)
car1->height = 1 + (((height(car1->left))>=(height(car1->right)))?(height(car1->left)):(height(car1->right)));

int difference = height(car1->left)-height(car1->right);  


if((difference < -1) && (height(car1->right->left)-height(car1->right->right) > 0)){
car1->right = rightrotation1(car1->right);
car1 = leftrotation1(car1);
}

else if((difference > 1) && ( (height(car1->left->left)-height(car1->left->right)) < 0)){
car1->left = leftrotation1(car1->left);
car1 = rightrotation1(car1);
}

else if ((difference > 1) && ((height(car1->left->left)-height(car1->left->right))>=0)){
car1 = rightrotation1(car1);
}

else if ((difference < -1) && ((height(car1->right->left)-height(car1->right->right))<=0)){
car1 = leftrotation1(car1);
}

return car1;
}
regnum(){
root3 = NULL;
}
};

int main()
{
int n;
regnum<float> R;
heap constheap;
vehicle<float> *cars[50];
heap newheap[100];
static int c=0;
int r;
int x;
int f;
int v;
int o=0;
int j=0;
int re;
static int k=0;
float t;
static float curr;
cin>> n;
while(n--){
cin >> f;
switch(f){
case 1:
cin >> r;
cin >> x;
cin >> v;
vehicle<float> *temp;
temp = new vehicle<float>;
possible = 1;
R.root3 = R.insert(R.root3,temp,r,x,curr,v);
if(possible!=0){
cars[k] = new vehicle<float>;
cars[k]=temp;
j=0;
while(j<k){
if(cars[j]!=NULL){
t=(((cars[j]->x) - (temp->x))/((temp->v) - (cars[j]->v)));

if(t>0){
constheap.insert(t,cars[k]->r,cars[j]->r);
}
}
j++;
}
k++;
}
break;

case 2:
cin >> re;
o=0;
while(o<k){
if(cars[o]->r == re)
cars[o] = NULL;
o++;
}
cout << "hello";
for(j=0;j<k;j++){
if(cars[j]!=NULL){
t=((cars[j]->x - temp->x)/(temp->v - cars[j]->v));
if(t>0){
newheap[c].insert(t,cars[o]->r,cars[j]->r);
}
}
}
constheap = (newheap[c]);
R.root3 = R.remove(R.root3,r);
c++;
cout << "huhu successfully deleted";
break;

case 3:
again=1;
arr2d x,y;
int arrcoord[100][30];
int s=0;
while(again){
y = constheap.deletemin(x);
for(j=0;j<k;j++){
if(cars[j]->r==y.m[0][1]){
for(o=0;o<k;o++){
if(cars[o]->r==y.m[0][1]){
int coord = ((cars[j]->x)+((cars[j]->v)*(y.m[0][0])));
int x=0;
for(int d=0;d<s;d++){
if(arrcoord[d][1]==coord){
int b=0;
for(int u=2;u<((arrcoord[d][0])+2);u++){
if(y.m[0][1]==arrcoord[d][u])
b++;
}
if(b==0){
arrcoord[d][(arrcoord[d][0]+2)]=y.m[0][1];
(arrcoord[d][0])++;
}
int f=0;
for(int u=2;u<((arrcoord[d][0])+2);u++){
if(y.m[0][2]==arrcoord[d][u])
f++;
}
if(f==0){
arrcoord[d][(arrcoord[d][0]+2)]=y.m[0][2];
(arrcoord[d][0])++;
}
x++;
}
}
if(x==0)
{
arrcoord[s][0]=2;
arrcoord[s][1]=coord;
arrcoord[s][2]=y.m[0][1];
arrcoord[s][3]=y.m[0][2];
s++;
}
}
}
}
}
}
for(int i=0;i<s;i++){
for(j=1;j<(arrcoord[i][0]+2);j++){
cout << arrcoord[i][j] ;
cout << " ";
}
cout << "\n";
} 
curr = y.m[0][0];
break;
}
}
}
