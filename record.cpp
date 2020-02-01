#include "record.h"
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

record::record() {  // empty record
}

record::record(double score) : scoresSum(0), scoresNum(0), maxScore(0) {
	scoresSum += score;  // works out the total of all the scores entered.
	++scoresNum; // counter of the scores entered.
	maxScore = score; // because only one score is being entered, it's going to be the max score.
	scores.push_back(score); //adds current score to the score list.
}

void record::add_score(double score) {
	scoresSum += score;  //total of scores entered.
	++scoresNum;  //counter of scores entered. 
	if (score > maxScore) { //if the score entered is bigger than the current max score.
		maxScore = score; // then it becomes the new max score.
	}

	(scores.push_back(score));  //adds the current score to the score list.
	if (scores.size() > 10) { // if more than 10 scores are entered.
		scores.pop_front(); // removes the first one to add the new one, so only 10 scores are stored.
	}

}

double record::best_score() const {
	
	return maxScore; //returns the max Score that is worked out when the scores were added.

}

double record::overall_average()const {

	if (scores.size() == 0) { // if there aren't any scores
		return 0; 
	}
	
	return scoresSum / scoresNum; // returns the average

}

double record::recent_average() const {
	if (scores.size() == 0) { //if there aren't any  scores
		return 0; 
	}
	double sumOfScores = 0;  //variable for sum of the scores
	unsigned numOfScores = 0; // variable for counter of the scores 
	typedef deque<double>::const_iterator iter;
	for (iter i = scores.cbegin(); i != scores.cend(); ++i) { //
		++numOfScores;
		sumOfScores += *i; //adds all scores in the record together
	}
	return sumOfScores / numOfScores; //returns the average

}
	
bool record::novice() const {
	return scores.size() < 10; // true if num of scores are less than 10
}

int record::size() const {
	return scores.size();

}