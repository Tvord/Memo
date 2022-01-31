//
// Created by Tvord on 31.01.2022.
//

#ifndef MEMO_QUERIES_H
#define MEMO_QUERIES_H

#include <string>

const std::string NoteTableName = "Notes";

namespace Queries {
    const std::string CreateTable = "CREATE TABLE IF NOT EXISTS " + NoteTableName + " ("
                                    "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                                    "topic VARCHAR(255), "
                                    "desc VARCHAR(65535)"
                                    ")";
    const std::string AddNote = "INSERT INTO " + NoteTableName + " VALUES ("
                                "NULL, "
                                "'%s', "
                                "'%s')";
    const std::string ReadSingleNote = "SELECT * FROM " + NoteTableName + " WHERE "
                                      "id=%u";
    const std::string ReadAllNotes = "SELECT * FROM " + NoteTableName;

}

#endif //MEMO_QUERIES_H
