// ------------------------- Your tests - student_gtests.cpp ----------------------------- //
// Your own GoogleTest suite for the word_count module. It is graded: the autograder runs it
// against a correct implementation and against several with one bug each. A test is worth
// something only when it passes on the correct implementation and fails on a broken one, so a
// test that always fails (or that tests nothing) earns nothing.
//
// Two examples are given. Add tests of your own for to_lowercase, load_stopwords, count_words
// and output_word_counts, and for the edges: an empty document, a document that is all stop
// words, stop words written in mixed case, and the same word in several cases.
// --------------------------------------------------------------------------------------- //

#include <gtest/gtest.h>

#include <sstream>

#include "word_count.hpp"

using namespace std;

TEST(WordCountTests, StopwordsAreLoadedCaseInsensitively) {
    std::stringstream stopwords{"The OVER\n"};
    const auto loaded = load_stopwords(stopwords);
    EXPECT_TRUE(loaded.contains("the"));
    EXPECT_TRUE(loaded.contains("over"));
}


TEST(WordCountTests, StopWordwithRun){
	stringstream test("air lana bob lana lana time");
	stringstream test2("arctic");
	const auto stop_words1 = load_stopwords(test2);
	const auto counts = count_words(test, {});
	EXPECT_EQ(counts.at("lana"), 3);
	EXPECT_TRUE(stop_words1.contains("arctic"));


}


TEST(WordCountTests, WordsAreCountedCaseInsensitively) {
    std::stringstream document{"Apple apple APPLE pear"};
    const auto counts = count_words(document, {});
    EXPECT_EQ(counts.at("apple"), 3);
    EXPECT_EQ(counts.at("pear"), 1);
}

// ADD YOUR TESTS HERE
TEST(WordCountTests, LowerCaseLana){
	string test = "LAna DeL REy";
	to_lowercase(test);
	EXPECT_STREQ("lana del rey", test.c_str());



}


TEST(WordCountTests, LowerCaseSentence){
	string sen = "HELLO, wHO aRE yOU?";
	to_lowercase(sen);
	EXPECT_STREQ("hello, who are you?", sen.c_str());

}


TEST(WordCountTests, LoadStopWords) {
  stringstream test("hello world");

  const auto stop_words = load_stopwords(test);

  EXPECT_TRUE(stop_words.contains("hello"));
  EXPECT_TRUE(stop_words.contains("world"));
  EXPECT_FALSE(stop_words.contains("foo"));
}


TEST(WordCountTests, LoadStopWatchMultiple){
	stringstream test("lana del rey");
	stringstream test2("arctic");

	const auto stop_words1 = load_stopwords(test);
	const auto stop_words2 = load_stopwords(test2);

	EXPECT_TRUE(stop_words1.contains("del"));
	EXPECT_TRUE(stop_words2.contains("arctic"));
	EXPECT_FALSE(stop_words2.contains("monkeys"));

}

TEST(WordCountTests, LoadEmpty){

	stringstream empty("");

	const auto stop_words = load_stopwords(empty);
	EXPECT_FALSE(stop_words.contains("empty"));

}


TEST(WordCountTests, CountWords) {
  stringstream test("aa aa bc foo bar");
  const auto counts = count_words(test, {});

  EXPECT_EQ(counts.at("aa"), 2);
  EXPECT_EQ(counts.at("bc"), 1);
  EXPECT_EQ(counts.at("foo"), 1);
  EXPECT_EQ(counts.at("bar"), 1);
  EXPECT_FALSE(counts.contains("baz"));
}

TEST (WordCountTests, CountWordsMulti) {

stringstream test("air lana bob lana lana time");

const auto counts = count_words(test, {});
EXPECT_EQ(counts.at("lana"),3) ;
EXPECT_EQ(counts.at("time"),1);
EXPECT_EQ(counts.at("air"),1) ;
EXPECT_EQ(counts.at("bob"), 1);

EXPECT_FALSE(counts.contains("del"));

}


