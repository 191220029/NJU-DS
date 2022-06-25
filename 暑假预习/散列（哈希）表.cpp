//散列表（哈希表）查找
/**
在记录的存储位置和它的关键字之间建立一个确定的对应关系f，
使得每个关键字key对应一个存储位置f(key),这种对应关系f成为散列（哈希）函数
采用散列技术将记录存储在一块连续的空间中，这块连续的存储空间称为散列（哈希）表
*/



//好的散列函数=计算简单+分布均匀

//1.直接定址法
//f(key)=key
//f(key)=key-(const)x

//2.数字分析法 处理关键字位数比较大的情况 
/**
例如存储某公司员工手机号，抽取后四位数字作为散列地址是不错的选择 
手机号最后四位是用户编号，各不相同
*/

//3.平方取中法
//将关键字平方之后取中间若干位数字作为散列地址 关键字太大的话不太适合

//4.折叠法
//将关键字从左到右分隔成位数相等的几部分，然后将这几部分叠加求和，并按散列表表长取后几位作为散列地址

//5.除留余数法
//对于散列表长为m的散列函数计算公式为
//f(key)=key mod p ,(p<=m)
//p的选择是关键，避免发生冲突

//6.随机数法
//选择随机数作为关键字的随机函数值为它的散列地址。
//当关键字的长度不等时，采用这个方法构造散列函数是比较合适的。
//例如：f(key) = random(key)




/******************************************************************/
//处理冲突的办法
/**
开放地址法：
发生冲突就去找下一个散列地址，只要散列表足够大，那么该地址一定能够找到
fi(key)=(f(key)+di) MOD m (di=1,2,3,...,m-1)（线性探测法）

可以通过修改di的取值方式，例如使用平方运算来尽量解决堆积问题
fi(key)=(f(key)+di) MOD m (di=1,-1,2^2,-2^2,...,q^2,-q^2,q<=m/2)

也可以用随机探测法
fi(key) = (f(key)+di) MOD m (di是由随机函数获得的数列)

再散列函数法
fi(key) = RHi(key) (i=1,2,...) （用多个散列函数）

链地址法

公共溢出区法：再创建一个溢出表，进行存储
*/



//代码：
#define HASHSIZE 12
#define NULLKEY -32798
typedef strcut{
	int *elem; //数据元素的基址，动态分配数组
	int count; //当前数据元素的个数
}HashTable;

//初始化哈希表
int InitHashTable(HashTable *H){
	H->count = HASHSIZE;
	H->elem = (int*)malloc(HASHSIZE*sizeof(int));
	if(!H->elem){
		return -1;
	}
	for(int i = 0; i < HASHSIZE; i++){
		H->elem[i] = NULLKEY;
	}
	return 0;
}

//散列函数
//除留余数法
int Hash(int key){
	return key % HASHSIZE;
}

//插入关键字到散列表
void InsertHash(HashTable *H, int key){
	int addr;
	addr = Hash(key);
	while(H->elemp[addr]!=NULLKEY){//如果不为空则产生冲突
		//开放定址法：线形探测
		addr = (addr+1)%HASHSIZE;
	}
	H->elem[addr] = key;
}

//散列表查找关键字
int SearchHash(HashTable H, int key, int *addr){
	*addr = Hash(key);
	while(H.elem[*addr]!=key){
		//根据开放探测法的线性探测来找到要查找的元素
		*addr = (*addr+1)%HASHSIZE;
		if(H.elem[*addr]==NULLKEY || *addr == Hash(key)){//空元素或回到原来的位置则查找失败
			return -1;
		}
	}
	return 0;
}





