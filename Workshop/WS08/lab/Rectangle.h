#ifndef WS08_RECTANGLE_H
#define WS08_RECTANGLE_H

#include <cstring>
#include "Line.h"

namespace seneca {
    class Rectangle : public LblShape {
        int m_width;
        int m_height;
    public:
        Rectangle();
        Rectangle(const char* label, int width, int height);
        void getSpecs(std::istream& is) override;
        void draw(std::ostream& os) const override;
    };
}


#endif //WS08_RECTANGLE_H