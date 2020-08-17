#include<iostream>
using namespace std;

int possible;

//class for storing car information
template <class T>
class car{
public:
int r;
car<T> *left , *right ;
T toe;
float x;
int height;
int nright;
int nleft;
};
 
//class for storing car information w.r.t registration number
template <class T>
class vehicle{
public:
int r;
vehicle *left,*right;
T toe;
float x; 
int height;
int d;
};



//creating a node in ltr and rtl tree
template <class T>
car<T>* addcar(car<T>** car1,car<T>* car2,int r,float x,T t){
(*car1) = car2;
(*car1)->r = r;
(*car1)->x = x;
(*car1)->toe = t;
(*car1)->left = NULL;
(*car1)->right = NULL;
(*car1)->height = 1;
(*car1)->nright = 0;
(*car1)->nleft = 0;
return (*car1);
}

//creating node in regnum tree
template <class T>
vehicle<T>* addvehicle(vehicle<T>** vehicle1,int r,float x,T t,int d){
(*vehicle1) = new vehicle<T>;
(*vehicle1)->x = x;
(*vehicle1)->toe = t;
(*vehicle1)->left=NULL;
(*vehicle1)->right=NULL;
(*vehicle1)->r = r;
(*vehicle1)->height= 1;
(*vehicle1)->d=d;
return (*vehicle1);
} 

//right rotation for ltr and rtl tree
template <class T>
car<T>* rightrotation(car<T>* car1){
car<T> *a = car1->left;  
car<T> *b = a->right;  

a->right = car1;  
car1->left = b;

car1->nleft = (car1->nleft - 2)/3 ;
a->nright = (2*(a->nright)) + 1;

car1->height =1 + (((height(car1->left))>=(height(car1->right)))?(height(car1->left)):(height(car1->right)));
  
a->height = 1 + (((height(a->left))>=(height(a->right)))?(height(a->left)):(height(a->right)));

return a;
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

//left rotation for ltr and rtl tree
template <class T>
car<T>* leftrotation(car<T>* car1){

car<T> *a = car1->right;  
car<T> *b = a->left;  
a->left = car1;  
car1->right = b;

car1->nright = (car1->nright - 2)/3;
a->nleft  = (2*(a->nleft)) + 1;

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


template <class T>
class LTR{

public:

car<T> *root1;

car<T>* insert(car<T>* car1,car<T>* car2,int r, float x, T t){
if (root1 == NULL){
car<T>* v = addcar(&root1,car2,r,x,t);
return v;
}

if(x<((car1->x)+(t-car1->toe))){
if(car1->left != NULL){
car1->left = insert(car1->left,car2,r,x,t);
car1->nleft = car1->nleft + 1; 

}
else{
car1->left = addcar(&(car1->left),car2,r,x,t);
car1->nleft = car1->nleft + 1;
}
}

else if(x > ((car1->x)+(t-car1->toe))){
if(car1->right != NULL){
car1->right= insert(car1->right,car2,r,x,t);
car1->nright = car1->nright + 1 ;

}
else {
car1->right = addcar(&(car1->right),car2,r,x,t);
car1->nright = car1->nright + 1 ;
}
}

car1->height = 1 + (((height(car1->left))>=(height(car1->right)))?(height(car1->left)):(height(car1->right)));

int difference = height(car1->left)-height(car1->right);  

if((difference < -1) && (x > ((car1->right->x)+(t-car1->right->toe)))){
car1 = leftrotation(car1);
}

else if((difference > 1) && (x < ((car1->left->x)+(t-car1->left->toe)))){
car1 = rightrotation(car1);
}

else if ((difference > 1) && (x > ((car1->left->x)+(t-car1->left->toe)))){
car1->left = leftrotation(car1->left);
car1 = rightrotation(car1);
}

else if ((difference < -1) && (x < ((car1->right->x)+(t-car1->right->toe)))){
car1->right = rightrotation(car1->right);
car1 = leftrotation(car1);
}

return car1;
}

car<T>* remove(car<T>* car1,int x,int t){
//if tree is empty
if (root1 == NULL)
return NULL;


//going to left subtree for deletion
if(x < (car1->x)){
car1->left = remove(car1->left,x,t);
car1->nleft = car1->nleft - 1;
}

//going to right subtree for deletion
else if( x > (car1->x)){
car1->right = remove(car1->right,x,t);
car1->nright = car1->nright - 1;
}

//if desired node is found 
else if(x == (car1->x)){
if((car1->left==NULL)&&(car1->right==NULL)){ //node without children
car<T> *car3 ;
car3=car1;
car1=NULL;
free(car3);
}

else if((car1->left==NULL)&&(car1->right!=NULL)){ //node with right child
car<T> *car3 = car1->right;
*car1 = *car3;
free(car3);
}


else if((car1->left!=NULL)&&(car1->right==NULL)){ //node with left child
car<T> *car3 = car1->left;
*car1 = *car3;
free(car3);
}

else if((car1->left!=NULL)&&(car1->right!=NULL)){//node with two children
car<T> *car3 = smallest(car1->right);
car1->r = car3->r;
car1->x = car3->x;
car1->toe = car3->toe;
car1->right = remove(car1->right,car1->x,t);
}
}

if(car1 != NULL)
car1->height = 1 + (((height(car1->left))>=(height(car1->right)))?(height(car1->left)):(height(car1->right)));

int difference = height(car1->left)-height(car1->right);  

if((difference < -1) && (height(car1->right->left)-height(car1->right->right) > 0)){
car1->right = rightrotation(car1->right);
car1 = leftrotation(car1);
}

else if((difference > 1) && ( (height(car1->left->left)-height(car1->left->right)) < 0)){
car1->left = leftrotation(car1->left);
car1 = rightrotation(car1);
}

else if ((difference > 1) && ((height(car1->left)-height(car1->right))>=0)){

car1 = rightrotation(car1);
}

else if ((difference < -1) && ((height(car1->left)-height(car1->right))<=0)){

car1 = leftrotation(car1);
}

return car1;
}

int countleft(car<T>* car1,float x,float t){

int n;

if(car1 == NULL){
return 0;
}

if(x < ((car1->x)+(t-car1->toe))){
n = countleft(car1->left,x,t);
}

else if(x > ((car1->x)+(t-car1->toe))){
n = countleft(car1->right,x,t);
n = n + 1 + car1->nleft;
}

else if(x == ((car1->x)+(t-car1->toe)))
return car1->nleft;

return n;
}


int countright(car<T>* car1,float x,float t){

int n;

if(car1 == NULL){
return 0;
}

if(x < ((car1->x)+(t-car1->toe))){
n = countright(car1->left,x,t);
n = n + 1 + car1->nright;
}

else if(x > ((car1->x)+(t-car1->toe))){
n = countright(car1->right,x,t);

}

else if(x == ((car1->x)+(t-car1->toe)))
return car1->nright;

return n;
}

car<T>* findimmediateleft(car<T>* car1,float x,float t){
car<T> *car2;
if(car1 == NULL){
return NULL;
}
if( x < ((car1->x)+(t-car1->toe)))
car2 = findimmediateleft(car1->left,x,t);
else if(x > ((car1->x)+(t-car1->toe))){
car2 = findimmediateleft(car1->right,x,t);
if(car2 == NULL)
car2 = car1;
} 
else{
if(car1->left==NULL)
car2 = NULL;
else
car2 = largest(car1->left);
}
return car2;
}


car<T>* findimmediateright(car<T>* car1,float x,float t){
car<T> *car2;
if(car1 == NULL ){
return NULL;
}
if( x < ((car1->x)+(t-car1->toe))){
car2 = findimmediateleft(car1->left,x,t);
if(car2 == NULL)
car2 = car1;
}
else if(x > ((car1->x)+(t-car1->toe))){
car2 = findimmediateleft(car1->right,x,t);
} 
else{
if(car1->right==NULL)
car2 = NULL;
else
car2 = smallest(car1->right);
}
return car2;
}


LTR<T>(){
root1=NULL;
}
};

template <class T>
class RTL{

public:

car<T> *root2;

car<T>* insert(car<T>* car1,car<T>* car2,int r, float x, T t){
if (root2 == NULL){
car<T>* v = addcar(&root2,car2,r,x,t);
return v;
}

if(x<((car1->x)-(t-car1->toe))){
if(car1->left != NULL){
car1->left = insert(car1->left,car2,r,x,t);
car1->nleft = car1->nleft + 1; 

}
else{
car1->left = addcar(&(car1->left),car2,r,x,t);
car1->nleft = car1->nleft + 1;
}
}

else if(x > ((car1->x)-(t-car1->toe))){
if(car1->right != NULL){
car1->right= insert(car1->right,car2,r,x,t);
car1->nright = car1->nright + 1 ;

}
else {
car1->right = addcar(&(car1->right),car2,r,x,t);
car1->nright = car1->nright + 1 ;
}
}

car1->height = 1 + (((height(car1->left))>=(height(car1->right)))?(height(car1->left)):(height(car1->right)));

int difference = height(car1->left)-height(car1->right);  

if((difference < -1) && (x > ((car1->right->x)-(t-car1->right->toe)))){
car1 = leftrotation(car1);
}

else if((difference > 1) && (x < ((car1->left->x)-(t-car1->left->toe)))){
car1 = rightrotation(car1);
}

else if ((difference > 1) && (x > ((car1->left->x)-(t-car1->left->toe)))){
car1->left = leftrotation(car1->left);
car1 = rightrotation(car1);
}

else if ((difference < -1) && (x < ((car1->right->x)-(t-car1->right->toe)))){
car1->right = rightrotation(car1->right);
car1 = leftrotation(car1);
}

return car1;
}

car<T>* remove(car<T>* car1,int x,int t){
//if tree is empty
if (root2 == NULL)
return NULL;


//going to left subtree for deletion
if(x < (car1->x)){
car1->left = remove(car1->left,x,t);
car1->nleft = car1->nleft - 1;
}

//going to right subtree for deletion
else if( x > (car1->x)){
car1->right = remove(car1->right,x,t);
car1->nright = car1->nright - 1;
}

//if desired node is found 
else{
if((car1->left==NULL)&&(car1->right==NULL)){ //node without children
car<T> *car3 ;
car3=car1;
free(car3);
}

else if((car1->left==NULL)&&(car1->right!=NULL)){ //node with right child
car<T> *car3 = car1->right;
*car1 = *car3;
free(car3);
}


else if((car1->left!=NULL)&&(car1->right==NULL)){ //node with left child
car<T> *car3 = car1->left;
*car1 = *car3 ;
free(car3);
}

else if((car1->left!=NULL)&&(car1->right!=NULL)){//node with two children
car<T> *car3 = smallest(car1->right);
car1->r = car3->r;
car1->x = car3->x;
car1->toe = car3->toe;
car1->right = remove(car1->right,car1->x,t);
}
}

if(car1 != NULL)
car1->height = 1 + (((height(car1->left))>=(height(car1->right)))?(height(car1->left)):(height(car1->right)));

int difference = height(car1->left)-height(car1->right);  


if((difference < -1) && (height(car1->right->left)-height(car1->right->right) > 0)){
car1->right = rightrotation(car1->right);
car1 = leftrotation(car1);
}

else if((difference > 1) && ( (height(car1->left->left)-height(car1->left->right)) < 0)){
car1->left = leftrotation(car1->left);
car1 = rightrotation(car1);
}

else if ((difference > 1) && ((height(car1->left)-height(car1->right))>=0)){

car1 = rightrotation(car1);
}

else if ((difference < -1) && ((height(car1->left)-height(car1->right))<=0)){

car1 = leftrotation(car1);
}

return car1;
}

int countleft(car<T>* car1,float x,float t){

int n;

if(car1 == NULL){
return 0;
}

if(x < ((car1->x)-(t-car1->toe))){
n = countleft(car1->left,x,t);
}

else if(x > ((car1->x)-(t-car1->toe))){
n = countleft(car1->right,x,t);
n = n + 1 + car1->nleft;
}

else if(x == ((car1->x)-(t-car1->toe)))
return car1->nleft;

return n;
}


int countright(car<T>* car1,float x,float t){

int n;

if(car1 == NULL){
return 0;
}

if(x < ((car1->x)-(t-car1->toe))){
n = countright(car1->left,x,t);
n = n + 1 + car1->nright;
}

else if(x > ((car1->x)-(t-car1->toe))){
n = countright(car1->right,x,t);

}

else if(x == ((car1->x)-(t-car1->toe)))
return car1->nright;

return n;
}

car<T>* findimmediateleft(car<T>* car1,float x,float t){
car<T> *car2;
if(car1 == NULL){
return NULL;
}
if( x < ((car1->x)-(t-car1->toe)))
car2 = findimmediateleft(car1->left,x,t);
else if(x > ((car1->x)-(t-car1->toe))){
car2 = findimmediateleft(car1->right,x,t);
if(car2 == NULL)
car2 = car1;
} 
else{
if(car1->left==NULL)
car2 = NULL;
else
car2 = largest(car1->left);
}
return car2;
}


car<T>* findimmediateright(car<T>* car1,float x,float t){
car<T> *car2;
if(car1 == NULL ){
return NULL;
}
if( x < ((car1->x)-(t-car1->toe))){
car2 = findimmediateleft(car1->left,x,t);
if(car2 == NULL)
car2 = car1;
}
else if(x > ((car1->x)-(t-car1->toe))){
car2 = findimmediateleft(car1->right,x,t);
} 
else{
if(car1->right==NULL)
car2 = NULL;
else
car2 = smallest(car1->right);
}
return car2;
}


RTL<T>(){
root2=NULL;
}
};

template <class T>
class regnum{
public:

vehicle<T> *root3;

vehicle<T>* insert(vehicle<T>* vehicle1, int r,float x, T t, int d){
if (root3 == NULL){
vehicle<T>* v = addvehicle(&root3,r,x,t,d);
return v;
}
int k;
if(r<(vehicle1->r)){
if(vehicle1->left != NULL){
vehicle1->left = insert(vehicle1->left,r,x,t,d);
}
else{
vehicle1->left = addvehicle(&(vehicle1->left),r,x,t,d);
}
}
else if(r>(vehicle1->r)){
if(vehicle1->right != NULL)
vehicle1->right= insert(vehicle1->right,r,x,t,d);
else {
vehicle1->right = addvehicle(&(vehicle1->right),r,x,t,d);
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
vehicle<T> *car3 ;
car3=car1;
car1=NULL;
free(car3);
}

else if((car1->left==NULL)&&(car1->right!=NULL)){ //node with right child
vehicle<T> *car3 = car1->right;
*car1 = *car3 ;
free(car3);
}


else if((car1->left!=NULL)&&(car1->right==NULL)){ //node with left child
vehicle<T> *car3 = car1->left;
*car1 = *car3 ;
free(car3);
}

else if((car1->left!=NULL)&&(car1->right!=NULL)){//node with two children
vehicle<T> *car3 = smallest(car1->right);
car1->r = car3->r;
car1->x = car3->x;
car1->toe = car3->toe;
car1->d = car3->d;
car1->right = remove(car1->right,r);
}
}

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

else if ((difference > 1) && ((height(car1->left)-height(car1->right))>=0)){

car1 = rightrotation1(car1);
}

else if ((difference < -1) && ((height(car1->left)-height(car1->right))<=0)){

car1 = leftrotation1(car1);
}

return car1;
}

vehicle<T>* search(vehicle<T>* car1,int r){

vehicle<T> *car2;

if(car1==NULL)
return root3;

if(r  < car1->r)
car2= search(car1->left,r);

else if (r > car1->r)
car2 = search(car1->right,r);

else if(r==car1->r)
return car1;

return car2; 
} 

regnum(){
root3 = NULL;
}
};


int main()
{
int n;
LTR<float> ltr;
regnum<float> R;
RTL<float> rtl;
int r;
float t;
int x;
int d;
int f;
int k;
int q;
int c1;
int c2;
static float curr;
vehicle<float> *car3;
car<float> *car4;
car<float> *car5;
cin>> n;
while(n--){
cin >> f;
switch(f){
case 1:
cin >> r;
cin >> x;
cin >> t;
cin >> d;
car<float> *temp;
temp = new car<float>;
possible =1;
if(d==0){
R.root3 = R.insert(R.root3,r,x,t,d);
if(possible!=0)
ltr.root1 = ltr.insert(ltr.root1,temp,r,x,t);
}
if(d==1){
R.root3 = R.insert(R.root3,r,x,t,d);
if(possible!=0)
rtl.root2 = rtl.insert(rtl.root2,temp,r,x,t);
}
curr = t;
break;

case 2:
cin >> r;
cin >> t;
car3 = R.search(R.root3,r);
if(car3->d==0){
ltr.root1= ltr.remove(ltr.root1,car3->x,t);
R.root3 = R.remove(R.root3,r);
}
if(car3->d==1){
rtl.root2 = rtl.remove(rtl.root2,car3->x,t);
R.root3 = R.remove(R.root3,r);
}
curr = t;
break;

case 3:
cin >> r;
cin >> t;
car3 = R.search(R.root3,r);
if(car3->d == 0){
car4 = ltr.findimmediateleft(ltr.root1,((car3->x)+(t - (car3->toe))),t);
car5 = rtl.findimmediateleft(rtl.root2,((car3->x)+(t - (car3->toe))),t);
if(car5 == NULL)
cout << car4->r << endl;
else if(car4 == NULL)
cout << car5->r << endl;
else if(car4 == car5)
cout << "-1" << endl;
else if((car4 != NULL) && (car5 != NULL)){ 
if(((car4->x) + (t - car4->toe))>((car5->x) - (t -  car5->toe)))
cout << (car4->r) << endl;

else if(((car4->x) + (t - car4->toe))>((car5->x) - (t -  car5->toe)))
cout << (car5->r) << endl;

else if(((car4->x) + (t - car4->toe))==((car5->x) - (t -  car5->toe))){

if((car4->r) > (car5->r))
cout << (car5->r) << " " << (car4->r) << endl;

else if((car4->r) < (car5->r))
cout << (car4->r) << " " << (car5->r) << endl;
}
}
}
else if(car3->d == 1){
car4 = ltr.findimmediateleft(ltr.root1,((car3->x)-(t - (car3->toe))),t);
car5 = rtl.findimmediateleft(rtl.root2,((car3->x)-(t - (car3->toe))),t);
if(car5 == NULL)
cout << car4->r << endl;
else if(car4 == NULL)
cout << car5->r << endl;
else if(car4 == car5)
cout << "-1" << endl;
else if((car4 != NULL) && (car5 != NULL)){ 
if(((car4->x) + (t - car4->toe))>((car5->x) - (t -  car5->toe)))
cout << (car4->r) << endl;

else if(((car4->x) + (t - car4->toe))>((car5->x) - (t -  car5->toe)))
cout << (car5->r) << endl;

else if(((car4->x) + (t - car4->toe))==((car5->x) - (t -  car5->toe))){

if((car4->r) > (car5->r))
cout << (car5->r) << " " << (car4->r) << endl;

else if((car4->r) < (car5->r))
cout << (car4->r) << " " << (car5->r) << endl;
}
}
}

break;

case 4:
cin >> r;
cin >> t;
car3 = R.search(R.root3,r);
if(car3->d == 0){
car4 = ltr.findimmediateright(ltr.root1,((car3->x)+(t - (car3->toe))),t);
car5 = rtl.findimmediateright(rtl.root2,((car3->x)+(t - (car3->toe))),t);
if(car5 == NULL)
cout << car4->r << endl;
else if(car4 == NULL)
cout << car5->r << endl;
else if(car4 == car5)
cout << "-1" << endl;
else if((car4 != NULL) && (car5 != NULL)){ 
if(((car4->x) + (t - car4->toe))>((car5->x) - (t -  car5->toe)))
cout << (car4->r) << endl;

else if(((car4->x) + (t - car4->toe))>((car5->x) - (t -  car5->toe)))
cout << (car5->r) << endl;

else if(((car4->x) + (t - car4->toe))==((car5->x) - (t -  car5->toe))){

if((car4->r) > (car5->r))
cout << (car5->r) << " " << (car4->r) << endl;

else if((car4->r) < (car5->r))
cout << (car4->r) << " " << (car5->r) << endl;
}
}
}
else if(car3->d == 1){
car4 = ltr.findimmediateright(ltr.root1,((car3->x)-(t - (car3->toe))),t);
car5 = rtl.findimmediateright(rtl.root2,((car3->x)-(t - (car3->toe))),t);
if(car5 == NULL)
cout << car4->r << endl;
else if(car4 == NULL)
cout << car5->r << endl;
else if(car4 == car5)
cout << "-1" << endl;
else if((car4 != NULL) && (car5 != NULL)){ 
if(((car4->x) + (t - car4->toe))>((car5->x) - (t -  car5->toe)))
cout << (car4->r) << endl;

else if(((car4->x) + (t - car4->toe))>((car5->x) - (t -  car5->toe)))
cout << (car5->r) << endl;

else if(((car4->x) + (t - car4->toe))==((car5->x) - (t -  car5->toe))){

if((car4->r) > (car5->r))
cout << (car5->r) << " " << (car4->r) << endl;

else if((car4->r) < (car5->r))
cout << (car4->r) << " " << (car5->r) << endl;
}
}
}
break;

case 5:
cin >> r;
cin >> t;
car3 = R.search(R.root3,r);
if(car3->d == 0){
c1 = ltr.countleft(ltr.root1,((car3->x)+(t - (car3->toe))),t);
c2 = rtl.countleft(rtl.root2,((car3->x)+(t - (car3->toe))),t);
}
else if(car3->d == 1){
c1 = ltr.countleft(ltr.root1,((car3->x)-(t - (car3->toe))),t);
c2 = rtl.countleft(rtl.root2,((car3->x)-(t - (car3->toe))),t);
}
cout << c1+c2 << endl;
break;

case 6:
cin >> r;
cin >> t;
car3 = R.search(R.root3,r);
if(car3->d == 0){
c1 = ltr.countright(ltr.root1,((car3->x)+(t - (car3->toe))),t);
c2 = rtl.countright(rtl.root2,((car3->x)+(t - (car3->toe))),t);
}
else if(car3->d == 1){
c1 = ltr.countright(ltr.root1,((car3->x)-(t - (car3->toe))),t);
c2 = rtl.countright(rtl.root2,((car3->x)-(t - (car3->toe))),t);
}
cout << c1+c2 << endl;
break;

case 7:
cin >> r;
cin >> t;
car3 = R.search(R.root3,r);
if(car3->d == 0){
c1 = rtl.countleft(rtl.root2,((car3->x)+(curr - (car3->toe))),curr);
c2 = rtl.countleft(rtl.root2,((car3->x)+(t - (car3->toe))),t);
cout << c2-c1 << endl;
}
else if(car3->d == 1){
c1 = ltr.countleft(ltr.root1,((car3->x)-(curr - (car3->toe))),curr);
c2 = ltr.countleft(ltr.root1,((car3->x)-(t - (car3->toe))),t);
cout << c1-c2 << endl;
}

break;
}
}


return 0;
}
