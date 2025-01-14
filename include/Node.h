#ifndef Node_h
#define Node_h

#include <vector>

class Node;
struct Edge;

typedef std::unique_ptr<Node> node_t;

class Node
{
public:
    Node() = default;

    void contribute() const;
    void add_value();
    void add_edge(node_t& ngbr);

private:
    std::size_t m_value;
    std::vector<Edge> edges; 
};

struct Edge
{
    node_t& dest_node;
    std::size_t weight {}; 
};


#endif // Node_h