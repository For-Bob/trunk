参考：http://doc.qt.io/qt-5/qt3d-index.html		官网

疑难问题：1.QT Creater 运行不了提示 存储空间不足,无法处理此命令。无法加载****.dll,把qrc里面的资源文件分一些到新建的qrc文件里面去
			2.板子上无法运行，pc可以运用，将所有动态库都复制到板子上去
概念：　矢量：既有大小又有方向的量,如速度、 加速度、力、位移.一般来说,在物理学中称作矢量,在数学中称作向量.
　　	标量亦称“无向量”.有些物理量,只具有数值大小,而没有方向.这些量之间的运算遵循一般的代数法则,称做“标量”.如质量、密度、温度、功、能量、路程
		、速率、体积、时间、热量、电阻、功率、势能、引力势能、电势能等物理量.
		
		向量就是矢量,只不过向量是数学上表示的,
		矢量是物理上表示的!标量是只有大小而没有方向的!向量是既有大小又有方向的!
			
{qt 3d
	{例子说明
		multiviewport //多镜头
	}
	
	The functionality in Qt 3D is divided into the following C++ modules:
	{C++模块
		pro文件加上 QT += 3dcore 3drender 3dinput 3dlogic 3dextras 3danimation
		功能模块		
			Qt3DCore	Qt 3D module contains functionality to support near-realtime simulation systems
			Qt3DCore	Qt 3D 模块包含支持近实时仿真系统
			
			Qt3DInput	Qt 3D Input module provides classes for handling user input in applications using Qt3D
			Qt3DInput	Qt 3D 输入模块提供了处理用户在Qt3D应用中输入的类
			
			Qt3DLogic	Qt 3D Logic module enables synchronizing frames with the Qt 3D backend
			Qt3DLogic	Qt 3D 逻辑模块使帧和后端同步
			
			Qt3DRenderQt 3D Render module contains functionality to support 2D and 3D rendering using Qt 3D
			Qt3DRender	Qt 3D 渲染模块在使用Qt 3D包含支持2D和3D渲染
		开发阶段的模块
			Qt3DAnimation	Qt 3D Animation modules provides a set of prebuilt elements to help you get started with Qt 3D
			Qt3DExtras		Qt 3D Extras module provides a set of prebuilt elements to help you get started with Qt 3D
			Qt3DScene2D		Qt 3D Scene2D module provides a way to render Quick2 qml content to a Qt 3D texture	
	}
	
	For Qt Quick applications, Qt 3D provides the following QML modules:
	{QML模块
		pro文件加上 QT += 3dcore 3drender 3dinput 3dlogic 3dextras qml quick 3dquick 3danimation
		功能模块
			Qt3D.Core	Provides core Qt 3D QML types
			Qt3D.Core	提供Qt 3D核心的的QML类型
			
			Qt3D.Input	Provides QML types for Qt 3D user input
			Qt3D.Input	提供Qt 3D的用户输入的QML类型
			
			Qt3D.Logic	Provides QML types to synchronize frames with the 3D backend
			Qt3D.Logic 	提供帧和后端的同步的QML类型
			
			Qt3D.Render	Provides Qt 3D QML types for rendering
			Qt3D.Render	提供Qt 3D的QML类型的渲染
	}
	
	{Qt 3D概述
		Qt 3D提供了一个完整的配置渲染使开发者能够快速完成任何渲染管道(管线)。再者，Qt 3D提供了一套通用的接近实时的且优于渲染模拟框架。
		Qt 3D是划分为一部分核心很多aspicts是开发者实现的任意功能。aspect与components以eneities交互提供了部分功能。
			aspect的例子包含physics,audio,collision，artificial intelligence(AI)，和路径寻找。
	}
	
	{ 3D 的基本特点
		Qt 3D是一个3D框架能够画3D形状和移动它们的，其实就是移动camera。它支持以下基本的特点：
			C++与Qt Quick应用的2D和3D的渲染。
			Meshes (网格)
			Materials(素材)
			Shaders(着色器)
			Shaow mapping(阴影映射)
			Ambient occlusion (环境光遮蔽;环境光吸收;环境遮挡;环境闭塞) //TM的我也不知道怎么翻译了
			High dynamic range(高动态范围)
			Deferred rendering(延迟渲染)
			Multitexturing(纹理化)
			Instanced rendering(实例化渲染)
			Uniform Buffer Objects(统一缓冲对象)
			
		Materials(素材)
			Qt 3D拥有稳定和灵活的素材系统运行多功能的定制化。提供了不同渲染的方式来适应不同的平台或是OpenGl版本，通过不同状态设置使能多种渲染，
			提供不同层次上重写参数机制，轻易的切换着色器。所有素材的都是出自C++或者QML的binding属性。
			
	}
	
	{QML 3D
		参考：http://doc.qt.io/qt-5/qmltypes.html //很多都是官网翻译过来的，感觉有困惑就去官网看
			http://doc.qt.io/qt-5/qt3d-qml.html //3d
			
		3d的坐标解释：x: 左右 y:高低 z: 远近
		
		通常3D模型，具有camera ，Entity(Transfrom:用来动作变换; Material:用于着色处理; Mesh:3D模型)
		
		AbstractActionInput {
			详细描述：
				Action Input和所有Aggregate(集合) Action Inputs的基类
		}
		
		{AbstractAxisInput 
			自己描述：所有包含AxisInput的基类
			属性：
				sourceDevice : AbstractPhysicalDevice
		}
		
		AbstractPhysicalDevice {
			详细描述：
				这个基类用于Qt3d 与输入设备的任意输入的交互
		}
		
		
		Action{
			详细描述：
				关联触发相同事件的一套 AbstractActionInput
			属性：
				action : bool
				inputs : list<AbstractActionInput>	//一套AbstractActionInput必须是触发到这个Action的触发器
		}
			
		ActionInput {
			详细描述：
				关联一套物理设备(比如键盘)和按钮可以出发这个动作。源设备的一个或多个按钮都可以出发每一个Action input
				
			属性：
				buttons : list<int>						//Button可以出发这个Action
				sourceDevice : AbstractPhysicalDevice	//ActioinInput的源设备
			
			信号：
				buttonsChanged(const QVector<int> &buttons)	//关联按钮的输入动作发生变化，这个信号就会发射，槽函数onbuttonsChanged
				sourceDeviceChanged()						//关联源设备的输入动作发生变化这个信号就会发射，槽函数onSourceDeviceChanged
				
		}			
		
		AnalogAxisInput{
			属性：
				axis : int			//保存AnalogAxisInput的axis
		}
		
		Annotation //注释
		{			
			Inherits:Node
			name : string
			value : variant 
		}
		
		Axis(轴，x，y，z){
			详细描述：
				关联一组AbstractAxisInputs用于触发相同的事件
			
			属性：
				buttons : QVariantList				//Buttons可以触发这个Action
				inputs : list<AbstractAxisInput>	//AbstractAxisInput的列表里面的可以触发这个Axis。
				scale : real						//累加时scale轴值得数量，可以被认为是最大的速率或者是轴线可以控制的加速度
				value : int							//保存来自sourceAxis的累加值
				velocity : real
					//返回velocity（速率）。如果sourceAxisType设置Velocity 这个是通过scale乘源axis的值。
					//如果sourceAxisType设置Acceleration，velocity是整型值用于源axis加速度的值
		}
		
		{Entity(实体)
			Entity是一个Node的一个子类具有聚合几个Component3D实例并且指定它的行为。
			描述：Entity本身就是一个空壳。Entity对象的行为是由它引用的组件3D对象定义的。每个QT3D后端方面将会解释和处理一个Entity，通过识别它是由哪些组件组成的。
				一个方面可以决定只处理由单个变换组件组成的Entity，而另一个可以专注于MouseHandler。
			enabled: bool	//用于模型是否显示
			属性：
				components : list<Component3D> //保存Component3D的实例并且定义了entity的行为。
		}
		
		{FirstPersonCameraController
			详细描述：
				FirstPersonCameraController允许第一人视觉控制显示屏
			属性：				
				acceleration : real		//加速度，移动镜头的速率，按键按下移动
				camera : Camera			//当前控制的相机
				deceleration : real		//减速度，移动镜头的速率，按键松开移动
				linearSpeed : real		//速率
				lookSpeed : real 		//观察速度，外观速度决定相机平移和倾斜的转弯速率
		}
		
		FrameAction {
			提供让函数同步执行每个帧的方法
			详细描述：
				FrameAction提供了每帧执行同步任务在Qt3D后端。实现一些程序的逻辑方面和函数原型可以合成一个Qt3D附加的方面
				比如，FrameAction可用于使属性与Qt3D引擎同步，其中Qt Quick动画元素没有完全同步，在某些情况下可能导致卡顿。
			
			信号：
				triggered(real dt)	//这个信号被发射到每一帧。
									//槽函数
		}
		
		{FrameGraph
			属性:
				activeFrameGraph : FrameGraphNode //根节点
		}
			
		{TechniqueFilter 
			描述：TechniqueFilter指定当绘制图形体时在FrameGraph使用哪种技术。TechniqueFilter指定了FilterKey对象和Parameter对象的列表。
				当TechniqueFilter是存在与FrameGraph，只有techiques匹配列表中keys会被呈现。parameters的list参数可以用来设置着色器的parameters。
				通过Technique 和 RenderPass里面的parameters重写 TechniqueFilter里面的parameters
			
			属性：
				matchAll : list<FilterKey>
				parameters : list<Parameter>		
		}
		
		{Viewport(显示点)
			描述：场景的Viewport指定了QT3D显示面由哪个部分显示。viewport之外的区域未被触动。它还控制全局参数，如viewport中的gamma渲染。
			
			属性：
				gamma : rect //默认值2.2
				normalizedRect : rect //默认值[0.0,0.0,1.0,1.0]		
		}
		
		{CameraSelector
			描述：CameraSelector能够用于选择相机，当FarmeGraph画图像体的时候使用
			
			属性：
				camera:Entity	//保存当前选定的camera。		
		}
		
		{ClearBuffers //清空缓冲区
			描述：Qt3DRender::QClearBuffers FrameGraph的节点能够通过指定的值清除指定的显示目标缓冲。
			
			属性：
				buffers : enumeration
				clearDepthValue : real	//深度
				clearStencilValue : int	//模型
				color : color
				colorbuffer : RenderTargetOutput		
		}
		
		{Camera   
		定义通过视图显示的视图点
		属性：
			aspectRatio : real 				//宽高比
			bottom : real					//底部
			farPlane : real					//最远可以看的平面，超过就看不见
			fieldOfView : real				//camera视界，也就是视野范围宽度
			left : real						//左
			nearPlane : real				//最近可以看的平面，小于这个就看不见
			position : vector3d				//位置 ，vector3d:就是，x,y,z轴的坐标
											//x：左右,y：高低,z：远近，不管位置在哪都向中心点看去
			
			
			
			projectionMatrix : matrix4x4	//投影矩阵,matrix4x4：就是4*4的矩阵数据
			projectionType : enumeration	//投影类型，
				CameraLens.OrthographicProjection	//正交投影
				CameraLens.PerspectiveProjection	//透视投影
				CameraLens.FrustumProjection		//截锥投影
				CameraLens.CustomProjection			//自定义投影
			right : real					//右
			top : real						//顶部
			upVector : vector3d				//在相对于父实体的坐标中保存镜头向上的矢量坐标。一般正常值 Qt.vector3d( 0.0, 1.0, 0.0 ),如果要镜头一直保持一个角度，那么在改变镜头角度的时候，upVector的，x，y，z要赋值
			viewCenter : vector3d			//将相机的当前视图中心保持在相对于父entity的坐标中。 //保持镜头一直保持往某一点望去
			viewVector : vector3d			//在相对于父entity的坐标中保存相机的视图矢量。	
			
		方法
			//感觉像是x抽正方向的平移
			void pan(real angle, vector3d axis)					//以axis以上angle为单位调整camera中心周围的视盘中心。
			void pan(real angle)								//调整camera的angle角度。感觉像是x抽正方向的平移
			
			//围绕模型转圈
			void panAboutViewCenter(real angle, vector3d axis)	//调整camera镜头在中心视图通过在axis(轴线)上angele度
			void panAboutViewCenter(real angle)					//调整camera镜头在中心视图通过在angele度
			
			quaternion panRotation(real angle)					//返回计算得到的相对于angle的平移旋转，以调整相机的平移或Y轴上的左/右旋转的角度表示。
				quaternion：scalar, x, y, and z attributes.
				四元数：标量，x,y,z属性
			
			void roll(real angle)								//调整carmea滚动通过angle度
			void rollAboutViewCenter(real angle)				//调整camera视图中心的滚动通过angle度
			quaternion rollRotation(real angle)					//返回所计算的相对于angle的滚动旋转，以调整相机的滚动或Z轴上的左/右倾斜旋转。
			void rotate(quaternion q)							//用quaternion类型的q旋转camera的中心视图						
			void rotateAboutViewCenter(quaternion q)			//Rotates the camera about the view center with the use of a Quaternion in q.
											//用quaternion类型的q旋转camera的中心视图的周边	
			quaternion rotation(real angle, vector3d axis)		//返回计算angle角度和选择axis的旋转
			void tilt(real angle)								//通过angle度调整camera的tilt(倾斜)角度
			void tiltAboutViewCenter(real angle)				//通过angle角度调整camera关于中心视觉的tilt(倾斜)角度
			quaternion tiltRotation(real angle)					//返回计算tilt(倾斜)角度与angele度调整camera的tilt或者是在X抽上下转动的关联
			void translate(vector3d vLocal, enumeration option)	//通过本地坐标vLocal变化camera的位置和视觉向量，
											//option允许中心视觉是否要变换
											//Camera.TranslateViewCenter		变换视图中心导致视图方向保持一致
											//Camera.DontTranslateViewCenter	不变换视图中心导致视图方向改变											

			void translateWorld(vector3d vWorld, enumeration option)	//变换camera的位置和视图向量通过vWorld坐标，
											//option允许切换时视图中心是否要变换
											//Camera.TranslateViewCenter		变换视图中心导致视图方向保持一致
											//Camera.DontTranslateViewCenter	不变换视图中心导致视图方向改变	
			void viewAll()										//转动和移动camera以便它的 viewCenter是场景的包围体的中心，整个场景适合于视口。
						//只有lens工作在 perspective projection模式
			void viewEntity(Entity entity)						//转动和移动camera以便它的 viewCenter是场景的包围体的中心，整个场景适合于视口。
						//只有lens工作在 perspective projection模式
			void viewSphere(vector3d center, real radius)		//转动和移动camera以便它的viewCenter是center，一个半径球适视口。
		}

		{Configuration
			属性：
				controlledCamera : CameraCamera 
		}
		
		{CuboidMesh 方形体模型
			属性：
				xExtent : real					//保存x的长度
				xyMeshResolution : size			//保存x-y分辨率。x-y面菱角的数量
				xzMeshResolution : size			//保存x-z分辨率。x-z面菱角的数量
				yExtent : real					//保存y的长度
				yzMeshResolution : size			//保存y-z分辨率。y-z面菱角的数量
				zExtent : real					//保存z的长度
		}
		
		{CylinderMesh  圆柱体模型
			属性：
				length : real	//长度
				radius : real	//半径
				rings : int		//环数
				slices : int	//切片数
		}
		
		{ForwardRenderer
			ForwardRenderer提供了一个默认的FrameGraph向前的渲染器的实现。
			属性:
				camera : Entity			//保存当前用于屏幕渲染的camera的entity
				clearColor : color		//保存当前屏幕的清除色。在渲染之前帧缓存是被初始化用于清除色。
				frustumCulling : bool	//表明可视平截头体的裁剪是否应用于当前屏幕
				gamma : real			//保存渲染器gamma值应用于屏幕
				surface : Object		//保存当前渲染器得surface的值
				viewportRect : rect		//保存当前标准化的矩形观察窗
		}		
		
		{LayerFilter 
			详细描述：
				LayerFilter用于指导渲染器作为画frame图的一部分的层。LayerFilter选择entities作画在Layer上并作为Entity的组件添加在LayerFilter。
				LayerFilterA可以被配置为根据filterMode属性选择或丢弃具有特定层的entities。默认情况下，
			
			属性：
				filterMode : enumeration		//保存过滤器模式指定entities选择何种方式作画
					//默认值是LayerFilter.AcceptMatchingLayers.
					LayerFilter.AcceptAnyMatchingLayers		接受entities引用一个或者多个Layer对象添加到LayerFilter。
					LayerFilter.AcceptAllMatchingLayers		接受entities引用所有的Layer对象添加到LayerFilter。
					LayerFilter.DiscardAnyMatchingLayers	丢弃的entities引用一个或者多个Layer对象添加到LayerFilter。
					LayerFilter.DiscardAllMatchingLayers	丢弃的entities引用所有的Layer对象添加到LayerFilter。				
				
				layers : list<Layer>	//保存layers的列表用于指定选择作画在layers上。
		}
		
		{KeyEvent
			详细描述：
				KeyEvent类型不能直接创建，它被用于KeyboardHandler的信号参数
			属性：
				accepted : bool
				count : int
				isAutoRepeat : bool
				key : int
				modifiers : int
				nativeScanCode : quint32
				text : string
		}
		
		{KeyboardController
			属性：
				activeInput : KeyboardInput 
		}
		
		{KeyboardInput
			//QML的官方例子：keyboardinput
			属性：					
				controller : KeyboardController
				focus : bool
			信号：				
				void asteriskPressed(KeyEvent event)
				void backPressed(KeyEvent event)
				void backtabPressed(KeyEvent event)
				void backtabPressed(KeyEvent event)
				void callPressed(KeyEvent event)
				void cancelPressed(KeyEvent event)
				void context1Pressed(KeyEvent event)
				void context2Pressed(KeyEvent event)
				void context3Pressed(KeyEvent event)
				void context4Pressed(KeyEvent event)
				void deletePressed(KeyEvent event)
				void digit0Pressed(KeyEvent event)
				void digit1Pressed(KeyEvent event)
				void digit2Pressed(KeyEvent event)
				void digit3Pressed(KeyEvent event)
				void digit4Pressed(KeyEvent event)
				void digit5Pressed(KeyEvent event)
				void digit6Pressed(KeyEvent event)
				void digit7Pressed(KeyEvent event)
				void digit8Pressed(KeyEvent event)
				void digit9Pressed(KeyEvent event)
				void downPressed(KeyEvent event)
				void enterPressed(KeyEvent event)
				void escapePressed(KeyEvent event)
				void flipPressed(KeyEvent event)
				void hangupPressed(KeyEvent event)
				void leftPressed(KeyEvent event)
				void menuPressed(KeyEvent event)
				void noPressed(KeyEvent event)
				void numberSignPressed(KeyEvent event)
				void pressed(KeyEvent event)
				void released(KeyEvent event)
				void returnPressed(KeyEvent event)
				void rightPressed(KeyEvent event)
				void selectPressed(KeyEvent event)
				void spacePressed(KeyEvent event)
				void tabPressed(KeyEvent event)
				void upPressed(KeyEvent event)
				void volumeDownPressed(KeyEvent event)
				void volumeUpPressed(KeyEvent event)
				void yesPressed(KeyEvent event) 
		}
		
		{InputSettings	//不加这个鼠标和键盘无响应
			InputSettings保存了指向输入时间源对象的指针
			详细描述：
				InputSettings组件必须设置为scene的根entity的组件。它存储一个指向输入源(各种各样的输入类)动作的指针
			属性：				
				eventSource : Object 	//保存当前事件源。事件源是一个对象能够接收不同的输入事件，比如鼠标和键盘事件。典型的它是窗口实例。
				
				
		}
		
		{LogicalDevice 
			详细描述：
				允许用户在自己的应用程序里面定义自己希望的动作。
			属性：
				actions : list<Action>	//	用于Logic Device的动作
				axis : list<Axis>		//	用于Logic Device的的各轴线
		}
		
		{MouseInput
		}
		
		{MouseController
		}
		{RenderPassFilter 
			提供了保存vectors的Filter Keys和Parameters。
			详细描述：
				RenderPassFilter FrameGraph节点用于选择哪个RenderPass对象用来作画。当RenderPassFilter在FrameGraph里面，只有
			属性：
				matchAny : list<FilterKey>
				parameters : list<Parameter>
			
		}
		
		{RenderSettings 
			RenderSettings类型保存设置渲染处理和主的有效的FrameGraph相关的。
			属性：
				activeFrameGraph : FrameGraphNode	//保存当前有效的FrameGraph。
				pickingSettings : PickingSettings	//保存FrameGraph的当前的选取设置。
				renderPolicy : enumeration			//保存当前渲染规则
					//RenderSettings.OnDemand		当事件发生改变时FrameGraph才会渲染
					//RenderSettings.Always			FrameGraph一直不停的渲染
		}		
		
		{Scene3D
			Scene3D类型用于将Qt3D集成到QtQuick2dD里面
			详细描述：
				Scene3D类型呈现Qt3D显示，通过Entity提供到多采样的Framebuffer类。
				This object is later blitted into a non-multisampled Framebuffer object, which is then rendered with premultiplied alpha.
				该对象随后被转换成非多采样帧缓冲对象，然后用预乘α来渲染。
				
			属性：
				aspects : list<string>	//通常是"input"，这样屏幕才能接受鼠标和键盘事件
				cameraAspectRatioMode : enumeration
					Scene3D.AutomaticAspectRatio	自动宽高比
					Scene3D.UserAspectRatio			自动宽高比
				entity : Entity
				hoverEnabled : bool					鼠标悬停事件被接收了就返回true
				multisample : bool					多采样呈现缓冲在使用就返回true
				
			方法：
				void setItemAreaAndDevicePixelRatio(size area, real devicePixelRatio)
		}
		
		{SphereMesh 球型模型
			属性：
				generateTangents : bool		
				radius : real				半径
				rings : int					环数
				slices : int				切片数量
		}
		
		{Transform
			
			用于在模型上执行动作变换 ：比如平移角度偏移旋转，平移加旋转可以做到模型在模型上上任一一点上的旋转
			
			//欧拉角Eulerian angles用来确定定点转动物体位置的3个一组独立角参量
			属性：
				matrix : matrix4x4		//4*4矩阵
					//当matrix被设置，它被分解为平移，旋转，缩放
			matrix: {
				var m = Qt.matrix4x4();
				m.translate(Qt.vector3d(Math.sin(angle * Math.PI / 180) * scaleFactor,
										altitude,
										Math.cos(angle * Math.PI / 180) * scaleFactor));
				m.rotate(angle, Qt.vector3d(0, 1, 0));  //水平面旋转(车祸车子路上那种) 0 1 0
				m.rotate(angle, Qt.vector3d(1, 0, 0));  //(旋风冲锋龙卷风；螺旋桨)旋转 1 0 0
				m.rotate(angle, Qt.vector3d(0, 0, 1));  //(只有飞机能做的)旋转 1 0 0
				m.scale(1.0/scaleFactor);				//缩放	
				return m;
			}
				
				rotation : quaternion	//变换的旋转
				rotationX : real		//X轴旋转的欧拉角	旋风冲锋龙卷风；螺旋桨
				rotationY : real		//Y轴旋转的欧拉角	水平面旋转(车祸车子路上那种)
				rotationZ : real		//Z轴旋转的欧拉角	(只有飞机能做的)
				scale : real			//缩放，如果标度设置为scale3D，只保存X的值
				scale3D : vector3d		//缩放
				translation : vector3d	//位置平移变换
				
			方法：
				quaternion fromAxesAndAngles(vector3d axis1, real angle1, vector3d axis2, real angle2, vector3d axis3, real angle3)
				quaternion fromAxesAndAngles(vector3d axis1, real angle1, vector3d axis2, real angle2)
				quaternion fromAxisAndAngle(real x, real y, real z, real angle)
				quaternion fromAxisAndAngle(vector3d axis, real angle)
				quaternion fromEulerAngles(real pitch, real yaw, real roll)
				quaternion fromEulerAngles(vector3d eulerAngles)
				matrix4x4 rotateAround(vector3d point, real angle, vector3d axis)
		}
		
		{TorusMesh 环形体的模型
			属性：
				minorRadius : real 内半径
				radius : real		外半径
				rings : int			环数
				slices : int		切片数量
		}

		{PlaneMesh 
			A square planar mesh
			方形平面模型
			
			属性：
				height : real			//平面高度
				meshResolution : size	//保持平面分辨率。此属性的宽度和高度值指定模型在各个维度上生成的顶点的数量。
				mirrored : bool			//控制平面的UV坐标是否应该垂直翻转。
				width : real			//平面宽度
		}
		
		{Mesh
			用于加载模型实体
			属性：			
				source : url	//模型文件位置
				meshName : string	
					//符合要求的模型将被加载
					//如果meshName为空，整个模型都会被加载
					//如果meshName是普通字符串，只有匹配上mesh名字的，才会被加载
					//如果meshName是正则表达式，所有匹配上的都会被加载
				status : enumeration	//
					//Qt3DRender::QMesh::None		模型还没有分配
					//Qt3DRender::QMesh::Loading	模型正在加载
					//Qt3DRender::QMesh::Ready		模型以成功加载
					//Qt3DRender::QMesh::Error		模型在加载时发生错误
		}
		
		{NodeInstantiator 
			动态创建节点
			属性：
				active : bool							//当active是true，delegate组件就准备了，Instantiator将会根据model创建类。
														//当active是false，没有类会被创建，之前创建的类也会被销毁。
				asynchronous : bool						//当asynchronous是true，组件将会异步创建类。这意味着类不会马上生效，即使active被设置为true。
										//你可以使用objectAdded信号响应items正在被创建。
										//默认asynchronous是false。
				count : int								//Instantiator类的数量正在被管理
				delegate : QtQml::Component				//组件用于创建所有的类对象
										//注意在一个实例化的delegate内variable，index将是有效的，这个variable提供了在组件内例子的索引，
										//通过Instantiator的itemAt方法可以用于获取类
										//如果这个属性改变了，所有用于旧delegate的实例都将会被销毁，所有将创建的实例都会用心的delegate。
				model : variant							//这个属性可以用来支持任何的数据models：
										//通过repeater创建一个数代表delegates的数，A number
										//一个模型(比如：一个ListModel项目或者一个QAbstractItemModel子类)，A model
										//A string list
										//An object list
										//模型的类型的属性将暴露给delegate
										//默认值是1，创建一个delegate的实例
				object : QtQml::QtObject				//第一个创建引用的类，为仅创建一个对象的情况而设为方便
				
			Signals
				objectAdded(int index, QtObject object)
					//当在NodeInstantiator上增加一个节点，这个信号就会触发。index参数保存索引，objcect参数保存增加的Node.
						//槽函数是：onNodeAdded
				objectRemoved(int index, QtObject object)
					//当在Instantiator移除一个节点，这个信号就会触发。index参数是移除的索引，object参数保存移除的QtObject。
					//不要保存object的引用如果它是Instantiator创建的，类对象会立刻删除在信号被处理
					//槽函数是：onObjectRemove.
				
			方法：
				QtQml::QtObject objectAt(int index)	//返回标签对应的对象的引用
		}
	}
	
	Light{在Qt 3D场景中封装QAbstractLight对象，
		属性：
			color : QColor		颜色
			intensity : float	强度
			type : const Type
					Qt3DRender::QAbstractLight::PointLight			0
					Qt3DRender::QAbstractLight::DirectionalLight	1
					Qt3DRender::QAbstractLight::SpotLight			2
		{PointLight 点光源			//QML都是集成C++里面的Q****
			属性：
				color : QColor		颜色
				intensity : float	强度			
				constantAttenuation : float		指定点光源的恒定衰减
				linearAttenuation : float		指定点光源的线性衰减
				quadraticAttenuation : float	指定点光源的二次方衰减			
		}
		{EnvironmentLight 环境灯 这个的父类不是Light
			Encapsulate an environment light object in a Qt 3D scene	在qt 3d场景中形成环境光对象
			属性：
				irradiance : Texture
					Holds the current environment irradiance map texture.	保存当前环境光的绘制纹理
				
				specular : Texture
					Holds the current environment specular map texture.	保存当前镜面关的绘制纹理
					
		
		}
		
		{DirectionalLight 平行光
			在qt 3d场景中封装定向光对象			
			属性：
				worldDirection : vector3d 		指定平行光的域方向
				color : QColor		颜色
				intensity : float	强度		
		}
		
		{SpotLight 	
			在qt 3d场景中封装光斑对象		
			属性：
				constantAttenuation : float		指定光斑的恒定衰减
				cutOffAngle : float				指定光斑的遮光角
				linearAttenuation : float		指定光斑的线性衰减
				localDirection : vector3d		指定光斑的局部坐标
				quadraticAttenuation : float	指定光斑的二次方衰减		
		}
	}
	
	{Texture一般都是用TextureLoader	
		{QAbstractTexture
			这个基类用于提供材质
			公共类型：
				enum	CubeMapFace
							CubeMapPositiveX, 	指定模型映射的正X面
							CubeMapNegativeX, 	指定模型映射的负X面
							CubeMapPositiveY,	指定模型映射的正Y面
							CubeMapNegativeY,	指定模型映射的负Y面
							CubeMapPositiveZ	指定模型映射的正Z面
							CubeMapNegativeZ, 	指定模型映射的负Z面
							AllFaces			所有面
				enum	Filter	保存过滤类型
							Nearest, 				最近的	
							Linear,					线性的
							NearestMipMapNearest, 	最近的纹理映射最近
							NearestMipMapLinear, 	最近的线性纹理映射
							LinearMipMapNearest, 	最近的线性纹理映射
							LinearMipMapLinear		线性纹理映射线性
				enum	Status { None, Loading, Ready, Error }	//材质的状态
				enum	Target 							
							TargetAutomatic, 		目标将会决定Qt3D引擎
							Target1D, 				GL_TEXTURE_1D
							Target1DArray,			GL_TEXTURE_1D_ARRAY
							Target2D,				GL_TEXTURE_2D
							Target2DArray			GL_TEXTURE_2D_ARRAY
							Target3D				GL_TEXTURE_3D
							TargetCubeMap			GL_TEXTURE_CUBE_MAP
							TargetCubeMapArray		GL_TEXTURE_CUBE_MAP_ARRAY
							Target2DMultisample		GL_TEXTURE_2D_MULTISAMPLE
							Target2DMultisampleArray	GL_TEXTURE_2D_MULTISAMPLE_ARRAY
							TargetRectangle			GL_TEXTURE_RECTANGLE
							TargetBuffer			GL_TEXTURE_BUFFER
				enum	TextureFormat 	所有材质的格式
							NoFormat,
							Automatic, 
							R8_UNorm, 	RG8_UNorm,		RGBA8_UNorm
							R16_UNorm	RG16_UNorm		RGB16_UNorm			RGBA16_UNorm
							R8_SNorm	RG8_SNorm		RGB8_SNorm			RGBA8_SNorm
							R16_SNorm	RG16_SNorm		RGB16_SNorm			RGBA16_SNorm
							R8U			RG8U			RGB8U				RGBA8U
							R16U		RG16U			RGB16U				RGBA16U
							R32U		RG32U			RGB32U				RGBA32U
							R8I			RG8I			RGB8I				RGBA8I
							R16I		RG16I			RGB16I				RGBA16I
							R32I		RG32I			RGB32I				RGBA32I
							R16F		RG16F			RGB16F				RGBA16F
							R32F		RG32F			RGB32F				RGBA32F
							RGB9E5		RG11B10F		RG3B2				R5G6B5		RGB5A1			RGBA4		RGB10A2
							D16			D24				D24S8				D32			D32F			D32FS8X24
							RGB_DXT1	RGBA_DXT1		RGBA_DXT3			RGBA_DXT5
							R_ATI1N_UNorm	R_ATI1N_SNorm	RG_ATI2N_UNorm	RG_ATI2N_SNorm
							RGB_BP_UNSIGNED_FLOAT		RGB_BP_SIGNED_FLOAT	RGB_BP_UNorm	
							R11_EAC_UNorm	R11_EAC_SNorm	RG11_EAC_UNorm	RG11_EAC_SNorm
							RGB8_ETC2	SRGB8_ETC2
							RGB8_PunchThrough_Alpha1_ETC2	SRGB8_PunchThrough_Alpha1_ETC2
							RGBA8_ETC2_EAC	SRGB8_Alpha8_ETC2_EAC	RGB8_ETC1
							SRGB8		SRGB8_Alpha8	SRGB_DXT1		SRGB_Alpha_DXT1		SRGB_Alpha_DXT3	SRGB_Alpha_DXT5	SRGB_BP_UNorm
							DepthFormat	AlphaFormat		RGBFormat			RGBAFormat	LuminanceFormat	LuminanceAlphaFormat
			属性：
				comparisonFunction : ComparisonFunction
				comparisonMode : ComparisonMode
				depth : int						材质的深度
				format : TextureFormat			材质的格式
				generateMipMaps : bool			材质是否自动产生纹理映射
				handle : const QVariant			材质句柄，如果QT3D是用OPENGL渲染，句柄是一个整形的材质id
				handleType : const HandleType	材质的句柄类型
				height : int					材质的高度
				layers : int					材质最大的层，默认最大值是1
				magnificationFilter : Filter	材质的放大滤波
				maximumAnisotropy : float		材质的最大有向性
				minificationFilter : Filter		材质的缩小滤波
				samples : int					保留纹理提供程序的每个texel的样本数。默认情况下，样本数为1。
				status : const Status			
				target : const Target
				width : int						材质的宽度
				wrapMode : Qt3DRender::QTextureWrapMode* const				
		}
		{TextureLoader 材质载入器 继承QAbstractTexture
			处理载入材质和设置材质的属性
			mirrored : bool		这个属性指定了当材质加载完是否有映射，这是一种避免操作图像以匹配渲染API使用的纹理坐标原点的便利方法。默认值是true，在使用压缩纹理格式时没有效果。
			source:"url"//图像地址
			wrapMode {
				wrapModeX.(Repeat;MirroredRepeat;ClampToEdge;ClampToBorder)//平铺；镜面平铺；压到边；压到边缘
				wrapModeY.(Repeat;MirroredRepeat;ClampToEdge;ClampToBorder)
				wrapModeZ.(Repeat;MirroredRepeat;ClampToEdge;ClampToBorder)
			}			//填充方式
			generateMipMaps： bool //是否自动绘制纹理	
		}
	}
	
	{Effect //效果
		效果类型结合了一组parameters和这些parameters使用的techniques，以生成材质的渲染效果。
		在可能的情况下，应在多个材质实例之间共享一个效果实例。
		属性：
			parameters : list<Parameter>	parameters用于在该效果使用的明暗器中设置相应的统一值。
				Parameter{name : QString
						value : QVariant}
				比如：	Parameter {name: "diffuseColor"; value: "blue"}
						Parameter {name: "diffuseValues[0]"; value: [0.0, 1.0. 2.0, 3.0, 4.0, 883.0, 1340.0, 1584.0]}
			
			techniques : list<Technique>	参数用于在该效果使用的明暗器中设置相应的统一值。
			{Technique	
					filterKeys : list<FilterKey>	指定list的FilterKey用于Techinque。
						{FilterKey
							详细描述：FilterKey用于存储filter的键值对，Filter的key用于Technique和RenderPass指定使用哪一阶段的渲染技术或渲染过程。
							属性：							
								name : string
								value : variant 
						}	
					graphicsApiFilter : GraphicsApiFilter		指定用于图像的过滤器接口
						{GraphicsApiFilter	对于OpenGL标识附加技术所需的API
							属性：								
								api : enumeration												
									OpenGLES	QSurfaceFormat::OpenGLES
									OpenGL		QSurfaceFormat::OpenGL
								extensions : stringlist		//扩展
								majorVersion : int			//主版本
								minorVersion : int			//次版本
								profile : enumeration		//配置文件							
									NoProfile				QSurfaceFormat::NoProfile
									CoreProfile				QSurfaceFormat::CoreProfile
									CompatibilityProfile	QSurfaceFormat::CompatibilityProfile
								vendor : string 			//小贩
						}
					renderPasses : list<RenderPass>
					{RenderPass	
						详细说明：RenderPass指定由技术使用的单个渲染过程（一个明暗器程序执行的实例）。渲染过程由ShaderProgram和FilterKey对象列表、RenderState对象列表和参数对象列表组成									
								当所引用的至少一个RenderPass节点与RenderPassFilter中的任何FilterKey节点匹配或未指定FilterKey节点且FrameGraph中不存在RenderPassFilter时，RenderPass使用给定的RenderState和参数节点执行ShaderProgram。
								如果Renderpass定义了一个参数，那么如果在运行时与通过关联的任何Technique、Effect、Material、Techniquefilter、Renderpassfilter中存在同名参数，则该参数将被重写。这对于定义健全的默认值仍然有用。								
								在渲染时，对于框架图的每个叶节点，通过累积框架图分支中所有Renderstateset节点定义的状态来记录基本渲染状态。每个Renderpass都可以通过指定自己的RenderState节点来重载此基本渲染状态。
							属性：								
								filterKeys : list<FilterKey>								
								parameters : list<Parameter>
								renderStates : list<RenderState>
								shaderProgram : ShaderProgram

					}
					
			}
						
					graphicsApiFilter : GraphicsApiFilter		
					parameters : list<Parameter>
					
	}
	
	
	Material{//材质
		{Material
			不可创建的材质虚基类，用来着色之类的
			详细描述：
				Material提供了一种指定实体呈现的方式。任何方面都可以定义它自己的Material子类型，以便Material可以用来描述视觉元素；
				例如，声音应该从元素反射的方式、表面的温度等等。
				就其本身而言，材料什么也不能做。只有当它引用一个Effect节点时，材料才变得有用。

				在实践中，经常发生的是单个Effect被多个材料成分所引用。这只允许创建效果、技术、传递和着色器一次，同时允许通过添加Parameter实例指定材料。
			
			属性：
				effect : Effect					//指定要与material一起使用的效果。
				parameters : list<Parameter>	//保存material使用的参数列表。
		}
		
		{DiffuseMapMaterial	 漫反射贴图材质
			DiffuseMapMaterial提供了冯氏照明和凹凸效果的默认实现，其中从纹理映射读取漫反射和平面光线成分
			属性：
				ambient : color				//当前环境颜色
				diffuse : TextureImage		//当前的漫反射贴图纹理
				shininess : real			//光亮，值越大，反光就越弱
				specular : color			//平面纹理
				textureScale : real			//当前纹理比例， 1： textureScale的值
		}
	
		{NormalDiffuseSpecularMapMaterial 	普通漫反射镜面反射贴图材质
			NormalDiffuseSpecularMapMaterial 提供了冯氏照明和凹凸效果的默认实现，其中从纹理映射读取漫反射和平面光线成分，模型的正交线由普通纹理映射绘制。
			属性：
				ambient : color				//当前环境颜色
				diffuse : TextureImage		//当前的漫反射贴图纹理
				normal : TextureImage		//当前正交线贴图纹理
				shininess : real			//光亮程度，值越大，反光就越强
				specular : TextureImage		//平面纹理
				textureScale : real			//当前纹理比例， 1： textureScale的值
		}
		
		DiffuseSpecularMapMaterial{		漫反射镜面贴图材质
			DiffuseSpecularMapMaterial 提供了冯氏照明的默认实现，其中漫反射和镜面反射都是从图片纹理读取
			ambient : color				环境色
			diffuse : TextureImage		漫反射贴图
			shininess : real			光亮值
			specular : TextureImage		镜面贴图
			textureScale : real 		放大和缩小系数
		}
		
		GoochMaterial{				古奇	
			GoochMaterial提供用于古奇的着色模型的材质，广泛应用CAD和CAM应用。
			Gooch 布光模型用颜色和光亮来显示3D的曲面，这通常比仅依赖亮度变化的Phong等模型要好。在CAD和CAM的高精度照片场景下不是目的，Gooch底纹模型与暗色轮廓边缘是一种流行的解决方案。
			详细的解释：http://users.cs.northwestern.edu/~ago820/SIG98/abstract.html
			alpha : real				α值		gooch明暗器使用的颜色渐变的起点计算为c=cool+alpha*diffuse。
			beta : real					β值
			cool : color			冷色
			diffuse : color				漫反射色
			shininess : real			光亮值	亮度值越高，亮显越小
			specular : color			镜面色
			warm : color 			暖色
		}	
		
		TexturedMetalRoughMaterial{	 	纹理金属粗糙加工材料
			TexturedMetalRoughMaterial提供了一个默认PBR光亮的实现方式,环境映射和凹凸效果都是从图片纹理组件获取
			
			baseColor:Texture		基色的贴图
			metalness:Texture		金属性贴图
			roughness:Texture		粗糙的贴图
			normal:Texture			正常的贴图
			ambientOcclusion:Texture	周围环境的贴图
			PBR:PBR即基于物理的渲染，是一套尝试基于真实世界光照物理模型的渲染技术合集，使用了一种更符合物理学规律的方式来模拟光线，达到
				更真实的渲染效果，而且可以直接通过物理参数来直观地达到想要的结果，不用通过拙劣的各种参数调整。物理参数一般直接通过贴图来传递
				给Shader。   
		}
		
		MetalRoughMaterial{		//金属粗加工材料	
			baseColor : QColor				基色
			metalness : float				金属性			//值越大，金属感越强
			roughness : float				粗糙度			//值越小，越能体现金属感
		}
		
		NormalDiffuseMapAlphaMaterial{		法线漫反射贴图Alpha材质
			NormalDiffuseMapAlphaMaterial提供了比NormalDiffuseMapMaterial的更细化，并在渲染过程中进行了alpha覆盖和深度测试。
			详细说明：高光照明效果基于环境光、漫反射光和高光3个照明组件的组合。这些组分的相对强度由其反射率系数控制，该系数
						被建模为RGB三联体：

			ambient : color					环境色		环境光是物体在没有任何其他光源的情况下发出的颜色。
			diffuse : TextureImage			漫反射贴图	漫反射是为使用灯光进行粗糙表面反射而发射的颜色。
			normal : TextureImage			正常的贴图	
			shininess : real				光亮值			表面的光泽度由一个浮动属性控制。
			specular : color				镜面色			“镜面反射”是为灯光的闪亮表面反射而发射的颜色。
			textureScale : real 			放大和缩小系数
		}
		
		NormalDiffuseMapMaterial{		普通漫反射贴图材质
			NormalDiffuseMapmMaterial提供了Phong照明和凹凸效果的默认实现，其中漫反射灯光组件是从纹理贴图读取的，网格的法
			线是从正常纹理贴图渲染的。
			
			详细说明：高光照明效果基于环境光、漫反射光和高光3个照明组件的组合。这些组分的相对强度由其反射率系数控制，该系数被建模为RGB三
							联体：

			ambient : color					环境色		环境光是物体在没有任何其他光源的情况下发出的颜色。
			diffuse : TextureImage			漫反射贴图	漫反射是为使用灯光进行粗糙表面反射而发射的颜色。
			normal : TextureImage			正常的贴图
			shininess : real				光亮值		表面的光泽度由一个浮动属性控制。
			specular : color				镜面色		“镜面反射”是为灯光的闪亮表面反射而发射的颜色。
			textureScale : real 			放大和缩小系数
		}
		
		PhongAlphaMaterial{		冯氏α材质
			PhongAlphaMaterial提供了一种通过alpha值实现Phong的照明效果处理
			alpha : real					范围0~1，默认值0.5	alpha是0（完全透明）和1（不透明）之间的曲面透明度。			
			ambient : color					环境色			环境光是物体在没有任何其他光源的情况下发出的颜色。
			diffuse : color					漫反射色		漫反射是为使用灯光进行粗糙表面反射而发射的颜色。
			shininess : real				光亮值			表面的光泽度由一个浮动属性控制。
			specular : color 				镜面色			“镜面反射”是为灯光的闪亮表面反射而发射的颜色。

		}
		
		PhongMaterial{		冯氏材质
			PhongMaterial类提供了冯氏（明暗处理算法的一种名称）光亮效应
			ambient : color					环境色			环境光是物体在没有任何其他光源的情况下发出的颜色。
			diffuse : color					漫反射色		漫反射是为使用灯光进行粗糙表面反射而发射的颜色。
			shininess : real				光亮值			表面的光泽度由一个浮动属性控制。
			specular : color 				镜面色			“镜面反射”是为灯光的闪亮表面反射而发射的颜色。
		}	
	}
	
	

}