#include"UFSets.h"

UFSets::UFSets(int sz) {
    //���캯����sz �Ǽ���Ԫ�ظ�����˫������ķ�Χ
    //Ϊparent[0]��parent[size-1]��
    size = sz;			  //����Ԫ�ظ���
    parent = new int[size];  //����˫������
    for (int i = 0; i < size; i++) parent[i] = -1;
    //ÿ���Գɵ�Ԫ�ؼ���
};

int UFSets::Find(int x) {
    //�������������ذ���Ԫ��x�����ĸ���
    if (parent[x] < 0) return x;   //����parent[]ֵС��0  
    else return (Find(parent[x]));
};

void UFSets ::WeightedUnion(int Root1, int Root2) {
    //��Union�ļ�Ȩ����Ľ����㷨
    int temp = parent[Root1] + parent[Root2];
    if (parent[Root2] < parent[Root1]) {
        parent[Root1] = Root2;     //Root2�н������
        parent[Root2] = temp;      //Root1ָ��Root2
    }
    else {
        parent[Root2] = Root1;    //Root1�н������
        parent[Root1] = temp;      //Root2ָ��Root1
    }
};
