#include <Neural_Network.h>
#include <vector> 

void Neural_Network::initialise_network(const std::vector<int>& layer_sizes)
{
    //Construct nodes
    for (int layer_i = 0; layer_i < layer_sizes.size(); ++layer_i)
    {
        int layer_size = layer_sizes[layer_i];
        m_network.emplace_back(layer_t(layer_size));
        layer_t& layer {m_network[layer_i]};

        for (int node_i = 0; node_i < layer_size; ++node_i)
            layer[node_i] = std::make_unique<Node>();
    }

    //Set edges 
    for (int layer_i = 0; layer_i < layer_sizes.size() - 1; ++layer_i)
    {
        layer_t& curr_layer {m_network[layer_i]};
        layer_t& nxt_layer {m_network[layer_i + 1]};

        for (int node_i = 0; node_i < curr_layer.size(); ++node_i)
        {
            node_t& curr_node {curr_layer[node_i]};
            for (int nxt_i = 0; nxt_i < nxt_layer.size(); ++nxt_i)
                curr_node->add_edge(nxt_layer[nxt_i]);
        }

    }

}