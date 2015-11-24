// GLM lib for matrix calculation
#include "include/glm/glm.hpp"
#include "include/glm/gtc/matrix_transform.hpp"
#include "include/glm/gtc/type_ptr.hpp"

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

#include "segtree.h"

typedef glm::vec3 vec3;
using namespace std;

void print(set<int> t) {
    for (auto it = t.begin() ; it != t.end() ; it++)
        cout << *it << " ";
    cout << endl;
}
int main(int argc, char const *argv[]) {

    typedef set<int> SI;
    segtree st;
    struct {
        float x,y,z;
        int id;
    } p;

    int id = 0;
    p.x = 1;
    p.y = 1;
    // for (p.x = 0; p.x <= 10; p.x += 3)
    //     for (p.y = 0; p.y <= 10; p.y += 3)

    for (p.x = 0; p.x < 10; p.x += 0.2){
		st.insert(vec3(p.x, p.y, p.z), id++);
        //cout << "id :" << id << " px " << p.x << endl;
	}

    st.query(vec3(0, 0, 0), vec3(5, 0, 0));
    // int count = 0;
    // for (auto i = st.v.begin() ; i != st.v.end() ; i++) {
    //     cout << "subtree: " << count++ << " :" << endl;
    //     for (size_t j = 0; j < 2; j++) {
    //         if (i->tree[j] != -1) {
    //             cout << "j : " << j <<" tree : " << i->tree[j] << endl;
    //         }
    //     }
    //     for (auto j = i->elements.begin() ; j != i->elements.end() ; j++) {
    //         cout << *j << " ";
    //     }
    //     cout << endl << "==========================" << endl;;
    // }

    return 0;
}
