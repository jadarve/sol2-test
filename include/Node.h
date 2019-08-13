#ifndef SCRIPT_NODE_H_
#define SCRIPT_NODE_H_

#include "NodeDescriptor.h"

#include <string>

namespace script {

class Interpreter;


class Node {

public:
    Node() = delete;
    Node(const Node&) = delete;
    Node(Node&&) = delete;

    Node(const NodeDescriptor& descriptor);

    ~Node() = default;

    Node& operator = (const Node& node) = delete;
    Node& operator = (Node&& node)      = delete;

    static void registerTo(script::Interpreter& interpreter);

    void setFunctionName(const std::string& functionName);
    std::string getFunctionName() const noexcept;

private:
    script::NodeDescriptor m_descriptor;

    std::string m_functionName;

};

} // namespace script

#endif // SCRIPT_NODE_H_
