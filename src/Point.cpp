//
// Created by xiangweilai on 2020/3/7.
//

#include "Point.h"
#include <cassert>

ll fastGcd(ll x, ll y) {
    if (x < y)
        return fastGcd(y, x);
    if (!y)
        return x;
    if ((x >> 1u) << 1u == x) {
        if ((y >> 1u) << 1u == y) return (fastGcd(x >> 1u, y >> 1u) << 1u);
        else return fastGcd(x >> 1u, y);
    } else {
        if ((y >> 1u) << 1u == y) return fastGcd(x, y >> 1u);
        else return fastGcd(y, x - y);
    }
}


void Coordinate::simplifyRational() {
    assert(isRational);

    // now bottom != 0
    // 6 / -4 --> -3 / 2
    if (bottom < 0) {
        top = -top;
        bottom = -bottom;
    }

    // now bottom > 0 ---> gcd != 0
    ll gcd = fastGcd(abs(bottom), abs(top));
    top /= gcd;
    bottom /= gcd;
}

void Coordinate::simplifySqrt(ll add, ll coeff, ll insqrt, ll btm) {
    ll tryRoot = sqrt(insqrt);
    if (tryRoot * tryRoot == insqrt) {  // actually a RATIONAL !
        isRational = true;
        top = add + coeff * tryRoot;
        bottom = btm;
        simplifyRational();
    }
}

Coordinate::Coordinate(ll tp, ll btm) : top(tp), bottom(btm), isNan(false), isRational(true), value(0) {
    if (btm == 0) {
        isNan = true;
        return;
    }
    simplifyRational();
}

Coordinate::Coordinate(ll a, ll b, ll c, ll btm) : top(0), bottom(0), isNan(false), isRational(false), value(0) {
    if (btm == 0) {
        isNan = true;
        return;
    } else
        value = (a + sqrt(c) * b) / btm;
    simplifySqrt(a, b, c, btm);
}

std::ostream &operator<<(std::ostream &os, const Coordinate &coordinate) {
    if (coordinate.isNan) {
        os << "nan";
        return os;
    }
    if (coordinate.isRational) {
        os << coordinate.top << " / " << coordinate.bottom;
        return os;
    } else {
        os << std::fixed << std::setprecision(8) << coordinate.value;
        return os;
    }
}


Point::Point(Coordinate xx, Coordinate yy) : x(xx), y(yy) {}

std::ostream &operator<<(std::ostream &os, const Point &point) {
    os << "(" << point.x << ", " << point.y << ")";
    return os;
}
