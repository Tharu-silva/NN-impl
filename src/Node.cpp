#include "Node.h"
#include "Neural_Network.h"

void Node::add_value(std::size_t value)
{
    m_value += value;
}

void Node::add_edges(layer_t &nodes)
{
    //Create edge
    for (int i = 0; i < nodes.size(); ++i)
        m_edges.emplace_back( Edge{nodes[i], 0});   
}