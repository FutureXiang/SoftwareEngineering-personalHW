//
// Created by xiangweilai on 2020/3/9.
//

#ifndef GEOMETRY_SHAPES_H
#define GEOMETRY_SHAPES_H

#include <variant>
#include <vector>
#include <iostream>
#include "Point.h"


class Line {
public:
    Line(int x1, int y1, int x2, int y2);

    int p1_x, p1_y;
    int p2_x, p2_y;
};


class Circle {
public:
    Circle(int x, int y, int r);

    int center_x, center_y;
    int radius;
};

std::vector<Point> intersection(Line x, Circle y);

std::vector<Point> intersection(Circle x, Line y);

std::vector<Point> intersection(Line x, Line y);

std::vector<Point> intersection(Circle x, Circle y);

ll square(ll x);

// variant for auto combination
using Geometry = std::variant<Line, Circle>;

struct interset_visitor {
    template<typename Shape1, typename Shape2>
    std::vector<Point> operator()(const Shape1 &lhs, const Shape2 &rhs) const {
        return intersection(lhs, rhs);
    }
};


#endif //GEOMETRY_SHAPES_H
