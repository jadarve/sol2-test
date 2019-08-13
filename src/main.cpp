#include <cstdlib>
#include <cstdint>
#include <iostream>
#include <string>
#include <type_traits>


#include "Interpreter.h"
#include "NodeDescriptor.h"
#include "Node.h"


int main(int argc, const char** argv) {

    auto interpreter = script::Interpreter {};

    // register types
    script::NodeDescriptor::registerTo(interpreter);
    script::Node::registerTo(interpreter);

    if (argc == 1) {
        std::cout << "Expecting LUA script file path";
        return EXIT_FAILURE;
    }

    interpreter.runFile(argv[1]);

    auto desc = interpreter.get<script::NodeDescriptor&>("desc");
    std::cout << "desc.getWidth()  : " << desc.getWidth() << std::endl;
    std::cout << "desc.getHeight() : " << desc.getHeight() << std::endl;

    auto& node = interpreter.get<script::Node&>("node");
    std::cout << "node.getFunctionName() : " << node.getFunctionName() << std::endl;

    return EXIT_SUCCESS;
}

