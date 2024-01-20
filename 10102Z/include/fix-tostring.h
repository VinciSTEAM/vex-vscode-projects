#ifndef _FIX_TO_STRING_H_
#define _FIX_TO_STRING_H_

#include <string>
#include <sstream>

namespace std {
    template<typename T>
    std::string to_string(T n) {
        std::ostringstream s;
        s << n;
        return s.str();
    }
};

#endif
