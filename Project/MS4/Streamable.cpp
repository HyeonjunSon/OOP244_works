
#include "Streamable.h"

using namespace std;

namespace seneca {
    std::ostream &operator<<(std::ostream &os, const Streamable& streamable) {
        if (!streamable)
            return os;
        return streamable.write(os);
    }
    std::istream &operator>>(std::istream &is, Streamable& streamable) {
        return streamable.read(is);
    }
}