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
	const bool Complete() { return complete; }					//输出完成标记
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
	bool complete=false;							//是否已计算
	int size=0;									//最小项数量
	int finger=0;								//最小项位数
	vector<int> MinItem;						//最小项
	vector<int> ConMinItem;						//结果
	vector<QM_CONSOLIDATION> ConsolidationTable;//合并表
	vector<QM_CONSOLIDATION> ProductTable;		//乘积表

};

#endif