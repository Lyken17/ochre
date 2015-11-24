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

    // octree t;
    //
    // for (size_t i = 0; i < 20; i++) {
    //     t.insert(vec3(i/2.0, i/2.0, i/2.0), i, 1);
    // }
    // int count = 0;
    // for (auto i = t.v.begin() ; i != t.v.end() ; i++) {
    //     cout << "line: " << count++ << " :";
    //     for (auto j = i->elements.begin() ; j != i->elements.end() ; j++) {
    //         cout << *j << " ";
    //     }
    //     cout << endl;
    // }
    typedef set<int> SI;
    octree st;
    struct {
        float x,y,z;
        int id;
    } p;
	SI s;

	// int result = xrange.intersect(Range(4, 4, 0));
    //
    // printf("result: %d\n", result);
	// assert(result == 0);
    int id = 0;
    p.x = 1;
    p.y = 1;

    for (p.z=1; p.z <= 10; p.z++){
		st.insert(vec3(p.x, p.y, p.z), id++, 0);
	}

    int count = 0;
    for (auto i = st.v.begin() ; i != st.v.end() ; i++) {
        cout << "line: " << count++ << " :";
        for (auto j = i->elements.begin() ; j != i->elements.end() ; j++) {
            cout << *j << " ";
        }
        cout << endl;
    }

    return 0;
}
