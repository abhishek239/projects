#include <bits/stdc++.h> 
using namespace std;

int main(){
	long long int n,a,m,b,d,c,i,j,k,l,t,count,temp1,temp2,w;
	double number;
	srand(time(0));
	cin >> number;
	n = number;
	long long int preprocess[n];
	string str,str1,str2;
	
	cin >> str;
	cin >> m;
	//convering strings to integers
	for(a=0;a<n;a++){
		if(str[a]=='0')
			str[a]-='0';
		else
			str[a]-='0';
	}
	//calculating the number of times function should run to achieve the required probability
	t=((log2(1/number))/log2((1-(15/(16*log2(number))))));
	
	
	long long int apow[n];
	
	apow[0]=1;
	//calculating the powers to 2 previously
	for(d=1;d<n;d++){
		apow[d] = apow[d-1]*2;
	}
	//calculating the hash of the substrings previously for program to be faster
		preprocess[0]=0;
			for(w=1;w<= n;w++){
				preprocess[w] = preprocess[w-1] + apow[w-1]*str[w-1];
			}
	//running each test case
	for(a=0;a<m;a++){
		cin >> i >> j >> k >> l;
		//checking whether input is correct or wrong
		if(j-i == l-k){
		
		count = 0;
		
		//running hash function for t trails	
		for(int z=0;z<(t+1);z++){

			long long int p;
		//picking a random number between 1 to 16nlog(n)
			p = (rand())%(int)(16*number*log2(number));
		
			double sum = 0;
				
			sum = (preprocess[j]-preprocess[i-1])/apow[i-1];
			 //calculating hash of 1st string
			temp1=(long long int)sum%p;
		
			
			sum = (preprocess[l]-preprocess[k-1])/apow[k-1];
			//calculating hash of 2nd string
			temp2=(long long int)sum%p;
			
			if(temp1 == temp2)
				count++; 		 
		}
		//printing output 1 with error probability 1/n
		if(count == t+1)
			cout << "1" << endl ;	
		//if atleast once the output of hash function is 0 the final output is zero
		else
			cout << "0" << endl;
	}
	}		
}
