#ifndef GNODE_HPP
#define GNODE_HPP

#include "g-edge.hpp"

#include <vector>

class GNode {

	public:
		GNode(int i);
		~GNode();

		void add_neighbor(GNode* n);
		bool is_neighbor(GNode* n);

		int id;
		std::vector<GNode*> neighbors;

};

#endif