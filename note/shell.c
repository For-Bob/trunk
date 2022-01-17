shell{shell中的赋值不能加在等式两边加空格
参考：《Linux Shell 实例精解》
	xxx.sh
	#!/bin/sh
	
	{在文件夹下的文件里找内容，
		find ./ -type f -name "*.*" | xargs grep "wsa_raw"

	}
	
	* 匹配文件名中的任何字符，包括字符串；
	？ 匹配文件名中的任何单个字符。
	~ 代表使用者的 home 目录
	
	{正规表达式的元字符集
		元字符 		功能 					例子				匹配什么 
		^ 			锚定行的开始 			/^love/ 			匹配所有以love 开头的行 
		$ 			锚定行的结束 			/love$/ 			匹配所有以love 结束的行 
		. 			匹配一个字符 			/l..e/ 				匹配所有这样的行，这些行包含这样的字符：
																第一个字符是l，紧跟着两个字符，然后是e 
		* 			代表0 个或者多个先前字 	/*love/				匹配所有这样的行，有0 个或者多个空格，*/
					符 											空格后跟着love 
		[] 			匹配字符组中的一个字符 	/[Ll]ove/ 			匹配所有包含love 或者 Love 的行 
		[x-y] 		匹配以字符范围组成的组						/[A-Z]ove/ 匹配所有这样的行，这些行包含如下的字符，
					中的一个字符 								第一个字符是从A 到Z 中间的一个，后面跟着ove
		[^] 		匹配一个不在范围内的字	/[^A-Z]ove/ 		匹配所有这样的行，这些行包含如下的字符，
					符 											第一个字符不是从A 到Z 中间的一个，后面
																跟着ove
		\ 			用来转义一个元字符 		/love\./ 			匹配所有这样的行，这些行包含如下的字符：
																love 后面跟着一个点。通常点是表示任何字
																符的通配符 
		许多使用RE 元字符集的UNIX 程序都支持附加元字符集。 
		\< 			锚定单词的开始 			/\<love/ 			匹配所有这样的行，这些行包含以love 开头
																的单词（vi 和grep 支持这个功能） 
		\> 			锚定单词的结束 			/love\>/ 			匹配所有这样的行，这些行包含以love 结束
																的单词（vi 和grep 支持这个功能） 
		\(..\) 		标记后面用到的匹配		/\(love\)able\1rs/ 	最多可以使用9 个标签。第一个标签是模板
					字符（传） 									最左边的部分。在本例子中，模板love 保存
																为标签1，后面的\1 指的就是Love；本例子
																搜索的是这样的行，这些行包含这样的字符，
																在Loveable 后面跟着lovers 
		x\{m\}or 	m 次复制字符x			o\{5,10\} 			匹配所有这样的行，包含的o 的数量在5 到
		x\{m,\}or 	至少m 次复制字符x 							10 个之间。（vi 和grep 支持这个功能）
		x\{m,n\} 	至少m 次复制字符x 
					复制字xa
	}
	:1,$s/\([0o]ccur\)ence/\1rence/  //vi模式下输入
	//1:$s第一行到最后一行，编辑器寻找字符串Occurence 或者occurence
	//因为这是在第一个模板中标
	//记的，因此称为tag1。这个模板被保存到内存存储器中，叫作寄存器1。先把\1 用1 中的内容替
	//换，再把单词的其他部分（在本例中是rence）附加到它的后面。
	//后面的1代表前面的[0o]ccur
	
	{常用命令和特殊字符 比如grep
		xargs	//相当于并的意思
		比如
			find ./ -name "wifi-ui-app" |xargs ls -l //找到wifi-ui-app并ls看一下
			
		{正则表达式
			{1.使用句点匹配单字符"."
				ls -l |grep ..x..x..x	//就会出现像下面，匹配符合要求的文件
				drwxr-xr-x 2 vepal users    4096 Aug 24 17:04 apwiz
				d--x--x--x 2 vepal users    4096 Sep  8 14:57 channelview
				dr-xr-xr-x 2 vepal users    4096 Aug 22 09:13 clientscan
				drwxr-xr-x 4 vepal users    4096 Aug 24 18:06 cmake_tmp
				drwxr-xr-x 4 vepal users    4096 Feb  1  2016 contrib
			}
			
			{2.^只允许在一行的开始匹配字符或单词
				svn status |grep ^M		//查看svn状态的以M开头的文件
				M       wsa/include/signature.h
				M       wsa/include/wsa.h
				M       wsa/source/signature.cpp
			}
			
			{3.可以说$与^正相反
				ls -l |grep wiz&	//查看以wiz结尾的文件
				drwxr-xr-x 2 vepal users    4096 Aug 24 17:04 apwiz
				drwxr-xr-x 5 vepal users    4096 Jun 24 15:10 wifiwiz-develop
			}
			
			{4.*
				比如compu*te	//匹配u一次或多次
					compute，compuute，compuuute
			}
			
			{5.[]	//使用[ ]匹配特定字符串或字符串集，
				-	//从...到...
				比如 svn status|grep ^[A-M]	//查看svn状态的以A到M开头的文件
				比如 svn status|grep ^[AM]	//查看svn状态的以A或者M开头的文件
			}			
			
			{6.\{\}	//使用\{\}匹配模式结果出现的次数
				A \ { 2 \ } B
				匹配值为A A B
				匹配A至少4次，使用：
				A \ { 4 , \ } B
				可以得结果A A A A B或A A A A A A A B，但不能为A A A B。
				如给出出现次数范围，例如 A出现2次到4次之间：
				A \ { 2 , 4 \ } B
				则结果为A A B、 A A A B、 A A A A B，而不是A B或A A A A A B等
			}
			
			{经常使用的正则表达式举例
				^ 							对行首
				$ 							对行尾
				^[the] 						对以the开头行
				[Ss]igna[lL] 				对匹配单词signal、signaL、Signal、SignaL
				[Ss]igna[lL]\. 				对同上，但加一句点
				[mayMAY]					对包含may大写或小写字母的行
				^USER$						对只包含USER的行
				[tty]$ 						对以tty结尾的行
				\. 							对带句点的行
				^d..x..x..x			 		对用户、用户组及其他用户、组成员有可执行权限的目录
				^[^l]						对排除关联目录的目录列表
				[.*0]						对0之前或之后加任意字符
				[000*]						对000或更多个
				[iI]						对大写或小写I
				[iI][nN]					对大写或小写i或n
				[^$]						对空行
				[^.*$]						对匹配行中任意字符串
				^......$					对包括6个字符的行
				[a-zA-Z]					对任意单字符
				[a-z][a-z]*					对至少一个小写字母
				[^0-9\$]					对非数字或美元标识
				[^0-9A-Za-z]				对非数字或字母
				[123]						对1到3中一个数字
				[Dd]evice					对单词device或Device、De..ce对前两个字母为De，后跟两个任意字符，最后为ce
				\^q							对以^q开始行
				^.$							对仅有一个字符的行
				^\.[0-9][0-9]				对以一个句点和两个数字开始的行
				'"Device"'					对单词device
				De[Vv]ice\.					对单词Device或device
				[0-9]\{2\}-[0-9]\{2\}-[0-9]\{4\}	 对日期格式d d - m m - y y y y
				[0-9]\{3\}\.[0-9]\{3\}\.[0-9]\{3\}\.[0-9]\{3\}	对I P地址格式nnn. nnn.nnn.nnn
				[^.*$]						对匹配任意行
				$<							表示所有的依赖目标集
				$@							表示目标集
				{$<	$@	
					objects = foo.o bar.o 
					all: $(objects)
				 
					$(objects): %.o: %.c
						   $(CC) -c $(CFLAGS) $< -o $@
				 
					上面的例子中，指明了我们的目标从$object中获取，“%.o”表明要所有以“.o”结尾的目标，也就是“foo.o bar.o”，也就是变量$object集合的模式，而依赖模式“%.c”则取模式“%.o”的“%”，
					也就是“foobar”，并为其加下“.c”的后缀，于是，我们的依赖目标就是“foo.cbar.c”。而命令中的“$<”和“$@”则是自动化变量，“$<”表示所有的依赖目标集（也就是“foo.c bar.c”），
					“$@”表示目标集（也就是foo.o bar.o”）。
				}
			}
		}
		
		{grep	（全局正则表达式版本）允许对文本文件进行模式查找。
			grep "drawGrid" *.cpp	//比如查找当前文件夹下所有cpp文件里面的drawGrid
			
			{正则表达式
				元字符 	功能 					例子 				匹配什么 
				^ 		锚定行的开始 			^love 				匹配所有以love 开头的行 
				$ 		锚定行的结束 			love$ 				匹配所有以love 结束的行 
				. 		匹配一个字符 			l..e 				匹配所有这样的行，这些行包含这样的字符，第
																	一个字符是l，紧跟着两个字符，然后是e 
				* 		代表0个或者多个先前		*love 				匹配所有这样的行，有0 个或者多个空格，空格
						字符 										后跟着love
				[] 		匹配字符组中的一个字 	[Ll]ove 			匹配所有包含love 或者 Love 的行 
						符 
				[^] 	匹配一个不在范围内的	[^A-Z]ove 			匹配所有这样的行，这些行包含如下的字符，第一
						字符										个字符不是从A～Z 中间的一个，后面跟着ove
				/<a 	锚定单词的开始 			\<love 				匹配所有这样的行，这些行包含以love 开头的
																	单词（vi 和grep 支持这个功能）
				\> 		锚定单词的结束 			love\> 				匹配所有这样的行，这些行包含以love 结束的
																	单词（vi 和grep 支持这个功能）
				\(..\)b 标记后面用到的匹配字	\(love\)able 		最多可以使用9 个标签。第一个标签是模板最左
						符											边的部分。在本例子中，模板love 保存为标签1，
																	后面的\1 指的就是Love；本例子搜索的是这样
																	的行，这些行包含这样的字符，在Loveable 后
																	面跟着lovers 
				x\{m\} 		m 次复制字符x		o\{5,10\} 			匹配所有这样的行，包含的 o 的数量在5～10
				x\{m,\} 	至少m 次复制字符x	o\{5,\} 			个之间。（vi 和grep 支持这个功能） 
				x\{m,n\}c 	至少m 次。至多n 次复	o\{5,10\} 
							制字符x
				\w 		文字和数字字符，		L\w*e				匹配一个l 字符，紧跟着0 个或者多个文字或数
						[A-Za-z0-9] 								字字符，然后是e 
				\W 		同上 					love\W+ 			匹配love 后面是一个或者多个非单词字符，如																	点号或者问号 
				\b 		单词分界线 				\blove\b 			仅仅匹配单词love 
			}
			{常用的grep选项有：
				-a 不要忽略二进制数据。
				-A<显示列数> 除了显示符合范本样式的那一行之外，并显示该行之后的内容。
				-b 在显示符合范本样式的那一行之外，并显示该行之前的内容。
				-c 计算符合范本样式的列数。
				-C<显示列数>或-<显示列数>  除了显示符合范本样式的那一列之外，并显示该列之前后的内容。
				-d<进行动作> 当指定要查找的是目录而非文件时，必须使用这项参数，否则grep命令将回报信息并停止动作。
				-e<范本样式> 指定字符串作为查找文件内容的范本样式。
				-E 将范本样式为延伸的普通表示法来使用，意味着使用能使用扩展正则表达式。
				-f<范本文件> 指定范本文件，其内容有一个或多个范本样式，让grep查找符合范本条件的文件内容，格式为每一列的范本样式。
				-F 将范本样式视为固定字符串的列表。
				-G 将范本样式视为普通的表示法来使用。
				-h 在显示符合范本样式的那一列之前，不标示该列所属的文件名称。
				-H 在显示符合范本样式的那一列之前，标示该列的文件名称。
				-i 忽略字符大小写的差别。
				-l 列出文件内容符合指定的范本样式的文件名称。
				-L 列出文件内容不符合指定的范本样式的文件名称。
				-n 在显示符合范本样式的那一列之前，标示出该列的编号。
				-q 不显示任何信息。
				-R/-r 此参数的效果和指定“-d recurse”参数相同。
				-s 不显示错误信息。
				-v 反转查找。
				-w 只显示全字符合的列。
				-x 只显示全列符合的列。
				-y 此参数效果跟“-i”相同。
				-o 只输出文件中匹配到的部分
			}
			
			{被括弧括起来的字符类 
				被括弧括起来的类（Bracketed Class） 含义 
				[:alnum:] 							文字数字字符 
				[:alpha:] 							文字字符 
				[:digit:] 							数字字符 
				[:graph:] 							非空字符（非空格、控制字符） 
				[:lower:] 							小写字符 
				[:cntrl:] 							控制字符 
				[:print:] 							跟非空字符一样，但是包括空格 
				[:punct:]							标点符号 
				[:space:] 							所有白空格字符（新行、空格、制表符） 
				[:upper:] 							大写字符 
				[:xdigit:] 							十六进制数字（0-9、a-f、A-F）
				
				1   % grep '[[:space:]]\.[[:digit:]][[:space:]]' datafile 
					southwest   SW    Lewis Dalsass       2.7     .8   2     18 
					southeast   SE    Patricia Hemenway  4.0     .7   4     15 
				 
				2   % grep –E '[[:space:]]\.[[:digit:]][[:space:]]' datafile 
					southwest   SW    Lewis Dalsass       2.7     .8   2    18 
					southeast   SE    Patricia Hemenway  4.0     .7   4    15 
				 
				3   % egrep '[[:space:]]\.[[:digit:]][[:space:]]' datafile 
					southwest   SW  Lewis Dalsass       2.7      .8    2   18 
					southeast SE Patricia Hemenway 4.0 .7 4 15 
				//1，2，3 对于Linux 下的各种grep（除了fgrep）都支持POSIX 括号括起来的类集。在上面的各
				//个例子中，grep 都将搜索一个空格、逗号、数字[0-9]和另外一个空格字符。				
			}
			
			{例子
				% grep '\.[0-9]\{2\}[^0-9]' datafile 
				northwest NW Charles Main 3.0 .98 3 34 
				western WE Sharon Gray 5.3 .97 5 23
				扩展元字符{}用来表示重复。除非在前面加上反斜杠，否则Gnu 和UNIX 版本的正规grep 无法
				识别这个扩展元字符。该正则表达式的意思是：搜索这样的行，该行包含这样的字符串，第一个
				字符是一个点号\.，紧跟着一个0～9 之间的数字[0-9]，如果该字符串重复两次\{2\}，则后面就是
				一个非数字的字符[^0-9]。 
			}
			
			{在两个文件中搜索内容
				grep TB Savage datafile 
				grep: Savage: No such file or directory 
				datafile:eastern   EA   TB Savage        4.4   .84    5   20 
				因为第一个参数是模板，其他的参数是文件名，所以grep 将在文件Savage 和datafile 中搜索TB
			}
			
			{在文件中搜索两个字符一空格一字符
				grep '[A-Z][A-Z] [A-Z]' datafile 
				eastern EA TB Savage 4.4 .84 5 20 
				northeast NE AM Main Jr. 5.1 .94 3 13 
				 
				说明 
				打印所有包含前两个字符是大写字母，后面紧跟着一个空格及一个大写字母的字符串的行。例
				如，TB Savage 和AM Main。 
			}
			
			{选项 功能 
				-b 在搜索到的行的前面打印该行所在的块号码。该功能在通过内容定位块的
				号码时非常有用 
				-c 只显示有多少行匹配，而不具体显示匹配的行 
				-h 不显示文件名 
				-i 在字符串比较的时候忽略大小写 
				-l 只显示包含匹配模板的行的文件名清单，不同项目之间用换行符分隔 
				-n 在每一行前面打印该行在文件中的行数 
				-s 静默工作，除非出现错误信息，否则不打印任何信息，这个功能在检测退
				出状态的时候有用 
				-v 反检索，只显示不匹配的行 
				-w 如果被\<和\>引用，就把表达式做为一个单词搜索只在grep 中有效（不是
				所有版本的grep 都支持该特性，SCO UNIX 的grep 就不支持） 
			}
			
			{表3.7 所有Gnu 版本都可以使用的grep 的选项（-G、-E 和-F） 
				选项 					功能 
				-# 						表示同时显示匹配行上下的#行，例如：grep -2 pattern filename 表示同时
										显示匹配行上下各两行 
				-A#,--after-context=# 	在匹配指定的内容的行打印完毕后，再打印一行#号 
				-B#,--before-context=# 	在匹配模板的行的前面打印1 行#号 
				-C,--context 			相当于选项-2，在匹配行的前后各打印2 行空行 
				-V,--version 			显示包括bug 报告在内的版本信息 
				-b,--byte-offset 		在每一行前面打印字符偏移量 
				-c,--count 				打印每个文件匹配行的个数 
				-e PATTERN,--regexp=PATTERN 使用PATTERN 的字面意义作为模板，在模板以“-”开头的时候非
										常有用 
				-f FILE,--file=FILE 	从FILE 中提取模板。空文件中包含0 个模板，所以什么也不匹配 
				-h,--no-filename 		当多个文件匹配时候，不显示匹配文件名前缀 
				-i,--ignore-case 		在模板和输入文件中都忽略大小写差别 
				-L,--files-without-match 打印不匹配模板的文件名清单 
				-l,-- files-with-matches 打印匹配模板的文件名清单 
				-n,--line-number 		在匹配的行前面打印行号 
				-q,--quiet 				取消标准输出，跟-n 功能是一样的 
				-s,--silent 			不显示关于不存在或者无法读文件的错误信息 
				-v,--revert-match 		打印不匹配模板的行 
				-w,--word-regexp 		只打印以单词形式匹配模板的行，模板可以是包含数字、字符和下
										划线的字符串 
				-x,--line-regexp 		只打印整行匹配的行 
				-y 						用法同-i 
				-U,--binary 			把文件作为二进制文件，这个选项只在MS-DOS 和MS-Windows
										中被支持 
				-u,--unix-byte-offsets 	按照UNIX 风格报告字符偏移量。只在-b 选项同时被使用的时候才
										有效。这个选项只在MS-DOS 和MS-Windows 中被支持
			}
			
			{标准grep 回顾 
				命令 						功能 
				grep '\<Tom\>' file 		打印包含单词Tom 的行 
				grep 'Tom savage' 			file 打印包含Tom savage 的行 
				grep '^Tommy' 				file 打印以Tommy 开头的行 
				grep '\.bak$' 				file 打印以\.bak 结束的行，单引号保护美元符号（$）不作为模板的一部分 
				grep '[Pp]yramid' * 		打印当前目录下所有文件中包含Pyramid 或者pyramid 的行 
				grep '[A-Z]' file 			打印包含至少一个大写字母的行 
				grep '[0-9]' file 			打印包含至少一个数字的行 
				grep '[A-Z]…[0-9]' file 	打印包含5 个字符，并以一个大写字符开头，及一个数字结束的字符串的行 
				grep -w '[tT]est' file 		打印包含单词Test 或者test 的行 
				grep -s "Mark Todd" file 	寻找包含Mark Todd 的行，但是不打印行，而是用来检查退出状态值 
				grep -v 'Marry' file 		打印所有不包含Marry 的行 
				grep -i 'sam' file 			打印所有包含sam 的行，而不考虑大小写（如，SAM、sam、SaM、sAm）
				grep -l 'Dear Boss' * 		打印包含Dear Boss 的文件的文件名清单 
				grep -n 'Tom' file 			在打印的匹配行前追加行号 
				grep "$name" file 			把变量$name 的值作为模板，在文件中寻找匹配模板的行。注意，必须使
											用双引号 
				grep '$5' file 				打印包含$5 的行，必须使用单引号 
				ps -ef|grep " ^ *user1" 	命令ps -ef 的结果通过管道传递给grep，grep 打印其中以user1 开头（在
											user1 前有0 个或者多个空格也可以）的行
			}
			
			% grep –l 'ss'  * 
			datafile 
			datebook 
			说明 选项-l 使得grep 只打印匹配的文件名，而不打印匹配的行。
			
			在所有文件中查询单词“sort it”
			grep "sort it" *
				
			grep -c "48"	data.f
				4	//grep返回数字4，意义是有4行包含字符串“48”。
				
			grep '48'	myfile	//在文件中查找包含48，比如483,4895
			
			精确查找
				grep '48\>'	myfile	//在文件中查找48，
			
			缺省情况下，grep是大小写敏感的，如要查询大小写不敏感字符串，必须使用-i开关。
				grep -i "sept" myfile
			
			模式范围
				grep '48[34]' myfile	//假定要查找内容为484和483，
				
			不匹配行首
				grep '^[^48]' myfile	//其行首不是48，可以在方括号中使用 ^记号，表明查询在行首开始
				
			匹配任意字符
				grep 'L...D' myfile	//如果抽取以L开头，以D结尾的所有代码,已知代码长度为 5个字符
				grep '[A-Z][A-Z]..C' myfile	//头两个是大写字母，中间两个任意，并以 C结尾：
			
			日期查询
				grep '5..199[6,8]' myfile		//先查询所有以5开始中间两个任意以1996或1998结尾的所有记录
				
			范围组合
				grep '[0-9][0-5][0-6]' myfile		//第一个字符为任意数字，第二个数字在0到5之间，第三个数字在0到6之间，
			
			模式出现机率
				grep '4\{2,\}' myfile	//抽取包含数字4至少重复出现两次的所有行
				grep '9\{3,\}' myfile	//抽取记录使之包含数字999
				grep '8\{2,6}3'	myfile//匹配数字8重复出现2到6次，并以3结尾：
				
			与，或
				grep命令加-E参数
				grep -E '216|219' myfile	//查找219或者216
				
			空行
				grep '^$' myfile
				
			匹配特殊字符
				查询有特殊含义的字符，诸如$ . ' " * [] ^ | \ + ? ,必须在特定字符前加\。假设要查询包含“ .”的所有行，脚本如下：
				grep '\.' myfile
				或者是一个双引号：
				grep '\"' myfile
				以同样的方式，如要查询文件名conftroll.conf（这是一个配置文件），脚本如下：
				grep 'conftroll\.conf' myfile
				
			查询格式化文件名
				grep '^[a-z]\{1,6}\.^[A-Z]\{1,2}' myfile	//在file文件中查找以小写字母开头1个到6个之间“.”以大写字母开头1个到2个之间
				
			{类名
				类 					等价的正则表达式 	类				等价的正则表达式
				[[:upper:]]			[ A - Z ]			[[:alnum:]]		[ 0 - 9 a - zA-Z]
				[[:lower:]]			[ a - z ] 			[[:space:]]		空格或t a b键
				[[:digit:]]			[ 0 - 9 ] 			[[:alpha:]]		[ a - z A - Z ]
			}
			
			{使用通配符*的匹配模式
				grep 'l.*s'	myfile	//l开头，（.是任意，.*就是任意而且个数不定）s结尾
					looks
					likes
					
				grep 'l.*k.' myfile	//l开头，中间任意，+k，结尾任意
					looks
					likes
			}
			
		}
		
		file 	myfile//确定file的文件类型
		
		cp 		- i：在覆盖文件之前提示用户，由用户确认。
				- p：保留权限模式和更改时间。
				- r：拷贝相应的目录及其子目录。
		
		diff	格式：
				diff options file1 file2
				选项：
				- c：按照标准格式输出 (见下面的例子)。
				- I：忽略大小写
				diff命令将显示两个文件中不一致的行。
				
		dircmp	格式：
				dircmp options directory1 directory2
				-s：不显示相同的文件。
				dircmp命令与diff命令十分相似—它比较并显示两个目录中的不同。
				
		du		格式：
				du options directory
				选项：
				-a：显示每个文件的大小，不仅是整个目录所占用的空间。
				-s：只显示总计。
				后面加个h，将以K显示
				
		fuser	格式：
				fuser options file
				选项：
				- k：杀死所有访问该文件或文件系统的进程。
				- u：显示访问该文件或文件系统的所有进程。
				
		head
				格式：
				head -number files
				head命令可以显示相应文件的前number行
				
		logname
				该命令可以显示当前所使用的登录用户名：
				
		rmdir
				格式：
				rmdir options directory
				选项：
				- p：如果相应的目录为空目录，则删除该目录。
				$ rmdir /var/spool/tmp/lp_HP
				上面的命令将删除/var/spool/tmp目录下的lp_HP目录。
				
		script
				格式：
				script option file
				- a：将输出附加在文件末尾。
				可以使用script命令记录当前会话。只要在命令行键入该命令即可。该命令在你退出当前
				会话时结束。它可以将你的输入记录下来并附加到一个文件末尾。
				$ script mylogin
				将会启动script命令并将所有会话内容记录在mylogin文件中。
				
		shutdown
				格式：
				shutdown
				该命令将关闭系统。很多系统供应商都有自己特定的命令变体。
				$ shutdown now
				上面的命令将会立即关机。
				$ shutdown -g60 -I6 -y
				上面的命令将会在60秒之后关机，然后重新启动系统
		
		strings
				格式：
				strings filename
				该命令可以看二进制文件中所包含的文本。
		
		touch
				格式：
				touch options filename
				选项：
				-t MMDDhhmm 创建一个具有相应月、日、时分时间戳的文件。
				下面的命令能够以当前时间创建文件或更新已有文件的时间戳。
				touch myfile
				上面的命令以当前时间创建了一个名为myfile的文件。
				touch -t 06100930	myfile2
				上面的命令以时间戳6月10日上午9:30创建了一个名为myfile2的空文件。
		
		tty
				格式：
				t t y
				可以使用t t y来报告所连接的设备或终端。
				可以使用tty -s命令来确定脚本的标准输入。返回码为：
				0：终端。
				1：非终端。	

		uname
				格式：
				uname options
				选项：
				- a：显示所有信息。
				- s：系统名。
				- v：只显示操作系统版本或其发布日期。
				
		wc
				格式：
				wc options files 。
				选项：
				- c：显示字符数。
				- l：显示行数。
				- w：显示单词数。
		
		whereis
				格式：
				whereis command_name
				whereis命令能够给出系统命令的二进制文件及其在线手册的路径。
	}
	
	{sed
		{	命令 			功能 
			a\ 				在当前行后面加入一行或者文本 
			b label 		分支到脚本中带有标号的地方，如果标号不存在就分支到脚本的末尾 
			c\ 				用新的文本改变或者替代本行的文本 
			d 				从模板块（Pattern space）位置删除行 
			D 				删除模板块的第一行 
			i\ 				在当前行上面插入文本 
			h 				拷贝模板块的内容到内存中的缓冲区 
			H 				追加模板块的内容到内存中的缓冲区 
			g 				获得内存缓冲区的内容，并替代当前模板块中的文本 
			G 				获得内存缓冲区的内容，并追加到当前模板块文本的后面 
			l 				列表不能打印字符的清单 
			n 				读取下一个输入行，用下一个命令处理新的行而不是用第一个命令 
			N 				追加下一个输入行到模板块后面并在二者之间嵌入一个新的行，改变当前行的号码 
			p 				打印模板块的行 
			P 				打印模板块的第一行 
			q 				退出sed 
			r file 			从file 中读行 
			t label 		if 分支，从最后一行开始，条件一旦被满足或者T 命令或者t 命令，将导致分支到
								带有标号的命令处，或者到脚本的末尾 
			T label 		错误分支，从最后一行开始，一旦发生错误或者T 命令或者t 命令，将导致分支到
							带有标号的命令处，或者到脚本的末尾 
			w file 			写并追模板块到file 末尾 
			W file 			写并追模板块的第一行到file 末尾 
			! 				表示后面的命令对所有没有被选定的行发生作用 
			s/re/string/ 	用string 替换正则表达式re 
			= 				打印当前行号码 
			#command 		把注释扩展到下一个换行符以前 
			替换标记 
			g 				行内全面替换 
			p 				打印行 
			w 				把行写入一个文件 
			x 				互换模板块中的文本和缓冲区中的文本 
			y 				把一个字符翻译为另外的字符（但是不能用于正则表达式） 
		}
		
		{ sed 正则表达式元字符集 
			元字符 功能 						例子 					匹配什么 
			^ 		锚定行的开始				/^love/ 				匹配所有以love 开头的行 
			$ 		锚定行的结束 				/love$/ 				匹配所有以love 结束的行 
			. 		匹配一个非换行符的字符 		/l..e/ 					匹配所有包含l 紧随两个任意字符，然
																		后是e 的行 
			* 		匹配零或多个字符			 /*love/ 				匹配所有模板是一个或多个空格后紧  */
																		跟love 的行 
			[ ] 	匹配一个指定范围内的字符	 /[Ll]ove/ 				匹配包含Love 或love 的行 
			[^] 	匹配一个不在指定范围内的	/[^A-KM-Z]ove/ 			匹配包含模板以A～K 或M～Z 的一个
						字符 											字母开头，紧跟ove 的行
			\(..\) 	保存匹配的字符 				s/\(love\)able/\1rs/ 	标签标记出来的部分被保存在1 号标签
																			中，为了方便在后面引用，使用\|来表
																			示，\|将被标签标记出来的模板替换，
																			从表达式的最左边开始，向右最多可以
																			使用9 个标签。例如，love 被保存在寄
																			存器1 当中，并稍后用做字符串替换。
																			 loveable 就被替换为lovers 3 
			& 		保存搜索字符用来替换其他	s/love/**&**/
						字符 

			 &表示搜索字符串，所以 love 就变为
			**love** 
			\< 锚定单词的开始 /\<love/ 匹配包含以love 开头的单词的行 
				\> 锚定单词的结束 /love\>/ 匹配包含以love 结尾的单词的行 
			x\{m\} 
			x\{m,\} 
			x\{m,n\}a 

			重复字符X，M 次 
			重复字符X，至少M 次 
			重复字符X，至少M 次，不
			多于N 次 

			/o\{5\}/ 匹配包含5 个o，或至少5 个o 或5~10
			个o 的行 
		}
		{sed回归
			命令 									功能 
			sed –n ‘/sentimental/p’filex 			打印所有包含sentimental 的行到屏幕。文件filex 并没有变化。如
													果没有-n 选项，所有包含sentimental 的行都将被打印两次 
			sed ‘1,3d’ filex>newfilex 				从文件filex 中删除1、2、3 行，并把变化保存到文件newfilex 中 
			sed ‘/[Dd]aniel/d’ filex 				删除包含Daniel 或者deniel 的行 
			sed –n ’15,20p’ filex 					打印第15 行～第20 行 
			sed ‘1,10s/Montana/MT/g’ filex 			把从第1 行～第20 行范围内所有的Montana 替换为MT 
			sed ‘March/\!d’ filex(tcsh) 			删除所有不包含March 的行（tcsh 中的反斜杠用来避免跟历史字
			sed’/March/!d’ filex(sh) 				符混淆）
			sed ‘/report/s/5/8’ filex 				在所有包含report 的行中，第一个出现的5 都将被替换成8 
			sed ‘s/….//’ filex 						删除每一行的前4 个字符。也就是用空字符串替换每一行的前4
													个字符 
			sed ‘s/…$//’ filex 						删除每一行的最后3 个字符。也就是用空字符串替换每一行的最
													后3 个字符 
			sed ‘/east/,/west/s/North/South/’ filex 所有从east 到west 之间的行中的North 都被替换为Sourth 
			sed –n ‘/Time off/w timefile’ filex 	把所有包含Time off 的行写入到新文件timefile 中 
			sed ‘s/\([Oo]ccur\)ence/\lrence/’ file 	用Occurrence 或者occurrence 替换Occurrence 和occurrence 
			sed –n ‘l’ filex 						打印所有包含不能打印字符的行，这些不能打印的字符显示为
													\nn，nn 是字符的八进制值，制表符显示为> 
		}

	}
	
	{awk
		一个awk 程序包括awk 命令、程序结构、引用（或输入文件）和输入文件的名字。如
		果输入文件没有被指定，输入就来自标准输入或键盘。 
		awk 结构由模板、动作或者模板和动作联合组成。模板是由某种类型表达式的说明组成。
		如果没看见关键字if，但是你在评价表达式的时候想到了单词if，这就是模板。动作是在大
		括弧内被分号或者新的一行分隔的一个或者多个说明。模板不能够放在大括弧中，由在斜杠
		中间的正则表达式和awk 提供的操作中的一个或者几个组成。 
		awk 命令可以从命令行中输入，也可以从awk 脚本中输入。输入行可以来自文件、管道
		和标准输入。 
	}
	
	{注释一片区域
		
		:||{
		很多语句
		}	//亲自试了的，
		
		:<<!
		很多语句
		！	//没有试
		
		: '
		很多语句
		'	//没有试
		
	}
	
	{grep//匹配字符，它能使用正则表达式搜索文本，并把匹配的行打印出来。
		{常用用法
			[root@www ~]# grep [-acinv] [--color=auto] '搜寻字符串' filename	//一般不用--color，因为自己没弄对
			选项与参数：
			-a ：将 binary 文件以 text 文件的方式搜寻数据
			-c ：计算找到 '搜寻字符串' 的次数
			-i ：忽略大小写的不同，所以大小写视为相同
			-n ：顺便输出行号
			-v ：反向选择，亦即显示出没有 '搜寻字符串' 内容的那一行！
			--color=auto ：可以将找到的关键词部分加上颜色的显示喔！
		}
	}
	
	{删除除了需要的文件夹和文件之外的所有文件和文件夹
		rm -rf `ls |grep -v "file"`	//单个有效
		
	}
	
	{切换目录pushd
		在当前目录下：pushd 要切换的目录 >挂载的地方(这个可以是随便那个地方)
		列子：vepal@linux-uuvd:~/workspace> pushd mttplus/mttplus_trunk/ui/settingAbout/ >mytest/make1/null
		vepal@linux-uuvd:~/workspace/mttplus/mttplus_trunk/ui/settingAbout> pushd
		~/workspace ~/workspace/mttplus/mttplus_trunk/ui/settingAbout
		vepal@linux-uuvd:~/workspace> pushd
		~/workspace/mttplus/mttplus_trunk/ui/settingAbout ~/workspace
		就起到了目录切换的作用，
		popd就是删除
	}
	
	{shell里面的定义
		local //申明的变量，只有在当前函数有效
		declare -a //声明一个数组
		unset 	//删除变量
	}
	
	{查看文件大小
		du -sh file
	}
	
	{关于空格
		在判断时，符号之间一定要用空格
		在运算时，符号之间不要有空格
	}
	
	{向文件中写内容
		echo "内容" > file	//向文件中写内容，是覆盖
		echo "内容">> file	//向文件中写内容，是追加
	}
	
	if-then{
		if command	//如果这个命令的退出状态是0，则执行后面的
		then
			commands
		fi
		
		if command
		then 
			commands
		else
			commands
		fi
		
		if command1
		then 
			commands
		elif	command2
		then	
			commands
		fi
		//列子，一定要注意空格，
		#!/bin/sh
		#this is only for test by naypesong!
		user=naypesong
		if [ "x1" == "x2" ];
		then
				echo "$user can be printf?"
		elif [ "x1" > "x2" ];then
				echo "this is elseif"
		else
				echo "this is else"
		fi

		最精简的 if 命令的语法是：
		if TEST-COMMANDS; then CONSEQUENT-COMMANDS; fi
		
		TEST-COMMAND 执行后且它的返回状态是0，那么 CONSEQUENT-COMMANDS 就执行。返回状态是最后一个命令的退出状态，或者当没有条件是真的话为0。
		
		Primary(TEST-COMMAND) 	意义
		[ -a FILE ] 			如果 FILE 存在则为真。
		[ -b FILE ] 			如果 FILE 存在且是一个块特殊文件则为真。
		[ -c FILE ] 			如果 FILE 存在且是一个字特殊文件则为真。
		[ -d FILE ] 			如果 FILE 存在且是一个目录则为真。
		[ -e FILE ] 			如果 FILE 存在则为真。
		[ -f FILE ] 			如果 FILE 存在且是一个普通文件则为真。
		[ -g FILE ] 			如果 FILE 存在且已经设置了SGID则为真。
		[ -h FILE ] 			如果 FILE 存在且是一个符号连接则为真。
		[ -k FILE ] 			如果 FILE 存在且已经设置了粘制位则为真。
		[ -p FILE ] 			如果 FILE 存在且是一个名字管道(F如果O)则为真。
		[ -r FILE ] 			如果 FILE 存在且是可读的则为真。
		[ -s FILE ] 			如果 FILE 存在且大小不为0则为真。
		[ -t FD ] 				如果文件描述符 FD 打开且指向一个终端则为真。
		[ -u FILE ] 			如果 FILE 存在且设置了SUID (set user ID)则为真。
		[ -w FILE ] 			如果 FILE 如果 FILE 存在且是可写的则为真。
		[ -x FILE ] 			如果 FILE 存在且是可执行的则为真。
		[ -O FILE ] 			如果 FILE 存在且属有效用户ID则为真。
		[ -G FILE ] 			如果 FILE 存在且属有效用户组则为真。
		[ -L FILE ] 			如果 FILE 存在且是一个符号连接则为真。
		[ -N FILE ] 			如果 FILE 存在 and has been mod如果ied since it was last read则为真。
		[ -S FILE ] 			如果 FILE 存在且是一个套接字则为真。
		[ FILE1 -nt FILE2 ] 	如果 FILE1 has been changed more recently than FILE2, or 如果 FILE1FILE2 does not则为真。 exists and
		[ FILE1 -ot FILE2 ] 	如果 FILE1 比 FILE2 要老, 或者 FILE2 存在且 FILE1 不存在则为真。
		[ FILE1 -ef FILE2 ] 	如果 FILE1 和 FILE2 指向相同的设备和节点号则为真。
		[ -o OPTIONNAME ] 		如果 shell选项 “OPTIONNAME” 开启则为真。 
		
		[ -z STRING ] 					“STRING” 的长度为零则为真。
		[ -n STRING ] or [ STRING ] 	“STRING” 的长度为非零 non-zero则为真。
		[ STRING1 == STRING2 ] 			如果2个字符串相同。 “=” may be used instead of “==” for strict POSIX compliance则为真。
		[ STRING1 != STRING2 ] 			如果字符串不相等则为真。
		[ STRING1 < STRING2 ] 			如果 “STRING1” sorts before “STRING2” lexicographically in the current locale则为真。
		[ STRING1 > STRING2 ] 			如果 “STRING1” sorts after “STRING2” lexicographically in the current locale则为真。
		[ ARG1 OP ARG2 ] 				“OP” is one of -eq, -ne, -lt, -le, -gt or -ge. These arithmetic binary operators return true if “ARG1” is equal to, not equal to, less than, less than or equal to,
										greater than, or greater than or equal to “ARG2”, respectively. “ARG1” and “ARG2” are integers. 
	
	}

	test{条件判断一定要用[]而不是()
		if test condition
		then	
			commands
		fi
		test:数值比较，字符串比较，文件比较
		eq：是否等于
		ge：是否大于或等于
		gt：是否大于
		le：是否小于或等于
		lt：是否小于
		ne：是否不等于
		还可以坚持文件
		
		运算符						描述										示例
		文件比较运算符
		-e filename 				如果 filename 存在，则为真 				[ -e /var/log/syslog ]
		-d filename 				如果 filename 为目录，则为真 			[ -d /tmp/mydir ]
		-f filename 				如果 filename 为常规文件，则为真 		[ -f /usr/bin/grep ]
		-L filename 				如果 filename 为符号链接，则为真 		[ -L /usr/bin/grep ]
		-r filename 				如果 filename 可读，则为真 				[ -r /var/log/syslog ]
		-w filename 				如果 filename 可写，则为真 				[ -w /var/mytmp.txt ]
		-x filename 				如果 filename 可执行，则为真 			[ -L /usr/bin/grep ]
		filename1 -nt filename2 	如果 filename1 比 filename2 新，则为真 	[ /tmp/install/etc/services -nt /etc/services ]
		filename1 -ot filename2 	如果 filename1 比 filename2 旧，则为真 	[ /boot/bzImage -ot arch/i386/boot/bzImage ]
		
		字符串比较运算符 （请注意引号的使用，这是防止空格扰乱代码的好方法）
		-z string 					如果 string 长度为零，则为真 			[ -z "$myvar" ]
		-n string 					如果 string 长度非零，则为真 			[ -n "$myvar" ]
		string1 = string2 			如果 string1 与 string2 相同，则为真 	[ "$myvar" = "one two three" ]
		string1 != string2 			如果 string1 与 string2 不同，则为真 	[ "$myvar" != "one two three" ]
		
		算术比较运算符
		num1 -eq num2 	等于 	[ 3 -eq $mynum ]
		num1 -ne num2 	不等于 	[ 3 -ne $mynum ]
		num1 -lt num2 	小于 	[ 3 -lt $mynum ]
		num1 -le num2 	小于或等于 	[ 3 -le $mynum ]
		num1 -gt num2 	大于 	[ 3 -gt $mynum ]
		num1 -ge num2 	大于或等于 	[ 3 -ge $mynum ]

		
	}
	
	{mkdir新建文件夹
		mkdir folder	//建一个文件夹名字为folder
		mkdir	-p folder/folder1	//如果没有folder这个文件夹，加了-p就是一次性建了folder和folder1
	}
	tar{
		-c: 建立压缩档案
		-x：解压
		-t：查看内容
		-r：向压缩归档文件末尾追加文件
		-u：更新原压缩包中的文件
		
		-z：有gzip属性的
		-j：有bz2属性的
		-Z：有compress属性的
		-v：显示所有过程
		-O：将文件解开到标准输出
		压缩{
			tar –cvf jpg.tar *.jpg //将目录里所有jpg文件打包成tar.jpg	无压缩，只是重命名
			tar –czf jpg.tar.gz *.jpg   //将目录里所有jpg文件打包成jpg.tar后，并且将其用gzip压缩，生成一个gzip压缩过的包
			tar –cjf jpg.tar.bz2 *.jpg //将目录里所有jpg文件打包成jpg.tar后，
			tar –cZf jpg.tar.Z *.jpg   //将目录里所有jpg文件打包成jpg.tar后，
			rar a jpg.rar *.jpg //rar格式的压缩，需要先下载rar for linux
			zip jpg.zip *.jpg //zip格式的压缩，需要先下载zip for linux
		}
		解压{
			tar –xvf file.tar //解压 tar包
			tar -xzvf file.tar.gz //解压tar.gz
			tar -xjvf file.tar.bz2   //解压 tar.bz2
			tar –xZvf file.tar.Z   //解压tar.Z
			unrar e file.rar //解压rar
			unzip file.zip //解压zip
			
			tar -xvf file.tar.gz -c dir/	//解压文件到指定的文件夹下
		}
		
	}
		
	引用变量{
		#！/bin/bash
		#test variable
		days=10
		guest="katie"
		echo"$guest checked in $days days ago"
		运行脚本产生如下输出结果
		katie checked in 10 days ago
		
		变量的运算
		i=10
		j=2
		m=$[$i+$j]		//一定是[]而不是(),算数加减采用$[] 输出12
		echo $m
		
		i=ii j=jj m=mm
		m=$[$i + $j]	echo $m	//0
		m=$i+$j	echo $m			//jj+kk
		
		想要链接字符串
		m+=i m+=j echo $m		//mmiijj
		
	}	
	
	重定向输入输出{
		输出重定向{
			command>outputfile	//会重写文件里面的内容
			command>>outputfile	//追加内容
			输入：command<outputfile
			
		}
	}
	
	管道{
		有时需要将一个命令的输出发送至另一个命令的输入
		如：command1|command2
			ps -e|grep
	}
	
	大于小于等符号{
		\>:大于，依次类推
	}
	
	文件比较{test命令比较
		-d file			//检查file是否存在并且是一个目录
		-e file			//检查file是否存在
		-f file			//坚持file是否存在并且是一个文件
		-r file			//坚持file是否存在并且可读
		-s file			//检查file是否存在并且不为空
		-w file			//检查file是否存在并且可写
		-x file			//检查file是否存在并且可执行
		-o file			//检查file是否存在并且被当前用户拥有
		-G file			//检查file是否存在并且默认组是否为当前用户组
		file1 -nt file2	//检查file1是否比file2新
		file1 -ot file2	//检查file1是否比file2旧
	}
	
	for{
		for var in list
		do 
			commands
		done
		//list中提供一系列用于迭代的值，var包含列表的当前值。
		列子{
			$cat test1
			#!/bin/bash
			#basic for command
			for test in china amercia japan
			do	
				echo the next state is $test
			done
			$./test1	//执行
			the next state is china
			the next state is amercia
			the next state is japan
			
			for test in i don't know if this'll work
			do 
				echo "word:$test"
			done
			//运行
			word:i
			word:dont know if thisll
			word:work
			//shell看到列表值当中的单引号，并试图用它们来定义一个单独的数据值，的确破坏了这个过程
			解决： \ ""
			for test in i don\'t konw if "this'll"	work
			
			从变量读取列表{
				list="china amercia japan"
				list=$list"Connecticut"
				for state in $list
				do
					echo "Have you ever visited $state"
				done
				Have you ever visited china
				Have you ever visited amercia
				Have you ever visited japan
			}
			
			读取命令中的值{
			$cat test5
			#!/bin/bash
				file="stages"
				for state in 'cat $file'
				do
					echo "Visit beatiful $state"
				done
				$cat states
				beijing
				chengdu
				ziyang
				$./test5
				Visit beatiful beijing
				Visit beatiful chengdu
				Visit beatiful ziyang
			}
			
			常用的Linux中使用的一些命令行选项的常用含义{
				-a	//显示所有对象
				-c	//生成计数
				-d 	//指定目录
				-e 	//展开对象
				-f 	//指定读取数据的文件
				-h 	//显示命令的帮助信息
				-i 	//忽略大小写
				-l 	//生成长格式的输出
				-n 	//使用非交互式（批量）模式
				-o 	//指定一个输出文件来重定向输出
				-q 	//以quiet模式执行
				-r 	//递归超能力目录和文件
				-s 	//以silent模式执行
				-v 	//生成verbose输出
				-x 	//排除和拒绝
				-y 	//设置所有提问的回答为yes
			}
			
			echo{
				-n 不要在最后自动换行
				e 若字符串中出现以下字符，则特别加以处理，而不会将它当成一般
				文字输出：
				   \a 发出警告声；
				   \b 删除前一个字符；
				   \c 最后不加上换行符号；
				   \f 换行但光标仍旧停留在原来的位置；
				   \n 换行且光标移至行首；
				   \r 光标移至行首，但不换行；
				   \t 插入tab；
				   \v 与\f相同；
				   \\ 插入\字符；
				   \nnn 插入nnn（八进制）所代表的ASCII字符；
				–help 显示帮助
				–version 显示版本信息
				echo "the echo command test!">a.sh
				这个就会在a.sh文件中输出“the echo command test!”这一行文字！
			}
			
			
		}
	}
	
	cp{
		cp -R dir ./ 	//拷贝目录到当前文件夹下，连这个文件夹下的子目录一起拷贝过来
		cp -avx dir ./	//拷贝目录到当前文件夹下，所有的属性都拷贝过来
		-a	归档文件，保留其属性
		-b	为每个现有destination文件创建一个备份，而不是覆盖他
		-d	保留
		-f	强制覆盖现有destination文件，没有提示
		-i	覆盖destination文件前提示
		-l	创建文件链接而不是复制文件
		-p	保留文件属性
		-r	递归复制文件
		-R	递归复制目录
		-s	创建符号链接而不是复制文件
		-S	重写备份特性
		-u	仅在source文件的日期和时间比destination新时复制source文件
		-v	冗长模式，解释发生的事件
		-x	将复制限定在当前文件系统
	}
	
	{.mak文件
		makefile(.mak)的作用是命令行编译连接命令nmake使用的文件。它以文本的方式规定了nmake要编译那些文件，
		生成那些文件，
		要连接那些文件，生成的.exe文件的名称等，也支持增量编译。它有自己的一套语法。可参见MSDN,
		搜索make files就可以了。 
	}
	
	{默认的shell环境变量
	bash shell bourne变量
		CDPATH		冒号分隔的目录列表，用作cd命令的搜索路径
		HOME		当前用户的主目录
		IFS			用于分隔字段的字符列表，shell使用它们分隔文本字符串
		MAIL		当前用户邮箱的文件名。对于新邮件，bash shell将检查该文件
		MAILPATH	当前用户邮箱的过个文件名。由冒号分隔。对于新邮件，bash shell将检查改列表中的各个文件
		OPTARG		getopts命令车里的最后一个选项参数的值
		OPTIND		getopts命令车里的最后一个选项参数的索引值
		PATH		冒号分隔的目录列表，shell将在这些目录中查找命令
		PS1			主shell命令行界面提示字符串
		PS2			次shell命令行界面提示字符串
	bash shell环境变量
		BASH		执行当前bash shell实例的完成路径名称
		LANG		shell的地区类别
		PWD			当前中作目录
		RANDOM		返回0到32767之间的随机数
		UID			当前用户数值形式的真实用户id
		/tec/profile文件是bash shell在系统上的主默认启动文件。
	}
	
	{vi 的一些操作命令
		h 用于左移一个字符
		j 用于下移一行
		k 用于上移一行
		l 用于右移一个字符
		PageDown(或Ctl+f)用于下移一个屏幕的数据
		PageUp(或Ctl+b)用于上移一个屏幕的数据
		G 用于移动到缓冲的最后一行
		num G用于移动到缓冲中的第num行
		gg 用于移动到缓冲的第一行
		x		删除当前光标位置的字符
		dd		删除当前光标位置的行
		dw		删除当前光标位置的单词
		d$		删除当前光标位置到行末的所有内容
		J		删除当前光标位置到行末的断开线
		a		将数据附加在当前光标位置后面
		A		将数据附加在当前光标位置所在行后面
		r char	将当前光标位置的单个字符替换为char
		R text 	将当前光标位置的数据覆盖为text，直到你按esc键为止
		/		搜索
		替换命令
		:s/old/new
		:s/old/new/g	用于替换一行中的所有old
		:#,:s/old/new/g	用于替换两行中的所有old
		:%s/old/new/g	用于替换整个文件中的所有old
		:%s/old/new/gc	用于替换整个文件中的所有old，但每次替换是都会弹出提示。
	}
	
	{使用双圆括号
		val++	后增量
		val--	后减量
		++val	前增量
		--val	前减量
		！		逻辑否定
		~		逐位取反
		**		取幂
		<<		逐位左移
		>>		逐位右移
		&		逐位布尔逻辑
		|		逐位布尔逻辑或
		&&		逻辑与
		||		逻辑或
	}

	{统计文件的行数
		wc -l file					//只统计行数，这个最快
		sed '$=' file				//统计行数，而且还能显示内容
		awk 'END {print NR}' file	//只统计行数
		find ./dir -type f | xargs cat | wc -l	//统计文件夹下文件的行数
	}
	
	{``
		MYDIR=`pwd`	//$MYDIR就是当前文件夹的路径
		MYDIR=`ls`	//就是当前文件和文件夹的列表
		//统计文件夹下文件夹下的行数
		MYDIR=`pwd`
		find $MYDIR -type f | xargs cat | wc -l
	}
	
	{find
		-type 是find命令的一个参数：
		-type:查找某一类型文档
		b:块设备文档
		d:目录
		c:字符设备文档
		P:管道文档
		l:符号链接文档
		f:普通文档
	}
	
	{一行执行两句话
		echo "1" echo "2"	//输出 1 echo 2
		echo "1"; ehco "2"	//输出1 换行2
	}
	
	{\两行是一行
		gcc  \
			main.c
		
	}

	{ln
		将档案 yy 产生一个 symbolic link : zz
		ln -s yy zz
		将档案 yy 产生一个 hard link : xx
		ln yy xx
		
		短选项		长选项				含义
					--backup[=CONTROL]	为每个已存在的目标文件创建备份文件
		-b			类似--backup，但不接受任何参数
		-d			--directory			创建指向目录的硬链接(只适用于超级用户)
		-f			--force				强行删除任何已存在的目标文件
		-i			--interactive		交互模式，文件存在则提示用户是否覆盖
		-L			--logical			引用的目标是符号链接
		-n			--no-dereference	把符号链接视为一般目录
		-P			--physical			make hard links directly to symbolic links
		-r			--relative			create symbolic links relative to link location
		-s			--symbolic			软链接(符号链接)
		-S<附加字尾>--suffix=<附加字尾>	与-b参数一并使用，可指定备份文件的所要附加的字尾。
		-t			--target-directory=DIRECTORY	specify the DIRECTORY in which to create
		-T			--no-target-directory	treat LINK_NAME as a normal file always
		-v			--verbose			执行时显示详细的信息。
	}
	
	{冒号里面的冒号
		"\"\""
	}
	
	{set
		set -e # Exit the script if an error happens
		脚本A
 
		set +e # don t bail out of bash script if ccache doesn t exist
		脚本B

		set -e # back to regular 《bail out on error》 mode
		脚本C

		如上面一个 脚本 shell ，
		A  和 C 中的脚本执行的时候如果出现了返回值为非零 ，整个脚本就会立即退出 
		B 脚本中如果出现了返回值为非零将会继续执行下面的脚本 C 。
		
		选项 说明
		-a 自动向已经修改的变量或为导出后序命令的变量作出标志
		-b 不是在原提示符之前,而是立即引发终止后台任务的状态表表
		-e 如果命令带非零值返回,立即退出
		-f 禁止带扩展名的路径
		-h 定义函数时,定位和存储函数命令,当函数被执行时,通常查询函数命令
		-k 所有的关键词参数,而不只是那些命令名前的关键词参数,被放在环境命令中
		-m 监视器模式,启动任务控制.此选项默认支持系统shell交互.后台进程以单独的进程组运行,在每次完成任务时显示包含退出的状态行
		-n 读取命令但不执行命令.通常监查shell脚本的句法错误.交互shell被忽略
		-o option-name 选项名可以是下列之一:
		选项 说明
		allexport 同-a选项
		braceexpand shell执行花括号扩展,在默认情况下起作用
		emacs 使用emacs风格命令行编辑接口.除非shell以-noline-editing选项启动,否则当shell交互时,通过默认启动该选项
		errexit 同-e选项
		histexpand 同-H选项
		ignoreeof 其结果是好像shell命令IGNOREEOF=10被执行
		interactive 允许单词前带#号,以使得在交互shell中忽略命令行的全部字符-commands
		monitor 同-m选项
		noclobber 同-C选项
		noexec 同-n选项
		noglob 同-f选项
		nohash 同-d选项
		notify 同-b选项
		nounset 同-u选项
		physical 同-p选项
		posix 改变BASH属性以匹配标准,默认操作不同于POSIX1003.2标准
		verbose 同-v选项
		vi 使用vi风格的命令行编辑器
		XTRACE 同-x选项,如果没有给出选项名,显示当前选项值
		-p 打开特权模式(在此模式,$ENV文件被处理,不能从环境中继承
		shell函数.如果是有效用户ID而不是实用户组则自动启动.关闭此选项将使得有效用户和组IDs设置实用户和组IDs)
		-t 在读取命令并执行之后退出
		-u 当执行参数括展时,把非设置变量作为错误处理(如果扩展企图出现在非设置变量中,shell显示错误信息.如果不是交互式,则带非凌值退出)
		-v 输入行被读取时,显示shell输入行
		-x 在每个简单命令被扩展之后,显示PS4扩展值,之后是要执行的命令
		-l 保存和恢复绑定在命令中的名称
		-d 禁止执行查找散列命令(通常,命令被保存在散列表中,一旦被找到就不再继续查找)
		-C 效果好像是执行了noclobber=shell命令
		-H 使用!风格的历史替代(当shell交互时,在默认情况下,此选项有效)
		-P 如果设置此参数,当执行改变目录命令cd时,不遵循符号链接,而是使用实际的目录
		如果在选项后没有参数,不设置位置参数.否则,即使一些参数以a选项开始,也要把位置参数设置为argument- 结束选项的信号,将引发其余的参数被赋值到位置参数中(-x和-v选项被关闭.如果没有argument,位置参数将保留未改变的参数)
	}

	{$0,$?,$!等的特殊用法
		变量说明:
		$$
		Shell本身的PID（ProcessID）
		$!
		Shell最后运行的后台Process的PID
		$?
		最后运行的命令的结束代码（返回值）
		$-
		使用Set命令设定的Flag一览
		$*
		所有参数列表。如"$*"用「"」括起来的情况、以"$1 $2 … $n"的形式输出所有参数。
		$@
		所有参数列表。如"$@"用「"」括起来的情况、以"$1" "$2" … "$n" 的形式输出所有参数。
		$#
		添加到Shell的参数个数
		$0
		Shell本身的文件名
		$1～$n
		添加到Shell的各参数值。$1是第1参数、$2是第2参数…。
		我们先写一个简单的脚本，执行以后再解释各个变量的意义
		# touch variable
		# vi variable
		脚本内容如下：
		#!/bin/sh
		echo "number:$#"
		echo "scname:$0"
		echo "first :$1"
		echo "second:$2"
		echo "argume:$@"
		保存退出
		赋予脚本执行权限
		# chmod +x variable
		执行脚本
		# ./variable aa bb
		number:2
		scname:./variable
		first: aa
		second:bb
		argume:aa bb
		通过显示结果可以看到：
		$# 是传给脚本的参数个数
		$0 是脚本本身的名字
		$1是传递给该shell脚本的第一个参数
		$2是传递给该shell脚本的第二个参数
		$@ 是传给脚本的所有参数的列表
	}
	
}

{linux下常用命令
	suse：shift+->/<- 在多个konsole里面左右切换，也可以用alt+数字，来切换第几个konsole
}

