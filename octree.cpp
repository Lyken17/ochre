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
    // cout << pos[0] << endl;
    // cout << pos[1] << endl;
    // cout << pos[2] << endl;
    // cout << "id : " << id << " size : " << v[id].size << endl;
    v[id].elements.insert(index);
    cout << "elements" << endl;

    if (v[id].size <= 2.0) return;

    int s0 = pos[0] < v[id].mid[0] ? 0 : 1;
    int s1 = pos[1] < v[id].mid[1] ? 0 : 1;
    int s2 = pos[2] < v[id].mid[2] ? 0 : 1;


    int status = s0 * 4 + s1 * 2 + s2;
    cout << "status : " << status << endl;
    if(v[id].tree[status] == 0) {
        // cout << "parent " << id << " status " << status << endl;
        cout << "size " << v.size() << endl;
        v[id].tree[status] = v.size();
        sub T = sub(v[id].bound[status], v[id].mid);
        // cout << v[id].bound[status][0] << "  " << v[id].mid[0] << endl;
        // cout << v[id].bound[status][1] << "  " << v[id].mid[1] << endl;
        // cout << v[id].bound[status][2] << "  " << v[id].mid[2] << endl;
        v.push_back(T);
        cout << "push success" << endl;
    }
    //cout << "tree" << v[id].tree[status] << endl;
    //cout << "tree : " << v[id].tree[status] << endl;
    cout << "======================" << endl;
    octree::insert(pos, index, v[id].tree[status]);
}
