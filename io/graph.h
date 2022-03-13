#include <map>
#include <vector>

using namespace std;
class GraphAlgorithm {
	// ����ÿһ���ڵ�
	// ��ɫ��0����ɫ
	//1 ��ɫ
	//2 ��ɫ
	struct Node
	{
		Node(size_t id, size_t col = 0, int d = 0, int p = -1) :index(id), color(col), distance(d), parent(p) {}
		size_t index;
		size_t color;
		int distance;
		int parent;

	};

public:
	GraphAlgorithm();
	~GraphAlgorithm();
	void Run();
	void GenerateAllNodes();
	void BFS(size_t sorce_index) ;
	void GenerateNeighborList();
	void WriteAllNodes();
private:
	// ������ⲿ��������нڵ�
	std::vector<Node> all_nodes_;
	// ������ʱ�ڽӽڵ��б�,����ÿ���ڵ���all_nodes�е���������
	std::map<size_t, std::vector<size_t>> neighbor_lists_;
};