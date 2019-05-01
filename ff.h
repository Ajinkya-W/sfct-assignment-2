
graph ff(graph g,int s,int t,bool flag)                                     //Ford-Fulkerson algo begins
{
    int Cf,min,u,v;
    List p,q;
    graph f(g.nodeval());                                                   //flow matrix
    graph r(g.nodeval());                                                   //residual graph

    for(int i=0;i<g.nodeval();i++)
       for(int j=0;j<g.nodeval();j++)
        {
             r.setcost(i,j,g.getcost(i,j));                                 //initializing residual graph
        }

    if(flag==0)                                                             //this selects BFS
    {
        while(bfs(s,t,r).peek()!=-1)                                        //till a path is returned
        {
            p=bfs(s,t,r);

            min=9999;
            while(p.nextExist())
            {
                u=p.dequeue();
                v=p.peek();
                Cf=r.getcost(u,v);
                if(Cf<min)
                {
                    min=Cf;
                }
            }
            q=bfs(s,t,r);

            while(q.nextExist())
            {
                u=q.dequeue();
                v=q.peek();

                if(g.getcost(u,v)!=0)
                {
                    f.setcost(u,v,(f.getcost(u,v)+ min));
                    r.setcost(u,v,(g.getcost(u,v)-f.getcost(u,v)));
                }
                else
                {
                    f.setcost(v,u,(f.getcost(v,u)- min));
                    r.setcost(u,v,f.getcost(v,u));
                }
            }
        }
    }

    else
     {

        while(dfs(s,t,r).peek()!=-1)                                        //till a path is returned
        {

            p=dfs(s,t,r);
            min=9999;

            while(p.nextExist())
            {
                u=p.dequeue();
                v=p.peek();
                Cf=r.getcost(u,v);
                if(Cf<min)
                {
                    min=Cf;
                }
            }
            q=dfs(s,t,r);

            while(q.nextExist())
            {
                u=q.dequeue();
                v=q.peek();

                if(g.getcost(u,v)>0)
                {
                    f.setcost(u,v,(f.getcost(u,v)+ min));

                }
                else
                {
                    f.setcost(v,u,(f.getcost(v,u)- min));

                }
            }
            for(int u=0;u<r.nodeval();u++)
            {
                for(int v=0;v<r.nodeval();v++)
                {
                    if(g.getcost(u,v)>0)
                        r.setcost(u,v,(g.getcost(u,v)-f.getcost(u,v)));
                    else
                        r.setcost(u,v,f.getcost(v,u));
                }
            }
        }
    }

    return f;
}
