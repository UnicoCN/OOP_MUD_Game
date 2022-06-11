#include "../include/ending.h"
#include <iostream>
#include <windows.h>
#include <cstdio>
void Ending(int san)
{
    system("cls");
    std::cout << "终于要结束了……出口就在眼前。" << std::endl;
    std::cout << "只要能够推开那扇门，一切就都能结束，亦如上次。" << std::endl;
    std::cout << "你掏出一直带在身上的钥匙，打开了门……" << std::endl;
    if(san < 0)
    {
        std::cout << "推开门，门外是许多辆警车，以及更多持枪警戒的警察。" << std::endl;
        std::cout << "浑身是血的你欣喜若狂，朝他们高喊道“你们终于来了！快来救我！”" << std::endl;
        std::cout << "警察们如临大敌，纷纷将枪口对向你，高喊“不许动！放下武器！”" << std::endl;
        std::cout << "你完全不能理解他们为什么要这么做，但还是放下了手里的武器，警察们一拥而上，把你按倒在地。" << std::endl;
        std::cout << "你听到有人向对讲机汇报“嫌犯已被逮捕”" << std::endl;
        std::cout << "这时你才注意到，那些被你杀掉的怪物，到底是什么东西……" << std::endl;
        std::cout << "你只感觉天旋地转，耳边又响起了“它”的笑声……" << std::endl;
        std::cout << "达成结局——杀人凶手" << std::endl;
    }
    else if(san <= 25)
    {
        std::cout << "你从地狱杀出，再一次从“它”手里回到了人世间。" << std::endl;
        std::cout << "你费劲力气，推开酒店大门。" << std::endl;
        std::cout << "这是你的救赎，你战胜了它！" << std::endl;
        Sleep(2000);
        std::cout << "……如果门外的前台不用“它”的声音说“欢迎，入住，天堂，酒店”…………就好了…………" << std::endl;
        std::cout << "达成结局——while循环" << std::endl;
    }
    else if(san <= 50)
    {
        std::cout << "你终于杀出了酒店。" << std::endl;
        std::cout << "但你早该想到的，“它”的能力已经远超曾经，酒店以外的人世间早已变了样。" << std::endl;
        std::cout << "“它”把地狱带上人间，“它”把人间变成天堂酒店。" << std::endl;
        std::cout << "“它”觉得这样“它”就赢了。" << std::endl;
        std::cout << "但你举起了你的斧头。" << std::endl;
        std::cout << "达成结局——求生者" << std::endl;
    }
    else if(san <= 75)
    {
        std::cout << "“他又一次通过了测试！”" << std::endl;
        std::cout << "“真是奇迹！计算机估计的他的生还几率甚至低于0.3%！”" << std::endl;
        std::cout << "“但是，他仍然没能展现出我们期望的现实扭曲能力。”" << std::endl;
        std::cout << "“至少他很快适应了现实扭曲后的世界。”" << std::endl;
        std::cout << "“这次不如在难度V的现实扭曲世界测试吧……我宣布第三次测试开始！”" << std::endl;
        std::cout << "达成结局——？？？" << std::endl;
    }
    else
    {
        std::cout << "你已经明白了这一切。" << std::endl;
        std::cout << "正当博士和他的助手陷入通过测试的震惊和喜悦之中，你挣脱了仪器的束缚，站了起来。" << std::endl;
        std::cout << "他们不能理解，为什么你能摆脱机器，又为什么你能拿到一把和梦境中一模一样的斧头。" << std::endl;
        std::cout << "“这不是你们期待的能力吗？你们不就是想培养出人形的‘它’吗？”" << std::endl;
        std::cout << "“现在你们如愿了。”" << std::endl;
        std::cout << "达成结局——重返人间" << std::endl;
    }
    std::cout << "输入回车以结束游戏" << std::endl;
    getchar();
    exit(0);
}