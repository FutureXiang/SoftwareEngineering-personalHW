//
// Created by xiangweilai on 2020/3/7.
//

#ifndef GEOMETRY_POINT_H
#define GEOMETRY_POINT_H

#include <cmath>
#include <ostream>
#include <iomanip>

typedef long long ll;

class Coordinate {
    // Case 1: Rational Number = A / B (long-longs)
    // Case 2: Float Number = C (double)

    // Line-Line intersections: coordinate range = (-4e10, 4e10)
    // DOUBLE IS NOT ENOUGH ! (41234567890.12345xxx...)
    // use rational

    // Line-Circle / Circle-Circle intersections: coordinate range = (-2e5, 2e5)
    // DOUBLE IS ENOUGH ! (212345.1234567890xxx...)

    // use rational (if a square number) / double (if not)
private:
    bool isRational;
    bool isNan;

    void simplifyRational();

    void simplifySqrt(ll add, ll coeff, ll insqrt, ll btm);

public:
    ll top, bottom;
    double value;

    Coordinate(ll tp, ll btm);  // simple A / B
    Coordinate(ll a, ll b, ll c, ll btm);  // ( a + b * sqrt(c) ) / btm, ---> (1) A/ B (2) double value
    Coordinate() = default;

    friend std::ostream &operator<<(std::ostream &os, const Coordinate &coordinate);

    bool isInf() const {
        return isNan;
    }
};


class Point {
private:
    Coordinate x, y;
public:
    Point(Coordinate xx, Coordinate yy);

    Point() = default;

    friend std::ostream &operator<<(std::ostream &os, const Point &point);
};

ll fastGcd(ll x, ll y);

#endif //GEOMETRY_POINT_H
