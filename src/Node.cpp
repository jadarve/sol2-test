#include "Node.h"
#include "NodeDescriptor.h"
#include "Interpreter.h"

#include <iostream>

namespace script {

void Node::registerTo(script::Interpreter& interpreter) {

    auto& tableNamespace = interpreter.getNamespace();

    tableNamespace.new_usertype<script::Node>("Node",
        sol::constructors<script::Node(const script::NodeDescriptor&)>(),
        "functionName", sol::property(&Node::getFunctionName, &Node::setFunctionName),
        "width", sol::property(&Node::getWidth, &Node::setWidth),
        "height", sol::property(&Node::getHeight, &Node::setHeight));
}

Node::Node(const NodeDescriptor& descriptor) :
    m_descriptor {descriptor} {
}

void Node::setFunctionName(const std::string& functionName) {
    m_functionName = functionName;

    std::cout << "Node::setFunctionName() : " << m_functionName
              << " [" << m_descriptor.getHeight() << ", " << m_descriptor.getWidth() << "]" <<std::endl;
}

std::string Node::getFunctionName() const noexcept {
    return m_functionName;
}


void Node::setWidth(const uint32_t width) {
    m_descriptor.setWidth(width);
}


uint32_t Node::getWidth() const noexcept {
    return m_descriptor.getWidth();
}


void Node::setHeight(const uint32_t height) {
    m_descriptor.setHeight(height);
}


uint32_t Node::getHeight() const noexcept {
    return m_descriptor.getHeight();
}


void Node::onInit() {

    // call interpreter here!
}

} // namespace script
