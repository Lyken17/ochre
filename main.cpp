// GLM lib for matrix calculation
#include "include/glm/glm.hpp"
#include "include/glm/gtc/matrix_transform.hpp"
#include "include/glm/gtc/type_ptr.hpp"

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

#include "octree.h"

typedef glm::vec3 vec3;
using namespace std;

int main(int argc, char const *argv[]) {

    octree t;

    for (size_t i = 0; i < 20; i++) {
        t.insert(vec3(i/2.0, i/2.0, i/2.0), i, 1);
    }
    int count = 0;
    for (auto i = t.v.begin() ; i != t.v.end() ; i++) {
        cout << "line: " << count++ << " :";
        for (auto j = i->elements.begin() ; j != i->elements.end() ; j++) {
            cout << *j << " ";
        }
        cout << endl;
    }

    return 0;
}
