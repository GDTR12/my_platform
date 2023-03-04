WORK_DIR		:=../../build
BUILD_DIR		:=../../build/obj
SRCS			:=${shell find $(SRC_DIR) -type f -name '*.cpp' -not -path '.'}
CURRENT_FOLDER	:=${shell pwd}
OBJ_DIR			:=${BUILD_DIR}/${shell basename ${CURRENT_FOLDER}}/
TARGET			:=SoTest.so
CXXFLAGS		:=-L./

${TARGET}:${SRCS}
	${CXX} -fPIC -shared $^ -o lib${TARGET}
	mv ./lib${TARGET} ${OBJ_DIR}
	

clean:
	rm -rf *.so test