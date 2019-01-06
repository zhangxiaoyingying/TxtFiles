// Txtfile.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
#define random(x) (rand()%x)


/****从txt文件读入，写入新的txt文件(string类型)***/
void WriteOutString()
{

	ifstream myfile("C:\\Users\\ZY\\Desktop\\hello.txt");
	ofstream outfile("C:\\Users\\ZY\\Desktop\\out.txt",ios::app);
	string temp;
	if(!myfile.is_open())
	{
		cout<<"未能成功打开文件"<<endl;
	}
	while(getline(myfile,temp))		
	{
		outfile<<temp;
		outfile<<endl;
	}

	myfile.close();
	outfile.close();

}

/***从新txt文件读入，写入txt（int型数据,且每一行数据个数一样多）***/
int cost[10][10];
void WriteOutInt()
{

	int v,w,weight;
	ifstream infile;	//输入流
	ofstream outfile;	//输出流
	infile.open("C:\\Users\\ZY\\Desktop\\data.txt",ios::in);
	if(!infile.is_open())
		cout<<"open file failure!"<<endl;


	while(!infile.eof())				//若不是文件结尾，就一直循环
	{
		infile>>v>>w>>weight;
		cost[v][w] = weight;
		cost[w][v] = weight;
	}
	infile.close();
	outfile.open("C:\\Users\\ZY\\Desktop\\result.txt",ios::app);	//定位在结尾，则每次写入都不会丢失内容
	if(!outfile.is_open())
		cout<<"open out file failure!"<<endl;
	for (int i=0; i !=10; ++i)
	{
		for(int j=0; j!=10; ++j)
		{
			outfile << i<<"\t"<<j<<"\t"<< cost[i][j]<<endl;	//在result结果文件中写入结果
		}
	}
	outfile.close();


}


/***从新txt文件读入，写入txt（int型数据，不同行数据不同）***/
void WriteOutInt2()
{
	int Num_3,Num_2;	//	数据中有3列的，有2列的

	int v,w,weight;
	ifstream infile;	//输入流
	ofstream outfile;	//输出流

	infile.open("C:\\Users\\ZY\\Desktop\\data.txt",ios::in);
	if(!infile.is_open())
		cout<<"open file failure!"<<endl;

	infile >> Num_3 >>Num_2;	//首先读取第一行

	while(Num_3 != 0)				//读取3个数据的
	{
		infile>>v>>w>>weight;
		cost[v][w] = weight;
		cost[w][v] = weight;
		Num_3--;
	}

	while(Num_2 !=0)		//读取2个数据的
	{
		infile>>v>>w;
		cost[v][w] = 100;
		cost[w][v] = 100;
		Num_2--;
	}
	infile.close();

	outfile.open("C:\\Users\\ZY\\Desktop\\result.txt",ios::app);	//定位在结尾，则每次写入都不会丢失内容
	if(!outfile.is_open())
		cout<<"open out file failure!"<<endl;
	for (int i=0; i !=10; ++i)
	{
		for(int j=0; j!=10; ++j)
		{
			outfile << i<<"\t"<<j<<"\t"<< cost[i][j]<<endl;	//在result结果文件中写入结果
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
	outfile.open("C:\\Users\\ZY\\Desktop\\result2.txt",ios::app);	//定位在结尾，则每次写入都不会丢失内容
	if(!outfile.is_open())
		cout<<"open out file failure!"<<endl;

	while(!infile.eof())				//若不是文件结尾，就一直循环
	{
		infile>>v>>w;

			m= v  +2000+random(10) ;
			n = w+2000+random(10);
			m1= v + 2000  ;
			n1 = w+2000;
			//outfile << m<<n<<endl;	//在result结果文件中写入结果
			outfile << m<<"\t"<<n<<"\t"<<endl;	//在result结果文件中写入结果
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


	while (getline(myfile, temp))                    //利用getline（）读取每一行，并按照行为单位放入到vector
	{
		vec.push_back(temp);
	}

	vector <float> radius;


	cout << "读入的数据为 " << endl;
	for (auto it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << endl;
		istringstream is(*it);                    //用每一行的数据初始化一个字符串输入流；
		string s;
		int pam = 0;

		while (is >> s)                          //以空格为界，把istringstream中数据取出放入到依次s中
		{
			if (pam == 5)                       //获取第六列的数据

			{
				float r = atof(s.c_str());     //做数据类型转换，将string类型转换成float
				radius.push_back(r);
				//cout << r << endl;
			}

			pam++;

		}
	}
	cout << "读入的第6列数据为 " << endl;

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
	string a[100];              //采用 string 类型，存100行的文本，不要用数组 
	int i=0; 
	ifstream infile;

	infile.open("C:\\Users\\ZY\\Desktop\\test.txt",ios::in);

	while(!infile.eof())            // 若未到文件结束一直循环 
	{  
		getline(infile, a[i], '\n');//读取一行，以换行符结束，存入 a[] 中
		i++;                    //下一行
	}
	for(int ii=0;ii<i;ii++)        // 显示读取的txt内容 
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
	//统计txt中的文件行数
	FILE *fp =fopen(dataPath,"r");
	while (fgets(buf,N,fp)!=NULL)
	{
		if (buf[strlen(buf)-1] =='\n')
		{
			count++;			//count 记录txt文件中的行数
		}
	}
	fclose(fp);
	//将txt文件中的坐标保存到vector中
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

