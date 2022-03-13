#include <map>
#include <vector>

using namespace std;
class GraphAlgorithm {
	// 创建每一个节点
	// 颜色，0，白色
	//1 灰色
	//2 黑色
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
	// 保存从外部读入的所有节点
	std::vector<Node> all_nodes_;
	// 创建临时邻接节点列表,保存每个节点在all_nodes中的索引号码
	std::map<size_t, std::vector<size_t>> neighbor_lists_;
};