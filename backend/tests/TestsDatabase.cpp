//
// Created by Tvord on 31.01.2022.
//
#include <gtest/gtest.h>
#include <dbconnect.h>

class Database : public ::testing::Test {
protected:
    void SetUp() override {
        ASSERT_NO_THROW(db = new dbconnect("123"));
        EXPECT_EQ(db->createNotesTable(), true);
        db->insertNote({0, "Topic1", "Description1"});
        db->insertNote({0, "Topic2", "Description2"});
        db->insertNote({0, "Topic3", "Description3"});
    }

    void TearDown() override {
        std::remove("123");
    }

    dbconnect *db;
};

TEST_F(Database, Database_CanCreate) {
//    {
//        ASSERT_NO_THROW(dbconnect db1("123"));
//    }
}

TEST_F(Database, Database_SelectAll) {
    {
        //dbconnect db1("123");
        EXPECT_NE(db->allNotes()->size(), 0);
        auto notes = db->allNotes();
        EXPECT_EQ(notes->at(1).id, 2);
        EXPECT_EQ(notes->at(1).topic, "Topic2");
        EXPECT_EQ(notes->at(1).description, "Description2");
        delete notes;
    }
}

TEST_F(Database, Database_SelectOne) {
    {
        auto note = db->getNote(3);
        EXPECT_EQ(note->id, 3);
        EXPECT_EQ(note->description, "Description3");
        EXPECT_EQ(note->topic, "Topic3");
        delete note;
    }
}