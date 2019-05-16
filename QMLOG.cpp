#include "QMLOG.h"

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
