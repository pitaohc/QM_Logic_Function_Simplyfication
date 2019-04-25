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

│        │        |公有成员|

│        ├──`QM_CONSOLIDATION(int n);`

│        │        └──构造函数，并会按照参数 n 确定储存的位数

│        ├──`QM_CONSOLIDATION(int n, int finger);`

│        │        └──构造函数，按照参数 finger 确定储存的位数

│        ├──`~QM_CONSOLIDATION();`

│        │        └──析构函数

│        ├──`const vector<int>& PopNum();`

│        │        └──输出储存的序号数组（向量）

│        ├──`const vector<int>& PopBit();`

│        │        └──输出储存的二进制数组（向量）

│        ├──`int  PopIndex();`

│        │        └──输出 index 标识

│        ├──`void PushIndex(int num);`

│        │        └──输入 index 标识

│        ├──`bool Merge(QM_CONSOLIDATION& right);`

│        │        └──与另一个合并项合并，成功返回true，失败返回false

│        ├──`bool operator +=(QM_CONSOLIDATION& right);`

│        │        └──重载 += 操作符，与另一个合并项合并

│        ├──`bool operator ==(QM_CONSOLIDATION& right);`

│        │        ├──重载  == 操作符，与另一个合并项比较，相同返回false，

│        │        └── 不同返回false

│        ├──`friend ostream& operator <<(ostream& out, QM_CONSOLIDATION `│        │      `me);`

│        │        └──重载 ostream 中的 << 操作符，输出内容 

│        │        |私有成员|

│        ├──`int diff(QM_CONSOLIDATION& right);`

│        │        └──比较合并项，仅有一位不同时输出该位的位置，否则输出-1

│        ├──`void SetBit();`

│        ├──`int index=-1;`

│        ├──`int finger;`

│        ├──`vector<int> num;`

│        └──`vector<int> bit;`

└──`QMLOG`

         ├──`QMLOG(int arr[], int n);`

         ├──`QMLOG(vector<int>& vect);`

         ├──`QMLOG(QMLOG& copy);`

         ├──`QMLOG();`

         ├──`~QMLOG();`

         ├──`QMLOG& PutItem(vector<int>& Min_Item);`

         ├──`vector<int>& GetSinplest();`

         ├──`const int Size() ;`

         ├──`const vector<int>& PopMinItem() ;`

         ├──`const vector<QM_CONSOLIDATION>& PopConsolidationTable();`

         ├──`const vector<QM_CONSOLIDATION>& PopProductTable() ;`

         ├──`void operator =(QMLOG& copy);`

         ├──`friend ostream& operator <<(ostream& out,QMLOG me);`

         │

         ├──`void InitConList();`

         ├──`void Consolidation();`

         ├──`void InitProductTable();`

         ├──`void SelectLessItem();`

         ├──`void AddRemainItem();`

         ├──`int size;`

         ├──`vector<int> MinItem;`

         ├──`vector<int> ConMinItem;`

         ├──`vector<QM_CONSOLIDATION> ConsolidationTable;`

         ├──`vector<QM_CONSOLIDATION> ProductTable;`











```
└
```
