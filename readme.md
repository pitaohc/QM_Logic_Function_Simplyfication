<div>
<center>
<h1>
QM逻辑化简法更新文档
</h1>
</center>
</div>

# 流程

    1、将最小项转化成二进制编码表
    2、将二进制编码表写入合并表
    3、合并合并表
    4、如果无法继续合并则继续，否则返回step3
    5、通过列表法选择最小乘积项
    6、将剩余乘积项化简
    7、如果无法继续化简则继续，否则返回step6
    8、输出化简后的最小项

# CLASS声明

├──`QM_CONSOLIDATION（合并项）`

│        │        |**公有成员**|

│        ├──`QM_CONSOLIDATION(int n);`

│        │        └──构造函数，并会按照参数 **n** 确定储存的位数

│        ├──`QM_CONSOLIDATION(int n, int finger);`

│        │        └──构造函数，按照参数 **finger** 确定储存的位数

│        ├──`~QM_CONSOLIDATION();`

│        │        └──析构函数

│        ├──`const vector<int>& PopNum();`

│        │        └──输出储存的序号数组（向量）

│        ├──`const vector<int>& PopBit();`

│        │        └──输出储存的二进制数组（向量）

│        ├──`int  PopIndex();`

│        │        └──输出 **index** 标识

│        ├──`void PushIndex(int num);`

│        │        └──输入 **index** 标识

│        ├──`bool Merge(QM_CONSOLIDATION& right);`

│        │        └──与另一个合并项合并，成功返回**true**，失败返回**false**

│        ├──`bool operator +=(QM_CONSOLIDATION& right);`

│        │        └──重载 **+=** 操作符，与另一个合并项合并

│        ├──`bool operator ==(QM_CONSOLIDATION& right);`

│        │        ├──重载  **==** 操作符，与另一个合并项比较，相同返回**true**，

│        │        └── 不同返回**false**

│        ├──`friend ostream& operator <<(ostream& out, QM_CONSOLIDATION `│        │                `me);`

│        │        └──重载 ostream 中的 **<<** 操作符，输出内容 

│        │        |**私有成员**|

│        ├──`int diff(QM_CONSOLIDATION& right);`

│        │        └──比较合并项，仅有一位不同时输出该位的**位置**，否则输出**-1**

│        ├──`void SetBit();`

│        │        └──设置位向量

│        ├──`int index=-1;`

│        │        └──标识，默认值为**-1**，即没有标识

│        ├──`int finger;`

│        │        └──位数

│        ├──`vector<int> num;`

│        │        └──序号向量

│        └──`vector<int> bit;`

│                  └──位向量

└──`QMLOG`

|        ├──`QMLOG(int arr[], int n);`

│        |        └── 构造函数，传入c数组

|        ├──`QMLOG(vector<int>& vect);` 

│        |        └──构造函数，传入vector向量

|        ├──`QMLOG(QMLOG& copy);`

│        |        └──拷贝构造函数

|        ├──`QMLOG();`

│        |        └──默认空构造函数

│        ├──`~QMLOG();`

|        │        └──析构函数

|        ├──`QMLOG& PutItem(vector<int>& Min_Item);`

│        |        └──放入待化简最小项vector向量

|        ├──`vector<int>& GetSinplest();`

│        |        └──得到最简式

|        ├──`const int Size() ;`  

│        |        └──输出最小项数量

|        ├──`const vector<int>& PopMinItem() ;`   

│        |        └──输出最小项vector向量

|        ├──`const vector<QM_CONSOLIDATION>& PopConsolidationTable();`

│        |        └──输出合并表（合并项vector向量）

|        ├──`const vector<QM_CONSOLIDATION>& PopProductTable() ;`  

│        |        └──输出乘积表（合并项vector向量）

|        ├──`void operator = (QMLOG& copy);`   

│        |        └──重载  **=**  操作符，复制构造函数

|        ├──`friend ostream& operator <<(ostream& out,QMLOG me);`

│        |        └──重载 **<<** 操作符

|        ├──`void InitConList();`

│        |        └──初始化合并表

|        ├──`void Consolidation();`   

│        |        └──合并函数

|        ├──`void InitProductTable();`

│        |        └──初始化乘积表

|        ├──`void SelectLessItem();`

│        |        └──选择最少乘积项

|        ├──`void AddRemainItem();`

│        |        └──增加剩余项

|        ├──`int size;`

│        |        └──最小项数量

|        ├──`vector<int> MinItem;`

│        |        └──最小项vector

|        ├──`vector<int> ConMinItem;`

|        │        └──结果vector

|        ├──`vector<QM_CONSOLIDATION> ConsolidationTable;`

│        |        └──合并表

|        ├──`vector<QM_CONSOLIDATION> ProductTable;`

└───┴───┴──乘积表

# 2019年4月25日 更新

1、QMLOG对象初始化合并表函数

2、QMLOG对象中加入私有成员声明，储存字符串结果
