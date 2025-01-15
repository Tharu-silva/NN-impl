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

void Neural_Network::run_inference(const std::vector<std::size_t>& inputs)
{
    assert(inputs.size() == input_dim && "Inputs incorrect size");

    //Iterate over first layer, set values of inputs and call contribute on input nodes
    for (int i = 0; i < input_dim; ++i)
    {
        node_t& input_node {m_network[INPUT_LAYER][i]};
        input_node->add_value(inputs[i]);
        input_node->contribute(); 
    }

    //Iterate over other layers but output layer
    for (int i = 1; i < n_layers - 1; ++i)
    {
        layer_t& layer = m_network[i];
        for (const auto& node: layer)
            node->contribute();
    }   
}