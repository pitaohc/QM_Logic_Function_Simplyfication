#pragma once

/*
step：
	1、将最小项转化成二进制编码表
	2、将二进制编码表写入合并表
	3、合并合并表
	4、如果无法继续合并则继续，否则返回step3
	5、通过列表法选择最小乘积项
	6、将剩余乘积项化简
	7、如果无法继续化简则继续，否则返回step6
	8、输出化简后的最小项
*/
#ifndef _QMLOG_

#define _QMLOG_
#include"myhead.h"
#include"QM_CONSOLIDATION.h"
#define FALSE 0
#define TRUE 1
#define X 2
using namespace std;

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
	int index=-1;	//标识
	int finger;		//位数
	vector<int> num;//序号向量
	vector<int> bit;//位向量
};

/********************************************************************
 class:		QM逻辑表达式
 function:	储存最简表达式

********************************************************************/
class QMLOG
{
public:
	QMLOG(int arr[], int n);
	QMLOG(vector<int>& vect);
	QMLOG(QMLOG& copy);
	QMLOG();
	~QMLOG();
	
	QMLOG& PutItem(vector<int>& Min_Item);//放入待化简式


	vector<int>& GetSinplest();//得到最简式

	//输出变量函数
	const int Size() { return size; }							//输出
	const vector<int>& PopMinItem() { return MinItem;}			//输出最小项
	const vector<QM_CONSOLIDATION>& PopConsolidationTable() { return ConsolidationTable; }	//输出合并表
	const vector<QM_CONSOLIDATION>& PopProductTable() { return ProductTable; }				//输出乘积表
	
	//操作符重载函数
	void operator =(QMLOG& copy);//复制构造函数
	friend ostream& operator <<(ostream& out,QMLOG & me);
private:
	//vector<int>* PMin_Item;//最小项
	//vector<int>* PCon_Min_Item;//结果
	//vector<QM_CONSOLIDATION>* PConsolidation_Table;//合并表
	//vector<QM_CONSOLIDATION>* PProduct_Table;//乘积表	

	//私有成员函数
	void InitConList();			//1、初始化合并表 ,得出位数和设置consolidation_table
	void Consolidation();		//合并式子,合并consolidation_table
	void InitProductTable();	//初始化乘积表,Product_Table
	void SelectLessItem();		//列表法选择最少乘积项
	void AddRemainItem();		//增加剩余项
	//私有成员变量
	int size;									//最小项数量
	vector<int> MinItem;						//最小项
	vector<int> ConMinItem;						//结果
	vector<QM_CONSOLIDATION> ConsolidationTable;//合并表
	vector<QM_CONSOLIDATION> ProductTable;		//乘积表

};

#endif