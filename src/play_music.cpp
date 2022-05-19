#include <iostream>
#include <cstdlib>
#include <windows.h>

#include "../include/play_music.h"

void play_music::start_play()
{
    mciSendString(TEXT("open .\\music\\test_bgm.mp3 alias song"), NULL, 0, NULL);
    mciSendString(TEXT("play song repeat"), NULL, 0, NULL);
    return;
}

void end_play()
{
    mciSendString(TEXT("stop song"), NULL, 0, NULL);
    mciSendString(TEXT("close song"), NULL, 0, NULL);
    return;
}