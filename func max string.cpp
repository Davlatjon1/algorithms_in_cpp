#include<iostream>
#include<stdio.h>
#include<sstream>
#include<string>
using namespace std;
string GetLine(string text=""){
	getline(cin, text);
	return text;
}
string Str_working(string text){
	string text_after, words, part_words;
	stringstream ss(text);
	while(!ss.eof()){
		ss>>words;
		while(words.find("/") != string::npos){
			part_words = words.substr(0,words.find("/"));
			text_after.append(part_words+" ");
			words = words.substr(words.find("/")+1,words.length()-words.find("/")-1);
		}
		text_after.append(words+" ");
	}
	return text_after;
}
void max_string(string text){
	stringstream ss(text);
	string max_string, words;
	size_t s=0,max=0;
	while(!ss.eof()){
		ss>>words;
		s = words.length();
		if (s>max){
			max=s;
			max_string.assign(words);
		}			
	}
	cout<<max_string<<"="<<max;		
}
void Function_max_str(){
	string text, text_after;
	text = GetLine();
	text_after = Str_working(text);
	max_string(text_after);
}
 
int main(){
	Function_max_str();
	return 0;
}


