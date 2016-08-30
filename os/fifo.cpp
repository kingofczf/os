#include<iostream>

class fifostruct
{
int fifosum = 0;
int sstfsum = 0;
int fifosumN = 0;//∆Ωæ˘—∞µ¿æ‡¿Î
int sstfsumN = 0;
};

void fifo() {
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