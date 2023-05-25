#include <unordered_set>
#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
	/*
		unordered set is based on hashing
		insert, begin, end, size, clear, find, count, erase, empty
		no duplicates
		all operations are O(1) on average
	*/
	unordered_set<int> s;
	for (int i = 10; i < 60; i += 10) {
		s.insert(i);
	}

	//iterating method
	for (auto x : s)
		cout << x << endl;

	for (auto it = s.begin(); it != s.end(); it++)
		cout << (*it) << endl;

	//find function, returns iterator
	if (s.find(30) == s.end())
		cout << "Not found" << endl;
	else cout << "Found" << (*s.find(30)) << endl;


	//alternative to find is count, returns 0 or 1
	if (s.count(30))
		cout << "Found" << endl;

	//erase
	s.erase(30);
	// size
	s.size();
	//empty
	if (s.empty())
		cout << "Empty" << endl;



	/*
		stores key value pairs
		based on hashing
		no order of keys
		all operations are O(1) on average


	
	*/

	unordered_map<string, int> m;
	m["price"] = 10;
	m["tag"] = 1054;
	m.insert({ "bar_code", 348983 });

	//iterating
	for (auto x : m)
		cout << x.first << x.second << endl;
	for (auto it = m.begin(); it != m.end(); it++)
		cout << it->first << it->second << endl;

	//find
	if (m.find("tag") == m.end())
		cout << "not found" << endl;
	else cout << "found" << endl;

	if (m.count("tag") > 0)
		cout << "found" << endl;



}

