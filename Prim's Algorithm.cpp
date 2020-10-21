vi visited(N,0);
vii mst;
vector<pair<ll,ll> > adj[N];        // value, node
void prim()
{
    priority_queue<pair<ll,pair<ll,ll> >,vector<pair<ll,pair<ll,ll> > >,greater<pair<ll,pair<ll,ll> > > > pq;
    for(ll i=0;i<adj[1].size();i++)
        pq.push(mp(adj[1][i].ff,mp(1,adj[1][i].ss)));
    visited[1]=1;
    while(!pq.empty())
    {
        pair<ll,pair<ll,ll> > edg=pq.top();
        pq.pop();
        if(visited[edg.ss.ff] && visited[edg.ss.ss])
            continue;
        mst.pb(edg.ss);
        if(!visited[edg.ss.ff])
        {
            visited[edg.ss.ff]=1;
            for(ll i=0;i<adj[edg.ss.ff].size();i++)
                pq.push(mp(adj[edg.ss.ff][i].ff,mp(edg.ss.ff,adj[edg.ss.ff][i].ss)));
        }
        if(!visited[edg.ss.ss])
        {
            visited[edg.ss.ss]=1;
            for(ll i=0;i<adj[edg.ss.ss].size();i++)
                pq.push(mp(adj[edg.ss.ss][i].ff,mp(edg.ss.ss,adj[edg.ss.ss][i].ss)));
        }
    }
}
