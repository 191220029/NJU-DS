#pragma once
template <class Name, class Attribute>
class Dictionary {
    //����: һ��<����-����>��, ����, ������Ψһ��
public:
    Dictionary(int size = DefaultSize);      //���캯��
    bool Member(Name name);
    //��name�Ƿ����ֵ���
    Attribute* Search(Name name);
    //���ֵ��������ؼ�����nameƥ��ı��� 
    void Insert(Name name, Attribute attr);
    //��name���ֵ���, ���޸���Ӧ<name, attr>��
    //��attr��; �������<name, attr>���ֵ���
    void Remove(Name name);
    //��name���ֵ���, �����ֵ���ɾ����Ӧ��
    //<name, attr>��
};

const int defaultSize = 50;
template <class K, class E>
class SortedList : public SeqList {
public:
    int Search(K k1) const;			     //����
    void Insert(const K k1, E& e1);	     //���룬
    bool Remove(const K k1, E& e1);	     //ɾ��
    int BinarySearch(K k1) const;
    int BinarySearch(K k1, const int low, const int high) const;

};

template <class K, class E>
int SortedList<K, E>::Search(K k1) const {
    //˳�������ؼ���Ϊk1�����ݶ���
    int n = last + 1;
    for (int i = 1; i <= n; i++)
        if (data[i - 1] == k1) return i;         //�ɹ�
        else if (data[i - 1] > k1) break;
    return 0;       //˳������ʧ��, ����ʧ����Ϣ
};

template<class K, class E>
int SortedList<K, E>::BinarySearch
(K k1, const int low, const int high) const {
    //�۰������ĵݹ��㷨���õ�E�����ز�����<���͡�>��
    int mid = 0;		        //Ԫ����Ŵ�0��ʼ
    if (low <= high) {
        mid = (low + high) / 2;
        if (data[mid] < k1)
            mid = BinarySearch(k1, mid + 1, high);
        else if (data[mid] > k1)
            mid = BinarySearch(k1, low, mid - 1);
        else return mid;
    }
    return 0;
};

template<class K, class E>
int SortedList <K, E>::BinarySearch(K k1) const {
    //�۰������ĵ����㷨���õ�K�����ز�����<���͡�>�� 
    int high = n - 1, low = 0, mid;    //Ԫ����Ŵ�0��ʼ	      
    while (low <= high) {
        mid = (low + high) / 2;
        if (data[mid] < k1) low = mid + 1;
        //������������	 
        else if (data[mid] > k1) high = mid - 1;
        //������������
        else return mid;                 //�����ɹ�
    }
    return 0;                                  //����ʧ��
}

