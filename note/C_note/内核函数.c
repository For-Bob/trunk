{内核函数
	{函数名: atexit
		头文件:#include<stdlib.h>
		功 能: 注册终止函数(即main执行结束后调用的函数)
		用 法: void atexit(void (*func)(void));
		注意：exit调用这些注册函数的顺序与它们 登记时候的顺序相反。同一个函数如若登记多次，则也会被调用多次。
		
		用法：一般用于回收线程，进程，资源等。
		#include <stdio.h>
		#include <stdlib.h>
		void exit_fn1(void)
		{
		printf("Exit function #1 called\n");
		}
		void exit_fn2(void)
		{
		printf("Exit function #2 called\n");
		}
		int main(void)
		{
		/* post exit function #1 */
		atexit(exit_fn1);
		/* post exit function #2 */
		atexit(exit_fn2);
		printf("after main\n");
		return 0;
		}
		输出：
		after main
		Exit function #2 called
		Exit function #1 called
	}
	
	{int ioctl(int fd, int cmd, …)；
		#include <sys/ioctl.h>
		ioctl是设备驱动程序中对设备的I/O通道进行管理的函数。所谓对I/O通道进行管理，就是对设备的一些特性进行控制，例如串口的传输波特率、马达的转速等等。
		VT_GETMODE　获取活动虚终端当前所在的状态
		VT_SETMODE　设置虚终端模式(自动或进程控制)。
	}
	
	{signal()函数
		#include <signal.h>
		typedef void (*sighandler_t)(int);
		sighandler_t signal(int signum,signadler_t handler);
		
		#include <stdio.h>
		#include <signal.h>
		
		typedef void (* signal_handler)(int);
		
		void signal_handler_fun(int signal_num)
		{
			printf("catch signal %d\n",signal_num);
		}
		
		int main(int argc,char *argv[])
		{
			signal_handler p_signal = signal_handler_fun;
			signal(SIGINT,p_signal);
			while(1);
			return 0;
		}
		输出：
			此程序是对当我们按下CTRL +C键时，会执行我们定义的信号处理函数。
			
		{信号
			信号 值 处理动作 发出信号的原因 
			---------------------------------------------------------------------- 
			SIGHUP 1 A 终端挂起或者控制进程终止 
			SIGINT 2 A 键盘中断（如break键被按下） 
			SIGQUIT 3 C 键盘的退出键被按下 
			SIGILL 4 C 非法指令 
			SIGABRT 6 C 由abort(3)发出的退出指令 
			SIGFPE 8 C 浮点异常 
			SIGKILL 9 AEF Kill信号 
			SIGSEGV 11 C 无效的内存引用 
			SIGPIPE 13 A 管道破裂: 写一个没有读端口的管道 
			SIGALRM 14 A 由alarm(2)发出的信号 
			SIGTERM 15 A 终止信号 
			SIGUSR1 30,10,16 A 用户自定义信号1 
			SIGUSR2 31,12,17 A 用户自定义信号2 
			SIGCHLD 20,17,18 B 子进程结束信号 
			SIGCONT 19,18,25 进程继续（曾被停止的进程） 
			SIGSTOP 17,19,23 DEF 终止进程 
			SIGTSTP 18,20,24 D 控制终端（tty）上按下停止键 
			SIGTTIN 21,21,26 D 后台进程企图从控制终端读 
			SIGTTOU 22,22,27 D 后台进程企图从控制终端写 
		}
	}
	
	{isatty()
		#include <unistd.h>
		int isatty(int desc)
		如果是一个连接到打开终端的描述符就返回1，否则返回0
	}
	
	{int fileno(FILE *stream);
		#include<stdlib.h>
		返回文件流的整形描述符
	}
	
	{ttyname()
		#include <unistd.h>

		char *ttyname(int desc);
		返回指向终端设备的打开的文件描述符路径的指针，如果错误返回NULL
	}
	
	{int tcgetattr(int fd, struct termios *termios_p);
		tcgetattr用于获取终端的相关参数
		说明：tcgetattr函数用于获取与终端相关的参数。参数fd为终端的文件描述符，返回的结果保存在termios结构体中，该结构体一般包括如下的成员：
		tcflag_t c_iflag;      
		tcflag_t c_oflag;      
		tcflag_t c_cflag;      
		tcflag_t c_lflag;     
		cc_t     c_cc[NCCS];
	}
	
}