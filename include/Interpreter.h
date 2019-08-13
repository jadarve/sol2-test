#ifndef SCRIPT_INTERPRETER_H_
#define SCRIPT_INTERPRETER_H_

#include <string>

#define SOL_ALL_SAFETIES_ON 1
#include "sol/sol.hpp"

namespace script {

class Interpreter {

public:
    Interpreter();

    ~Interpreter() = default;

    template<typename T>
    void run(T&& code) {
        static_assert(std::is_convertible<T, std::string>::value, "typename T must be convertible to std::string");
        m_lua.script(code);
    }

    void runFile(const std::string& fileName);

    template<typename T, typename S>
    T get(S&& name) {
        static_assert(std::is_convertible<S, std::string>::value, "typename S must be convertible to std::string");

        return static_cast<T>(m_lua[name]);
    }

    sol::table& getNamespace() noexcept;

private:
    sol::state m_lua;
    sol::table m_namespace;
};

} // namespace script

#endif // SCRIPT_INTERPRETER_H_
