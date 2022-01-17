
evhttp_cmd_type { EVHTTP_REQ_GET, EVHTTP_REQ_POST, EVHTTP_REQ_HEAD }
{基于libevent的http协议 学习笔记之认识基本函数（1）
	1. evhttp_new

	声明： struct evhttp *evhttp_new(struct event_base *base);

	用途：用于创建一个新的HTTP server，

	参数： base（可选）用来接收http事件， （注：可选是什么意思暂时不清楚，欢迎补充！），

	结果指针释放：在需要释放http server指针时，可参见函数evhttp_free()。



	2. evhttp_bind_socket

	声明：int evhttp_bind_socket(struct evhttp *http, const char *address, ev_uint16_t port);

	用途：绑定http server到一个指定的ip地址和端口，可重复调用该函数来绑定到同一个地址的不同端口，

	参数：（1）http为待绑定的http server指针，（2）address为待绑定的ip地址，（3）port为待绑定的端口号，

	结果：0表示绑定成功，-1表示绑定失败。

	注：跟此函数类似的一个函数为evhttp_bind_socket_with_handle，其声明是struct evhttp_bound_socket *evhttp_bind_socket_with_handle(struct evhttp *http, const char *address, ev_uint16_t port); 与evhttp_bind_socket唯一不同的地方是返回值不同，它返回了一个socket句柄。



	3. evhttp_accept_socket

	声明：int evhttp_accept_socket(struct evhttp *http, evutil_socket_t fd);

	用途：使http server可以接受来自指定的socket的连接，可重复调用来绑定到不同的socket，

	参数：（1）http为待绑定的http server指针，（2）fd为待绑定的socket（该socket应已准备好接受连接），

	结果：0表示成功，-1表示失败。

	注：跟此函数类似的一个函数为evhttp_accept_socket_with_handle，其声明是struct evhttp_bound_socket *evhttp_accept_socket_with_handle(struct evhttp *http, evutil_socket_t fd); 与evhttp_accept_socket唯一不同的地方是返回值不同，它返回了一个socket句柄。



	4. evhttp_uri_parse

	声明：struct evhttp_uri *evhttp_uri_parse(const char *source_uri);

	用途：一般必定调用evhttp_uri_parse_with_flags，从而解析uri中的host（即ip地址或者域名）和port，

	参数：source_uri为指向uri的字符指针。

	注：uri指统一资源标识符，是一个抽象概念，而url是一个具体的概念，可以根据url找到网上资源。具体可参考：https://www.zhihu.com/question/21950864

	结果指针释放：evhttp_uri_free



	5. evhttp_connection_base_new

	声明：struct evhttp_connection *evhttp_connection_base_new(
	struct event_base *base, struct evdns_base *dnsbase,
	const char *address, unsigned short port);

	用途：用于创建http请求的连接对象，即当连接对象con_obj得到了一个http request时，会主动解析address，并与之建立连接。

	参数：（1）base，用于处理连接事件，（2）dnsbase，用于解析host names，一般为NULL值，（3）address，需要建立连接的对端ip地址，（4）port，需要建立连接的对端端口号

	结果指针释放：evhttp_connection_free



	6. evhttp_set_timeout

	声明：void evhttp_set_timeout(struct evhttp *http, int timeout_in_secs);

	用途：为一个http请求设置超时时间，

	参数：（1）http，http server指针，（2）timeout_in_secs，以秒为单位



	7. evhttp_request_new

	声明：struct evhttp_request *evhttp_request_new(void (*cb)(struct evhttp_request *, void *), void *arg);

	用途：用于创建一个http请求，该请求的内容未初始化，创建完后需立即填充（参考evhttp_add_header），

	参数：（1）cb，为回调函数，当http 请求完成后（发送到对端成功，或者出现错误）被调用，（2）arg为任意需要在cb中使用的参数。

	结果指针释放：evhttp_request_free



	8. evhttp_add_header

	声明：int evhttp_add_header(struct evkeyvalq *headers, const char *key, const char *);

	用途：为已存在的http请求头部添加另外的头部，

	参数：（1）headers，为http请求的output_headers，（2）key，为headers的名字，（3）value，为headers的值。

	结果：0表示成功，-1表示失败



	9. evhttp_make_request

	声明：int evhttp_make_request(struct evhttp_connection *evcon,   struct evhttp_request *req,    enum evhttp_cmd_type type, const char *uri);

	用途：为指定的一个连接创建一个http请求，这个连接属于该http请求对象req，连接失败时，req不再有效，该指针已经被释放了，

	参数：（1）evcon， http连接，（2）req，已经创建好并已配置好的http请求，（3）type，该http请求的类型，EVHTTP_REQ_GET、EVHTTP_REQ_POST等

	（4）uri，与该http请求相对应

	结果：0表示成功，-1表示失败

	注：需要取消http请求，可参考evhttp_cancel_request
	
	10.然后你可以注册一个或者多个回调函数来处理收到的请求。可以通过函数 evhttp_set_cb() 为每一个 URI 指定一个回调函数。
	
}

{基本流程

	http服务端使用到的借口函数及流程如下

	创建event_base和evhttp
	struct event_base *event_base_new(void);
	struct evhttp *evhttp_new(struct event_base *base);
	
	绑定地址和端口
	int evhttp_bind_socket(struct evhttp *http, const char *address, ev_uint16_t port);
	
	设置处理函数
	void evhttp_set_gencb(struct evhttp *http,
	void (*cb)(struct evhttp_request *, void *), void *arg);
	
	派发事件循环
	int event_base_dispatch(struct event_base *);

}

