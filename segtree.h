#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))

typedef glm::vec3 vec3;

struct sub
{
    //bound coordinate
    float left, right, mid;
    //sub tree index
    int l_sub, r_sub;
    
    std::set<int> elements;
    float length;

    sub() {
        l_sub = r_sub = -1;
        length = 0;
    }

    sub (float start, float end) {
        sub();
        left = start;
        right = end;
        mid = left + right;
        length = right - left;
    }
};

class segtree
{
public:
    std::vector<sub> v;

    void insert(vec3 pos, int index);
    std::set<int> query(vec3 start, vec3 end);

    float node_size;
    segtree() {
        node_size = 0.5;
        sub T(0, 10);
        v.push_back(T);
    }

private:
    std::set<int> query(float start, float end, int id);
    void insert(float pos, int index, int id);
};
