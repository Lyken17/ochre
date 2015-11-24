#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))

typedef glm::vec3 vec3;


struct sub
{
    //bound coordinate
    vec3 lfu, lfd, lbu, lbd, rfu, rfd, rbu, rbd;
    vec3 mid;
    vec3 bound[8];

    float length;
    //sub tree index
    int left_front_up, left_front_down, left_back_up, left_back_down;
    int right_front_up, right_front_down, right_back_up, right_back_down;
    int tree[8];

    bool divided;
    std::set<int> elements;

    sub() {
        left_front_up = left_front_down = left_back_up = left_back_down = 0;
        right_front_up = right_front_down = right_back_up = right_back_down = 0;

        length = 0;
        divided = false;

    }

    sub (vec3 start, vec3 end) {
        sub();

        for (size_t i = 0; i < 8; i++) {
            tree[i] = -1;
            bound[i] = vec3(0,0,0);
        }

        float xmax = MAX(start[0], end[0]);
        float ymax = MAX(start[1], end[1]);
        float zmax = MAX(start[2], end[2]);

        float xmin = MIN(start[0], end[0]);
        float ymin = MIN(start[1], end[1]);
        float zmin = MIN(start[2], end[2]);

        bound[0] = lbd = vec3(xmin, ymin, zmin);
        bound[1] = lfd = vec3(xmin, ymin, zmax);
        bound[2] = lbu = vec3(xmin, ymax, zmin);
        bound[3] = lfu = vec3(xmin, ymax, zmax);

        bound[4] = rbd = vec3(xmax, ymin, zmin);
        bound[5] = rfd = vec3(xmax, ymin, zmax);
        bound[6] = rbu = vec3(xmax, ymax, zmin);
        bound[7] = rfu = vec3(xmax, ymax, zmax);

        mid = lfu + rbd;
        mid /= 2;
        length = ymax - ymin;
    }


};

class octree
{
public:
    std::vector<sub> v;

    void insert(vec3 pos, int index);
    std::set<int> query(vec3 start, vec3 end);

    float node_size;
    octree() {
        node_size = 6;
        sub T(vec3(0, 0, 0), vec3(10 ,10 ,10 ));
        v.push_back(T);
    }

private:
    std::set<int> query(vec3 start, vec3 end, int id);
    void insert(vec3 pos, int index, int id);
};
