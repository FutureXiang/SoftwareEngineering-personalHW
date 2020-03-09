#include <iostream>
#include "Shapes.h"

int main() {
    int objCount;
    std::cin >> objCount;
    auto *objs = new std::vector<Geometry>();

    // temp vars for input
    char objType;
    int x1, y1, x2, y2;

    for (int i = 0; i < objCount; ++i) {
        std::cin >> objType;
        if (objType == 'L') {
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            objs->emplace_back(Line(x1, y1, x2, y2));
        } else if (objType == 'C') {
            scanf("%d%d%d", &x1, &y1, &x2);
            objs->emplace_back(Circle(x1, y1, x2));
        } else
            continue;
    }

    objCount = objs->size();
    for (int i = 0; i < objCount; ++i) {
        for (int j = i + 1; j < objCount; ++j) {
            std::vector<Point> intersections = std::visit(interset_visitor{}, (*objs)[i], (*objs)[j]);
            for (Point p: intersections)
                std::cout << p << std::endl;
        }
    }
    return 0;
}
