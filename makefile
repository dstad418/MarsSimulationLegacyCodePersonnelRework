output: personnel.o personmgr.o hashtable.o person.o
	g++ -g personnel.o personmgrImp.o hashtableImp.o personImp.o -o output

personnel.o: personnel.cpp
	g++ -c personnel.cpp

personmgr.o: personmgrImp.cpp personmgr.h
	g++ -c personmgrImp.cpp

hashtable.o: hashtableImp.cpp hashtable.h
	g++ -c hashtableImp.cpp

person.o: personImp.cpp person.h
	g++ -c personImp.cpp

clean:
	rm *.o output
