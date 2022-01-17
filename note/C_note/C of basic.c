{C基础复习

	C到目标文件的编译过程
	{
		1.预处理				源代码*.c
		2.编译					|	预处理
		3.汇编					预处理*.i
		4.链接					|	编译
								汇编文件(*.s)
								| 	汇编
								目标代码(*.o)
								|链接
								可执行文件
	} 

	内核的分配情况
	{
		1G内核空间
		3G用户空间
		{
			命令行参数->(环境变量)
			栈->(局部变量，形参，->系统分配，系统销毁)
			堆->程序员手动开辟，程序员手动释放
			静态区(data		生命周期
					bss		从定义开始到程序结束
					)		放全局变量和static修饰的变量
			只读区->字符串常量
			text->指令
		}
	}

	
	{printf格式
		%a             浮点数、十六进制数字和p-记数法（Ｃ９９）
		%A　　　　浮点数、十六进制数字和p-记法（Ｃ９９）
		%c　　　　 一个字符(char)
		%C           一个ISO宽字符
		%d　　　　有符号十进制整数(int)（%ld、%Ld：长整型数据(long),%hd：输出短整形。）　
		%e　　　　浮点数、e-记数法
		%E　　　　浮点数、Ｅ-记数法
		%f　　　　 单精度浮点数(默认float)、十进制记数法（%.nf  这里n表示精确到小数位后n位.十进制计数）
		%g　　　　根据数值不同自动选择％f或％e．
		%G　　　　根据数值不同自动选择％f或％e.
		%i              有符号十进制数（与％d相同）
		%o　　　　无符号八进制整数
		%p　　　   指针
		%s　　　　 对应字符串char*（%s == %hs == %hS 输出 窄字符）
		%S             对应宽字符串WCAHR*（%ws == %S 输出宽字符串）
		%u　　　   无符号十进制整数(unsigned int)
		%x　　　　使用十六进制数字０f的无符号十六进制整数　
		%X　　　   使用十六进制数字０f的无符号十六进制整数
		%%　　　  打印一个百分号
	}
	数组指针是指针(指向数组的指针)->(*p)[5]
	指针数组是数组(装指针的数组)->*p[5]
	
	1/2,1/4,1/6,1/8……的和
	
	等比数列求和公式：Sn=a1(1-q^n)/(1-q)
	a1 = 第一项， q = 等比系数
	
	{数组初始化
		不管是几维数组，两种初始化方式为0
		1. int dataArray[x][x] = {0}; 
		2. memset(dataArray,0,sizeof(dataArray));
	}
	
	{存储的关系，字节，字的各种转换关系
		一个字节是8位，bit:字位
		1bit表示1位，
		1Byte表示一个字节
		1B=8b。
		1024B=1KB
		1024KB=1M
		1024M=1G.
	}
	
	{pthread
		pthread_create()：创建一个线程
		
		pthread_exit()：终止当前线程
		
		pthread_cancel()：中断另外一个线程的运行
		
		pthread_join()：阻塞当前的线程，直到另外一个线程运行结束
		
		pthread_kill()：向线程发送一个信号
		
		pthread_self():	获取当前调用线程的 thread identifier(标识号).
		
		pthread_detach()：分离线程
			创建一个线程默认的状态是joinable, 如果一个线程结束运行但没有被join,则它的状态类似于进程中的Zombie Process,即还有一部分资源没有被回收（退出状态码），
			所以创建线程者应该pthread_join来等待线程运行结束，并可得到线程的退出代码，回收其资源（类似于wait,waitpid)
			但是调用pthread_join(pthread_id)后，如果该线程没有运行结束，调用者会被阻塞，在有些情况下我们并不希望如此，比如在Web服务器中当主线程为每个新来的链接创建一个子线程进行处理的时候，
			主线程并不希望因为调用pthread_join而阻塞（因为还要继续处理之后到来的链接），这时可以在子线程中加入代码
			pthread_detach(pthread_self())
			或者父线程调用
			pthread_detach(thread_id)（非阻塞，可立即返回）
				这将该子线程的状态设置为detached,则该线程运行结束后会自动释放所有资源。
	}
	
	malloc,kmalloc,vmalloc
		malloc分配的是用户空间
		vmalloc和kmalloc是分配的是内核空间
		kmalloc分配的大小有限，vmalloc和kmalloc分配较大的空间
		
	函数指针 char *loop(void)
	指针函数
	{
		举例说明
		#include <stdio.h>
		int Plus(int a, int b);
		int Minus(int ,int );
		
		int main()
		{
			int x = 5,y = 8;
			int (*pFun)(int a,int b);	//声明一个名为pFun函数指针
			pFun = Plus;
			printf("%d\n",(*pFun)(x,y));	//值13
			pFun = Minus;
			printf("%d\n",(*pFun)(x,y));	//-3
		}
		
		int Plus(int a, int b)
		{
			return (a+b);
		}
		
		int Minus(int ,int )
		{
			return (a-b);
		}
		
	}
	
	字符串常规操作
	{
		char orderbuf[1024];
		char buff[1024] = "song";
		int i;
		strncmp(orderbuf,"GetTemp",7)	//比较字符串中的内容
		i = strlen(buff);				//buff中内容的长度(i = 4)
		strcat(buff,orderbuf)			//将orderbuf加到buff后面
		strcpy(buff,orderbuf)			//将orderbuf的内容复制到buff中，必须保证buff中的内存要大于orderbuf中的内存
		sprintf(buff,"%d",i);			//将整数转换为字符串
		atoi()							//将字符转为整数
		
		strcpy只能复制字符串，而memcpy可以复制任意内容，例如字符数组、整型、结构体、类等。
		strcpy不需要指定长度，它遇到被复制字符的串结束符"\0"才结束，所以容易溢出。memcpy则是根据其第3个参数决定复制的长度。
	}
	
		strcpy只能拷贝字符串，memcpy什么数据都能拷贝
	strcpy()	//一定要注意strdest的内存大小一定不能比strsrc小
	{
			char *mystrcpy(char *strdest, const char *strsrc) 
			{ 
				if(strsrc == NULL)
				{
					printf("error\n");
				}
				 char *tmp = strdest; 
				 while( (*strdest != NULL) && (*strsrc != NULL)) 
				{ 
				  *strdest++ = *strsrc++; 
				} 
				*strdest = '\0';
				printf(" *tmp :%s\n", tmp);
				return tmp; 
			} 
		char* mystrcpy(char *strdest, const char *strsrc) 
		{ 
			int i;
			if(strsrc == NULL)
			{
				printf("error\n");
			}
			 char *tmp = strdest; 
			for(i = 0;strsrc[i] != '\0';i++)
			{
				strdest[i] = strsrc[i];
			} 
			strdest[i] = '\0';
			return tmp;
		} 
	}
	
	strcat()
	{
		char *strcat (char * dst, const char * src)
			{
				if(NULL == dst || NULL == src)
				{
					return NULL;	
				}

				char * cp = dst;
				while( *cp )
					cp++; /* find end of dst */
				while( *cp++ = *src++ ) ; /* Copy src to end of dst */
				return dst; /* return dst */
			}	
			
		char* strcat(char *dest, const char *src)
           {
			if(NULL == dst || NULL == src)
			{
				return NULL;	
			}
			  size_t dest_len = strlen(dest);
               size_t i;

               for (i = 0 ; src[i] != '\0' ; i++)
                   dest[dest_len + i] = src[i];
               dest[dest_len + i] = '\0';

               return dest;
           }
		   
		   

	}
	
	字符串右移n位
	{
		void LoopMove ( char *pStr, int steps ) 
		{ 
			int n = strlen( pStr ) - steps; 
			char tmp[MAX_LEN]; 
			strcpy ( tmp, pStr + n ); 			//拷贝循环要移动的那几位			
			strcpy ( tmp + steps, pStr); 		//将pStr的内容接在tmp已经拷贝的后面
			*( tmp + strlen ( pStr ) ) = '\0'; 	//将tmp的内容进行截取
			strcpy( pStr, tmp ); 				
		}
	}
	
	1+2+...+n
	{
		(1+n)*n/2;
	}
	
	大端存储返回为0，小端存储返回为1
	{
		int cheek(void)
		{
			union CPU
			{
				int a;
				char b;
			}X;
			x.a = 1;
			return (x.b == 1);
		}
	}
	
	#define和typedef的区别
	{
		#define nn int*
		nn a,b,c;(int *a,b,c)
		
		typedef int* nn
		nn a,b,c;(int *a;int *b;int *c)
	}
	
	打印文件名，函数名，以及行数
	{
		printf("%s\t%s\t%d\n",__FILE__,__FUNCTION__,__LINE__);
	}
	
	全局变量和局部变量可以重名，局部变量会屏蔽全局变量的值
	
	/***********************/
	//bulit-in 没有包含头文件
	
	const的用法
	{
		const离哪个近，离谁近就修饰谁。把int去掉来看
		const int *p;	//const 修饰*p，p是指针，*p是指针指向的对象，不可变
		int const *p;	//修饰*p,p是指针,*p是指针指向的对象，不可变
		int *const p;	//修饰p，p不可变，p指向的对象可变
		const int *const p;//迁一个constant修饰*p，后一个const修饰p，指针p和p指向的都不变
	}
	
	static
	{
		修饰的变量()，生命周期会到程序结束
		作用域：
		修饰的全局变量，隐藏这个全局变量，修饰的函数名，其他.C文件不能调用，
	}
	
	volatile 防止优化
	
	union 联合体
	{
		同一时间只能存储其中一个数据，只分配一个其中最大的长度。
	}
	
	C指针
	{
		//******给一个0x65465的地址上赋值为0x00*******//
		int *p;
		p = (int *)0x65465;
		*p = 0x00;
		
		//*********给指针分配一个4个char的数据空间大小**********//
		char *p = (char *)malloc(4);
		
		if(p == NULL)	//判断地址是否分配成功
		{
			printf("error\n");
		}
		
		free(p);
		p = NULL;	//释放地址
	}
	
	设置板子和虚拟机通信
	{
		设置虚拟机，能与外网ping通
		服务器IP
		板子IP

		挂载nfs
		setenv bootargs root=nfs nfsroot=192.168.1.7（虚 拟机）:/nfs/rootfs console=ttySAC0,115200 init=/linuxrc ip=192.168.1.232（板子地址）

		setenv bootargs root=nfs nfsroot=192.168.1.79:/nfs/rootfs console=ttySAC0,115200 init=/linuxrc ip=192.168.1.52


		setenv serverip 192.168.1.79		虚拟机//IP
		setenv ipaddr 192.168.1.52		板子//
		setenv gatewayip  192.168.1.232	电脑

		sudo service   tftpd-hpa   restart  //启动tft服务器
	}
	
	2、判断当前操作系统是大端存储还是小端存储
	{
		#include <stdio.h>

		int main (int argc, char *argv[])
		{
			short var = 0xf9f8;
			unsigned char *p = (unsigned char *)&var;
			
			printf("%x\n",*p);
			
			return 0;
		}
	}
	
	几种排序法
	{
		void insert_sort(int *a, int len)//直接插入排序
		{
			int tmp;
			int i,j;

		/*    for(i = 1; i < len; i++)
			{
				tmp = a[i];
				for(j = i-1; j >= 0 && a[j] >= tmp; j--)
				{
					a[j+1] = a[j];
				}
				a[j+1] = tmp;
			}*/

			/*利用监视哨*/
			for(i = 2; i < len; i++)
			{
				a[0] = a[i];
				for(j = i-1; a[j] > a[0]; j--)
				{
					a[j+1] = a[j];
				}
				a[j+1] = a[0];
			}

		}
		
		/*
		比较相邻的元素。如果第一个比第二个大，就交换他们两个。
		对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对。在这一点，最后的元素应该会是最大的数。
		*/
		void bubble_sort(int *a, int len)//冒泡法排序
		{
			int i, j;
			int tmp;

			for(i = 0; i < len-1; i++)
			{
				for(j = 0; j < len-i-1; j++)
				{
					if(a[j+1] > a[j])
					{
						tmp = a[j+1];
						a[j+1] = a[j];
						a[j] = tmp;
					}
				}
			}
		}

		void quick_sort(int *a, int start, int end)//快速排序
		{
			int tmp;
			int i, j;

			i = start;
			j = end;
			tmp = a[i];

			while(i < j)
			{
				while((i < j) && (a[j] >= tmp))
				{
					j--;
				}
				if(i < j)
					a[i] = a[j];
				while((i < j) && (a[i] < tmp))
				{
					i++;
				}
				if(i < j)
					a[j] = a[i];
			}
			a[i] = tmp;

			if(start < i-1)
			{
				quick_sort(a, start, i-1);
			}
			if(i+1 < end)
			{
				quick_sort(a, i+1, end);
			}
			
}
	
		int main()
		{
			int a[] = {2,1,3,5,7,9,-1,4,6,8,0};
			/*insert_sort(a, sizeof(a)/sizeof(a[0]));*/
			/*bubble_sort(a, sizeof(a)/sizeof(a[0]));*/
			quick_sort(a, 0, sizeof(a)/sizeof(a[0])-1);
			
			int i;
			for(i = 0; i < sizeof(a)/sizeof(a[0]); i++)
			{
				printf("%d,",a[i]);
			}
			printf("\n");

			return 0;
		}
	}
	
	switch
	{
		除了整型和字符外 其他的都不行
	}
	
	左值
	{
		位于等号(=)左边的值是不能运算的
	}
	
	{结构体
		//声明
		struct stu
		{
			int num;
			char name[20];
			int age;
		};

		struct stu boy1,boy2; //定义
		
		typedef struct stu
		{
			int num;
			char name[20];
			int age;
		}stu1;
		stu1 mystruct;<==> struct stu mystruct	//定义
		
		//声明加定义
		struct stu
		{
			int num;
			char name[20];
			int age;
		}boy1,boy2;  
		
		//声明加定义和赋值
		struct student
		{
			long int num;
			int      age;
			char*    name;
		}st1={200,18,"zhangsan"}; 
	}
}




 