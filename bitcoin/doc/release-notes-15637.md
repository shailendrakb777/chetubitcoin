RPC changes
-----------
In getmempoolancestors, getmempooldescendants, getmempoolentry and getrawmempool RPCs, to be consistent with the returned value and other RPCs such as getrawtransaction, vsize has been added and size is now deprecated. size will only be returned if h2hcoind is started with `-deprecatedrpc=size`.