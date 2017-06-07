#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "list.hpp"
#include <iostream>

TEST_CASE("describe_defaultConstructorEmpty","[empty]")
{
	List<int> list;
	REQUIRE(list.empty()==true);
	REQUIRE(list.size()==0);
}

TEST_CASE("describe_pushFront", "[pushFront]")
{
	List<int> list{};
	list.push_front(4);
	REQUIRE(4==*list.begin());
	list.push_front(5);
	list.push_front(6);
	REQUIRE(6==*list.begin());
}

TEST_CASE("describe_pushBack", "[pushBack]")
{
	List<int> list{};
	list.push_back(4);
	REQUIRE(4==*list.end());
	list.push_back(5);
	list.push_back(6);
	REQUIRE(6==*list.end());
}

TEST_CASE("describe_popFront", "[popFront]")
{
	List<int> list{};
	list.push_front(4);
	list.pop_front();
	REQUIRE(list.empty()==true);
	list.push_front(5);
	list.push_front(6);
	list.pop_front();
	REQUIRE(*list.begin()==5);
}

TEST_CASE("describe_popBack", "[popBack]")
{
	List<int> list{};
	list.push_back(4);
	list.pop_back();
	REQUIRE(list.empty()==true);
	list.push_back(5);
	list.push_back(6);
	list.pop_back();
	REQUIRE(*list.end()==5);
}

TEST_CASE("describe_clear", "[clear]")
{
	List<int> list{};
	list.push_front(3);
	list.push_back(6);
	list.clear();
	REQUIRE(list.empty()==true);
}

TEST_CASE("describe_emptyDefault", "[emptyDefault]")
{
	List<int> list;
	auto a = list.begin();
	auto b = list.end();
	REQUIRE(a==b);
}

TEST_CASE("describe_beginIterator","[beginIterator]")
{
	List<int> list;
	list.push_front(15);
	REQUIRE(15==*list.begin());
}

TEST_CASE("describe_operators", "[operators]")
{
	List<int> list1;
	list1.push_front(1);
	list1.push_back(2);
	List<int> list2;
	list2.push_front(1);
	list2.push_back(2);
	REQUIRE(list1==list2);
	list2.pop_front();
	REQUIRE(list1!=list2);
}

TEST_CASE("describe_copy", "[copy]")
{
	List<int> list1;
	list1.push_front(1);
	list1.push_back(2);
	List<int> list2{list1};
	REQUIRE(list1==list2);
}

TEST_CASE("describe_reverse", "[reverse]")
{
	List<int> list;
	list.push_front(1);
	list.push_back(2);
	list.reverse();
	REQUIRE(*list.end()==1);
	REQUIRE(*list.begin()==2);
	list.reverse();
	REQUIRE(*list.end()==2);
	REQUIRE(*list.begin()==1);
}

TEST_CASE("describe_move", "[move]")
{
	List<int> list1;
	list1.push_front(20);
	list1.push_front(10);
	List<int> list2(std::move(list1));
	REQUIRE(0==list1.size());
	REQUIRE(list1.empty());
	REQUIRE(2==list2.size());
	REQUIRE(10==*list2.begin());
	REQUIRE(20==*list2.end());
}

int main(int argc, char *argv[]){
	return Catch::Session().run(argc,argv);
}