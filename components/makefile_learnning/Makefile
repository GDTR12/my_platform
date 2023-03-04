
# ${wildcard ./*.cpp}	查找当前目录下所有cpp文件
# 
WORK_DIR		:=./build
SRC_DIR			:=./src
BUILD_DIR		:=./build/obj
BIN_DIR			:=./build/bin
SRCS			:=${shell find -type f -name '*.cpp' -not -path $(SRC_DIR)}
TIME			:=${shell date '+%Y.%m.%d %H:%M:%S'}
DEPENDS			:=${shell find -path ${BUILD_DIR}}

TARGET			:=learn_make
# ${patsubst 原模式，目标模式，文件列表}	将对应的cpp文件替换成.o文件
# OBJ=${patsubst %.cpp,%.o,${shell find $(SRC_DIR) -type f -name '*.cpp' -not -path './src'}}

 .PHONY:clean show

SRCS += ${shell find -type f -name '*.c' -not -path '.'}
INC_DIR = -I ./include -I ./src/others 
INC_DIR += -I ./lib/tutorial_dynamic_link_library -I tutorial_static_link_library

${TARGET}:${OBJ}
# @可以抑制echo "helo world" 命令本身的输出
	${CXX} -c ${SRCS} $(INC_DIR) -o ${BIN_DIR}/$@ 


# # 模式匹配：（%匹配所有的类型）
# %.o:${OTHER_DIR}/%.cpp
# 	${CXX} -c $^ -o $@


# %.o:${MAIN_DIR}/%.cpp
# 	${CXX} -c $^ -o $@

clean:
	rm -rf *.o learn_make

show:
#      echo $(AS) 
#      echo ${CC}
#      echo ${CPP}
#      echo ${CXX}
#      echo ${RM}
	echo ${AR}
	echo ${TIME}
#      echo ${wildcard ./*.cpp}
#	   echo ${shell find $(SRC_DIR) -type f -name '*.cpp' -not -path './src .'}


