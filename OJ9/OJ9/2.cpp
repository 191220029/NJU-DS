/*
С�����Ĵ�����

�ڶ�ά�ռ��С����������Ϊ(xMe,yMe)��С������������(xHome,yHome)λ�á�ÿһ����С��������ѡ����㵱ǰλ�������������ĸ�����֮һ�ƶ�һ����λ��С������������ʱ���ڻص����ң�����Ƭ��ά�ռ��У���n�Դ����ţ�ÿһ�Դ�������(xs,ys,xt,yt)����ʽ��������ʾ�㵽��(xs,ys)��Ϳ��Է��������⡱���ܣ�����10���ӵ���(xt,yt)�㣬�෴��Ҳ���Ի���10���Ӵ�(xt,yt)�㷢�������⡱���ܵ���(xs,ys)�㡣���ܿ������޶�η�������ֻ������������3�Դ�����֮��ʹ�á�����С���������������ʱ�����롣

�����ʽ

�����һ��N,��ʾ��N�Դ��͵�(N<200) ������һ�У�������xMe��yMe��xHome��yHome����ʾ��ǰ���λ�ú���ҵ�λ�á�

������N�У�ÿ������һ�Դ�����(xs, ys, xt, yt)����������棨0 <= xi, yi <= 10^9��

�����ʽ

�����һ�У�����һ��������ʾ�ؼҵ�������ʱ

��������1
3
0 0 20 20
1 1 18 20
1000 1003 1000 1004
1000 1005 1000 1006

�������1
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