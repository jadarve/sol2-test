#ifndef SCRIPTING_H_
#define SCRIPTING_H_

#include <cstdint>
#include <string>

#define SOL_ALL_SAFETIES_ON 1
#include "sol/sol.hpp"

namespace scripting {

class Descriptor {

public:
    Descriptor& setWidth(const uint32_t width);
    Descriptor& setFunctionName(const std::string& functionName);

    uint32_t getWidth() const noexcept;
    const std::string& getFunctionName() const noexcept;

    static void registerTo(sol::table& tableNamespace);

private:
    uint32_t m_width;
    std::string m_functionName;

}; // class A


class Node {

}; // class B

} // namespace scripting

#endif
