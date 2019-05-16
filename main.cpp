#include"QMLOG.h"
#include"myhead.h"
int main()
{
	//QM_CONSOLIDATION qm1(15,4);
	cout << "欢迎使用QM化简程序" << endl
		<< "请输入最小项表达式" << endl;
	vector<int> v1 = { 1,2,3,4,5,6,7 };
	QMLOG qm1(v1);
	cout << qm1;
	return 0;
}