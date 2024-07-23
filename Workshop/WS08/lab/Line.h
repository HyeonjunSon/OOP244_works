#ifndef WS08_LINE_H
#define WS08_LINE_H

#include "LblShape.h"

namespace seneca {
    class Line : public LblShape {
        int m_length;
    public:
        Line();
        Line(const char* label, int length);
        void getSpecs(std::istream& is) override;
        void draw(std::ostream& os) const override;
    };
}


#endif //WS08_LINE_H