compiler_cxx := g++

sort_persons:\
sort_persons.cc\
person.cc\
sorter.cc
	${compiler_cxx} ${^} -o ${@}