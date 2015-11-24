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
    if (v[id].elements.size() > 1) {
        int s0 = pos[0] < v[id].mid[0] ? 0 : 1;
        int s1 = pos[1] < v[id].mid[1] ? 0 : 1;
        int s2 = pos[2] < v[id].mid[2] ? 0 : 1;

        int status = s0 * 4 + s1 * 2 + s2;

        if(v[id].tree[status] == 0) {
            v[id].tree[status] = v.size();
            v.push_back(sub(v[id].bound[status], v[id].mid));
        }

        // switch (status) {
        //     case 0: //x < mid.x && y < mid.y  && z < mid.z
        //         if (v[id].left_back_down == 0) {
        //             v[id].left_back_down = v.size();
        //             v.push_back(sub(v[id].lbd, v[id].mid));
        //         }
        //         octree::insert(pos, index, v[id].left_back_down);
        //         break;
        //     case 1: //x < mid.x && y < mid.y  && z >= mid.z
        //         if (v[id].left_front_down == 0) {
        //             v[id].left_front_down = v.size();
        //             v.push_back(sub(v[id].lfd, v[id].mid));
        //         }
        //         octree::insert(pos, index, v[id].left_front_down);
        //         break;
        //     case 2: //x < mid.x && y >= mid.y && z < mid.z
        //         if (v[id].left_back_up == 0) {
        //             v[id].left_back_up = v.size();
        //             v.push_back(sub(v[id].lbu, v[id].mid));
        //         }
        //         octree::insert(pos, index, v[id].left_back_up);
        //         break;
        //     case 3: //x < mid.x && y >= mid.y && z >= mid.z
        //         if (v[id].left_front_up == 0) {
        //             v[id].left_front_up = v.size();
        //             v.push_back(sub(v[id].lfu, v[id].mid));
        //         }
        //         octree::insert(pos, index, v[id].left_front_up);
        //         break;
        //     case 4: //x >= mid.x && y < mid.y && z < mid.z
        //         if (v[id].right_back_down == 0) {
        //             v[id].right_back_down = v.size();
        //             v.push_back(sub(v[id].rbd, v[id].mid));
        //         }
        //         octree::insert(pos, index, v[id].right_back_down);
        //         break;
        //     case 5: //x >= mid.x && y < mid.y && z >= mid.z
        //         if (v[id].right_front_down == 0) {
        //             v[id].right_front_down = v.size();
        //             v.push_back(sub(v[id].rfd, v[id].mid));
        //         }
        //         octree::insert(pos, index, v[id].right_front_down);
        //         break;
        //     case 6: //x >= mid.x && y >= mid.y && z < mid.z
        //         if (v[id].right_back_up == 0) {
        //             v[id].right_back_up = v.size();
        //             v.push_back(sub(v[id].rbu, v[id].mid));
        //         }
        //         octree::insert(pos, index, v[id].right_back_up);
        //         break;
        //     case 7:
        //         if (v[id].right_front_up == 0) {
        //             v[id].right_front_up = v.size();
        //             v.push_back(sub(v[id].rfu, v[id].mid));
        //         }
        //         octree::insert(pos, index, v[id].right_front_up);
        //         break;
        // }
        //
    }
}
