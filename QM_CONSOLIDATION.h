#pragma once
#include"myhead.h"
using namespace std;
#ifndef _QM_CONSOLIDATION_
#define _QM_CONSOLIDATION_
enum STATUS
{
	FALSE, TRUE, X
};

/********************************************************
class:	合并项
function:存放合并项信息
*********************************************************/
class QM_CONSOLIDATION
{
public:
	QM_CONSOLIDATION(int n);			//构造函数，动态位
	QM_CONSOLIDATION(int n, int finger);//构造函数，固定位
	~QM_CONSOLIDATION();				//析构函数
	const vector<int>& PopNum();//输出序号向量
	const vector<int>& PopBit();//输出位向量
	int	 PopIndex();			//输出标识
	void PushIndex(int num);    //输入标识
	bool Merge(QM_CONSOLIDATION& right);		//合并合并项
	bool operator +=(QM_CONSOLIDATION& right);	//合并合并项 +=操作符重载
	bool operator ==(QM_CONSOLIDATION& right);  //比较两个合并项是否相等
	friend ostream& operator <<(ostream& out, QM_CONSOLIDATION me);

private:
	int diff(QM_CONSOLIDATION& right);//合并项比较
	void SetBit();  //设置位向量
	int index = -1;	//标识
	int finger;		//位数
	vector<int> num;//序号向量
	vector<int> bit;//位向量
};




#endif // !_QM_CONSOLIDATION_

