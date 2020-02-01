#include "table.h"
#include "record.h"
#include <string>
#include <map>
#include <vector>
#include <algorithm>


void table::add_score(const std::string &name, double score)
{
	records[name].add_score(score); // records[name] adds a new record to the name given and returns the record, then adds their score to that record.
}

int table::num_players() const
{
	return records.size();  //returns the number of player records that are stored in the map
}
bool compare_recent(const pair<string, record> &p1, const pair<string, record> &p2) { //binary predicate for print_best_recent()
	return p1.second.recent_average() > p2.second.recent_average(); //returns if the first is bigger than the second
}

std::vector<std::string> table::print_best_recent(int n) const
{
	vector<string> playersNames; //vector to store the names of players to return
	vector<pair<string, record>> pairs; //vector to store the players and their scores

	for (map<string, record>::const_iterator p = records.cbegin(); p != records.cend(); ++p) { //iterator to step through the map
		pairs.push_back(*p); //pushes the map values to the pairs vector
	}
	sort(pairs.begin(), pairs.end(), compare_recent); //sorts the pairs in ascending order based on the score
	for (int i = 0; i < n && i < pairs.size(); ++i) { //for each highest score in the vector
		playersNames.push_back(pairs[i].first); //pushes the name to vector playersName.
	}
	return playersNames;
}

double table::average_best() const
{
	if (records.size() == 0) { //if there isn't any scores
		return 0; 
	}
	double scoresSum = 0; //variable for sum of the scores
	int scoresNum = 0; // variable for counter of the scores 
	for (map<string, record>::const_iterator p = records.cbegin(); p != records.cend(); ++p) {
		scoresSum += p->second.best_score(); //total best scores in the map
		++scoresNum; //counter of the best scores
	}
	return scoresSum / scoresNum; //works out the average
}

std::string table::best_overall() const
{
	pair<string, record> bestOverallPair; // store the players and scores using map pairs 
	for (map<string, record>::const_iterator p = records.cbegin(); p != records.cend(); ++p) { // uses an iterator to step through the map
		if (bestOverallPair.second.overall_average() < p->second.overall_average()) { //if the new average score is bigger than current average score
			bestOverallPair = *p; //then it becomes the new best average
		}
	}
	return bestOverallPair.first; //returns name of player with the highest average
}

bool novice(pair<string, record> p)  // unary predicate for novice_count()
{
	return p.second.novice(); // returns true if the score is lower
}
int table::novice_count() const
{
	return count_if(records.cbegin(), records.cend(), novice); //counts how many scores in the map is novice
	
}