#include"io.h"
#include<string>
#include<vector>
#include<cstdlib>
#include <ctime> // Header file needed to use time
#include <iostream>
#include<fstream>
#include"D:/code/algorithm/algorithm/insertionsort/insertionsort.h"
IoToFile::IoToFile(const std::string file_one, const std::string file_two) 
	:file_one_(file_one),file_two_(file_two),random_int_() {
	random_int_.reserve(1000000);

}
IoToFile::~IoToFile() {} 

void IoToFile::GenerateRandomInt() {
	size_t num = 1000000;
	for (size_t i = 0; i < num; ++i) {
		int number = rand() % 1000 + 1;
		random_int_.push_back(number);
		//std::cout << rand() << std::endl;
	}
}

void IoToFile::WriteToFile(const std::string file) {
	ofstream fout(file);
	if (fout) {
		size_t num = random_int_.size();
		for (size_t i = 0; i < num; ++i) {
			fout << random_int_[i] << std::endl; // 使用与cout同样的方式进行写入
		}
	}
	fout.close();
}

void IoToFile::ReadFromFile(const std::string file) {
	random_int_.clear();
	ifstream data(file);
	int d;
	while (data >> d) {
		random_int_.push_back(d);
	}
	data.close();
	size_t num = random_int_.size();
	//for (size_t i = 0; i < num; ++i) {
	//	std::cout << random_int_[i] << std::endl;
	//}
}

void IoToFile::SortInt() {
	size_t n = random_int_.size();
		for (int j = 2; j < n; j++) {
			int key = random_int_[j];
			int i = j - 1;
			while (i >= 0 && random_int_[i] > key) {
				random_int_[i + 1] = random_int_[i];
				i = i - 1;
			}
			random_int_[i + 1] = key;
		}
}
void IoToFile::Run() {
	GenerateRandomInt();
	WriteToFile(file_one_);
	ReadFromFile(file_one_);
	SortInt();
	WriteToFile(file_two_);
}


int main() {
	std::string file_one = "D:\\code\\algorithm\\algorithm\\io\\file_one.txt";
	std::string file_two = "D:\\code\\algorithm\\algorithm\\io\\file_two.txt";
	IoToFile io(file_one,file_two);
	io.Run();

}

