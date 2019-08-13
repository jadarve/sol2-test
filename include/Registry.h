#ifndef SCRIPT_REGISTRY_H_
#define SCRIPT_REGISTRY_H_

#include "Interpreter.h"
#include "Node.h"

#include <string>
#include <memory>

namespace script {

class Registry {

public:
    Registry();

    ~Registry() = default;

    void registerNode(const std::string& name, const std::string& luaCode);

    std::shared_ptr<script::Node> createNode(const std::string& name);

private:
    std::unique_ptr<script::Interpreter> m_interpreter;
};

} // namespace script

#endif // SCRIPT_REGISTRY_H_
