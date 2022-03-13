#include "io.h"
#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>

IoToFile::IoToFile(const std::string& file_one, const std::string& file_two) 
	:file_one_(file_one),file_two_(file_two),random_int_() {
	random_int_.reserve(1000000);
}
IoToFile::~IoToFile() {} 

void IoToFile::GenerateRandomInt() {
	size_t num = 100;
	for (size_t i = 0; i < num; ++i) {
		int number = rand() % 1000 + 1;
		random_int_.push_back(number);
		//std::cout << rand() << std::endl;
	}
}

void IoToFile::WriteToFile(const std::string& file) {
	std::ofstream fout(file);
	if (fout) {
		for (size_t i = 0; i < random_int_.size(); ++i) {
			fout << random_int_[i] << std::endl; // 使用与cout同样的方式进行写入
		}
	}
	fout.close();
}

void IoToFile::ReadFromFile(const std::string& file) {
	random_int_.clear();
	std::ifstream data(file);
	int d;
	while (data >> d) {
		random_int_.push_back(d);
	}
	data.close();
	//for (size_t i = 0; i < random_int_.size(); ++i) {
	//	std::cout << random_int_[i] << std::endl;
	//}
}

void IoToFile::SortInt() {
	std::sort(random_int_.begin(),random_int_.end());
	std::cout << random_int_.size() << std::endl;
}
void IoToFile::Run() {
	GenerateRandomInt();
	WriteToFile(file_one_);
	ReadFromFile(file_one_);
	SortInt();
	WriteToFile(file_two_);
}
 std::string file_one = "D:\\code\\algorithm\\algorithm\\io\\file_one.txt";
 std::string file_two = "D:\\code\\algorithm\\algorithm\\io\\file_two.txt";
int main(int argc, char** argv) {
	//IoToFile io(file_one, file_two);
	IoToFile io(argv[0], argv[1]);
	io.Run();
}

