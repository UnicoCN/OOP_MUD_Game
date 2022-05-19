src_file = main.cpp src/start_menu.cpp src/attributes.cpp src/map.cpp src/IO.cpp src/play_music.cpp src/environment_setting.cpp src/about_us.cpp src/food.cpp 
include_file = include/start_menu.h include/attributes.h include/map.h include/IO.h include/play_music.h include/environment_setting.h include/about_us.h include/food.h
One_Way_Out.exe : ${src_file} ${include_file}
	g++ main.cpp src/start_menu.cpp src/attributes.cpp src/map.cpp src/IO.cpp src/play_music.cpp src/environment_setting.cpp src/about_us.cpp -o One_Way_Out.exe -lwinmm

.PHONY : clean
clean :
	del *.exe 

