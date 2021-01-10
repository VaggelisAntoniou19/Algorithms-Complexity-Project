#include "greedy.hpp"

   Graph:: Graph(input &in)
    {
        this->fill_Graph(in);
        this->filename = in.getFilename();
    }
    Graph::~Graph() {}
     void Graph::save_to_file(int total)
     {
         string line,word;
         fstream fp;
         fp.open("first_fit.txt",ios::in);
         while(fp>>line)
         {
             stringstream ss(line);
             getline(ss,word,',');
             if(word==this->filename)
             {
                 return;
             }
         }
         fp.close();

         fp.open("first_fit.txt",ios::app);
         fp<<this->filename<<","<<total<<endl;
         fp.close();
     }
    void Graph::fill_Graph(const input &in)
    {
        const int size = in.size();
        this->V = size;
        this->adj = new std::list<int>[size];
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (i == j)
                    continue;
                if (in.is_adjacence(i, j))
                {
                    this->adj[i].push_back(j);
                }
            }
        }
    }

    //Î•ÎºÏ„Î­Î»ÎµÏƒÎ· Î±Î»Î³Î¿Ï�Î¯Î¸Î¼Î¿Ï… first fit
    void Graph::greedyColoring()
    {
        int *result = new int[this->V];
        bool *available = new bool[this->V];

        // Assign the first color to first vertex
        result[0] = 0;

        // Initialize remaining V-1 vertices as unassigned
        for (int u = 1; u < V; u++)
            result[u] = -1; // no color is assigned to u

        // A temporary array to store the available colors. True
        // value of available[cr] would mean that the color cr is
        // assigned to one of its adjacent vertices;
        for (int cr = 0; cr < V; cr++)
            available[cr] = true;

        // Assign colors to remaining V-1 vertices
        for (int u = 1; u < V; u++)
        {
            // Process all adjacent vertices and flag their colors
            // as unavailable

            list<int>::iterator i;
            for (i = adj[u].begin(); i != adj[u].end(); ++i)
                if (result[*i] != -1)
                    available[result[*i]] = false;

            // Find the first available color
            int cr;
            for (cr = 0; cr < V; cr++)
                if (available[cr])
                    break;

            result[u] = cr; // Assign the found color

            // Reset the values back to true for the next iteration
            for (i = adj[u].begin(); i != adj[u].end(); ++i)
                if (result[*i] != -1)
                    available[result[*i]] = true;
        }

        // print the result
        for (int u = 0; u < V; u++)
            cout << "\tVertex:" << u << " --->  Color:" << result[u] << endl;
        cout<<"Colors used:"<<*max_element(result,result+this->V)+1<<endl;
        this->save_to_file(*max_element(result,result+this->V)+1);
        delete[] result;
        delete[] available;
    }
