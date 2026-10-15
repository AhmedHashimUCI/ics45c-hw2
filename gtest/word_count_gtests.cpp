#include <gtest/gtest.h>

#include <sstream>

#include "word_count.hpp"

using namespace std;

TEST(WordCount, ToLowercase) {
  string test = "hEllO wOrLd";

  to_lowercase(test);
  EXPECT_STREQ("hello world", test.c_str());
}



TEST(WordCount, LowerCaseLana){
	string test = "LAna DeL REy";
	to_lowercase(test);
	EXPECT_STREQ("lana del rey", test.c_str());



}


TEST(wordCount, LowerCaseSentence){
	string sen = "HELLO, wHO aRE yOU?";
	to_lowercase(sen);
	EXPECT_STREQ("hello, who are you?", sen.c_str());

}


TEST(WordCount, LoadStopWords) {
  stringstream test("hello world");

  const auto stop_words = load_stopwords(test);

  EXPECT_TRUE(stop_words.contains("hello"));
  EXPECT_TRUE(stop_words.contains("world"));
  EXPECT_FALSE(stop_words.contains("foo"));
}


TEST(WordCount, LoadStopWatchMultiple){
	stringstream test("lana del rey");
	stringstream test2("arctic");

	const auto stop_words1 = load_stopwords(test);
	const auto stop_words2 = load_stopwords(test2);

	EXPECT_TRUE(stop_words1.contains("del"));
	EXPECT_TRUE(stop_words2.contains("arctic"));
	EXPECT_FALSE(stop_words2.contains("monkeys"));

}

TEST(WordCount, LoadEmpty){

	stringstream empty("");

	const auto stop_words = load_stopwords(empty);
	EXPECT_FALSE(stop_words.contains("empty"));

}


TEST(WordCount, CountWords) {
  stringstream test("aa aa bc foo bar");
  const auto counts = count_words(test, {});

  EXPECT_EQ(counts.at("aa"), 2);
  EXPECT_EQ(counts.at("bc"), 1);
  EXPECT_EQ(counts.at("foo"), 1);
  EXPECT_EQ(counts.at("bar"), 1);
  EXPECT_FALSE(counts.contains("baz"));
}

TEST (WordCount, CountWordsMulti) {

stringstream test("air lana bob lana lana time");

const auto counts = count_words(test, {});
EXPECT_EQ(counts.at("lana"),3) ;
EXPECT_EQ(counts.at("time"),1);
EXPECT_EQ(counts.at("air"),1) ;
EXPECT_EQ(counts.at("bob"), 1);

EXPECT_FALSE(counts.contains("del"));

}



TEST(WordCount, OutputWordCounts) {
  map<string, int> word_counts;
  word_counts["foo"] = 1;
  word_counts["bar"] = 5;
  word_counts["xy"] = 3;

  stringstream output;
  output_word_counts(word_counts, output);
  EXPECT_STREQ(output.str().c_str(), "bar 5\nfoo 1\nxy 3");
}

