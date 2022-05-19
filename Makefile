One_Way_Out.exe : main.cpp src/start_menu.cpp src/attributes.cpp src/map.cpp src/IO.cpp include/start_menu.h include/attributes.h include/map.h include/IO.h include/play_music.h include/environment_setting.h include/food.h
	g++ main.cpp src/start_menu.cpp src/attributes.cpp src/map.cpp src/IO.cpp src/play_music.cpp src/environment_setting.cpp src/food.cpp -o One_Way_Out.exe -lwinmm

.PHONY : clean
clean :
	del *.exe 

