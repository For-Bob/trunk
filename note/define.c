#define说明

{define中的特殊标识符
	##最简单的连接符，
	#@用来给参数加单引号，#用来给参数加双引号即转出字符串
	例子：
		#define Conn(x,y) x##y
		#define ToChar(x) #@x
		#define ToString(x) #x
		
		int a = Conn(12, 34);	//a = 1234
		char b = ToChar(a);		//b = 'a'
		char c[] = ToString(a); //c = "1234"
	可变参数的宏定义
		...表示参数可变，__VA_ARGS__在预处理中为实际的参数集所替换
		#define LOG(format, ...) fprintf(stdout, format, __VA_ARGS__)
	
	## 另外，如果##后的参数本身也是一个宏的话，##会阻止这个宏的展开，也就是只替换一次。
    #define STRCPY(a, b)    strcpy(a ## _p, #b)
		char var1_p[20];
        char var2_p[30];

        STRCPY(STRCPY(var1,var2),var2);
        /* 这里是否会展开为： strcpy(strcpy(var1_p,"var2")_p,"var2“）？
         * 答案是否定的：
         * 展开结果将是：  strcpy(STRCPY(var1,var2)_p,"var2")
         * ## 阻止了参数的宏展开!
         * 如果宏定义里没有用到 # 和 ##, 宏将会完全展开*/
		 
	#define LOG_I(ctxn, format, ...)    printf("[INFO]["##ctxn##"]"##format"\n",__VA_ARGS__)//这里的##是连接符
	LOG_I(HMIA, " %s line = %d [time] = %d millisec", __func__, __LINE__, kzsTimeGetCurrentTimestamp() - one::hmi::s_startTime);
	[INFO][HMIAPP] onProjectLoaded line = 86 [time] = 1220 millisec

}
{工程例子
	#ifndef APPDEF_H
	#define APPDEF_H

	#define SET_PROPERTY(name, value) setProperty_##name(value)
	#define GET_PROPERTY(name) getProperty_##name()

	#define DECLARE_READ_(...)//这个宏定义是啥事都不干，后面的这种定义是一样的意思
	#define DECLARE_READ_2(...)
	#define DECLARE_READ_READ(type, member, read) \
		public: inline type read() const {return member;} \

	#define DECLARE_WRITE_(...)
	#define DECLARE_WRITE_1(...)
	#define DECLARE_WRITE_2(...)
	#define DECLARE_WRITE_WRITE(type, member, write, notify) \
		private: inline void write(const type &value) {\
		if (member != value) {member = value; emit notify();}}

	#define READ_CONCAT(_0, read, _2, N, ...) DECLARE_READ_##read
	#define WRITE_CONCAT(_0, _1, write, N, ...) DECLARE_WRITE_##write

	
	// DECLARE_PROPERTY(type, name[, read])	
	#define DECLARE_PROPERTY(type, name, ...) \	//...代表参数个数不定，参数类型不定
		Q_PROPERTY(type name MEMBER m_##name NOTIFY name##Changed) \
		READ_CONCAT(0, ##__VA_ARGS__, 2, 1, 0)(type, m_##name, getProperty_##name) \	//__VA_ARGS__ 是一个可变参数的宏，很少人知道这个宏，这个可变参数的宏是新的C99规范中新增的，目前似乎只有gcc支持（VC6.0的编译器不支持）。实现思想就是宏定义中参数列表的最后一个参数为省略号（也就是三个点）。
		WRITE_CONCAT(0, ##__VA_ARGS__, 2, 1, 0)(type, m_##name, setProperty_##name, name##Changed) \//##__VA_ARGS__ 宏前面加上##的作用在于，当可变参数的个数为0时，这里的##起到把前面多余的","去掉的作用,否则会编译出错
		Q_SIGNALS: void name##Changed(); \
		private: type m_##name;

	#endif // APPDEF_H
	
	//一般的传参是DECLARE_PROPERTY(int，value，READ)、	DECLARE_PROPERTY(int，value，READ,WRITE) 	DECLARE_PROPERTY(int，value，,WRITE)
	//1.DECLARE_PROPERTY(int，value，READ)到READ_CONCAT(0, ##__VA_ARGS__, 2, 1, 0)(type, m_##name, getProperty_##name)，就是READ_CONCAT(0,READ,2,1,0)(int,m_value,getProperty_value),READ_CONCAT在进行宏展开，DECLARE_READ__READ在宏展开，
		//DECLARE_READ__READ(int,m_value,getProperty_value)在展开 public: inline int getProperty_value() const {return m_value}
		//WRITE_CONCAT(0, ##__VA_ARGS__, 2, 1, 0)(type, m_##name, setProperty_##name, name##Changed)宏展开WRITE_CONCAT(0, 2, 1, 0)在宏展开DECLARE_WRITE_1
	//2.DECLARE_PROPERTY(int，value，READ,WRITE)到READ_CONCAT(0, ##__VA_ARGS__, 2, 1, 0)(type, m_##name, getProperty_##name)，就是READ_CONCAT(0,READ,WRITE,1,0)(int,m_value,getProperty_value),READ_CONCAT在进行宏展开，DECLARE_READ__READ在宏展开，
		//DECLARE_READ__READ(int,m_value,getProperty_value)在展开 public: inline int getProperty_value() const {return m_value}
		//到WRITE_CONCAT(0, ##__VA_ARGS__, 2, 1, 0)(type, m_##name, setProperty_##name, name##Changed)，就是WRITE_CONCAT(0, READ,WRITE 2, 1, 0)(int, m_value, setProperty_value, valueChanged)，WRITE_CONCAT(_0, _1, write, N, ...) 在宏展开，DECLARE_WRITE_WRITE在宏展开，
		//DECLARE_WRITE_WRITE(int, m_value, setProperty_value, valueChanged)宏展开，private: inline void setProperty_value(const int &value){if(m_value !=value){m_value = value;emit valueChanged()} }
	//3.DECLARE_PROPERTY(int，value，,WRITE)，WRITE_CONCAT就不说了，和上面一样的，READ_CONCAT(0, ##__VA_ARGS__, 2, 1, 0)(type, m_##name, getProperty_##name)宏展开就为READ_CONCAT(0, , 2, 1, 0)(type, m_##name, getProperty_##name)在宏展开， DECLARE_READ_
}	