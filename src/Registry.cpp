#include "Registry.h"

#include "NodeDescriptor.h"

namespace script {

Registry::Registry() :
    m_interpreter {std::make_unique<script::Interpreter>()} {

    script::NodeDescriptor::registerTo(*m_interpreter);
    script::Node::registerTo(*m_interpreter);
    m_interpreter->runFile("../lua/registry.lua");
}

void Registry::registerNode(const std::string& name, const std::string& luaCode) {

    m_interpreter->run(luaCode);
}


std::shared_ptr<script::Node> Registry::createNode(const std::string& name) {

    auto desc = script::NodeDescriptor {};

    auto node = std::make_shared<script::Node>(desc);
    // node->setFunctionName("mainC++");

    auto locals = m_interpreter->load(R"(
        local name, node = ...
        initNode(name, node)
    )");

    locals(name, node);
    // m_interpreter->run("initNode(name, node)");

    return node;
}

} // namespace script
