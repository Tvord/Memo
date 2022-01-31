//
// Created by Tvord on 25.01.2022.
//

#include "dbconnect.h"

dbconnect::dbconnect(std::string dbname) : _dbname(dbname) {
    auto result = sqlite3_open_v2(_dbname.c_str(), &_db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);
    if (result) {
        fprintf(stderr, "Cannot open database %s by error: %s\n", _dbname.c_str(), sqlite3_errmsg(_db));
        throw not_opened();
    }
}

dbconnect::~dbconnect() {
    sqlite3_close(_db);
}

std::vector<Note> *dbconnect::allNotes() const {
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(_db, Queries::ReadAllNotes.c_str(), -1, &stmt, NULL ) == SQLITE_ERROR) {
        fprintf(stderr, "Cannot prepare query: %s\nProblem description: %s\n", Queries::ReadAllNotes.c_str(), sqlite3_errmsg(_db));
    }

    auto result = new std::vector<Note>;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        Note nt;
        nt.id = sqlite3_column_int(stmt, 0);
        nt.topic = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        nt.description = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
        result->push_back(nt);
    }
    sqlite3_finalize(stmt);
    return result;
}

Note *dbconnect::getNote(const unsigned int id) const {
    sqlite3_stmt* stmt;
    auto sz = (size_t)std::snprintf(nullptr, 0, Queries::ReadSingleNote.c_str(), id);
    auto query = new char[sz + 1];
    sprintf(query, Queries::ReadSingleNote.c_str(), id);

    if (sqlite3_prepare_v2(_db, query, -1, &stmt, NULL ) == SQLITE_ERROR) {
        fprintf(stderr, "Cannot prepare query: %s\nProblem description: %s\n", Queries::ReadAllNotes.c_str(), sqlite3_errmsg(_db));
        throw prepare_error();
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        auto nt = new Note();
        nt->id = sqlite3_column_int(stmt, 0);
        nt->topic = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        nt->description = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
        sqlite3_finalize(stmt);
        return nt;
    }
    return nullptr; // No results
}

bool dbconnect::insertNote(const Note &note) {
    sqlite3_stmt* stmt;
    //char* query{};
    auto sz = (size_t)std::snprintf(nullptr, 0, Queries::AddNote.c_str(), note.topic.c_str(), note.description.c_str());
    auto query = new char[sz + 1];
    sprintf(query, Queries::AddNote.c_str(), note.topic.c_str(), note.description.c_str());

    if (sqlite3_exec(_db, query, NULL, stmt, NULL) != SQLITE_OK) {
        fprintf(stderr, "Cannot prepare query: %s\nProblem description: %s\n", Queries::ReadAllNotes.c_str(),
                sqlite3_errmsg(_db));

        throw prepare_error();
    } else {
        return true;
    }
}

bool dbconnect::createNotesTable() {
    sqlite3_stmt* stmt;

    if (sqlite3_exec(_db, Queries::CreateTable.c_str(), NULL, stmt, NULL) != SQLITE_OK) {
        fprintf(stderr, "Cannot prepare query: %s\nProblem description: %s\n", Queries::ReadAllNotes.c_str(),
                sqlite3_errmsg(_db));

        throw prepare_error();
    } else {
        return true;
    }
}
