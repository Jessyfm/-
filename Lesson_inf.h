
class Lesson 
{
public:
	 Lesson();
	 ~Lesson();
	void showlesson_title();
 	void showlesson(int i);                        //��ʾ��i���γ���Ϣ   
    void showalllesson();                          //��ʾ���еĿγ���Ϣ
    void SearchByTeachername(char name[21]);       //���ݽ�ʦ�������ҿγ���Ϣ 
	int lessonNum;                                 //�γ���Ϣ����
	void w_lessoninf();                            //дtxt�ļ�������
	void r_lessoninf();                            //��txt�ļ�������
	void over();                                    //�˳�ϵͳ����
	friend class allclass;
	int Savebutton; 	
	typedef struct                   //�γ���Ϣ�ṹ������
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


