One_Way_Out.exe : main.cpp src/start_menu.cpp src/attributes.cpp src/map.cpp
	g++ main.cpp src/start_menu.cpp src/attributes.cpp src/map.cpp -o One_Way_Out.exe

.PHONY : clean
clean :
	del *.exe 

