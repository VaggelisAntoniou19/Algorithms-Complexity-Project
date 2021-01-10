#include "input.hpp"

using namespace std;

vector<string> files;
vector<int> file_exams;

int count_common_elements(set<int> s1, set<int> s2)
{
    int c = 0;
    for (int x : s1) // range based for
    {
        for (int y : s2)
        {
            if (x == y)
            {
                c++;
                break;
            }
        }
    }
    return c;
}
int menu()
{
    cout << "\n";
    int option;
    std::cout << "1-Print Statistics" << std::endl;
    std::cout << "2-First Fit" << std::endl;
    std::cout<<"3-Show All file Statistics"<<std::endl;
    std::cout<<"4-Show All First Fit Results"<<std::endl;
    std::cout<<"5-Show Html Results"<<std::endl;
    std::cout << "6-Exit" << std::endl;
    std::cout << "Select an option:";
    std::cin >> option;
    return option;
}
void source()
{
    fstream fs;
    fs.open("input.txt", ios::in);
    string line, word;
    while (getline(fs, line))
    {
        stringstream ss(line);
        getline(ss, word, ',');
        files.push_back(word);
        getline(ss, word, ',');
        file_exams.push_back(stoi(word));
    }
    fs.close();
}

string fileselection()
{
    int a;
    if (files.empty())
    {
        source();
    }
    for (int i = 0; i < files.size(); i++)
    {
        cout << i + 1 << "." << files.at(i) << endl;
    }
    cout << "Select your input file:";
    cin >> a;
    return files.at(a - 1);
}
int number_of_vertices(string fn)
{
    int i = 0;
    for (auto &x : files)
    {
        if (x == fn)
        {
            return file_exams[i];
        }
        i++;
    }
    return -1;
}


   input:: input(int number_of_exams)
    {
        for (int i = 0; i < number_of_exams; i++)
        {
            this->exam_students.push_back(set<int>());
            this->adj.push_back(vector<int>());
        }
    }
    void input::save_to_file(int v,double d,int max,int median,int min,double mean,double cv)
    {
        //ÎˆÎ»ÎµÎ³Ï‡Î¿Ï‚ Î±Î½ Î· ÎµÎ³Î³Ï�Î±Ï†Î® Ï€Î¿Ï… Ï€Î¬Ï‰ Î½Î± Î±Ï€Î¿Î¸Î·ÎºÎµÏ�ÏƒÏ‰ Ï…Ï€Î¬Ï�Ï‡ÎµÎ¹ Î®Î´Î· ÏƒÏ„Î¿ Î±Ï�Ï‡ÎµÎ¯Î¿.
        //Î‘Î½ Ï…Ï€Î¬Ï�Ï‡ÎµÎ¹ ÏƒÏ„Î±Î¼Î±Ï„Î¬Ï‰ Ï„Î·Î½ Î­ÎºÏ„Î­Î»ÎµÏƒÎ· Ï„Î·Ï‚ ÏƒÏ…Î½Î¬Ï�Ï„Î·ÏƒÎ·Ï‚.
        string line,word;
        ifstream is;
        is.open("statistics.txt");
        while(is>>line)
        {
            istringstream iss(line);
            getline(iss,word,',');
            if(word==this->filename)
            {
                return;
            }
        }  
        is.close();

        //Î‘Î½ Î· ÎµÎ³Î³Ï�Î±Ï†Î® Î´ÎµÎ½ Ï…Ï€Î¬Ï�Ï‡ÎµÎ¹ Ï„Î·Ï…Î½ Ï€Ï�Î¿ÏƒÎ¸Î­Ï„Ï‰ ÏƒÏ„Î¿ Î±Ï�Ï‡ÎµÎ¯Î¿.
        ofstream os;
        os.open("statistics.txt",ios::app);
        os<<this->filename<<","<<v<<","<<d<<","<<max<<","<<median<<","<<min<<","<<mean<<","<<cv<<endl;
       os.close();
    }
    double input::density()
    {
        int counter = 0;
        const int size = this->exam_students.size();
        for (int i = 0; i < size; i++)
        {
            counter += count_if(this->adj[i].begin(), this->adj[i].end(), [](int &a) { return a != 0; });
        }
        return (double)counter / pow(size, 2);
    }
    void input::fill_adjacency()
    {
        const int size = this->exam_students.size();
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (i == j)
                {
                    adj[i].push_back(0);
                    continue;
                }
                adj[i].push_back(count_common_elements(this->exam_students.at(i), this->exam_students.at(j)));
            }
        }
    }
    void input::openfile(string filename)
    {
        int i;
        stringstream ss(filename);
        getline(ss, this->filename, '/');
        getline(ss, this->filename, '/');
        getline(ss, this->filename, '/');
        fstream fs;
        fs.open(filename, ios::in);
        if (!fs.is_open())
        {
            cerr << "Could not open file " << filename << endl;
            exit(-1);
        }
        int student_id = 0;
        string line, word;
        while (getline(fs, line))
        {
            if (line.empty())
                continue;
            student_id++;
            istringstream iss(line);
            int exam_id;
            while (iss >> exam_id)
            {
                this->exam_students[exam_id - 1].insert(student_id);
            }
        }
        fs.close();
        this->fill_adjacency();
    }
    int input::size() const
    {
        return this->adj.size();
    }
    std::string input::getFilename() const
    {
        return this->filename;
    }
    bool input::is_adjacence(int s, int t) const
    {
        return this->adj[s][t] != 0;
    }
    void input::stats()
    {
        int max, min, median;
        double mean, cv, dens;
        int *sum;
        const int size = this->exam_students.size();
        sum = new int[size];
        for (int i = 0; i < size; i++)
        {
            sum[i] = count_if(this->adj[i].begin(), this->adj[i].end(), [](int &a) { return a != 0; });
        }
        max = *max_element(sum, sum + size);
        min = *min_element(sum, sum + size);
        mean = accumulate(sum, sum + size, 0) / (size * 1.0);
        sort(sum, sum + size);
        median = sum[size / 2];
        cv = 0.0;
        for (int i = 0; i < size; i++)
        {
            cv += pow((double)sum[i] - mean, 2);
        }
        cv /= size - 1;
        cv = (sqrt(cv) / mean) * 100.0;
        dens = this->density();
        cout.precision(4);
        int ver=this->exam_students.size();
        cout << "^^^^^^^^^^^^ Statistics ^^^^^^^^^^^^^^" << endl;
        cout<<"\tVertices:"<<ver<<endl;
        cout << "\tDensity:" << dens << endl;
        cout << "\tMax:" << max << endl;
        cout << "\tMin:" << min << endl;
        cout << "\tMedian:" << median << endl;
        cout << "\tMean:" << mean << endl;
        cout << "\tCoeffience of variation:" << cv << endl;
        delete[] sum;
        this->save_to_file(ver,dens,max,median,min,mean,cv);
        cout << endl << endl;
    }
    void input::printexams()
    {
        for (auto &x : this->exams)
        {
            cout << x << endl;
        }
    }
