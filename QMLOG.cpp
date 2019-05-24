#include "QMLOG.h"

//数组构造函数
QMLOG::QMLOG(int arr[], int n)
{
	vector<int> temp(arr, arr + n);
	PutItem(temp);
}

//向量构造函数
QMLOG::QMLOG(vector<int> & vect)
{
	PutItem(vect);
}

//拷贝构造函数
QMLOG::QMLOG(QMLOG & copy)
{
	size = copy.Size();
	complete = copy.Complete();
	MinItem = copy.PopMinItem();
	ConMinItem = copy.GetSinplest();
	ConsolidationTable = copy.PopConsolidationTable();
	ProductTable = copy.PopProductTable();
}

//默认构造函数
QMLOG::QMLOG() :size(0) {}
//析构函数
QMLOG::~QMLOG() {}

//操作符=重载
void QMLOG::operator=(QMLOG& copy)
{
	size = copy.Size();
	MinItem = copy.PopMinItem();
	ConsolidationTable = copy.PopConsolidationTable();
	ProductTable = copy.PopProductTable();

}

//初始化合成表
void QMLOG::InitConList()
{
	int max = *(MinItem.end() - 1);
	int finger = 1;
	
	while (max>0)
	{
		max /= 2;
		finger++;
	}
	QMLOG::finger = finger;
	for (int i = 0; i < size; i++)
	{
		ConsolidationTable.push_back({ MinItem[i], finger });
	}
}
//合并函数
void QMLOG::Consolidation()
{
	auto temp_con = ConsolidationTable;
	for (int i = 0; i < size; i++)
	{
		for (int j = i+1; j < size; j++)
		{
			ConsolidationTable[i] += ConsolidationTable[j];
		}
	}
}
//初始化乘积表
void QMLOG::InitProductTable()
{

}
//选择最小项
void QMLOG::SelectLessItem()
{

}
//增加剩余项
void QMLOG::AddRemainItem()
{

}

//设置最小项向量
QMLOG& QMLOG::PutItem(vector<int>& vect)
{
	//设置个数
	size = vect.size();
	//设置向量并排序
	MinItem = vect;
	sort(MinItem.begin(), MinItem.end());
	complete = false;
	return *this;
}
//取得结果
vector<int>& QMLOG::GetSinplest()
{
	//如果已经有结果，就直接返回，否则计算
	if (!complete)
	{
		InitConList();
		Consolidation();
		InitProductTable();
		SelectLessItem();
		AddRemainItem();
		complete = true;
	}
	return ConMinItem;
}
//输出函数
ostream& operator<<(ostream& out, QMLOG& me)
{
	int size = me.Size();
	vector<int> MinItem = me.PopMinItem();			//最小项
	vector<int> ConMinItem = me.GetSinplest();	//结果
	vector<QM_CONSOLIDATION> ConsolidationTable = me.PopConsolidationTable();	//合并表
	vector<QM_CONSOLIDATION> ProductTable = me.PopProductTable();				//乘积表

	out << "长度: " << size << endl;
	out << "待化简表达式" << endl;
	//for_each(MinItem.begin(), MinItem.end(), [&](int x) {out <<'m'<< x << " + "; });
	out << 'm' << MinItem[0];
	for (int i = 1; i < MinItem.size(); i++)
	{
		out << " + m" << MinItem[i];
	}
	out << endl;
	out << "合成表" << endl;
	out << "P | A B C D E | NUM" << endl;
	out << "-------------------" << endl;
	for_each(ConsolidationTable.begin(), ConsolidationTable.end(), [&](QM_CONSOLIDATION x)
		{
			out << x << endl;
		});
	out << "乘积表" << endl;
	out << "P&M";
	for_each(MinItem.begin(), MinItem.end(), [&](int x) {out << ' ' << x; });
	out << endl;
	for_each(ConsolidationTable.begin(), ConsolidationTable.end(), [&](QM_CONSOLIDATION x)
		{
			out << x.PopIndex();
			for (int i = 0; i < MinItem.size(); i++)
			{
				vector<int> num = ConsolidationTable[i].PopNum();
				int len = num.size();
				for (int j = 0; j < len; j++)
				{
					if (MinItem[i] == num[j])
						cout << " 1 ";
					else
						cout << "   ";
				}
			}
		});
	return out;
}

