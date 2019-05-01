
List bfs(int s,int t,graph g)
{
    List Q;int c;
    int v=g.nodeval(),x,i=0,k,flag=0;
    bool visited[v]={0};
    int path[v]={-1};
    visited[s]=1;
    path[s]=s;
 List p;
    Q.add(s);

    while(!Q.isEmpty())
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
                        while(i!=s)
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
        if(Q.isEmpty())
          {
              p.head=NULL;
              return p;
          }
    }
    return p;
}

List dfs(int s,int t,graph g)
{
    List S;List p;
    int v=g.nodeval(),x,i,k;
    int visited[v]={0};
    int path[v]={-1};

    path[s]=s;

    S.add(s);

    while(!S.isEmpty())
    {
        /////////////
        x=S.pop();
        //if(visited[x]!=1)
        visited[x]=1;

        if(x==t)
           break;
        for(i=0;i<v;i++)
        {
            if(g.getcost(x,i)!=0 && visited[i]!=1)
            {//cout<<i<<endl;
                S.add(i);
                path[i]=x;

            }
        }
         //if(S.isEmpty())
          {
           //   p.head=NULL;
             // return p;
          }
    }

    k=i;

    p.add(k);
    while(i!=s)
    {
        k=path[i];
        p.add(k);
        i=k;
    }
    p.revList();

    return p;
}/*
List dfs(int s,int t,graph g)
{
    List S;
    int v=g.nodeval(),x,i;
    bool visited[v]={0};
    int path[v]={-1};
    visited[s]=1;
    path[s]=s;

    for(i=0;i<v;i++)
        {
            if(g.getcost(x,i)!=0 && i!=t)
                dfs(i,t,g);
        }
    return p;
}*/
