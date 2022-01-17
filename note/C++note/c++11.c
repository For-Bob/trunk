参考： https://blog.csdn.net/byxdaz/article/details/88603387

预处理，编译，汇编，链接
常量表达式发生在编译阶段；变量是发生在程序运行阶段

线程池
线程池管理器：用于创建并管理线程池，包括 创建线程池，销毁线程池，添加新任务；
工作线程：线程池中线程，在没有任务时处于等待状态，可以循环的执行任务；
任务接口：每个任务必须实现的接口，以供工作线程调度任务的执行，它主要规定了任务的入口，任务执行完后的收尾工作，任务的执行状态等；
任务队列：用于存放没有处理的任务。提供一种缓冲机制。

常用算法;
插入排序
希尔排序
选择排序
堆排序
冒泡排序
快速排序
归并排序

计数排序
桶排序
基数排序

函数模板和模板函数的区别:
函数模板提供了一类函数的抽象，它提供了任意类型为参数及返回值。函数模板经实例化后生成的具体函数成为模板函数。函数模板代表了一类函数，模板函数表示某以具体函数。

{auto自动类型，但是有一点不能当返回值
	如果要auto当返回值应该怎么办？
	后置返回类型
	template<typename T, typename U>
	auto add(T x, U y) -> decltype(x+y) {
		return x+y;
	}；
}

{vector说明
	size()//容器真实占用的大小
	capacity()//返回预分配的大小空间
	reserve(n)//修改了capacity的值，
	for (std::vector<int>::reverse_iterator it=a.rbegin(); it!=a.rend(); ++it)//从后面向前面
	for (std::vector<int>::iterator it=a.rbegin(); it!=a.rend(); ++it)//从前面向后面
}
	
{其他容器说明
	deque：一个双向队列，多个连续的内存块，deque起始和结尾都能够快速的插入和删除元素。vector只能在尾端进行。
	queue：队列，queue与stack模版非常类似，
	priority_queue：优先队列与队列的差别在于优先队列不是按照入队的顺序出队，而是按照队列中元素的优先权顺序出队
	stack:先进后出
	multimap:可以有相同的key，map不能有相同的key
	multiset:可以有同样的元素，set不能有相同的key
}

初始化列表:
	初始化列表的的顺序，是被声明的顺序，而不是在初始化列表中的顺序。
std::using 取代typedef
	typedef double db; //c99
	using db = double; //c++11

{std::array
跟数组的区别就是增加了迭代器（iterator）: std::array<int, 4> arrayDemo = { 1,2,3,4 };
valarray 支持很多数值数组操作，如求数组总和、最大数、最小数等。 
	cshift:向左移动元素（循环）
		int init[]={10,20,30,40,50};
		std::valarray<int> myvalarray (init,5);
		myvalarray = myvalarray.cshift(2);   // 30 40 50 10 20
		myvalarray = myvalarray.cshift(-1);  // 20 30 40 50 10
	shift:向左移动元素(不循环)
		myvalarray = myvalarray.shift(2);        // 30 40 50  0  0
	max:返回里面的最大值
		std::cout << "The max is " << myvalarray.max() << '\n';	//50
	min:返回最小值
	sum:返回和
	size：大小
	resize:重新分配大小
		std::valarray<int> myarray (10,5);   // 10 10 10 10 10
		myarray.resize(3);                   // 0  0  0
	swap:交换
		std::valarray<int> foo {10,20,30,40};
		std::valarray<int> bar {100,200,300};
		foo.swap(bar);
	slice(j,k,l);
		j:表示第一个被选中的元素的下标也就是索引 
		k:表示一共要几个元素（这个要考虑到数组大小而定）
		l:表示元素之间的间隔多少 
	例如：
	有一组数据是：1,2,3,4,5,6,7,8,9,10
	slice(0,4,3);   这表示什么意思呢？第0个索引开始，也就是从数值1开始要抓取4个元素，并且每个元素距离为3，所以这四个数值分别是：1,4,7,10
	std::valarray<int>val = { 1,2,3,4,5,6,7,8,9,10 };
	std::valarray<int>bal(val[slice(0, 4, 3)]);
	for (int i = 0; i<bal.size(); i++)
	{
		cout << bal[i] << " ";//1,4,7,10
	}
}
	
std::forward_list
	std::forward_list为从++新增的线性表，与list区别在于它是单向链表

{std::unordered_map与std::map
	map：
	优点：
		有序性，这是map结构最大的优点，其元素的有序性在很多应用中都会简化很多的操作
		红黑树，内部实现一个红黑书使得map的很多操作在logn的时间复杂度下就可以实现，因此效率非常的高
	缺点： 空间占用率高，因为map内部实现了红黑树，虽然提高了运行效率，但是因为每一个节点都需要额外保存父节点、孩子节点和红/黑性质，使得每一个节点都占用大量的空间
		适用处：对于那些有顺序要求的问题，用map会更高效一些
	unordered_map：
		优点： 因为内部实现了哈希表，因此其查找速度非常的快,时间复杂度o(1)
		缺点： 哈希表的建立比较耗费时间
		适用处：对于查找问题，unordered_map会更加高效一些，因此遇到查找问题，常会考虑一下用unordered_map
	总结：
		内存占有率的问题就转化成红黑树 VS hash表 , 还是unorder_map占用的内存要高。
		map/multimap 底层基于红黑树，元素自动有序，且插入、删除效率高
		unordered_map/unordered_multimap 底层基于哈希表，故元素无序，查找效率高。
}

{std::unordered_set
std::unordered_set的数据存储结构也是哈希表的方式结构，除此之外，std::unordered_set在插入时不会自动排序，这都是std::set表现不同的地方。
std::unordered_set<int> unorder_set;
int a[5] {1,1,2,3,4};
std::set<int> myset{a, a + 5};
for (std::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
	std::cout << ' ' << *it;//1,2,3,4
}

{tuple多元数组:多种数据类型
	auto t1 = make_tuple(1, "a1", "b1", "c1");
    cout << get<0>(t1) << " ";
    cout << get<1>(t1) << " ";
}

{std::get 返回tuple的第n个引用值
	#include <iostream>
	#include <tuple>

	int main ()
	{
	  std::tuple<int,char> mytuple (10,'a');

	  std::get<0>(mytuple) = 20;

	  std::cout << "mytuple contains: ";
	  std::cout << std::get<0>(mytuple) << " and " << std::get<1>(mytuple);//mytuple contains: 20 and a
	  std::cout << std::endl;

	  return 0;
	}
}

default关键字生成默认构造函数和析构函数；
delete关键字禁止拷贝构造、禁止赋值构造、禁止自定义参数的构造函数，注意析构函数不可由delete修饰

{function是一个template
参考：https://blog.csdn.net/xf_zhen/article/details/52224139
	调用元素类型：函数、函数指针、类成员函数指针或任意类型的函数对象
	#include <functional>
	1.普通函数
		void printA(int a)
		{
			 cout << a << endl;          
		}

		std::function<void(int a)> func;
		func = printA;
		func(2);   //2

	2.成员函数
		class Foo{
			Foo(int num) : num_(num){}
			void print_add(int i) const {cout << num_ + i << endl;}
			int num_;  
		};

		//保存成员函数
		std::function<void(const Foo&,int)> f_add_display = &Foo::print_add;
		Foo foo(2);
		f_add_display(foo,1);
}

{bind	可将bind函数看作是一个通用的函数适配器，它接受一个可调用对象
	调用bind的一般形式：auto newCallable = bind(callable,arg_list);
	其中，newCallable本身是一个可调用对象，arg_list是一个逗号分隔的参数列表，对应给定的callable的参数。即，当我们调用newCallable时，newCallable会调用callable,并传给它arg_list中的参数。
	#include <iostream>
	#include <functional>
	using namespace std;
	class A
	{
	public:
		void fun_3(int k,int m)
		{
		    cout<<"print: k="<<k<<",m="<<m<<endl;
		}
	};

	void fun_1(int x,int y,int z)
	{
		cout<<"print: x=" <<x<<",y="<< y << ",z=" <<z<<endl;
	}

	void fun_2(int &a,int &b)
	{
		a++;
		b++;
		cout<<"print: a=" <<a<<",b="<<b<<endl;
	}

	int main(int argc, char * argv[])
	{
		//f1的类型为 function<void(int, int, int)>
		auto f1 = std::bind(fun_1,1,2,3); //表示绑定函数 fun 的第一，二，三个参数值为： 1 2 3
		f1(); //print: x=1,y=2,z=3

		auto f2 = std::bind(fun_1, placeholders::_1,placeholders::_2,3);
		//表示绑定函数 fun 的第三个参数为 3，而fun 的第一，二个参数分别由调用 f2 的第一，二个参数指定
		f2(1,2);//print: x=1,y=2,z=3
	 
		auto f3 = std::bind(fun_1,placeholders::_2,placeholders::_1,3);
		//表示绑定函数 fun 的第三个参数为 3，而fun 的第一，二个参数分别由调用 f3 的第二，一个参数指定
		//注意： f2  和  f3 的区别。
		f3(1,2);//print: x=2,y=1,z=3

		int m = 2;
		int n = 3;
		auto f4 = std::bind(fun_2, placeholders::_1, n); //表示绑定fun_2的第一个参数为n, fun_2的第二个参数由调用f4的第一个参数（_1）指定。
		f4(m); //print: m=3,n=4
		cout<<"m="<<m<<endl;//m=3  说明：bind对于不事先绑定的参数，通过std::placeholders传递的参数是通过引用传递的,如m
		cout<<"n="<<n<<endl;//n=3  说明：bind对于预先绑定的函数参数是通过值传递的，如n
		
		A a;
		//f5的类型为 function<void(int, int)>
		auto f5 = std::bind(&A::fun_3, a,placeholders::_1,placeholders::_2); //使用auto关键字
		f5(10,20);//调用a.fun_3(10,20),print: k=10,m=20

		std::function<void(int,int)> fc = std::bind(&A::fun_3, a,std::placeholders::_1,std::placeholders::_2);
		fc(10,20);   //调用a.fun_3(10,20) print: k=10,m=20 
		return 0; 
	}
}

{std::chrono时间相关 #include <chrono> 
	比以前的时间方便了许多：
	std::chrono::duration<double> duration //时间间隔
	std::this_thread::sleep_for(std::chrono::seconds(duration)); //sleep
	LOG(INFO) << "duration is " << duration.count() << std::endl;
	std::chrono::microseconds  //微秒
	std::chrono::seconds //秒
	end = std::chrono::system_clock::now(); //获取当前时间
}

{std::thread
	成员函数
		get_Id()//获取线程id
		joinable();//是否join
		join();// join 线程
		detach();//detach线程
		swap();//swap线程
		native_handle();//获取线程句柄
		线程的值传递的引用，线程会自动加一层值拷贝
	#include <thread>
	void threadfun1()
	{
	    std::cout << "threadfun1 - 1\r\n" << std::endl;
	    std::this_thread::sleep_for(std::chrono::seconds(1));
	    std::cout << "threadfun1 - 2" << std::endl;
	}

	void threadfun2(int iParam, std::string sParam)
	{
	    std::cout << "threadfun2 - 1" << std::endl;
	    std::this_thread::sleep_for(std::chrono::seconds(5));
	    std::cout << "threadfun2 - 2" << std::endl;
	}

	class A{
		void runThread(int param)
		{
			td::cout << "class thread param:"<< param << std::endl;
		}
	}

	int main()
	{
		A aclass;
	    std::thread t1(threadfun1);
	    std::thread t2(threadfun2, 10, "abc");
		std::thread t3(&A::runThread,&aclass, 10);
	    t1.join();
	    std::cout << "join" << std::endl;
	    t2.detach();
	    std::cout << "detach" << std::endl;
	}
}

{atomic:原子变量
	原子数据类型不会发生数据竞争，能直接用在多线程中而不必我们用户对其进行添加互斥资源锁的类型。
	atomic_flag 初始化状态为ATOMIC_FLAG_INIT，方法有test_and_set()和clear()。
	std::atomic_flag是一个原子的布尔类型，可支持两种原子操作：
    	test_and_set, 如果atomic_flag对象被设置，则返回true; 如果atomic_flag对象未被设置，则设置之，返回false
    	clear. 清除atomic_flag对象

　　std::atomic_flag可用于多线程之间的同步操作，类似于linux中的信号量。使用atomic_flag可实现mutex.
		#include <iostream>
		#include <atomic>
		#include <vector>
		#include <functional>
		#include <thread>

		std::atomic<int> i(0);//初始化为0
		std::atomic_flag winner = ATOMIC_FLAG_INIT;
		const int count = 100000;
		const int n = 10;

		void add()
		{
			for (int j = 0; j < count; ++j)
				i++;
		}

		int main()
		{
			i.store(0);
			std::vector<std::thread> workers;
			std::cout << "start " << n << " workers, "
				      << "every woker inc " << count  << " times" << std::endl;

			for (int j = 0; j < n; ++j)
				workers.push_back(std::move(std::thread(add)));

			for (auto & w : workers)
				w.join();

			std::cout << "workers end "
				      << "finally i is " << i << std::endl;

			if (i == n * count)
				std::cout << "i++ test passed!" << std::endl;
			else
				std::cout << "i++ test failed!" << std::endl;

			return 0;
		}
}

{智能指针：
	#include <memory>
	shared_ptr，基于引用计数的智能指针，会统计当前有多少个对象同时拥有该内部指针；
	 std::shared_ptr<int> mPointer = std::make_shared<int>();

	{weak_ptr是由shared_ptr管理的一种弱引用对象的模版类。weak_ptr的对象能够使用shared_ptr指针的构造函数转换为一个shared_ptr对象。但是这里shared_ptr的构造函数参数需要包含weak_ptr的lock成员，该成员是weak_ptr用来获取shared_ptr的指针。
		weak_ptr用法：
			shared_ptr<int> p(new int(5));
			weak_ptr<int> q(p);
			//使用weak_ptr的lock成员来获取shared_ptr的指针
			if(shared_ptr<int> r = q.lock())
			{
				// use *r
			}
			关于lock()成员简单说明一下，lock成员获取到的shared_ptr p指针创建一个“临时对象”（我们weak_ptr弱引用的体现），这个临时对象同样指向p，即使p执了reset这样的delete引用的操作，弱引用对象仍然持有改智能指针的地址，直到r指针的生命周期结束才会释放。
		weak_ptr::swap成员，交换两个weak_ptr所指内容以及地址
		weak_ptr::reset成员，·重新指定对象地址和内容，就像是重新使用默认构造函数进行了初始化
		weak_ptr::use_count成员，获取shared_ptr对象被引用的次数。如果为空，则返回0
		weak_ptr::expired成员，当根据use_count==0来返回bool，其返回为true的时候，使用lock获取weak_ptr的指针只能获取到空指针
		weak_ptr::lock成员，会向weak_ptr对象返回一个shared_ptr。
	}
	unique_ptr: 遵循独占语义的智能指针，资源所有权的转移只能通过std::move()而不能通过赋值
}

{互斥锁：mutex 线程往往是并行执行，互斥锁用于线程执行的同步性，比如线程1执行完成，线程2在执行
	成员变量：
		lock()
		try_lock()
		unlock
	#include <iostream>       // std::cout
	#include <thread>         // std::thread
	#include <mutex>          // std::mutex, std::unique_lock
	using namespace std;
	std::mutex mtx;           // mutex for critical section

	void print_block (int n, char c) {
	  // critical section (exclusive access to std::cout signaled by lifetime of lck):
	  mtx.lock();
	  for (int i=0; i<n; ++i) 
	  {
		  if(i%50 == 0 && i != 0)
		    std::cout << endl;
		  std::cout << c; 
	  }
	  std::cout << '\n';
	  mtx.unlock();
	}

	int main ()
	{
	  std::thread th1 (print_block,500,'*');
	  std::thread th2 (print_block,500,'$');

	  th1.join();
	  th2.join();

	  return 0;
	}
}

{std::recursive_mutex 介绍

std::recursive_mutex 与 std::mutex 一样，也是一种可以被上锁的对象，但是和 std::mutex 不同的是，std::recursive_mutex 允许同一个线程对互斥量多次上锁（即递归上锁），来获得对互斥量对象的多层所有权，std::recursive_mutex 释放互斥量时需要调用与该锁层次深度相同次数的 unlock()，可理解为 lock() 次数和 unlock() 次数相同，除此之外，std::recursive_mutex 的特性和 std::mutex 大致相同。

std::unique_lock与std::lock_guard	：是为了防止mutex死锁的情况出现的。
	lock_guard是一个互斥量包装程序，创建lock_guard对象时，它将尝试获取提供给它的互斥锁的所有权。当控制流离开lock_guard对象的作用域时，lock_guard析构并释放互斥量。
	它的特点如下：
	    创建即加锁，作用域结束自动析构并解锁，无需手工解锁
    	不能中途解锁，必须等作用域结束才解锁
    	不能复制
			#include <iostream>       // std::cout
			#include <thread>         // std::thread
			#include <mutex>          // std::mutex
			#include <chrono> 
			std::mutex mtx;           // mutex for critical section
			int g_i = 0;
			using namespace std;
			void addItSelf_guard (int count) {
				lock_guard<mutex> lock(mtx);	//lock_guard创建的时候就加锁了，函数执行完，这个变量消失的时候，自动解锁
				for(int i = 0; i < count; i++)
					g_i++;
				cout << " g_i: " << g_i << endl;
			}

			int main ()
			{
				std::thread th1 (addItSelf_guard,100000);
				std::thread th2 (addItSelf_guard,200000);

				th1.detach();
				th2.detach();
				while(1)
				{
					std::this_thread::sleep_for(std::chrono::seconds(10));
				}
				return 0;
			}

	unique_lock是一个通用的互斥量锁定包装器，它允许延迟锁定，限时深度锁定，递归锁定，锁定所有权的转移以及与条件变量一起使用。unique_lock 是 lock_guard 的升级加强版。
	unique_lock() noexcept;
	explicit unique_lock (mutex_type& m);	//构造就加锁 
	unique_lock (mutex_type& m, try_to_lock_t tag);//构造的时候，调用try_lock试图加锁
	unique_lock (mutex_type& m, defer_lock_t tag) noexcept;//构造的时候不加锁
	unique_lock (mutex_type& m, adopt_lock_t tag);//采用当前锁(假定它已经被线程上锁了)

	它的特点如下：
		创建时可以不锁定（通过指定第二个参数为std::defer_lock），而在需要时再锁定
		可以随时加锁解锁
		作用域规则同 lock_grard，析构时自动释放锁
		不可复制，可移动
		条件变量需要该类型的锁作为参数（此时必须使用unique_lock）
		跟recursive_lock一起使用，防止递归造成的死锁，unique_lock<std::recursive_mutex>
}

{条件变量：condition_variable #include <condition_variable>
	条件变量用于阻塞被掉线程直到通知之后恢复。
	std::condition_variable只能和std::unique_lock<std::mutex>一起工作。
	notify_one              通知一个等待线程(public)
	notify_all              通知所有等待线程(public)
	wait                    阻塞当前线程直至条件变量被唤醒(public)
	wait_for                阻塞当前线程直至条件变量被唤醒或“超时”意思就是两者满足其一就行了
	wait_until              阻塞当前线程直至条件变量被唤醒或直到指定的时间点(public)
	native_handle           返回native handle(public)
	#include <iostream>       // std::cout
	#include <thread>         // std::thread
	#include <mutex>          // std::mutex
	#include <condition_variable>
	using namespace std;
	std::mutex mtx;           // mutex for critical section
	bool isWait = true;
	std::condition_variable cv;
	void printf_unique(int id)
	{
		cout << "wait thread id: " << id << endl;
		unique_lock<mutex> lock(mtx);
		cv.wait(lock);
		cout << "thread id: " << id << endl;
	}

	void notify_printf()
	{
		cout << "notify_printf " << endl;
		isWait = false;
		cv.notify_all();//通知的时候，wait一定要先阻塞，如果通知之后再阻塞就会一直卡住
	}

	int main ()
	 {
		thread threads[10];
		for(int i = 0; i < 10; i++)
		{
			threads[i] = thread(printf_unique, i);
		}
		notify_printf();
		for(auto& th: threads)
			th.detach();
		while(1)
		{
		    std::this_thread::sleep_for(std::chrono::seconds(10));
		}
		return 0;
	}
}

{move
	是将对象的状态或者所有权从一个对象转移到另一个对象，只是转移，没有内存的搬迁或者内存拷贝所以可以提高利用效率,改善性能。
	string str = "hello";
	cout << "address: " << &str  << " str: " << str << endl;//address: 0x7ffd249ce5d0 str: hello
	string str_mv = move(str);
	cout << "address: " << &str << " str: " <<str
		 << " str_mv address: " << &str_mv  << " str_mv: " << str_mv << endl;
	//address: 0x7ffd249ce5d0 str:  str_mv address: 0x7ffd249ce5f0 str_mv: hello

右值引用 参考：https://www.jianshu.com/p/d19fc8447eaa	
	右值引用表示：&&。右值是指表达式结束时就不在存在的临时对象。避免拷贝构造。
	两种情况时候用右值引用：1. int&& a = 2;//右边就是这种直接拿值，不能是间接拿值
						   2.与move一起使用。
	简单例子说明：
		int && a = 1; //实质上就是将不具名(匿名)变量取了个别名
		int b = 1;
		int && c = b; //编译错误！ 不能将一个左值复制给一个右值引用，说白了不能是间接拿值

	常量左值引用却是个奇葩，它可以算是一个“万能”的引用类型，它可以绑定非常量左值、常量左值、右值，
	const int & a = 1; //常量左值引用绑定 右值， 不会报错
	class A {
	  public:
		int a;
	};
	A getTemp()
	{
		return A();
	}
	const A & a = getTemp();   //不会报错 而 A& a 会报错，这里就是右值引用，因为是直接拿值
	总结一下，其中T是一个具体类型：
		左值引用， 使用 T&, 只能绑定左值
		右值引用， 使用 T&&， 只能绑定右值
		常量左值， 使用 const T&, 既可以绑定左值又可以绑定右值
		已命名的右值引用，编译器会认为是个左值

	universal references(通用引用)
		当右值引用和模板结合的时候，就复杂了。T&&并不一定表示右值引用，它可能是个左值引用又可能是个右值引用。
		template<typename T>
		void f( T&& param){
		
		}
		f(10);  //10是右值
		int x = 10; //
		f(x); //x是左值
		
		只有当发生自动类型推断时（如函数模板的类型自动推导，或auto关键字），&&才是一个universal references。
		template<typename T>
		void f( T&& param); //这里T的类型需要推导，所以&&是一个 universal references

		template<typename T>
		class Test {
		  Test(Test&& rhs); //Test是一个特定的类型，不需要类型推导，所以&&表示右值引用  
		};

		void f(Test&& param); //右值引用

		//复杂一点
		template<typename T>
		void f(std::vector<T>&& param); //在调用这个函数之前，这个vector<T>中的推断类型
		//已经确定了，所以调用f函数的时候没有类型推断了，所以是 右值引用

		template<typename T>
		void f(const T&& param); //右值引用
		// universal references仅仅发生在 T&& 下面，任何一点附加条件都会使之失效

		引用规则：			
			所有的右值引用叠加到右值引用上仍然使一个右值引用。
			所有的其他引用类型之间的叠加都将变成左值引用。
			#include <string>
			using namespace std;

			template<typename T>
			void f(T&& param){
				if (std::is_same<string, T>::value)
					std::cout << "string" << std::endl;
				else if (std::is_same<string&, T>::value)
					std::cout << "string&" << std::endl;
				else if (std::is_same<string&&, T>::value)
					std::cout << "string&&" << std::endl;
				else if (std::is_same<int, T>::value)
					std::cout << "int" << std::endl;
				else if (std::is_same<int&, T>::value)
					std::cout << "int&" << std::endl;
				else if (std::is_same<int&&, T>::value)
					std::cout << "int&&" << std::endl;
				else
					std::cout << "unkown" << std::endl;
			}

			int main()
			{
				int x = 1;
				f(1); // 参数是右值 T推导成了int, 所以是int&& param, 右值引用
				f(x); // 参数是左值 T推导成了int&, 所以是int&&& param, 折叠成 int&,左值引用
				int && a = 2;
				f(a); //虽然a是右值引用，但它还是一个左值， T推导成了int&
				string str = "hello";
				f(str); //参数是左值 T推导成了string&
				f(string("hello")); //参数是右值， T推导成了string
				f(std::move(str));//参数是右值， T推导成了string
			}
		st::ref 返回一个引用
			// ref example
			#include <iostream>     // std::cout
			#include <functional>   // std::ref

			int main () {
			  int foo (10);

			  auto bar = std::ref(foo);

			  ++bar;

			  std::cout << foo << '\n';	//11

			  return 0;
			}

		完美转发
			所谓转发，就是通过一个函数将参数继续转交给另一个函数进行处理，原参数可能是右值，可能是左值，如果还能继续保持参数的原有特征，那么它就是完美的。
			void process(int& i){
				cout << "process(int&):" << i << endl;
			}
			void process(int&& i){
				cout << "process(int&&):" << i << endl;
			}

			void myforward(int&& i){
				cout << "myforward(int&&):" << i << endl;
				process(i);
			}

			int main()
			{
				int a = 0;
				process(a); //a被视为左值 process(int&):0
				process(1); //1被视为右值 process(int&&):1
				process(move(a)); //强制将a由左值改为右值 process(int&&):0
				myforward(2);  //右值经过forward函数转交给process函数，却称为了一个左值，
				//原因是该右值有了名字  所以是 process(int&):2
				myforward(move(a));  // 同上，在转发的时候右值变成了左值  process(int&):0
				// forward(a) // 错误用法，右值引用不接受左值
			}
			
		上面的例子就是不完美转发，而c++中提供了一个std::forward()模板函数解决这个问题
			#include <iostream>
			#include <cstring>
			#include <vector>
			using namespace std;

			void RunCode(int &&m) {
				cout << "rvalue ref" << endl;
			}
			void RunCode(int &m) {
				cout << "lvalue ref" << endl;
			}
			void RunCode(const int &&m) {
				cout << "const rvalue ref" << endl;
			}
			void RunCode(const int &m) {
				cout << "const lvalue ref" << endl;
			}

			// 这里利用了universal references，如果写T&,就不支持传入右值，而写T&&，既能支持左值，又能支持右值
			template<typename T>
			void perfectForward(T && t) {
				RunCode(forward<T> (t));
			}

			template<typename T>
			void notPerfectForward(T && t) {
				RunCode(t);
			}

			int main()
			{
				int a = 0;
				int b = 0;
				const int c = 0;
				const int d = 0;

				notPerfectForward(a); // lvalue ref
				notPerfectForward(move(b)); // lvalue ref
				notPerfectForward(c); // const lvalue ref
				notPerfectForward(move(d)); // const lvalue ref

				cout << endl;
				perfectForward(a); // lvalue ref
				perfectForward(move(b)); // rvalue ref
				perfectForward(c); // const lvalue ref
				perfectForward(move(d)); // const rvalue ref
			}
}

{随机数		
	random_device  random_device提供()操作符,用来返回一个min()到max()之间的一个数字.如果是Linux(Unix Like或者Unix)下,都可以使用这个来产生高质量的随机数,可以理解为真随机数.
	rand_s Windows下面的是这个
可快速产生高质量的伪随机数
	std::random_device rd;  //获取随机数种子
    std::mt19937 mt(rd()); //产生随机数
}

{wchar_t
	宽字符,char是8位的，wchar_t是16位的，	可以用于汉字或者日文。
	wchar_t title[] = L"Chief Ass"; //w_char string
}

{char16_t和char32_t
	都是无符号的，一个是16位，一个位32位，常用u'c'和u"be good"表示字符常量和字符串常量。
	char16_t ch1 = u'q';
	char32_t ch2 = U"Hello world";
原始字符 R"nc()nc"
	cout << R"nc(hello /t world)nc" << endl; //hello /t world
UTF-8编码 u8
	cout << u8"你好世界" << endl; //你好世界
u定义的字符是char16_t类型
U定义的字符是char32_t类型
L定义的字符是wchar_t类型
其他说明
	cout<<fixed //fixed就是用一般的方式输出浮点数，而不是科学计数法; 
	cout.precision(6)//输出6位有效数字，第6位四舍五入得到
	cout.setf(ios_base::showpoint) //强制显示浮点数小数点后的0
}

{type_traits用于判断各种数据类型
	std::is_integral 是否是整型，是就返回真，否则为false，以下为基本整型类型
		bool
		char
		char16_t
		char32_t
		wchar_t
		signed char
		short int
		int
		long int
		long long int
		unsigned char
		unsigned short int
		unsigned int
		unsigned long int
		unsigned long long int
	例子：
		#include <iostream>
		#include <type_traits>
		int main() {
		  std::cout << std::boolalpha;	//按照布尔类型输出，否则下面输出0或者1
		  std::cout << "is_integral:" << std::endl;
		  std::cout << "char: " << std::is_integral<char>::value << std::endl;		//true
		  std::cout << "int: " << std::is_integral<int>::value << std::endl;		//true
		  std::cout << "float: " << std::is_integral<float>::value << std::endl;	//false
		  return 0;
		}
	
	std::is_floating_point 是否为浮点型，以下为基本浮点类型
		float
		double
		long double
		
	std::is_arithmetic //是否为算术运算符，是否为is_integral和is_floating_point
		is_integral
		is_floating_point

	std::is_signed(是否为有符号)和std::is_unsigned(是否为无符号)
		struct A { };
		enum class B : int { x,y,z };
		//有符号
		std::cout << "int: " << std::is_signed<int>::value << std::endl; //true
		std::cout << "unsigned long: " << std::is_signed<unsigned long>::value << std::endl;//false
		std::cout << "A: " << std::is_signed<A>::value << std::endl;//false
  		std::cout << "B: " << std::is_signed<B>::value << std::endl;//false
		//无符号
		std::cout << "int: " << std::is_unsigned<int>::value << std::endl;//false
		std::cout << "unsigned long: " << std::is_unsigned<unsigned long>::value << std::endl;//true
		std::cout << "A: " << std::is_unsigned<A>::value << std::endl;//false
		std::cout << "B: " << std::is_unsigned<B>::value << std::endl;//false

	std::is_pointer(是否为指针类型)
		std::cout << std::boolalpha;
		std::cout << "int: " << std::is_pointer<int>::value << std::endl;//false
		std::cout << "int*: " << std::is_pointer<int*>::value << std::endl;//true
		std::cout << "int**: " << std::is_pointer<int**>::value << std::endl;//true
		std::cout << "int(*)(int): " << std::is_pointer<int(*)(int)>::value << std::endl//true
	
	std::enable_if<bool Cond, class T>
		如果Cond为true，T才是有效的
		#include <type_traits>
		//方法一
		template<typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value>::type>
		T add(T t)
		{
			return (t + t);
		}
		
		//方法二
		template <class T>
		typename std::enable_if<std::is_arithmetic<T>::value, bool>::type
		is_num(T i) { return bool(i % 2); }
		int main()
		{
			std::cout << add( 1) << std::endl;
			std::cout << is_num(2) << std::endl;
			return 0;
		}
	
}
 */
{typeid://获取类型
		#include <typeinfo>   // operator typeid
		struct Base {};
		struct Derived : Base {};
		std::cout << std::boolalpha;
		// fundamental types:
		std::cout << "int vs my_int_type: ";
		std::cout << ( typeid(int) == typeid(my_int_type) ) << '\n; //int vs my_int_type: true
		// class types:
		std::cout << "Base vs Derived: ";
		std::cout << ( typeid(Base)==typeid(Derived) ) << '\n';//Base vs Derived: false
		// non-polymorphic object:
		Base* pbase = new Derived;
		std::cout << "Base vs *pbase: ";
		std::cout << ( typeid(Base)==typeid(*pbase) ) << '\n';//Base vs *pbase: true
		// polymorphic object:
		Poly_Base* ppolybase = new Poly_Derived;
		std::cout << "Poly_Base vs *ppolybase: ";
		std::cout << ( typeid(Poly_Base)==typeid(*ppolybase) ) << '\n';//Poly_Base vs *ppolybase: false

		int i;
		int * pi;
		std::cout << "int is: " << typeid(int).name() << '\n';//int is: int
		std::cout << "  i is: " << typeid(i).name() << '\n';//i is: int
		std::cout << " pi is: " << typeid(pi).name() << '\n';// pi is: int *
		std::cout << "*pi is: " << typeid(*pi).name() << '\n';// *pi is: int
}

{less：主要是重载了operator()方法，用来比较lhs 和 rhs
		内部实现：
			constexpr bool operator()(const T &lhs, const T &rhs) const 
			{
			 　　return lhs < rhs;
			}
			如果lhs比rhs小，就返回true；如果lhs比rhs大，就返回false;
			cout << less<int>()(10, 12) <<eendl;	//true
　　			cout << less<int>()(12, 10) << endl;	//false
		int foo[]={10,20,5,15,25};
		int bar[]={15,10,20};
		std::sort (foo, foo+5, std::less<int>());  // 5 10 15 20 25
		std::sort (bar, bar+3, std::less<int>());  //   10 15 20
}

{sort: 排序
	1. std::sort(vector.begin, vector.end);//默认从小到大排序
	2. std::sort(vector.begin, vector.end,function);
	//根据function条件来判断，function(int i, intj){ return (i < j);}	//反正就是根据返回值来判断的，这个就是从小到大排序
	// sort algorithm example
	#include <iostream>     // std::cout
	#include <algorithm>    // std::sort
	#include <vector>       // std::vector

	bool myfunction (int i,int j) { return (i<j); }

	struct myclass {
	  bool operator() (int i,int j) { return (i<j);}
	} myobject;

	int main () {
	  int myints[] = {32,71,12,45,26,80,53,33};
	  std::vector<int> myvector (myints, myints+8);               // 32 71 12 45 26 80 53 33

	  // using default comparison (operator <):
	  std::sort (myvector.begin(), myvector.begin()+4);           //(12 32 45 71)26 80 53 33
	  for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
		std::cout << ' ' << *it;
	  std::cout << '\n';

	  // using function as comp
	  std::sort (myvector.begin()+4, myvector.end(), myfunction); // 12 32 45 71(26 33 53 80)
		for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
			std::cout << ' ' << *it;
		  std::cout << '\n';
	  
	  // using object as comp
	  std::sort (myvector.begin(), myvector.end(), myobject);     //(12 26 32 33 45 53 71 80)

	  // print out content:
	  std::cout << "myvector contains:";
	  for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
		std::cout << ' ' << *it;
	  std::cout << '\n';

	  return 0;
	}
}

{includes:用于包含关系
		int container[] = {5,10,15,20,25,30,35,40,45,50};
		int continent[] = {40,30,20,10};

		std::sort (container,container+10);
		std::sort (continent,continent+4);
		std::includes(container,container+10,continent,continent+4);	//true
}

{set_union:用于元素取并集：取并集合之间要把这些数据排序，否则的取出来就有重复的数据
	int container[] = {5,10,15,20,25,30,35,40,45,50};
	int continent[] = {40,30,20,10};

	std::sort (container,container+9);     //  5 10 15 20 25
  	std::sort (continent,continent+4); 
	vector<int> veUnion(15);//必须分配空间，否则下面的set_union要挂
	std::vector<int>::iterator it = set_union(container, container + 9, continent, continent + 4, veUnion.begin());
	//veUnion.resize(it-veUnion.begin()); 

	for(it = veUnion.begin(); it != veUnion.end(); ++it)
		cout << " " << *it;// 5 10 15 20 25 30 35 40 45 0 0 0 0 0 0
}

{transform:将某操作应用于指定范围的每个元素
	transform(first,last,result,op);//first是容器的首迭代器，last为容器的末迭代器，result为存放结果的容器，op为要进行操作的一元函数对象或sturct、class。

	transform(first1,last1,first2,result,binary_op);//first1是第一个容器的首迭代 器，last1为第一个容器的末迭代器，first2为第二个容器的首迭代器，result为存放结果的容器，binary_op为要进行操作的二元函数 对象或sturct、class。
	注意：第二个重载版本必须要保证两个容器的元素个数相等才行，否则会抛出异常
	 #include <iostream>
	 #include <algorithm>
	 using namespace std;
	 char op(char ch)
	 {
	  
	    if(ch>='A'&&ch<='Z')
	         return ch+32;
	     else
	         return ch;
	 }
	 int main()
	 {
	     string first,second;
	     cin>>first;
	     second.resize(first.size());
	     transform(first.begin(),first.end(),second.begin(),op);
	     cout<<second<<endl;
	     return 0;
	 }	
	//利用transform函数将一个给定的字符串中的小写字母改写成大写字母，并将结果保存在一个叫second的数组里，原字符串内容不变。
	#include <iostream>
	#include <algorithm>
	#include <vector>
	using namespace std;
	void print(int &elem){cout<<elem<<" ";}
	int op(int a,int b){return a*b;}
	int main()
	{
		vector <int> A,B,SUM;
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
		    int t;
		    cin>>t;
		    A.push_back(t);
		}
		for(int i=0;i<n;i++)
		{
		    int t;
		    cin>>t;
		    B.push_back(t);
		}
		SUM.resize(n);
		transform(A.begin(),A.end(),B.begin(),SUM.begin(),op);
		for_each(SUM.begin(),SUM.end(),print);
		return 0;
	}
	//transform函数将两个vector的每个元素相乘，并输出相乘的结果。
}

{for_each://配合函数使用的for循环
	//定义
	template<typename InputIterator, typename Function>
	Function for_each(InputIterator beg, InputIterator end, Function f) {
	  while(beg != end) 
		f(*beg++);
	}	
	//例子：

	#include <iostream>     // std::cout
	#include <algorithm>    // std::for_each
	#include <vector>       // std::vector

	void myfunction (int i) {  // function:
	  std::cout << ' ' << i;
	}

	struct myclass {           // function object type:
	  void operator() (int i) {std::cout << ' ' << i;}
	} myobject;

	int main () {
	  std::vector<int> myvector;
	  myvector.push_back(10);
	  myvector.push_back(20);
	  myvector.push_back(30);

	  std::cout << "myvector contains:";
	  for_each (myvector.begin(), myvector.end(), myfunction);
	  std::cout << '\n';

	  // or:
	  std::cout << "myvector contains:";
	  for_each (myvector.begin(), myvector.end(), myobject);
	  std::cout << '\n';

	  return 0;
	}
}

{<climits>头文件定义的符号常量
	CHAR_MIN 　　　　　　char的最小值
	SCHAR_MAX 　　　　　signed char 最大值
	SCHAR_MIN 　　　　　 signed char 最小值

	UCHAR_MAX 　　　　　unsigned char 最大值

	SHRT_MAX 　　　　　　short 最大值
	SHRT_MIN　　　　　　 short 最小值
	USHRT_MAX　　　　　 unsigned short 最大值
	INT_MAX　　　　　　　int 最大值
	INT_MIN 　　　　　　　int 最小值
	UINT_MAX 　　　　　　unsigned int 最大值
	UINT_MIN  　　　　　　unsigned int 最小值
	LONG_MAX　　　　　　long最大值
	LONG_MIN 　　　　　　long最小值
	ULONG_MAX 　　　　　unsigned long 最大值
	FLT_MANT_DIG　　　　float 类型的尾数
	FLT_DIG　　　　　　　  float 类型的最少有效数字位数
	FLT_MIN_10_EXP　　　带有全部有效数的float类型的负指数的最小值（以10为底）
	FLT_MAX_10_EXP 　　 float类型的正指数的最大值（以10为底）
	FLT_MIN 　　　　　　　保留全部精度的float类型正数最小值
	FLT_MAX　　　　　　　 float类型正数最大值	
}

{std::copy 如果要把一个序列拷贝到一个容器中去，通常用std::copy算法
egg1
	int a[3] = {1, 2, 3};  
	int b[3];  
	std::copy(a, a+3, b);  
egg2	
	int myints[]={10,20,30,40,50,60,70};
	std::vector<int> myvector (7);
	std::copy ( myints, myints+7, myvector.begin() );
egg3
	std::vector<int> mVector{11,2,3,3,45,56};
	std::vector<int> mVe(6);
	std::copy ( mVector.begin(), mVector.end(), mVe.begin() );
}

{std::equal 可以用和比较字符串类似的方式来比较序列。如果两个序列的长度相同，并且对应元素都相等，equal() 算法会返回 true。
	// equal algorithm example
	#include <iostream>     // std::cout
	#include <algorithm>    // std::equal
	#include <vector>       // std::vector

	bool mypredicate (int i, int j) {
	  return (i==j);
	}

	int main () {
	  int myints[] = {20,40,60,80,100};               //   myints: 20 40 60 80 100
	  std::vector<int>myvector (myints,myints+5);     // myvector: 20 40 60 80 100

	  // using default comparison:
	  if ( std::equal (myvector.begin(), myvector.end(), myints) )
		std::cout << "The contents of both sequences are equal.\n";
	  else
		std::cout << "The contents of both sequences differ.\n";

	  myvector[3]=81;                                 // myvector: 20 40 60 81 100

	  // using predicate comparison:
	  if ( std::equal (myvector.begin(), myvector.end(), myints, mypredicate) )
		std::cout << "The contents of both sequences are equal.\n";
	  else
		std::cout << "The contents of both sequences differ.\n";

	  return 0;
}
}

{std::fill 和 std::fill_n 填充函数
	int a[10];
    fill(a,a+10,6);//全部元素填充6
	
	vector<int> v = {1,2,3,4,5,6,7,8,9};
    fill_n(v.begin(),5,1);//1,1,1,1,1,6,7,8,9
	
	vector<int> v;
    fill_n(back_inserter(v),10,1);//1 1 1 1 1 1 1 1 1 1
	back_inserter 函数是一种增量迭代插入的方式，这种方法可以动态的填装数据，避免了容量不足的情况。
}

{std::ref和std::cref

	std::ref 用于包装按引用传递的值。
	std::cref 用于包装按const引用传递的值。

	为什么需要std::ref和std::cref
	bind()是一个函数模板，它的原理是根据已有的模板，生成一个函数，但是由于bind()不知道生成的函数执行的时候，传递进来的参数是否还有效。所以它选择参数值传递而不是引用传递。如果想引用传递，std::ref和std::cref就派上用场了。

	#include <functional>
	#include <iostream>

	void f(int& n1, int& n2, const int& n3)
	{
		std::cout << "In function: n1[" << n1 << "]    n2[" << n2 << "]    n3[" << n3 << "]" << std::endl;
		++n1; // 增加存储于函数对象的 n1 副本
		++n2; // 增加 main() 的 n2
		//++n3; // 编译错误
		std::cout << "In function end: n1[" << n1 << "]     n2[" << n2 << "]     n3[" << n3 << "]" << std::endl;
	}

	int main()
	{
		int n1 = 1, n2 = 1, n3 = 1;
		std::cout << "Before function: n1[" << n1 << "]     n2[" << n2 << "]     n3[" << n3 << "]" << std::endl;
		std::function<void()> bound_f = std::bind(f, n1, std::ref(n2), std::cref(n3));
		bound_f();
		std::cout << "After function: n1[" << n1 << "]     n2[" << n2 << "]     n3[" << n3 << "]" << std::endl;
	}
	运行结果：
	Before function: n1[1]     n2[1]     n3[1]
	In function: n1[1]    n2[1]    n3[1]
	In function end: n1[2]     n2[2]     n3[1]
	After function: n1[1]     n2[2]     n3[1]

	分析
	n1是值传递，函数内部的修改对外面没有影响。
	n2是引用传递，函数内部的修改影响外面。
	n3是const引用传递，函数内部不能修改。
}

{std::is_same只用用于typedef和template两种，不能用于以声明好的变量做类型判断
	template <class T, class U> struct is_same
	这个类的用于判断T和U是否是一样的类型，包含const，volatie条件
	
	// is_same example
	#include <iostream>
	#include <type_traits>
	#include <cstdint>

	typedef int integer_type;
	struct A { int x,y; };
	struct B { int x,y; };
	typedef A C;

	int main() {
	  std::cout << std::boolalpha;
	  std::cout << "is_same:" << std::endl;
	  std::cout << "int, const int: " << std::is_same<int, const int>::value << std::endl;	//false
	  std::cout << "int, integer_type: " << std::is_same<int, integer_type>::value << std::endl;//true
	  std::cout << "A, B: " << std::is_same<A,B>::value << std::endl;//false
	  std::cout << "A, C: " << std::is_same<A,C>::value << std::endl;//true
	  std::cout << "signed char, std::int8_t: " << std::is_same<signed char,std::int8_t>::value << std::endl;//true
	  return 0;
	}
}

{std::decay 退化类型的修饰
	std::decay就是对一个类型进行退化处理
	
	template< class T >
	struct decay {
		private:
			typedef typename std::remove_reference<T>::type U;
		public:
			typedef typename std::conditional< 
				std::is_array<U>::value,
				typename std::remove_extent<U>::type*,
				typename std::conditional< 
					std::is_function<U>::value,
					typename std::add_pointer<U>::type,
					typename std::remove_cv<U>::type
				>::type
			>::type type;
		};
	其实就是把各种引用啊什么的修饰去掉，把cosnt int&退化为int，这样就能通过std::is_same正确识别出加了引用的类型了
	
	#include <iostream>
	#include <type_traits>
	template<typename TYPE>
	void typeCheck(TYPE data);
	template<typename TYPE>
	void typeCheckOne(TYPE data);
	int main()
	{
		/*unitClass unit;
		unit.functionTest();
	*/
		int a = 1;
		const int& b = a;
		int& c = a;
		int d[12];
		const int& e = d[7];
		typeCheck<int>(a);        //int type
		typeCheck<const int&>(b);//other type
		typeCheck<int &>(c);        //other type
		typeCheck<const int&>(d[7]);//other type
		typeCheck(8);                //int type
		std::cout << "=================================" << std::endl;
		typeCheckOne<int>(a);			//int type
		typeCheckOne<const int&>(b);	//int type
		typeCheckOne<int &>(c);			//int type
		typeCheckOne<const int&>(d[7]);	//int type
		typeCheckOne(8);                //int type

		int i;
		std::cin >> i;
		return 0;
	}

	template<typename TYPE>
	void typeCheck(TYPE data)
	{
		if (std::is_same<TYPE, int>::value)
		{
			std::cout << "int type" << std::endl;
		}
		else if (std::is_same<TYPE, std::string>::value)
		{
			std::cout << "string type" << std::endl;
		}
		else
		{
			std::cout << "other type" << std::endl;
		}
	}

	template<typename TYPE>
	void typeCheckOne(TYPE data)
	{
		if (std::is_same<typename std::decay<TYPE>::type, int>::value)
		{
			std::cout << "int type" << std::endl;
		}
		else
		{
			std::cout << "other type" << std::endl;
		}
	}
	
	在模板里可以通过std::is_same判断模板的类型，从而实现对不同类型的区别对待
	在堆类型要求不是非常严格的情况下，可以使用std::decay把类型退化为基本形态，结合std::is_same用，可以判断出更多的情况
	
}

{once_flag与call_once组合，实现只调用一次函数
	单例例子：
	CPageTimerManager *CPageTimerManager::instance = nullptr;
	std::once_flag page_init_flag;
	CPageTimerManager* CPageTimerManager::getInstance()
	{
		std::call_once(page_init_flag, []() { instance = new CPageTimerManager; });
		return instance;
}

}