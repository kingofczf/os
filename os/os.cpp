#include<iostream>
#include<ctime>
using namespace std;
void FCFS(int a[], int n);
void SSTF(int a[], int n);
void CopyL(int Sour[], int Dist[], int x); //数组Sour复制到数组Dist，复制到x个数
//void SetDI(int DiscL[]);  //随机生成磁道数  
//void Print(int Pri[], int x);  //打印输出数组Pri
void DelInq(int Sour[], int x, int y);  //数组Sour把x位置的数删除，并把y前面的数向前移动，y后的数保持不变(即会出现2个y) 
int SCAN(int DiscL[], int n, int x, int y);  //扫描算法(SCAN)
void CSCAN(int DiscL[],int Han);  //循环扫描算法(CSCAN)
void FSCAN( int DiscL[],int Han);  //N步扫描算法(NStepScan)
int main()
{
	int n; //磁道的个数
	int s; //功能号

	cout << "请输入当前磁道的个数,按Enter键显示生成的随机磁道号:" << endl;
	cin >> n;
	int *a = new int[n];
	cout << "生成的随机磁道号为：";
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++) {
		a[i] = (rand() % 100) + 1;
		cout << a[i] << " ";
	}

	cout << endl;
	while (1)
	{
		cout << endl;
		cout << "-----------------------------------------------------" << endl;
		cout << "|                   磁盘调度算法列表                |" << endl;
		cout << "|---------------------------------------------------|" << endl;
		cout << "|              1 先来先服务算法（FCFS)              |" << endl;
		cout << "|---------------------------------------------------|" << endl;
		cout << "|              2 最短寻道时间(SSTF)                 |" << endl;
		cout << "|---------------------------------------------------|" << endl;
		cout << "|              3 扫描算法(SCAN)                     |" << endl;
		cout << "|---------------------------------------------------|" << endl;
		cout << "|              4 循环扫描算法(CSCAN)                |" << endl;
		cout << "|---------------------------------------------------|" << endl;
		cout << "|              5 N步SCAN(FSCAN)                     |" << endl;
		cout << "|---------------------------------------------------|" << endl;
		cout << "|              0 退出                               |" << endl;
		cout << "-----------------------------------------------------" << endl;
		cout << endl;
		cout << "请选择所需功能的前置编号：";
		cin >> s;
		if (s > 5)
		{
			cout << "数据输入有误!请重新输入：" << endl;
		}
		else {

			switch (s) {
			case 0: exit(0); break;
			case 1:FCFS(a, n); break;
			case 2:SSTF(a, n); break;
			case 3:SCAN(a, n,0,9); break;//默认是10个磁道
			case 4:CSCAN(a, n); break;
			case 5:FSCAN(a, n); break;
			}
		}
	}
	return 0;
}

//数组Sour复制到数组Dist，复制到第x个数
void CopyL(int Sour[], int Dist[], int x)
{
	int i;
	for (i = 0; i <= x; i++)
	{
		Dist[i] = Sour[i];
	}
}
//数组Sour把x位置的数删除，并把y前面的数向前移动，y后的数保持不变(即会出现2个y) 
void DelInq(int Sour[], int x, int y)
{
	int i;
	for (i = x; i<y; i++)
	{
		Sour[i] = Sour[i + 1];
		x++;
	}
}
//先来先服务调度算法(FCFS) 
void  FCFS(int a[], int n) {
	int sum = 0, j, i, first = 0, now;
	cout << "请输入当前磁道号：";
	cin >> now; //确定当前磁头所在位置
	cout << "磁盘调度顺序为：" << endl;
	for (i = 0; i < n; i++)//按访问顺序输出磁道号 
	{
		cout << a[i] << " ";
	}
	//计算sum
	for (i = 0, j = 1; j < n; i++, j++)
	{
		first += abs(a[j] - a[i]); //外围磁道与最里面磁道的距离
	}
	sum += first + abs(now - a[0]);
	cout << endl;
	cout << "移动的总磁道数为：" << sum << endl;
	//float ave;
	//ave=
	cout << "平均移动距离为：" << (float)sum / (float)(i + 1) << endl;
}


//敏短寻道时间算法 （SSTF) 
void  SSTF(int  a[], int n) {
	int temp;
	int k = 1;
	int now, l, r;
	int i, j, sum = 0;
	//将磁道号按递增排序 
	for (i = 0; i < n; i++)
		for (j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	cout << "按递增顺序排好的磁道显示为 ：" << endl;
	for (i = 0; i < n; i++)
	{
		cout << a[i] << " "; //输出排好的磁道顺序
	}
	cout << endl;
	cout << "请输入当前的磁道号 ：";
	cin >> now;//确定当前磁头所在位置
	cout << "磁盘调度顺序为:" << endl;
	if (a[n - 1] <= now)//当前磁头位置大于最外围欲访问磁道
	{
		for (i = n - 1; i >= 0; i--)
			cout << a[i] << " ";
		sum = now - a[0];
	}
	else
		if (a[0] >= now)//当前磁头位置小于最里欲访问磁道
		{
			for (i = 0; i < n; i++)
				cout << a[i] << " ";
			sum = a[n - 1] - now;
		}
		else
		{
			while (a[k] < now)//确定当前磁道在己排的序列中的位置
			{
				k++;
			}
			l = k - 1;//在磁头位置的前一个欲访问磁道
			r = k; //磁头欲访问磁道
			while ((l >= 0) && (r < n))
			{
				if ((now - a[l]) <= (a[r] - now))//选择离磁头近的磁道
				{
					cout << a[l] << " ";
					sum += now - a[l];
					now = a[l];
					l = l - 1;
				}
				else
				{
					cout << a[r] << " ";
					sum += a[r] - now;
					now = a[r];
					r = r + 1;
				}
			}
			if (l = -1)//磁头位置里侧的磁道己访问完 
			{
				for (j = r; j < n; j++)//访问磁头位置外侧的磁道
				{
					cout << a[j] << " ";
				}
				sum += a[n - 1] - a[0];
			}
			if (r == n)//磁头位置外侧的磁道己访问完 
			{
				for (j = k - 1; j > -1; j--)//访问磁头位置里侧的磁道
				{
					cout << a[j] << " ";
				}
				sum += a[n - 1] - a[0];
			}
		}
	cout << endl;
	cout << "移动的总道数为 ：" << sum << endl;
	cout << "平均移动距离为：" << (float)sum / (float)i << endl;
}

int NAll = 0;
int Best[5][2]; //用作寻道长度由低到高排序时存放的数组 
int Jage;
float Aver = 0;
// 扫描算法(SCAN)
int SCAN(int DiscL[], int Han, int x, int y)
{
	int j, n, k, h, m, All;
	int t = 0;
	int Temp;
	int Min;
	int RLine[10]; //将随机生成的磁道数数组Discl[]复制给数组RLine[] 
	int Order;
	Order = 1;
	k = y;
	m = 2;  //控制while语句的执行，即是一定要使当前磁道向内向外都要扫描到
	All = 0;  //统计全部的磁道数变量
	CopyL(DiscL, RLine, 9);  //复制磁道号到临时数组RLine
	cout<<"按照SCAN算法磁道的访问顺序为:"<<endl;
	Min = 64000;
	for (j = x; j <= y; j++)  //寻找与当前磁道号最短寻道的时间的磁道号
	{
		if (RLine[j]>Han)  //如果第一个随机生成的磁道号大于当前的磁道号，执行下一句
			Temp = RLine[j] - Han;  //求出临时的移动距离
		else
			Temp = Han - RLine[j];  //求出临时的移动距离
		if (Temp<Min)
		{
			Min = Temp;  //Temp临时值赋予Min
			h = j;   //把最近当前磁道号的数组下标赋予h
		}
	}
	All = All + Min;
	cout<<RLine[h];
	if (RLine[h] >= Han) {  //判断磁道的移动方向，即是由里向外还是由外向里
		Order = 0;
		t = 1;
	}
	Han = RLine[h];
	DelInq(RLine, h, k);  //每个磁道数向前移动一位
	k--;
	while (m>0)
	{
		if (Order == 1)  //order是判断磁盘扫描的方向标签，order是1的话，磁道向内移动
		{
			for (j = x; j <= y; j++)
			{
				h = -1;
				Min = 64000;
				for (n = x; n <= k; n++)  //判断离当前磁道最近的磁道号
				{
					if (RLine[n] <= Han)
					{
						Temp = Han - RLine[n];
						if (Temp<Min)
						{
							Min = Temp;  //Temp临时值赋予Min
							h = n;  //把最近当前磁道号的数组下标赋予h
						}
					}
				}
				if (h != -1)
				{
					All = All + Min;  //叠加移动距离
					cout<<"  "<<RLine[h];
					Han = RLine[h]; //最近的磁道号作为当前磁道
					DelInq(RLine, h, k);
					k--;
				}
			}
			Order = 0;  //当完成向内的移动，order赋予0，执行else语句，使磁道向外移动
			m--;  //向内完成一次，m减一次，保证while循环执行两次
		}
		else  //order是0的话，磁道向外移动
		{
			for (j = x; j <= y; j++)
			{
				h = -1;
				Min = 64000;
				for (n = x; n <= k; n++)  //判断离当前磁道最近的磁道号
				{
					if (RLine[n] >= Han)
					{
						Temp = RLine[n] - Han;
						if (Temp<Min)
						{
							Min = Temp;   //Temp临时值赋予Min
							h = n;  //把最近当前磁道号的数组下标赋予h
						}
					}
				}
				if (h != -1)
				{
					All = All + Min;  //叠加移动距离
					cout << "  " << RLine[h];
					Han = RLine[h];  //最近的磁道号作为当前磁道
					DelInq(RLine, h, k);
					k--;
				}
			}
			Order = 1;  //当完成向内的移动，order赋予0，执行else语句，使磁道向外移动
			m--;   //向内完成一次，m减一次，保证while循环执行两次
		}
	}
	NAll = NAll + All;
	if ((y - x)>5)
	{
		Best[Jage][1] = All;//Best[][1]存放移动磁道数 
		Best[Jage][0] = 3;//Best[][0]存放算法的序号为:3
		Jage++;//排序序号加1
		Aver = ((float)All) / 10;//求平均寻道次数 
		cout << endl << "移动磁道数:" << All;
		cout << endl << "平均寻道长度:"<<Aver;
	}
	if (t == 1) cout<<endl<<"磁道由内向外移动";
	else cout<<endl<<"磁道由外向内移动";
	return(Han);
}
//循环扫描算法(CSCAN)
void CSCAN(int DiscL[], int Han)
{
	int j, h, n, Temp, m, k, All, Last, i;
	int RLine[10];  //将随机生成的磁道数数组Discl[]复制给数组RLine[] 
	int Min;
	int tmp = 0;
	m = 2;
	k = 9;
	All = 0;   //统计全部的磁道数变量
	Last = Han;
	CopyL(DiscL, RLine, 9);  //复制磁道号到临时数组RLine
	cout<<"按照CSCAN算法磁道的访问顺序为:"<<endl;
	while (k >= 0)
	{
		for (j = 0; j <= 9; j++)  //从当前磁道号开始，由内向外搜索离当前磁道最近的磁道号
		{
			h = -1;
			Min = 64000;
			for (n = 0; n <= k; n++)
			{
				if (RLine[n] >= Han)
				{
					Temp = RLine[n] - Han;
					if (Temp<Min)
					{
						Min = Temp;
						h = n;
					}
				}
			}
			if (h != -1)
			{
				All = All + Min;  //统计一共移动的距离
				cout << "  " << RLine[h];
				Han = RLine[h];
				Last = RLine[h];
				DelInq(RLine, h, k);
				k--;
			}
		}
		if (k >= 0)
		{
			tmp = RLine[0];
			for (i = 0; i<k; i++)//算出剩下磁道号的最小值
			{
				if (tmp>RLine[i]) tmp = RLine[i];
			}
			Han = tmp;//把最小的磁道号赋给Han
			Temp = Last - tmp;//求出最大磁道号和最小磁道号的距离差
			All = All + Temp;
		}
	}
	Best[Jage][1] = All;//Best[][1]存放移动磁道数 
	Best[Jage][0] = 4;//Best[][0]存放算法的序号为:4
	Jage++;//排序序号加1
	Aver = ((float)All) / 10;//求平均寻道次数 
	cout << endl << "移动磁道数:" << All;
	cout << endl << "平均寻道长度: " << Aver;
}
//N步扫描算法(NStepScan)
void FSCAN(int DiscL[], int Han1)
{
	int i, m, k;
	int RLine1[10];
	NAll = 0;
	m = 2;
	k = 9;  //限定10个的磁道数  
	i = -1;
	CopyL(DiscL, RLine1, 9);  //复制磁道号到临时数组RLine
	cout<<endl<<"按照FSCAN算法磁道的访问顺序为:";
	for (m = 0; m < 2; m++)  //由于限定10磁道数，将10个磁道数分为两组，每组5个磁道数，每个组按照SCAN算法执行，该循环循环2次
	{
		Han1 = SCAN(RLine1, Han1, i + 1, i + 5);
		i = i + 5;
	}
	Best[Jage][1] = NAll;//Best[][1]存放移动磁道数 
	Best[Jage][0] = 5;//Best[][0]存放算法的序号为:5
	Aver = ((float)NAll) / 10;//求平均寻道次数 
	cout<<endl<<"移动磁道数:"<< NAll;
	cout<<endl<< "平均寻道长度: "<<Aver;

}