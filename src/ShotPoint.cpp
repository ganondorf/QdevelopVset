#include "ShotPoint.h"
/*
 * Shotpoint:
 *   -Stores a single shotpoint (one <sp> from the XML file)
 *
 */
ShotPoint::ShotPoint(pugi::xml_node node) {
    float_src = node.child_value("floatsrc");
    string opt = "";
    if(float_src) { opt = "f"; }
    xs        =(double) atof(node.child_value(string(opt + "xs").c_str()));
    ys        =(double) atof(node.child_value(string(opt + "ys").c_str()));
    zs        = (double)atof(node.child_value(string(opt + "zs").c_str()));
}