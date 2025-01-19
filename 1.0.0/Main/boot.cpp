#include<iostream>
#include<stdio.h> 
#include<windows.h>
using namespace std;
typedef long long (*oper)(long long x,long long y);
typedef double(*fd)(double x,double y,double z);
typedef void(*_srand)();
typedef int(*_rand)();
void numin(long long& x,long long& y){
	cout<<"�������һ������>>>";
	cin>>x;
	cout<<"������ڶ�������>>>";
	cin>>y;
	return;
} 
void DoubleNumin(double& x,double& y){
	cout<<"�������һ������>>>";
	cin>>x;
	cout<<"������ڶ�������>>>";
	cin>>y;
	return;
}
int main(){
	HMODULE dll=LoadLibrary("operator.dll");
	HMODULE ddll=LoadLibrary("doubleoperator.dll");
	HMODULE defdll=LoadLibrary("defaultoperator.dll"); 
	HMODULE rand=LoadLibrary("random.dll");
	HMODULE size=LoadLibrary("lengthoperator.dll"); 
	cout<<"[debug]C++ ������ project initializering...\n";
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
			cout<<"[soruces]DLL ProcAddress Load Success!\n[debug]�����ɹ�,����3�������\n";
			Sleep(3000);
			system("cls");
			printf("��ӭʹ��C++������\n");
			start:
				int type;
				printf("�����·�ѡ������Ҫ���������\n1.�������� 2.����С�������� 3.�ܳ����� 4.������� 5.���� 6.�˳�\n>>>");
				scanf("%d",&type);
				switch(type){
					case 1:
						int select_int;
						ic_start:
							printf("����Ҫʲô����?\n1.�ӷ� 2.���� 3.�˷� 4.���� 5.����ѡ��\n>>>");
							cin>>select_int;
							if(select_int==1){
								long long x,y,out;
								numin(x,y);
								out=addition(x,y);
								printf("�����������,���:%lld\n",out);
								goto ic_start;
							}
							else if(select_int==2){
								long long x,y,out;
								numin(x,y);
								out=subtraction(x,y);
								printf("�����������,���:%lld\n",out);
								goto ic_start;
							}
							else if(select_int==3){
								long long x,y,out;
								numin(x,y);
								out=multiplication(x,y);
								printf("�����������,���:%lld\n",out);
								goto ic_start;
							}
							else if(select_int==4){
								long long x,y,out;
								numin(x,y);
								out=division(x,y);
								if(out==-1){
									cout<<"�ڶ���������Ϊ0!\n";
									goto ic_start; 
								}
								else{
									printf("�����������,���:%lld\n",out);
									goto ic_start;
								}
							}
							else if(select_int==5){
								goto start;
							}
							else{
								cout<<"OOPS!û���ҵ��������͵ļ���!\n";
								goto ic_start;
							}
					case 2:
						int select_double;
						dc_start:
							printf("����Ҫʲô����?\n1.�������ӷ� 2.���������� 3.�������˷� 4.���������� 5.����ѡ��\nTips:���ڼ�������,���ֻ�ܾ�ȷ��С�����2λ\n>>>");
							cin>>select_double;
							if(select_double==1){
								double x,y,out;
								DoubleNumin(x,y);
								out=d_addition(x,y,0);
								printf("�����������,���:%.2lf\n",out);
								goto dc_start;
							} 
							else if(select_double==2){
								double x,y,out;
								DoubleNumin(x,y);
								out=d_subtraction(x,y,0);
								printf("�����������,���:%.2lf\n",out);
								goto dc_start;
							}
							else if(select_double==3){
								double x,y,out;
								DoubleNumin(x,y);
								out=d_multiplication(x,y,0);
								printf("�����������,���:%.2lf\n",out);
								goto dc_start;
							}
							else if(select_double==4){
								double x,y,out;
								DoubleNumin(x,y);
								out=d_division(x,y,0);
								if(out==-1){
									cout<<"�ڶ���������Ϊ0!\n";
									goto dc_start;
								}
								else{
									printf("�����������,���:%.2lf\n",out);
									goto dc_start;
								}
							}
							else if(select_double==5){
								goto start;
							}
							else{
								cout<<"OOPS!û���ҵ��������͵ļ���!\n";
								goto dc_start;
							}
					case 3:
						int pr_select;
						pr_start:
							printf("����Ҫ����ʲôͼ�ε��ܳ�?\n1.���� 2.������ 3.Բ�� 4.����ѡ��\nTips:֧��С��,ֻ������λС��\n>>>");
							cin>>pr_select;
							if(pr_select==1){
								double x,y,out;
								cout<<"���볤:";
								cin>>x;
								cout<<"�����:";
								cin>>y;
								if(x<y){
									cout<<"OOPS!������ݲ�����Ҫ��,���������!\n";
									goto pr_start;
								} 
								out=rp(x,y,0); 
								printf("�þ��ε��ܳ�Ϊ:%.2lf\n",out);
								goto pr_start;
							}
							else if(pr_select==2){
								double a[5],out;
								cout<<"�������е�����(3��,�ո����):";
								for(int i=1;i<=3;i++){
									cin>>a[i];
								}
								out=tp(a[1],a[2],a[3]);
								printf("�������ε��ܳ�Ϊ:%.2lf\n",out);
								goto pr_start;
							}
							else if(pr_select==3){
								double r,out;
								cout<<"����뾶:";
								cin>>r;
								out=cp(r,0,0);
								printf("��Բ�ε��ܳ�Ϊ:%.2lf\n",out);
								goto pr_start;
							}
							else if(pr_select==4){
								goto start;
							}
							else{
								cout<<"OOPS!û���ҵ�����ͼ�ε��ܳ�������!\n";
								goto pr_start;
							}
					case 4:
						int aa_select;
						aa_start:
							printf("����Ҫ����ʲôͼ�ε����?\n1.���� 2.������ 3.Բ��\nTips:֧��С��,ֻ������λС��\n>>>");
							cin>>aa_select;
							if(aa_select==1){
								double x,y,out;
								cout<<"���볤:";
								cin>>x;
								cout<<"�����:";
								cin>>y;
								if(x<y){
									cout<<"OOPS!������ݲ�����Ҫ��,���������!";
									goto aa_start;
								}
								out=ra(x,y,0);
								printf("�þ��ε����Ϊ:%.2lf\n",out);
								goto aa_start;
							} 
							else if(aa_select==2){
								double a[5],out;
								cout<<"����ߺ͵׳�(�ո����):";
								for(int i=1;i<=2;i++){
									cin>>a[i];
								}
								out=ta(a[1],a[2],0);
								printf("�������ε����Ϊ:%.2lf\n",out);
								goto aa_start;
							}
							else if(aa_select==3){
								double r,out;
								cout<<"����뾶:";
								cin>>r;
								out=ca(r,0,0);
								printf("��Բ�ε����Ϊ:%.2lf\n",out);
								goto aa_start; 
							}
							else{
								cout<<"OOPS!û���ҵ�����ͼ�ε��ܳ�������!\n";
								goto aa_start;
							}
					case 5:
						int def_type;
						dc2_start:
							printf("����Ҫʲô����?\n1.ȡƽ�� 2.ȡ���� 3.�Զ���η� 4.ȡ����� 5.�������������Ϊϵͳʱ�� 6.����ѡ��\n>>>");
							cin>>def_type;
							if(def_type==1){
								long long n,out;
								cout<<"����һ������>>>";
								scanf("%lld",&n);
								out=pow2(n,0);
								printf("ȡƽ�����,���:%lld\n",out);
								goto dc2_start;
							}
							else if(def_type==2){
								long long n,out;
								cout<<"����һ������>>>";
								scanf("%lld",&n);
								out=pow3(n,0);
								printf("ȡ�������,���:%lld\n",out);
								goto dc2_start;
							}
							else if(def_type==3){
								long long n,f,out;
								cout<<"����һ������>>>";
								scanf("%lld",&n);
								cout<<"Ҫȡ���ٴη�>>>";
								scanf("%lld",&f);
								out=defpow(n,f);
								printf("ȡ%lld�η����,���:%lld\n",f,out);
								goto dc2_start;
							}
							else if(def_type==4){
								int out;
								out=random();
								printf("�������ȡ���:%d\n",out);
								goto dc2_start;
							}
							else if(def_type==5){
								srandst();
								printf("����������������!\n");
								goto dc2_start;
							}
							else if(def_type==6){
								goto start;
							}
							else{
								cout<<"OOPS!û���ҵ��������͵ļ���!\n";
								goto dc2_start;
							}
					case 6:
						int cast;
						printf("���Ҫ�뿪��?\n");
						cast_select:
							printf("1.����뿪 2.����\n>>>");
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
								cout<<"�Ҳ����~\n";
								goto cast_select;
							}
					default:
						printf("OOPS!�Ҳ�������,������ѡ��!\n");
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
		cout<<"[Error]DLL Library Load Failure!(����DLL�����ڴ淢������!)\nShutdowning...";
		Sleep(1000);
		return 0;
	}
}
