#include <fstream> 
#include<iostream>  
#include<stdio.h>                 //C语言标准输入输出头文件
#include<stdlib.h>                //文件操作需要用到的头文件
#include<string.h>                // 2
#include <iomanip>
#include "Lesson_inf.h"
#include "Teacher_inf.h"
using namespace std;  

 
Teacher::Teacher()
{        
      r_teacherinf();
}
 /*****************************************************************************************************************/
Teacher::~Teacher()
{        
     delete []teacher;
}
 /*****************************************************************************************************************/
void Teacher::w_teacherinf ()
{
		fstream File1;
		File1.open("教师信息.txt",ios_base::out);
        File1<<teacherNum<<endl;
		for(int teacherNum1=0;teacherNum1<teacherNum;teacherNum1++)
		{ 
    	  File1<<"      "<<teacher[teacherNum1].id<<"         "<<teacher[teacherNum1].college<<"          "<<teacher[teacherNum1].name<<"      "<<teacher[teacherNum1].phone
			   <<"       "<<teacher[teacherNum1].password<<"         "<<teacher[teacherNum1].email<<"\r\n" ;
		}
	    File1.close();
}
 /*****************************************************************************************************************/
void Teacher::r_teacherinf ()
{
	    ifstream File1;
		File1.open("教师信息.txt",ios_base::in | ios_base::binary);
		if (File1)
		{   
	     teacherNum=0;
		 File1>>teacherNum;

		for(int teacherNum1=0;teacherNum1<teacherNum;teacherNum1++)
		{ 
    	  File1>>teacher[teacherNum1].id>>teacher[teacherNum1].college>>teacher[teacherNum1].name>>teacher[teacherNum1].phone
			   >>teacher[teacherNum1].password>>teacher[teacherNum1].email;
		}
	    File1.close();
		}
		else
	    cout<<"文件无效\n";
}
 /*****************************************************************************************************************/
int Teacher:: teacherRegisteration()                    //验证老师输入信息的函数
{  
    cout<<"请输入您的教师工号:  ";
	cin>>teacherID;
	int i=0;
	while(strcmp(teacherID,teacher[i].id)!=0)
	{
		i++;
		if(i>teacherNum)
		{
		cout<<"        输入的ID无效\n";
        	cout<<"        请重新输入 :";
        cin>>teacherID;
        	i=0;
		}
	}
	cout<<"        请输入密码:  ";
	cin>>teacherPassword;
	while(strcmp(teacherPassword,teacher[i].password)!=0)
	{
	  cout<<"        密码无效\n";
      cout<<"        请重新输入密码:  ";
      cin>>teacherPassword;
	}
	Tself_num=i;
	temp=teacher[i];
	return Tself_num;
}
 /*****************************************************************************************************************/
void Teacher::showedAllCourses()                      //查看所有课程信息
{
	Lesson::showalllesson();                          //显示所有的课程信息
	cout<<"\n即将返回到教师功能选择界面\n"; 
	system("pause");
}
 /*****************************************************************************************************************/
void Teacher::showMyCourses_tea()    //查看自己所开设的课程
{  
    cout<<"以下为您已开设的课程: \n";
	Lesson::SearchByTeachername(temp.name);	
}
 /*****************************************************************************************************************/
void Teacher::searchcourse()                            //调用课程查找 
{
	int i,j,ii;
	cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"本系统提供两种查询方式：\n";
    cout<<"-------------[ 1.课程编号 ]\n";
    cout<<"-------------[ 2.课程名称 ]\n";
	cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"请输入相应功能的编号："; 
    int choose;
	cin>>choose; 
    while(choose<1||choose>2)           //容错  不在以上所列的功能以内时循环 
    { 
	   cout<<"输入的数字无效，请重新输入（1——2）:";
	    cin>>choose;
    }     
    switch(choose)
    {
    	case 1:
            system("cls");
		    cout<<"请输入需要查找的课程编号："<<endl;
			char ID[11];
			cin>>ID;	
			system("cls");                   
		    cout<<"以下为您的课程查询结果: \n";
			Lesson::showlesson_title();
			for(i=0;i<lessonNum;i++)
			{
				if((strcmp(ID,lesson[i].id)==0)&&(strcmp(teacher[Tself_num].name,lesson[i].teacherName)==0))
				{
					Lesson::showlesson(i);
                    ii=1;
				}
			}
	        break;
		case 2:
            system("cls");
		    cout<<"请输入需要查找的课程名称："<<endl;
        	char Name[21];
			cin>>Name;
			system("cls");                       
			cout<<"以下为您的课程查询结果: \n";
			Lesson::showlesson_title();
			for(j=0;j<lessonNum;j++)
			{
				if((strcmp(Name,lesson[j].name)==0)&&(strcmp(teacher[Tself_num].name,lesson[j].teacherName)==0))
				{
					Lesson::showlesson(j);
				    ii=1;
				}
			}
			break;
	}
	if(ii!=1)
	{   
		system("cls");                      
	    cout<<"无相关课程"<<endl<<"即将返回教师功能选择界面"<<endl;
	    system("pause");
	}
	else
	{
	  cout<<endl;
	  cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
      cout<<"接下来您可选择\n";
      cout<<"-------------[ 1.课程删除             ]\n";
      cout<<"-------------[ 2.课程信息修改         ]\n";
      cout<<"-------------[ 3.返回教师功能选择界面 ]\n";
	  cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
      cout<<"请输入相应功能的编号："; 
      int choose1;
	  cin>>choose1; 
	  cout<<endl;
      while(choose1<1||choose1>3)           //容错  不在以上所列的功能以内时循环 
	  { 
	    cout<<"输入的数字无效，请重新输入（1——3）:";
	    cin>>choose1;
	  }     
	  switch(choose1)//switch语句选择执行功能
	  {
    	case 1:
			deletecourse();
			break;
		case 2:
			editcourse();
			break;
	  }
	}
}

 /*****************************************************************************************************************/
void Teacher:: modifycourse()              // 课程信息修改
{ 
	if(Savebutton)
   {
		cout<<"系统已确认课程信息，暂不支持编辑，详情请咨询管理员:生医1601班冯敏（Tel：18774854031）\n"<<"即将返回教师功能选择界面"<<endl;
        system("pause");
   }
  else
  {		
	showMyCourses_tea();    //查看自己所开设的课程
	cout<<endl;
	cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"您可选择：\n";
    cout<<"------------[ 1.课程删除             ]\n";
    cout<<"------------[ 2.课程信息修改         ]\n";
    cout<<"------------[ 3.返回教师功能选择界面 ]\n";
	cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"请输入相应功能的编号："; 
    int choose1;
	cin>>choose1; 
	 while(choose1<1||choose1>3)           //容错  不在以上所列的功能以内时循环 
    { 
	   cout<<"输入的数字无效，请重新输入（1——3）:";
	    cin>>choose1;
    }     
	switch(choose1)//switch语句选择执行功能
    {
    	case 1:
		    deletecourse();
			break;
		case 2:
			editcourse();
			break;
	}
  }
}
 /*****************************************************************************************************************/
void Teacher::deletecourse()
{
   if(Savebutton)
   {
		cout<<"系统已确认课程信息，暂不支持编辑，详情请咨询管理员:生医1601班冯敏（Tel：18774854031）"<<endl<<"即将返回教师功能选择界面"<<endl;
        system("pause");
   }
  else
  {
   cout<<"请输入欲删除课程的编号：";
   char ID[11];
   cin>>ID;	
   int i=0;
   while(strcmp(ID,lesson[i].id)!=0 || strcmp(teacher[Tself_num].name,lesson[i].teacherName)!=0 || lesson[i].nownum>0)
    {
        i++;
        if(i>lessonNum)
        {
            cout<<"输入的课程编号无效或该课程已选人数大于0不能删除\n";
			break;	
        }	
    }
   if(i<=lessonNum)
   {
   int deletedLine=i;
   fstream File2;
   File2.open("课程属性.txt",ios_base::out);
   int lessonnum=lessonNum-1;
   File2<<lessonnum<<"   "<<Savebutton<<endl;
   for(int lessonNum1=0;lessonNum1<lessonNum;lessonNum1++)
   { 
	   if(lessonNum1!=deletedLine)
	   {
			File2<<lesson[lessonNum1].id<<"  "<<lesson[lessonNum1].name<<"    "<<lesson[lessonNum1].credit<<"    "<<lesson[lessonNum1].ltimes<<"    "<<lesson[lessonNum1].teacherName
			<<"  "<<lesson[lessonNum1].weeks<<"  "<<lesson[lessonNum1].time1<<"  "<<lesson[lessonNum1].time2<<"  "<<lesson[lessonNum1].classplace<<"  "<<lesson[lessonNum1].maxnum<<"  "<<lesson[lessonNum1].nownum<<endl;
	   }
	}
   File2.close();
   Lesson::r_lessoninf();      
   cout<<"\n删除完毕。"<<endl;
   }
  cout<<"\n即将返回到教师功能选择界面\n"; 
  system("pause");
}
}
/*****************************************************************************************************************/
void Teacher:: editcourse()
{
	if(Savebutton)
   {
		cout<<"系统已确认课程信息，暂不支持编辑，详情请咨询管理员:生医1601班冯敏（Tel：18774854031）"<<endl<<"即将返回教师功能选择界面"<<endl;
        system("pause");
   }
  else
  {
   cout<<"请输入欲修改课程的编号：";
   char ID[11];
   cin>>ID;	
   cout<<endl;
   int i=0;
   while(strcmp(ID,lesson[i].id)!=0 || strcmp(teacher[Tself_num].name,lesson[i].teacherName)!=0 || lesson[i].nownum>0)
    {
        i++;
        if(i>lessonNum)
        {
            cout<<"输入的课程编号无效或该课程已选人数大于0不能修改\n";
	        cout<<"即将返回到教师功能选择界面\n"; 
            system("pause");
            allfunction();
			break;	
        }	
    }
   cout<<"请输入新的课程学分:";
   cin>>lesson[i].credit; cout<<endl;
   while(lesson[i].credit<1||(lesson[i].credit-(int) lesson[i].credit)!=0)
   {
	   cout<<"课程学分必须为大于等于1的整数，请重新输入：";
	   cin>>lesson[i].credit; cout<<endl;
   }	
   cout<<"请输入新的课程学时:";
   cin>>lesson[i].ltimes; cout<<endl;
   while(lesson[i].ltimes<20)
   {
	   cout<<"课程学时必须大于20，请重新输入：";
	   cin>>lesson[i].ltimes; cout<<endl;
   }		
   cout<<"请输入新的课程周数（如：X-X周）:";
   cin>>lesson[i].weeks; cout<<endl;
   cout<<"请输入新的课程上课时间1（如:周X第XX节):";
   cin>>lesson[i].time1;   cout<<endl;
   cout<<"请输入新的课程上课时间2（如:周X第XX节):";
   cin>>lesson[i].time2; cout<<endl;
   cout<<"请输入新的课程上课地点（如：S201）:";
   cin>>lesson[i].classplace; cout<<endl;
   cout<<"请输入新的课程最大选修人数:";
   cin>>lesson[i].maxnum; cout<<endl;
   Lesson:: w_lessoninf();
   Lesson:: r_lessoninf();
   cout<<"修改成功。修改后的课程信息如下："<<endl<<endl;
   Lesson:: showlesson_title();
   Lesson::showlesson(i);
   cout<<"\n即将返回到教师功能选择界面\n"; 
   system("pause");
}
}
 /*****************************************************************************************************************/
void Teacher::addcourse()
{	
	if(Savebutton)
	{
		cout<<"系统已确认课程信息，暂不支持编辑，详情请咨询管理员:生医1601班冯敏（Tel：18774854031）"<<endl<<"即将返回教师功能选择界面"<<endl;
        system("pause");
	}
	else
	{
		int x,i;
		for(x=0;x<2;x++)
		{	 system("cls");
			Lesson:: data1 temp;
			strcpy(temp.teacherName,teacher[Tself_num].name);
			cout<<"开始添加课程(至少2门)"<<endl;
			cout<<"输入课程编号:";
			cin>>temp.id;   cout<<endl;
			cout<<"请输入课程名称(仅限汉字字母数字):";
			cin>>temp.name; cout<<endl;
			cout<<"请输入课程学分:";
			cin>>temp.credit; cout<<endl;
			while(temp.credit<1||(temp.credit-(int) temp.credit)!=0)
			{
				cout<<"课程学分必须为大于等于1的整数，请重新输入：";
				cin>>temp.credit; cout<<endl;
			}	
			cout<<"请输入课程学时:";
			cin>>temp.ltimes; cout<<endl;
			while(temp.ltimes<20)
			{
				cout<<"课程学时必须大于20，请重新输入：";
				cin>>temp.ltimes; cout<<endl;
			}		
			cout<<"请输入课程周数（X-X周）:";
			cin>>temp.weeks; cout<<endl;
			cout<<"请输入课程上课时间1（周X第XX节）:";
			cin>>temp.time1; cout<<endl;
			cout<<"请输入课程上课时间2（周X第XX节）:";
			cin>>temp.time2; cout<<endl;
			cout<<"请输入课程上课地点（如：S201）:";
			cin>>temp.classplace; cout<<endl;
			cout<<"请输入课程最大选修人数：";
			cin>>temp.maxnum; cout<<endl;
			temp.nownum=0;
			for(i=0;i<lessonNum;i++)   //通过 for 和 if 来判断同一名教师的上课时间不能冲突 
			{
				if(strcmp(lesson[i].id, temp.id)==0)      //课程编号不能重复
				{
					cout<<"该课程编号与当前存在的课程编号冲突，重新输入课程编号:"<<i<<"  "<<lesson[i].id;
					cin>>temp.id;
				}
					if((strcmp(lesson[i].name ,temp.name)==0))   //课程名不能重复
				{
					cout<<"该课程名称与当前存在的课程名称冲突，重新输入课程名称:"<<i<<"  "<<lesson[i].id;
					cin>>temp.name;
				}
					if((strcmp(lesson[i].teacherName,temp.teacherName)==0))    //  自己的上课时间不能冲突 
				{
					if((strcmp(lesson[i].weeks,temp.weeks)==0))
					{
						if((strcmp(lesson[i].time1,temp.time1)==0) ||(strcmp(lesson[i].time1,temp.time2)==0)||(strcmp(lesson[i].time2,temp.time1)==0) ||(strcmp(lesson[i].time2,temp.time2)==0))
						{
							cout<<"该课程和该教师上课时间冲突"<<"\n请重新输入课程周数（X-X周）:";
							cin>>temp.weeks;
							cout<<"\n重新输入上课开始时间1（周X第XX节;周X第XX节;...;）:";
							cin>>temp.time1;
                            cout<<"\n重新输入上课开始时间2（周X第XX节;周X第XX节;...;）:";
							cin>>temp.time2;
						} 
					}
				}
					if(strcmp(lesson[i].weeks,temp.weeks)==0)               //和别人的上课时间地点教室不能冲突 
				{
						if((strcmp(lesson[i].time1,temp.time1)==0) ||(strcmp(lesson[i].time1,temp.time2)==0)||(strcmp(lesson[i].time2,temp.time1)==0) ||(strcmp(lesson[i].time2,temp.time2)==0))
					{
						if(strcmp(lesson[i].classplace,temp.classplace)==0) 
						{
							cout<<"该课程跟他人上课时间地点冲突"<<"\n请重新输入课程周数（X-X周）:";
							cin>>temp.weeks;
							cout<<"\n重新输入上课开始时间1（周X第XX节;周X第XX节;...;）:";
							cin>>temp.time1;
							cout<<"\n重新输入上课开始时间2（周X第XX节;周X第XX节;...;）:";
							cin>>temp.time2;
							cout<<"\n请重新输入课程上课地点（如：S201）:";
							cin>>temp.classplace;
						} 
					} 
				}
			}
	   lesson[lessonNum]=temp;//将新的课程加进去
	   lessonNum++;  
	   Lesson::w_lessoninf();
	   Lesson::r_lessoninf();
}
	cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"接下来您可选择：\n";
    cout<<"-------------[ 1.继续录入 ]\n";
    cout<<"-------------[ 2.返回至教师功能界面 ]\n";
	cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"请输入相应功能的编号："; 
		int choose;
		cin>>choose;
		while(choose<1||choose>2)                 //不在以上所列的功能以内时循环
		{ 
			cout<<"输入的数字无效，请重新输入（1——2）:";
			cin>>choose;
		}   
		switch(choose) 
		{
		case 1:
			system("cls");	
			addcourse();
			break;
		case 2:
			system("cls");	
			break;  	
		}
	}
}
 /*****************************************************************************************************************/
 void Teacher::saveinf ()
 {  	
	cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
	cout<<"温馨提示：课程信息保存后不可修改------------------------------------------------------------------------------------------\n";
    cout<<"您可选择：\n";
    cout<<"---------[ 1.课程信息保存                       ]\n";
    cout<<"---------[ 2.取消本次操作并返回教师功能选择界面 ]\n";
	cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"请输入相应功能的编号："; 
    int choose1;
	cin>>choose1; 
	 while(choose1<1||choose1>2)           //容错  不在以上所列的功能以内时循环 
    { 
	   cout<<"输入的数字无效，请重新输入（1——2）:";
	    cin>>choose1;
    }     
	switch(choose1)//switch语句选择执行功能
    {
    	case 1:
              Savebutton=1;      //Savebutton为0时可实现编辑
			  system("cls");	
	          cout<<"系统已确认课程信息，暂不支持编辑，详情请咨询管理员:生医1601班冯敏（Tel：18774854031）"<<endl<<"即将返回教师功能选择界面"<<endl;
              system("pause");
		      break;
		case 2:	break;
 }
 }
 /*****************************************************************************************************************/
 void Teacher::master_inf ()
 { 
	cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"您可选择修改个人信息： \n";
    cout<<"-------------[ 1.修改密码   ] \n";
    cout<<"-------------[ 2.更换手机号 ]\n";
    cout<<"-------------[ 3.更改邮箱   ]\n";	
	cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"请输入相应功能的编号："; 
    int choose;
	cin>>choose; 
    while(choose<1||choose>3)                 //不在以上所列的功能以内时循环
		{ 
			cout<<"输入的数字无效，请重新输入（1——3）:";
			cin>>choose;
		}   
		switch(choose) 
		{
		case 1:
			system("cls");	
			editpassword();
			break;
		case 2:
			system("cls");	
			edittel();
			break;
		case 3:
			system("cls");	
			editemail();
			break;
		}
		w_teacherinf ();
	    r_teacherinf ();
		cout<<"教师信息修改成功！";
		cout<<"即将返回到教师功能选择界面\n"; 
        system("pause");
 }
 /*****************************************************************************************************************/
void Teacher::editpassword()
{
	cout<<"请输入新密码：  "<<endl;
	char password1[81];
    scanf("%s",password1);
    strcpy(teacher[Tself_num].password,password1);
}
 /*****************************************************************************************************************/
void Teacher::edittel()
{
	cout<<"请输入新的电话号码：  "<<endl;
    char phone1[20];
	 scanf("%s",phone1);
    strcpy(teacher[Tself_num].phone,phone1);
}
 /*****************************************************************************************************************/
void Teacher::editemail()
{
	cout<<"请输入新的邮箱：  "<<endl;
	char email1[81];
	 scanf("%s",email1);
    strcpy(teacher[Tself_num]. email, email1);
}
/*****************************************************************************************************************/
void Teacher::allfunction()
{
	system("cls");                     
	cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
	cout<<"--------------------------------------------< 教 师 管 理 系 统 >---------------------------------------------------------\n";
	cout<<"-----["<<setw(6)<<teacher[Tself_num].id<<"   " <<setw(4)<<teacher[Tself_num].name<<"]   欢迎使用-------------------------------------------------------------------------------------------\n"; 
	cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"--------------------------------------------1.查看所有开设课程   ---------------------------------------------------------\n";
	cout<<"--------------------------------------------2.显示我的开设课程   ---------------------------------------------------------\n";
	cout<<"--------------------------------------------3.课程查找           ---------------------------------------------------------\n";
	cout<<"--------------------------------------------4.课程录入           ---------------------------------------------------------\n";
	cout<<"--------------------------------------------5.课程编辑           ---------------------------------------------------------\n";
	cout<<"--------------------------------------------6.课程信息保存       ---------------------------------------------------------\n";
	cout<<"--------------------------------------------7.个人信息管理       ---------------------------------------------------------\n";
	cout<<"--------------------------------------------8.返回权限登录系统   ---------------------------------------------------------\n";
	cout<<"--------------------------------------------9.退出系统           ---------------------------------------------------------\n";
	cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
	cout<<"--------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"请输入相应功能的编号："; 
    int choose;
	cin>>choose; 
    while(choose<1||choose>9)           //容错  不在以上所列的功能以内时循环 
    { 
	   cout<<"输入的数字无效，请重新输入（1——9）:";
	    cin>>choose;
    }     
    switch(choose)//switch语句选择执行功能
    {
    	case 1:
            system("cls");
			showedAllCourses();
	    	allfunction();
			break;
		case 2:
		    system("cls"); 
	        showMyCourses_tea();       //调用查询自己已开设课程函数
			cout<<"即将返回到教师功能选择界面\n"; 
        	system("pause");
			allfunction();
			break;
	    case 3:
		    system("cls");
			searchcourse();        //调用课程查找 
		    allfunction(); 
			break;
    	case 4:
	        system("cls");         //清屏 
	        addcourse();          
	        allfunction();     
	        break;
		case 5:		  
	        system("cls");      //清屏 
	        modifycourse();     
	        allfunction();    //回到教师功能选择 
	        break;
		case 6:
	        system("cls");         //清屏 
	         saveinf();//调用  根据课程名称查询 函数 
	        allfunction();     //回到教师功能选择 
			break;
		case 7:
		    system("cls");
            master_inf();
			allfunction();
		case 8:
	        system("cls");       //清屏 
			cout<<"即将返回到权限登录界面\n"; 
        	system("pause");
	        break;
		case 9:
	        system("cls");       //清屏 
         	Lesson::over();
	        break;
	}
}
