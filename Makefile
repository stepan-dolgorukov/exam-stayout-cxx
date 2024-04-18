compiler_cxx := g++

compiler_cxx_flags :=\
-std=c++17\
-Wall

sort_persons:\
sort_persons.cc\
person.cc\
sorter.cc
	${compiler_cxx} ${compiler_cxx_flags} ${^} -o ${@}