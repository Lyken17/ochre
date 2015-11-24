#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))

typedef glm::vec3 vec3;

struct sub
{
    //bound coordinate
    float left, right, mid;
    float bound[2];

    //sub tree index
    int l_sub, r_sub;
    int tree[2];

    std::set<int> elements;
    float length;

    sub() {
        l_sub = r_sub = -1;
        length = 0;
    }

    sub (float start, float end) {
        sub();

        if (start > end) {
            float temp = start;
            start = end;
            end = start;
        }

        tree[0] = l_sub = - 1;
        tree[1] = r_sub = -1;

        bound[0] = left = start;
        bound[1] = right = end;

        mid = (left + right) / 2;
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
        node_size = 2;
        sub T(0, 10);
        v.push_back(T);
    }

private:
    std::set<int> query(float start, float end, int id);
    void insert(float pos, int index, int id);
};
