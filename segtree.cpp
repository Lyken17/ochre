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

set<int> merge(set<int> a0, set<int> a1, set<int> a2, set<int> a3, set<int> a4) {
    set<int> T;
    T.insert(a0.begin(), a0.end());
    T.insert(a1.begin(), a1.end());
    T.insert(a2.begin(), a2.end());
    T.insert(a3.begin(), a3.end());
    T.insert(a4.begin(), a4.end());
    return T;
}


set<int> segtree::query(vec3 start, vec3 end) {
    segtree::query(start[0], end[0], 0);
}

set<int> segtree::query(float start, float end, int id) {

}

void segtree::insert(vec3 pos, int index) {
    segtree::insert(pos[0], index, 0);
}

void segtree::insert(float pos, int index, int id) {

}
