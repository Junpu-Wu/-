#include"link.h" 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//链表的头部插入 
STU *insert_linkA(STU *head,STU tmp)
{
	STU *pi=(STU *)calloc(1,sizeof(STU));
	if(pi == NULL)//此块打印动态申请错误 
	{
		perror("calloc");
		return head;
	}
	*pi = tmp;
	if(head != NULL) pi->next=head;
	else pi->next = NULL;
	head=pi;//插入链表之前链表不存在
	return head;
}


//链表的尾部插入
STU *insert_linkB(STU *head,STU tmp)
{
	STU *pi=(STU *)calloc(1,sizeof(STU));
	if(pi == NULL)//此块打印动态申请错误 
	{
		perror("calloc");
		return head;
	}
	*pi=tmp;
	pi->next = NULL;
	if(head == NULL) head=pi;
	else
	{
		STU *p3=head;
		while(p3->next != NULL) p3=p3->next;
		p3->next=pi;
	}
	return head;
}



//链表的有序插入 （根据学号） 
 STU *insert_linkC(STU *head,STU tmp)
{
	STU *pi=(STU *)calloc(1,sizeof(STU));//动态申请 
	if(pi == NULL)//此块打印动态申请错误 
	{
		perror("calloc");
		//打印错误 
		return head;
	}
	*pi=tmp;
	STU *pb=head;
	STU *pf=head;
	if(head == NULL)//情况一如果原链表内无节点 
	{
	pi->next=NULL;
	return pi;
	}
	else 
	{
		STU *checkp=head;
		while(checkp!=NULL)//检查学号是否被注册 
		{
			if(checkp->num==pi->num)
			{
				printf("Invalid Input\n");
				printf("输入的学号已被注册\n");
				free(pi);
				return head;
			}
			checkp=checkp->next; 
		} 
		
		while(pb->num < pi->num&&pb->next!=NULL)
		{
			pf=pb;
			pb=pb->next;
		}
		if(pf == head&&pf->num > pi->num)//新节点在链表头的位置； 
		{
			pi->next=head;
			head=pi;
		}//到此为止，寻找新节点插入位置结束 
		else if(pb->num > pi->num) //新节点在原节点之间 
		{
			pf->next=pi;
			pi->next=pb;
		}
		else//新节点将插入到链表的尾部 
		{
			pb->next=pi;
			pi->next=NULL;
		}
	}

	return head;
}


//学管系统帮助信息、菜单目录 
void stu_help(void)
{
	printf("--------------------注意:输入＃和：之间的英文指令以实现功能！--------------------\n"); 
	printf("--------------------例如我想增加一个学生的信息就输入“insert”-------------------\n");
	printf("#########################################\n");
	printf("#help:打印操作菜单（也就是该菜单）      #\n");
	printf("#insert：增加一个学生的信息             #\n");
	printf("#print：按需打印学生的信息              #\n");
	printf("#search：查询一个学生的信息             #\n");
	printf("#delete删除一个学生的信息               #\n");
	printf("#free：删除所有学生的信息               #\n");
	printf("#quit：退出程序                         #\n");
	printf("#alteration：修改一个学生的信息         #\n");
	printf("#adm_alteration:修改管理员的信息        #\n");
	printf("#register:批量登记学生的成绩            #\n");
	printf("#soc_print:按需打印学生的成绩           #\n");
	printf("#########################################\n");
}



//根据姓名查询 
void search_name(STU *head)//根据学生姓名查询 
{
	printf("请输入您希望查询的姓名:"); 
	char exm[32]="";
	scanf("%s",exm);
	STU *pb=head;
	while(pb != NULL)
	{
		if(strcmp(pb->name,exm) == 0) break;
		pb=pb->next;
	}
	if(pb == NULL) printf("NO DATA FOUND!!!\n");
	else 
	{
	printf("学生学号：%05d",pb->num);printf(" "); 
	printf("学生姓名：%*s",5,pb->name);printf(" ");
	printf("学生性别：%*s",2,pb->sex);printf(" ");
	printf("学生专业：%*s",8,pb->major);printf("\n");
	printf("该学生成绩如下：\n");
	printf("高等数学成绩：%5d",pb->scoreA);printf(" ");
	printf("程序设计成绩：%5d",pb->scoreB);printf(" ");
	printf("大学英语成绩：%5d",pb->scoreC);printf(" ");
	printf("思修教育成绩：%5d",pb->scoreD);printf(" ");
	printf("该学期总成绩：%5d",pb->score_sum);printf("\n");
	}
}


//根据学号查询 
void search_num(STU *head)
{
	printf("请输入您希望查询的学生学号：");
	int example1=0;
	STU *pb=head;
	scanf("%d",&example1);
	while(pb != NULL)
	{
		if(example1 == pb->num) break;
		pb=pb->next;
	}
	if(pb == NULL) printf("NO DATA FOUND!\n");
	else 
	{
	printf("学生学号：%05d",pb->num);printf(" "); 
	printf("学生姓名：%*s",5,pb->name);printf(" ");
	printf("学生性别：%*s",2,pb->sex);printf(" ");
	printf("学生专业：%*s",8,pb->major);printf("\n");
	printf("该学生成绩如下：\n");
	printf("高等数学成绩：%5d",pb->scoreA);printf(" ");
	printf("程序设计成绩：%5d",pb->scoreB);printf(" ");
	printf("大学英语成绩：%5d",pb->scoreC);printf(" ");
	printf("思修教育成绩：%5d",pb->scoreD);printf(" ");
	printf("该学期总成绩：%5d",pb->score_sum);printf("\n");
	}
}



//链表节点的删除函数 
//此部分应注意，每执行一次删除要刷新首地址
STU *delete_link(STU *head)
{
	char exm[32]="";
	printf("请输入需要被删除的名字："); 
	scanf("%s",exm); 
	if(head == NULL)//当首地址为空 
	{
		printf("NO DATA FOUND!!!\n");
		return head;
	}
	STU *pb=head;//定义一个指针变量扫描链表 
	STU *pf=head;//定义一个指针变量紧随其后，以方便地址修改操作 
	while(pb != NULL)
	{
		if(strcmp(pb->name,exm) == 0) break;
		pf=pb; 
		pb=pb->next;
	}
	if(pb == NULL) printf("NO DATA FOUND!!!\n");
	else if(pb == head)//注意：若要删除头节点，应该更新首地址 
	{
		head=pb->next;
		free(pb);//释放该节点空间 
	}
	else//中部删除或者是尾部删除 
	{
		pf->next=pb->next;
		free(pb);//释放该节点空间 
	}
	return head; 
}



//整个链表的释放函数 
STU *free_link(STU *head,int *n)
{
	printf("------------确定要删除所有学生的信息？------------\n");
	printf("1.我确定\n");
	printf("2.算了\n");
	int choice=0;
	while(1)
	{
		int test=0;
		test=scanf("%d",&choice);
		if(test==0)
		{
			printf("------------输入错误！请重新输入！-----------\n");
			continue; 
		}
		else break;
	}
	if(choice==1)
	{
		head=NULL;
		*n=0;
		printf("-----------已删除所有的数据！----------\n"); 
		return head;
	}
	if(choice==2)
	{
		printf("-----------已取消您的请求！----------\n");
		return head;
	}
}



//链表内容的修改
STU *alteration_link(STU *head)
{
	if(head == NULL)
	{
		printf("NO DATA FOUND!!!\n");
		return head;
	}
	printf("-----请输入您希望被修改信息的姓名:"); 
	char exm[32]="";
	scanf("%s",exm);
	STU *pb=head;
	while(pb != NULL)
	{
		if(strcmp(pb->name,exm) == 0) break;
		pb=pb->next;
	}
	if(pb == NULL) printf("---------------NO DATA FOUND!!!-----------------\n");
	else
	{
		printf("-------------您希望修改该学生的哪一项信息？--------------\n");
		printf("1.修改学号\n");
		printf("2.修改姓名\n");
		printf("3.修改性别\n");
		printf("4.修改专业\n");
		printf("5.修改高等数学成绩\n");
		printf("6.修改程序设计的成绩\n");
		printf("7.修改英语成绩\n");
		printf("8.修改思想道德修养与法律基础的成绩\n"); 
		int n2=0;
		scanf("%d",&n2);
		switch(n2)
		
		{
		case 1: pb->num=alter_num(&pb->num);break;
		case 2: alter_name(pb->name);break;
		case 3: alter_sex(pb->sex);break;
		case 4: alter_major(pb->major);break;
		case 5: alter_math(pb);break;//修改高数成绩 
		case 6: alter_programming(pb);break;//修改程序设计成绩 
		case 7: alter_English(pb);break;//修改英语成绩 
		case 8: alter_Politition(pb);break;//修改思修成绩 
		default:printf("输入信息错误！\n");break;
		}
		
	}
	return head;
} 



//链表的内容修改之学号修改
 int alter_num(int *num)
 {
 	printf("--请输入该生新的学号\n");
 	scanf("%d",num);
 	return *num;
 }
 
 
 
 //链表的内容修改之姓名修改
 void alter_name(char *name) 
 {
 	printf("--请输入该生新的姓名：\n");
 	scanf("%s",name);
 	return;
 }
 
 
 
 //链表的内容修改之性别修改
 void alter_sex(char *sex)
 {
 	printf("----请输入该生新的性别：\n");
 	scanf("%s",sex);
 	return;
 }
 
 //链表的内容修改之高数成绩的修改
 void alter_math(STU *p)
 {
 	printf("---请输入新的成绩\n");
	scanf("%d",&p->scoreA);
	p->score_sum=p->scoreA+p->scoreB+p->scoreC+p->scoreD;
	printf("-------------------成绩修改完毕!-------------------\n"); 
	return; 
 }
 
 //链表的内容修改之成绩的修改
void alter_programming(STU *p)
 {
 	printf("请输入新的成绩\n");
	scanf("%d",&p->scoreB);
	p->score_sum=p->scoreA+p->scoreB+p->scoreC+p->scoreD;
	printf("成绩修改完毕\n"); 
	return; 
 }
  
//链表的内容修改之成绩的修改
   void alter_English(STU *p)
   {
	printf("请输入新的成绩\n");
	scanf("%d",&p->scoreC);
	p->score_sum=p->scoreA+p->scoreB+p->scoreC+p->scoreD;
	printf("成绩修改完毕\n"); 
	return;
	} 
//链表的内容修改之成绩的修改
  void alter_Politition(STU *p)
  {
  	printf("请输入新的成绩\n");
	scanf("%d",&p->scoreD);
	p->score_sum=p->scoreA+p->scoreB+p->scoreC+p->scoreD;
	printf("成绩修改完毕\n"); 
	return;
  }
 //链表的内容修改之专业修改
void alter_major(char *major)
{
	printf("请输入该生新的专业：\n");
 	scanf("%s",major);
 	return;
}



//登录 
ADM *Sys_Login(void)
{
	ADM *sample=NULL;
	sample=File_adm_write();
	if(sample==NULL)
	{
		printf("文件拉取出错或者没有学生数据！\n");
		printf("请注册新账号！\n"); 
	}
	else printf("已从文件读取数据！\n"); 
	printf("请输入您需要的操作：\n");
	printf("1.登录(新用户请选择第二项，否则可能导致系统崩溃)\n");
	printf("2.创建新的管理账户（注意：此操作将会删除此前所有的数据内容）\n");
	printf("3.退出程序\n");
	int choice=0;
	int test=0;
	while(1)
	{
	test=scanf("%d",&choice);
	if(test==0)
	{
		printf("输入错误！\n");
		continue;
	}
	else break;
	}
	if(choice==1)
	{
		int count3=0; 
		while(1)
		{
		char usernameA[32];//输入账户 
		char codeA[16];//输入密码 
		printf("请输入你的账户：\n");
		scanf("%s",usernameA);
		printf("请输入你的密码：\n");
		scanf("%s",codeA);
		int cmp1=99;//用于返回strcmp的值 
		int cmp2=99;
		cmp1=strncmp(usernameA,sample->username,strlen(sample->username));
		cmp2=strncmp(codeA,sample->code,strlen(sample->code));
		if(cmp1==0&&cmp2==0) return sample;//登录成功 
		else
		{
			count3++;
			if(count3==3)
			{
				printf("您已三次输入错误！\n");
				printf("为保护系统文件，原有的数据将删除！\n");
				printf("是否创建新账户？\n");
				printf("1.是\n");
				printf("2.否，我要退出程序！\n");
				int choice3=0;
				while(1)
				{
					test=scanf("%d",&choice3);
					if(test==0)
					{
						printf("输入错误！\n");
						continue;
					}
					else break;
				}
				if(choice3==1)
				{
					File_memset();
					sample=add_administrator();
					return sample;
				}
				if(choice3==2)
				{
					File_memset();
					return NULL;
				}
			}
			printf("输入的账户或者是密码错误！\n");
			printf("请选择：（输入选项前的序号）\n");
			printf("1.重新输入账户或密码\n");
			printf("2.退出程序\n");
			int temp3=0;
			while(1)
			{
				test=scanf("%d",&temp3);
				if(test==0)
				{
					printf("输入错误！\n");
					continue;
				}
				else break;
			}
			if(temp3==2) return NULL;
			else continue;
		}
		}
	}
	else if(choice==2) 
	{
		File_memset();
		sample=add_administrator();
		return sample;
	}
	else
	{
		return NULL;
	}
}



//管理员信息读取操作 
ADM *File_adm_write(void)
{
	FILE *fp=NULL;
	ADM *pin=NULL;
	pin=(ADM *)malloc(sizeof(ADM));
	fp=fopen("administrator.txt","r");
	if(fp == NULL)
	{
		perror("fopen");
		printf("文件打开时出错！\n");
		return NULL;
	}
	int testnum=0;
	testnum=fread(pin,sizeof(ADM),1,fp);
	fclose(fp); 
	if(testnum != 1)
	{
		printf("读取文件时出错！\n");
		return NULL; 
	}
	return pin;
}



//学生信息读取操作
STU *readFile_stu(STU* head,int count)
{
	if(count == 0) return NULL;
	else
	{
		FILE *fp=NULL;
		fp=fopen("student.txt","r");
		int testnum = 0;
		if(fp == NULL)
		{
			perror("fopen");
			return NULL;
		}
		STU *tmp=NULL;
		tmp=(STU *)calloc(count,sizeof(STU));
		testnum=fread(tmp,sizeof(STU),count,fp);
		fclose(fp);
		if(testnum != count) 
		{
			printf("读入信息错误\n");
			return NULL;
		}else if(testnum == 0) return NULL;
		else return tmp;
	}
} 




//新增管理员信息
ADM *add_administrator(void)
{
	ADM *newuser=NULL;
	newuser=(ADM *)malloc(sizeof(ADM));
	printf("请输入账户名\n");
	scanf("%s",newuser->username);
	printf("请输入您的密码\n");
	scanf("%s",newuser->code);
	newuser->stepcount=0;
	printf("创建完毕！该管理员信息会在系统合法退出后保存。\n");
	return newuser;
}



//清空文件 
void File_memset(void)
{
	FILE *fp1=NULL;
	 if((fp1=fopen("student.txt","w"))==NULL)  
    {    
	    perror("fopen");
        return;
    }
    FILE *fp2=NULL;
	if((fp2=fopen("administrator.txt","w"))==NULL)  
    {    
	    perror("fopen");
        return;
    }
    fputs("0",fp2);
    fputs("0",fp1);
    fclose(fp1);
    fclose(fp2);
    return;
}



//创建链表
STU *stu_link_made(STU *head,int count)
{
	int i=1;
	STU *pb=head;
	STU *pf=head;
	if(head == NULL)
	{
		return NULL;
	}
	else
	{
		while(i<count)
		{
			pb++;
			pf->next=pb;
			pf++;
			i++;
		}
		pb->next=NULL;
	}
	return head;
} 



//学生信息链表转数组 
STU *Trans_link_to_arr(STU *head,int count)
{
	int i=0;
	STU *pb=head;
	STU *temp;
	temp=(STU *)calloc(count,sizeof(STU));
	for(i=0;pb!=NULL;i++)
	{
		*(temp+i)=*pb;
		pb=pb->next;
	}
	return temp;
}



//将学生信息写入文件 
void writeFile_stu(STU *savehead,int count)
{
	FILE *fp=NULL;
	int testnum=0;
	fp=fopen("student.txt","w");
	if(fp==NULL)
	{
		perror("fopen");
		return;
	}
	testnum=fwrite(savehead,sizeof(STU),count,fp);printf("已保存%d个学生的信息\n",testnum);
	fclose(fp);
	return;
}



//将管理员信息写入文件
void writeFile_adm(ADM *admpin)
{
	FILE *fp=NULL;
	int testnum=0;
	fp=fopen("administrator.txt","w");
	if(fp == NULL)
	{
		perror("fopen");
		return;	
	}
	testnum=fwrite(admpin,sizeof(ADM),1,fp);
	printf("已保存%d个管理员的信息\n",testnum);
	fclose(fp);
	return;
} 



//按照当前顺序输出学生
void print_order(STU *head)
{
	STU *pb=head;
	if(pb == NULL)
	{
		printf("NO DATA FOND!!!\n");
		return;
	}
	else
	{
		while(pb != NULL)
		{
			printf("学生学号：%05d",pb->num);printf(" "); 
			printf("学生姓名：%*s",5,pb->name);printf(" ");
			printf("学生性别：%*s",2,pb->sex);printf(" ");
			printf("学生专业：%*s",8,pb->major);printf("\n");
			printf("该学生成绩如下：\n");
			printf("高等数学成绩：%5d",pb->scoreA);printf(" ");
			printf("程序设计成绩：%5d",pb->scoreB);printf(" ");
			printf("大学英语成绩：%5d",pb->scoreC);printf(" ");
			printf("思修教育成绩：%5d",pb->scoreD);printf(" ");
			printf("该学期总成绩：%5d",pb->score_sum);printf("\n");
			pb=pb->next;
		}
	}
	return;
}



//按照性别选择
void print_sex(STU *head)
{
	printf("请选择您要提取的性别\n");
	printf("1.男\n");
	printf("2.女\n");
	int choice_sex = 0;
	scanf("%d",&choice_sex);
	switch(choice_sex)
	{
		case 1:print_man(head);break;
		case 2:print_woman(head);break;
		default:print_sex(head);break;
	}
	return;
}



//打印男性的信息
void print_man(STU *head)
{
	STU *pb=head;
	if(pb == NULL)
	{
		printf("NO DATA FOUND!!!\n");
		return;
	}
	else
	{
		while(pb != NULL)
		{
			if(strcmp(pb->sex,"男") == 0)
			{
			printf("学生学号：%05d",pb->num);printf(" "); 
			printf("学生姓名：%*s",5,pb->name);printf(" ");
			printf("学生性别：%*s",2,pb->sex);printf(" ");
			printf("学生专业：%*s",8,pb->major);printf("\n");
			printf("该学生成绩如下：\n");
			printf("高等数学成绩：%5d",pb->scoreA);printf(" ");
			printf("程序设计成绩：%5d",pb->scoreB);printf(" ");
			printf("大学英语成绩：%5d",pb->scoreC);printf(" ");
			printf("思修教育成绩：%5d",pb->scoreD);printf(" ");
			printf("该学期总成绩：%5d",pb->score_sum);printf("\n");
			}
			pb=pb->next;
		}
		return;
	}	
}



//打印女性的信息
void print_woman(STU *head)
{
	STU *pb=head;
	if(pb==NULL)
	{
		printf("NO DATA FOUND!!!\n");
		return;
	}
	else
	{
		while(pb!=NULL)
		{
			if(strcmp(pb->sex,"女") == 0)
			{
				printf("学生学号：%05d",pb->num);printf(" "); 
				printf("学生姓名：%*s",5,pb->name);printf(" ");
				printf("学生性别：%*s",2,pb->sex);printf(" ");
				printf("学生专业：%*s",8,pb->major);printf("\n");
				printf("该学生成绩如下：\n");
				printf("高等数学成绩：%5d",pb->scoreA);printf(" ");
				printf("程序设计成绩：%5d",pb->scoreB);printf(" ");
				printf("大学英语成绩：%5d",pb->scoreC);printf(" ");
				printf("思修教育成绩：%5d",pb->scoreD);printf(" ");
				printf("该学期总成绩：%5d",pb->score_sum);printf("\n");
			}
			pb=pb->next;
		}
		return;
	}	
}  



//打印操作
void print_msg(STU *head)
{
	int choice_print=0;
	printf("您想根据什么来排序？\n");
	printf("1.学号顺序\n");
	printf("2.男女性别\n");
	printf("3.专业分类\n");
	scanf("%d",&choice_print);
	switch(choice_print)
	{
		case 1:print_order(head);break;
		case 2:print_sex(head);break;
		case 3:print_major(head);break;
		defult:print_msg(head);break;
	}
	return;
}
void print_major(STU *head)
{
	printf("请输入您需要查的专业名称：\n");
	char majorex[16];
	scanf("%s",majorex);
	STU *pb=head;
	if(pb==NULL)
	{
		printf("NO DATA FOUND!!!\n");
		return;
	}
	else
	{
		while(pb!=NULL)
		{
			if(strcmp(pb->major,majorex) == 0)
			{
				printf("学生学号：%05d",pb->num);printf(" "); 
				printf("学生姓名：%*s",5,pb->name);printf(" ");
				printf("学生性别：%*s",2,pb->sex);printf(" ");
				printf("学生专业：%*s",8,pb->major);printf("\n");
				printf("该学生成绩如下：\n");
				printf("高等数学成绩：%5d",pb->scoreA);printf(" ");
				printf("程序设计成绩：%5d",pb->scoreB);printf(" ");
				printf("大学英语成绩：%5d",pb->scoreC);printf(" ");
				printf("思修教育成绩：%5d",pb->scoreD);printf(" ");
				printf("该学期总成绩：%5d",pb->score_sum);printf("\n");
			}
			pb=pb->next;
		}
		return;
	}	
} 



//管理员信息修改函数
void adm_alter(ADM *admpin)
{
	int choice_alter=0;
	printf("请问您需要修改管理员的哪一项信息？\n");
	printf("1.账户名称\n");
	printf("2.密码\n");
	scanf("%d",&choice_alter);
	switch(choice_alter)
	{
		case 1:username_alter(admpin);break;
		case 2:code_alter(admpin);break;
		default:printf("输入错误！\n");adm_alter(admpin);break;
	}
	return;
} 



//管理员账户修改
void username_alter(ADM *admpin)
{
	printf("请输入新的管理员账号：\n");
	scanf("%s",admpin->username); 
	printf("信息修改完毕！"); 
	return; 
} 



//管理员密码修改 
void code_alter(ADM *admpin)
{
	printf("请输入新的管理员密码：\n");
	scanf("%s",admpin->code);
	printf("信息修改完毕！\n");
	return;
}


//打印学生成绩 
void soc_print(STU* head,int n)
{
	int i;
	STU* p = head;
	
	printf("1.打印高数成绩\n");
	printf("2.打印英语成绩\n");
	printf("3.打印程序设计成绩\n");
	printf("4.打印思修成绩\n");
	printf("5.打印总成绩\n"); 
	printf("请选择功能（1~5）：");
	scanf("%d", &i);
	
	if (i == 1)
	{
		int sum1 = 0;
		while (p)
		{
			sum1 += p->scoreA;
			printf("%05d %5s %5d\n", p->num,p->name,p->scoreA);
			p = p->next;
		}
		int average1 = sum1/n;
		printf("高等数学的平均成绩为：%d\n", average1);
	}
	
	else if (i==2)
	{
		int sum2 = 0;
		while (p)
		{
			sum2 += p->scoreB;
			printf("%05d %5s %5d\n", p->num,p->name,p->scoreB);
			p = p->next;
		}
		int average2 = sum2/n;
		printf("程序设计的平均成绩为：%d\n", average2);
	}
	
	else if (i==3)
	{
		int sum3 = 0;
		while (p)
		{
			sum3 += p->scoreC;
			printf("%05d %5s %5d\n", p->num,p->name,p->scoreC);
			p = p->next;
		}
		int average3 = sum3/n;
		printf("大学英语的平均成绩为：%d\n", average3);
	}
	
	else if (i==4)
	{
		int sum4 = 0;
		while (p)
		{
			sum4 += p->scoreD;
			printf("%05d %5s %5d\n", p->num,p->name,p->scoreD);
			p = p->next;
		}
		int average4 = sum4/n;
		printf("思想道德修养的平均成绩：%d\n", average4);
	}
	
	else if (i==5)
	{
		int sum5 = 0;
		while (p)
		{
			sum5 += p->score_sum;
			printf("%05d %5s %5d\n", p->num,p->name,p->score_sum);
			p = p->next;
		}
		int average5 = sum5/n;
		printf("总分的平均成绩为：%d\n", average5);
	}
	return;
}
	STU *soc_registration(STU *head)//批量导入学生成绩
	{
		STU *pb=head;
		if(pb==NULL)
		{
			printf("无学生数据！\n");
			return head;
		}
		printf("是否需要从上次停止登记的地方继续录入？(请输入选项前的序号)\n");
		printf("1.是的\n");
		printf("2.不，我想从头开始覆盖\n");
		int temp2=0;
		scanf("%d",&temp2);
		if(temp2==1)
		{
			while(pb->score_sum!=-1)
			{
				if(pb->next==NULL)
				{
					printf("未找到没有成绩的学生！若要覆盖之前的学生成绩数据，请在指令获取框中重新输入register指令！\n");
					return head; 
				}
				pb=pb->next;
			}
		} 
		while(1)
		{
			printf("学生姓名：%s\n",pb->name);
			printf("高等数学：\n");
			scanf("%d",&pb->scoreA);
			printf("程序设计：\n");
			scanf("%d",&pb->scoreB);
			printf("大学英语：\n");
			scanf("%d",&pb->scoreC);
			printf("思想道德：\n");
			scanf("%d",&pb->scoreD);
			pb->score_sum=pb->scoreA+pb->scoreB+pb->scoreC+pb->scoreD;
			printf("该学生的信息录入完毕！\n");
			if(pb->next==NULL)
			{
				printf("该学生信息已是最后一条!\n");
				return head; 
			}
			printf("是否继续录入成绩？（请填写选择的序号）\n");
			printf("1.是\n");
			printf("2.否\n"); 
			int temp=0;
			scanf("%d",&temp);
			if(temp == 2)
			{
				return head;
			}
			else pb=pb->next;
		}
	 } 
	

