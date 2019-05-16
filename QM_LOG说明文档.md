QMLOG类

public：

1、构造函数

QMLOG(int arr[], int n)

用c数组构造，给出数组与长度

QMLOG(vector<int>& vect)

用向量构造

QMLOG(QMLOG& copy)

拷贝构造

QMLOG()

默认构造



2、~QMLOG()

析构函数，暂无功能



3、PutItem(vector<int>& Min_Item)

放入最小项数组



4、GetSinplest()

处理最小项数组得出最简式



5、变量输出函数

Size()

输出最小项个数 返回const int

PopMinItem()

输出最小项向量，返回const vector<int>&

PopConsolidationTable()

输出合并表

const vector<QM_CONSOLIDATION>&

PopProductTable()

输出乘积表，const vector<QM_CONSOLIDATION>&



6、操作符重载函数

operator =(QMLOG& copy)

拷贝构造函数

operator <<(ostream& out,QMLOG me)

打印输出函数



private:

InitConList()

初始化合并表 ,得出位数和设置consolidation_table
Consolidation()

合并式子,合并consolidation_table
InitProductTable()

初始化乘积表,Product_Table
SelectLessItem()

列表法选择最少乘积项
AddRemainItem()

增加剩余项




