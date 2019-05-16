#include "QM_CONSOLIDATION.h"

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
	int len = bit.size(); //bit长度
	int diff = 0;        //不同位数量
	int pos = -1;		//不同位位置
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
ostream& operator<<(ostream & out, QM_CONSOLIDATION me)
{
	cout << me.PopIndex();
	cout << " |";
	for_each(me.PopBit().begin(), me.PopBit().end(), [&](int x) {out << ' ' << x; });
	cout << " |";
	for_each(me.PopNum().begin(), me.PopNum().end(), [&](int x) {out << ' ' << x; });
	cout << endl;
	return out;
}
