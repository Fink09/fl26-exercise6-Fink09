////////////////////////////////////////////////////////
// ECE 3574 Exercise: Unit Tests with Catch - starter code
//
#define CATCH_CONFIG_MAIN  // This line tells Catch to provide a main() function
                           // - do this in one cpp file only
#include "catch.hpp"       // This line provides access to all Catch macros
                           // - do not modify catch.hpp
#include <cassert>    
#include <cstdlib>

#include <map>
#include <string>
#include <utility>



TEST_CASE("multimap unit test1", "[multimap]") {
	std::multimap<std::string, std::string> m;	
	REQUIRE(m.size() == 0);
	
	m.insert(std::pair<std::string, std::string>("Ross", "Betsy"));
	REQUIRE(m.size() == 1);

}

/*
operator=
empty
size
clear
insert
erase
count
find
*/


TEST_CASE("multimap operator= test", "[multimap]") {
	std::multimap<std::string, int> m;
	m.insert(std::pair<std::string, int>("daniel", 1));
	m.insert(std::pair<std::string, int>("daniel", 2));

	std::multimap<std::string, int> m2;
	m2 = m;
	REQUIRE(m2.size() == 2);
	REQUIRE(m2.count("daniel") == 2);
	REQUIRE(m2.find("daniel")->second == 1);
}

TEST_CASE("multimap empty test", "[multimap]") {
	std::multimap<std::string, int> m;
	REQUIRE(m.empty() == true);
	m.insert(std::pair<std::string, int>("daniel", 1));
	REQUIRE(m.empty() == false);
}

TEST_CASE("multimap size test", "[multimap]") {
	std::multimap<std::string, int> m;
	REQUIRE(m.size() == 0);
	m.insert(std::pair<std::string, int>("test", 1));
	REQUIRE(m.size() == 1);
	m.insert(std::pair<std::string, int>("test", 2));
	REQUIRE(m.size() == 2);
	m.insert(std::pair<std::string, int>("test2", 1));
	REQUIRE(m.size() == 3);
	m.clear();
	REQUIRE(m.size() == 0);
	REQUIRE(m.empty() == true);
}

TEST_CASE("multimap clear test", "[multimap]") {
	std::multimap<std::string, std::string> m;
	for(int i = 0; i < 10; ++i) {
		m.insert(std::pair<std::string, std::string>("test", "test"));
	}
	REQUIRE(m.size() == 10);
	m.clear();
	REQUIRE(m.size() == 0);
	REQUIRE(m.empty() == true);
}

TEST_CASE("multimap insert test", "[multimap]") {
	std::multimap<std::string, std::string> m;
	m.insert(std::pair<std::string, std::string>("test", "test"));
	REQUIRE(m.size() == 1);
	m.insert(std::pair<std::string, std::string>("test", "test2"));
	REQUIRE(m.size() == 2);
	m.insert(std::pair<std::string, std::string>("test2", "test"));
	REQUIRE(m.size() == 3);
}

TEST_CASE("multimap erase test", "[multimap]") {
	std::multimap<std::string, std::string> m;
	m.insert(std::pair<std::string, std::string>("test", "test"));
	m.insert(std::pair<std::string, std::string>("test", "test1"));
	m.insert(std::pair<std::string, std::string>("test2", "test"));
	REQUIRE(m.size() == 3);
	m.erase("test");
	REQUIRE(m.size() == 1);
	REQUIRE(!(m.empty()));
}

TEST_CASE("multimap count test", "[multimap]") {
	std::multimap<std::string, int> m;
	m.insert(std::pair<std::string, int>("test", 1));
	REQUIRE(m.count("test") == 1);
	m.insert(std::pair<std::string, int>("test", 1));
	m.insert(std::pair<std::string, int>("test", 2));
	m.insert(std::pair<std::string, int>("test", 3));
	m.insert(std::pair<std::string, int>("test", 4));
	REQUIRE(m.count("test") == 5);

	m.insert(std::pair<std::string, int>("test2", 1));
	REQUIRE(m.count("test2") == 1);
	REQUIRE(m.count("test") == 5);

	m.insert(std::pair<std::string, int>("test2", 1));
	m.insert(std::pair<std::string, int>("test2", 2));
	m.insert(std::pair<std::string, int>("test2", 3));
	m.insert(std::pair<std::string, int>("test2", 4));
	REQUIRE(m.count("test2") == 5);
	REQUIRE(m.count("test") == 5);
	m.erase("test2");
	REQUIRE(m.count("test2") == 0);
	REQUIRE(m.count("test") == 5);
}

TEST_CASE("multimap find test", "[multimap]") {
	std::multimap<std::string, int> m;
	auto it = m.find("test");
	REQUIRE(it == m.end());

	m.insert(std::pair<std::string, int>("test1", 100));
	m.insert(std::pair<std::string, int>("test2", 10));
	m.insert(std::pair<std::string, int>("test3", 1));

	it = m.find("test1");
	REQUIRE(it != m.end());
	REQUIRE(it->first == "test1");
	REQUIRE(it->second == 100);
	it++;
	REQUIRE(it->first == "test2");
	REQUIRE(it->second == 10);
}

