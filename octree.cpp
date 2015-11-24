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
        if (!v[id].divided) {
            v[id].left_front_up = v.size();
            v.push_back(sub(v[id].lfu, v[id].mid));
            v[id].left_front_down = v.size();
            v.push_back(sub(v[id].lfd, v[id].mid));
            v[id].left_back_up = v.size();
            v.push_back(sub(v[id].lbu, v[id].mid));
            v[id].left_back_down = v.size();
            v.push_back(sub(v[id].lbd, v[id].mid));

            v[id].right_front_up = v.size();
            v.push_back(sub(v[id].rfu, v[id].mid));
            v[id].right_front_down = v.size();
            v.push_back(sub(v[id].rfd, v[id].mid));
            v[id].right_back_up = v.size();
            v.push_back(sub(v[id].rbu, v[id].mid));
            v[id].right_back_down = v.size();
            v.push_back(sub(v[id].rbd, v[id].mid));
        }


        if(pos[0] < v[id].mid[0]) { //x < mid.x
            if (pos[1] < v[id].mid[1]) { //y < mid.y
                if (pos[2] < v[id].mid[2]) { //z < mid.z
                    octree::insert(pos, index, v[id].left_back_down);
                }
                else {
                    octree::insert(pos, index, v[id].left_front_down);
                }
            }
            else { //y >= mid.y
                if (pos[2] < v[id].mid[2]) { //z < mid.z
                    octree::insert(pos, index, v[id].left_back_up);
                }
                else {
                    octree::insert(pos, index, v[id].left_front_up);
                }
            }
        }
        else { //x >= mid.x
            if (pos[1] < v[id].mid[1]) { //y < mid.y
                if (pos[2] < v[id].mid[2]) { //z < mid.z
                    octree::insert(pos, index, v[id].right_back_down);
                }
                else {
                    octree::insert(pos, index, v[id].right_front_down);
                }
            }
            else { //y >= mid.y
                if (pos[2] < v[id].mid[2]) { //z < mid.z
                    octree::insert(pos, index, v[id].right_back_up);
                }
                else {
                    octree::insert(pos, index, v[id].right_front_up);
                }
            }
        }

    }
}
