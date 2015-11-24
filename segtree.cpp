// GLM lib for matrix calculation
#include "include/glm/glm.hpp"
#include "include/glm/gtc/matrix_transform.hpp"
#include "include/glm/gtc/type_ptr.hpp"

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

#include "segtree.h"

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


set<int> segtree::query(vec3 start, vec3 end) {
    segtree::query(start[0], end[0], 0);
}

set<int> segtree::query(float start, float end, int id) {
    set<int> res;
    if ( id == -1 ) return res;
    if ( v[id].length < node_size ) return v[id].elements;

    float pp = 0.0001;
    float p = 0.00001;
    if ( v[id].bound[0] < start && v[id].bound[1] >= end)
        return merge (
                    segtree::query(start, v[id].mid - p, v[id].tree[0]),
                    segtree::query(v[id].mid,  end,  v[id].tree[1])
                );
    else if ( abs(v[id].bound[0] - start) < pp && abs(v[id].bound[1] - end) < pp)
        return v[id].elements;
}

void segtree::insert(vec3 pos, int index) {
    segtree::insert(pos[0], index, 0);
}

void segtree::insert(float pos, int index, int id) {

    v[id].elements.insert(index);
    if( v[id].length <= node_size ) return ;
    int status = pos < v[id].mid ? 0 : 1;

    if( v[id].tree[status] == -1 ) {
        v[id].tree[status] = v.size();
        sub T(v[id].bound[status], v[id].mid);
        //cout << "T length " << T.length << endl;
        v.push_back(T);
    }
    segtree::insert(pos, index, v[id].tree[status]);


}
