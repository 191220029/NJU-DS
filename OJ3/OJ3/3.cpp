/*
装箱月饼
计算机系准备去月饼加工厂的生产线上打包一箱月饼发给大家，工厂要求不准挑选，开始装箱后只能连续拾取生产线上运来的每一个月饼直到装箱结束（箱子足够大）。
工厂特制的每个月饼上都印有1个小写英文字母，系里希望在这箱月饼中，带有'n','j','u','c','s'五种字母的月饼都能够有偶数个（0也视为偶数）。
以月饼上印的字母代表这个月饼，给出月饼加工厂生产线上月饼制造的字母流，求解一次装箱最多能装月饼的数量。

输入格式
一行输入，以一个由小写英文字母组成的字符串代表工厂制造月饼的字母流。

输出格式
一行输出，直接输出一次装箱最多能装月饼的数量。

输入样例
jljjtmuvuqcwcrcjp
输出样例
13
解释
连续拾取的月饼为"ljjtmuvuqcwcr"，其中'j','u','c'各2个，'n','s'各0个，箱子里一共13个月饼。
*/

/*
/*
装箱月饼
计算机系准备去月饼加工厂的生产线上打包一箱月饼发给大家，工厂要求不准挑选，开始装箱后只能连续拾取生产线上运来的每一个月饼直到装箱结束（箱子足够大）。
工厂特制的每个月饼上都印有1个小写英文字母，系里希望在这箱月饼中，带有'n','j','u','c','s'五种字母的月饼都能够有偶数个（0也视为偶数）。
以月饼上印的字母代表这个月饼，给出月饼加工厂生产线上月饼制造的字母流，求解一次装箱最多能装月饼的数量。

输入格式
一行输入，以一个由小写英文字母组成的字符串代表工厂制造月饼的字母流。

输出格式
一行输出，直接输出一次装箱最多能装月饼的数量。

输入样例
jljjtmuvuqcwcrcjp
输出样例
13
解释
连续拾取的月饼为"ljjtmuvuqcwcr"，其中'j','u','c'各2个，'n','s'各0个，箱子里一共13个月饼。
*/


#include<iostream>
#include<string>
using namespace std;

#define MAX_INT 1e8

struct status { //记录每个字母njucs的奇偶状态
    bool s[5];
    int snum() {
        return (int)s[0] + (int)s[1] * 2 + (int)s[2] * 4 + (int)s[3] * 8 + (int)s[4] * 16;
    }
    status() {
        s[0] = s[1] = s[2] = s[3] = s[4] = 0;
    }
    void show() {
        cout << s[0] << s[1] << s[2] << s[3] << s[4] << endl;
    }
};


void printarray(int* a, int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;
}


void solution_3() {
    string s; cin >> s;
    int n = s.length();
    status* q = new status[s.length()];
    int fstStatus[32] = { 0 };//记录某状态（32种）第一次出现的位置
    for (int i = 0; i < 32; i++)
        fstStatus[i] = MAX_INT;
    //printarray(fstStatus, 32);

    int dstStatus[32] = { 0 };//记录某状态间的最长距离
    for (int i = 0; i < n; i++) {//记录第i个字母及前面出现的次数的奇偶状态
        if (i > 0) q[i] = q[i - 1];
        switch (s[i])
        {
        case 'n':
            q[i].s[0] = !q[i].s[0]; break;
        case 'j':
            q[i].s[1] = !q[i].s[1]; break;
        case 'u':
            q[i].s[2] = !q[i].s[2]; break;
        case 'c':
            q[i].s[3] = !q[i].s[3]; break;
        case 's':
            q[i].s[4] = !q[i].s[4]; break;
        default:
            break;
        }
        //更新某状态（32种）第一次出现的位置
        fstStatus[q[i].snum()] = min(i, fstStatus[q[i].snum()]);
    }

    //for (int i = 0; i < n; i++) {
    //    q[i].show();
    //}
    //cout << endl;

    //计算最长的序列
    //最后得到了全0状态那么所有字母都可以取下



    for (int i = n - 1; i >= 0; i--) {
        if (fstStatus[q[i].snum()] == 0 && q[i].snum() == 0)
            dstStatus[q[i].snum()] = max(dstStatus[q[i].snum()], i - fstStatus[q[i].snum()] + 1);
        else dstStatus[q[i].snum()] = max(dstStatus[q[i].snum()], i - fstStatus[q[i].snum()]);
        //dstStatus[q[i].snum()] = max(dstStatus[q[i].snum()], i - fstStatus[q[i].snum()]);
    }

    int res = 0;
    if (q[n - 1].snum() == 0) res = n;
    for (int i = 0; i < 32; i++) {
        res = max(res, dstStatus[i]);
    }
    cout << res;
    return;
}


int main() {
    solution_3();
    return 0;
}
