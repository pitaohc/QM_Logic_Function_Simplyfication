QM合并项

实现功能：

输入一个数字，让它变成合并项的模式

多个合并项之间可以比较

当合并项向量中无其他合并项可以和该合并项合并时，给予一个p标识



public:

1、QM_CONSOLIDATION(int n)

构造函数，动态位，根据给出的数字动态提供空间



2、QM_CONSOLIDATION(int n, int finger)

构造函数，固定位，按finger提供空间



3、~QM_CONSOLIDATION()

析构函数，暂无功能



4、PopNum()

返回num向量，返回类型为 const vector<int> &



5、PopBit()

返回bit向量，返回类型为 const vector<int> &



6、PopIndex()

返回p标识，类型为int



7、PushIndex(int num)

输入p标识



8、Merge(QM_CONSOLIDATION& right)

合并项合并函数，返回bool

false为不能合并

true为可以合并



9、operator +=(QM_CONSOLIDATION& right)

功能同Merge，重载了+=操作符



10、operator ==(QM_CONSOLIDATION& right)

比较两个合并项是否相等，重载==操作符



11、 operator <<(ostream& out, QM_CONSOLIDATION me)

打印输出函数



private:

1、diff(QM_CONSOLIDATION& right)

合并项比较函数

如果只有一位不同，就返回不同位的位置

如果 **多位不同**或**相同**则返回-1



2、SetBit()

设置位向量



3、int index = -1

p标识，默认值为-1



4、finger

位数



5、vector<int> num

序号向量（实际数字）



6、vector<int> bit 

位向量


