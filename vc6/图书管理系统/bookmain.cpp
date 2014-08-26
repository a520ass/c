#include"book.cpp"
//主函数开始
void main() 
{	
	BOOKS book[M];                          		//定义结构体数组 
	int length;                                  		//保存记录长度
	for(;;)                                      		//无限循环
	{
		system("cls");                           		//清屏
		switch(menu_select())            //调用主菜单函数，返回值作为开关语句的条件
		{
		case 1:length=enter(book);break;         		//输入记录
		case 2:modify(book,length);break;        		//修改
		case 3:length=del(book,length);break;     		//按书名删除记录
		case 4:search(book,length);break;        		//按书名查询
		case 5:statistics(book,length);break;        		//按时间段统计
		case 6:save(book,length);break;         	 	//保存文件
		case 7:length=load(book);break;         		//加载文件到内存
		case 0:exit(0);                     		//程序结束
		}
		printf("按回车键返回主菜单...\n");         		//提示信息 
		getchar();
	} 
	return;
}