#include "QMLOG.h"

//合并项 构造函数 动态位
QM_CONSOLIDATION::QM_CONSOLIDATION(int n)
{
	num.push_back(n);
	int finger = 0;
	while (n > 0)
	{
		n /= 2;
		finger++;
	}
	bit.assign(finger, 0);
	SetBit();
}
//合并项 构造函数 固定位
QM_CONSOLIDATION::QM_CONSOLIDATION(int n, int finger)
{
	num.push_back(n);
	this->finger = finger;
	bit.assign(finger, 0);
	SetBit();
}
//合并项 析构函数
QM_CONSOLIDATION::~QM_CONSOLIDATION()
{
}
//输出编号向量ARBITRARY
const vector<int>& QM_CONSOLIDATION::PopNum()
{
	return num;
}
//输出位向量
const vector<int>& QM_CONSOLIDATION::PopBit()
{
	return bit;
}
//输出标识
int QM_CONSOLIDATION::PopIndex()
{
	return index;
}
//设置标识
void QM_CONSOLIDATION::PushIndex(int num)
{
	index = num;
}
//找到两个合并项的不同位
int QM_CONSOLIDATION::diff(QM_CONSOLIDATION& right)
{
	int len = bit.size();
	int diff = 0;
	int pos = -1;
	for (int i = 0; i < len; i++)
	{
		if (bit[i] != right.bit[i])
		{
			diff++;
			pos = i;
		}
		if (diff > 1) return -1;
	}
	return pos;
}
//设置位向量
void QM_CONSOLIDATION::SetBit()
{

	int origin = num[0];
	int len = finger;
	while (origin > 0 && len > 0)
	{
		len--;
		bit[len] = (origin % 2);
		origin /= 2;
	}
}
//合并合并项
bool QM_CONSOLIDATION::Merge(QM_CONSOLIDATION& right)
{
	int pos = diff(right);
	if (pos != -1)
	{
		bit[pos] = X;
		num.insert(num.end(), right.num.begin(), right.num.end());
		return true;
	}
	else return false;
}
//合并合并项 重载操作符
bool QM_CONSOLIDATION::operator+=(QM_CONSOLIDATION& right)
{
	int pos = diff(right);
	if (pos != -1)
	{
		bit[pos] = X;
		num.insert(num.end(), right.num.begin(), right.num.end());
		return true;
	}
	else return false;
}
bool QM_CONSOLIDATION::operator==(QM_CONSOLIDATION& right)
{
	if (bit == right.bit) 
		return true;
	else 
		return false;
}
//打印 重载<<
ostream& operator<<(ostream& out, QM_CONSOLIDATION me)
{
	cout << me.PopIndex();
	cout << " |";
	for_each(me.PopBit().begin(), me.PopBit().end(), [&](int x) {out << ' ' << x; });
	cout << " |";
	for_each(me.PopNum().begin(), me.PopNum().end(), [&](int x) {out << ' ' << x; });
	return out;
}


QMLOG::QMLOG(int arr[], int n)
	:size(n)
{
	MinItem.assign(arr, arr + n);
	sort(MinItem.begin(), MinItem.end());
}

QMLOG::QMLOG( vector<int> & vect)
	:MinItem(vect)
{
	sort(MinItem.begin(), MinItem.end());
}

QMLOG::QMLOG(QMLOG & copy)
{
	size = copy.Size();
	MinItem = copy.PopMinItem();
	ConMinItem = copy.GetSinplest();
	ConsolidationTable = copy.PopConsolidationTable();
	ProductTable = copy.PopProductTable();
}

QMLOG::QMLOG() :size(0) {}

QMLOG::~QMLOG() {}

//操作符<<重载
void QMLOG::operator=(QMLOG& copy)
{
	size = copy.Size();
	MinItem = copy.PopMinItem();
	ConsolidationTable = copy.PopConsolidationTable();
	ProductTable = copy.PopProductTable();
}

void QMLOG::InitConList()
{

}

void QMLOG::Consolidation()
{

}

void QMLOG::InitProductTable()
{

}

void QMLOG::SelectLessItem()
{

}

void QMLOG::AddRemainItem()
{

}

//
QMLOG& QMLOG::PutItem(vector<int>& vect)
{
	size = vect.size();
	MinItem = vect;
	return *this;
}

vector<int>& QMLOG::GetSinplest()
{
	InitConList();
	Consolidation();
	InitProductTable();
	SelectLessItem();
	AddRemainItem();
	return ConMinItem;
}




ostream& operator<<(ostream& out, QMLOG me)
{
	int size = me.Size();
	vector<int> MinItem = me.PopMinItem();			//最小项
	vector<int> ConMinItem = me.GetSinplest();	//结果
	vector<QM_CONSOLIDATION> ConsolidationTable = me.PopConsolidationTable();	//合并表
	vector<QM_CONSOLIDATION> ProductTable = me.PopProductTable();				//乘积表

	out << "长度: " << size << endl;
	out << "待化简表达式" << endl;
	//for_each(MinItem.begin(), MinItem.end(), [&](int x) {out <<'m'<< x << " + "; });
	out<<'m' << MinItem[0];
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
	// TODO: 在此处插入 return 语句}
}
