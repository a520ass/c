#include"book.h"
//�˵���������������ֵΪ������������ѡ�Ĳ˵���
int menu_select()
{ 
	char s[80]; 
	int c;
	printf("***************ͼ��������˵�******************\n"); 
	printf("             1. ͼ��¼��\n"); 
	printf("             2. ͼ�������Ϣ�޸�\n");
	printf("             3. ɾ��ͼ��\n"); 
	printf("             4. ��ѯͼ��\n");
	printf("             5. ͼ��ͳ�����\n"); 
	printf("             6. ����ͼ���¼\n"); 
	printf("             7. ����ͼ���ļ�\n"); 
	printf("             0. �˳�\n"); 
	printf("***********************************************\n"); 
	do
	{ 
		printf("\n         �������Ĳ˵�ѡ����(0-7):"); //��ʾ����ѡ�� 
		scanf("%s",s);
		c=atoi(s);
		getchar();
	}while(c<0||c>7);							//ѡ�����0~7֮������ 
	return c;																		//����ѡ�����������ݸ���������Ӧ�ĺ��� 
}
//�����¼���β�Ϊ�ṹ�����飬����ֵ��������Ϊ���ͱ�ʾ��¼���� 
int enter(BOOKS b[])
{ 
	int i,n;
	char time[20];
	system("cls");
	printf("\n������ͼ���¼������\n");  
	scanf("%d",&n);							//�����¼��
	printf("������¼��ʱ��:");
	scanf("%s",time);
	for(i=0;i<n;i++)
	{
		strcpy(b[i].enteringtime,time);						//����¼��ʱ��
	}
	printf("������ͼ���¼��\n");
	printf("ͼ����     ����     ������     ����     ISBN��     ����\n"); 
	printf("---------------------------------------------------------\n"); 
	for (i=0;i<n;i++) 
	{ 
		scanf("%s",b[i].number);					//����ͼ����
		scanf("%s",b[i].title);					//��������
		scanf("%s",b[i].press);					//���������
		scanf("%s",b[i].author);					//��������
		scanf("%s",b[i].ISBN);					//����ISBN��
		scanf("%d",&b[i].price);					//���뵥��
		b[i].status=-1;
	} 
	getchar();
	return n;									//���ؼ�¼���� 	
} 
//���������Һ���������Ϊ��¼����ͼ�¼�����Լ�����s  
int find_title(BOOKS b[],int n,char *s) 
{ 
	int i; 
	for(i=0;i<n;i++)                   	//��¼��ʼ��ֱ�����һ�� 
	{ 
		if(strcmp(s,b[i].title)==0)       //��¼�е������ʹ��Ƚϵ������Ƿ���� 
			return i;              	//��ȣ��򷵻ظü�¼���±�ţ�������ǰ���� 
	} 
	return i;                          //����iֵ 
}
//ɾ������������Ϊ��¼����ͼ�¼���� 
int del(BOOKS b[],int n) 
{ 
	char s[20];								//Ҫɾ����¼������ 
	int ch=0; 
	int i; 
	printf("������Ҫɾ����ͼ������:\n");  
	scanf("%s",s);								//����ͼ������ 
	getchar();
	i=find_title(b,n,s);							//����find_title���� 
	if(i==n)
		printf("û���ҵ�����Ϊ%s��ͼ�飡\n",s);
	else
	{
		printf("����ɾ���У�\n");
		for(;i<n;i++)							//��ɾ��λ�ÿ�ʼ����ǰ��ͼ���¼
		{ 
			strcpy(b[i].number,b[i+1].number); 
			strcpy(b[i].title,b[i+1].title); 
			strcpy(b[i].press,b[i+1].press); 
			strcpy(b[i].author,b[i+1].author); 
			strcpy(b[i].ISBN,b[i+1].ISBN);
			b[i].price=b[i+1].price;               
		} 
		n--;									//ɾ�����¼����1
		printf("ɾ���ɹ���\n");	
	}
	return n;																		//���ؼ�¼�� 
}
//�޸ĺ��������ս���͹黹�޸�
void modify(BOOKS b[],int n)
{
	char title[20];                      		//Ҫ�޸ļ�¼��ͼ���� 
	int ch=0; 
	int i,x;  
	system("cls");
	printf("*****ͼ���޸Ĳ˵�*****:\n"); 
	printf("     1.���ͼ��     \n");
	printf("     2.�黹ͼ��     \n");
	printf("\n�������Ĳ˵�ѡ����(1-2):");
	scanf("%d",&x);
	if(x==1)
	{	printf("������Ҫ�����ͼ������:\n");
	scanf("%s",title);						//����ͼ����
	i=find_title(b,n,title); 						//����find_title���� 
	if(i==n)
	{
		printf("û���ҵ�����Ϊ%s��ͼ�飡\n",title);
		getchar();
		return;
	}
	else
		printf("��������ʱ��:");
	scanf("%s",b[i].loantime);
	if(b[i].status==0)
		printf("����Ϊ%sͼ���ѽ�����޷��ٴν����\n",title);
	else
		printf("�ѽ������Ϊ%s��ͼ�飡\n",title);
	b[i].status=0;						//����״̬
	getchar();
	}
	else
	{
		if(x==2)
			printf("������Ҫ�黹��ͼ������:\n");
		scanf("%s",title);
		i=find_title(b,n,title); 						//����find_title����
		if(i==n)
		{	printf("Ҫ�黹������Ϊ%s��ͼ��δ¼��ϵͳ\n",title);
		getchar();
		return;
		}
		else
			printf("������黹ʱ��:");
		scanf("%s",b[i].returntime);
		b[i].status=1;						//����״̬
		printf("�ѹ黹����Ϊ%s��ͼ�飡\n",title);
		getchar();
	}
}
//��ѯ���� 
void search(BOOKS b[],int n) 
{ 
	char time1[20],time2[20];								
	int i,x,y;										
	system("cls");
	printf("********��ѯ�˵�********\n"); 						//��ѯ�˵�
	printf("     1.��ʱ��β�ѯ\n");
	printf("     2.��ʱ���ѯ\n");
	printf("\n�������Ĳ˵�ѡ����(1-2):");
	scanf("%d",&x);								
	if(x==1)
	{
		printf("������ʱ���:");
		scanf("%s %s",time1,time2);
		system("cls");                           		//����
		printf("\n��%s��%sʱ��ε�ͼ������Ϣ����\n",time1,time2);
		printf("ͼ����\t����\t������\t����\tISBN��\t����\t״̬\t���ʱ��\n");
		for(i=0;i<n;i++)
		{
			if(strcmp(b[i].loantime,time2)<=0&&strcmp(b[i].loantime,time1)>=0)						//�жϽ��ʱ���Ƿ��ڸ�ʱ���
				if(b[i].status==0)printf("%s\t\t%s\t%s\t%s\t%s\t%d\t%d\t%s\n",b[i].number,b[i].title,b[i].press,b[i].author,b[i].ISBN,b[i].price,b[i].status,b[i].loantime);
		}
		printf("\n��%s��%sʱ��ε�ͼ��黹��Ϣ����\n",time1,time2);
		printf("ͼ����\t����\t������\t����\tISBN��\t����\t״̬\t�黹ʱ��\n");
		for(i=0;i<n;i++)
		{
			if(strcmp(b[i].returntime,time2)<=0&&strcmp(b[i].returntime,time1)>=0)						//�жϹ黹ʱ���Ƿ��ڸ�ʱ���
				if(b[i].status==1)printf("%s\t\t%s\t%s\t%s\t%s\t%d\t%d\t%s\n",b[i].number,b[i].title,b[i].press,b[i].author,b[i].ISBN,b[i].price,b[i].status,b[i].returntime);
		}
		getchar();
	}
	else
		if(x==2)
		{
			system("cls");                           		//����
			printf("********��ʱ���ѯ�˵�********\n"); 
			printf("     1.�����ʱ���ѯ\n");
			printf("     2.���黹ʱ���ѯ\n");
			printf("\n�������Ĳ˵�ѡ����(1-2):");
			scanf("%d",&y);
			if(y==1)
			{	printf("��������ʱ��:");
			scanf("%s",time1);
			printf("���ʱ��Ϊ%s��ͼ����Ϣ����\n",time1);
			printf("ͼ����\t����\t������\t����\tISBN��\t����\t״̬\n");
			for(i=0;i<n;i++)
			{
				if(strcmp(b[i].loantime,time1)==0)						//�жϽ��ʱ���Ƿ�����û���Ҫ��ѯ��ʱ��
					printf("%s\t\t%s\t%s\t%s\t%s\t%d\t%d\n",b[i].number,b[i].title,b[i].press,b[i].author,b[i].ISBN,b[i].price,b[i].status);
		getchar();
		return;
			}
			}
			else
				printf("������黹ʱ��:");
			scanf("%s",time1);
			printf("�黹ʱ��Ϊ%s��ͼ����Ϣ����\n",time1);
			printf("ͼ����\t����\t������\t����\tISBN��\t����\t״̬\n");
			for(i=0;i<n;i++)
			{
				if(strcmp(b[i].returntime,time1)==0)						//�жϹ黹ʱ���Ƿ�����û���Ҫ��ѯ��ʱ��
					printf("%s\t\t%s\t%s\t%s\t%s\t%d\t%d\n",b[i].number,b[i].title,b[i].press,b[i].author,b[i].ISBN,b[i].price,b[i].status);
		getchar();
		return;
			}
		}
}
//���溯��������Ϊ�ṹ������ͼ�¼�� 
void save(BOOKS b[],int n) 
{ 
	int i; 
	FILE *fp; 							//ָ���ļ���ָ�� 
	if((fp=fopen("ͼ����Ϣ.txt","w"))==NULL)	//���ļ������жϴ��Ƿ����� 
	{ 
		printf("�޷���ѧ����¼�ļ���\n");			//��ʧ�� 
		exit(1);  									//�˳� 
	} 
	printf("\n���ڱ�����\n"); 
	fprintf(fp,"%d",n);  							//����¼��д���ļ� 
	fprintf(fp,"\r\n");  								//�����з���д���ļ� 
	for(i=0;i<n;i++) 
	{ 
		fprintf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\n",b[i].enteringtime,b[i].number,b[i].title,b[i].press,b[i].author,b[i].ISBN,b[i].price,b[i].status);
		//��ʽд���¼ 
		fprintf(fp,"\r\n");							//�����з���д���ļ� 
	} 
	fclose(fp);									//�ر��ļ� 
	printf("****����ɹ�***\n");					//��ʾ����ɹ� 
} 
//���뺯��������Ϊ�ṹ������ 
int load(BOOKS b[]) 
{ 
	int i,n; 
	FILE *fp;										//ָ���ļ���ָ�� 
	if((fp=fopen("ͼ����Ϣ.txt","r"))==NULL)			//���ļ� 
	{ 
		printf("�޷���ѧ����¼�ļ���\n");			//��ʧ�� 
		exit(1);									//�˳� 
	} 
	fscanf(fp,"%d",&n);                           	//�����¼�� 
	for(i=0;i<n;i++) 
		fscanf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\n",b[i].enteringtime,b[i].number,b[i].title,b[i].press,b[i].author,b[i].ISBN,&b[i].price,&b[i].status); 
	//����ʽ�����¼ 
	fclose(fp);                                   	//�ر��ļ� 
	printf("�Ѿ��ɹ�����ѧ����¼�ļ����ڴ�!\n");   	//��ʾ����ɹ� 
	return n;                                    	//���ؼ�¼�� 
}
//ͳ�ƺ���
void statistics(BOOKS b[],int n)
{
	printf("������ʱ��Σ�");
	char time1[20],time2[20];
	int i,j,k;										
	scanf("%s %s",time1,time2);
	system("cls");                           		//����
	printf("��%s��%sʱ��ε�ͼ��¼����Ϣ����\n",time1,time2);
	printf("ͼ����\t����\t������\t����\tISBN��\t����\t״̬\t¼��ʱ��\n");
	for(i=0;i<n;i++)
	{
		if(strcmp(b[i].enteringtime,time2)<=0&&strcmp(b[i].enteringtime,time1)>=0)						//�ж�¼��ʱ���Ƿ��ڸ�ʱ���
			printf("%s\t\t%s\t%s\t%s\t%s\t%d\t%d\t%s\n",b[i].number,b[i].title,b[i].press,b[i].author,b[i].ISBN,b[i].price,b[i].status,b[i].enteringtime);
	}
	printf("\nͼ������Ϊ%d\n",n);
	printf("\n��%s��%sʱ��ε�ͼ������Ϣ����\n",time1,time2);
	printf("ͼ����\t����\t������\t����\tISBN��\t����\t״̬\t���ʱ��\n");
	for(i=0,j=0;i<n;i++)
	{
		if(strcmp(b[i].loantime,time2)<=0&&strcmp(b[i].loantime,time1)>=0)						//�жϽ��ʱ���Ƿ��ڸ�ʱ���
			if(b[i].status==0)
			{j++;
			printf("%s\t\t%s\t%s\t%s\t%s\t%d\t%d\t%s\n",b[i].number,b[i].title,b[i].press,b[i].author,b[i].ISBN,b[i].price,b[i].status,b[i].loantime);
			}
	}
	printf("\n�����ͼ������Ϊ%d\n",j);
	printf("\n��%s��%sʱ��ε�ͼ��黹��Ϣ����\n",time1,time2);
	printf("ͼ����\t����\t������\t����\tISBN��\t����\t״̬\t�黹ʱ��\n");
	for(i=0,k=0;i<n;i++)
	{
		if(strcmp(b[i].returntime,time2)<=0&&strcmp(b[i].returntime,time1)>=0)							//�жϹ黹ʱ���Ƿ��ڸ�ʱ���
			if(b[i].status==1)
			{	k++;
				printf("%s\t\t%s\t%s\t%s\t%s\t%d\t%d\t%s\n",b[i].number,b[i].title,b[i].press,b[i].author,b[i].ISBN,b[i].price,b[i].status,b[i].returntime);
			}
	}
	printf("\n�ѹ黹��ͼ������Ϊ%d\n",k);
	getchar();
}
