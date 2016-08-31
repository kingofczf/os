#include<iostream>
#include<ctime>
#include<time.h>
#include<stdio.h>
using namespace std;

time_t rawtime;
struct tm * timeinfo;

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
			case 3:SCAN(a, n,0,n); break;//Ĭ����10���ŵ�
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
	FILE *fp;
	fp = fopen("cipan.txt", "a");//aΪ׷�����
	if(!fp)
	{
		strcat("cipan", ".txt");
		fp = fopen("cipan.txt", "w");//д
	}
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	fprintf(fp, "��ǰʱ��Ϊ: %s", asctime(timeinfo));
	fprintf(fp, "��ǰ�Ĵ��̵��ȷ�ʽΪFIFO,������������Ϊ:\n");
	for (int num = 0; num < n; num++)
	{
		fprintf(fp,"%d%s",a[num]," ");
	}
	fprintf(fp,"\n");
	int sum = 0, j, i, first = 0, now;
	cout << "�����뵱ǰ�ŵ��ţ�";
	cin >> now; //ȷ����ǰ��ͷ����λ��
	fprintf(fp, "��ǰ�ŵ���:%d\n",now);
	cout << "���̵���˳��Ϊ:" << endl;
	fprintf(fp, "���̵���˳��Ϊ:\n");
	for (i = 0; i < n; i++)//������˳������ŵ��� 
	{
		cout << a[i] << " ";
		fprintf(fp, "%d%s",a[i]," ");
	}
	//����sum
	for (i = 0, j = 1; j < n; i++, j++)
	{
		first += abs(a[j] - a[i]); //��Χ�ŵ���������ŵ��ľ���
	}
	sum += first + abs(now - a[0]);
	cout << endl;
	fprintf(fp,"\n");
	cout << "�ƶ����ܴŵ���Ϊ��" << sum << endl;
	fprintf(fp, "�ƶ����ܴŵ���Ϊ:%d\n",sum);
	cout << "ƽ���ƶ�����Ϊ��" << (float)sum / (float)(i + 1) << endl;
	fprintf(fp,"ƽ���ƶ�����Ϊ��%f\n", (float)sum/ (float)(i + 1)); 
	fprintf(fp, "\n");
	fclose(fp);
}


//����Ѱ��ʱ���㷨 ��SSTF) 
void  SSTF(int  a[], int n) {
	FILE *fp;
	fp = fopen("cipan.txt", "a");//aΪ׷�����
	if (!fp)
	{
		strcat("cipan", ".txt");
		fp = fopen("cipan.txt", "w");//д
	}
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	fprintf(fp, "��ǰʱ��Ϊ: %s", asctime(timeinfo));
	fprintf(fp, "��ǰ�Ĵ��̵��ȷ�ʽΪSSTF,������������Ϊ:\n");
	for (int num = 0; num < n; num++)
	{
		fprintf(fp, "%d%s", a[num], " ");
	}
	fprintf(fp, "\n");
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
	fprintf(fp, "������˳���źõĴŵ���ʾΪ ��:\n");
	for (i = 0; i < n; i++)
	{
		cout << a[i] << " "; //����źõĴŵ�˳��
		fprintf(fp, "%d%s",a[i]," ");
	}
	cout << endl;
	fprintf(fp, "\n");
	cout << "�����뵱ǰ�Ĵŵ��� ��";
	cin >> now;//ȷ����ǰ��ͷ����λ��
	fprintf(fp, "��ǰ�ŵ��ţ�%d",now);
	cout << "���̵���˳��Ϊ:" << endl;
	fprintf(fp, "�����̵���˳��Ϊ:");
	if (a[n - 1] <= now)//��ǰ��ͷλ�ô�������Χ�����ʴŵ�
	{
		for (i = n - 1; i >= 0; i--)
		{
			cout << a[i] << " ";
			fprintf(fp,"%d%s",a[i]," ");
		}
		sum = now - a[0];
	}
	else
		if (a[0] >= now)//��ǰ��ͷλ��С�����������ʴŵ�
		{
			for (i = 0; i < n; i++)
			{
				cout << a[i] << " ";
				fprintf(fp, "%d%s", a[i], " ");
			}
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
					fprintf(fp, "%d%s", a[l], " ");
					sum += now - a[l];
					now = a[l];
					l = l - 1;
				}
				else
				{
					cout << a[r] << " ";
					fprintf(fp, "%d%s", a[r], " ");
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
					fprintf(fp, "%d%s", a[j], " ");
				}
				sum += a[n - 1] - a[0];
			}
			if (r == n)//��ͷλ�����Ĵŵ��������� 
			{
				for (j = k - 1; j > -1; j--)//���ʴ�ͷλ�����Ĵŵ�
				{
					cout << a[j] << " ";
					fprintf(fp, "%d%s", a[j], " ");
				}
				sum += a[n - 1] - a[0];
			}
		}
	cout << endl;
	fprintf(fp, "\n");
	cout << "�ƶ����ܵ���Ϊ ��" << sum << endl;
	cout << "ƽ���ƶ�����Ϊ��" << (float)sum / (float)i << endl;
	fprintf(fp, "�ƶ����ܵ���Ϊ ��%d\n",sum);
	fprintf(fp, "ƽ���ƶ�����Ϊ��%f\n", (float)sum / (float)i);
	fprintf(fp, "\n");
	fclose(fp);
}

int NAll = 0;
// ɨ���㷨(SCAN)
int SCAN(int a[],int n, int x, int y)
{
	FILE *fp;
		fp = fopen("cipan.txt", "a");//aΪ׷�����
	if (!fp)
	{
		
		
			strcat("cipan", ".txt");
			fp = fopen("cipan.txt", "w");//д
		
	}
		time(&rawtime);
		timeinfo = localtime(&rawtime);
		fprintf(fp, "��ǰʱ��Ϊ: %s", asctime(timeinfo));
		fprintf(fp, "��ǰ�Ĵ��̵��ȷ�ʽΪSCAN,������������Ϊ:\n");
		for (int num = 0; num < n; num++)
		{
			fprintf(fp, "%d%s", a[num], " ");
		}
		fprintf(fp, "\n");
		int sum = 0, now;
		cout << "�����뵱ǰ�ŵ��ţ�";
		cin >> now; //ȷ����ǰ��ͷ����λ��
		fprintf(fp, "��ǰ��ͷλ��Ϊ: %d", now);
	int j, l, k, h, m, All;
	int t = 0;
	int Temp;
	int Min;
	int b[100]; //��������ɵĴŵ�������a[]���Ƹ�����b[] 
	int Order;
	Order = 1;
	k = y;
	m = 2;  //����while����ִ�У�����һ��Ҫʹ��ǰ�ŵ��������ⶼҪɨ�赽
	All = 0;  //ͳ��ȫ���Ĵŵ�������
	CopyL(a, b, n);  //���ƴŵ��ŵ���ʱ����b
	cout << "���뵱ǰ��ͷ���ƶ�����,0Ϊ���⣬1Ϊ����" << endl;
	{
		cin >> Order;
		if (Order == 0)t = 1;
		else t = 0;
	}
	cout<<"����SCAN�㷨�ŵ��ķ���˳��Ϊ:"<<endl;
	fprintf(fp, "����SCAN�㷨�ŵ��ķ���˳��Ϊ:\n");
	Min = 64000;
	int Max = 65535;
	if (Order == 1) {
		for (j = x; j <= y; j++)  //Ѱ���뵱ǰ�ŵ������Ѱ����ʱ��Ĵŵ���
		{
			if (b[j] > now&&Order == 1)  //�����һ��������ɵĴŵ��Ŵ��ڵ�ǰ�Ĵŵ��ţ�ִ����һ��
				Temp = b[j] - now;  //�����ʱ���ƶ�����
			else
				Temp = now - b[j];  //�����ʱ���ƶ�����
			if (Temp < Min)
			{
				Min = Temp;  //Temp��ʱֵ����Min
				h = j;   //�������ǰ�ŵ��ŵ������±긳��h
			}
		}
		All = All + Min;
	}
	else  //order��0�Ļ����ŵ������ƶ�
	{
		for (j = x; j <= n; j++)  //Ѱ���뵱ǰ�ŵ������Ѱ����ʱ��Ĵŵ���
		{
			//if (b[j] >= now)  //�����һ��������ɵĴŵ��Ŵ��ڵ�ǰ�Ĵŵ��ţ�ִ����һ��
				//Temp = b[j] - now;  //�����ʱ���ƶ�����
			//else
				Temp = b[j] - now;
			if (Temp >= 0&&Temp<=Max)
			{
				Max = Temp;  //Temp��ʱֵ����Min
				h = j;   //�������ǰ�ŵ��ŵ������±긳��h
			}
		}
		All = All - Max;
	}

	cout<<b[h];
		fprintf(fp, "%d",b[h]);
	/*(if (b[h] >= now) {  //�жϴŵ����ƶ����򣬼����������⻹����������
		Order = 0;
		t = 1;
	}*/
		//�ŵ��ƶ�����

	now = b[h];
	DelInq(b, h, k);  //ÿ���ŵ�����ǰ�ƶ�һλ
	k--;
	while (m>0)
	{
		if (Order == 1)  //order���жϴ���ɨ��ķ����ǩ��order��1�Ļ����ŵ������ƶ�
		{
			for (j = x; j <= y; j++)
			{
				h = -1;
				Min = 64000;
				for (l = x; l <= k; l++)  //�ж��뵱ǰ�ŵ�����Ĵŵ���
				{
					if (b[l] <= now)
					{
						Temp = now - b[l];
						if (Temp<Min)
						{
							Min = Temp;  //Temp��ʱֵ����Min
							h = l;  //�������ǰ�ŵ��ŵ������±긳��h
						}
					}
				}
				if (h != -1&&b[h]!=-1)
				{
					All = All + Min;  //�����ƶ�����
					cout<<"  "<<b[h];
						fprintf(fp, "%s%d", " ",b[h]);
					now = b[h]; //����Ĵŵ�����Ϊ��ǰ�ŵ�
					DelInq(b, h, k);
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
				for (l = x; l <= k; l++)  //�ж��뵱ǰ�ŵ�����Ĵŵ���
				{
					if (b[l] >= now)
					{
						Temp = b[l] - now;
						if (Temp<Min)
						{
							Min = Temp;   //Temp��ʱֵ����Min
							h = l;  //�������ǰ�ŵ��ŵ������±긳��h
						}
					}
				}
				if (h != -1 && b[h] != -1)
				{
					All = All + Min;  //�����ƶ�����
					cout << "  " << b[h];
						fprintf(fp, "%s%d:", " ", b[h]);
					now = b[h];  //����Ĵŵ�����Ϊ��ǰ�ŵ�
					DelInq(b, h, k);
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
		cout << endl << "�ƶ��ŵ���:" << All;
		cout << endl << "ƽ��Ѱ������:"<< (float)All /n;

			fprintf(fp, "\n�ƶ��ŵ���:%d:", All);
			fprintf(fp, "\nƽ��Ѱ������:%f:", (float)All /n);
		
	}
	if (t == 1) {
		cout << endl << "�ŵ����������ƶ�";
fprintf(fp, "�ŵ����������ƶ�");
	}
	else
	{
		cout << endl << "�ŵ����������ƶ�";
	fprintf(fp, "�ŵ����������ƶ�");

	}
	fprintf(fp, "\n");
fclose(fp);
	return(n);
}
//ѭ��ɨ���㷨(CSCAN)
void CSCAN(int a[], int n)
{
	int sn = n;
	FILE *fp;
	fp = fopen("cipan.txt", "a");//aΪ׷�����
	if (!fp)
	{
		strcat("cipan", ".txt");
		fp = fopen("cipan.txt", "w");//д
	}
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	fprintf(fp, "��ǰʱ��Ϊ: %s", asctime(timeinfo));
	fprintf(fp, "��ǰ�Ĵ��̵��ȷ�ʽΪCSCAN,������������Ϊ:\n");
	for (int num = 0; num < n; num++)
	{
		fprintf(fp, "%d%s", a[num], " ");
	}
	fprintf(fp, "\n");
	int sum = 0, now;
	cout << "�����뵱ǰ�ŵ��ţ�";
	cin >> now; //ȷ����ǰ��ͷ����λ��
	fprintf(fp, "��ǰ��ͷλ��Ϊ: %d", now);
	int j, h, l, Temp, m, k, All, Last, i;
	int b[100];  //��������ɵĴŵ�������a[]���Ƹ�����b[] 
	int Min;
	int tmp = 0;
	m = 2;
	k = 9;
	All = 0;   //ͳ��ȫ���Ĵŵ�������
	Last = now;
	CopyL(a, b, 9);  //���ƴŵ��ŵ���ʱ����b
	cout<<"����CSCAN�㷨�ŵ��ķ���˳��Ϊ:"<<endl;
	fprintf(fp, "����CSCAN�㷨�ŵ��ķ���˳��Ϊ:\n");
	while (k >= 0)
	{
		for (j = 0; j <= 9; j++)  //�ӵ�ǰ�ŵ��ſ�ʼ���������������뵱ǰ�ŵ�����Ĵŵ���
		{
			h = -1;
			Min = 64000;
			for (l = 0; l <= k; l++)
			{
				if (b[l] >= now)
				{
					Temp = b[l] - now;
					if (Temp<Min)
					{
						Min = Temp;
						h = l;
					}
				}
			}
			if (h != -1)
			{
				All = All + Min;  //ͳ��һ���ƶ��ľ���
				cout << "  " << b[h];
				fprintf(fp, "%s%d"," ",b[h]);
				now = b[h];
				Last = b[h];
				DelInq(b, h, k);
				k--;
			}
		}
		if (k >= 0)
		{
			tmp = b[0];
			for (i = 0; i<k; i++)//���ʣ�´ŵ��ŵ���Сֵ
			{
				if (tmp>b[i]) tmp = b[i];
			}
			now = tmp;//����С�Ĵŵ��Ÿ���now
			Temp = Last - tmp;//������ŵ��ź���С�ŵ��ŵľ����
			All = All + Temp;
		}
	}
	cout << endl << "�ƶ��ŵ���:" << All;
	cout << endl << "ƽ��Ѱ������: " << ((float)All) / sn;
	fprintf(fp, "\n�ƶ��ŵ���%d", All);
	fprintf(fp, "\nƽ��Ѱ������%f", (float)All / sn);
	fprintf(fp, "\n");
	fclose(fp);
}
//N��ɨ���㷨(NStepScan)
void FSCAN(int a[], int n)
{
	int sn = n;
	FILE *fp;
	fp = fopen("cipan.txt", "a");//aΪ׷�����
	if (!fp)
	{
		strcat("cipan", ".txt");
		fp = fopen("cipan.t                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              xt", "w");//д
	}
	fprintf(fp, "��ǰ�Ĵ��̵��ȷ�ʽΪFSCAN,������������Ϊ:\n");
	for (int num = 0; num < n; num++)
	{
		fprintf(fp, "%d%s", a[num], " ");
	}
	fprintf(fp, "\n");
	int sum = 0, now;
	cout << "�����뵱ǰ�ŵ��ţ�";
	cin >> now; //ȷ����ǰ��ͷ����λ��
	fprintf(fp, "��ǰ��ͷλ��Ϊ: %d", now);
	int i, m, k;
	int b[10];
	NAll = 0;
	m = 2;
	k = 9;  //�޶�10���Ĵŵ���  
	i = -1;
	CopyL(a, b, 9);  //���ƴŵ��ŵ���ʱ����RLine
	cout<<endl<<"����FSCAN�㷨�ŵ��ķ���˳��Ϊ:";
	fprintf(fp, "\n����FSCAN�㷨�ŵ��ķ���˳��Ϊ:");
	for (m = 0; m < 2; m++)  //�����޶�10�ŵ�������10���ŵ�����Ϊ���飬ÿ��5���ŵ�����ÿ���鰴��SCAN�㷨ִ�У���ѭ��ѭ��2��
	{
		now = SCAN(b, now, i + 1, i + 5);
		i = i + 5;
	}
	cout<<endl<<"�ƶ��ŵ���:"<< NAll;
	cout<<endl<< "ƽ��Ѱ������: "<<((float)NAll)/10;
	fprintf(fp, "\n�ƶ��ŵ���:%d", NAll);
	fprintf(fp, "\nƽ��Ѱ������:%f", (float)NAll/10);
	fprintf(fp, "\n");
	fclose(fp);

}