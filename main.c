#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include"link.h"
int main()
{
	//定义一个变量用于保存当前学生的个数 
	int count=0;
	//定义一个管理员结构体指针，用于访问管理员的信息
	ADM *admpin=NULL;
	//若登陆失败，则改指针保存的地址为空，只有在重置管理员信息后或者是密码输入正确后，该指针才能访问管理员结构体中保存的数据 
	admpin=Sys_Login();
	if(admpin == NULL)//如果登陆失败，指针为空 ，则退出程序 
	{
		printf("执行出错或者是由用户选择退出\n"); 
		return 0;
	}
	count=admpin->stepcount;//传入学生个数 
	//登录成功了，打印功能菜单 
	stu_help(); //此函数打印该系统菜单 
	STU *head=NULL;//定义学生结构体的指针，用于读取、改动数据 
	//接下来从学生文件中读取学生信息 
	head=readFile_stu(head,count); 
	//打印反馈信息 
	printf("开始创建链表...\n");
	//由于保存在文件中的数据是以数组的方式保存，现将每个数组元素转换为单向链表的方式在内存进行存储 
	head=stu_link_made(head,count);
	//打印反馈信息 
	printf("链表创建完毕！\n"); 
	while(1)
	{
		char cmd[32]="";
		printf("请输入操作指令：");
		scanf("%s",cmd);
		//选择功能 
		if(strcmp(cmd,"help") == 0) //打印菜单 
		{
			stu_help(); 
		}
		//插入一条学生的信息，本系统采用了三种方式去插入一条学生的信息 
		else if(strcmp(cmd,"insert") == 0) 
		{
			 printf("-------insert------\n");
			 while(1)
			 {
			 	STU tmp;//定义一个临时结构体 
			 	printf("请输入学生学号：");
			 	scanf("%d",&tmp.num);
				printf("请输入学生姓名：");
				scanf("%s",tmp.name);
				printf("请输入学生的性别：");
				scanf("%s",tmp.sex);
				printf("请输入学生的专业：");
			 	scanf("%s",&tmp.major); 
			 	tmp.scoreA=-1;//初始化成绩 
			 	tmp.scoreB=-1;
				tmp.scoreC=-1;
				tmp.scoreD=-1;
			 	tmp.score_sum=-1; 
			 	//insert_linkC是按照学号有序插入学生信息 
			 	head=insert_linkC(head,tmp);
			 	printf("该学生信息录入完成！\n");
				count++;//插入一条学生信息后，学生的个数加一
				printf("是否继续添加学生信息？（请输入选项前的序号）\n");
				printf("1.是\n");
				printf("2.否\n");
				int temp1=0;
				scanf("%d",&temp1);
				if(temp1==2)
				{
					printf("已停止录入！\n");
					break;
				}
			  } 
		}
		//搜索学生信息 
		else if(strcmp(cmd,"search") == 0)
		{
			 printf("-------search------\n");//链表的查询 
			 printf("你希望通过什么样的方式进行查询？(请输入选项前的数字）\n");
			 printf("1.通过学号\n");
			 printf("2.通过姓名\n");
			 int example=0;
			 scanf("%d",&example);//通过序号来选择查找方式 
			 switch(example)
			 {
			 	case 1:search_num(head);break;//按照学号查找 
				case 2:search_name(head);break;//按照姓名查找 
				default:printf("输入的信号有误\n");break;//用户输入的信号不明，打印错误信息 
			 } 
		}
		//删除学生信息 
		else if(strcmp(cmd,"delete") == 0)//链表的删除 
		{
			 printf("-------delete------\n");
			 head=delete_link(head);
			 count--;//删除一条学生的信息后，学生的个数减一 
		}
		//释放整个链表的空间（清空） 
		else if(strcmp(cmd,"free") == 0)//整个链表的释放 
		{
			 printf("-------free------\n");
			 head=free_link(head,&count);
			 //释放完整个链表，重置学生的个数 
			 count=0;
			 continue;
		}
		//退出程序
		//注意：退出程序将分三个步骤进行
		//第一：将学生的信息链表转换为数组的形式存储
		//第二：将学生的信息数组写入磁盘文件
		//第三：将管理员的信息写入磁盘文件 
		else if(strcmp(cmd,"quit") == 0)
		{ 
			admpin->stepcount=count;//保存学生个数 
			STU *savehead=NULL;
			printf("----------正在保存学生的信息...\n");
			//第一步：将学生信息的链表结构转换为数组结构 
			savehead=Trans_link_to_arr(head,count);
			//第二步：结构体数组写入文件 
			writeFile_stu(savehead,count);
			//打印反馈信息 
			printf("----------学生的信息保存完毕!----------\n");
			printf("正在保存管理员的信息...\n");
			//将管理员的信息写入文件 
			writeFile_adm(admpin);
			//打印反馈信息 
			printf("----------管理员的信息保存完毕!---------\n");
			printf("---------------------感谢您使用本系统!---------------------\n");
			int aad=0;
			printf("----------是否退出？----------\n");
			printf("--1.是\n");
			printf("--2.否\n");
			scanf("%d",&aad);
			if(aad == 1)
			{
				break;
			}
			else
			{
				continue;
			}
		}
		else if(strcmp(cmd,"print") == 0)//打印链表 
		{
			 printf("-------print------\n");
			 print_msg(head);
			 continue; 
		}
		else if(strcmp(cmd,"alteration") == 0)//修改学生信息功能 
		{
			printf("-------alteration------\n");
			int n1=0;
			head=alteration_link(head);
			continue;
		}
		else if(strcmp(cmd,"adm_alteration") == 0)//修改管理员信息功能 
		{
			adm_alter(admpin);
			continue;
		}
		else if(strcmp(cmd,"soc_print") == 0)//打印学生成绩 
		{
			soc_print(head,count);
			continue;
		}
		else if(strcmp(cmd,"register") == 0)
		{
			soc_registration( head );
			continue;
		}
		
	}	
	return 0;
} 
