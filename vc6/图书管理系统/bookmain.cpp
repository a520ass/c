#include"book.cpp"
//��������ʼ
void main() 
{	
	BOOKS book[M];                          		//����ṹ������ 
	int length;                                  		//�����¼����
	for(;;)                                      		//����ѭ��
	{
		system("cls");                           		//����
		switch(menu_select())            //�������˵�����������ֵ��Ϊ������������
		{
		case 1:length=enter(book);break;         		//�����¼
		case 2:modify(book,length);break;        		//�޸�
		case 3:length=del(book,length);break;     		//������ɾ����¼
		case 4:search(book,length);break;        		//��������ѯ
		case 5:statistics(book,length);break;        		//��ʱ���ͳ��
		case 6:save(book,length);break;         	 	//�����ļ�
		case 7:length=load(book);break;         		//�����ļ����ڴ�
		case 0:exit(0);                     		//�������
		}
		printf("���س����������˵�...\n");         		//��ʾ��Ϣ 
		getchar();
	} 
	return;
}