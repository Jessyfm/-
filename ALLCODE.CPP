#include<iostream>  
#include <fstream> 
#include<stdio.h>                 //C语言标准输入输出头文件
#include<stdlib.h>                //文件操作需要用到的头文件
#include<string.h>                // 2
#include <iomanip>
#include "Lesson_inf.h"
#include "Teacher_inf.h"
#include "Student_inf.h"
#include "allclass.h"

using namespace std; 


void main()
{   
	system("mode con cols=123 lines=40  ");      //调整命令行窗口属性
	cout.setf(std::ios::left);
	system("color F0");
	allclass a;
	a.mainfun();
}
