/*
װ���±�
�����ϵ׼��ȥ�±��ӹ������������ϴ��һ���±�������ң�����Ҫ��׼��ѡ����ʼװ���ֻ������ʰȡ��������������ÿһ���±�ֱ��װ������������㹻�󣩡�
�������Ƶ�ÿ���±��϶�ӡ��1��СдӢ����ĸ��ϵ��ϣ���������±��У�����'n','j','u','c','s'������ĸ���±����ܹ���ż������0Ҳ��Ϊż������
���±���ӡ����ĸ��������±��������±��ӹ������������±��������ĸ�������һ��װ�������װ�±���������

�����ʽ
һ�����룬��һ����СдӢ����ĸ��ɵ��ַ��������������±�����ĸ����

�����ʽ
һ�������ֱ�����һ��װ�������װ�±���������

��������
jljjtmuvuqcwcrcjp
�������
13
����
����ʰȡ���±�Ϊ"ljjtmuvuqcwcr"������'j','u','c'��2����'n','s'��0����������һ��13���±���
*/

/*
/*
װ���±�
�����ϵ׼��ȥ�±��ӹ������������ϴ��һ���±�������ң�����Ҫ��׼��ѡ����ʼװ���ֻ������ʰȡ��������������ÿһ���±�ֱ��װ������������㹻�󣩡�
�������Ƶ�ÿ���±��϶�ӡ��1��СдӢ����ĸ��ϵ��ϣ���������±��У�����'n','j','u','c','s'������ĸ���±����ܹ���ż������0Ҳ��Ϊż������
���±���ӡ����ĸ��������±��������±��ӹ������������±��������ĸ�������һ��װ�������װ�±���������

�����ʽ
һ�����룬��һ����СдӢ����ĸ��ɵ��ַ��������������±�����ĸ����

�����ʽ
һ�������ֱ�����һ��װ�������װ�±���������

��������
jljjtmuvuqcwcrcjp
�������
13
����
����ʰȡ���±�Ϊ"ljjtmuvuqcwcr"������'j','u','c'��2����'n','s'��0����������һ��13���±���
*/


#include<iostream>
#include<string>
using namespace std;

#define MAX_INT 1e8

struct status { //��¼ÿ����ĸnjucs����ż״̬
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
    int fstStatus[32] = { 0 };//��¼ĳ״̬��32�֣���һ�γ��ֵ�λ��
    for (int i = 0; i < 32; i++)
        fstStatus[i] = MAX_INT;
    //printarray(fstStatus, 32);

    int dstStatus[32] = { 0 };//��¼ĳ״̬��������
    for (int i = 0; i < n; i++) {//��¼��i����ĸ��ǰ����ֵĴ�������ż״̬
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
        //����ĳ״̬��32�֣���һ�γ��ֵ�λ��
        fstStatus[q[i].snum()] = min(i, fstStatus[q[i].snum()]);
    }

    //for (int i = 0; i < n; i++) {
    //    q[i].show();
    //}
    //cout << endl;

    //�����������
    //���õ���ȫ0״̬��ô������ĸ������ȡ��



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
