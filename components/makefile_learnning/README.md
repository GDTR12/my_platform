**1. 基本语法：**

​	目标：依赖

​	[tab]命令

```makefile
a:
	echo "hello world"
	gcc -lstdc++ main.cpp

clean:
	rm -rf a.out
```

**2. gcc -lstdc++ main.cpp**:的实际编译流程：

​		预处理： gcc -E main.cpp >main.ii

​		编译： gcc -S main.ii   (得到的main.s为汇编文件)

​		汇编：gcc -c main.s    (得到的main.o为二进制文件)

​		链接：gcc -l main.o     (得到的a.out 为可执行文件)

**3. 变量：**

​	**3.1. 系统变量：**

​		$* 不包括扩展名的目标文件名称

​		$+ 所有的依赖文件

​		$< 表示规则中的第一个条件

​		$? 所有时间戳比目标文件晚的文件

​		$@ 目标文件的完整名称

​		$^ 所有不重复的依赖文件

​		$% 如果目标是归档成员，则表示目标打的归档成员名称

​	**3.2. 系统常量：**

​		    echo $(AS) 	汇编程序的名称

​    		echo ${CC}		c编译器名称

   		 echo ${CPP}	c预编译器名称

​    		echo ${CXX}	C++编译器名称

**4. 伪模式和模式匹配**

 	  .PHONY:目标

​		%.o:${MAIN_DIR}/%.cpp

**5. Dynamic linked library**

​	**代码在最后的可执行文件之外**，在运行时加载，只需维护一个地址

​	**5.1. 编译生成 .so**

​		-fPIC 产生位置无关的代码

​		-shared 共享

​		-L 手动指定库文件搜索目录，默认只链接共享目录

​		-i	指定头文件目录，默认当前目录

​		g++ -fPIC -shared -L[要编译的文件路径] [文件名称] -o lib[库名称] 		#-L后面无空格，库前面一定有lib

​	**5.2. 动态库使用：**

​			-l(小L) 依赖的动态库名称， 如：-lstd

​			动态库编译完成不能直接使用，程序无法直接找到动态库的位置

​			linux动态库的存储路径配置文件在：

​				/etc/ld.so.conf.d/x86_64-linux-gnu.conf

​				/etc/ld.so.conf下面

​			**安装使用：**拷贝动态库到linux动态库的存储路径下

​			**声明使用**：export

**6. Static linked library**

​	

​	${AR} -r lib${TARGET}.a ${TARGET}.o

**7. 公共部分做头文件**

​	include([目标makefile])	将其他文件的Makefile拿过来
