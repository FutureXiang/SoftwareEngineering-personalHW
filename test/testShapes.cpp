//
// Created by xiangweilai on 2020/3/10.
//

#include <iostream>
#include "gtest/gtest.h"
#include "Shapes.h"

TEST(IntersectionTest, line_line1) {
    // y = x & y = -x
    Line line1(-100000, -100000, 100000, 100000);
    Line line2(100000, -100000, -100000, 100000);
    auto result = intersection(line1, line2);
    EXPECT_EQ(result.size(), 1);
    Point point = result[0];
    std::ostringstream outstream;
    outstream << point;
    EXPECT_EQ(outstream.str(), "(0 / 1, 0 / 1)");
}

TEST(IntersectionTest, line_line2) {
    // y = x & y = -1.2x - 0.4
    Line line1(-100000, -100000, 100000, 100000);
    Line line2(-2, 2, 3, -4);
    auto result = intersection(line1, line2);
    EXPECT_EQ(result.size(), 1);
    Point point = result[0];
    std::ostringstream outstream;
    outstream << point;
    EXPECT_EQ(outstream.str(), "(-2 / 11, -2 / 11)");
}

TEST(IntersectionTest, line_line3) {
    // y = x & y = 1e5
    Line line1(-100000, -100000, 100000, 100000);
    Line line2(-100000, 100000, 100000, 100000);
    auto result = intersection(line1, line2);
    EXPECT_EQ(result.size(), 1);
    Point point = result[0];
    std::ostringstream outstream;
    outstream << point;
    EXPECT_EQ(outstream.str(), "(100000 / 1, 100000 / 1)");
}

TEST(IntersectionTest, line_line4) {
    // y = x & x = -1e5
    Line line1(-100000, -100000, 100000, 100000);
    Line line2(-100000, -100000, -100000, 100000);
    auto result = intersection(line1, line2);
    EXPECT_EQ(result.size(), 1);
    Point point = result[0];
    std::ostringstream outstream;
    outstream << point;
    EXPECT_EQ(outstream.str(), "(-100000 / 1, -100000 / 1)");
}

TEST(IntersectionTest, line_line5) {
    // y = 0 & x = -10
    Line line1(-1, 0, 0, 0);
    Line line2(-10, -5, -10, 5);
    auto result = intersection(line1, line2);
    EXPECT_EQ(result.size(), 1);
    Point point = result[0];
    std::ostringstream outstream;
    outstream << point;
    EXPECT_EQ(outstream.str(), "(-10 / 1, 0 / 1)");
}

TEST(IntersectionTest, line_line6) {
    // y = 2x & y = 2x + 1
    Line line1(-1, -2, 2, 4);
    Line line2(10, 21, 100, 201);
    auto result = intersection(line1, line2);
    EXPECT_EQ(result.size(), 0);
}

TEST(IntersectionTest, line_line7) {
    // y = 0 & y = -1
    Line line1(100, 0, -2, 0);
    Line line2(10, -1, 100, -1);
    auto result = intersection(line1, line2);
    EXPECT_EQ(result.size(), 0);
}

TEST(IntersectionTest, line_line8) {
    // x = 0 & x = -1
    Line line1(0, 0, 0, 1);
    Line line2(-1, 1, -1, -1);
    auto result = intersection(line1, line2);
    EXPECT_EQ(result.size(), 0);
}

TEST(IntersectionTest, line_line9) {
    // random test
    Line line1(237, -968, -326, -484);
    Line line2(-638, -352, 783, -776);
    auto result = intersection(line1, line2);
    EXPECT_EQ(result.size(), 1);
    Point point = result[0];
    std::ostringstream outstream;
    outstream << point;
    EXPECT_EQ(outstream.str(), "(-14792987 / 37421, -15881976 / 37421)");
}


std::string getOutput(Point x) {
    std::ostringstream outstream;
    outstream << x;
    return outstream.str();
}


TEST(IntersectionTest, line_circle1) {
    // x^2 + y^2 = 1 & x = 0
    Line line(0, -100000, 0, 100000);
    Circle circle(0, 0, 1);
    auto result = intersection(line, circle);
    EXPECT_EQ(result.size(), 2);
    EXPECT_EQ(getOutput(result[0]), "(0 / 1, 1 / 1)");
    EXPECT_EQ(getOutput(result[1]), "(0 / 1, -1 / 1)");
}

TEST(IntersectionTest, line_circle2) {
    // x^2 + y^2 = 1 & y = 0
    Line line(-100000, 0, 100000, 0);
    Circle circle(0, 0, 1);
    auto result = intersection(circle, line);
    EXPECT_EQ(result.size(), 2);
    EXPECT_EQ(getOutput(result[0]), "(1 / 1, 0 / 1)");
    EXPECT_EQ(getOutput(result[1]), "(-1 / 1, 0 / 1)");
}

TEST(IntersectionTest, line_circle3) {
    // x^2 + y^2 = 1 & y = x
    Line line(0, 0, 100000, 100000);
    Circle circle(0, 0, 1);
    auto result = intersection(line, circle);
    EXPECT_EQ(result.size(), 2);
    EXPECT_EQ(getOutput(result[0]), "(0.70710678, 0.70710678)");
    EXPECT_EQ(getOutput(result[1]), "(-0.70710678, -0.70710678)");
}

TEST(IntersectionTest, line_circle4) {
    // x^2 + y^2 = 1 & y = x + 1
    Line line(0, 1, 100000, 100001);
    Circle circle(0, 0, 1);
    auto result = intersection(circle, line);
    EXPECT_EQ(result.size(), 2);
    EXPECT_EQ(getOutput(result[0]), "(0 / 1, 1 / 1)");
    EXPECT_EQ(getOutput(result[1]), "(-1 / 1, 0 / 1)");
}

TEST(IntersectionTest, line_circle5) {
    // x^2 + y^2 = 1 & y = 2x - 1
    Line line(0, -1, 1, 1);
    Circle circle(0, 0, 1);
    auto result = intersection(line, circle);
    EXPECT_EQ(result.size(), 2);
    EXPECT_EQ(getOutput(result[0]), "(4 / 5, 3 / 5)");
    EXPECT_EQ(getOutput(result[1]), "(0 / 1, -1 / 1)");
}

TEST(IntersectionTest, line_circle6) {
    // x^2 + y^2 = 1 & y = 1
    Line line(0, 1, 1, 1);
    Circle circle(0, 0, 1);
    auto result = intersection(circle, line);
    EXPECT_EQ(result.size(), 1);
    EXPECT_EQ(getOutput(result[0]), "(0 / 1, 1 / 1)");
}

TEST(IntersectionTest, line_circle7) {
    // x^2 + y^2 = 1 & x = -1
    Line line(-1, 2, -1, 1);
    Circle circle(0, 0, 1);
    auto result = intersection(line, circle);
    EXPECT_EQ(result.size(), 1);
    EXPECT_EQ(getOutput(result[0]), "(-1 / 1, 0 / 1)");
}

TEST(IntersectionTest, line_circle8) {
    // random test
    Line line(-11, 6, -13, 1);
    Circle circle(-17, 4, 20);
    auto result = intersection(circle, line);
    EXPECT_EQ(result.size(), 2);
    EXPECT_EQ(getOutput(result[0]), "(-5.30910751, 20.22723121)");
    EXPECT_EQ(getOutput(result[1]), "(-19.72537524, -15.81343811)");
}

TEST(IntersectionTest, line_circle9) {
    // random test
    Line line(-11, 6, -13, 1);
    Circle circle(-17, 4, 4);
    auto result = intersection(circle, line);
    EXPECT_EQ(result.size(), 0);
}

// Generic Tangent Cases ???

TEST(IntersectionTest, circle_circle1) {
    // inner / outer
    Circle circle1(0, 0, 2);
    Circle circle2(0, 0, 1);
    auto result = intersection(circle1, circle2);
    EXPECT_EQ(result.size(), 0);
}

TEST(IntersectionTest, circle_circle2) {
    // inner / outer
    Circle circle1(0, 0, 3);
    Circle circle2(1, 1, 1);
    auto result = intersection(circle1, circle2);
    EXPECT_EQ(result.size(), 0);
}

TEST(IntersectionTest, circle_circle3) {
    // inner tangent
    Circle circle1(0, 0, 3);
    Circle circle2(0, 2, 1);
    auto result = intersection(circle1, circle2);
    EXPECT_EQ(result.size(), 1);
    EXPECT_EQ(getOutput(result[0]), "(0 / 1, 3 / 1)");
}

TEST(IntersectionTest, circle_circle4) {
    // outer tangent
    Circle circle1(0, 4, 3);
    Circle circle2(3, 0, 2);
    auto result = intersection(circle1, circle2);
    EXPECT_EQ(result.size(), 1);
    EXPECT_EQ(getOutput(result[0]), "(9 / 5, 8 / 5)");
}

TEST(IntersectionTest, circle_circle5) {
    // inter
    Circle circle1(0, 0, 5);
    Circle circle2(3, 2, 6);
    auto result = intersection(circle1, circle2);
    EXPECT_EQ(result.size(), 2);
    EXPECT_EQ(getOutput(result[0]), "(3 / 1, -4 / 1)");
    EXPECT_EQ(getOutput(result[1]), "(-33 / 13, 56 / 13)");
}

TEST(IntersectionTest, circle_circle6) {
    // random test
    Circle circle1(3, -5, 2);
    Circle circle2(-1, 1, 6);
    auto result = intersection(circle1, circle2);
    EXPECT_EQ(result.size(), 2);
    EXPECT_EQ(getOutput(result[0]), "(3.42988133, -3.04674578)");
    EXPECT_EQ(getOutput(result[1]), "(1.03165713, -4.64556191)");
}
