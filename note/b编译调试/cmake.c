参考：https://blog.csdn.net/zhuiyunzhugang/article/details/88142908
https://cmake.org/cmake/help/v3.0/manual/cmake-commands.7.html //官网

	一、Cmake 简介
		cmake 是一个跨平台、开源的构建系统。它是一个集软件构建、测试、打包于一身的软件。它使用与平台和编译器独立的配置文件来对软件编译过程进行控制。

	二、CMakeLists.txt 语法介绍
		CMakeLists.txt 的语法比较简单，由命令、注释和空格组成，其中命令是不区分大小写的。符号 # 后面的内容被认为是注释。命令由命令名称、小括号和参数组成，参数之间使用空格进行间隔。

	三、常用命令
	1. 指定 cmake 的最小版本
		cmake_minimum_required(VERSION 3.4.1)
		这行命令是可选的，我们可以不写这句话，
	2. 设置项目名称
		project(demo)
	3. add_executable生成可执行程序

		例子说明 :
		# CMake 最低版本号要求
		cmake_minimum_required (VERSION 2.8)
		# 项目信息
		project (Demo1)
		# 指定生成目标
		add_executable(Demo main.cc)

	4. aux_source_directory 
		该命令会查找指定目录下的所有源文件，然后将结果存进指定变量名。
		aux_source_directory(<dir> <variable>)
		例子说明：
			# CMake 最低版本号要求
			cmake_minimum_required (VERSION 2.8)
			# 项目信息
			project (Demo2)
			# 查找当前目录下的所有源文件
			# 并将名称保存到 DIR_SRCS 变量
			aux_source_directory(. DIR_SRCS)
			# 添加 math 子目录
			#add_subdirectory(math)
			# 指定生成目标
			add_executable(Demo ${DIR_SRCS})
			# 添加链接库
			#target_link_libraries(Demo MathFunctions)

	5. add_subdirectory
		上面的用命令 add_subdirectory 指明本项目包含一个子目录 math，这样 math 目录下的 CMakeLists.txt 文件和源代码也会被处理 
	6. target_link_libraries
		target_link_libraries 指明可执行文件 main 需要连接一个名为 MathFunctions 的链接库 。
	
	7. option	
		option(address "This is a option for address" ON)
			如果用户没有定义过address,那我address的默认值就是ON,如果用户在命令行显示改变过address的值比如为OFF,那么在脚本中address的值就是OFF。
		例子：
			if(address)
				message("defined address!!!!!!!!!!")
			else()
				message("NOT defined address!!!!!!!!!")
			endif()

			option(address "hello world" ON)
			message("option is ${address}")

			if(address)
				message("defined address!!!!!!!!!!")
			else()
				message("NOT defined address!!!!!!!!!")
			endif()

			输出结果为

			NOT defined address!!!!!!!!!!
			option is a
			defined address!!!!!!!!!!


	
	8. SET用来显式的定义变量
		SET(SRC_LIST hello.cpp add.cpp sub.cpp) 
		将 hello.cpp add.cpp sub.cpp 赋值给 SRC_LIST 变量
		CACHE
			SET(var1 13 "info" CACHE 14 "")
			如果cache存在该var1变量，使用cache中变量
			如果cache中不存在，将该13值写入var1
			SET(var1 15 ... CACHE ... FORCE)
			不论cache中是否存在，始终将15写入到var1 

	9. MESSAGE 输出打印构建目录
	例子说明 生成一个hello的工程
		# 指定工程名
		PROJECT (HELLO)
		# 现阶段，你只需要了解 SET 指令可以用来显式的定义变量即可
		# 将 hello.cpp 赋值给 SRC_LIST 变量，也可以指定多个源文件，用空格隔开
		# SET(SRC_LIST hello.cpp add.cpp sub.cpp)
		SET(SRC_LIST hello.cpp)
		# 输出打印构建目录
		MESSAGE(STATUS "This is HELLO_BINARY_DIR " ${HELLO_BINARY_DIR})
		# 输出打印资源目录
		MESSAGE(STATUS "This is HELLO_SOURCE_DIR " ${HELLO_SOURCE_DIR})
		# 输出打印资源目录，与HELLO_SOURCE_DIR 一样 
		MESSAGE(STATUS "This is PROJECT_SOURCE_DIR " ${PROJECT_SOURCE_DIR})
		# 输出打印 CMake 资源目录，与 PROJECT_SOURCE_DIR 一样 
		MESSAGE(STATUS "This is CMAKE_SOURCE_DIR " ${CMAKE_SOURCE_DIR})
		# 生成可执行文件 hello ，${SRC_LIST}是引用变量，也就是源文件 hello.cpp
		ADD_EXECUTABLE(hello ${SRC_LIST})

	生成一个libmath.so动态库，并且将其生成在 libs 目录下。
		# 指定 cmake 最低编译版本
		CMAKE_MINIMUM_REQUIRED(VERSION 3.14)
		PROJECT (MATH)
		# 把当前工程目录下的 src 目录的下的所有 .cpp 和 .c 文件赋值给 SRC_LIST
		# AUX_SOURCE_DIRECTORY(${PROJECT_SOURCE_DIR}/src SRC_LIST)
		FILE(GLOB SRC_LIST "${PROJECT_SOURCE_DIR}/src/*.cpp")
		# 打印 SRC_LIST 文件列表
		# MESSAGE(STATUS ${SRC_LIST})
		# 指定头文件目录
		INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)
		# 指定输出 .so 动态库的目录位置
		SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
		# 指定生成动态库
		ADD_LIBRARY(math SHARED ${SRC_LIST})
		# 指定生成版本号，VERSION指代动态库版本，SOVERSION指代API版本
		# SET_TARGET_PROPERTIES(math PROPERTIES VERSION 1.2 SOVERSION 1)
	10. MATCHES
		如果给定的字串或变量值域给定的正则表达式匹配的话，表达式返回真。
		IF (CMAKE_SYSTEM_NAME MATCHES "Linux")  
			MESSAGE(STATUS "current platform: Linux ")  
		ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Windows")  
			MESSAGE(STATUS "current platform: Windows")  
		ELSEIF (CMAKE_SYSTEM_NAME MATCHES "FreeBSD")  
			MESSAGE(STATUS "current platform: FreeBSD")  
		ELSE ()  
			MESSAGE(STATUS "other platform: ${CMAKE_SYSTEM_NAME}")  
		ENDIF (CMAKE_SYSTEM_NAME MATCHES "Linux")  
	11. 多个源文件
		同一目录，多个源文件
		aux_source_directory 命令，该命令会查找指定目录下的所有源文件，然后将结果存进指定变量名。
		例子：
			# CMake 最低版本号要求
			cmake_minimum_required (VERSION 2.8)
			# 项目信息
			project (Demo2)
			# 查找当前目录下的所有源文件
			# 并将名称保存到 DIR_SRCS 变量
			aux_source_directory(. DIR_SRCS)
			#添加c++11编译环境
			add_definitions(-std=c++11)
			# 指定生成目标
			add_executable(Demo ${DIR_SRCS})

		多个目录，多个源文件
			命令 add_subdirectory 指明本项目包含一个子目录
			例子：
			# CMake 最低版本号要求
			cmake_minimum_required (VERSION 2.8)
			# 项目信息
			project (Demo3)
			# 查找当前目录下的所有源文件
			# 并将名称保存到 DIR_SRCS 变量
			aux_source_directory(. DIR_SRCS)
			# 添加 math 子目录
			add_subdirectory(math)
			# 指定生成目标
			add_executable(Demo main.cc)
			# 添加链接库
			target_link_libraries(Demo MathFunctions)
	12. 生成目标 add_executable

	13. 库文件
		add_library、target_link_libraries、link_directories
		add_library
			该指令的主要作用就是将指定的源文件生成链接文件，然后添加到工程中去。
		link_directories
			该指令的作用主要是指定要链接的库文件的路径，该指令有时候不一定需要。因为find_package和find_library指令可以得到库文件的绝对路径。不过你自己写的动态库文件放在自己新建的目录下时，可以用该指令指定该目录的路径以便工程能够找到。
		target_link_libraries
			该指令的作用为将目标文件与库文件进行链接。
		例子：
		 link_directories(
			${catkin_INCLUDE_DIRS}
			$(svo_SOURCE_DIR)/include/svo
			$(svo_SOURCE_DIR)/include/svo/track
		)
		add_library(${PROJECT_NAME} SHARED
		src/track/Tracking.cpp		
		)

		add_executable(${PROJECT_NAME}_node src/svo_node.cpp src/system.cpp)
		target_link_libraries(${PROJECT_NAME}_node
			${catkin_LIBRARIES}
			${PROJECT_NAME}		
		)

		1，link_libraries用在add_executable之前，target_link_libraries用在add_executable之后
		2，link_libraries用来链接静态库，target_link_libraries用来链接导入库，
	
	14. include_directories
		是用来提供找头文件路径的,它相当于g++选项中的-I参数的作用		

			include_directories(../../../thirdparty/comm/include)

	15. file文件操作命令 参考：https://blog.csdn.net/tantion/article/details/84378266
		file(WRITE filename "message towrite"... )
		WRITE 将一则信息写入文件’filename’中，如果该文件存在，它会覆盖它，如果不存在，它会创建该文件。
		
		file(APPEND filename "message to write"... )
		APPEND 如同WRITE，区别在于它将信息内容追加到文件末尾。

		file(READ filename variable [LIMIT numBytes] [OFFSEToffset] [HEX])
		READ 会读取文件的内容并将其存入到变量中。它会在给定的偏移量处开始读取最多numBytes个字节。如果指定了HEX参数，二进制数据将会被转换成十进制表示形式并存储到变量中
		
		file(<MD5|SHA1|SHA224|SHA256|SHA384|SHA512> filenamevariable)
		MD5, SHA1, SHA224, SHA256, SHA384, 和SHA512 会计算出文件内容对应的加密散列。

		file(STRINGS myfile.txt myfile)， 将输入文件的每行内容存储在变量"myfile"中。

		file(GLOB variable [RELATIVE path] [globbingexpressions]...)
		GLOB 会产生一个由所有匹配globbing表达式的文件组成的列表，并将其保存到变量中。Globbing 表达式与正则表达式类似，但更简单。

		file(GLOB_RECURSE variable [RELATIVE path] [FOLLOW_SYMLINKS] [globbingexpressions]...)
		GLOB_RECURSE 与GLOB类似，区别在于它会遍历匹配目录的所有文件以及子目录下面的文件。

	16. list
		list(LENGTH <list><output variable>)	返回list的长度
		list(GET <list> <elementindex> [<element index> ...]<output variable>)  返回list中index的element到value中
		list(APPEND <list><element> [<element> ...]) 添加新element到list中
		list(FIND <list> <value><output variable>) 返回list中element的index，没有找到返回-1
		list(INSERT <list><element_index> <element> [<element> ...]) 将新element插入到list中index的位置
		list(REMOVE_ITEM <list> <value>[<value> ...]) 从list中删除某个element
		list(REMOVE_AT <list><index> [<index> ...]) 从list中删除指定index的element
		list(REMOVE_DUPLICATES <list>) 从list中删除重复的element
		list(REVERSE <list>)	将list的内容反转
		list(SORT <list>)	将list按字母顺序排序
		LIST与SET命令类似，即使列表本身是在父域中定义的，LIST命令也只会在当前域创建新的变量
	
	17. set_target_properties
		设置目标的一些属性来改变它们构建的方式。
		set_target_properties(target1 target2 ...
                        PROPERTIES prop1 value1
                        prop2 value2 ...)
		这条指令可以用来设置输出的名称，对于动态库，还可以用来指定动态库版本和API版本。
		例子：# 即：静态库名为 libhello.a； 动态库名为libhello.so ；
		# 所以，希望 "hello_static" 在输出时，不是"hello_static"，而是以"hello"的名字显示，故设置如下：
		SET_TARGET_PROPERTIES (hello_static PROPERTIES OUTPUT_NAME "hello")
		
		cmake在构建一个新的target时，会尝试清理掉其他使用这个名字的库，
	 	因此，在构建libhello.a时，就会清理掉libhello.so. 
		为了回避这个问题，比如再次使用SET_TARGET_PROPERTIES定义 CLEAN_DIRECT_OUTPUT属性。
		SET_TARGET_PROPERTIES (hello_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)
		SET_TARGET_PROPERTIES (hello PROPERTIES CLEAN_DIRECT_OUTPUT 1)
			
		# 按照规则，动态库是应该包含一个版本号的，
		# VERSION指代动态库版本，SOVERSION指代API版本。
		SET_TARGET_PROPERTIES (hello PROPERTIES VERSION 1.2 SOVERSION 1)
	
	18. install指令
		install用于指定在安装时运行的规则。它可以用来安装很多内容，可以包括目标二进制、动态库、静态库以及文件、目录、脚本等：
		目标文件 	内容 						安装目录变量 					默认安装文件夹
		ARCHIVE 	静态库 						${CMAKE_INSTALL_LIBDIR} 		lib
		LIBRARY 	动态库 						${CMAKE_INSTALL_LIBDIR} 		lib
		RUNTIME 	可执行二进制文件 			${CMAKE_INSTALL_BINDIR} 		bin
		PUBLIC_HEADER 	与库关联的PUBLIC头文件 	${CMAKE_INSTALL_INCLUDEDIR} 	include
		PRIVATE_HEADER 	与库关联的PRIVATE头文件 	${CMAKE_INSTALL_INCLUDEDIR} 	include
	
	19.	foreach{
	foreach(loop_var RANGE start stop [step])
		...
	endforeach(loop_var)
	例子：
		foreach(i RANGE 1 9 2)
			mesage(${i})
		endforeach(i)
		#输出：13579
		}
		
	20.	if() #条件判断

		
