#include <iostream>
#include "pugixml.hpp"
#include "pugixml.cpp"
#include "pugiconfig.hpp"
#include <fstream>
#include <vector>

using namespace std;
using namespace pugi;

int main(){
    setlocale(LC_ALL, "Russian");
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




}


