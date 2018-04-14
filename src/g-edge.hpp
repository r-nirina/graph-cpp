#ifndef GEDGE_HPP
#define GEDGE_HPP

#include "g-node.hpp"

class GEdge {

	public:
		GEdge(GNode* src, GNode* trg);

		GNode* source;
		GNode* target;

};

#endif