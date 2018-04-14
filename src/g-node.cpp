#include "g-node.hpp"

GNode::GNode(int id) :
id(id) {}

GNode::~GNode() {}

bool GNode::is_neighbor(GNode* n) {
    return (_is_neighbor(n) != -1);
}

void GNode::add_neighbor(GNode* n) {
    if (!is_neighbor(n)) neighbors.push_back(GEdge(this, n));
}

void GNode::remove_neighbor(GNode* n) {
    int index = _is_neighbor(n);
    if (index != -1) {
        // neighbors[index] = neighbors[neighbors.size() - 1];
        neighbors[index] = neighbors.back();
        neighbors.pop_back();
    }
}

unsigned int GNode::num_neighbors() {
    return neighbors.size();
}

/* ----------------------- priavte ----------------------- */

int GNode::_is_neighbor(GNode* n) {
    for (unsigned int i = 0; i < neighbors.size(); ++i) {
        if (neighbors[i].target == n) return i;
    }
    return -1;
}