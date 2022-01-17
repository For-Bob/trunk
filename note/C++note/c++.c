http://wenku.baidu.com/link?url=30LEUsfDOFhnt1-Oc1X4GBD7BrASiilx0QQnB_1HMLXxrhIpp_PwQs-Dk9S4nPzQJCw9jtG29BGmq8mjRQUDwnn8ADvhFbTZwDCkzMQ-eEam_KHKHUQvWy7tBQqbaiwA

http://towriting.com/blog/2013/08/01/what-is-cpp11/ //c++11，找点时间把这个链接的内容仔细看看

https://www.learncpp.com/	//官方学习通道

http://purecpp.org/	//社区

c++ primer 作为参考书 
effective c++ 要经常看
google c++ 编码风格

 二叉树的遍历主要有三种：
（1）先(根)序遍历（根左右）
（2）中(根)序遍历（左根右）
（3）后(根)序遍历（左右根）

{C++基本知识点
	
	{拷贝构造函数，赋值构造函数
		拷贝构造函数：对象以值传递方式从函数返回，且接受返回值的对象已经初始化过
			1. A a(b);
			2. A a = b;
		赋值构造函数：对象需要通过另外一个对象进行初始化
			A a;	B b;	b = a;
	}
	{static的作用
		静态局部变量，静态全局变量，静态函数
		类的静态成员和函数
	}	
	
	{c++转换
		static_cast
			static_cast<type-id> (expression)
			把expression转换为type-ID类型，但没有运行是类型检查来保证转换的安全性。
			用于基本类型之间的转换，如int转char，
			
		dynamic_cast
			dynamic_cast<type-id> (expression)
			把expression转换为type-ID类型，有运行类型的检查。
			用于将父类转为子类
	}
	
	{explicit	禁止隐式转换
		在C++程序中很少有人去使用explicit关键字，不可否认，在平时的实践中确实很少能用的上。再说C++的功能强大，往往一个问题可以利用好几种C++特性去解决。但稍微留心一下就会发现现有的MFC库或者C++标准库中的相关类声明中explicit出现的频率是很高的。
			了解explicit关键字的功能及其使用对于我们阅读使用库是很有帮助的，而且在编写自己的代码时也可以尝试使用。既然C++语言提供这种特性，我想在有些时候这种特性将会非常有用。
	}
	
	{numeric_limits 
		numeric_limits<double>::max () 
		是函数，返回编译器允许的 double 型数 最大值。
		类似的 numeric_limits<int>::max ()  返回 编译器允许的 int 型数 最大值。
	}
	
	{ofstream 和ifstream
		都是操作文件的读写，和c里面的read和write差不多，其实也是调用的read和write
		详细的看这个网站http://www.cnblogs.com/azraelly/archive/2012/04/14/2446914.html
	}
	
	
	{::的用法
		:: 的用法小结：
			用于将类内声明的静态数据成员在类外初始化；
			用于将类内声明的函数成员在类外实现；
			用于捞出继承时访问权限被改变的成员，使之还原为原来的权限；
			继承时派生类新增了与基类同名的成员，由于同名屏蔽，从而使基类的成员被遮蔽，可用: :将被遮蔽的基类成员重见天日；
			用于在类外或子类中访问不继承的静态成员；
			用于区分不同名空间的标识符。


		:: 的作用之一：恢复访问权{
			#include <iostream>  
			using namespace std;  
			class A  
			{   
			public:   
				A(int xx = 1,int yy = 2){X=xx;Y=yy;}  
				int get_XY(){return X*Y;}  
				void put_XY(){cout << X << "*" << Y <<"="<< X*Y <<endl;}  
			protected:   
				int X,Y;  
			};  
			class B:private A  
			{   
			public:   
				B(int s,int xx,int yy):A(xx,yy),S(s){} 
				A:: get_XY;  
				void make_S(){put_XY();cout<<S<<endl;}  
			private:   
				int S;  
			};  
			  
			  
			void main()  
			{  
				B b(3,5,6);  
				b.get_XY();  
				//b.put_XY(); 还是private权限，不可以在类外被访问。  
				b.make_S();  
			}  

			注意：
			恢复时不可带类型名；( int A::get_XY(); 错)
			只能恢复不可提升或降低访问权限；
			当父类被恢复的函数重载时，将全都恢复；
			父类中不同访问域的重载函数不能恢复；
			若子类新增了与父类同名的成员，则父类同名的成员不可恢复。
		}

		:: 的作用之二：隐藏再现{
			#include <iostream>  
			using namespace std;  
			class A  
			{   
			public:   
				int X,Y;   
			};  
			class B:public A  
			{   
			public:   
				int Y,Z;   
			};  
			void main()  
			{   
				B b;  
				b.X= 1;  
				b.Y= 2;  
				b.A::Y= 3;  
				b.Z= 4;  
			}  
		}
		
		:: 的作用之三：隐藏再现{
			#include <iostream>  
			using namespace std;  
			class A  
			{   
				public:  
				static int i;  
				static void Add() { i++; }  
				void out() { cout<<"static i = "<<i<<endl; }  
			};  
			int A::i= 10;  
			class B:private A   
			{  
			public:   
				A::out;   
			};  
			class C:public B  
			{   
			public:  
				void f();  
			};  
			void C::f()  
			{   
				//私有继承，化公为私  
				//i = 50; // 错  
				//Add() ; // 错  
				A:: i = 50;  
				A:: Add();  
			}  
			void main()  
			{   
				A x;  
				C y;  
				x.Add();  
				x.out();  
				y.f();  
				y.out();  
				cout<< "static i = "<<A::i<<endl;  
			};  
		}
	}

	Template{
		模板是一种对类型进行参数化的工具；
	　　通常有两种形式：函数模板和类模板；
		格式如下：
			1.Template<class T>
			2.Template<typename T>
	}
	
	{随机数
		rand()	//随机数
		rand() % 3 //小于3的随机数
	}
	
}

{STL
	{容器
		vector:			可变大小数组，支持快速随机访问
		deque:			双端队列，支持快速随机访问，向前或向后快速插入/删除
		list:			双向链表，支持双向顺序访问，支持快速插入/删除在链表的的任何节点
		forward_list:	单向链表，仅支持单向顺序访问，支持快速插入/删除在链表的的任何节点
		array:			固定大小数组，支持快速随机访问，不能增加或移除节点
		string:			一个特殊的容器，与vector有点类似，但是只能包含字符串，快速随机访问，支持在末尾快递插入/删除
		{pair
			pair<T,T1>pairdata;	//creat the pair data
			pairdata = make_pair(data1,data2);	//insert data,pair only insert one make_pair
			cout<<"first:"<<pairdata.first<<"second:"<<pairdata.second<<endl;	//print the value of the pair
		}
		
		{tuple
			#include <tuple>
			tuple<T, T1, T2> tuple1;   //creates tuple of integers
			tuple1 = make_tuple(DATA1, DATA2, DATA3);    // insert DATA1, DATA2 and DATA3 to the tuple1,tuple only insert one make_tuple
			T Pdata1;
			T1 Pdata2;
			T2 Pdata3;
			tie(Pdata1,Pdata2,Pdata3) = tuple1;
			cout<<"first:"<<Pdata1<<"second:"<<Pdata2<<"thrid:"<<Pdata3<<endl;	//print the value of the tuple
		}
		
		{array
			array<T,size> data_array;	//T is type,size is equal the length		
			array<int, 4> odd_numbers = { 2, 4, 6, 8 };	//init the odd_numbers		
			at(index)	//get the element of the index 
			[]	//is equal to "at"
			front()	//This method returns the first element in the array.
			back()	//This method returns the last element in the array.
			fill()	//This method assigns the given value to every element of the array
				instance:
						array<int,8> myarray;
						myarray.fill(1);		//This will fill the array myarray with value as 1, at all of its 8 available positions.
						
			swap()	//This method swaps the content of two arrays of same type and same size.
				instance:
					array<string, 8> a = { "my1","2","3","4","5","6","7","8" };
					array<string, 8> b = { "8","7","6","5","4","3","2","1" };
					a.swap(b);	//swaps array a and b 
			
			operators ( == , != , > , < , >= , <= )
				All these operators can be used to lexicographically compare values of two arrays.	//in fact that is logic judgement
			
			empty()
				This method can be used to check whether the array is empty or not.Syntax : array_name.empty(), returns true if array is empty else return false. 
			
			size()
				This method returns the number of element present in the array.
				
			max_size()
				This method returns the maximum size of the array.
				
			begin() and end()	//This method returns the iterator pointing to the first element of the array,This method returns an iterator pointing to an element next to the last element in the array
				//begin and end like the pointer
				instance:
					for (auto j = begin(odd_numbers); j != end(odd_numbers); j++)
						cout << *j<<" ";

		}
		
		{VECTOR and the simple usage for iterator
			1.成员函数：
				1.push_back   在数组的最后添加一个数据
				2.pop_back    去掉数组的最后一个数据 
				3.at                得到编号位置的数据
				4.begin           得到数组头的指针
				5.end             得到数组的最后一个单元+1的指针
				6.front        得到数组头的引用
				7.back            得到数组的最后一个单元的引用
				8.max_size     得到vector最大可以是多大
				9.capacity       当前vector分配的大小
				10.size           当前使用数据的大小
				11.resize         改变当前使用数据的大小 -----如 myvector.resize(10);
					调用resize之后，size将会返回n。如果n小于当前大小，容器尾部的元素会被销毁。如果n大于当前大小，新默认构造的元素会添加到容器尾部。如果n大于当前容量，在元素加入之前会发生重新分配。
				12.reserve      改变当前vecotr所分配空间的大小---如 myvector.reserve(10)
					强制容器把它的容量改为至少n，提供的n不小于当前大小。这一般强迫进行一次重新分配，因为容量需要增加。（如果n小于当前容量，vector忽略它，
					这个调用什么都不做，string可能把它的容量减少为size()和n中大的数，但string的大小没有改变。在我的经验中，使用reserve来从一个string中修整多余容量一般不如使用“交换技巧”，那是条款17的主题。）
				13.erase         删除指针指向的数据项
				14.clear          清空当前的vector
				15.rbegin        将vector反转后的开始指针返回(其实就是原来的end-1)
				16.rend          将vector反转构的结束指针返回(其实就是原来的begin-1)
				17.empty        判断vector是否为空
				18.swap         与另一个vector交换数据
				19.insert
					insert(iterator,data);			//在iterator元素之前插入data
					insert(iterator,count,data);	//在iterator元素count个之前插入data
					insert(iterator,vector1.begin(),vector1.end());	//在iterator元素之前vector1的所有元素
			2.初始化
				vector<int> a ;                                //声明一个int型向量a
				vector<int> a(10) ;                            //声明一个初始大小为10的向量
				vector<int> a(10, 1) ;                         //声明一个初始大小为10且初始值都为1的向量
				vector<int> b(a) ;                             //声明并用向量a初始化向量b
				
				int x[] = { 1, 2, 3, 4, 5 };
					vector<int> myvector(x, x + 5);			   //将myvector的值初始化为数组第0个到第5-1个，一共5个
					
				vector<int> b(a.begin(), a.begin()+3) ;        //将a向量中从第0个到第2个(共3个)作为向量b的初始值
			3.例子
			{begin和end、rbegin和rend：int 、 string and char[]
				#include <iostream>
				#include <vector>
				#include <algorithm>
				#include <string>

				using namespace std;

				void ReverseString(char *Src)
				{
					int i = 0;
					string mysrc = Src;
					reverse_iterator<string::iterator> rsrc;
					for (rsrc = mysrc.rbegin(); rsrc != mysrc.rend(); rsrc++,i++)
						Src[i] = *rsrc;
				}

				int main()
				{
					/******开始:反转char*******/
					char p_str[] = "hello world";
					ReverseString(p_str);			
					printf("after reverse: %s\n",p_str);
					/******结束:反转char*******/

					/*******开始:排序int,反转int********/
					vector<int> numVector;
					for (int i = 0; i < 5; i++)
					{
						numVector.push_back(i);
						i++;
					}

					for (int i = 1; i < 6; i++)
					{
						numVector.push_back(i);
						i++;
					}


					sort(numVector.begin(), numVector.end());
					cout << "\nafter sort" << endl;
					vector<int>::iterator it_numVector;
					for (it_numVector = numVector.begin(); it_numVector != numVector.end(); it_numVector++)
						cout << "\t" << *it_numVector;

					vector<int>::reverse_iterator rint;
					cout << "\reverse vector" << endl;
					for (rint = numVector.rbegin(); rint != numVector.rend(); rint++)
						cout << "\t" << *rint;
					/*******结束:排序int,反转int********/
					
					/*******开始:反转string********/
					string world = "hello world";
					reverse_iterator<string::iterator> r;
					cout << "\nstring reserve" << endl;
					for (r = world.rbegin(); r != world.rend(); r++)
						cout << *r;
					/*******结束:反转string********/
					
					int i;
					cin >> i;
					return 0;
				}
			}
			
		}
		
		{list
			初始化list
				list<T> instance_list;	//creat the empty linked list
				list<int> instance_list{,1,2,3};	//creat the new linked list 
			
			insert()
				insert(iterator,data);			//在iterator元素之前插入data
				insert(iterator,count,data);	//在iterator元素count个之前插入data
				insert(iterator,vector1.begin(),vector1.end());	//在iterator元素之前vector1的所有元素
				
			push_back(element)		//push_back(element) method is used to push elements into a list from the back.
			push_front(element) 	//method is used to push elements into a list from the front.
			
			pop_back and pop_front
				pop_front() removes first element from the start of the list. While pop_back() removes first element from the end of the list.
				
			empty
				This method returns true if the list is empty else returns false.
				
			size
				This method can be used to find the number of elements present in the list.
				
			front and back
				front() is used to get the first element of the list from the start while back() is used to get the first element of the list from the back.
				
			swap
				Swaps two list, if there is exception thrown while swapping any element, swap() throws exception. Both lists which are to be swapped must be of the same type, i.e you can’t swap list of an integer with list of strings. 
				
			reverse
				This method can be used to reverse a list completely.
				instance:
					list.reverse()
			
			sort() method sorts the given list.
				sort() : sorts the elements of the list in ascending order, the element of the list should by numeric for this function.
				sort(compare_function) : This type of sort() is used when we have to alter the method of sorting.
				instance:
					bool compare_function( string& s1 , string& s2 )
					{
					return ( s1.length() < s2.length() );		//compare_function‘>’降序(最大的在前面)；‘<’升序(最小的在前面)
					}

					int main()
					{
					  list<int> list1 = {2,4,5,6,1,3};
					  list<string> list2 = {"h" , "hhh" , "hh"};

					  list1.sort();
					  /* list1 is now 1 2 3 4 5 6 */

					  list2.sort(compare_function);
					  /* list2 is now h hh hhh */ 
					}
			
			splice() method transfers the elements from one list to another.	//是转移，不是结合，把自己的元素转移给另外的list，自己转移的给其他list的自己也就没有了			
				splice(iterator, list_name) : Transfers complete list list_name at position pointed by the iterator.then list_name is null;
				splice(iterator, list_name, iterator_pos) : Transfer elements pointed by iterator_pos from list_name at position pointed by iterator.
				splice(iterator, list_name, itr_start, itr_end) : Transfer range specified by itr_start and itr_end from list_name at position pointed by iterator.

			merge() Merges two sorted list. It is mandatory that both the list should be sorted first.	
				merge之前一定要先排序不然会出现不可预料的错误。
				list1.merge(list2);		//merge之后程序运行发现list2为空了，	
		}
		
		{map
			map<key_type , value_type> map_name;	//和QMAP有很多相同的用法
			
			初始化
				map<int,int> m{ {1,2} , {2,3} , {3,4} };
				map<string,int> map1; 
				  map1["abc"]=100;    // inserts key = "abc" with value = 100
				  map1["b"]=200;      // inserts key = "b" with value = 200
				  map1["c"]=300;      // inserts key = "c" with value = 300
				  map1["def"]=400;    // inserts key = "def" with value = 400
				map<char,int> map2 (map1.begin(), map1.end());
				  /* creates a map map2 which have entries copied 
						from map1.begin() to map1.end() */ 
				map<char,int> map3 (m);
					/* creates map map3 which is a copy of map m */
			
			at and []	//键，得到对应的值
			
			empty, size and max_size	//和其他的list，vector一样的用法
			
			insert and insert_or_assign	//插入
				insert(pair)			//map.insert(pair<int,int>(5,6))
				
				 map::iterator i , j;
				  start_itr = m.find(2);    // points to entry having key =2
				  end_itr = m.find(5);    // points to entry having key =5
				insert(start_itr , end_itr)	//map.insert(2对应的值，5对应的值);
			insert_or_assing() works exactly as insert() except that if the given key is already present in the map then its value is modified.
				也是插入的意思，如果已经存在对应的键，那么就修改对应的值就行了，其他和insert功能一样。
			
			earse(iterator)移除map中iterator指向的那个值
			erase(start_iterator, end_iterator) : 
				/****begin:operate of map*******/
				map<int, string> m{ { 1,"nikhilesh" } ,{ 2,"shrikant" } ,{ 3,"ashish" },{4,"naype"} };
				map<int, string>::iterator it_map;
				map<int, string>::iterator it_map1;
				
				it_map = m.begin();
				it_map1 = m.find(3);
				cout << "size:" << m.size();

				m.erase(it_map, it_map1);	//移除1到3（不包括3）之间的子map
				//m.erase(it_map);	//移除第一个子map
				cout << "size:" << m.size()<<endl;

				it_map = m.begin();

				while (it_map != m.end())
				{
					
					cout<<"key:"<<it_map->first;
					cout<<"valude:"<<it_map->second<<endl;
					it_map++;
				}
				/****end:operate of map*******/
			clear	//移除map中所用的值
			
			begin()	//返回map的第一个
				
			end()	//返回map的最后一个
			find(key)	//返回map的key_value等于key的子map		
				
			与auto的使用例子：
				for(auto it: map1)
				{
					qDebug() << it.first << it.second;
				}
			
		}
		
		{stack
			stack<object_type> stack_name;
			添加和删除总是从最上面操作
			push()	//插入
			pop()	//弹出
			top()	//返回stack最顶部的元素
			size()	//实际大小
			empty()	//判断是否为空
			swap()	//交换
		}
		
		{queue
			push()	用于插入
			pop()	弹出
			front()	返回队列的第一个元素
			back()	返回队列的最后一个元素
			size()	返回队列中实际元素的个数
			empty()	判断队列是否为空
			swap()	交换
		}
		
		{priority queue
			queue实际是差不多的，唯一不同的是，pop()总是弹出元素中最大的那个，而不是都是最后压入的
			push()	用于插入
			pop()	弹出		
			size()	返回队列中实际元素的个数
			empty()	判断队列是否为空
			swap()	交换
		}
		
		{deque
			双队列是速记的双重的结尾队列
			push_back(element e)插入一个元素e在队列的末尾
			push_front(element e)插入一个元素e在队列的起始位置
			insert有三种方式：			
				insert(iterator i, element e) : 在队列的i之前插入e
				insert(iterator i, int count, element e) : 在队列的i之前插入count个e
				insert(iterator i, iterator first, iterator last) : 在队列的i之前插入first到last之间的元素
			pop_back()弹出队列的最后一个元素，队列的长度大小减一
			pop_front()弹出队列的第一个元素，队列的长度大小减一
			empty	判断是否为空
			size	返回队列中当前元素的个数
			max_siza	返回内存分配给队列中最大的占用空间
			swap	交换两个队列
		}
	}
	
	{算法
		用所有算法之前，最好先用sort先排序
		
		{iterator
			iterator用于指向容器
			声明iterator
				container_type<parameter_list>::iterator iterator_name;
			advance(iterator i ,int distance)	i = i + distance；
			
			distance(iterator first, iterator last)	返回last和first之间相差的个数
			
			next(iterator i ,int n) 返回 i+n，i不变
			
			prev(iterator i, int n)	返回 i-n，i不变
		}

		{sort	
			sort(start_iterator, end_iterator )	按升序的方式排序
			sort(start_iterator, end_iterator, compare_function) :按compare_function的方式排序：compare_function‘>’降序(最大的在前面)；‘<’升序(最小的在前面)
			instance:
				bool compare_function( string& s1 , string& s2 )
				{
				return ( s1.length() < s2.length() );		//compare_function‘>’降序(最大的在前面)；‘<’升序(最小的在前面)
				}

				int main()
				{
				  list<int> list1 = {2,4,5,6,1,3};
				  list<string> list2 = {"h" , "hhh" , "hh"};

				  list1.sort();
				  /* list1 is now 1 2 3 4 5 6 */

				  list2.sort(compare_function);
				  /* list2 is now h hh hhh */ 
				}
				
			partial_sort()	先排序前半部分元素，官方解释-“剩余部分往后面移然后保持原来的顺序”。实际上并不是，还是排序了，但并没有完全排序玩
				partial_sort(start, middle, end )	在start到end的范围内，按照升序的方式来先拍start到middle的个数，
				partial_sort(start, middle, end, compare_function)	在start到end的范围内，按照升/降序的方式（取决去compare_function的'>'或者'<'）来先排start到middle的个数，
				
			is_sorted()	判断是否已经排序，返回ture或者flase
				is_sorted(start_iterator, end_iterator)	检查start_iterator到end_iterator范围内是否已升序排序了
				is_sorted(start_iterator, end_iterator, compare_function)	检查start_iterator到end_iterator范围内是否排序取决于compare_function了
		}
		
		{binary_search
			用于查找在给定范围内是否有要查找的元素，有就返回true，否则就返回false
			注意一点：程序运行时，发现必须先排序，否则是找不到的
			binary_search(first, last, value)	//直接查找
			binary_search(first, last, value, compare_function)	//按照compare_function排序，然后来查找
		}
		
		{equal_range
			返回一对iterator，当给的元素在是在范围内,不在的话要异常出错
			equal_range(first, last, value)
			equal_range(first, last, value, compare_function)
			
			instance
				bool compare_function (int i,int j) { return (i <= j); }

				int main () 
				{
				   int input[] = {1,1,1,2,2,2,3,3,6,7,7,7,7,7,8,9};
				   vector<int> v(input, input+16);
							   
				   pair< vector<int>::iterator, vector<int>::iterator > sub_range;
				   /* defining the pair of two iterators to an integer vector */

				 
				   sub_range = equal_range (v.begin(), v.end(), 2);	
				   /* now sub_range.first points to 4th element in the vector v and 
					 sub_range.second points to 7th element , 
					 note that sub_range.secong points to the element 
					 which is next to the element in the subrange  */ 
					 cout << *(sub_range.first)<<" "<<*(sub_range.second);	//print
					 //first is value，second is the end of next current value

				   sub_range = equal_range (v.begin(), v.end(), 20, compare_function);
				   /* sub_range.first points to first element in the vector v , 
				   as it satisfy the condition exerted by compare_function , <= , 
					 sub_range.second points to 7th element in the vector . */
				}
		}
		
		 lower_bound(first,last,val)	算法返回一个非递减序列[first, last)中的第一个大于等于值val的位置。
		 upper_bound(first,last,val)	算法返回一个非递减序列[first, last)中第一个大于val的位置。
		 
		 {count
			返回给定值的个数
				count(first ,last ,value)	//返回在first和last之间value的个数
		 }
		 
		 {equal
			equal(first1, last1, first2)	//判断在first1到last1之间的所有元素是否与frist2开始的个数(first1到last1之间的个数)的元素相等
			equal(first1, last1, first2,compare_function)	//如果compare_function返回时true也是返回true
		 }
	
		{mismatch
			mismatch(first1, last1, first2)	返回一对iterator，iterator.first是first1的第一个不同的值，iterator.second是first2的第一个不同的值。
		}
		
		{search
			search(first1 ,last1 ,first2 ,last2)	查找first2到last2在first1到last1间，找到的话，就返回第一次找到first1到last1之间的位置，否则返回last1的位置
			search(first1, last1, count, value)	一样的查找，只是在first1到last1之间查找count个value
		}
		
		copy() and copy_n()
		fill() and fill_n()
		{move()
			instance：
				string b = "Vicky";
				string c;
				c = move(b);	//c = "Vicky" b is null now
				
		}		
	}
}

{C和C++ 之间的相互转化
	{string和char之间的相互转化
		1.c++的string转char*
			string Mystring = "hello world";
			const char *p_str = Mystring.c_str();
			const char *p_str1 = Mystring.data();
			printf("frist:%s,second:%s\n",p_str,p_str1);
			
		2.c++的string转char[]
			string Mystring = "hello world";
			char Chstring[1024];
			int length = Mystring.size();
			for(int i = 0; i < length; i++)
				Chstring[i] = Mystring[i];
		
		3.char[]、char*转string
			char chString[] = "hello world";
			char *pString = "hello world";
			string myString;
			myString = chString;
			myString = pString;
	}	
}

{ 分隔字符串
更多使用方法https://www.cnblogs.com/happykoukou/p/5427268.html
	1.使用strtok 可以多个字符处理
	#include <stdio.h>
	#include <string.h>

	  char str[] ="- This, a sample string.";
	  char * pch;
	  printf ("Splitting string \"%s\" into tokens:\n",str);
	  pch = strtok (str," ,.-");
	  while (pch != NULL)
	  {
		printf ("%s\n",pch);
		pch = strtok (NULL, " ,.-");
	  }
	
	2.使用istringstream 只能处理一个字符
	#include <sstream>
	#include <iostream>
	#include <vector>
	using namespace std;

	string s = "a2/4b/5c/opd";
	istringstream iss(s);
	string buffer;
	while(getline(iss, buffer, '/')){
		cout<<buffer<<endl;
	}
}

{随机数
#include <time.h>

template<typename T>
T RandT(T _min, T _max)
{
	T temp;
	if (_min > _max)
	{
		temp = _max;
		_max = _min;
		_min = temp;
	}
	return rand() / (double)RAND_MAX *(_max - _min) + _min;
}
srand((unsigned)time(NULL));
RandT<int>(1, 10);//生成1到10的随机数
}

{std::cout //格式输出
	int value = 31;
	std::cout << oct << "value:" << value << std::endl;//八进制输出
	std::cout << *dec << "value:" << value << std::endl;//十进制输出
	std::cout << hex << "value:" << value << std::endl;//十六进制输出
	std::cout << setbase(8) << "value:" << value << std::endl;//八进制输出
	std::cout << setbase(10) << "value:" << value << std::endl;//十进制输出
	std::cout << setbase(16) << "value:" << value << std::endl;//十六进制输出

	double dValue = 32;
	std::cout << "value: " << dValue << std::endl;
	std::cout << fixed << "value: " << dValue << std::endl;//32.000000
	std::cout << scientific << "value: " << dValue << std::endl;//3.200000e+01 指数

	bool bValue = true;
	std::cout << boolalpha << "bValue: " << bValue << std::endl;//输出true
	
	setiosflags(ios::fixed) 固定的浮点显示 
	setiosflags(ios::scientific) 指数表示 
	setiosflags(ios::left) 左对齐 
	setiosflags(ios::right) 右对齐 
	setiosflags(ios::skipws 忽略前导空白 
	setiosflags(ios::uppercase) 16进制数大写输出 
	setiosflags(ios::lowercase) 16进制小写输出 
	setiosflags(ios::showpoint) 强制显示小数点 
	setiosflags(ios::showpos) 强制显示符号 
	
	//类型获取
	std::cout << typeid(value).name() << std::endl;//输出int
}
