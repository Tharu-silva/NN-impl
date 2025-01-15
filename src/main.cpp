#include "Neural_Network.h"
#include "Node.h"
#include <iostream>

int main()
{
    std::vector<std::size_t> layer_sizes {1,2,3,4};
    Neural_Network* net = new Neural_Network(layer_sizes);
    return 0;
}