//
// Created by xiangweilai on 2020/3/7.
//

#ifndef GEOMETRY_POINT_H
#define GEOMETRY_POINT_H

#include <cmath>
#include <ostream>
#include <iomanip>
#include <sstream>

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
    bool isNan;

    void simplifyRational();

    void simplifySqrt(ll add, ll coeff, ll insqrt, ll btm);

public:
    bool isRational;
    ll top, bottom;
    double value;

    Coordinate(ll tp, ll btm);  // simple A / B
    Coordinate(ll a, ll b, ll c, ll btm);  // ( a + b * sqrt(c) ) / btm, ---> (1) A/ B (2) double value
    Coordinate() = default;

    friend std::ostream &operator<<(std::ostream &os, const Coordinate &coordinate);

    bool isInf() const {
        return isNan;
    }

    std::size_t hashCode() const {
        if (isRational) {
            std::size_t h1 = std::hash<long long>{}(top);
            std::size_t h2 = std::hash<long long>{}(bottom);
            return ((h1 ^ (h2 << 1u)) << 1u) | 1u;
        } else {
            std::size_t h = std::hash<double>{}(value);
            return (h << 1u) | 0u;
        }
    }
};


class Point {
public:
    Coordinate x, y;

    Point(Coordinate xx, Coordinate yy);

    Point() = default;

    friend std::ostream &operator<<(std::ostream &os, const Point &point);
};

ll fastGcd(ll x, ll y);


// Hash Function For Point objects in support of unordered_map<Point>
struct hashCode_Point {
    std::size_t operator()(const Point &point) const {
        std::size_t h1 = point.x.hashCode();
        std::size_t h2 = point.y.hashCode();
        return h1 ^ (h2 << 1u);
    }
};

struct equals_Point {
    bool operator()(const Point &lhs, const Point &rhs) const {
        /* std::ostringstream outstream1, outstream2;
        outstream1 << lhs;
        outstream2 << rhs;
        return outstream1.str() == outstream2.str(); */
        bool x_eq = false, y_eq = false;
        if (lhs.x.isRational) {
            x_eq = (rhs.x.isRational & (lhs.x.top == rhs.x.top) & (lhs.x.bottom == rhs.x.bottom));
        } else {
            x_eq = ((!rhs.x.isRational) & ((long long)(lhs.x.value * 1e8) == (long long)(rhs.x.value * 1e8)));
        }
        if (lhs.y.isRational) {
            y_eq = (rhs.y.isRational & (lhs.y.top == rhs.y.top) & (lhs.y.bottom == rhs.y.bottom));
        } else {
            y_eq = ((!rhs.y.isRational) & ((long long)(lhs.y.value * 1e8) == (long long)(rhs.y.value * 1e8)));
        }
        return x_eq & y_eq;
    }
};


#endif //GEOMETRY_POINT_H
