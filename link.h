//该头文件包含结构体的定义与函数调用的声明 
//该学生系统未采用图形化界面 
#pragma once//防止头文件重复包含 
typedef struct student
{
	int num;//学生学号 
	char name[16];//学生姓名 
	char sex[4];//学生性别 
	char major[16];//学生专业 
	int scoreA;//高等数学成绩
	int scoreB;//程序设计成绩
	int scoreC;//英语成绩
	int scoreD;//思想道德修养成绩
	int score_sum;//总成绩 
	char postscript[50];//成绩录入状态 
	struct student *next;//链表节点指针域 
}STU;//学生信息结构 


typedef struct administrator
{
	char username[32];
	char code[16];
	int stepcount;
}ADM;//管理员结构 


extern STU *insert_linkA(STU *head,STU tmp);//插入节点，头部插入 
extern STU *insert_linkB(STU *head,STU tmp);//插入节点，尾部插入 
extern STU *insert_linkC(STU *head,STU tmp);//声明的插入函数 
extern void stu_help(void);//系统帮助函数 
extern void search_name(STU *head); //按照比对姓名查找学生信息信息 
extern void search_num(STU *head);//查询 
extern STU *delete_link(STU *head);//删除节点 
extern STU *free_link(STU *head,int *n);//释放空间 
extern STU *alteration_link(STU *head);//修改 
extern void alter_major(char *major);//修改专业 
extern void alter_sex(char *sex);//修改性别 
extern void alter_name(char *name); //修改姓名 
extern int alter_num(int *num);//修改学号
extern void alter_math(STU *p);//修改高等数学成绩
extern void alter_programming(STU *p);//修改程序设计成绩 
extern void alter_English(STU *p);//修改英语成绩
extern void alter_Politition(STU *p);//修改思修成绩 
extern ADM *Sys_Login(void);//登录 
extern ADM *File_adm_write(void);//读取管理员信息 
extern STU *readFile_stu(STU* head,int count);//读取学生信息 
extern ADM *add_administrator(void);//写入管理员信息
extern void File_memset(void);//清空文件
extern STU *stu_link_made(STU *head,int count); //创建链表
extern STU *Trans_link_to_arr(STU *head,int count);//将学生信息链表转换为数组 
extern void writeFile_stu(STU *savehead,int count);//将学生信息写入文件
extern void writeFile_adm(ADM *admpin);//将管理员信息写入文件 
extern void print_msg(STU *head); //打印操作 
extern void print_woman(STU *head);//打印男性信息 
extern void print_man(STU *head);//打印女性信息
extern void print_sex(STU *head);//性别选择
extern void print_major(STU *head);//按照专业打印
extern void adm_alter(ADM *admpin);//管理员信息修改 
extern void username_alter(ADM *admpin);//管理员账号修改 
extern void code_alter(ADM *admpin); //管理员密码修改 
extern void soc_print(STU* head,int n);//打印学生成绩 
extern STU *soc_registration(STU *head);//批量导入学生成绩
 
