#include "Interpreter.h"

namespace script {

Interpreter::Interpreter() {
    m_lua.open_libraries(sol::lib::base, sol::lib::math);
    m_namespace = m_lua["ll"].get_or_create<sol::table>();
}

void Interpreter::runFile(const std::string& fileName) {
    m_lua.script_file(fileName);
}

sol::table& Interpreter::getNamespace() noexcept {
    return m_namespace;
}



} // namespace script
