let component = ReasonReact.statelessComponent("LoginPage");

module AuthenticateUser = [%graphql
  {|
    mutation AuthenticateUserMutation($facebookToken: String!) {
      authenticateUser(facebookToken: $facebookToken) {
        token
      }
    }
  |}
];

module AuthenticateUserMutation =
  ReasonApollo.CreateMutation(AuthenticateUser);

let handleFacebookDidConnect =
    (
      facebookResponse: FBLogin.facebookResponse,
      authenticateUser: AuthenticateUserMutation.apolloMutation,
    ) => {
  let facebookToken = facebookResponse##authResponse##accessToken;
  let variables = AuthenticateUser.make(~facebookToken, ())##variables;
  Js.Promise.(
    authenticateUser(~variables, ())
    |> then_(response =>
         resolve(
           switch (AuthenticateUserMutation.apolloDataToReason(response)) {
           | Data(data) =>
             Js.log(data##authenticateUser##token);
             Auth.setToken(data##authenticateUser##token);
             Location.reload();
           | _ => Js.log("No data")
           },
         )
       )
    |> ignore
  );
};

module LoginHandler = {
  let component = ReasonReact.statelessComponent("LoginHandler");

  let make = (~authenticateUser, children) => {
    ...component,
    didMount: _self =>
      FBLogin.initialize(
        ~onResponse=
          facebookResponse =>
            if (facebookResponse##status == "connected") {
              handleFacebookDidConnect(facebookResponse, authenticateUser);
            },
        (),
      ),
    render: _self => children |> ReasonReact.array,
  };
};

let token = Auth.getToken();

let make = _children =>
  AuthenticateUserMutation.make((authenticateUser, _) =>
    <div>
      <h2> (ReasonReact.string("Login Page")) </h2>
      <h4>
        (
          ReasonReact.string(
            "Token key: "
            ++ (
              switch (token) {
              | Some(token) => token
              | None => "-"
              }
            ),
          )
        )
      </h4>
      <FBLoginButton />
      <FacebookLoginButtonWrapper />
      <LoggedInUser />
      <LoginHandler authenticateUser />
    </div>
  );

/* let make = _children =>
   AuthenticateUserMutation.make((authenticateUser, _) =>
     <LoginHandler authenticateUser>
       ...<div>
            <h2> (ReasonReact.string("Login Page")) </h2>
            <h4>
              (
                ReasonReact.string(
                  "Token key: "
                  ++ (
                    switch (token) {
                    | Some(token) => token
                    | None => "-"
                    }
                  ),
                )
              )
            </h4>
            <FBLoginButton />
            <FacebookLoginButtonWrapper />
            <LoggedInUser />
          </div>
     </LoginHandler>
   ); */