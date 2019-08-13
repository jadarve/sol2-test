#ifndef SCRIPT_NODE_DESCRIPTOR_H_
#define SCRIPT_NODE_DESCRIPTOR_H_

#include <cstdint>

namespace script {

class Interpreter;


class NodeDescriptor {

public:
    void setWidth(const uint32_t width);
    uint32_t getWidth() const noexcept;

    void setHeight(const uint32_t height);
    uint32_t getHeight() const noexcept;

    static void registerTo(script::Interpreter& interpreter);

private:
    uint32_t m_height  {0};
    uint32_t m_width   {0};

};

} // namespace script

#endif // SCRIPT_NODE_DESCRIPTOR_H_
