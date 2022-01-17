C常用{
	
	fopen{
		如果成功的打开一个文件, fopen()函数返回文件指针,否则返回空指针 (NULL)
			"r"           打开文字文件只读
			"w"           创建文字文件只写
			"a"           增补, 如果文件不存在则创建一个
			"r+"          打开一个文字文件读/写
			"w+"          创建一个文字文件读/写
			"a+"          打开或创建一个文件增补
			"b"           二进制文件(可以和上面每一项合用)
			"t"           文这文件(默认项)
	}
	
	fseek{
		 int fseek( FILE *stream, long offset, int origin );
	  第一个参数stream为文件指针
	  第二个参数offset为偏移量，整数表示正向偏移，负数表示负向偏移
	  第三个参数origin设定从文件的哪里开始偏移,可能取值为：SEEK_CUR、 SEEK_END 或 SEEK_SET  SEEK_SET： 文件开头  SEEK_CUR： 当前位置  SEEK_END： 文件结尾
	  其中SEEK_SET,SEEK_CUR和SEEK_END和依次为0，1和2.  简言之：
	  fseek(fp,100L,0);把fp指针移动到离文件开头100字节处；
	  fseek(fp,100L,1);把fp指针移动到离文件当前位置100字节处；  fseek(fp,100L,2);把fp指针退回到离文件结尾100字节处。
	}
	ftell函数{
		ftell函数用以获得文件当前位置指针的位置
	}
	rewind函数{
		rewind(fp);
		函数没有返回值.函数的功能是使文件的位置指针回到文件的开头.
	}
	
	{access 确定文件的访问权限的
		int   access(const   char   *filename,   int   amode); 
		amode参数为0时表示检查文件的存在性，如果文件存在，返回0，不存在，返回-1。 
		这个函数还可以检查其它文件属性： 
		06     检查读写权限 
		04     检查读权限 
		02     检查写权限 
		01     检查执行权限 
		00     检查文件的存在性
		而这个就算这个文件没有读权限，也可以判断这个文件存在于否
		存在返回0，不存在返回-1

		C函数
		　　函数名: access 
		　　功 能: 确定文件的访问权限 
		　　用 法: int access(const char *filename, int amode);
	}
	
	{sscanf 字符串分隔
		1. 常见用法。
	　　char buf[512] = ;
	　　sscanf("123456 ", "%s", buf);
	　　printf("%s\n", buf);
	　　结果为：123456
	
	　　2. 取指定长度的字符串。如在下例中，取最大长度为4字节的字符串。
	　　sscanf("123456 ", "%4s", buf);
	　　printf("%s\n", buf);
	　　结果为：1234
	
	　　3. 取到指定字符为止的字符串。如在下例中，取遇到空格为止字符串。
	　　sscanf("123456 abcdedf", "%[^ ]", buf);
	　　printf("%s\n", buf);
	　　结果为：123456
	
	　　4. 取仅包含指定字符集的字符串。如在下例中，取仅包含1到9和小写字母的字符串。
	　　sscanf("123456abcdedfBCDEF", "%[1-9a-z]", buf);
	　　printf("%s\n", buf);
	　　结果为：123456abcdedf
	
	　　5. 取到指定字符集为止的字符串。如在下例中，取遇到大写字母为止的字符串。
	　　sscanf("123456abcdedfBCDEF", "%[^A-Z]", buf);
	　　printf("%s\n", buf);
	　　结果为：123456abcdedf
	
	　　6、给定一个字符串iios/12DDWDFF@122，获取 / 和 @ 之间的字符串，先将 "iios/"过滤掉，再将非'@'的一串内容送到buf中
	　　sscanf("iios/12DDWDFF@122", "%*[^/]/%[^@]", buf);
	　　printf("%s\n", buf);
	　　结果为：12DDWDFF
	
	　　7、给定一个字符串““hello, world”，仅保留world。（注意：“，”之后有一空格）
	　　sscanf(“hello, world”, "%*s%s", buf);
	　　printf("%s\n", buf);
	　　结果为：world
	　　%*s表示第一个匹配到的%s被过滤掉，即hello被过滤了
	　　如果没有空格则结果为NULL。
	}
	
}