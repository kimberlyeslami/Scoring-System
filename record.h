#pragma once
#ifndef RECORD_H
#define RECORD_H
#include<vector>
#include <deque>
#include <string>

using namespace std;
class record {
	deque <double> scores; // storing record algorithm
	double scoresSum;  //sum of the scores variable
	double scoresNum; //counter of the scores
	double maxScore;

public:
	record();
	record(double score);
	void add_score(double score);
	double best_score() const;
	double overall_average()const;
	double recent_average() const;
	bool novice() const;
	int size() const; // this is for testing
};
#endif