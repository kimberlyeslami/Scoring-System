#ifndef TABLE_H
#define TABLE_H
#include <vector>
#include "record.h"
#include <map>
#include <string>
#include <vector>



class table {
	//add contain for storing names and records
	std::map<std::string, record> records;

public:


	void add_score(const std::string &name, double score);
	int num_players() const;
	std::vector<std::string> print_best_recent(int n) const;
	double average_best() const;
	std::string best_overall() const;
	int novice_count() const;
};
#endif