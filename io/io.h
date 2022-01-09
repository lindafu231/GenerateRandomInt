#include<string>
#include<vector>
using namespace std;
class IoToFile{
public:
	IoToFile::IoToFile(const std::string file_one,const std::string file_two);
	IoToFile::~IoToFile();
	void IoToFile::GenerateRandomInt();
	void IoToFile::WriteToFile(const std::string file);
	void IoToFile::ReadFromFile(const std::string file);
	void IoToFile::SortInt();
	void IoToFile::Run();
private:
	std::string file_one_;
	std::string file_two_;
	std::vector<int> random_int_;
};