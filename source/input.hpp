/*
 * input.hpp
 *
 */

#ifndef INPUT_HPP_
#define INPUT_HPP_
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include <algorithm>
#include <list>
#include <numeric>
#include <iomanip>
#include <cmath>
#include <ctime>

using namespace std;

class input
{
private:
    string filename;
    string statsstring;
    set<string> exams;
    vector<set<int>> exam_students;
    vector<vector<int>> adj;
public:
    input(int number_of_exams);
    void save_to_file(int v,double d,int max,int median,int min,double mean,double cv);
    double density();
    void fill_adjacency();
    void openfile(string filename);
    int size() const;
    std::string getFilename() const;
    bool is_adjacence(int s, int t) const;
    void stats();

};

int count_common_elements(set<int> s1, set<int> s2);
int menu();
void source();
string fileselection();
int number_of_vertices(string fn);

#endif /* INPUT_HPP_ */
