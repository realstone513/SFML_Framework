#include <SFML/Graphics.hpp>
#include "Framework/Framework.h"

int main()
{
    Framework framwork(1280, 720);
    framwork.Init();
    framwork.Do();

    return 0;
}