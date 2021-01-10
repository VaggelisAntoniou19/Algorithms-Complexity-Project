#include "greedy.hpp"
#include <Windows.h>

//-------------------------------------------------
//File Path
std::string GetFilePath()
{
  char buffer[MAX_PATH];
  GetModuleFileName( NULL, buffer, MAX_PATH );
  std::string f =std::string(buffer);
  return f.substr(0, f.find_last_of( "\\/" ));
}
//-------------------------------------------------
//-----------------------------------------------------------------------------


void Show_total_Results()
{
    std::string htmlcontent="<html><body><center><div style=\"color:red; background-color:cyan; width:30%; font-size:21px; margin-bottom:46px; overflow:hidden;\">Statistics and First Fit Results for Graph Coloring</div><hr><table border=\"3\" style=\"background-color:lightgray; color:blue; font-weight:bold; font-size:18px; text-align:center;\"><tr style=\"background-color:green; color:black; font-size:21px;\"><td>FILENAME</td><td>VERTICES</td><td>DENSITY</td><td>MAX</td><td>MEDIAN</td><td>MIN</td><td>MEAN</td><td>CV</td></tr>"; 
    ifstream is;
    is.open("statistics.txt",ios::in);
    string line,word;
    vector <string> data;
    while(is>>line)
    {
        data.clear();
        stringstream ss(line);
        while(getline(ss,word,','))
        {
          data.push_back(word);
        }
        htmlcontent+="<tr>";
        for(auto &x:data)
        {
            htmlcontent+="<td>"+x+"</td>";
        }
        htmlcontent+="</tr>";
    }
    is.close();
    htmlcontent+="</table><br><br><hr>";
    htmlcontent+="<table border=\"3\" style=\"background-color:blue; color:lightgray; font-weight:bold; font-size:18px; text-align:center;\"><tr style=\"background-color:green; color:black; font-size:21px;\"><td>FILENAME</td><td>COLORS USED</td></tr>";
    is.open("first_fit.txt");
    while(is>>line)
    {
        data.clear();
        stringstream ss(line);
        while(getline(ss,word,','))
        {
          data.push_back(word);
        }
        htmlcontent+="<tr>";
        for(auto &x:data)
        {
            htmlcontent+="<td>"+x+"</td>";
        }
        htmlcontent+="</tr>";
    }
    is.close();
    htmlcontent+="</table></center></body></html>";

    ofstream os;
    os.open("preview.html");
    os<<htmlcontent<<endl;
    os.close();
    ShellExecute(NULL,"open","preview.html",NULL,NULL,SW_SHOWNORMAL);
}
//------------------------------------------------------------------------------


void showAllStats()
{
    ifstream is;
    cout.precision(4);
    double num;
    is.open("statistics.txt");
    string line,word;
    vector <string> data;
    while(is>>line)
    {
        data.clear();
        istringstream iss(line);
        while(getline(iss,word,','))
        {
            data.push_back(word);
        }
        cout<<data[0]<<"-->";
        for(int i=1,t=data.size();i<t;i++)
        {
            num=std::stod(data[i]);
            cout<<num<<"\t";
        }
        cout<<endl;
    }
    is.close();
    cout<<endl<<endl;
}

void ShowFirstFitResults()
{
    ifstream is;
    is.open("first_fit.txt");
    string line,word;
    cout<<"\tFILENAME  \tCOLORS"<<endl;
    while(is>>line)
    {
        stringstream ss(line);
        cout<<"\t";
        while(getline(ss,word,','))
        {
          cout<<word<<"\t ";
        }
        cout<<endl;
    }
    is.close();
}

int main()
{
    int op;
    string actualname=fileselection();
    std::string fn="datasheets/"+actualname;
    input i(number_of_vertices(actualname));
    i.openfile(fn);
    Graph g(i);
    while (true)
    {
        op = menu();
        switch (op)
        {
        case 1:
         i.stats();
           break;
        case 2:
         g.greedyColoring();
         break;
        case 3:
          showAllStats();
          break;
        case 4:
          ShowFirstFitResults();
          break;
        case 5:
          Show_total_Results();
          break;
        case 6:
            exit(EXIT_SUCCESS);
        default:
            cerr<<"Invallid choice please select on of the valid";
        }
    }
}
