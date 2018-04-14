#ifndef GGRAPH_HPP
#define GGRAPH_HPP

#include "g-node.hpp"

#include <cassert>

class GGraph {

	public:
		GGraph();
		~GGraph();

		// Tests whether there is an edge from the src node to the trg node
		bool are_adjacent(int id_src, int id_trg) const;
		bool are_adjacent(GNode* src, GNode* trg) const;

		// Returns all neighbor edges of a given node
		std::vector<GEdge> neighbors(int id);
		std::vector<GEdge> neighbors(GNode* n);

		// Adds a node, if it is not in the graph
		void add_node(int id);
		void add_node(GNode* n);

	private:
		std::vector<GNode*> nodes;
		unsigned int node_count;
		unsigned int edge_count;

		void _add_node(int id, GNode* n);

};

#endif