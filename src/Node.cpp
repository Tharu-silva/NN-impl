#include "Node.h"
#include "Neural_Network.h"
#include <iostream>

void Node::contribute() const
{
    std::cout << "Node CONTRIBUTE!" << std::endl;
    //Iterate over edges and call add_value with m_value * edge.weight + m_bias
    std::size_t pre_activ = m_value + m_bias;
    std::size_t activ = ReLU(pre_activ);
    for (const auto& edge: m_edges)
    {
        std::size_t contribution = activ * edge.weight;
        edge.dest_node->add_value(contribution);
    }
}

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