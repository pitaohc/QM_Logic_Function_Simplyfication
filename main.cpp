#include"QMLOG.h"
#include<iostream>
int main()
{
	//QM_CONSOLIDATION qm1(15,4);
	vector<int> v1 = { 1,2,3,4,5,6,7 };
	QMLOG qm1(v1);
	qm1.GetSinplest();
	cout << qm1.Size();
	cout << qm1;
	return 0;
}