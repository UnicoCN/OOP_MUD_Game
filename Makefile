One_Way_Out.exe : main.cpp src/start_menu.cpp
	g++ main.cpp src/start_menu.cpp -o One_Way_Out.exe

.PHONY : clean
clean :
	del *.exe 

