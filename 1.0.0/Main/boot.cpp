#include<iostream>
#include<stdio.h> 
#include<windows.h>
using namespace std;
typedef long long (*oper)(long long x,long long y);
typedef double(*fd)(double x,double y,double z);
typedef void(*_srand)();
typedef int(*_rand)();
void numin(long long& x,long long& y){
	cout<<"请输入第一个数字>>>";
	cin>>x;
	cout<<"请输入第二个数字>>>";
	cin>>y;
	return;
} 
void DoubleNumin(double& x,double& y){
	cout<<"请输入第一个数字>>>";
	cin>>x;
	cout<<"请输入第二个数字>>>";
	cin>>y;
	return;
}
int main(){
	HMODULE dll=LoadLibrary("operator.dll");
	HMODULE ddll=LoadLibrary("doubleoperator.dll");
	HMODULE defdll=LoadLibrary("defaultoperator.dll"); 
	HMODULE rand=LoadLibrary("random.dll");
	HMODULE size=LoadLibrary("lengthoperator.dll"); 
	cout<<"[debug]C++ 计算器 project initializering...\n";
	Sleep(800);
	cout<<"[debug]DLL Library loader...\n";
	if(dll!=NULL&&
	ddll!=NULL&&
	defdll!=NULL&&
	rand!=NULL&&
	size!=NULL
	){
		cout<<"[sources]DLL Library Load Success!\n";
		Sleep(1000);
		cout<<"[debug]DLL ProcAddress Loading...\n";
		oper addition=(oper)GetProcAddress(dll,"OperAddition");
		oper subtraction=(oper)GetProcAddress(dll,"OperSubtraction");
		oper multiplication=(oper)GetProcAddress(dll,"OperMultiplication");
		oper division=(oper)GetProcAddress(dll,"OperDivision");
		fd d_addition=(fd)GetProcAddress(ddll,"OperAddition");
		fd d_subtraction=(fd)GetProcAddress(ddll,"OperSubtracation");
		fd d_multiplication=(fd)GetProcAddress(ddll,"OperMultiplication");
		fd d_division=(fd)GetProcAddress(ddll,"OperDivision");
		fd sqrt=(fd)GetProcAddress(defdll,"get_sqrt");
		oper pow2=(oper)GetProcAddress(defdll,"get_pow2");
		oper pow3=(oper)GetProcAddress(defdll,"get_pow3");
		oper defpow=(oper)GetProcAddress(defdll,"get_defpow");
		fd PI=(fd)GetProcAddress(defdll,"PI");
		_srand srandst=(_srand)GetProcAddress(rand,"SrandToSystemTime");
		_rand random=(_rand)GetProcAddress(rand,"Random");
		fd rp=(fd)GetProcAddress(size,"GetRectanglePrimeter");
		fd ra=(fd)GetProcAddress(size,"GetRectangleArea");
		fd cp=(fd)GetProcAddress(size,"GetCircularPrimeter");
		fd ca=(fd)GetProcAddress(size,"GetCircularArea");
		fd tp=(fd)GetProcAddress(size,"GetTrianglePrimeter");
		fd ta=(fd)GetProcAddress(size,"GetTriangleArea");
		if(addition!=NULL&&
		subtraction!=NULL&&
		multiplication!=NULL&&
		division!=NULL&&
		d_addition!=NULL&&
		d_subtraction!=NULL&&
		d_multiplication!=NULL&&
		d_division!=NULL&&
		sqrt!=NULL&&
		pow2!=NULL&&
		pow3!=NULL&&
		defpow!=NULL&&
		PI!=NULL&&
		srandst!=NULL&&
		random!=NULL&&
		rp!=NULL&&
		ra!=NULL&&
		cp!=NULL&&
		ca!=NULL&&
		tp!=NULL&&
		ta!=NULL
		){
			cout<<"[soruces]DLL ProcAddress Load Success!\n[debug]启动成功,将在3秒后启动\n";
			Sleep(3000);
			system("cls");
			printf("欢迎使用C++计算器\n");
			start:
				int type;
				printf("请在下方选择你需要计算的类型\n1.整数运算 2.含有小数的运算 3.周长计算 4.面积计算 5.其他 6.退出\n>>>");
				scanf("%d",&type);
				switch(type){
					case 1:
						int select_int;
						ic_start:
							printf("你想要什么运算?\n1.加法 2.减法 3.乘法 4.除法 5.重新选择\n>>>");
							cin>>select_int;
							if(select_int==1){
								long long x,y,out;
								numin(x,y);
								out=addition(x,y);
								printf("计算任务完成,结果:%lld\n",out);
								goto ic_start;
							}
							else if(select_int==2){
								long long x,y,out;
								numin(x,y);
								out=subtraction(x,y);
								printf("计算任务完成,结果:%lld\n",out);
								goto ic_start;
							}
							else if(select_int==3){
								long long x,y,out;
								numin(x,y);
								out=multiplication(x,y);
								printf("计算任务完成,结果:%lld\n",out);
								goto ic_start;
							}
							else if(select_int==4){
								long long x,y,out;
								numin(x,y);
								out=division(x,y);
								if(out==-1){
									cout<<"第二个数不能为0!\n";
									goto ic_start; 
								}
								else{
									printf("计算任务完成,结果:%lld\n",out);
									goto ic_start;
								}
							}
							else if(select_int==5){
								goto start;
							}
							else{
								cout<<"OOPS!没有找到这种类型的计算!\n";
								goto ic_start;
							}
					case 2:
						int select_double;
						dc_start:
							printf("你想要什么运算?\n1.浮点数加法 2.浮点数减法 3.浮点数乘法 4.浮点数除法 5.重新选择\nTips:由于技术问题,结果只能精确到小数点后2位\n>>>");
							cin>>select_double;
							if(select_double==1){
								double x,y,out;
								DoubleNumin(x,y);
								out=d_addition(x,y,0);
								printf("计算任务结束,结果:%.2lf\n",out);
								goto dc_start;
							} 
							else if(select_double==2){
								double x,y,out;
								DoubleNumin(x,y);
								out=d_subtraction(x,y,0);
								printf("计算任务结束,结果:%.2lf\n",out);
								goto dc_start;
							}
							else if(select_double==3){
								double x,y,out;
								DoubleNumin(x,y);
								out=d_multiplication(x,y,0);
								printf("计算任务结束,结果:%.2lf\n",out);
								goto dc_start;
							}
							else if(select_double==4){
								double x,y,out;
								DoubleNumin(x,y);
								out=d_division(x,y,0);
								if(out==-1){
									cout<<"第二个数不能为0!\n";
									goto dc_start;
								}
								else{
									printf("计算任务结束,结果:%.2lf\n",out);
									goto dc_start;
								}
							}
							else if(select_double==5){
								goto start;
							}
							else{
								cout<<"OOPS!没有找到这种类型的计算!\n";
								goto dc_start;
							}
					case 3:
						int pr_select;
						pr_start:
							printf("你想要计算什么图形的周长?\n1.矩形 2.三角形 3.圆形 4.重新选择\nTips:支持小数,只保留两位小数\n>>>");
							cin>>pr_select;
							if(pr_select==1){
								double x,y,out;
								cout<<"输入长:";
								cin>>x;
								cout<<"输入宽:";
								cin>>y;
								if(x<y){
									cout<<"OOPS!你的数据不符合要求,请检查后再试!\n";
									goto pr_start;
								} 
								out=rp(x,y,0); 
								printf("该矩形的周长为:%.2lf\n",out);
								goto pr_start;
							}
							else if(pr_select==2){
								double a[5],out;
								cout<<"输入所有的数据(3个,空格隔开):";
								for(int i=1;i<=3;i++){
									cin>>a[i];
								}
								out=tp(a[1],a[2],a[3]);
								printf("该三角形的周长为:%.2lf\n",out);
								goto pr_start;
							}
							else if(pr_select==3){
								double r,out;
								cout<<"输入半径:";
								cin>>r;
								out=cp(r,0,0);
								printf("该圆形的周长为:%.2lf\n",out);
								goto pr_start;
							}
							else if(pr_select==4){
								goto start;
							}
							else{
								cout<<"OOPS!没有找到这种图形的周长计算类!\n";
								goto pr_start;
							}
					case 4:
						int aa_select;
						aa_start:
							printf("你想要计算什么图形的面积?\n1.矩形 2.三角形 3.圆形\nTips:支持小数,只保留两位小数\n>>>");
							cin>>aa_select;
							if(aa_select==1){
								double x,y,out;
								cout<<"输入长:";
								cin>>x;
								cout<<"输入宽:";
								cin>>y;
								if(x<y){
									cout<<"OOPS!你的数据不符合要求,请检查后在试!";
									goto aa_start;
								}
								out=ra(x,y,0);
								printf("该矩形的面积为:%.2lf\n",out);
								goto aa_start;
							} 
							else if(aa_select==2){
								double a[5],out;
								cout<<"输入高和底长(空格隔开):";
								for(int i=1;i<=2;i++){
									cin>>a[i];
								}
								out=ta(a[1],a[2],0);
								printf("该三角形的面积为:%.2lf\n",out);
								goto aa_start;
							}
							else if(aa_select==3){
								double r,out;
								cout<<"输入半径:";
								cin>>r;
								out=ca(r,0,0);
								printf("该圆形的面积为:%.2lf\n",out);
								goto aa_start; 
							}
							else{
								cout<<"OOPS!没有找到这种图形的周长计算类!\n";
								goto aa_start;
							}
					case 5:
						int def_type;
						dc2_start:
							printf("你想要什么计算?\n1.取平方 2.取立方 3.自定义次方 4.取随机数 5.重置随机数种子为系统时间 6.重新选择\n>>>");
							cin>>def_type;
							if(def_type==1){
								long long n,out;
								cout<<"输入一个数字>>>";
								scanf("%lld",&n);
								out=pow2(n,0);
								printf("取平方完成,结果:%lld\n",out);
								goto dc2_start;
							}
							else if(def_type==2){
								long long n,out;
								cout<<"输入一个数字>>>";
								scanf("%lld",&n);
								out=pow3(n,0);
								printf("取立方完成,结果:%lld\n",out);
								goto dc2_start;
							}
							else if(def_type==3){
								long long n,f,out;
								cout<<"输入一个数字>>>";
								scanf("%lld",&n);
								cout<<"要取多少次方>>>";
								scanf("%lld",&f);
								out=defpow(n,f);
								printf("取%lld次方完成,结果:%lld\n",f,out);
								goto dc2_start;
							}
							else if(def_type==4){
								int out;
								out=random();
								printf("随机数获取结果:%d\n",out);
								goto dc2_start;
							}
							else if(def_type==5){
								srandst();
								printf("随机数种子重置完毕!\n");
								goto dc2_start;
							}
							else if(def_type==6){
								goto start;
							}
							else{
								cout<<"OOPS!没有找到这种类型的计算!\n";
								goto dc2_start;
							}
					case 6:
						int cast;
						printf("真的要离开吗?\n");
						cast_select:
							printf("1.真的离开 2.算了\n>>>");
							cin>>cast;
							if(cast==1){
								system("cls");
								cout<<"[debug]Shutdowning...";
								FreeLibrary(dll);
								FreeLibrary(ddll);
								Sleep(1000);
								return 0;
							} 
							else if(cast==2){
								goto start;
							}
							else{
								cout<<"找不到喔~\n";
								goto cast_select;
							}
					default:
						printf("OOPS!找不到该项,请重新选择!\n");
						goto start;
				} 
				goto start;
		}
		else{
			cout<<"[Error]DLL ProcAddress Load Failure!";
			FreeLibrary(dll);
			FreeLibrary(ddll);
			Sleep(1000);
			return 0;
		}
	}
	else{
		cout<<"[Error]DLL Library Load Failure!(分配DLL运行内存发生错误!)\nShutdowning...";
		Sleep(1000);
		return 0;
	}
}
