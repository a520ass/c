#include"book.h"
//菜单函数，函数返回值为整数，代表所选的菜单项
int menu_select()
{ 
	char s[80]; 
	int c;
	printf("***************图书管理主菜单******************\n"); 
	printf("             1. 图书录入\n"); 
	printf("             2. 图书借阅信息修改\n");
	printf("             3. 删除图书\n"); 
	printf("             4. 查询图书\n");
	printf("             5. 图书统计输出\n"); 
	printf("             6. 保存图书记录\n"); 
	printf("             7. 加载图书文件\n"); 
	printf("             0. 退出\n"); 
	printf("***********************************************\n"); 
	do
	{ 
		printf("\n         输入您的菜单选项编号(0-7):"); //提示输入选项 
		scanf("%s",s);
		c=atoi(s);
		getchar();
	}while(c<0||c>7);							//选择项不在0~7之间重输 
	return c;																		//返回选择项，主程序根据该数调用相应的函数 
}
//输入记录，形参为结构体数组，函数值返回类型为整型表示记录长度 
int enter(BOOKS b[])
{ 
	int i,n;
	char time[20];
	system("cls");
	printf("\n请输入图书记录条数：\n");  
	scanf("%d",&n);							//输入记录数
	printf("请输入录入时间:");
	scanf("%s",time);
	for(i=0;i<n;i++)
	{
		strcpy(b[i].enteringtime,time);						//输入录入时间
	}
	printf("请输入图书记录：\n");
	printf("图书编号     书名     出版社     作者     ISBN号     单价\n"); 
	printf("---------------------------------------------------------\n"); 
	for (i=0;i<n;i++) 
	{ 
		scanf("%s",b[i].number);					//输入图书编号
		scanf("%s",b[i].title);					//输入书名
		scanf("%s",b[i].press);					//输入出版社
		scanf("%s",b[i].author);					//输入作者
		scanf("%s",b[i].ISBN);					//输入ISBN号
		scanf("%d",&b[i].price);					//输入单价
		b[i].status=-1;
	} 
	getchar();
	return n;									//返回记录条数 	
} 
//按书名查找函数，参数为记录数组和记录条数以及书名s  
int find_title(BOOKS b[],int n,char *s) 
{ 
	int i; 
	for(i=0;i<n;i++)                   	//记录开始，直到最后一条 
	{ 
		if(strcmp(s,b[i].title)==0)       //记录中的书名和待比较的书名是否相等 
			return i;              	//相等，则返回该记录的下标号，程序提前结束 
	} 
	return i;                          //返回i值 
}
//删除函数，参数为记录数组和记录条数 
int del(BOOKS b[],int n) 
{ 
	char s[20];								//要删除记录的书名 
	int ch=0; 
	int i; 
	printf("请输入要删除的图书书名:\n");  
	scanf("%s",s);								//输入图书书名 
	getchar();
	i=find_title(b,n,s);							//调用find_title函数 
	if(i==n)
		printf("没有找到书名为%s的图书！\n",s);
	else
	{
		printf("正在删除中！\n");
		for(;i<n;i++)							//从删除位置开始依次前移图书记录
		{ 
			strcpy(b[i].number,b[i+1].number); 
			strcpy(b[i].title,b[i+1].title); 
			strcpy(b[i].press,b[i+1].press); 
			strcpy(b[i].author,b[i+1].author); 
			strcpy(b[i].ISBN,b[i+1].ISBN);
			b[i].price=b[i+1].price;               
		} 
		n--;									//删除后记录数减1
		printf("删除成功！\n");	
	}
	return n;																		//返回记录数 
}
//修改函数，按照借出和归还修改
void modify(BOOKS b[],int n)
{
	char title[20];                      		//要修改记录的图书名 
	int ch=0; 
	int i,x;  
	system("cls");
	printf("*****图书修改菜单*****:\n"); 
	printf("     1.借出图书     \n");
	printf("     2.归还图书     \n");
	printf("\n输入您的菜单选项编号(1-2):");
	scanf("%d",&x);
	if(x==1)
	{	printf("请输入要借出的图书书名:\n");
	scanf("%s",title);						//输入图书名
	i=find_title(b,n,title); 						//调用find_title函数 
	if(i==n)
	{
		printf("没有找到书名为%s的图书！\n",title);
		getchar();
		return;
	}
	else
		printf("请输入借出时间:");
	scanf("%s",b[i].loantime);
	if(b[i].status==0)
		printf("书名为%s图书已借出，无法再次借出！\n",title);
	else
		printf("已借出书名为%s的图书！\n",title);
	b[i].status=0;						//更改状态
	getchar();
	}
	else
	{
		if(x==2)
			printf("请输入要归还的图书书名:\n");
		scanf("%s",title);
		i=find_title(b,n,title); 						//调用find_title函数
		if(i==n)
		{	printf("要归还的书名为%s的图书未录入系统\n",title);
		getchar();
		return;
		}
		else
			printf("请输入归还时间:");
		scanf("%s",b[i].returntime);
		b[i].status=1;						//更改状态
		printf("已归还书名为%s的图书！\n",title);
		getchar();
	}
}
//查询函数 
void search(BOOKS b[],int n) 
{ 
	char time1[20],time2[20];								
	int i,x,y;										
	system("cls");
	printf("********查询菜单********\n"); 						//查询菜单
	printf("     1.按时间段查询\n");
	printf("     2.按时间查询\n");
	printf("\n输入您的菜单选项编号(1-2):");
	scanf("%d",&x);								
	if(x==1)
	{
		printf("请输入时间段:");
		scanf("%s %s",time1,time2);
		system("cls");                           		//清屏
		printf("\n从%s到%s时间段的图书借出信息如下\n",time1,time2);
		printf("图书编号\t书名\t出版社\t作者\tISBN号\t单价\t状态\t借出时间\n");
		for(i=0;i<n;i++)
		{
			if(strcmp(b[i].loantime,time2)<=0&&strcmp(b[i].loantime,time1)>=0)						//判断借出时间是否在该时间段
				if(b[i].status==0)printf("%s\t\t%s\t%s\t%s\t%s\t%d\t%d\t%s\n",b[i].number,b[i].title,b[i].press,b[i].author,b[i].ISBN,b[i].price,b[i].status,b[i].loantime);
		}
		printf("\n从%s到%s时间段的图书归还信息如下\n",time1,time2);
		printf("图书编号\t书名\t出版社\t作者\tISBN号\t单价\t状态\t归还时间\n");
		for(i=0;i<n;i++)
		{
			if(strcmp(b[i].returntime,time2)<=0&&strcmp(b[i].returntime,time1)>=0)						//判断归还时间是否在该时间段
				if(b[i].status==1)printf("%s\t\t%s\t%s\t%s\t%s\t%d\t%d\t%s\n",b[i].number,b[i].title,b[i].press,b[i].author,b[i].ISBN,b[i].price,b[i].status,b[i].returntime);
		}
		getchar();
	}
	else
		if(x==2)
		{
			system("cls");                           		//清屏
			printf("********按时间查询菜单********\n"); 
			printf("     1.按借出时间查询\n");
			printf("     2.按归还时间查询\n");
			printf("\n输入您的菜单选项编号(1-2):");
			scanf("%d",&y);
			if(y==1)
			{	printf("请输入借出时间:");
			scanf("%s",time1);
			printf("借出时间为%s的图书信息如下\n",time1);
			printf("图书编号\t书名\t出版社\t作者\tISBN号\t单价\t状态\n");
			for(i=0;i<n;i++)
			{
				if(strcmp(b[i].loantime,time1)==0)						//判断借出时间是否等于用户所要查询的时间
					printf("%s\t\t%s\t%s\t%s\t%s\t%d\t%d\n",b[i].number,b[i].title,b[i].press,b[i].author,b[i].ISBN,b[i].price,b[i].status);
		getchar();
		return;
			}
			}
			else
				printf("请输入归还时间:");
			scanf("%s",time1);
			printf("归还时间为%s的图书信息如下\n",time1);
			printf("图书编号\t书名\t出版社\t作者\tISBN号\t单价\t状态\n");
			for(i=0;i<n;i++)
			{
				if(strcmp(b[i].returntime,time1)==0)						//判断归还时间是否等于用户所要查询的时间
					printf("%s\t\t%s\t%s\t%s\t%s\t%d\t%d\n",b[i].number,b[i].title,b[i].press,b[i].author,b[i].ISBN,b[i].price,b[i].status);
		getchar();
		return;
			}
		}
}
//保存函数，参数为结构体数组和记录数 
void save(BOOKS b[],int n) 
{ 
	int i; 
	FILE *fp; 							//指向文件的指针 
	if((fp=fopen("图书信息.txt","w"))==NULL)	//打开文件，并判断打开是否正常 
	{ 
		printf("无法打开学生记录文件！\n");			//打开失败 
		exit(1);  									//退出 
	} 
	printf("\n正在保存中\n"); 
	fprintf(fp,"%d",n);  							//将记录数写入文件 
	fprintf(fp,"\r\n");  								//将换行符号写入文件 
	for(i=0;i<n;i++) 
	{ 
		fprintf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\n",b[i].enteringtime,b[i].number,b[i].title,b[i].press,b[i].author,b[i].ISBN,b[i].price,b[i].status);
		//格式写入记录 
		fprintf(fp,"\r\n");							//将换行符号写入文件 
	} 
	fclose(fp);									//关闭文件 
	printf("****保存成功***\n");					//显示保存成功 
} 
//读入函数，参数为结构体数组 
int load(BOOKS b[]) 
{ 
	int i,n; 
	FILE *fp;										//指向文件的指针 
	if((fp=fopen("图书信息.txt","r"))==NULL)			//打开文件 
	{ 
		printf("无法打开学生记录文件！\n");			//打开失败 
		exit(1);									//退出 
	} 
	fscanf(fp,"%d",&n);                           	//读入记录数 
	for(i=0;i<n;i++) 
		fscanf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\n",b[i].enteringtime,b[i].number,b[i].title,b[i].press,b[i].author,b[i].ISBN,&b[i].price,&b[i].status); 
	//按格式读入记录 
	fclose(fp);                                   	//关闭文件 
	printf("已经成功加载学生记录文件到内存!\n");   	//显示保存成功 
	return n;                                    	//返回记录数 
}
//统计函数
void statistics(BOOKS b[],int n)
{
	printf("请输入时间段：");
	char time1[20],time2[20];
	int i,j,k;										
	scanf("%s %s",time1,time2);
	system("cls");                           		//清屏
	printf("从%s到%s时间段的图书录入信息如下\n",time1,time2);
	printf("图书编号\t书名\t出版社\t作者\tISBN号\t单价\t状态\t录入时间\n");
	for(i=0;i<n;i++)
	{
		if(strcmp(b[i].enteringtime,time2)<=0&&strcmp(b[i].enteringtime,time1)>=0)						//判断录入时间是否在该时间段
			printf("%s\t\t%s\t%s\t%s\t%s\t%d\t%d\t%s\n",b[i].number,b[i].title,b[i].press,b[i].author,b[i].ISBN,b[i].price,b[i].status,b[i].enteringtime);
	}
	printf("\n图书总数为%d\n",n);
	printf("\n从%s到%s时间段的图书借出信息如下\n",time1,time2);
	printf("图书编号\t书名\t出版社\t作者\tISBN号\t单价\t状态\t借出时间\n");
	for(i=0,j=0;i<n;i++)
	{
		if(strcmp(b[i].loantime,time2)<=0&&strcmp(b[i].loantime,time1)>=0)						//判断借出时间是否在该时间段
			if(b[i].status==0)
			{j++;
			printf("%s\t\t%s\t%s\t%s\t%s\t%d\t%d\t%s\n",b[i].number,b[i].title,b[i].press,b[i].author,b[i].ISBN,b[i].price,b[i].status,b[i].loantime);
			}
	}
	printf("\n借出的图书总数为%d\n",j);
	printf("\n从%s到%s时间段的图书归还信息如下\n",time1,time2);
	printf("图书编号\t书名\t出版社\t作者\tISBN号\t单价\t状态\t归还时间\n");
	for(i=0,k=0;i<n;i++)
	{
		if(strcmp(b[i].returntime,time2)<=0&&strcmp(b[i].returntime,time1)>=0)							//判断归还时间是否在该时间段
			if(b[i].status==1)
			{	k++;
				printf("%s\t\t%s\t%s\t%s\t%s\t%d\t%d\t%s\n",b[i].number,b[i].title,b[i].press,b[i].author,b[i].ISBN,b[i].price,b[i].status,b[i].returntime);
			}
	}
	printf("\n已归还的图书总数为%d\n",k);
	getchar();
}
