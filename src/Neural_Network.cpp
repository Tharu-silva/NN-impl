#include <Neural_Network.h>
#include <vector> 
#include <iostream>

void Neural_Network::initialise_network(const std::vector<std::size_t>& layer_sizes)
{
    //Construct nodes
    for (int layer_i = 0; layer_i < n_layers; ++layer_i)
    {
        int layer_size = layer_sizes[layer_i];
        m_network.emplace_back(layer_t(layer_size));
        layer_t& layer {m_network[layer_i]};

        for (int node_i = 0; node_i < layer_size; ++node_i)
            layer[node_i] = std::make_unique<Node>();
    }

    //Set edges 
    for (int layer_i = 0; layer_i < n_layers - 1; ++layer_i)
    {
        layer_t& curr_layer {m_network[layer_i]};
        layer_t& nxt_layer {m_network[layer_i + 1]};

        // Add an edge from each node in current layer to each node in the next layer
        for (const auto& curr_node : curr_layer)
            curr_node->add_edges(nxt_layer);        
    }
}