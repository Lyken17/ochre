// GLM lib for matrix calculation
#include "include/glm/glm.hpp"
#include "include/glm/gtc/matrix_transform.hpp"
#include "include/glm/gtc/type_ptr.hpp"

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

#include "octree.h"

using namespace std;

set<int> query(vec3 start, vec3 end) {

}

void octree::insert(vec3 pos, int index, int id) {
    v[id].elements.insert(index);

    if ( v[id].length < 2 ) return;
    int s0 = pos[0] < v[id].mid[0] ? 0 : 1; //x
    int s1 = pos[1] < v[id].mid[1] ? 0 : 1; //y
    int s2 = pos[2] < v[id].mid[2] ? 0 : 1; //z

    int status = s0 * 4 + s2 * 2 + s1;

    if ( v[id].tree[status] == -1 ) {
        v[id].tree[status] = v.size();
        sub T(v[id].bound[status], v[id].mid);
        v.push_back(T);
    }
    octree::insert(pos ,index, v[id].tree[status]);


}
