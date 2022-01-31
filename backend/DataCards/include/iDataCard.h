//
// Created by Tvord on 25.01.2022.
//

#ifndef MEMO_IDATACARD_H
#define MEMO_IDATACARD_H

#include <string>
#include <iostream>
#include <chrono>

class iDataCard {
public:
    explicit iDataCard(int id) : _id(id) { lastId = std::max(_id, lastId); }
    explicit iDataCard() : _id(++lastId) {}

    const std::string& getTopic()  {return topic;}
    const std::string& getText() { return description;}
    iDataCard& setTopic(const std::string& newTopic) { topic = newTopic; return *this; }
    iDataCard& setText(const std::string& newDesc) { description = newDesc; return *this; }

    std::ostream& operator<<(std::ostream& stream) { stream << "Topic: " << getTopic() << std::endl << getText() << std::endl; return stream; }

private:
    const int _id{0};
    static int lastId;
    std::string topic;
    std::string description;
};


#endif //MEMO_IDATACARD_H
