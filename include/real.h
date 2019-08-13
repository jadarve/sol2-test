#ifndef REAL_H_
#define REAL_H_

#include <map>
#include <memory>

namespace scripting {

class Descriptor;
class ComputeNode;

} // namespace scripting


namespace real {

class Descriptor {

}; // class A

class ComputeNode {

public:
    void bind(const std::string& name, const std::shared_ptr<real::Descriptor>& obj) {
        bindings[name] = obj;
    }

private:
    std::map<std::string, std::shared_ptr<real::Descriptor>> bindings;

}; // class B

} // namespace real

#endif // REAL_H_
