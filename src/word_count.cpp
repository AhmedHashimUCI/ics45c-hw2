#include <iostream>
#include "word_count.hpp"
#include <cctype>

using namespace std;

void to_lowercase(string &str){

	for (char c : str){

	c = static_cast<char>(tolower(static_cast<unsigned char>(c)));

	}
}

set<string> load_stopwords(istream& stopwords){

	set<string> words;
	string stop;

	while (stopwords >> stop){
		to_lowercase(stop);
		words.insert(stop);

	}
	
	return words;

}

map<string, int> count_words(istream& document, const set<string>& stopwords){

	map<string, int> freq;
	string word;

	while(document >> word){
		to_lowercase(word);
		if(stopwords.find(word) == stopwords.end()){
		
			freq[word]++;

		}

	}

	return freq;
	
	}



void output_word_counts(const map<string, int>& word_counts, ostream& output){

	for (auto pairs: word_counts){

		output << pairs.first << " " << pairs.second << endl;
	}
}
