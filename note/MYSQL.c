
{SQL

	DDL-Data Definition Language 数据定义语言；
	E-R entity-relationship	实体-关系
	UML Unified Modeling Language 	为定义的模型语言
	DML（Data Manipulation Language 数据操控语言）；
	SQL (Structured Query Language) 结构化查询语言
	DBMS Data Base Management System）数据库管理系统
	
	{键的类型
		复合键：包含两个或更多属性的键。
		
		{候选键与主键
			候选键是唯一标识表中每一行的键。候选键可以是单列键，也可以是复合键。主键是DBMS用于唯一标识表中每一行的候选键。例如：
				EMPLOYEE(EmployeeNumber, FirstName, LastName, Department, Email, Phone)
				
				用户告诉我们，EmployeeNumber是唯一键，Email是唯一键，复合键(FirstName,LastName,Department)也是唯一键，因此有三个候选键。在设计数据库时，需要选出一个候选键作为主键(primary key)。 因此本例使用EmployeeNumber作为主键。
		}
	}
	
	{基本类型
		char(n):		用户定义的固定n个长度的字符串
		varchar(n)：	用户定义的可变的n个长度的字符串
		int：			整型
		smallint：		整型
		numeric(p,d)	p个长度的数，d为小数点位
		real,double precision：浮点数和双精度浮点数
		float(n)		n位精度的浮点数
		
		char与varchar的区别：
			char(10) varchar(10)：储存"aaa"，则char(10)需要10个字符的空间来储存，而varchar(10)只需要3个字符的空间。
			
		类型		字节	最小值		最大值
		tinyint		1		-128~		127	有符号
							0			255	无符号
		smallint	2		-32768		32767	有符号
							0			65535	无符号
		mediumint	32767	-8388608	8388607	有符号
							0			16777215	无符号
		int			4		-2147483648	2147483647	有符号
							0			4294967295	无符号
		bigint		8		-9223372036854775808	9223372036854775807
							0			18446744073709551615
		
		numeric(10,2)	长度为10，小数位两位
		
		
	}

	{一些常用的 SQL 关键字
		SQL关键字		向导和数据库类用它来
		SELECT			标识数据源中要使用的表和列。
		WHERE			应用筛选器以缩小选定范围。
		ORDER BY		对记录集应用排序顺序。
		Insert			向记录集添加新记录。
		Delete			从记录集中删除记录。
		UPDATE			修改记录的字段。 
	}
	
	{基本语法
		select name	//选择表中的哪一项
			from table	//选择哪个表
			where condition	//条件是什么，如果没条件，那么就会得到所有的name
		
		insert into table	//插入内容
			vaules(int,vchar,vchar...);
			
		delete from table //删除
		
		drop table r;	//移除table中r的所有信息和关系
		delete table r; //移除table中r的所有信息和关系
		
		/DROP TABLE语句则不仅将表中的数据行全部删除，而且还将表的结构也删除。可以形象的比喻成DELETE 语句仅仅是“吃光碗里的饭” ，而 DROP TABLE 语句则是“吃光碗里的饭还将碗砸碎” 。
		
		alter table r add A D;	//为table中r添加属性A,D
		
		select distinct dept_name //查询instructor表中dept_name,但是会去掉重复的内容，distinct就是去除重复的
				from instructor;
				
		select ID, name, dept name, salary * 1.1	//这个查询，会使salary原本的值*1.1，其他和前面一样
			from instructor;
			
		并列条件用“，”隔开就行
		
		{创建表
			create table department
			(dept_name varchar (20),
			building varchar (15),
			budget numeric (12,2),
			primary key (dept_name));
			创建一个表名字为；department
				三个属性，名字：dept_name 字符串长度20，名字building 字符串长度15，名字budget,数字长度12,2位小数位
				主键为dept_name
			
			定义非空约束
				CREATE TABLE T_Student (FNumber VARCHAR(20) NOT NULL ,FName VARCHAR(20)
					NOT NULL ,FAge INT NOT NULL ,FFavorite VARCHAR(20),FPhoneNumber VARCHAR(20))
				非空字段的定义在类型定义后增加了“NOTNULL” ，其他定义方式与普通字段相同。	
				
			定义默认值
				CREATE TABLE T_Teacher (FNumber VARCHAR(20),FName VARCHAR(20),FAge INT,
					FISMaster VARCHAR(5) DEFAULT 'NO')
			
			定义外键
				FOREIGN KEY 外键字段名称 REFERENCES 目标表名(被关联的字段名称)
					MYSQL,MSSQLServer:
						CREATE TABLE T_Department (FId VARCHAR(20),FName VARCHAR(20),
							FLevel INT,PRIMARY KEY (FId))
							
					我们在员工信息表中保存部门信息表中的主键，保存这个主键的字段就被称为员工信息表中指向部门信息表的外键。		
					CREATE TABLE T_Employee (FNumber VARCHAR(20),FName VARCHAR(20),
						FDepartmentId VARCHAR(20),
						FOREIGN KEY (FDepartmentId) REFERENCES T_Department(FId))
					
		}
		
		{为表增删列（字段）
			添加
				ALTER TABLE 待修改的表名 ADD 字段名 字段类型
				例子：为T_Person表增加个人爱好字段
				ALTER TABLE T_PERSON ADD FFavorite VARCHAR(20)
			
			删除
				ALTER TABLE 待修改的表名 DROP 待删除的字段名
				例子：删除T_Person表中年龄字段的SQL语句
				ALTER TABLE T_PERSON DROP FAge
		}
		
		{删除数据表
			DROP TABLE 要删除的表名
			例子：将T_Person表删除
			DROP TABLE T_PERSON
			注意：如果在表之间穿件了外键关联关系，必须首先删除引用表，然后才能删除被引用表。比如 A 表创建了指向 B 表的外键关联关系， 那么必须首先删除 A 表后才能删除 B 表。
		}
		
		{向数据表中插入数据 INSERT
			CREATE TABLE T_Person (FName VARCHAR(20),FAge INT,FRemark
				VARCHAR(20),PRIMARY KEY (FName));	//先创建一个表
				
			INSERT INTO T_Person(FName,FAge,FRemark) VALUES('Tom',18,'USA')	//插入一条数据
			
			//插入多条数据
			INSERT INTO T_Person(FName,FAge,FRemark) VALUES('Jim',20,'USA');
			INSERT INTO T_Person(FName,FAge,FRemark) VALUES('Lili',22,'China') ;
			INSERT INTO T_Person(FName,FAge,FRemark) VALUES('XiaoWang',17,' China ') ;
		}

		{查看表中的所有内容
			select *from 表名
		}
		
		{查找字符
			"%"		匹配字符串
				"Intro%"	匹配有Intro开始的字符串
				"%Intro%"	匹配有Intro的字符串
			"\\"	代表\	跟C语言一样的
			*		选择所有
		}
		
		{排序
			select name
			from instructor
			where dept_name = ’Physics’
			order by name;
			显示出来是instrucor表中,dept_name的内容按升序显示，order默认就是升序
		}
		
		{between
			select name
			from instructor
			where salary between 90000 and 100000;
			显示出来是instrucor表中，工资大于90000，小于100000这之间的。
		}
		
		{union 连接两条语句 相当于并
			(select course id
			from section
			where semester = ’Fall’ and year= 2009)
			union
			(select course id
			from section
			where semester = ’Spring’ and year= 2010);
			将section表中，semester = ’Fall’和’Spring’，year = 2009和2010的条件，选出来显示course_id,这个会去除重复的内容。
			
			如果想要保留重复的内容，就将union换成union all
		}
		
		{intersect 相当于与
			用法与union一样
			
			intersect all保留重复的内容
		}
		
		{except 相当于异或
			用法与union一样
			execpt all保留重复的内容
		}
		
		{替换
			
			update table[表名] set Fields[字段名]=replace(Fields[字段名],'被替换原内容','要替换成的内容')

			update ProgInfo set JoinTime=replace(JoinTime,'2007-3-2','2007-03-02') 
			
			UPDATE T_Person SET FRemark = 'Sonic', FAge=25	//将T_Person中的FRemark都设为Sonic和FAge都设为25。并列条件用“，”隔开就行
			
			UPDATE T_Person SET FAge = 12 WHERE FNAME='Tom' //将T_Person中FNAME是Tom的FAge设为12
		}

		{或
			检索出所有工资少于 5000 元或者年龄大于 25 岁的员工的所有信息：
			SELECT * FROM T_Employee
				WHERE FSalary<5000 OR FAge>25
		}
		
		{聚合函数
			MAX 	计算字段最大值
			MIN	 	计算字段最小值
			AVG 	计算字段平均值
			SUM 	计算字段合计值
			COUNT 	统计数据条数		
			
			{例子：最大值
				查询年龄大于 25 岁的员工的最高工资，执行下面的 SQL：
				SELECT MAX(FSalary) FROM T_Employee
				WHERE FAge>25
			}
			
			{例子：平均值
				统计一下工资大于 3800 元的员工的平均年龄，执行下面的 SQL：
				SELECT AVG(FAge) FROM T_Employee
				WHERE FSalary>3800
			}
			
			{例子：最大值和最小值
				统计公司的最低工资和最高工资：
				SELECT MIN(FSalary),MAX(FSalary) FROM T_Employee
			}
		}	
		
		{排序 ORDER BY
			年龄排序所有员工信息的列表：
			SELECT * FROM T_Employee
			ORDER BY FAge ASC	//ORDER BY FAge /*默认是升序*/
			//ASC是升序，DESC是降序
		}
		
		{通配符
		
			{单字匹配
				进行单字符匹配的通配符为半角下划线“_” ，它匹配单个出现的字符。
					比如通配符表达式“b_d”匹配第一个字符为 b、第二个字符为任意字符、第三个字符为 d 的字符串， “bed”、“bad”都能匹配这个表达式，
					通配符表达式“_oo_”匹配第一个字符为任意字符、第二个字符为 o、第三个字符为 o、第四个字符为任意字符的字符串， “look” 、“took” 、“cool”都能匹配这个表达式，
					
					例子：
						以任意字符开头，剩余部分为“erry”。
						SELECT * FROM T_Employee
						WHERE FName LIKE '_erry'
					
					例子：长度为 4、 第三个字符为 “n”、其它字符为任意字符的姓名
						SELECT * FROM T_Employee
						WHERE FName LIKE '__n_'
					
				进行多字符匹配的通配符为半角百分号“%” ，它匹配任意次数（零或多个）出现的任意字符。
					比如通配符表达式“k%”匹配以“k”开头、任意长度的字符串， “k” 、“kerry”、“kb” 都能匹配这个表达式，
					配符表达式“b%t”匹配以“b”开头、以“t”结尾、任意长度的字符串， “but” 、“bt” 、“belt” 都能匹配这个表达式，
					
				例子：	
					SELECT * FROM T_Employee
						WHERE FName LIKE '%n%'
						
				例子：最后一个字符为任意字符、倒数第二个字符为“n”、长度任意的字符串
					SELECT * FROM T_Employee
						WHERE FName LIKE '%n_'
			}
			
			{集合匹配
				进行集合匹配的通配符为“[]” ，方括号中包含一个字符集，它匹配与字符集中任意一个字符相匹配的字符。
					比如通配符表达式“[bt]%”匹配第一个字符为 b 或者 t、长度不限的字符串， “bed”、“token”、“t”都能匹配这个表达式。
					
					例子：
						SELECT * FROM T_Employee
							WHERE FName LIKE '[SJ]%
					
				在MYSQL上不能用集合匹配，下面的例子等同于上面
						SELECT *FROM T_Employee
							WHERE FName LIKE 'S%' OR FName LIKE 'J%'
							
				还可以使用否定符“^”来对集合取反，它匹配不与字符集中任意一个字符相匹配的字符。
					比如通配符表达式“[^bt]%”匹配第一个字符不为 b 或者 t、长度不限的字符串， “at”、“lab”、“lot”都能匹配这个表达式，而 “bed”、“token”、“t”等则不能匹配这个表达式。
					
					例子：以“S”或者“J“开头长度，长度任意
						SELECT * FROM T_Employee
							WHERE FName LIKE '[^SJ]%'
				
					而下面的 SQL 可以实现和上面例子相同的效果：
						SELECT * FROM T_Employee
							WHERE NOT(FName LIKE 'S%') AND NOT(FName LIKE 'J%')
			}
			
			{空值检测
				SELECT * FROM T_Employee
					WHERE FNAME IS NULL
			}
			
			{反义运算符
				这样“不等于”、“不大于”和“不小于”就分别可以表示成“<>”、“<=”和“>=”
				
					例子：检索所有年龄不等于22岁并且工资不小于2000元
						SELECT * FROM T_Employee
							WHERE FAge<>22 AND FSALARY>=2000
						
				NOT运算符用来将一个表达式的值取反，也就是将值为“真”的表达式结果变为“假”
				
				例子：检索所有年龄不等于22岁并且工资不小于2000元
					SELECT * FROM T_Employee
						WHERE NOT(FAge=22) AND NOT(FSALARY<2000)
					//建议使用NOT，因为这个通用一些				
			}
			
			{多值检测
				OR表示或的意思
					
					例子：检测为23岁、25岁和28岁的员工
						SELECT FAge,FNumber,FName FROM T_Employee
							WHERE FAge=23 OR FAge=25 OR FAge=28
				
				IN一样的意思
					例子：如果需要检测很多年龄段的，就容易出错，
						SELECT FAge,FNumber,FName FROM T_Employee
							WHERE FAge IN (23,25,28)
			}
			
			{范围值检测
				例子：检索所有年龄介于23岁到27岁之间的员工信息
					SELECT * FROM T_Employee
						WHERE FAGE>=23 AND FAGE <=27
				
				SQL提供了一个专门用语范围值检测的语句“BETTWEEN AND”
					SELECT * FROM T_Employee
						WHERE FAGE BETWEEN 23 AND 27	//与上面一样的意思
				
				例子：检索所有工资介于2000元到3000元之间以及5000元到8000元的员工信息
					SELECT * FROM T_Employee
						WHERE (FSalary BETWEEN 2000 AND 3000)
						OR (FSalary BETWEEN 5000 AND 8000)
			}
			
			{数据分组
				例子：查看公司员工有哪些年龄段的
					SELECT FAge FROM T_Employee
					GROUP BY FAge
					
				如果SELECT语句有WHERE子句，则GROUP BY子句必须放到WHERE语句的之后
					SELECT FAge FROM T_Employee
						WHERE FSubCompany = 'Beijing'
						GROUP BY FAge
				
				GROUP BY子句中可以指定多个列，只需要将多个列的列名用逗号隔开即可
					SELECT FSubCompany,FDepartment FROM T_Employee
						GROUP BY FSubCompany,FDepartment
						
				HAVING语句
					有的时候需要对部分分组进行过滤，比如只检索人数多余1个的年龄段
						SELECT FAge,COUNT(*) AS CountOfThisAge FROM T_Employee
							GROUP BY FAge
							HAVING COUNT(*)>1
							
					HAVING语句中也可以像WHERE语句一样使用复杂的过滤条件，比如下面的SQL用来检索人数为1个或者3个的年龄段，可以使用下面的SQL：
					SELECT FAge,COUNT(*) AS CountOfThisAge FROM T_Employee
						GROUP BY FAge
						HAVING COUNT(*) =1 OR COUNT(*) =3
					
					SELECT FAge,COUNT(*) AS CountOfThisAge FROM T_Employee	//与上面的功能一致，只是将OR换成了IN
						GROUP BY FAge
						HAVING COUNT(*) IN (1,3)
			}
		}
		
		{限制结果集行数 LIMIT
			按照工资降序排列的从第二行开始（行号从0开始）的最多五条记录
				SELECT * FROM T_Employee ORDER BY FSalary DESC LIMIT 2,5
		}
		
		{DISTINCT
			SELECT DISTINCT FDepartment FROM T_Employee	//查询结果会去掉重复的内容
		}
		
		{函数
			{数学函数
				ABS()求绝对值
				POWER()函数是用来计算指数的函数。该函数接受两个参数，第一个参数为待求幂的表达式，第二个参数为幂
				SQRT()函数是用来计算平方根的函数
				RAND()函数的返回值是随机数
				CEILING()函数：舍入到最大整数 相当于在原来数加1，如果有小数部分，且小数部分不为0
				FLOOR()函数 用来舍掉一个数的小数点后的部分，并且向下舍入到邻近的最小的整数。
				ROUND()函数：四舍五入函数，
					ROUND(m,d)，其中 m 为待进行四舍五入的数值，而 d 则为计算精度，也就是进行四舍五入时保留的小数位数。
					比如 3.663 进行精度为 2 的四舍五入得到 3.66
				SIN()：用来计算一个数值的正弦值的函数
				COS()：求余弦值
				ASIN()：反正弦值
				ACOS()：反余弦值
				TAN(): 用来计算一个数值的正切值的函数为 
				ATAN(): 用来计算一个数值的反正切值的函数为 
				ATAN2(X,Y)函数返回 2 个变量 X 和 Y 的反正切
				COT(): 计算一个数值的反正切值的函数
				PI():求π值
				DEGREES ()：将一个数值从弧度制转换为角度制的函数
				RADIANS ()：将一个数值从角度制转换为弧度制的函数
				SIGN()函数用来返回一个数值的符号，如果数值大于 0 则返回 1，如果数值等于 0 则返回 0，如果数值小于 0 则返回-1
				MOD()函数用来计算两个数整除后的余数。该函数接受两个参数，第一个参数为除数，而第二个参数则是被除数。
				LOG ()函数用来计算一个数的自然对数值
				LOG10()函数用来计算一个数的以 10 为底的对数值。
			}
			
			{字符串函数
				LENGTH()函数用来计算一个字符串的长度
				LOWER()函数用来将一个字符串转换为小写。
				UPPER ()函数用来将一个字符串转换为大写
				LTRIM()函数用来将一个字符串左侧的空格去掉
				RTRIM ()函数用来将一个字符串左侧的空格去掉
				TRIM ()函数用来将一个字符串两侧的空格去掉
				SUBSTRING(string,start_position,length)：返回子字符串，其中参数 string 为主字符串，start_position 为子字符串在主字符串中的起始位置，length为子字符串的最大长度。
				INSTR(string,substring)其中参数 string 为主字符串，参数 substring 为待查询的子字符串。如果 string 中存在substring 子字符串，则返回子字符串第一个字符在主字符串中出现的位置；
					如果 string 中不存在 substring 子字符串，则返回 0。
				LOCATE(substring,string)	//作用与上面一样，只是主字符串和子字符串交换了位置。
				LEFT()函数用于从左侧开始取任意长度的子字符串
				RIGHT ()函数用于从右侧开始取任意长度的子字符串
				REPLACE(string,string_tobe_replace,string_to_replace)	//元素，被替换的，替换成的
				ASCII()函数用来得到一个字符的 ASCII 码，它有且只有一个参数，这个参数为待求ASCII 码的字符，如果参数为一个字符串则函数返回第一个字符的 ASCII 码，
				CHAR()得到一个 ASCII 码数字对应的字符
				SOUNDEX()函数用于计算一个字符串的发音特征值，
				DIFFERENCE(str，str1)str发音与str1的相似度
			}
			
			{时间日期函数
				NOW(),SYSDATE(),CURRENT_TIMESTAMP	//日期和时间
				CURDATE(),CURRENT_DATE			//日期
				CURTIME(),CURRENT_TIME			//时间
				DATE_ADD (date,INTERVAL expr type)	//其中参数date为待计算的日期；参数expr为待进行加法运算的增量，它可以是数值类型或者字符串类型，取决于type参数的取值
				DATE_SUB()	//减量，用法一样
				DATEDIFF(date1,date2)	//函数将返回date1与date2之间的天数差额，
			}
			
			{类型转换
				CAST(expression AS type)
				CONVERT(expression,type)
				
				type可以是以下任意值
				可选值 				缩写 		说明
				BINARY 				BINARY		字符串
				CHAR 							字符串类型
				DATE 							日期类型
				DATETIME 						时间日期类型
				SIGNED INTEGER 		SIGNED 		有符号整数
				TIME 							时间类型
				UNSIGNED INTEGER 	UNSIGNED 	无符号整数
				
				例子：
				SELECT
					CAST('-30' AS SIGNED) as sig,
					CONVERT ('36', UNSIGNED INTEGER) as usig
			}
			
			{其他函数
				TO_CHAR(expression,format)函数用来将时间日期类型或者数值类型的数据转换为字符串，参数expression为待转换的表达式，参数format为转换后的字符串格式，参数format可以省略，
				TO_DATE (expression,format)函数用来将字符串转换为时间类型，参数expression为待转换的表达式，参数format为转换格式，参数format可以省略
				TO_NUMBER()函数用来将字符串转换为数值类型，参数expression为待转换的表达式，参数format为转换格式。
				HEXTORAW()用于将十六进制格式的数据转换为原始值。
				而RAWTOHEX()函数用来将原始值转换为十六进制格式的数据。
				TO_MULTI_BYTE()函数用于将字符串中的半角字符转换为全角字符。TO_MULTI_BYTE('moring')	//ｍｏｒｉｎｇ
				TO_SINGLE_BYTE()函数则用来将字符串中的全角字符转换为半角字符。TO_SINGLE_BYTE('ｈｅｌｌｏ')	//hello
				COALESCE()函数，这个函数主要用来进行空值处理：COALESCE ( expression,value1,value2……,valuen) expression不为空值则返回expression；
				否则判断value1是否是空值，如果value1不为空值则返回value1；否则判断value2是否是空值，如果value2不为空值则返回value3；……以此类推，如果所有的表达式都为空值，则返回NULL。
					IFNULL(expression,value)是COALESCE的简化版，功能还是一样的。
				NULLIF ( expression1 , expression2 )如果两个表达式不等价，则 NULLIF 返回第一个 expression1的值。如果两个表达式等价，则 NULLIF 返回第一个 expression1类型的空值。
				
				CASE()函数:
					CASE expression
					WHEN value1 THEN returnvalue1
					WHEN value2 THEN returnvalue2
					WHEN value3 THEN returnvalue3
					……
					ELSE defaultreturnvalue
					END
					
					CASE
					WHEN condition1 THEN returnvalue1
					WHEN condition 2 THEN returnvalue2
					WHEN condition 3 THEN returnvalue3
					……
					ELSE defaultreturnvalue
					END
				
				IF()函数：IF(expr1,expr2,expr3)如果 expr1 为真(expr1 <> 0 以及 expr1 <> NULL)，那么 IF() 返回 expr2，否则返回expr3
				
				CONV()函数用于对数字进行进制转换，CONV(N,from_base,to_base)将数字 N 从 from_base进制转换到 to_base进制，并以字符串表示形式返回
				BIN(N)、OCT(N)、HEX(N)它们分别用于返回 N的字符串表示的二进制、八进制值和十六进制形式
				
				填充函数：
					LPAD(str,len,padstr)
					RPAD(str,len,padstr)
					用字符串 padstr 对 str 进行左（右）边填补直至它的长度达到 len 个字符长度，然后返回 str。如果 str 的长度长于 len'，那么它将被截除到 len 个字符。
					
				REPEAT()函数用来得到一个子字符串重复了若干次所组成的字符串，参数str为子字符串，而count为重复次数。
				REVERSE()函数用来将一个字符串的顺序颠倒
				
			}
			
		}
		
	}
	
}