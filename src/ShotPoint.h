#include "pugixml.hpp"
#include <string>
#include <stdlib.h>

using namespace std;

class ShotPoint {
public:
    bool float_src;
    double xs;
    double ys;
    double zs;

    ShotPoint(pugi::xml_node node);
};