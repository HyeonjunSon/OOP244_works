#include "Shape.h"

namespace seneca {
    std::ostream& operator<<(std::ostream &os, Shape& shape) {
        shape.draw(os);
        return os;
    }
    std::istream& operator>>(std::istream &is, Shape& shape) {
        shape.getSpecs(is);
        return is;
    }
}