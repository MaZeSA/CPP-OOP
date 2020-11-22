
#include "PlaySound.h"

void PlayMenu()
{
    PlaySound(TEXT("Sound\\menu.wav"), NULL, SND_FILENAME | SND_ASYNC);
}
void GameLost()
{
    PlaySound(TEXT("Sound\\GameLost.wav"), NULL, SND_FILENAME | SND_ASYNC);
}
void GameWin()
{
    PlaySound(TEXT("Sound\\GameWin.wav"), NULL, SND_FILENAME | SND_ASYNC);
}