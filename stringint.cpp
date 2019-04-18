#include<iostream>
#include<string>


using namespace std;

int main(void){
	
	int i = 123;
	string s = to_string(i);
	cout<<"정수 -> 문자열 :" << s << endl;
	s = "456";
	i=stoi(s);
	cout<< "문자열 -> 정수: "<<i <<endl;
	system("pause");
	return 0;
}
