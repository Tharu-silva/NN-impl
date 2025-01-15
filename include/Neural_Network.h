#ifndef Neural_Network_h
#define Neural_Network_h

#include <vector>
#include <memory> 
#include <Node.h>

typedef std::vector<std::unique_ptr<Node>> layer_t;
typedef std::vector<layer_t> network_t;

class Neural_Network 
{
public:
    std::size_t input_dim, output_dim, n_layers;;

    Neural_Network(const std::vector<std::size_t>& layer_sizes)
        : INPUT_LAYER {0}, OUTPUT_LAYER {layer_sizes.size() - 1}, 
        n_layers {layer_sizes.size()}, input_dim {layer_sizes[INPUT_LAYER]}, 
        output_dim {layer_sizes[OUTPUT_LAYER]}
    {
        //Initialise network according to layer sizes
        initialise_network(layer_sizes);
    }

private:
    std::size_t INPUT_LAYER, OUTPUT_LAYER;
    network_t m_network {};

    void initialise_network(const std::vector<std::size_t>& layer_sizes);
};



#endif // Neural_Network_h