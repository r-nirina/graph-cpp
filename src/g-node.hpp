#ifndef GNODE_HPP
#define GNODE_HPP

#include "g-edge.hpp"

#include <vector>

class GNode {

	public:
		GNode(int id);
		~GNode();

		bool is_neighbor(GNode* n);
		void add_neighbor(GNode* n);
		void remove_neighbor(GNode* n);

		unsigned int num_neighbors();

		int id;
		std::vector<GEdge> neighbors;

	private:
		int _is_neighbor(GNode* n);

};

#endif