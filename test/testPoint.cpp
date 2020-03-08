//
// Created by xiangweilai on 2020/3/7.
//

#include <iostream>
#include "gtest/gtest.h"
#include "Point.h"

TEST(CoordinateTest, construct1) {
    Coordinate c(1, 2);
    std::ostringstream outstream;
    outstream << c;
    EXPECT_EQ(outstream.str(), "1 / 2");
}

TEST(CoordinateTest, construct2) {
    Coordinate c(1, 2, 3, 4);
    std::ostringstream outstream;
    outstream << c;
    EXPECT_EQ(outstream.str(), "1.11602540");
}

TEST(CoordinateTest, simplify1) {
    Coordinate c(1, 2, 9, 4);
    std::ostringstream outstream;
    outstream << c;
    EXPECT_EQ(outstream.str(), "7 / 4");
}

TEST(CoordinateTest, simplify2) {
    Coordinate c(1, -3, 9, 4);
    std::ostringstream outstream;
    outstream << c;
    EXPECT_EQ(outstream.str(), "-2 / 1");
}

TEST(CoordinateTest, simplify3) {
    Coordinate c(1, 2, 12, 4);
    std::ostringstream outstream;
    outstream << c;
    EXPECT_EQ(outstream.str(), "1.98205081");
}

TEST(CoordinateTest, simplify4) {
    Coordinate c(40000000000, 60000000000);
    std::ostringstream outstream;
    outstream << c;
    EXPECT_EQ(outstream.str(), "2 / 3");
}

TEST(CoordinateTest, simplify5) {
    Coordinate c(40000000000, -60000000000);
    std::ostringstream outstream;
    outstream << c;
    EXPECT_EQ(outstream.str(), "-2 / 3");
}

TEST(CoordinateTest, simplify6) {
    Coordinate c(-40000000000, -60000000000);
    std::ostringstream outstream;
    outstream << c;
    EXPECT_EQ(outstream.str(), "2 / 3");
}

TEST(CoordinateTest, simplify7) {
    Coordinate c(-40000000000, 60000000000);
    std::ostringstream outstream;
    outstream << c;
    EXPECT_EQ(outstream.str(), "-2 / 3");
}

TEST(CoordinateTest, simplify8) {
    Coordinate c(2, 3, 12, 4);
    std::ostringstream outstream;
    outstream << c;
    EXPECT_EQ(outstream.str(), "3.09807621");
}

TEST(CoordinateTest, simplify9) {
    Coordinate c(-2, -3, 12, -4);
    std::ostringstream outstream;
    outstream << c;
    EXPECT_EQ(outstream.str(), "3.09807621");
}

TEST(CoordinateTest, nan1) {
    Coordinate c(10000000000, 9999999999);
    std::ostringstream outstream;
    outstream << c;
    EXPECT_EQ(outstream.str(), "10000000000 / 9999999999");
}

TEST(CoordinateTest, nan2) {
    Coordinate c(-10000000000, 00000000);
    std::ostringstream outstream;
    outstream << c;
    EXPECT_EQ(outstream.str(), "nan");
}

TEST(CoordinateTest, nan3) {
    Coordinate c(1, -2, 3, 0);
    std::ostringstream outstream;
    outstream << c;
    EXPECT_EQ(outstream.str(), "nan");
}


TEST(PointTest, construct) {
    Coordinate x(6, 8);
    Coordinate y(1, -2, 3, -4);
    Point p(x, y);
    std::ostringstream outstream;
    outstream << p;
    EXPECT_EQ(outstream.str(), "(3 / 4, 0.61602540)");
}