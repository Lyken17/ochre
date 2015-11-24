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

set<int> merge(set<int> a0, set<int> a1) {
    set<int> T;
    T.insert(a0.begin(), a0.end());
    T.insert(a1.begin(), a1.end());
    return T;
}

set<int> merge(set<int> a0, set<int> a1, set<int> a2) {
    set<int> T;
    T.insert(a0.begin(), a0.end());
    T.insert(a1.begin(), a1.end());
    T.insert(a2.begin(), a2.end());
    return T;
}

set<int> merge(set<int> a0, set<int> a1, set<int> a2, set<int> a3) {
    set<int> T;
    T.insert(a0.begin(), a0.end());
    T.insert(a1.begin(), a1.end());
    T.insert(a2.begin(), a2.end());
    T.insert(a3.begin(), a3.end());
    return T;
}

set<int> merge(set<int> a0, set<int> a1, set<int> a2, set<int> a3, set<int> a4) {
    set<int> T;
    T.insert(a0.begin(), a0.end());
    T.insert(a1.begin(), a1.end());
    T.insert(a2.begin(), a2.end());
    T.insert(a3.begin(), a3.end());
    T.insert(a4.begin(), a4.end());
    return T;
}


set<int> octree::query(vec3 start, vec3 end) {
    octree::query(start, end, 0);
}

set<int> octree::query(vec3 start, vec3 end, int id) {
    set<int> res;
    if ( id == -1 ) return res;
    if ( v[id].length < node_size) return v[id].elements;

    vec3 min_point(MIN(start[0], end[0]),MIN(start[1], end[1]),MIN(start[2], end[2]));
    vec3 max_point(MAX(start[0], end[0]),MAX(start[1], end[1]),MAX(start[2], end[2]));

    start = min_point;
    end   = max_point;

    int a0 = start[0] < v[id].mid[0] ? 0 : 1; //x
    int a1 = start[1] < v[id].mid[1] ? 0 : 1; //y
    int a2 = start[2] < v[id].mid[2] ? 0 : 1; //z

    int b0 = end[0] < v[id].mid[0] ? 0 : 1; //x
    int b1 = end[1] < v[id].mid[1] ? 0 : 1; //y
    int b2 = end[2] < v[id].mid[2] ? 0 : 1; //z

    int s1 = a0 * 4 + a1 * 2 + a2;
    int s2 = b0 * 4 + b1 * 2 + b2;
    int situtaion = a0 ^ b0 + a1 ^ b1 + a2 ^ b2;

    float precision = 0.00001;
    vec3 p(precision, precision, precision);
    vec3 px(precision , 0, 0);
    vec3 py(0 , precision, 0);
    vec3 pz(0 , 0, precision);

    switch (situtaion) {
        case 0:
            return octree::query(start, end, v[id].tree[s1]);
            break;
        case 1:
            return res;
            break;
        case 2:
            return res;
            break;
        case 3:
            return merge(
                        merge(
                            octree::query(v[id].bound[0], v[id].mid, v[id].tree[0]),
                            octree::query(v[id].bound[1], v[id].mid, v[id].tree[1]),
                            octree::query(v[id].bound[2], v[id].mid, v[id].tree[2]),
                            octree::query(v[id].bound[3], v[id].mid, v[id].tree[3])
                        ),
                        merge(
                            octree::query(v[id].bound[4], v[id].mid, v[id].tree[4]),
                            octree::query(v[id].bound[5], v[id].mid, v[id].tree[5]),
                            octree::query(v[id].bound[6], v[id].mid, v[id].tree[6]),
                            octree::query(v[id].bound[7], v[id].mid , v[id].tree[7])
                        )
                    )
                    ;
            break;
    }
}

void octree::insert(vec3 pos, int index) {
    octree::insert(pos, index, 0);
}

void octree::insert(vec3 pos, int index, int id) {
    v[id].elements.insert(index);

    if ( v[id].length < node_size ) return;
    int s0 = pos[0] < v[id].mid[0] ? 0 : 1; //x
    int s1 = pos[1] < v[id].mid[1] ? 0 : 1; //y
    int s2 = pos[2] < v[id].mid[2] ? 0 : 1; //z

    int status = s0 * 4 + s1 * 2 + s2;

    if ( v[id].tree[status] == -1 ) {
        v[id].tree[status] = v.size();
        sub T(v[id].bound[status], v[id].mid);
        v.push_back(T);
    }
    octree::insert(pos ,index, v[id].tree[status]);


}
