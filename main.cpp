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

    typedef set<int> SI;
    octree st;
    struct {
        float x,y,z;
        int id;
    } p;

    int id = 1;
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
