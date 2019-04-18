#include<iostream>
#include<string>

using namespace std;

class Student{
	
	private:
		string name;
		int englishScore;
		int mathScore;
		int getSum(){ return englishScore + mathScore;}
	
	public:
		Student (string n, int e, int m){
			name = n;
			englishScore = e;
			mathScore = m;
		}
		void show(){ cout<< name << ":[합계 "<<getSum()<<"점]\n"; }
				
};

int main(void){
	Student a = Student("나동빈",100,98);
	a.show() ;
	system("pause");
}
