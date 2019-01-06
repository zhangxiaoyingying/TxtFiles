// Txtfile.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
#define random(x) (rand()%x)


/****��txt�ļ����룬д���µ�txt�ļ�(string����)***/
void WriteOutString()
{

	ifstream myfile("C:\\Users\\ZY\\Desktop\\hello.txt");
	ofstream outfile("C:\\Users\\ZY\\Desktop\\out.txt",ios::app);
	string temp;
	if(!myfile.is_open())
	{
		cout<<"δ�ܳɹ����ļ�"<<endl;
	}
	while(getline(myfile,temp))		
	{
		outfile<<temp;
		outfile<<endl;
	}

	myfile.close();
	outfile.close();

}

/***����txt�ļ����룬д��txt��int������,��ÿһ�����ݸ���һ���ࣩ***/
int cost[10][10];
void WriteOutInt()
{

	int v,w,weight;
	ifstream infile;	//������
	ofstream outfile;	//�����
	infile.open("C:\\Users\\ZY\\Desktop\\data.txt",ios::in);
	if(!infile.is_open())
		cout<<"open file failure!"<<endl;


	while(!infile.eof())				//�������ļ���β����һֱѭ��
	{
		infile>>v>>w>>weight;
		cost[v][w] = weight;
		cost[w][v] = weight;
	}
	infile.close();
	outfile.open("C:\\Users\\ZY\\Desktop\\result.txt",ios::app);	//��λ�ڽ�β����ÿ��д�붼���ᶪʧ����
	if(!outfile.is_open())
		cout<<"open out file failure!"<<endl;
	for (int i=0; i !=10; ++i)
	{
		for(int j=0; j!=10; ++j)
		{
			outfile << i<<"\t"<<j<<"\t"<< cost[i][j]<<endl;	//��result����ļ���д����
		}
	}
	outfile.close();


}


/***����txt�ļ����룬д��txt��int�����ݣ���ͬ�����ݲ�ͬ��***/
void WriteOutInt2()
{
	int Num_3,Num_2;	//	��������3�еģ���2�е�

	int v,w,weight;
	ifstream infile;	//������
	ofstream outfile;	//�����

	infile.open("C:\\Users\\ZY\\Desktop\\data.txt",ios::in);
	if(!infile.is_open())
		cout<<"open file failure!"<<endl;

	infile >> Num_3 >>Num_2;	//���ȶ�ȡ��һ��

	while(Num_3 != 0)				//��ȡ3�����ݵ�
	{
		infile>>v>>w>>weight;
		cost[v][w] = weight;
		cost[w][v] = weight;
		Num_3--;
	}

	while(Num_2 !=0)		//��ȡ2�����ݵ�
	{
		infile>>v>>w;
		cost[v][w] = 100;
		cost[w][v] = 100;
		Num_2--;
	}
	infile.close();

	outfile.open("C:\\Users\\ZY\\Desktop\\result.txt",ios::app);	//��λ�ڽ�β����ÿ��д�붼���ᶪʧ����
	if(!outfile.is_open())
		cout<<"open out file failure!"<<endl;
	for (int i=0; i !=10; ++i)
	{
		for(int j=0; j!=10; ++j)
		{
			outfile << i<<"\t"<<j<<"\t"<< cost[i][j]<<endl;	//��result����ļ���д����
		}
	}
	outfile.close();


}

void WriteOutINS()
{

	int v,w;
		double m,n;
		double m1,n1;
	ifstream infile;
	ofstream outfile;
	infile.open("C:\\Users\\ZY\\Desktop\\imgdata.txt",ios::in);
	if(!infile.is_open())
		cout<<"open infile failure!"<<endl;
	outfile.open("C:\\Users\\ZY\\Desktop\\result2.txt",ios::app);	//��λ�ڽ�β����ÿ��д�붼���ᶪʧ����
	if(!outfile.is_open())
		cout<<"open out file failure!"<<endl;

	while(!infile.eof())				//�������ļ���β����һֱѭ��
	{
		infile>>v>>w;

			m= v  +2000+random(10) ;
			n = w+2000+random(10);
			m1= v + 2000  ;
			n1 = w+2000;
			//outfile << m<<n<<endl;	//��result����ļ���д����
			outfile << m<<"\t"<<n<<"\t"<<endl;	//��result����ļ���д����
			cout<<endl;
//	outfile << m1<<"\t"<<n1<<"\t"<<endl;	
	
	}
	infile.close();

	
	
	
	outfile.close();

}


//int main()
//{
////	WriteOutInt();
////	WriteOutInt2();
//	WriteOutINS();
//	return 0;
//}




#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int test_ReadRow(){

	ifstream myfile("C:\\Users\\ZY\\Desktop\\test.txt");

	if (!myfile.is_open()){
		cout << "Unable to open myfile";
		system("pause");
		exit(1);

	}

	vector<string> vec;
	string temp;


	while (getline(myfile, temp))                    //����getline������ȡÿһ�У���������Ϊ��λ���뵽vector
	{
		vec.push_back(temp);
	}

	vector <float> radius;


	cout << "���������Ϊ " << endl;
	for (auto it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << endl;
		istringstream is(*it);                    //��ÿһ�е����ݳ�ʼ��һ���ַ�����������
		string s;
		int pam = 0;

		while (is >> s)                          //�Կո�Ϊ�磬��istringstream������ȡ�����뵽����s��
		{
			if (pam == 5)                       //��ȡ�����е�����

			{
				float r = atof(s.c_str());     //����������ת������string����ת����float
				radius.push_back(r);
				//cout << r << endl;
			}

			pam++;

		}
	}
	cout << "����ĵ�6������Ϊ " << endl;

	for (auto it = radius.begin(); it != radius.end(); it++)
	{
		cout << *it << endl;
	}

	//cout << "successfully to open myfile";
	system("pause");
	return 1;
}

#include <iostream>
#include <fstream>

using namespace std;
char s[80];
vector<int> truePath;
int test_Write()
{
	string a[100];              //���� string ���ͣ���100�е��ı�����Ҫ������ 
	int i=0; 
	ifstream infile;

	infile.open("C:\\Users\\ZY\\Desktop\\test.txt",ios::in);

	while(!infile.eof())            // ��δ���ļ�����һֱѭ�� 
	{  
		getline(infile, a[i], '\n');//��ȡһ�У��Ի��з����������� a[] ��
		i++;                    //��һ��
	}
	for(int ii=0;ii<i;ii++)        // ��ʾ��ȡ��txt���� 
	{  
		cout<< a[ii] << endl;
		
	}
	infile.close();
	return 0;
}
#define N 100
int main()
{
	ifstream infile;
	infile.open("C:\\Users\\ZY\\Desktop\\test.txt",ios::in);
	char buf[N];
	int count=1;
	const char* dataPath = "C:\\Users\\ZY\\Desktop\\test.txt";
	//ͳ��txt�е��ļ�����
	FILE *fp =fopen(dataPath,"r");
	while (fgets(buf,N,fp)!=NULL)
	{
		if (buf[strlen(buf)-1] =='\n')
		{
			count++;			//count ��¼txt�ļ��е�����
		}
	}
	fclose(fp);
	//��txt�ļ��е����걣�浽vector��
	FILE *fp1=  fopen(dataPath,"r");
	double a ,b,c;
	for(int i =0; i<count;i++)
	{
		fscanf(fp1,"%lf,%lf,%lf",&a,&b,&c);
		printf("%lf,%lf,%lf\n",a,b,c);
		truePath.push_back(a);
		truePath.push_back(b);
		truePath.push_back(c);
	}

	fclose(fp1);
	for (int i=0;i<truePath.size();i++)
	{
		cout<<truePath[i]<<endl;
	}
	cout<<truePath.size()<<endl;
	cout<<count<<endl;
}

