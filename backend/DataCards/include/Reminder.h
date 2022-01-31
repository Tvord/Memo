//
// Created by Tvord on 25.01.2022.
//

#ifndef MEMO_REMINDER_H
#define MEMO_REMINDER_H

#include <iDataCard.h>

using namespace std::chrono_literals;

class Reminder : public iDataCard {
public:
    explicit Reminder();
    explicit Reminder(int id);

    //std: interval{1d};
};


#endif //MEMO_REMINDER_H
