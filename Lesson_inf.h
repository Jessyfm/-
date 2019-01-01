
class Lesson 
{
public:
	 Lesson();
	 ~Lesson();
	void showlesson_title();
 	void showlesson(int i);                        //显示第i个课程信息   
    void showalllesson();                          //显示所有的课程信息
    void SearchByTeachername(char name[21]);       //根据教师姓名查找课程信息 
	int lessonNum;                                 //课程信息总数
	void w_lessoninf();                            //写txt文件并更新
	void r_lessoninf();                            //读txt文件并更新
	void over();                                    //退出系统界面
	friend class allclass;
	int Savebutton; 	
	typedef struct                   //课程信息结构体数组
	{
	char id[11];
	char name[81]; 
    float  credit;
	int ltimes;
	char teacherName[21];
	char weeks[21];
    char time1[81];
	char time2[81];
	char classplace[18];
	int maxnum;
	int nownum;
}data1;
	data1 lesson[15];
private:  
         
};


