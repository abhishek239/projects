#include<iostream>
#include<string.h>
using namespace std;

class node{
public:
node *left;
node *right ;
int frequency;
int ending;
};

//trie class
class trie{
public:
node* root;
void insert(string str,node* nextnode){
int i;
if(str[0]=='0'){
if(nextnode->left!=NULL){
nextnode->left->frequency+=1;
for(i=0;str[i]!='\0';i++)
str[i] = str[i+1];
insert(str,nextnode->left);
return;
}
else{
node* newnode=new node;
nextnode->left = newnode;
newnode->left = NULL;
newnode->right = NULL;
newnode->frequency = 1;
newnode->ending = 0;
for(i=0;str[i]!='\0';i++)
str[i] = str[i+1];
insert(str,nextnode->left);
return;
}
}
else if(str[0]=='1'){
if(nextnode->right!=NULL){
nextnode->right->frequency+=1;
for(i=0;str[i]!='\0';i++)
str[i] = str[i+1];
insert(str,nextnode->right);
return;
}
else{
node* newnode=new node;
nextnode->right = newnode;
newnode->left = NULL;
newnode->right = NULL;
newnode->frequency = 1;
newnode->ending = 0;
for(i=0;str[i]!='\0';i++)
str[i] = str[i+1];
insert(str,nextnode->right);
return;
}
}
else if(str[0]=='\0'){
nextnode->ending=1;
//nextnode->frequency+=1; 
return;
}
}
void insert1(string str,node* nextnode){
int i;
if(str[0]=='0'){
if(nextnode->left!=NULL){
nextnode->left->frequency+=1;
for(i=0;str[i]!='\0';i++)
str[i] = str[i+1];
insert1(str,nextnode->left);
return;
}
else{
node* newnode=new node;
nextnode->left = newnode;
newnode->left = NULL;
newnode->right = NULL;
newnode->frequency = 1;
newnode->ending = 1;
for(i=0;str[i]!='\0';i++)
str[i] = str[i+1];
insert1(str,newnode);
return;
}
}
else if(str[0]=='1'){
if(nextnode->right!=NULL){
nextnode->right->frequency+=1;
for(i=0;str[i]!='\0';i++)
str[i] = str[i+1];
insert1(str,nextnode->right);
return;
}
else{
node* newnode=new node;
nextnode->right = newnode;
newnode->left = NULL;
newnode->right = NULL;
newnode->frequency = 1;
newnode->ending = 1;
for(i=0;str[i]!='\0';i++)
str[i] = str[i+1];
insert1(str,nextnode->right);
return;
}
}

else if(str[0]=='\0'){
//nextnode->ending=1;
//nextnode->frequency+=1; 
return;
}

}


void remove(string str,node* nextnode){

int i;

if(str[0]=='0'){
if(nextnode->left!=NULL){
nextnode->left->frequency-=1;
for(i=0;str[i]!='\0';i++)
str[i] = str[i+1];
remove(str,nextnode->left);
return;
}
}

else if(str[0]=='1'){
if(nextnode->right!=NULL){
nextnode->right->frequency-=1;
for(i=0;str[i]!='\0';i++)
str[i] = str[i+1];
remove(str,nextnode->right);
return;
}
}

else if(str[0]=='\0'){
//nextnode->ending=1;
//nextnode->frequency+=1; 
return;
}

}


int search(string str,node* testnode ){
int i,k;
if(root==NULL)
return 2;
else{
if(str[0]=='0'){
if(testnode->left!=NULL){
for( i=0;str[i]!='\0';i++)
str[i] = str[i+1];
k=search(str,testnode->left);
}
else
return 0;
}
else if(str[0]=='1'){
if(testnode->right!=NULL){
for( i=0;str[i]!='\0';i++)
str[i] = str[i+1];
k = search(str,testnode->right);
}
else
return 0;
}
else if(str[0]=='\0'){
if(testnode->ending == 1)
return 1;
else 
return 0;
}
return k;
}
}

int search1(string p,node* nextnode){
int k,i;
string str1;

if(root == NULL)
return 0;
else{
if(p[0]=='0'){
if(nextnode->left!= NULL){
for(i=0;p[i]!='\0';i++)
p[i] = p[i+1];
k = search1(p,nextnode->left);
}
else 
return 0;
}
else if(p[0]=='1'){
if(nextnode->right!= NULL){
for(i=0;p[i]!='\0';i++)
p[i] = p[i+1];
k = search1(p,nextnode->right);
}
else
return 0;
}
else if(p[0] == '\0'){
//if(nextnode->ending == 1)
return nextnode->frequency;
}
return k;
}
}



int search2(string p,node* nextnode,int value){
int k,i;

string str1;
if(root == NULL)
return 0;
if(p[0]=='0'){
if(nextnode->left!=NULL){
value+=nextnode->left->frequency;
cout << value <<endl;
for(i=0;p[i]!='\0';i++)
str1[i] = p[i+1];
//cout << p << endl;
k = search2(str1,nextnode->left,value);
}
else
return value;
}

else if(p[0]=='1'){
if(nextnode->right!=NULL){
value+=nextnode->right->frequency;
cout << value <<endl;
for(i=0;p[i]!='\0';i++)
str1[i] = p[i+1];
//cout << p <<endl;
k = search2(str1,nextnode->right,value);
}
else
return value;
}

else if(p[0]=='?'){
if((nextnode->right!=NULL)|(nextnode->left!=NULL)){
if(nextnode->left!=NULL){
value+=nextnode->left->frequency;
cout << value <<endl;
for(i=0;p[i]!='\0';i++)
str1[i] = p[i+1];
//cout << p <<endl;
k = search2(str1,nextnode->left,value);
value = k;
}

if(nextnode->right!=NULL){
value+=nextnode->right->frequency;
cout << value <<endl;
for(i=0;p[i]!='\0';i++)
str1[i] = p[i+1];
//cout <<p<< endl;
k = search2(str1,nextnode->right,value);
}
}
else
return value;
}

else if(p[0] == '\0'){
return value;
}

return k;

}
trie(){
root=NULL;
}

};

int main(){
int t,i,j,c,k,g,flag =0,result,count1,count=0,count2;
string str1,str[100000],p;
cin >> t;
trie totaltrie;
trie newtrie[10000];
while(t--){
cin >> c;
switch(c){
case 1:
cin >> str1;
flag= 0;
if(count){
for(i=0;i<count;i++){
if(str1 == str[i] )
flag = 1;
}
}
if(flag ==0){
str[count] = str1;
count++;
}
break;
case 2:
cin >> str1;
for(i=0;i<count;i++){
if(str1 == str[i])
str[i] = "\0";
}
break ;
case 3:
cin >> p;
count2 = 0;
for(i=0;i < count && str[i]!="\0" ; i++){

for(j=0;(j<=32-strlen(&(p[0])));j++){
count1 = 0;
for(k=0;k<strlen(&(p[0]));k++){
if(p[k] == str[i][j+k])
count1++;
}
if(count1 == strlen(&(p[0])))
count2++;
}
}
cout << count2;
break;
case 4:
cin >> p;
count2 = 0;
for(i=0;i < count && str[i]!="\0" ; i++){
for(j=0;j<strlen(&(p[0]));j++){
if(p[j]=='?'){
count2++;
continue;
}
else if(p[j] == str[i][j])
count2++;
else if(p[j]!=str[i][j])
break;
}
}
cout << count2;
break;
}
} 
}

