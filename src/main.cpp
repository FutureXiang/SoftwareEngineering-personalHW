#include <iostream>
#include <unordered_set>
#include "Shapes.h"

int main(int argc, char *argv[]) {
    // handle arguments & freopen
    for (int i = 0; i < argc; ++i) {
        if (strcmp(argv[i], "-i") == 0) {
            freopen(argv[i + 1], "r", stdin);
        }
        if (strcmp(argv[i], "-o") == 0) {
            freopen(argv[i + 1], "w", stdout);
        }
    }

    // main content
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
    std::unordered_set<Point, hashCode_Point, equals_Point> container;
    for (int i = 0; i < objCount; ++i) {
        for (int j = i + 1; j < objCount; ++j) {
            std::vector<Point> intersections = std::visit(interset_visitor{}, (*objs)[i], (*objs)[j]);
            for (Point p: intersections)
                container.insert(p);
        }
    }
    std::cout << container.size() << std::endl;
    return 0;
}
