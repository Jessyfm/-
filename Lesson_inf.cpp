#include <fstream> 
#include<iostream>  
#include<stdio.h>                 //C���Ա�׼�������ͷ�ļ�
#include<stdlib.h>                //�ļ�������Ҫ�õ���ͷ�ļ�
#include<string.h>                // 2
#include <iomanip>
#include "Lesson_inf.h"
#include "Teacher_inf.h"
#include "Student_inf.h"

using namespace std;   

Lesson::Lesson()
{       
		 r_lessoninf();
}
/*****************************************************************************************************************/
Lesson::~ Lesson()
{       
	delete []lesson;
}
 /*****************************************************************************************************************/
void Lesson:: w_lessoninf()             //дtxt�ļ�������
{
   fstream File2;
   File2.open("�γ�����.txt",ios_base::out);
   File2<<lessonNum<<endl;
   File2<<Savebutton<<endl;
   for(int lessonNum1=0;lessonNum1<lessonNum;lessonNum1++)
   {   
    	File2<<lesson[lessonNum1].id<<"  "<<lesson[lessonNum1].name<<"    "<<lesson[lessonNum1].credit<<"    "<<lesson[lessonNum1].ltimes<<"    "<<lesson[lessonNum1].teacherName
			<<"  "<<lesson[lessonNum1].weeks<<"  "<<lesson[lessonNum1].time1<<"  "<<lesson[lessonNum1].time2<<"  "<<lesson[lessonNum1].classplace<<"  "<<lesson[lessonNum1].maxnum<<"  "<<lesson[lessonNum1].nownum<<endl;
	}
   File2.close();
} 
/*****************************************************************************************************************/
void Lesson:: r_lessoninf()             //дtxt�ļ�������
{
        ifstream File;
		File.open("�γ�����.txt",ios_base::in | ios_base::binary);
		if (File)
		{  
	     lessonNum=0;
		 File>>lessonNum>>Savebutton;                      //�ļ���һ������ʾ�γ�����
     	for(int lessonNum1=0;lessonNum1<lessonNum;lessonNum1++)
		{ 
    	File>>lesson[lessonNum1].id>>lesson[lessonNum1].name>>lesson[lessonNum1].credit>>lesson[lessonNum1].ltimes>>lesson[lessonNum1].teacherName
			>>lesson[lessonNum1].weeks>>lesson[lessonNum1].time1>>lesson[lessonNum1].time2>>lesson[lessonNum1].classplace>>lesson[lessonNum1].maxnum>>lesson[lessonNum1].nownum;
		}
	    File.close();
		}
		else{
	    cout<<"�ļ���Ч\n";
		}
}
 /*****************************************************************************************************************/
void Lesson:: showlesson_title()
{
    cout<<"�γ̱�� �γ�����              ѧ��  ѧʱ  �ο���ʦ  �Ͽ�����    �Ͽ�ʱ��1   �Ͽ�ʱ��2  �Ͽεص�  ��ѡ����  ��ѡ����\n";

}
 /*****************************************************************************************************************/
void Lesson::showlesson(int i)
{
		 r_lessoninf();
         cout.width(8);
        cout<<lesson[i].id<<" ";
			cout.width(20);
        cout<<lesson[i].name<<"  ";
			cout.width(6);
        cout<<lesson[i].credit;
			cout.width(6);
        cout<<lesson[i].ltimes;
		cout.width(10);
        cout<<lesson[i].teacherName;
			cout.width(12);
        cout<<lesson[i].weeks;
			cout.width(12);
        cout<<lesson[i].time1;
			cout.width(14);
        cout<<lesson[i].time2;
			cout.width(10);
        cout<<lesson[i].classplace;
			cout.width(10);
        cout<<lesson[i].maxnum;
			cout.width(4);
        cout<<lesson[i].nownum<<endl; 
}
/*****************************************************************************************************************/
void Lesson::showalllesson()
{
	int i;
	Lesson::showlesson_title();
	for(i=0;i<lessonNum;i++)
	{
		Lesson::showlesson(i);
	}
	cout<<"\n--------------------------------------------------------------------------------------------------------------------------\n";
}
 /*****************************************************************************************************************/
void Lesson::SearchByTeachername(char name[21])
{
	
    int j=0,i=0,ii=0;
   while(i<=lessonNum)
    {	
	   if(strcmp(name,lesson[i].teacherName)!=0)  //�ж����������Ϣ ���У�j=1��
        {
		   j=1;
        }
        i++;	
    }
	if (j==1)
	{
     showlesson_title();
     while(ii<=lessonNum)
	 { 
      if(strcmp(name,lesson[ii].teacherName)==0)  
	  {
	  showlesson(ii);
	   }
      ii++;
	 }
	}
    else
	{
	    system("cls");
        cout<<"����ؿγ̣�"<<endl;

	}
	cout<<"\n--------------------------------------------------------------------------------------------------------------------------\n";
}
/*****************************************************************************************************************/
void Lesson::over ()
{
	cout<<"\n--------------------------------------------------------------------------------------------------------------------------\n";
	cout<<"\n---------------------------------------�����˳�ѡ�ι���ϵͳ,ллʹ�ã�----------------------------------------------------\n";  //������Խ����¼��ʾ 
	cout<<"-------------------------------------------------------------------------------- [ Made By ��ҽ1601����� ] --------------\n";
	cout<<"\n--------------------------------------------------------------------------------------------------------------------------\n";
	exit(0); 
}
