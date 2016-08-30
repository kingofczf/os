
#include<iostream>
#include<time.h>
#include<string>
#include<list>
using namespace std;
static int num;
static int chooseNum;
static int seq[];

int fifosum = 0;
int sstfsum = 0;
int fifosumN = 0;//平均寻道距离
int sstfsumN = 0;

string fifoseq = "";
string sstfseq = "";
string scanseq = "";
string scanseq_mini = "";
string cscanseq = "";
string fscanseq = "";
string fscanseq1 = "";
string fscanseq2 = "";
int scansum = 0;
int scansum_mini = 0;
int cscansum = 0;
int fscansum = 0;
int fscansum1 = 0;
int fscansum2 = 0;

int scansumN = 0;//平均寻道距离
int scansum_miniN = 0;
int cscansumN = 0;
int fscansumN = 0;
int fscansum1N = 0;
int fscansum2N = 0;

list<int> resultofSCAN;//在resultofSCAN里面放的是Integer类型数值
list<int> resultofCSCAN;
list<int> resultofFCSCAN;
list<int> resultofSCAN_mini;

list<int> distanceofSCAN;//ArrayList动态数组
list<int> distanceofSCAN_mini;
list<int> distanceofCSCAN;

list<int> temp;
list<int> seqArrayList;

class  diaodu {
	disk_scheduling();
}


 void disk_scheduling() {

		 void actionPerformed(ActionEvent arg0) {
		// TODO Auto-generated method stub
		//生成随机序列
		String choose = jTextField7.getText();
		chooseNum = Integer.parseInt(choose);
		String numget = jTextField1.getText();
		num = Integer.parseInt(numget);
		seq = new int[num];
		for (int i = 0; i<num; i++)
		{
			double s;
			s = Math.random() * 200;//产生0~1之间的任意小数，然后*200
			seq[i] = (int)s;//seq[]里面存放随机序列
		}
		String seq_str = "";
		for (int i = 0; i<num; i++) {
			seq_str = seq_str + String.valueOf(seq[i]) + " ";
		}
		((JTextArea)jTextArea1).setLineWrap(true);//当行长度大于所分配的宽度时，换行
		((JTextArea)jTextArea1).setText(seq_str);//把随机序列插入到jTextArea1

		int array = 0;

		while (seqArrayList.size()<num)
		{
			seqArrayList.add(seq[array]);
			temp.add(seq[array]);
			array++;
		}
		Collections.sort(temp);//对temp数组的自然序列排序
							   //调度算法				

		((JTextArea)jTextArea2).setLineWrap(true);
		String fifoString = String.valueOf(fifosum) + "      " + String.valueOf(fifosumN);
		((JTextField)jTextField2).setText(fifoString);
		String sstfString = String.valueOf(sstfsum + "      " + String.valueOf(sstfsumN));
		((JTextField)jTextField3).setText(sstfString);

		String scanString = String.valueOf(scansum + "      " + String.valueOf(scansumN));
		((JTextField)jTextField4).setText(scanString);

		String cscanString = String.valueOf(cscansum + "      " + String.valueOf(cscansumN));
		((JTextField)jTextField5).setText(cscanString);

		String fscanString = String.valueOf(fscansum + "      " + String.valueOf(fscansumN));
		((JTextField)jTextField6).setText(fscanString);
		switch (chooseNum)
		{
		case 1:
		{
			new Thread()
			{
				public void run()
			{
				fifo();
			}
			}.start();
			break;
		}
		case 2:
		{
			new Thread()
			{
				public void run()
			{
				sstf();
			}
			}.start();
			break;
		}
		case 3:
		{
			new Thread()
			{
				public void run()
			{
				scan();
			}
			}.start();

			break;
		}
		case 4:
		{
			new Thread()
			{
				public void run()
			{
				cscan();
			}
			}.start();

			break;
		}
		case 5:
		{
			new Thread()
			{
				public void run()
			{
				fscan();
			}
			}.start();

			break;
		}
		default:break;
		}
		//移动磁道数



	}

	private void cscan() { //循环扫描算法
		int position = 0;
		int start = 100;
		for (int i = 0; i < temp.size(); i++)
		{
			if (temp.get(i)<start)
			{
				position = i;
				continue;
			}
			else
			{
				resultofCSCAN.add(temp.get(i).intValue());
			}
		}

		for (int i = 0; i <= position; i++)
		{
			resultofCSCAN.add(temp.get(i).intValue());
		}

		for (int i = 0; i < resultofCSCAN.size(); i++)
		{
			cscanseq = cscanseq + resultofCSCAN.get(i).intValue() + " ";
			((JTextArea)jTextArea2).setText(((JTextArea)jTextArea2).getText() + " " + cscanseq + "\n");
			try
			{
				Thread.sleep(1500);
			}
			catch (InterruptedException e)
			{
			}
		}
		//长度
		distanceofCSCAN.add(Math.abs(start - resultofCSCAN.get(0).intValue()));
		for (int i = 1; i <num; i++)
		{
			distanceofCSCAN.add(Math.abs(resultofCSCAN.get(i).intValue() - resultofCSCAN.get(i - 1).intValue()));

		}
		for (int i = 0; i <num; i++)
		{
			cscansum += distanceofCSCAN.get(i).intValue();
		}
		cscansumN = cscansum / num;
		String fifoString = String.valueOf(fifosum) + "      " + String.valueOf(fifosumN);
		((JTextField)jTextField2).setText(fifoString);
		String sstfString = String.valueOf(sstfsum + "      " + String.valueOf(sstfsumN));
		((JTextField)jTextField3).setText(sstfString);

		String scanString = String.valueOf(scansum + "      " + String.valueOf(scansumN));
		((JTextField)jTextField4).setText(scanString);

		String cscanString = String.valueOf(cscansum + "      " + String.valueOf(cscansumN));
		((JTextField)jTextField5).setText(cscanString);

		String fscanString = String.valueOf(fscansum + "      " + String.valueOf(fscansumN));
		((JTextField)jTextField6).setText(fscanString);
	}

	private void scan() {//扫描算法，方向：由里向外
		int start = 100;
		int position = 0;
		for (int i = 0; i < temp.size(); i++)
		{
			if (temp.get(i)<start)
			{
				position = i;
				continue;
			}
			else
			{
				resultofSCAN.add(temp.get(i).intValue());
			}
		}
		for (int i = position; i >= 0; i--) {
			resultofSCAN.add(temp.get(i).intValue());
		}
		for (int i = 0; i < resultofSCAN.size(); i++) {
			scanseq = scanseq + resultofSCAN.get(i).intValue() + " ";
			((JTextArea)jTextArea2).setText(((JTextArea)jTextArea2).getText() + " " + scanseq + "\n");
			try
			{
				Thread.sleep(1500);
			}
			catch (InterruptedException e)
			{
			}
		}
		//横跨磁道数
		distanceofSCAN.add(Math.abs(start - resultofSCAN.get(0).intValue()));
		for (int i = 1; i <num; i++)
		{
			distanceofSCAN.add(Math.abs(resultofSCAN.get(i).intValue() - resultofSCAN.get(i - 1).intValue()));
		}
		for (int i = 0; i <num; i++)
		{
			scansum += distanceofSCAN.get(i).intValue();
		}
		scansumN = scansum / num;
		String fifoString = String.valueOf(fifosum) + "      " + String.valueOf(fifosumN);
		((JTextField)jTextField2).setText(fifoString);
		String sstfString = String.valueOf(sstfsum + "      " + String.valueOf(sstfsumN));
		((JTextField)jTextField3).setText(sstfString);

		String scanString = String.valueOf(scansum + "      " + String.valueOf(scansumN));
		((JTextField)jTextField4).setText(scanString);

		String cscanString = String.valueOf(cscansum + "      " + String.valueOf(cscansumN));
		((JTextField)jTextField5).setText(cscanString);

		String fscanString = String.valueOf(fscansum + "      " + String.valueOf(fscansumN));
		((JTextField)jTextField6).setText(fscanString);
	}

	private void sstf() {//最短寻道时间优先
		int begin = 100;
		int avg = 0;
		int temp = 1000;
		int k = 0;
		int t = num;
		int j = 0;
		int sstf[];
		sstf = new int[num];
		int sstf_disk[];
		sstf_disk = new int[num];
		for (int i = 0; i<num; i++)
		{
			sstf[i] = seq[i];
		}
		while (t>0)
		{
			for (int i = 0; i<num; i++)
			{
				if (sstf[i]>0)
				{
					if (sstf[i]<begin)
					{
						avg = begin - sstf[i];
						if (temp>avg)
						{
							temp = avg;
							k = i;
						}
					}
					else
					{
						avg = sstf[i] - begin;
						if (temp>avg)
						{
							temp = avg;
							k = i;
						}
					}
				}
			}
			sstfseq = sstfseq + (sstf[k] + " ");
			((JTextArea)jTextArea2).setText(((JTextArea)jTextArea2).getText() + " " + sstfseq + "\n");
			try
			{
				Thread.sleep(1500);
			}
			catch (InterruptedException e)
			{
			}
			if (begin>sstf[k])
			{
				sstf_disk[j] = begin - sstf[k];
			}
			else
			{
				sstf_disk[j] = sstf[k] - begin;
			}
			j++;
			begin = sstf[k];
			sstf[k] = -1;
			t--;
			avg = 0;
			k = 0;
			temp = 10000;
		}
		for (int i = 0; i<num; i++)
		{
			sstfsum = sstfsum + sstf_disk[i];
		}
		sstfsumN = sstfsum / num;
		String fifoString = String.valueOf(fifosum) + "      " + String.valueOf(fifosumN);
		((JTextField)jTextField2).setText(fifoString);
		String sstfString = String.valueOf(sstfsum + "      " + String.valueOf(sstfsumN));
		((JTextField)jTextField3).setText(sstfString);

		String scanString = String.valueOf(scansum + "      " + String.valueOf(scansumN));
		((JTextField)jTextField4).setText(scanString);

		String cscanString = String.valueOf(cscansum + "      " + String.valueOf(cscansumN));
		((JTextField)jTextField5).setText(cscanString);

		String fscanString = String.valueOf(fscansum + "      " + String.valueOf(fscansumN));
		((JTextField)jTextField6).setText(fscanString);
	}

	private void fscan()//N-Step-SCAN算法的简化。它只将磁盘请求队列分成两个子队列。			                      
	{                        //队列之间fifo,队列内部scan
		int begin = 100;
		int avg = 0;
		int fscan1[];
		int fscan2[];
		int a = num / 2;
		int b = num - num / 2;
		fscan1 = new int[a];
		fscan2 = new int[b];
		for (int i = 0; i<a; i++)
		{
			fscan1[i] = seq[i];
		}
		scan_mini(fscan1,a);
		for (int i = 0; i < resultofSCAN_mini.size(); i++)
		{
			fscanseq1 = fscanseq1 + resultofSCAN_mini.get(i).intValue() + " ";
			((JTextArea)jTextArea2).setText(((JTextArea)jTextArea2).getText() + " " + fscanseq1 + "\n");
			try
			{
				Thread.sleep(1500);
			}
			catch (InterruptedException e)
			{
			}
		}
		fscansum1 = scansum_mini;
		scansum_mini = 0;//清零
		resultofSCAN_mini.clear();//清零
		for (int i = 0; i<b; i++)
		{
			fscan2[i] = seq[a + i];
		}
		scan_mini(fscan2,b);
		for (int i = 0; i < resultofSCAN_mini.size(); i++)
		{
			fscanseq2 = fscanseq2 + resultofSCAN_mini.get(i).intValue() + " ";
			((JTextArea)jTextArea2).setText(((JTextArea)jTextArea2).getText() + " " + fscanseq2 + "\n");
			try
			{
				Thread.sleep(1500);
			}
			catch (InterruptedException e)
			{
			}
		}
		fscansum2 = scansum_mini;
		fscansum = fscansum1 + fscansum2;
		fscansumN = fscansum / num;
		String fifoString = String.valueOf(fifosum) + "      " + String.valueOf(fifosumN);
		((JTextField)jTextField2).setText(fifoString);
		String sstfString = String.valueOf(sstfsum + "      " + String.valueOf(sstfsumN));
		((JTextField)jTextField3).setText(sstfString);

		String scanString = String.valueOf(scansum + "      " + String.valueOf(scansumN));
		((JTextField)jTextField4).setText(scanString);

		String cscanString = String.valueOf(cscansum + "      " + String.valueOf(cscansumN));
		((JTextField)jTextField5).setText(cscanString);

		String fscanString = String.valueOf(fscansum + "      " + String.valueOf(fscansumN));
		((JTextField)jTextField6).setText(fscanString);
	}
	private void scan_mini(int a[],int n)
	{
		Arrays.sort(a);
		int start = 100;
		int position = 0;
		if (a[0] >= start)
		{
			for (int i = 0; i < n; i++)
				resultofSCAN_mini.add(a[i]);
		}
		else if (a[0] <= start)
		{
			for (int i = n - 1; i >= 0; i--)
				resultofSCAN_mini.add(a[i]);
		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				if (a[i] < start)
					position = i;
				break;
			}
			for (int i = position; i < n; i++)
			{
				resultofSCAN_mini.add(a[i]);
			}
			for (int i = position; i >= 0; i--)
			{
				resultofSCAN_mini.add(a[i]);
			}
		}
		for (int i = 0; i < resultofSCAN_mini.size(); i++)
		{
			scanseq_mini = scanseq_mini + resultofSCAN_mini.get(i).intValue() + " ";
		}
		//横跨磁道数
		distanceofSCAN_mini.add(Math.abs(start - resultofSCAN_mini.get(0).intValue()));
		for (int i = 1; i <n; i++)
		{
			distanceofSCAN_mini.add(Math.abs(resultofSCAN_mini.get(i).intValue() - resultofSCAN_mini.get(i - 1).intValue()));
		}
		for (int i = 0; i <n; i++)
		{
			scansum_mini += distanceofSCAN_mini.get(i).intValue();
		}
	}

	private void fifo() {
		// TODO Auto-generated method stub
		int begin = 100;
		int avg = 0;
		int fifo[];
		fifo = new int[num];
		for (int i = 0; i<num; i++) {
			fifo[i] = seq[i];
			fifoseq = fifoseq + String.valueOf(seq[i]) + " ";
			((JTextArea)jTextArea2).setText(((JTextArea)jTextArea2).getText() + " " + fifoseq + "\n");
			try
			{
				Thread.sleep(1500);
			}
			catch (InterruptedException e)
			{
			}

		}
		for (int i = 0; i<num; i++) {
			if (fifo[i]<begin) {
				avg = begin - fifo[i];
			}
			else {
				avg = fifo[i] - begin;
			}
			begin = fifo[i];
			fifosum = fifosum + avg;
			fifosumN = fifosum / num;
		}
		String fifoString = String.valueOf(fifosum) + "      " + String.valueOf(fifosumN);
		((JTextField)jTextField2).setText(fifoString);
		String sstfString = String.valueOf(sstfsum + "      " + String.valueOf(sstfsumN));
		((JTextField)jTextField3).setText(sstfString);

		String scanString = String.valueOf(scansum + "      " + String.valueOf(scansumN));
		((JTextField)jTextField4).setText(scanString);

		String cscanString = String.valueOf(cscansum + "      " + String.valueOf(cscansumN));
		((JTextField)jTextField5).setText(cscanString);

		String fscanString = String.valueOf(fscansum + "      " + String.valueOf(fscansumN));
		((JTextField)jTextField6).setText(fscanString);
	}
	});
	jButton2.addActionListener(new ActionListener(){//按钮“重置”
		public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		jTextField1.setText("");
		((JTextArea)jTextArea1).setText("");
		((JTextArea)jTextArea2).setText("");
		jTextField2.setText("");
		jTextField3.setText("");
		jTextField4.setText("");
		jTextField5.setText("");
		jTextField6.setText("");
		jTextField7.setText("");
		fifosum = 0;
		fscansum = 0;
		sstfsum = 0;
		scansum = 0;
		scansum_mini = 0;
		cscansum = 0;
		chooseNum = 0;
		sstfseq = "";

		fifosum = 0;
		sstfsum = 0;
		fifosumN = 0;//平均寻道距离
		sstfsumN = 0;

		sstfseq = "";
		scanseq = "";
		scanseq_mini = "";
		cscanseq = "";
		fscanseq = "";
		fscanseq1 = "";
		fscanseq2 = "";

		scansum = 0;
		scansum_mini = 0;
		cscansum = 0;
		fscansum = 0;
		fscansum1 = 0;
		fscansum2 = 0;

		scansumN = 0;//平均寻道距离
		scansum_miniN = 0;
		cscansumN = 0;
		fscansumN = 0;
		fscansum1N = 0;
		fscansum2N = 0;

		resultofSCAN.clear();
		resultofCSCAN.clear();
		resultofFCSCAN.clear();
		resultofSCAN_mini.clear();
	}
	});
}

private void initGUI() {
	try {
		setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
		this.setName("frame1");
		this.setTitle("\u78c1\u76d8\u8c03\u5ea6");//磁盘调度
		{
			jPanel1 = new JPanel();
			getContentPane().add(jPanel1, BorderLayout.CENTER);
			jPanel1.setPreferredSize(new java.awt.Dimension(439, 679));//设置此组件的首选大小 439 679
			{
				jLabel1 = new JLabel();
				jPanel1.add(jLabel1);
				jLabel1.setText("\u8bf7\u8f93\u5165\u5e8f\u5217\u957f\u5ea6\uff1a");//请输入序列长度：
				jLabel1.setPreferredSize(new java.awt.Dimension(108, 15));//108 15
			}
			{
				jTextField1 = new JTextField();
				jPanel1.add(jTextField1);
				jTextField1.setPreferredSize(new java.awt.Dimension(91, 22));//91
			}
			{
				jLabel10 = new JLabel();
				jPanel1.add(jLabel10);
				jLabel10.setText("\u8bf7\u9009\u62e9\u8c03\u5ea6\u7b97\u6cd5\uff1a");//请输入序列长度：
				jLabel10.setPreferredSize(new java.awt.Dimension(108, 15));//108 15
			}
			{
				jTextField7 = new JTextField();
				jPanel1.add(jTextField7);
				jTextField7.setPreferredSize(new java.awt.Dimension(91, 22));//91
			}
			{
				jButton1 = new JButton();
				jPanel1.add(jButton1);
				jButton1.setText("\u5f00\u59cb");//开始
				jButton1.setPreferredSize(new java.awt.Dimension(91, 22));
			}
			{
				jButton2 = new JButton();
				jPanel1.add(jButton2);
				jButton2.setText("\u91cd\u7f6e");//重置
				jButton2.setPreferredSize(new java.awt.Dimension(84, 22));
			}
			{
				jLabel2 = new JLabel();
				jPanel1.add(jLabel2);
				jLabel2.setText("\u8bf7\u6c42\u5e8f\u5217\uff1a");//请求序列：
				jLabel2.setPreferredSize(new java.awt.Dimension(366, 15));//366
			}
			{
				jScrollPane1 = new JScrollPane();
				jPanel1.add(jScrollPane1);
				jScrollPane1.setPreferredSize(new java.awt.Dimension(365, 133));
				{
					jTextArea1 = new JTextArea();
					jScrollPane1.setViewportView(jTextArea1);
					jTextArea1.setPreferredSize(new java.awt.Dimension(434, 239));
				}
			}
			{
				jLabel3 = new JLabel();
				jPanel1.add(jLabel3);
				jLabel3.setText("\u670d\u52a1\u5e8f\u5217\uff1a(\u8d77\u59cb\u78c1\u9053\u4e3a100)");//服务序列：(起始磁道为100)
				jLabel3.setPreferredSize(new java.awt.Dimension(370, 15));
			}
			{
				jScrollPane2 = new JScrollPane();
				jPanel1.add(jScrollPane2);
				jScrollPane2.setPreferredSize(new java.awt.Dimension(367, 150));
				{
					jTextArea2 = new JTextArea();
					jScrollPane2.setViewportView(jTextArea2);
					jTextArea2.setPreferredSize(new java.awt.Dimension(437, 390));
				}
			}
			{
				jLabel4 = new JLabel();
				jPanel1.add(jLabel4);
				jLabel4.setText("\u79fb\u52a8\u78c1\u9053\u6570\u548c\u5e73\u5747\u79fb\u52a8\u8ddd\u79bb\uff1a");//移动磁道数和平均移动距离：
				jLabel4.setPreferredSize(new java.awt.Dimension(364, 15));
			}
			{
				jLabel5 = new JLabel();
				jPanel1.add(jLabel5);
				jLabel5.setText("1. FIFO\uff1a");//FIFO:
				jLabel5.setPreferredSize(new java.awt.Dimension(368, 22));
			}
			{
				jTextField2 = new JTextField();
				jPanel1.add(jTextField2);
				jTextField2.setPreferredSize(new java.awt.Dimension(368, 22));
			}
			{
				jLabel6 = new JLabel();
				jPanel1.add(jLabel6);
				jLabel6.setText("2. SSTF\uff1a");//SSTF:
				jLabel6.setPreferredSize(new java.awt.Dimension(368, 22));
			}
			{
				jTextField3 = new JTextField();
				jPanel1.add(jTextField3);
				jTextField3.setPreferredSize(new java.awt.Dimension(368, 22));
			}
			{
				jLabel7 = new JLabel();
				jPanel1.add(jLabel7);
				jLabel7.setText("3. SCAN\uff1a");//SCAN:
				jLabel7.setPreferredSize(new java.awt.Dimension(368, 22));
			}
			{
				jTextField4 = new JTextField();
				jPanel1.add(jTextField4);
				jTextField4.setPreferredSize(new java.awt.Dimension(368, 22));
			}
			{
				jLabel8 = new JLabel();
				jPanel1.add(jLabel8);
				jLabel8.setText("4. C-SCAN\uff1a");//C-SCAN:
				jLabel8.setPreferredSize(new java.awt.Dimension(368, 22));
			}
			{
				jTextField5 = new JTextField();
				jPanel1.add(jTextField5);
				jTextField5.setPreferredSize(new java.awt.Dimension(368, 22));
			}
			{
				jLabel9 = new JLabel();
				jPanel1.add(jLabel9);
				jLabel9.setText("5. F-SCAN\uff1a");//F-SCAN:
				jLabel9.setPreferredSize(new java.awt.Dimension(368, 22));
			}
			{
				jTextField6 = new JTextField();
				jPanel1.add(jTextField6);
				jTextField6.setPreferredSize(new java.awt.Dimension(368, 22));
			}
		}
		pack();
		this.setSize(500, 750);//447
	}
	catch (Exception e) {
		//add your error handling code here
		e.printStackTrace();
	}
}

}

void main() {

	diaodu inst = new diaodu();


}