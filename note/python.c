参考：https://www.liaoxuefeng.com/wiki/1016959663602400/1017063826246112
{python基础
	{r''表示''内部的字符串默认不转义
		>>> print('\\\t\\')
		\       \
		>>> print(r'\\\t\\')
		\\\t\\
	}

	{如果字符串内部有很多换行用'''...'''的格式表示多行内容,这里注意必须要是'''...'''
		>>> print('''line1
		... line2
		... line3''')
		line1
		line2
		line3
	}

	{布尔值 	True; False
	}

	{与 and， 或or ，not取反
	}

	{空值 None，不是0哈
	}

	{常量 全部都是大写的
	}

	{/ 这个是除法；  //这个地板除，值为整数，%取余数
		>>> 10 // 3
		3
		
		>>> 10 % 3
		1
	}

	{编码
		{ord()获取字符的整数}

		{chr()编码转换为对应的字符}

		{以Unicode表示的str通过encode()方法可以编码为指定的bytes，例如：

			>>> 'ABC'.encode('ascii')
			b'ABC'
			>>> '中文'.encode('utf-8')
			b'\xe4\xb8\xad\xe6\x96\x87'
			>>> '中文'.encode('ascii')
		}

		{要把bytes变为str，就需要用decode()方法
			>>> b'ABC'.decode('ascii')
			'ABC'
			>>> b'\xe4\xb8\xad\xe6\x96\x87'.decode('utf-8')
			'中文'
			
			如果bytes中只有一小部分无效的字节，可以传入errors='ignore'忽略错误的字节：

			>>> b'\xe4\xb8\xad\xff'.decode('utf-8', errors='ignore')
			'中'
		}
		
		len()函数计算的是str的字符数，如果换成bytes，len()函数就计算字节数：
		
		{格式化： %d(整数),%f(浮点数),%s(字符串),%x(十六进制)
			>>> 'Hello, %s' % 'world'
				'Hello, world'
			>>> 'Hi, %s, you have $%d.' % ('Michael', 1000000)
				'Hi, Michael, you have $1000000.'
		}		
	}

	{list 和tuple
		参考：https://www.liaoxuefeng.com/wiki/1016959663602400/1017092876846880
		list
			Python内置的一种数据类型是列表：list。list是一种有序的集合，可以随时添加和删除其中的元素。

			比如，列出班里所有同学的名字，就可以用一个list表示：

			>>> classmates = ['Michael', 'Bob', 'Tracy']
			>>> classmates
			['Michael', 'Bob', 'Tracy']
			变量classmates就是一个list。用len()函数可以获得list元素的个数：

			>>> len(classmates)
			3
			用索引来访问list中每一个位置的元素，记得索引是从0开始的：

			>>> classmates[0]
			'Michael'
			>>> classmates[1]
			'Bob'
			>>> classmates[2]
			'Tracy'
		
		当索引超出了范围时，Python会报一个IndexError错误，所以，要确保索引不要越界，记得最后一个元素的索引是len(classmates) - 1。

			如果要取最后一个元素，除了计算索引位置外，还可以用-1做索引，直接获取最后一个元素：

			>>> classmates[-1]
			'Tracy'
			以此类推，可以获取倒数第2个、倒数第3个：

			>>> classmates[-2]
			'Bob'
			>>> classmates[-3]
			'Michael'
			
		tuple
			另一种有序列表叫元组：tuple。tuple和list非常类似，但是tuple一旦初始化就不能修改，比如同样是列出同学的名字：

			>>> classmates = ('Michael', 'Bob', 'Tracy')
			现在，classmates这个tuple不能变了，它也没有append()，insert()这样的方法。其他获取元素的方法和list是一样的，你可以正常地使用classmates[0]，classmates[-1]，但不能赋值成另外的元素。
	}

	{条件判断
		if:
			;
		elif:
			;
		else:
			;
	}
	
	{循环
		names = ['Michael', 'Bob', 'Tracy']
		for name in names:
			print(name)
		
		for x in [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]:
			sum = sum + x
	}
	
	{dict和set
		dict的支持，dict全称dictionary，在其他语言中也称为map，使用键-值（key-value）存储，具有极快的查找速度。
			>>> d = {'Michael': 95, 'Bob': 75, 'Tracy': 85}
			>>> d['Michael']
			95
		
		set和dict类似，也是一组key的集合，但不存储value。由于key不能重复，所以，在set中，没有重复的key。
			>>> s = set([1, 1, 2, 2, 3, 3])
			>>> s
			{1, 2, 3}
	}
}

{函数
	abs()绝对值函数
	
	{数据类型转换，直接转类型
		>>> int('123')
		123
		>>> int(12.34)
		12
		>>> float('12.34')
		12.34
		>>> str(1.23)
		'1.23'
		>>> str(100)
		'100'
		>>> bool(1)
		True
		>>> bool('')
		False
	}
	
	{定义函数
		定义一个函数要使用def语句，依次写出函数名、括号、括号中的参数和冒号:，然后，在缩进块中编写函数体，函数的返回值用return语句返回。
		def my_abs(x):
			if x >= 0:
				return x
			else:
				return -x
		
		返回多个值
			import math

			def move(x, y, step, angle=0):
				nx = x + step * math.cos(angle)
				ny = y - step * math.sin(angle)
				return nx, ny
			但其实这只是一种假象，Python函数返回的仍然是单一值：
				原来返回值是一个tuple！但是，在语法上，返回一个tuple可以省略括号，而多个变量可以同时接收一个tuple，按位置赋给对应的值，所以，Python的函数返回多值其实就是返回一个tuple，但写起来更方便。
	}
	
	{高级特性
		
	}
}

