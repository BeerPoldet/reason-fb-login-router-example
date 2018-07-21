module LoggedInUser = [%graphql
  {|
    query LoggedInUser {
      loggedInUser {
        id
      }
    }
  |}
];

module LoggedInUserQuery = ReasonApollo.CreateQuery(LoggedInUser);

type authResult =
  | Loading
  | Authorized
  | Unauthorize;

let make = children =>
  LoggedInUserQuery.make(({result}) =>
    switch (result) {
    | LoggedInUserQuery.Loading => children(Loading)
    | LoggedInUserQuery.Data(data) =>
      switch (data##loggedInUser) {
      | Some(_) => children(Authorized)
      | None => children(Unauthorize)
      }
    | _ => children(Unauthorize)
    }
  );