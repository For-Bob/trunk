正则表达式
{表达规则	
	符号	意义
	^		匹配行的开头，要匹配这个字符，请使用 \^。
	$		匹配行的结尾，要匹配这个字符，请使用 \$。
	.		匹配任意单个字符，要匹配这个字符，请使用 \.。
	[…]		匹配[]中的任意一个字符，要匹配字符，请使用 \[\]。
	(…)		设定分组。要匹配这些字符，请使用 \( 和 \)。
	\		转义字符,要匹配这个字符，请使用 \\。
	\d		匹配数字[0-9]
	\D		\d 取反
	\w		匹配字母[a-z]，数字，下划线
	\W		\w 取反
	\s		匹配空格
	\S		\s 取反
	+		前面的元素重复1次或多次,要匹配这个字符，请使用 \+。
	*		前面的元素重复任意次,要匹配这个字符，请使用 \*。
	?		前面的元素重复0次或1次,要匹配这个字符，请使用 \?。
	{n}		前面的元素重复n次,要匹配这些字符，请使用 \{ 和 \}。
	{n,}	前面的元素重复至少n次
	{n,m}	前面的元素重复至少n次，至多m次
	|		逻辑或,要匹配这个字符，请使用 \|。
	$&		表示原来的字符，一般用于replace
	
	说明：
		比如下面的\( 实际程序是\\(,一定要注意这个,因为\\转义才是\
		如果不想用转义字符，那么可以前面加上R，然后()
			比如：std::regex r(R"(Speed:\t\d*)");
}

{c++正则表达式函数
	函数								功能
	regex_match(s, e)					目标字符串s和正则表达式e是否完全匹配						
	regex_match(s, m,e)					目标字符串s是否存在某个子串与正则表达式e完全匹配,匹配结果m	
		特别说明：注意完全匹配，
		比如：s = "GetValues", e = "GetValue", 这种情况返回都是false，必须要完全一样才行
		
	regex_search(s, m,e)				目标字符串s是否存在某个子串与正则表达式e匹配,匹配结果m	
	
		返回值：对于regex_match和regex_search的返回值，若匹配存在则返回 true ，否则返回 false 
		参数说明：m	-	匹配结果		//声明为cmatch m或者 smatch m
				  s	-	目标字符串		//一般声明为string  s
				  e	-	正则表达式		//声明为regex
				  
	regex_replace(s, e, s1)			用s1替换目标字符串s中与正则表达式re匹配的子串		//string s;  ;regex e; string s1	
		
}

{子函数说明
	std::cmatch	std::match_results<const char*>						//cmatch是一个字符串
	std::smatch	std::match_results<std::string::const_iterator>		//cmatch是一个字符串合集
}

{匹配前面的函数说明
	std::match_results<BidirIt,Alloc>::prefix					//到未匹配前缀的引用。就是匹配到字符的前面字符
	
	比如：
	#include <iostream>
	#include <regex>
	#include <string>
	 
	int main()
	{
	  std::regex re("a(a)*b");
	  std::string target("naaaby");
	  std::smatch sm;
	 
	  std::regex_search(target, sm, re);
	  std::cout << sm.prefix().str() << '\n';	//匹配了aaab,前面的就是n，所以输出n
	}
}

{匹配后面的函数说明
	std::match_results<BidirIt,Alloc>::suffix					//到未匹配后缀的引用。就是匹配过后剩下的
	
	比如：
	#include <iostream>
	#include <regex>
	#include <string>
	 
	int main()
	{
		std::regex re("a(a)*b");
		std::string target("naaaby");
		std::smatch sm;
	 
		std::regex_search(target, sm, re);
		std::cout << sm.suffix().str() << '\n'; //匹配了aaab,剩下就是 y，所以输出y
	}
}

