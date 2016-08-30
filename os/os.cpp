#include<iostream>
#include<ctime>
using namespace std;
void FCFS(int a[], int n);
void SSTF(int a[], int n);
void CopyL(int Sour[], int Dist[], int x); //����Sour���Ƶ�����Dist�����Ƶ�x����
//void SetDI(int DiscL[]);  //������ɴŵ���  
//void Print(int Pri[], int x);  //��ӡ�������Pri
void DelInq(int Sour[], int x, int y);  //����Sour��xλ�õ���ɾ��������yǰ�������ǰ�ƶ���y��������ֲ���(�������2��y) 
int SCAN(int DiscL[], int n, int x, int y);  //ɨ���㷨(SCAN)
void CSCAN(int DiscL[],int Han);  //ѭ��ɨ���㷨(CSCAN)
void FSCAN( int DiscL[],int Han);  //N��ɨ���㷨(NStepScan)
int main()
{
	int n; //�ŵ��ĸ���
	int s; //���ܺ�

	cout << "�����뵱ǰ�ŵ��ĸ���,��Enter����ʾ���ɵ�����ŵ���:" << endl;
	cin >> n;
	int *a = new int[n];
	cout << "���ɵ�����ŵ���Ϊ��";
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
		cout << "|                   ���̵����㷨�б�                |" << endl;
		cout << "|---------------------------------------------------|" << endl;
		cout << "|              1 �����ȷ����㷨��FCFS)              |" << endl;
		cout << "|---------------------------------------------------|" << endl;
		cout << "|              2 ���Ѱ��ʱ��(SSTF)                 |" << endl;
		cout << "|---------------------------------------------------|" << endl;
		cout << "|              3 ɨ���㷨(SCAN)                     |" << endl;
		cout << "|---------------------------------------------------|" << endl;
		cout << "|              4 ѭ��ɨ���㷨(CSCAN)                |" << endl;
		cout << "|---------------------------------------------------|" << endl;
		cout << "|              5 N��SCAN(FSCAN)                     |" << endl;
		cout << "|---------------------------------------------------|" << endl;
		cout << "|              0 �˳�                               |" << endl;
		cout << "-----------------------------------------------------" << endl;
		cout << endl;
		cout << "��ѡ�����蹦�ܵ�ǰ�ñ�ţ�";
		cin >> s;
		if (s > 5)
		{
			cout << "������������!���������룺" << endl;
		}
		else {

			switch (s) {
			case 0: exit(0); break;
			case 1:FCFS(a, n); break;
			case 2:SSTF(a, n); break;
			case 3:SCAN(a, n,0,9); break;//Ĭ����10���ŵ�
			case 4:CSCAN(a, n); break;
			case 5:FSCAN(a, n); break;
			}
		}
	}
	return 0;
}

//����Sour���Ƶ�����Dist�����Ƶ���x����
void CopyL(int Sour[], int Dist[], int x)
{
	int i;
	for (i = 0; i <= x; i++)
	{
		Dist[i] = Sour[i];
	}
}
//����Sour��xλ�õ���ɾ��������yǰ�������ǰ�ƶ���y��������ֲ���(�������2��y) 
void DelInq(int Sour[], int x, int y)
{
	int i;
	for (i = x; i<y; i++)
	{
		Sour[i] = Sour[i + 1];
		x++;
	}
}
//�����ȷ�������㷨(FCFS) 
void  FCFS(int a[], int n) {
	int sum = 0, j, i, first = 0, now;
	cout << "�����뵱ǰ�ŵ��ţ�";
	cin >> now; //ȷ����ǰ��ͷ����λ��
	cout << "���̵���˳��Ϊ��" << endl;
	for (i = 0; i < n; i++)//������˳������ŵ��� 
	{
		cout << a[i] << " ";
	}
	//����sum
	for (i = 0, j = 1; j < n; i++, j++)
	{
		first += abs(a[j] - a[i]); //��Χ�ŵ���������ŵ��ľ���
	}
	sum += first + abs(now - a[0]);
	cout << endl;
	cout << "�ƶ����ܴŵ���Ϊ��" << sum << endl;
	//float ave;
	//ave=
	cout << "ƽ���ƶ�����Ϊ��" << (float)sum / (float)(i + 1) << endl;
}


//����Ѱ��ʱ���㷨 ��SSTF) 
void  SSTF(int  a[], int n) {
	int temp;
	int k = 1;
	int now, l, r;
	int i, j, sum = 0;
	//���ŵ��Ű��������� 
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
	cout << "������˳���źõĴŵ���ʾΪ ��" << endl;
	for (i = 0; i < n; i++)
	{
		cout << a[i] << " "; //����źõĴŵ�˳��
	}
	cout << endl;
	cout << "�����뵱ǰ�Ĵŵ��� ��";
	cin >> now;//ȷ����ǰ��ͷ����λ��
	cout << "���̵���˳��Ϊ:" << endl;
	if (a[n - 1] <= now)//��ǰ��ͷλ�ô�������Χ�����ʴŵ�
	{
		for (i = n - 1; i >= 0; i--)
			cout << a[i] << " ";
		sum = now - a[0];
	}
	else
		if (a[0] >= now)//��ǰ��ͷλ��С�����������ʴŵ�
		{
			for (i = 0; i < n; i++)
				cout << a[i] << " ";
			sum = a[n - 1] - now;
		}
		else
		{
			while (a[k] < now)//ȷ����ǰ�ŵ��ڼ��ŵ������е�λ��
			{
				k++;
			}
			l = k - 1;//�ڴ�ͷλ�õ�ǰһ�������ʴŵ�
			r = k; //��ͷ�����ʴŵ�
			while ((l >= 0) && (r < n))
			{
				if ((now - a[l]) <= (a[r] - now))//ѡ�����ͷ���Ĵŵ�
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
			if (l = -1)//��ͷλ�����Ĵŵ��������� 
			{
				for (j = r; j < n; j++)//���ʴ�ͷλ�����Ĵŵ�
				{
					cout << a[j] << " ";
				}
				sum += a[n - 1] - a[0];
			}
			if (r == n)//��ͷλ�����Ĵŵ��������� 
			{
				for (j = k - 1; j > -1; j--)//���ʴ�ͷλ�����Ĵŵ�
				{
					cout << a[j] << " ";
				}
				sum += a[n - 1] - a[0];
			}
		}
	cout << endl;
	cout << "�ƶ����ܵ���Ϊ ��" << sum << endl;
	cout << "ƽ���ƶ�����Ϊ��" << (float)sum / (float)i << endl;
}

int NAll = 0;
int Best[5][2]; //����Ѱ�������ɵ͵�������ʱ��ŵ����� 
int Jage;
float Aver = 0;
// ɨ���㷨(SCAN)
int SCAN(int DiscL[], int Han, int x, int y)
{
	int j, n, k, h, m, All;
	int t = 0;
	int Temp;
	int Min;
	int RLine[10]; //��������ɵĴŵ�������Discl[]���Ƹ�����RLine[] 
	int Order;
	Order = 1;
	k = y;
	m = 2;  //����while����ִ�У�����һ��Ҫʹ��ǰ�ŵ��������ⶼҪɨ�赽
	All = 0;  //ͳ��ȫ���Ĵŵ�������
	CopyL(DiscL, RLine, 9);  //���ƴŵ��ŵ���ʱ����RLine
	cout<<"����SCAN�㷨�ŵ��ķ���˳��Ϊ:"<<endl;
	Min = 64000;
	for (j = x; j <= y; j++)  //Ѱ���뵱ǰ�ŵ������Ѱ����ʱ��Ĵŵ���
	{
		if (RLine[j]>Han)  //�����һ��������ɵĴŵ��Ŵ��ڵ�ǰ�Ĵŵ��ţ�ִ����һ��
			Temp = RLine[j] - Han;  //�����ʱ���ƶ�����
		else
			Temp = Han - RLine[j];  //�����ʱ���ƶ�����
		if (Temp<Min)
		{
			Min = Temp;  //Temp��ʱֵ����Min
			h = j;   //�������ǰ�ŵ��ŵ������±긳��h
		}
	}
	All = All + Min;
	cout<<RLine[h];
	if (RLine[h] >= Han) {  //�жϴŵ����ƶ����򣬼����������⻹����������
		Order = 0;
		t = 1;
	}
	Han = RLine[h];
	DelInq(RLine, h, k);  //ÿ���ŵ�����ǰ�ƶ�һλ
	k--;
	while (m>0)
	{
		if (Order == 1)  //order���жϴ���ɨ��ķ����ǩ��order��1�Ļ����ŵ������ƶ�
		{
			for (j = x; j <= y; j++)
			{
				h = -1;
				Min = 64000;
				for (n = x; n <= k; n++)  //�ж��뵱ǰ�ŵ�����Ĵŵ���
				{
					if (RLine[n] <= Han)
					{
						Temp = Han - RLine[n];
						if (Temp<Min)
						{
							Min = Temp;  //Temp��ʱֵ����Min
							h = n;  //�������ǰ�ŵ��ŵ������±긳��h
						}
					}
				}
				if (h != -1)
				{
					All = All + Min;  //�����ƶ�����
					cout<<"  "<<RLine[h];
					Han = RLine[h]; //����Ĵŵ�����Ϊ��ǰ�ŵ�
					DelInq(RLine, h, k);
					k--;
				}
			}
			Order = 0;  //��������ڵ��ƶ���order����0��ִ��else��䣬ʹ�ŵ������ƶ�
			m--;  //�������һ�Σ�m��һ�Σ���֤whileѭ��ִ������
		}
		else  //order��0�Ļ����ŵ������ƶ�
		{
			for (j = x; j <= y; j++)
			{
				h = -1;
				Min = 64000;
				for (n = x; n <= k; n++)  //�ж��뵱ǰ�ŵ�����Ĵŵ���
				{
					if (RLine[n] >= Han)
					{
						Temp = RLine[n] - Han;
						if (Temp<Min)
						{
							Min = Temp;   //Temp��ʱֵ����Min
							h = n;  //�������ǰ�ŵ��ŵ������±긳��h
						}
					}
				}
				if (h != -1)
				{
					All = All + Min;  //�����ƶ�����
					cout << "  " << RLine[h];
					Han = RLine[h];  //����Ĵŵ�����Ϊ��ǰ�ŵ�
					DelInq(RLine, h, k);
					k--;
				}
			}
			Order = 1;  //��������ڵ��ƶ���order����0��ִ��else��䣬ʹ�ŵ������ƶ�
			m--;   //�������һ�Σ�m��һ�Σ���֤whileѭ��ִ������
		}
	}
	NAll = NAll + All;
	if ((y - x)>5)
	{
		Best[Jage][1] = All;//Best[][1]����ƶ��ŵ��� 
		Best[Jage][0] = 3;//Best[][0]����㷨�����Ϊ:3
		Jage++;//������ż�1
		Aver = ((float)All) / 10;//��ƽ��Ѱ������ 
		cout << endl << "�ƶ��ŵ���:" << All;
		cout << endl << "ƽ��Ѱ������:"<<Aver;
	}
	if (t == 1) cout<<endl<<"�ŵ����������ƶ�";
	else cout<<endl<<"�ŵ����������ƶ�";
	return(Han);
}
//ѭ��ɨ���㷨(CSCAN)
void CSCAN(int DiscL[], int Han)
{
	int j, h, n, Temp, m, k, All, Last, i;
	int RLine[10];  //��������ɵĴŵ�������Discl[]���Ƹ�����RLine[] 
	int Min;
	int tmp = 0;
	m = 2;
	k = 9;
	All = 0;   //ͳ��ȫ���Ĵŵ�������
	Last = Han;
	CopyL(DiscL, RLine, 9);  //���ƴŵ��ŵ���ʱ����RLine
	cout<<"����CSCAN�㷨�ŵ��ķ���˳��Ϊ:"<<endl;
	while (k >= 0)
	{
		for (j = 0; j <= 9; j++)  //�ӵ�ǰ�ŵ��ſ�ʼ���������������뵱ǰ�ŵ�����Ĵŵ���
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
				All = All + Min;  //ͳ��һ���ƶ��ľ���
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
			for (i = 0; i<k; i++)//���ʣ�´ŵ��ŵ���Сֵ
			{
				if (tmp>RLine[i]) tmp = RLine[i];
			}
			Han = tmp;//����С�Ĵŵ��Ÿ���Han
			Temp = Last - tmp;//������ŵ��ź���С�ŵ��ŵľ����
			All = All + Temp;
		}
	}
	Best[Jage][1] = All;//Best[][1]����ƶ��ŵ��� 
	Best[Jage][0] = 4;//Best[][0]����㷨�����Ϊ:4
	Jage++;//������ż�1
	Aver = ((float)All) / 10;//��ƽ��Ѱ������ 
	cout << endl << "�ƶ��ŵ���:" << All;
	cout << endl << "ƽ��Ѱ������: " << Aver;
}
//N��ɨ���㷨(NStepScan)
void FSCAN(int DiscL[], int Han1)
{
	int i, m, k;
	int RLine1[10];
	NAll = 0;
	m = 2;
	k = 9;  //�޶�10���Ĵŵ���  
	i = -1;
	CopyL(DiscL, RLine1, 9);  //���ƴŵ��ŵ���ʱ����RLine
	cout<<endl<<"����FSCAN�㷨�ŵ��ķ���˳��Ϊ:";
	for (m = 0; m < 2; m++)  //�����޶�10�ŵ�������10���ŵ�����Ϊ���飬ÿ��5���ŵ�����ÿ���鰴��SCAN�㷨ִ�У���ѭ��ѭ��2��
	{
		Han1 = SCAN(RLine1, Han1, i + 1, i + 5);
		i = i + 5;
	}
	Best[Jage][1] = NAll;//Best[][1]����ƶ��ŵ��� 
	Best[Jage][0] = 5;//Best[][0]����㷨�����Ϊ:5
	Aver = ((float)NAll) / 10;//��ƽ��Ѱ������ 
	cout<<endl<<"�ƶ��ŵ���:"<< NAll;
	cout<<endl<< "ƽ��Ѱ������: "<<Aver;

}