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

TEST_CASE("add an element with push_front","[modifiers]")
{
List<int> list;
list.push_front(42);
REQUIRE(42 == list.front());
}

TEST_CASE("add an element with push_back","[modifiers]")
{
List<int> list;
list.push_back(42);
REQUIRE(42 == list.back());
}

TEST_CASE("remove an added element with pop_front","[modifiers]")
{
List<int> list;
list.push_front(42);
list.push_front(13);
list.pop_front();
REQUIRE(42 == list.front());
}

TEST_CASE("remove an added element with pop_back","[modifiers]")
{
List<int> list;
list.push_front(42);
list.push_front(13);
list.pop_back();
REQUIRE(13 == list.back());
}

TEST_CASE("should be empty after clearing" , "[modifiers]")
{
	List<int> list;
	list.push_front(1);
	list.push_front(2);
	list.push_front(3);
	list.push_front(4);
	list.clear();
	REQUIRE(list.empty()==true);
}

TEST_CASE("should be an empty range after default construction","[iterators]")
{
	List<int> list;
	auto b = list.begin();
	auto e = list.end();
	REQUIRE(b==e);
}

TEST_CASE("provide acces to the first element with begin" , "[iterators]")
{
	List<int> list;
	list.push_front(42);
	REQUIRE(42==*list.begin());
}

/*TEST_CASE("test operators", "[operators]")
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

TEST_CASE("copy constructor", "[constructor]")
{
	List<int> list1;
	list1.push_front(1);
	list1.push_front (2);
	list1.push_front (3);
	list1.push_front (4);		
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
*/
int main(int argc, char *argv[]){
	return Catch::Session().run(argc,argv);
}
