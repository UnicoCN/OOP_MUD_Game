src_file = main.cpp src/*.cpp
include_file = include/*.h
One_Way_Out.exe : ${src_file} ${include_file}
	g++ main.cpp src/start_menu.cpp src/attributes.cpp src/map.cpp src/IO.cpp src/play_music.cpp \
	src/environment_setting.cpp src/about_us.cpp src/interact.cpp src/YouDead.cpp src/ending.cpp -o One_Way_Out.exe -lwinmm

.PHONY : clean
clean :
	del *.exe 

