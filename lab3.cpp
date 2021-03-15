#include <iostream>
#include "pugixml.hpp"
#include "pugixml.cpp"
#include "pugiconfig.hpp"
#include <fstream>
#include <vector>
#include <clocale>
#include <sstream>

using namespace std;
using namespace pugi;
/*
vector<string> split (const string &s, char delim) {
    vector<string> result;
    stringstream ss (s);
    string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }

    return result;
}
*/
class TransportStation
{
private:
    vector<string> split (const string &s, char delim) {
    vector<string> result;
    stringstream ss (s);
    string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
        }
    return result;
    }

public:
    string number;
    string type_of_vehicle;
    string object_type;
    string name_stopping;
    string the_official_name;
    string location;
    vector <string> routes;
    string coordinates;
    TransportStation(){

    };



};


int main(){
    std::locale::global(std::locale(""));
    vector <xml_node>  data;
    ifstream stream("data.xml");
    xml_document doc;
    doc.load(stream);
    vector <xml_node> datalab3;
	vector <xml_node> tramvai;
	vector <xml_node> troll;
	vector <xml_node> bus;
	for (xml_node i = doc.child("dataset").first_child(); i; i = i.next_sibling()){
		datalab3.push_back(i);
	}
/*
	for (int i = 0; i < datalab3.size();i++){
		cout << datalab3[i].child_value("number")<<endl;
    	cout << datalab3[i].child_value("type_of_vehicle")<<endl;
    	cout << datalab3[i].child_value("object_type")<<endl;
    	cout << datalab3[i].child_value("name_stopping")<<endl;
    	cout << datalab3[i].child_value("the_official_name")<<endl;
    	cout << datalab3[i].child_value("location")<<endl;
    	cout << datalab3[i].child_value("routes")<<endl;
    	cout << datalab3[i].child_value("coordinates")<<endl <<endl;;
	}
	*/
	for (int i = 0; i < datalab3.size();i++){
		if (datalab3[i].child_value("type_of_vehicle") == "Трамвай") tramvai.push_back(datalab3[i]);
               // cout << datalab3[i].child_value("type_of_vehicle") << endl;
		if (datalab3[i].child_value("type_of_vehicle") == "Троллейбус") troll.push_back(datalab3[i]);
               // cout << datalab3[i].child_value("type_of_vehicle") << endl;
		if (datalab3[i].child_value("type_of_vehicle") == "Автобус") bus.push_back(datalab3[i]);
               // cout << datalab3[i].child_value("type_of_vehicle") << endl;
	}
}

