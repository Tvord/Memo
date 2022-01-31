//
// Created by Tvord on 25.01.2022.
//

#ifndef MEMO_NOTE_H
#define MEMO_NOTE_H

#include <iDataCard.h>

class Note : public iDataCard {
public:
    explicit Note();
    explicit Note(int id);
};


#endif //MEMO_NOTE_H
