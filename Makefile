One_Way_Out.exe : main.cpp src/start_menu.cpp src/attributes.cpp src/map.cpp src/IO.cpp include/start_menu.h include/attributes.h include/map.h include/IO.h
	g++ main.cpp src/start_menu.cpp src/attributes.cpp src/map.cpp src/IO.cpp -o One_Way_Out.exe

.PHONY : clean
clean :
	del *.exe 

