
List bfs(int s,int t,graph g)                                           //BFS execution begins
{
    List Q;
    List p;
    int c;
    int v=g.nodeval(),x,i=0,k,flag=0;
    bool visited[v]={0};
    int path[v]={-1};
    visited[s]=1;
    path[s]=s;
    Q.add(s);

    while(!Q.isEmpty())                                                 //till queue's not empty
    {
        x=Q.dequeue();
        for(i=0;i<v;i++)
        {
            if(g.getcost(x,i)!=0 && visited[i]!=1 )
            {
                visited[i]=1;
                Q.add(i);
                path[i]=x;
                if(i==t)
                {
                    flag=1;
                    k=i;
                    p.add(k);
                    while(i!=s)                                         //path to be returned as list p
                    {
                        k=path[i];
                        p.add(k);
                        i=k;
                    }
                    p.revList();
                    return p;
                }

            }
        }
        if(Q.isEmpty())                                                  //if empty then returns NULL list
        {
            p.head=NULL;
            return p;
        }
    }
    return p;
}

List dfs(int s,int t,graph g)                                            //DFS execution begins
{
    List S;
    List p;
    int v=g.nodeval(),x,i=0,k,flag=0;
    int visited[v]={0};
    int path[v]={-1};

    path[s]=s;
    S.add(s);
    x=s;
    while(i!=t)
    {

        x=i;
        flag=0;
        for(i=0;i<v;i++)
        {
            if(g.getcost(x,i)!=0 && visited[i]!=1)
            {
                visited[x]=1;
                S.add(i);
                path[i]=x;
                flag=1;
                break;
            }
        }
          if(flag!=1)
          {
             S.pop();

             if(!S.isEmpty())
                i=S.top();
             else
                return p;
          }
    }

    k=t;
    p.add(k);
    i=k;
    while(i!=s)                                         //path to be returned as list p
    {
        k=path[i];
        p.add(k);
        i=k;
    }
        p.revList();

    return p;
}
