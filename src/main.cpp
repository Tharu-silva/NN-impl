#include "Neural_Network.h"
#include "Node.h"
#include <iostream>

int main()
{
    std::vector<std::size_t> layer_sizes {1,2,2,2,1};
    Neural_Network* net = new Neural_Network(layer_sizes);

    std::vector<std::size_t> input {1};
    net->run_inference(input);
    return 0;
}