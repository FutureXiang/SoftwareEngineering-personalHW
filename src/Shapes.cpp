//
// Created by xiangweilai on 2020/3/9.
//

#include "Shapes.h"

Line::Line(int x1, int y1, int x2, int y2) : p1_x(x1), p1_y(y1), p2_x(x2), p2_y(y2) {}

Circle::Circle(int x, int y, int r) : center_x(x), center_y(y), radius(r) {}


std::vector<Point> intersection(Line a, Circle b) {
//    std::cout << "Line - Circle!\n";
    std::vector<Point> container;
    // https://mathworld.wolfram.com/Circle-LineIntersection.html
    int x1 = a.p1_x - b.center_x;
    int y1 = a.p1_y - b.center_y;
    int x2 = a.p2_x - b.center_x;
    int y2 = a.p2_y - b.center_y;
    ll dx = (ll)x2 - (ll)x1;
    ll dy = (ll)y2 - (ll)y1;
    ll dr2 = dx * dx + dy * dy;
    ll D = 1ll * x1 * y2 - 1ll * x2 * y1;
    ll D2 = D * D;
    ll delta = 1ll * b.radius * b.radius * dr2 - D2;
    if (delta < 0)
        return container;
    else if (delta == 0) {
        container.emplace_back(Coordinate(D * dy + b.center_x * dr2, dr2), Coordinate(-D * dx + b.center_y * dr2, dr2));
        return container;
    } else {
        ll coeff_xx = dx * ((dy >= 0) ? 1 : -1);
        ll coeff_yy = abs(dy);
        container.emplace_back(Coordinate(D * dy + b.center_x * dr2, coeff_xx, delta, dr2),
                               Coordinate(-D * dx + b.center_y * dr2, coeff_yy, delta, dr2));
        container.emplace_back(Coordinate(D * dy + b.center_x * dr2, -coeff_xx, delta, dr2),
                               Coordinate(-D * dx + b.center_y * dr2, -coeff_yy, delta, dr2));
        return container;
    }
}

std::vector<Point> intersection(Circle a, Line b) {
//    std::cout << "Circle - Line!\n";
    return intersection(b, a);
}

std::vector<Point> intersection(Line a, Line b) {
    std::vector<Point> container;
    // https://en.wikipedia.org/wiki/Line–line_intersection
//    std::cout << "Line - Line!\n";
    ll x1 = a.p1_x, y1 = a.p1_y;
    ll x2 = a.p2_x, y2 = a.p2_y;
    ll x3 = b.p1_x, y3 = b.p1_y;
    ll x4 = b.p2_x, y4 = b.p2_y;
    Coordinate xx((x1 * y2 - y1 * x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - y3 * x4),
                  (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4));
    Coordinate yy((x1 * y2 - y1 * x2) * (y3 - y4) - (y1 - y2) * (x3 * y4 - y3 * x4),
                  (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4));
    if (xx.isInf() || yy.isInf())
        return container;
    else {
        container.emplace_back(xx, yy);
        return container;
    }
}

std::vector<Point> intersection(Circle a, Circle b) {
    std::vector<Point> container;
//    std::cout << "Circle - Circle!\n";
    ll x1 = a.center_x, y1 = a.center_y, r1 = a.radius;
    ll x2 = b.center_x, y2 = b.center_y, r2 = b.radius;

    ll d2 = square(x1 - x2) + square(y1 - y2);
    if (d2 > square(r1 + r2) || d2 < square(r1 - r2))
        return container;
    if (d2 == square(r1 + r2) || d2 == square(r1 - r2)) {
        // x1 + (square(r1)-square(r2)+d2)/(2*d2) * (x2-x1);
        // y1 + (square(r1)-square(r2)+d2)/(2*d2) * (y2-y1);
        Coordinate x3((square(r1) - square(r2) + d2) * (x2 - x1) + 2 * d2 * x1, 2 * d2);
        Coordinate y3((square(r1) - square(r2) + d2) * (y2 - y1) + 2 * d2 * y1, 2 * d2);
        container.emplace_back(x3, y3);
        return container;
    } else {
        ll add_x3 = (square(r1) - square(r2) + d2) * (x2 - x1) + 2 * d2 * x1;
        ll add_y3 = (square(r1) - square(r2) + d2) * (y2 - y1) + 2 * d2 * y1;
        ll btm = 2 * d2;
        ll coeff_x3 = y2 - y1;
        ll coeff_y3 = x2 - x1;
        ll insqrt = 4 * square(r1) * d2 - square(square(r1) - square(r2) + d2);
        container.emplace_back(Coordinate(add_x3, +coeff_x3, insqrt, btm), Coordinate(add_y3, -coeff_y3, insqrt, btm));
        container.emplace_back(Coordinate(add_x3, -coeff_x3, insqrt, btm), Coordinate(add_y3, +coeff_y3, insqrt, btm));
        return container;
    }
}

ll square(ll x) {
    return x * x;
}
