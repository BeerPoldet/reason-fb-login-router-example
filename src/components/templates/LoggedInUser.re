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

let component = ReasonReact.statelessComponent("LoggedInUser");

let make = _children => {
  ...component,
  render: _self =>
    <LoggedInUserQuery>
      ...(
           ({result}) =>
             switch (result) {
             | Loading => <h1> (ReasonReact.string("Loading")) </h1>
             | Data(data) =>
               switch (data##loggedInUser) {
               | Some(loggedInUser) =>
                 <h2>
                   (ReasonReact.string("User id " ++ loggedInUser##id))
                 </h2>
               | None => <h2> (ReasonReact.string("Not logged in")) </h2>
               }
             | _ => ReasonReact.null
             }
         )
    </LoggedInUserQuery>,
};