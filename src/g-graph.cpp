#include "g-graph.hpp"

GGraph::GGraph() :
node_count(0),
edge_count(0) {}

GGraph::~GGraph() {
    for (unsigned int i = 0; i < nodes.size(); ++i) {
        delete nodes[i];
    }
    nodes.clear();
}

bool GGraph::are_adjacent(int id_src, int id_trg) const {
    return nodes[id_src]->is_neighbor(nodes[id_trg]);
}

bool GGraph::are_adjacent(GNode* src, GNode* trg) const {
    return src->is_neighbor(trg) /* && trg->is_neighbor(src) */ ;
}

std::vector<GEdge> GGraph::neighbors(GNode* n) {
    return n->neighbors;
}

std::vector<GEdge> GGraph::neighbors(int id) {
    return nodes[id]->neighbors;
}

void GGraph::add_node(int id) {
    _add_node(id, nullptr);
}

void GGraph::add_node(GNode* n) {
    assert(n != nullptr);
    _add_node(n->id, n);
}

/* ----------------------- private ------------------------ */

void GGraph::_add_node(int id, GNode* n) {
    if (id >= nodes.size()) nodes.resize(id, nullptr);
    if (nodes[id] == nullptr) {
        nodes[id] = (n == nullptr) ? new GNode(id) : n;
        node_count++;
    }
}