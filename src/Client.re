let inMemoryCache = ApolloInMemoryCache.createInMemoryCache();

let authLink =
  ApolloLinks.apolloLinkSetContext(() => {
    {
      "headers": {
        "Authorization": switch (Auth.getToken()) {
          | Some(token) => Js.Nullable.return("Bearer " ++ token)
          | None => Js.Nullable.undefined
          },
      },
    };
  });

let httpLink =
  ApolloLinks.createHttpLink(
    ~uri="https://api.graph.cool/simple/v1/cjj49ngnd6p8101158g04pk13",
    (),
  );

let instance =
  ReasonApollo.createApolloClient(
    ~link=ApolloLinks.from([|authLink, httpLink|]),
    ~cache=inMemoryCache,
    (),
  );