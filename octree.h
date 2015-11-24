#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))

typedef glm::vec3 vec3;


struct sub
{
    //bound coordinate
    vec3 lfu, lfd, lbu, lbd, rfu, rfd, rbu, rbd;
    vec3 mid;
    //sub tree index
    int left_front_up, left_front_down, left_back_up, left_back_down;
    int right_front_up, right_front_down, right_back_up, right_back_down;

    bool divided;
    std::set<int> elements;

    sub() {
        left_front_up = left_front_down = left_back_up = left_back_down = 0;
        right_front_up = right_front_down = right_back_up = right_back_down = 0;
        divided = false;
    }

    sub (vec3 start, vec3 end) {
        sub();
        float xmax = MAX(start[0], end[0]);
        float ymax = MAX(start[1], end[1]);
        float zmax = MAX(start[2], end[2]);

        float xmin = MIN(start[0], end[0]);
        float ymin = MIN(start[1], end[1]);
        float zmin = MIN(start[2], end[2]);

        lfu = vec3(xmin, ymax, zmax);
        lfd = vec3(xmin, ymin, zmax);
        lbu = vec3(xmin, ymax, zmin);
        lbd = vec3(xmin, ymin, zmin);

        rfu = vec3(xmax, ymax, zmax);
        rfd = vec3(xmax, ymin, zmax);
        rbu = vec3(xmax, ymax, zmin);
        rbd = vec3(xmax, ymin, zmin);

        mid = lfu + rbd;
        mid /= 2;
    }


};

class octree
{
public:
    std::vector<sub> v;
    std::set<int> query(vec3 start, vec3 end);
    void insert(vec3 pos, int index, int id);

    octree() {
        sub T;
        v.push_back(T);
        sub TT(vec3(0, 0, 0), vec3(10 ,10 ,10 ));
        v.push_back(T);
    }
};
