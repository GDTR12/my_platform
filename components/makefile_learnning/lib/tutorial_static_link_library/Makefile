WORK_DIR		:=../../build
BUILD_DIR		:=../../build/obj
SRCS			:=${shell find $(SRC_DIR) -type f -name '*.cpp' -not -path '.'}
CURRENT_FOLDER	:=${shell pwd}
OBJ_DIR			:=${BUILD_DIR}/${shell basename ${CURRENT_FOLDER}}/
TARGET			:=ATest

lib${TARGET}.a:${SRCS}
	${CXX} -c $^ -o ${TARGET}.o
	${AR} -r lib${TARGET}.a ${TARGET}.o
	mv lib${TARGET}.a ${OBJ_DIR}
	$(RM) -rf *.o

clean:
	rm -rf *.o ${OBJ_DIR}*.a

show:
	echo ${CURRENT_FOLDER}