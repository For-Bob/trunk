makefile{
	//学习网站：http://www.cnblogs.com/wang_yb/p/3990952.html
	http://goodcandle.cnblogs.com/archive/2006/03/30/278702.html	//例子
	
	{编译宏
		int main()
		{
			#ifdef DEBUG
		   printf("1\n"); 
		   #elif RELEASE
		   printf("2\n"); 
		   #else
			printf("3\n"); 
		   #endif
		  return 0;
		}
		
		g++ -DDEBUG file.cpp -o file //打印 1 
		g++ -DRELEASE file.cpp -o file //打印 2 
		g++ -DSDFA file.cpp -o file //打印 3
	}
	
	Makefile有三个非常有用的变量。分别是$@，$^，$<代表的意义分别是：
		$@--目标文件，$^--所有的依赖文件，$<--第一个依赖文件。
	
	makefile基本命令{
		edit : main.o kbd.o command.o display.o insert.o search.o files.o utils.o
			cc -o edit main.o kbd.o command.o display.o insert.o search.o files.o utils.o
		target ... : prerequisites ...
			command
		target 也就是一个目标文件，
		prerequisites 就是，要生成那个 target 所需要的文件或是目标
		command 也就是 make 需要执行的命令
	}
	
	{$ $@例子说明
		%.o: %.c
       $(CC) $(CFLAGS) -c $< -o $@
	%.o:%.cpp
		   $(XX) $(CFLAGS) -c $< -o $@
       这几句命令表示把所有的.c,.cpp编译成.o文件。
	   $@就是生产的.o文件
	}
	
	自动生成依赖性{
		如果main.c中有一句"#include "defs.h""
		main.o:main.c defs.harderr
		
		cc -M main.c
		其输出：
		main.o:main.c defs.h
		/*于是由编译器自动生成的依赖关系，这样一来，你就不必再手动书写若干文件的依赖关系，而由编译
	器自动生成了。需要提醒一句的是，如果你使用 GNU 的 C/C++编译器，你得用"-MM"参数，不然， "-M"
	参数会把一些标准库的头文件也包含进来。*/
	}
	
	makefile中使用变量{
		objects = main.o kbd.o command.o display.o insert.o search.o files.o utils.o
		edit : $(objects)
			cc -o edit $(objects)	//与上面是等价的
	}
	
	makefile自动推导{
		utils.o : utils.c defs.h
			cc -c utils.c
		等价于
	=	utils.o : defs.h
	}
	
	引用其它的 Makefile{
		include foo.make *.mk $(bar)
		等价于
	=	include foo.make a.mk b.mk c.mk e.mk f.mk
	}
	
	伪目标{
		PHONY: clean
	clean:
		rm *.o temp
		//make clean 就会删除所有后缀名为.o的文件和temp
		"伪目标"并不是一个文件，只是一个标签， 由于"伪目标"不是
		文件，所以 make 无法生成它的依赖关系和决定它是否要执行。我们只有通过显示地指明这个"目标"才能让
		其生效。当然， "伪目标"的取名不能和文件名重名，不然其就失去了 "伪目标"的意义了。
		all : prog1 prog2 prog3
		.PHONY : all
		prog1 : prog1.o utils.o
			cc -o prog1 prog1.o utils.o
		prog2 : prog2.o
			cc -o prog2 prog2.o
		prog3 : prog3.o sort.o utils.o
		cc -o prog3 prog3.o sort.o utils.o
		//make all 就会编译上面所有的文件
		"$@"表示目标的集合，
	}
	
	变量的基础{
		foo = c
		prog.o : prog.$(foo)
			$(foo)$(foo) -$(foo) prog.$(foo)
		展开后得到：
		prog.o : prog.c
			cc -c prog.c
		//强烈建议你给变量加上括号
		变量中的变量{
			x := foo
			y := $(x) bar
			x := late
			//等价于
			y := foo bar
			x := later
			
			FOO ?= bar
			其含义是，如果 FOO 没有被定义过，那么变量 FOO 的值就是"bar"，如果 FOO 先前被定义过，那么
			这条语将什么也不做
			}
		
		变量的替换{
			//其格式是"$(var:a=b)"或是"${var:a=b}"，其意思是，把变量"var"
										//中所有以"a"字串 "结尾"的"a"替换成"b"字串。
			foo := a.o b.o c.o
			bar := $(foo:.o=.c)
			//意思是把"$(foo)"中所有以".o"字串 "结尾"全部替换成".c"，
			//把变量的值再当成变量
			{
				x = y
				y = z
				a := $($(x))
				//$(x)的值是"y"，所以$($(x))就是$(y)，于是$(a)的值就是"z"
				
				x = $(y)
				y = z
				z = Hello
				a := $($(x))
				//这里的$($(x))被替换成了 $($(y))，因为$(y)值是"z"，所以，最终结果是： a:=$(z)，也就是"Hello"。
			}
		}
	}
	
	特殊变量vpath{
			VPATH//如果没有指明这个变量，make只会在当前目录中去寻找依赖文件和目标文件
					//如果定义了这个变量，make会在当前目录找不到的情况下，到所指定的目录中去找寻文件
			vpath%.c foo:bar	
			vpath%.c blish		//先在foo目录找.c的文件，然后在blish目录下，最后才是bar目录下	
			1. vpath <pattern> <directories>
			为符合模式<pattern>的文件指定搜索目录<directories>。
			2. vpath <pattern>
			清除符合模式<pattern>的文件的搜索目录。
			3. vpath
			清除所有已被设置好了的文件搜索目录。
		}
	
	if{
		if 
		else
		endif
		
		ifdef只是测试一个变量是否有值
		endif
		
		$(if <condition>,<then-part>,<else-part>)
		而 if函数的返回值是，如果<condition>为真（非空字符串）， 那个<then-part>会是整个函数的返回值，
		如果<condition>为假（空字符串）， 那么<else-part>会是整个函数的返回值，此时如果<else-part>没有被定义，
		那么，整个函数返回空字串。
	}
	
	foreach 函数{
		//相当于for函数
		names := a b c d
		files := $(foreach n,$(names),$(n).o)
		//$(files)的值是"a.o b.o c.o d.o"
	}
	
	make的参数{
		"-"	//在include前面一个"-",无论include过程中出现什么错误，都不报错继续执行。
		"-b"
		"-m"
		//忽略和其他版本make的兼容性
		"~"//如果是"~、test"表示是$HOME目录下的test目录
		"-B"
		"-always-make"
		//认为所有的目标都需要更新（重编译）
		"-C<dir>"
		"-directory=<dir>"
		/*指定读取makefile的目录。如果有多个"-C"参数，make的解释是后面的路径以前面的
		作为相对路径，并以最后的目录作为被指定目录。如："make -C ~hchen/test -C prog"
		等价于"make -C ~hchen/test/prog"*/
		"=debug[=<options>]"
		//输出make的调试信息。它有几种不同级别可供选择，如果没有参数，输出简单的调试信息
		<options>的取值
		a--也就是all，输出所有的调试信息
		b--就是basic，只输出简单的调试信息，不需要重编译
		v--也就是verbose，在b选项的级别之上。输出的信息包括哪个makefile被解析。
		i--也就是implicit，输出所有的隐含规则。
		j--也就是jobs，输出执行规则中命令的详细信息，如命令的PID、返回码等。
		m--也就是makefile，输出make读取makefile，更新makefile，执行makefile的信息。
		"-d"
		相当于"--debug=a"
		"-e"
		"-environment-overrides"
		指明环境变量的值覆盖makefile中定义的变量的值。
		"-f=<file>"
		"-file=<file>"
		"-makefile=<file>"
		指定需要执行的makefile
		"-i"
		"-ignore-errors"
		在执行时忽略所有的错误
		"-I<dir>"
		"-include-dir=<dir>"
		指定一个被包含makefile的搜索目标。可以使用多个"-I"参数来指定多个目录
		"-j[<jobsnum>]"
		"-jobs[=<jobsnum>]"
		指同时运行命令的个数。如果没有这个参数，make运行命令是能运行多少就运行多少
		m —— 也就是 makefile， 输出 make 读取 makefile，更新 makefile，执行 makefile 的信息。
		"-d" 
		相当于" --debug=a"
		"-e" 
		"--envienvironmentronment-overrides"
		指明环境变量的值覆盖 makefile 中定义的变量的值。
		"-f=<file>" 
		"--f=<file>" 
		 "--makefile=<file>" 
		指定需要执行的 makefile。
		 "-h" 
		 "-help" 
		显示帮助信息。
		 "-i" 
		 "--ignoreignore-errors" 
		在执行时忽略所有的错误。

		 "-I <dir>" 
		 "--includeinclude-dir=<dir>" 
		指定一个被包含 makefile 的搜索目标。可以使用多个" -I" 参数来指定多个目录。
		 "-j [<jobsnum>]" 
		 "--jobs[=<jobsnum>]" 
		指同时运行命令的个数。如果没有这个参数， make 运行命令时能运行多少就运行多少。如果有一个
		以上的" -j" 参数，那么仅最后一个" -j" 才是有效的。（注意这个参数在 MS-DOS 中是无用的）
		"-k"
		"-keep-going"
		出错也不停止运行。如果生成一个目标失败了，那么依赖于其上的目标就不会被执行了。
		伪代码{
				"all" 		//编译多有的目标
				"clean"		//删除所有被make创建的文件
				"install"	//安装已编译好的程序，就是把目标文件拷贝到指定的目标中去
				"print"		//列出改变过的源文件
				"tar"		//把源程序打包备份，也就是一个tar文件。
				"dist"		//创建一个压缩文件，一般是把tar文件压成Z文件。或者gz文件。
				"TAGS"		//更新所有的目标，以备完整的重编译使用。
				"check"and"test"	//一般用来测试makefile的流程
		}
	}
	
	检查规则{
		"-n"
		"-just-print"
		"-dry-run"
		"-recon"
		//不执行参数，这些参数只是打印命令
		"-t"
		"-touch"
		//把目标文件的时间更新，但不更改目标文件
		"-q"
		"-question"
		//找目标的意思，目标存在，什么都不输出， 不存在，打印一条出错信息。
		
		"-W <file>"
		"--whatwhat--if=<file>"
		"--assumeassume-new=<file>" 
		"--newnewnewnew-file=<file>"
		这个参数需要指定一个文件。一般是是源文件（或依赖文件）， Make 会根据规则推导来运行依赖于这
		个文件的命令，一般来说，可以和" -n" 参数一同使用，来查看这个依赖文件所发生的规则命令。
		另外一个很有意思的用法是结合" -p"和" -v"来输出 makefile 被执行时的信息（这个将在后面讲述）。
	}
	
	多目标{
		bigoutput littleoutput : text.g
		 generate text.g -$(subst output,,$@) > $@
		上述规则等价于：
		bigoutput : text.g
		 generate text.g -big > bigoutput
		littleoutput : text.g
		 generate text.g -little > littleoutput
		其中，-$(subst output,,$@)中的"$"表示执行一个 Makefile 的函数，函数名为 subst，后面的为参数。关
		于函数，将在后面讲述。这里的这个函数是截取字符串的意思，"$@"表示目标的集合，就像一个数组， "$@"
		依次取出目标，并执于命令
	}
	
	静态模式{
		<targets ...>: <target-pattern>: <prereq-patterns ...>
		 <commands>
		 ...
		targets 定义了一系列的目标文件，可以有通配符。是目标的一个集合。
		target-parrtern 是指明了 targets 的模式，也就是的目标集模式。
		prereq-parrterns 是目标的依赖模式， 它对 target-parrtern 形成的模式再进行一次依赖目标的定义。
		
		objects = foo.o bar.o
		all: $(objects)
		$(objects): %.o: %.c
			$(CC) -c $(CFLAGS) $< -o $@
		上面的例子中，指明了我们的目标从$object 中获取， "%.o"表明要所有以".o"结尾的目标，也就是"foo.o
		bar.o"，也就是变量$object 集合的模式，而依赖模式"%.c"则取模式"%.o"的"%"，也就是"foo bar"， 并为其
		加下".c"的后缀，于是，我们的依赖目标就是"foo.c bar.c"。而命令中的"$<"和"$@"则是自动化变量， "$<"
		表示所有的依赖目标集（也就是"foo.c bar.c"）， "$@"表示目标集（也就是"foo.o bar.o"）。 于是，上面的规则
		展开后等价于下面的规则：
		foo.o : foo.c
			$(CC) -c $(CFLAGS) foo.c -o foo.o
		bar.o : bar.c
			$(CC) -c $(CFLAGS) bar.c -o bar.o
	}
	
	显示命令{
		@echo 正在编译 XXX 模块......
		当 make 执行时，会输出"正在编译 XXX 模块......"字串，但不会输出命令，如果没有"@"，那么， make
		将输出：
		echo 正在编译 XXX 模块......
		正在编译 XXX 模块...... 
	}
	
	命令执行{
		你的第一条命令是 cd 命令，你希望第二条命令得在 cd 之后的基础上运行，那么你就不能把这两条命令写
		在两行上，而应该把这两条命令写在一行上，用分号分隔。如：
		 示例一：
		exec:
		 cd /home/hchen
		 pwd
		 示例二：
		exec:
		 cd /home/hchen; pwd
		当我们执行"make exec"时， 第一个例子中的 cd 没有作用， pwd 会打印出当前的 Makefile 目录，而第
		二个例子中， cd 就起作用了， pwd 会打印出"/home/hchen"。
	}
	
	变量高级用法{
		其格式是"$(var:a=b)"或是"${var:a=b}"，其意思是，把变量"var"中所有以"a"字串"结尾"的"a"替换成"b"字串。
		还是看一个示例吧：
		foo := a.o b.o c.o
		bar := $(foo:.o=.c)
		这个示例中，我们先定义了一个"$(foo)"变量，而第二行的意思是把"$(foo)"中所有以".o"字串 "结尾"全
		部替换成".c"，所以我们的"$(bar)"的值就是"a.c b.c c.c"。
		
		x = variable1
		variable2 := Hello
		y = $(subst 1,2,$(x))
		z = y
		a := $($($(z)))
		这个 例子 中 ， "$($($(z)))"扩展 为 "$($(y))"，而其再 次被扩展 为 "$($(subst 1,2,$(x)))"。 $(x) 的 值是
		"variable1"， subst 函数把"variable1"中的所有"1"字串 替换成"2"字串，于是， "variable1"变成"variable2"，再
		取其值，所以，最终， $(a)的值就是$(variable2)的值——"Hello"。
		
		可以使用多个变量来组成一个变量的名字，然后再取其值：
		first_second = Hello
		a = first
		b = second
		all = $($a_$b)
		这里的"$a_$b"组成了 "first_second"，于是， $(all)的值就是"Hello"。
	}
	 
	ifdef{
		ifdef只是测试一个变量是否有值
		 示例一：
		bar =
		foo = $(bar)
		ifdef foo
		frobozz = yes
		else
		frobozz = no
		endif
		 示例二：
		foo =
		ifdef foo
		frobozz = yes
		else
		frobozz = no
		endif
		第一个例子中， "$(frobozz)"值是"yes"， 第二个则是"no"。
	}
	
	字符串处理函数{
		$(subst <from>,<to>,<text>){//字符串 替换函数——subst。
			 功能：：
			把字串 <text>中的<from>字符串 替换成<to>。
			 返回：：
			函数返回被替换过后的字符串。
			 示例：：
			$(subst ee,EE,feet on the street)
			把"feet on the street"中的"ee"替换成"EE"， 返回结果是"fEEt on the strEEt"。
		}
		
		$(patsubst <pattern>,<replacement>,<text>){//模式字符串 替换函数——patsubst
			查找<text>中的单词（单词以"空格"、" Tab"或" 回车""换行"分隔）是否符合模式<pattern>，
			如果匹配的话，则以<replacement>替换。这里， <pattern>可以包括通配符" %"， 表示任意长度
			的字串。如果<replacement>中也包含" %"，那么， <replacement>中的这个" %"将是<pattern>
			中的那个" %"所代表的字串。（可以用" \"来转义，以" \%"来表示真实含义的" %" 字符）
			
			函数返回被替换过后的字符串。
			
			$(patsubst %.c,%.o,x.c.c bar.c)
				把字串" x.c.c bar.c" 符合模式[%.c]的单词替换成[%.o]， 返回结果是" x.c.o bar.o"
		}
		
		$(strip <string>){//去空格函数——strip
			去掉<string>字串中开头和结尾的空字符
			
			返回被去掉空格的字符串值
			
			$(strip a b c )
			把字串" a b c " 去到开头和结尾的空格， 结果是"abc"
		}
		
		$(findstring <find>,<in>){//查找字符串函数——findstring
			在字串 <in>中查找<find>字串
			
			如果找到，那么返回<find>，否则返回空字符串。
			
			$(findstring a,a b c)
			$(findstring a,b c)
			第一个函数返回" a" 字符串， 第二个返回"" 字符串（空字符串）
		}
		
		$(filter <pattern...>,<text>){//过滤函数——filter
			以<pattern>模式过滤<text>字符串中的单词， 保留符合模式<pattern>的单词。可以有多个模式。
			
			返回符合模式<pattern>的字串
			
			sources := foo.c bar.c baz.s ugh.h
			foo: $(sources)
			cc $(filter %.c %.s,$(sources)) -o foo
			$(filter %.c %.s,$(sources))返回的值是" foo.c bar.c baz.s"
		}
		
		$(filter-out <pattern...>,<text>){//反过滤函数——filter-out
			以<pattern>模式过滤<text>字符串中的单词， 去除符合模式<pattern>的单词。可以有多个模式
			
			返回不符合模式<pattern>的字串
			
			objects=main1.o foo.o main2.o bar.o
			mains=main1.o main2.o
			$(filter-out $(mains),$(objects)) 返回值是" foo.o bar.o"。
		}
		
		$(sort <list>){//排序函数——sort
			给字符串 <list>中的单词排序（ 升序）
			
			返回排序后的字符串
			
			$(sort foo bar lose)
			返回" bar foo lose"
			sort 函数会去掉<list>中相同的单词
		}
		
		$(word <n>,<text>){//取单词函数——word。
			取字符串 <text>中第<n>个单词。（从一开始）
			
			返回字符串 <text>中第<n>个单词。如果<n>比<text>中的单词数要大，那么返回空字符串
			
			$(word 2, foo bar baz)
			返回值是" bar"。
		}
		
		$(wordlist <s>,<e>,<text>){//取单词串函数——wordlist
			从字符串 <text>中取从<s>开始到<e>的单词串。 <s>和<e>是一个数字
			
			返回字符串 <text>中从<s>到<e>的单词字串。如果<s>比<text>中的单词数要大，那么返回空字符
			串。如果<e>大于<text>的单词数，那么返回从<s>开始，到<text>结束的单词串
			
			$(wordlist 2, 3, foo bar baz)
			返回值是" bar baz"。
		}
		
		$(words <text>){//单词个数统计函数——words
			统计<text>中字符串中的单词个数
			
			返回<text>中的单词数
			
			$(words, foo bar baz)
			返回值是" 3"
		}
		
		$(firstword <text>){//首单词函数——firstword
			取字符串 <text>中的第一个单词
			
			返回字符串 <text>的第一个单词
			
			$(firstword foo bar)
			返回值是" foo"
		}
		
		$(dir <names...>){//取目录函数——dir
			从文件名序列<names>中取出目录部分。目录部分是指最后一个反斜杠（" /"） 之前的部分。如果
			没有反斜杠，那么返回" ./"
			
			返回文件名序列<names>的目录部分
			
			$(dir src/foo.c hacks)
			返回值是" src/ ./"
		}
		
		$(notdir <names...>){//取文件函数——notdir
			从文件名序列<names>中取出非目录部分。 非目录部分是指最后一个反斜杠（" /"） 之后的部分
			
			返回文件名序列<names>的非目录部分
			
			$(notdir src/foo.c hacks)
			返回值是" foo.c hacks"
		}
		
		$(suffix <names...>){//取后缀函数——suffix
			从文件名序列<names>中取出各个文件名的后缀
			
			返回文件名序列<names>的后缀序列，如果文件没有后缀，则返回空字串
			
			$(suffix src/foo.c src-1.0/bar.c hacks)
			返回值是" .c .c"
		}
		
		$(basename <names...>){//取前缀函数——basename
			从文件名序列<names>中取出各个文件名的前缀部分
			
			返回文件名序列<names>的前缀序列，如果文件没有前缀，则返回空字串
			
			$(basename src/foo.c src-1.0/bar.c hacks)
			返回值是" src/foo src-1.0/bar hacks"
		}
		
		$(addsuffix <suffix>,<names...>){//加后缀函数——addsuffix
			把后缀<suffix>加到<names>中的每个单词后面。
		
			返回加过后缀的文件名序列。

			$(addsuffix .c,foo bar)
			返回值是" foo.c bar.c"。
		}
		
		$(addprefix <prefix>,<names...>){//加前缀函数——addprefix
			把前缀<prefix>加到<names>中的每个单词后面。

			返回加过前缀的文件名序列。

			$(addprefix src/,foo bar)
			返回值是" src/foo src/bar"。
		}
		
		$(join <list1>,<list2>){//连接函数——join
			把<list2>中的单词对应地加到<list1>的单词后面。如果<list1>的单词个数要比<list2>的多，那么，
			<list1>中的多出来的单词将保持原样。如果<list2>的单词个数要比<list1>多，那么， <list2>多出
			来的单词将被复制到<list2>中。
			
			返回连接过后的字符串。
			
			$(join aaa bbb , 111 222 333)
			返回值是" aaa111 bbb222 333"。
		}
		
		
		
		
	}
	
	指定目标{
		一般来说， make 的最终目标是 makefile 中的第一个目标，而其它目标一般是由这个目标连带出来的。
		任何在 makefile 中的目标都可以被指定成终极目标，但是除了以"-"打头，或是包含了 "="的目标，因
		为有这些字符的目标，会被解析成命令行参数或是变量。
		
		.PHONY: all
		all: prog1 prog2 prog3 prog4
		从这个例子中，我们可以看到，这个 makefile 中有四个需要编译的程序——"prog1"，  "prog2"，  "prog3"
		和 "prog4"，我们可以使用"make all"命令来编译所有的目标（如果把 all 置成第一个目标，那么只需执行
		"make"）， 我们也可以使用"make prog2"来单独编译目标"prog2"。
		
		 "all" 
		这个伪目标是所有目标的目标，其功能一般是编译所有的目标。
		 "clean" 
		这个伪目标功能是删除所有被 make 创建的文件。
		 "install" 
		这个伪目标功能是安装已编译好的程序，其实就是把目标执行文件拷贝到指定的目标中去。
		 "print" 
		这个伪目标的功能是例出改变过的源文件。
		 "tar" 
		这个伪目标功能是把源程序打包备份。也就是一个 tar 文件。
		 "dist" 
		这个伪目标功能是创建一个压缩文件，一般是把 tar 文件压成 Z 文件。或是 gz 文件。
		 "TAGS" 
		这个伪目标功能是更新所有的目标，以备完整地重编译使用。
		 """checkcheck""""和和和"""tttestestestest"""
		这两个伪目标一般用来测试 makefile 的流程。
	}
	
	关于命令的变量{
		AR
			函数库打包程序。默认命令是“ ar”。 
		AS
			汇编语言编译程序。默认命令是“ as”。
		CC
			C 语言编译程序。默认命令是“ cc”。
		CXX
			C++语言编译程序。默认命令是“ g++”。
		CO
			从 RCS 文件中扩展文件程序。默认命令是“ co”。
		CPP
			C 程序的预处理器（输出是标准输出设备）。 默认命令是“ $(CC) – E”。
		FC
			Fortran 和 Ratfor 的编译器和预处理程序。默认命令是“ f77”。
		GET
			从 SCCS 文件中扩展文件的程序。默认命令是“ get”。 
		LEX
			Lex 方法分析器程序（ 针对于 C 或 Ratfor）。 默认命令是“ lex”。
		PC
			Pascal 语言编译程序。默认命令是“ pc”。
		YACC
			Yacc 文法分析器（ 针对于 C 程序）。 默认命令是“ yacc”。
		YACCR
			Yacc 文法分析器（ 针对于 Ratfor 程序）。 默认命令是“ yacc – r”。
		MAKEINFO
			转换 Texinfo 源文件（ .texi）到 Info 文件程序。默认命令是“ makeinfo”。
		TEX
			从 TeX 源文件创建 TeX DVI 文件的程序。默认命令是“ tex”。
		TEXI2DVI
			从 Texinfo 源文件创建军 TeX DVI 文件的程序。默认命令是“texi2dvi”。
		WEAVE
			转换 Web 到 TeX 的程序。默认命令是“ weave”。
		CWEAVE
			转换 C Web 到 TeX 的程序。默认命令是“ cweave”。
		TANGLE
			转换 Web 到 Pascal 语言的程序。默认命令是“ tangle”。
		CTANGLE
			转换 C Web 到 C。默认命令是“ ctangle”。
		RMRMRM
			删除文件命令。默认命令是“ rm – f”。
	}
	
	自动化变量{
		$@
			表示规则中的目标文件集。在模式规则中，如果有多个目标，那么， "$@"就是匹配于目标中模式定义
			的集合。
		$%
			仅当目标是函数库文件中，表示规则中的目标成员名。列如，如果一个目标是"foo.a(bar.o)",那么，
				"$%"就是"bar.o","$@"就是"foo.a"。如果目标是不是函数库文件，那么，其值为空。
		$<
			依赖目标中的第一个目标名字。如果依赖目标是以模式（即"%"）定义的，那么"$<"将是符合模式的
			一系列的文件集。 注意，其是一个一个取出来的。
		$?
			所有比目标新的依赖目标的集合。以空格分隔。
		$^
			所有的依赖目标的集合。以空格分隔。如果在依赖目标中有多个重复的，那个这个变量会去除重复的
			依赖目标，只保留一份。
		$+
			这个变量很像"$^"，也是所有依赖目标的集合。只是它不去除重复的依赖目标。
		$(@D)
			表示"$@"的目录部分(不以斜杠作为结尾)，如果"$@"只是"dir/foo.o"，那么"$(@D)"就是"dir",而如果
				"$@"中没有包含斜杠的话,其值就是"."(当前目录)。
		$(@F)
			表示"$@"的文件部分，如果"$@"值是"dir/foo.o"那么"$(@F)"就是"foo.o"，"$(@F)"相当于函数"$(notdir$@)"
		"$(%D)"
		"$(%F)"
			分别表示了函数包文件成员的目录部分和文件部分。这对也形同"archive(member)"兴中的目标中的
				"member"中国包含了不同的目录很有用。
		"$(<D)"
		"$(<F)"
			分别表示依赖文件的目录部分和文件部分。
		"$(^D)"
		"$(^F)"
			分别表示所有依赖文件的目录的部分和文件部分(无相同的)
		"$(+D)"
		"$(+F)"
			分别表示所有依赖文件的目录的部分和文件部分(可以有相同的)
		"$(?D)"
		"$(?F)"
			分别表示被更行的文件的目录的部分和文件部分
	}
	
	{-c -C
		-c 小写，表示只编译，不链接
		-C 大写，切换到指定目录再执行 make 过程，makefile 在这个指定目录里面 
	}
	 //"CFLAGS"环境变量，
	//注释符"#"的这种特性值得我们注意，
	
	{wildcard 扩展通配符
		我们可以使用“$(wildcard *.c)”来获取工作目录下的所有的.c文件列表。
	}
	
	{notdir ： 去除路径
	
	}
	
	{patsubst ：替换通配符
		
	}
	
	{wildcard notdir patsubst的用法和列子
				示例1：
		建立一个测试目录，在测试目录下建立一个名为sub的子目录。
		$ mkdir test
		$ cd test
		$ mkdir sub

		在test下，建立a.c和b.c共2个文件；在sub目录下，建立sa.c和sb.c共2 个文件。

		建立一个简单的Makefile
		src=$(wildcard *.c ./sub/*.c)
		dir=$(notdir $(src))
		obj=$(patsubst %.c,%.o,$(dir) )

		all:
		 @echo $(src)
		 @echo $(dir)
		 @echo $(obj)
		 @echo "end"
		 
		执行结果分析：
		第一行输出：
		a.c b.c ./sub/sa.c ./sub/sb.c

		wildcard把 指定目录 ./ 和 ./sub/ 下的所有后缀是c的文件全部展开。

		第二行输出：
		a.c b.c sa.c sb.c
		notdir把“展开的文件”去除掉“路径信息”

		第三行输出：
		a.o b.o sa.o sb.o
		//*/
	}
	
	{:= ?= += =的区别
		= 是最基本的赋值
		:= 是覆盖之前的值
		?= 是如果没有被赋值过就赋予等号后面的值
		+= 是添加等号后面的值
	}
}

{工程列子
	######################################
	#
	#
	######################################
	  
	#target you can change test to what you want
	#共享库文件名，lib*.so
	TARGET  := libexpress.so
	  
	#compile and lib parameter
	#编译参数
	CC      := gcc
	LIBS    := -lpthread -lssl -lcrypto 
	LDFLAGS :=
	DEFINES :=
	INCLUDE := -I. -I /usr/local/include/curl -I /usr/local/ssl/include -I/usr/local/openssl/include
	CFLAGS  := -DWITH_OPENSSL -g -Wall -O3 -fPIC $(DEFINES) $(INCLUDE) 	###GCC 就会用这个
	CXXFLAGS:= $(CFLAGS) -DHAVE_CONFIG_H								###G++ 就会用这个
	SHARE   :=  -shared -o
	  
	#source file
	#源文件，自动找所有.c和.cpp文件，并将目标定义为同名.o文件
	SOURCE  := $(wildcard *.c) $(wildcard *.cpp) $(wildcard ./tinyxml/*.cpp) ### wildcard *.cpp 当前文件夹下所有的cpp文件，
	OBJS    := $(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(SOURCE)))				###patsubst %.cpp,%.o,$(SOURCE) 将SOURCE变量的所有cpp文件替换成.o文件 
	  
	.PHONY : everything objs clean veryclean rebuild
	  
	everything : $(TARGET)
	  
	all : $(TARGET)

	rebuild: veryclean everything
					
	clean :
		rm -fr *.o
		
	veryclean : clean
		rm -fr $(TARGET)
	  
	$(TARGET) : $(OBJS)
		$(CC) $(CXXFLAGS) $(SHARE) $@ $(OBJS) $(LDFLAGS) $(LIBS) 	###makefile会自动推到，.o文件的编译也是用这个命令 有点疑惑的地方，如果是cpp文件CC就是G++，如果是c文件CC就是gcc
																	###动态库也编译也是这样
}