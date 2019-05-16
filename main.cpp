#include"QMLOG.h"
#include"myhead.h"
int main()
{
	//QM_CONSOLIDATION qm1(15,4);
	vector<int> v1 = { 1,2,3,4,5,6,7 };
	QMLOG qm1(v1);
	cout << qm1;
	return 0;
}