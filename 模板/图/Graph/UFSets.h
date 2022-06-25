#pragma once
static const int DefaultSizeU = 10000;
class UFSets {	//�����еĸ����Ӽ��ϻ����ཻ
public:
    UFSets(int sz = DefaultSizeU);	//���캯��
    ~UFSets() { delete[]parent; }	//��������
    UFSets& operator = (UFSets& R);    //���ϸ�ֵ
    void Union(int Root1, int Root2);	     //�Ӽ��ϲ�
    int Find(int x);				//����x�ĸ�
    void WeightedUnion(int Root1, int Root2);
    //�Ľ�����:��Ȩ�ĺϲ��㷨
private:
    int* parent;		  //����Ԫ������(˫�ױ�ʾ)
    int size;			  //����Ԫ�ص���Ŀ
};


