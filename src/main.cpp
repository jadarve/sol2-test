#include <cstdlib>
#include <cstdint>
#include <iostream>
#include <string>
#include <type_traits>


#include "Interpreter.h"
#include "NodeDescriptor.h"
#include "Node.h"
#include "Registry.h"


int main(int argc, const char** argv) {

    auto interpreter = script::Interpreter {};

    // register types
    script::NodeDescriptor::registerTo(interpreter);
    script::Node::registerTo(interpreter);

    // if (argc == 1) {
    //     std::cout << "Expecting LUA script file path";
    //     return EXIT_FAILURE;
    // }

    // interpreter.runFile(argv[1]);

    // auto desc = interpreter.get<script::NodeDescriptor&>("desc");
    // std::cout << "desc.getWidth()  : " << desc.getWidth() << std::endl;
    // std::cout << "desc.getHeight() : " << desc.getHeight() << std::endl;

    // auto& node = interpreter.get<script::Node&>("node");
    // std::cout << "node.getFunctionName() : " << node.getFunctionName() << std::endl;
    
    auto registry = script::Registry {};
    registry.registerNode("RGBA2gray",
        R"(
        RGBA2gray = class(LuaNode)
        function RGBA2gray:onInit(node)
            node.functionName = 'RGBA2gray_main'
            node.width = 1024
            node.height = 768
        end

        -- register the class
        registerNode('RGBA2gray', RGBA2gray)
        )");

    registry.registerNode("RGBA2HSVA",
        R"(
        RGBA2HSVA = class(LuaNode)
        function RGBA2HSVA:onInit(node)
            node.functionName = 'RGBA2HSVA_main'
            node.width = 640
            node.height = 480
        end

        -- register the class
        registerNode('RGBA2HSVA', RGBA2HSVA)
        )");


    auto nodeRGBA = registry.createNode("RGBA2gray");
    auto nodeHSVA = registry.createNode("RGBA2HSVA");

    std::cout << "FROM C++" << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    std::cout << nodeRGBA->getFunctionName() << std::endl;
    std::cout << nodeRGBA->getHeight() << std::endl;
    std::cout << nodeRGBA->getWidth() << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    std::cout << nodeHSVA->getFunctionName() << std::endl;
    std::cout << nodeHSVA->getHeight() << std::endl;
    std::cout << nodeHSVA->getWidth() << std::endl;

    return EXIT_SUCCESS;
}

