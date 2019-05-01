//Main Program

#include <iostream>
using namespace std;
#include<fstream>
#include<string>
#include<time.h>
#include "graph.h"
#include "list.h"
#include "traversal.h"
#include "ff.h"

int **rmap(int **costm1,int lines1,int lines)
{
            int k=lines;

            for(int i=0; i < lines1; i++)											//function to remove anti-parallel edges
            {
                for(int j=i; j< lines1; ++j)
                {
                    if(costm1[i][j]>0 && costm1[j][i]>0 )
                    {
                        costm1[i][k]=costm1[i][j];
                        costm1[k][j]=costm1[i][j];
                        costm1[i][j]=0;
                        k++;
                    }
                }

            }
    return costm1;
}

int main() {																		//main program execution begins here
	string line;
	bool flag=0;
	int lines=0;
	ifstream myfile;
    //
	myfile.open("input_flownet.txt");                                               //opening the input text file
  	if (myfile.is_open())
  	{
    	while ( getline (myfile,line) )
    	{
      		++lines;																//for calculating number of vertices
    	}
  	}
	else
		cout << "Unable to open file";

    myfile.clear();
    myfile.seekg(0,ios::beg);

	int **costm=new int*[lines];													//creating a cost matrix for storing weights of edges in a graph
	for(int x=0;x<lines;x++)
		costm[x]=new int[lines];

    graph g(lines);
	for(int i=0; i < lines; i++)
    	for(int j=0; j< lines; ++j)
        {
			myfile >> costm[i][j];
            g.setcost(i,j,costm[i][j]);
		}
    myfile.close();																     //closing the text file

    int c=g.ifap(lines);                                                             //checking whether anti-parallel edges exist
    int lines1=lines+c;

        flag=1;
        int **costm1=new int*[lines1];												 //creating a cost matrix for storing weights of edges in a graph
        for(int x=0;x<lines1;x++)
            costm1[x]=new int[lines1]();

        for(int i=0; i < lines; i++)												 //setting cost-matrix in the graph object
        {
            for(int j=0; j< lines; j++)
            {
                if(i<lines && j<lines)
                {
                    costm1[i][j]=g.getcost(i,j);
                }
            }
        }

        costm1=rmap(costm1,lines1,lines);

        graph h(lines1);

        for(int i=0;i<lines1;i++)
            for(int j=0;j<lines1;j++)
                {

                    h.setcost(i,j,costm1[i][j]);
                }

        //sending h graph to Algorithm to find maximum flow
        //BY BFS*****

        graph i(lines1);
        clock_t start, end;																//initializing variables to note start and end clocks count
       start = clock();																//clock starts
        i=ff(h,0,5,0);
        i.rrmap(lines,lines1);																	//Sending graph object to Ford Fulkerson implementation
        end = clock();																	//clock ends
        double duration_sec = double(end-start)/CLOCKS_PER_SEC;							//calculating duration of FF execution
        cout<<"BFS (maximum flow value: "<<i.maxflow(lines)<<"; runtime: "<<duration_sec*1000<<"ms)"<<endl;
        i.print(lines);

    //BY DFS*****
        start, end;
        start = clock();																//clock starts
        i=ff(h,0,5,1);																    //Sending graph object to Edmonds Karp implementation
        end = clock();																	//clock ends
        duration_sec = double(end-start)/CLOCKS_PER_SEC;
        i.rrmap(lines,lines1);
        cout<<"DFS (maximum flow value: "<<i.maxflow(lines)<<"; runtime: "<<duration_sec*1000<<"ms)"<<endl;
        i.print(lines);

return 0;																		//Main program's execution ends
}
