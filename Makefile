One_Way_Out.exe : main.cpp src/start_menu.cpp src/attributes.cpp src/map.cpp src/IO.cpp
	g++ main.cpp src/start_menu.cpp src/attributes.cpp src/map.cpp src/IO.cpp -o One_Way_Out.exe

.PHONY : clean
clean :
	del *.exe 

