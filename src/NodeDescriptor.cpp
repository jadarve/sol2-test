#include "NodeDescriptor.h"
#include "Interpreter.h"

namespace script {

void NodeDescriptor::setWidth(const uint32_t width) {
    m_width = width;
}


uint32_t NodeDescriptor::getWidth() const noexcept {
    return m_width;
}


void NodeDescriptor::setHeight(const uint32_t height) {
    m_height = height;
}


uint32_t NodeDescriptor::getHeight() const noexcept {
    return m_height;
}


void NodeDescriptor::registerTo(script::Interpreter& interpreter) {

    auto& tableNamespace = interpreter.getNamespace();

    tableNamespace.new_usertype<script::NodeDescriptor>("NodeDescriptor",
        "width", sol::property(&NodeDescriptor::getWidth, &NodeDescriptor::setWidth),
        "height", sol::property(&NodeDescriptor::getHeight, &NodeDescriptor::setHeight));
}

} // namespace script
