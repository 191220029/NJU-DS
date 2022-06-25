/*
小蓝鲸的传送门

在二维空间里，小蓝鲸的坐标为(xMe,yMe)，小蓝鲸的寝室在(xHome,yHome)位置。每一秒钟小蓝鲸可以选择从你当前位置向上下左右四个方向之一移动一个单位。小蓝鲸想以最快的时间内回到寝室，在这片二维空间中，有n对传送门，每一对传送门以(xs,ys,xt,yt)的形式给出，表示你到达(xs,ys)点就可以发动“特殊”技能，花费10秒钟到达(xt,yt)点，相反你也可以花费10秒钟从(xt,yt)点发动“特殊”技能到达(xs,ys)点。技能可以无限多次发动，但只能在所给出的3对传送门之间使用。请问小蓝鲸回寝室最短用时多少秒。

输入格式

输入第一行N,表示有N对传送点(N<200) 接下来一行，依次是xMe、yMe、xHome、yHome，表示当前你的位置和你家的位置。

接下来N行，每行描述一对传送门(xs, ys, xt, yt)，含义见题面（0 <= xi, yi <= 10^9）

输出格式

输出仅一行，包含一个整数表示回家的最少用时

输入样例1
3
0 0 20 20
1 1 18 20
1000 1003 1000 1004
1000 1005 1000 1006

输出样例1
14

*/

/*

#include<iostream>
using namespace std;

const long long MAX_WEIGHT = 0x7fffffffffffffff;
const int size_path = 1000;
long long path[size_path][size_path];

long long _abs(long long x) {
    return x > 0 ? x : -x;
}

struct pos {
    long long x;
    long long y;
    bool operator==(pos P) {
        return this->x == P.x && this->y == P.y;
    }
    long long distance(pos P) {
        return _abs(this->x - P.x) + _abs(this->y - P.y);
    }
    pos() { x = 0, y = 0; }
    pos(long long a, long long b) {
        x = a, y = b;
    }
};

pos dots[size_path];

void init_path() {
    for (int i = 0; i < size_path; i++) {
        for (int j = 0; j < size_path; j++) {
            path[i][j] = (i == j) ? 0 : MAX_WEIGHT;
        }
    }
}


void solution_2() {
    int N; cin >> N;
    long long a, b;

    init_path();

    //get the start and end position
    cin >> a >> b;
    dots[0] = pos(a, b); //start
    cin >> a >> b;
    dots[1] = pos(a, b); //end
    //get trans doors

    int numDots = 2;
    for (int i = 0; i < N; i++) {
        long long sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        int flag1 = -1, flag2 = -1;
        for (int j = 0; j < numDots; j++) { //check input door if its start or end of old edges
            //if so, no need to store the point, otherwise store it
            if (flag1 < 0 && dots[j] == pos(sx, sy)) flag1 = j;
            if (flag2 < 0 && dots[j] == pos(ex, ey)) flag2 = j;
        }
        //store new dots
        if (flag1 < 0) {
            dots[numDots] = pos(sx, sy);
            flag1 = numDots; numDots++;
        }
        if (flag2 < 0) {
            dots[numDots] = pos(ex, ey);
            flag2 = numDots; numDots++;
        }
        //set weight of door's two dots
        path[flag1][flag2] = (path[flag1][flag2] < 10) ? path[flag1][flag2] : 10;
        path[flag2][flag1] = (path[flag1][flag2] < 10) ? path[flag1][flag2] : 10;
    }

    //find the shortest path
    //Floyd
    for (int i = 0; i < numDots; i++) {
        for (int j = 0; j < numDots; j++) {
            path[i][j] = (path[i][j] < dots[i].distance(dots[j])) ? path[i][j] : dots[i].distance(dots[j]);
        }
    }

    for (int k = 0; k < numDots; k++) {
        for (int i = 0; i < numDots; i++) {
            for (int j = 0; j < numDots; j++) {
                path[i][j] = (path[i][j] < path[i][k] + path[k][j]) ? path[i][j] : path[i][k] + path[k][j];
            }
        }
    }
    cout << path[0][1] << endl;



    return;
}

int main() {
    solution_2();
    return 0;
}
*/