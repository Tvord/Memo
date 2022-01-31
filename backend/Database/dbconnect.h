//
// Created by Tvord on 25.01.2022.
//

#ifndef MEMO_DBCONNECT5_H
#define MEMO_DBCONNECT5_H

#include <sqlite3.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <thread>
#include "queries.h"

class not_opened : public std::exception {
    const char * what() const noexcept override { return "Cannot open database"; }
};
class prepare_error : public std::exception {
    const char * what() const noexcept override { return "Cannot prepare query"; }
};

struct Note {
    unsigned int id;
    std::string topic;
    std::string description;
};

class dbconnect {
public:
    dbconnect(std::string dbname);
    ~dbconnect();

    std::vector<Note>* allNotes() const;
    Note* getNote(const unsigned int id) const;
    bool insertNote(const Note& note);
    bool createNotesTable();

private:
    std::string _dbname;
    sqlite3 *_db;
    static std::vector<Note> selectResult;
};


#endif //MEMO_DBCONNECT5_H
