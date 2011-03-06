// src/exception.hpp
//
//

#ifndef URPC_EXCEPTION_HPP
#define URPC_EXCEPTION_HPP

#include <stdexcept>

namespace urpc {

class GlobError : public std::runtime_error {
 public:
  explicit GlobError (const std::string& what)
      : std::runtime_error (what) {}
};

}

#endif // URPC_EXCEPTION_HPP
