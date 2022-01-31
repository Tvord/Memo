//
// Created by Tvord on 25.01.2022.
//

#ifndef MEMO_REPEATER_H
#define MEMO_REPEATER_H

#include <iDataCard.h>

using namespace std::chrono_literals;

class Repeater : public iDataCard {
public:
    explicit Repeater();
    explicit Repeater(int id);
    void updateDuration(std::chrono::duration<int, std::ratio<3600>> newDuration) { interval = newDuration; }

private:
    std::chrono::duration<int, std::ratio<3600>> interval{48h};
};


#endif //MEMO_REPEATER_H
