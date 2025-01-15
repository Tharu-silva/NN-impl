#ifndef Node_h
#define Node_h

#include <vector>
#include <memory>
class Node;
struct Edge;

typedef std::unique_ptr<Node> node_t;
typedef std::vector<std::unique_ptr<Node>> layer_t;


class Node
{
public:
    Node() = default;

    void contribute() const;
    void add_value(std::size_t value);
    void add_edges(layer_t& ngbrs);

private:
    std::size_t m_value;
    std::vector<Edge> m_edges; 
};

struct Edge
{
    node_t& dest_node;
    std::size_t weight {}; 
};


#endif // Node_h