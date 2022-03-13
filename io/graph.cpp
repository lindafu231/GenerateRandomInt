#include"graph.h"
#include< queue>
#include <iostream>

GraphAlgorithm::GraphAlgorithm():all_nodes_(),neighbor_lists_(){};
GraphAlgorithm::~GraphAlgorithm() {};

void GraphAlgorithm::Run() {
	GenerateAllNodes();
	GenerateNeighborList();
	BFS(0);
	WriteAllNodes();
}

void GraphAlgorithm::GenerateAllNodes() {
	for (size_t i = 0; i < 7; ++i) {
		Node node(i);
		all_nodes_.push_back(node);
	}
}

void GraphAlgorithm::GenerateNeighborList() {
	size_t num = all_nodes_.size();
	std::vector<size_t> neighbors;
	neighbors = {1,2,5,6};
	neighbor_lists_[0] = neighbors;
	neighbors.clear();
	neighbors = {0};
	neighbor_lists_[1] = neighbors;
	neighbors.clear();
	neighbors = {0};
	neighbor_lists_[2] = neighbors;
	neighbors.clear();
	neighbors = { 4,5 };
	neighbor_lists_[3] = neighbors;
	neighbors.clear();
	neighbors = { 3,5,6 };
	neighbor_lists_[4] = neighbors;
	neighbors.clear();
	neighbors = { 0,3,4 };
	neighbor_lists_[5] = neighbors;
	neighbors.clear();
	neighbors = { 0,4 };
	neighbor_lists_[6] = neighbors;
	for (auto each : neighbor_lists_) {
		std::cout << each.first << std::endl;
		for (auto id : each.second) {
			std::cout << all_nodes_[id].index << std::endl;

		}
	}
}
void GraphAlgorithm::BFS(size_t sorce_index) {
	// ����ԭ�㣬�����ԭ�����������������ȱ����������е�·������ӡ����
	Node& source_node = all_nodes_[sorce_index];
	source_node.color = 1;
	std::queue<size_t> search_queue;
	// ��Ԫ��ѹ�����ж�β
	// �����м�����������Ƿ񱻱������ı�־λ
	bool* is_visited = new bool[all_nodes_.size()];
	search_queue.push(sorce_index);
	is_visited[sorce_index] = true;
	while(!search_queue.empty())
	{
		size_t search_id = search_queue.front();
		search_queue.pop();
		auto iter = neighbor_lists_.find(search_id);
		for (auto id : iter->second) {

			Node& target_node = all_nodes_[id];
			//��������ڵ���ӽڵ㶼�Ѿ���������������˺�ɫ�����������ٱ�����
			if (target_node.color == 2) {
				continue;
			}
			// ֱ������Ϊ��ɫ
			target_node.color = 1;
			target_node.distance = all_nodes_[search_id].distance + 1;
			target_node.parent = search_id;
			search_queue.push(id);
			is_visited[id] = true;
		}
		all_nodes_[search_id].color = 2;
	}
}
void GraphAlgorithm::WriteAllNodes() {
	for (auto each : all_nodes_) {
		std::cout <<"  index = " << each.index <<"  distance = " << each.distance <<"  parent = " << each.parent << std::endl;
	
	
	}

}

int main() {
	GraphAlgorithm graph;
	graph.Run();

}