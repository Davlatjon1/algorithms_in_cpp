#include<iostream>
#include<string>
#include<sstream>
#include<stdio.h>
using namespace std;
int main(){
	string text;
	getline(cin, text);
	stringstream ss(text);
	string words;
	size_t max=-1,s=0;
	string chast_slova;
	string max_string;
	while(!ss.eof()){
		ss>>words;
		
		while(words.find("/") != string::npos){
			cout<<"zawel"<<endl;
			chast_slova = words.substr(0,words.find("/"));
			s=chast_slova.length();
			if(max<s){
				max=s;
				max_string.assign(chast_slova);
			} 
			words = words.substr(words.find("/")+1,words.length()-words.find("/")-1);
		}
		cout<<"--"<<words<<"--"<<endl;
		s=words.length();
		if(max<s){
			cout<<"DA";
			max=s;
			max_string.assign(words);
		}
	}
	cout<<max_string<<"="<<max;
	
	
	return 0;
	
}

//string test;
//	cin>>test;
//	cout<<test.find("/");
