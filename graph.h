#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

class graph{																		//Graph Class begins
	public:
	int **cm;																		//Cost matrix
	int node;																		//total number of vertices

	public:
	graph(int n)																	//graph's constructor
	{
		node=n;
		int v=n;
		cm= new int* [v];

		for(int i=0;i<v;i++)
			cm[i]=new int[v]();                                                     //initializing cost matrix's all weights as 0(zero)

	}
	int nodeval()																	//function returning total vertices of the graph
	{
		return node;
	}

	int setcost(int i,int j,int w)													//function setting weights of the graph into the cost matrix
	{
		cm[i][j]=w;
		return 0;
	}

	void rrmap(int n,int v){                                                        //Obtain the graph with initial number of nodes from the graph with dummy nodes
    	for(int i=0;i<n;i++)
            for(int j=n;j<v;j++)
                if(cm[i][j] != 0)

            for(int z=0;z<v;z++)
                if(cm[j][z] != 0)
                    cm[i][z]=cm[j][z];
	}

	int getcost(int i,int j)														//function to retrieve weights of the graph from the cost matrix
	{
		return cm[i][j];
	}

    int ifap(int lines)                                                             //Function checking whether any anti-parallel edges exists
	{                                                                               //& returns total no. of such edges
	    int count=0;
	    for(int i=0; i < lines; i++)
            for(int j=i; j< lines; ++j)
                if(i!=j && cm[i][j]>0 && cm[j][i]>0)
                {
                    ++count;
                }
        return count;
	}

    int print(int n)                                                                //Prints the Graph
    {
        for(int i=0; i < n; i++)
        {
            for(int j=0; j< n; j++)
            {
                cout<<cm[i][j]<<" ";
            }
        cout<<endl;
        }
    return 0;
    }

    int maxflow(int n)                                                              //Calculates the Max-Flow
    {                                                                               //Used for working on Flow Graph instance
        int mf=0,mf1=0;
        for(int j=0; j < n; j++)
        {
            mf+=cm[0][j];
            mf1+=cm[j][n-1];
        }

        if(mf==mf1)                                                                 //helps in checking whether the flow instance calculated is
            return mf;                                                              //correct or not
        else
            return -1;
    }
};

#endif
