module AppRouteConfig = {
  type route =
    | Main
    | Login;

  let toUrl = route =>
    switch (route) {
    | Main => "/"
    | Login => "/login"
    };

  let toRoute = (url: ReasonReact.Router.url) =>
    switch (url.path) {
    | ["login"] => Login
    | _ => Main
    };
};

module Router = Router.CreateRouter(AppRouteConfig);

let component = ReasonReact.statelessComponent("AppRouter");

let make = _children => {
  ...component,
  render: _self =>
    <WithAuth>
      ...(
           result =>
             switch (result) {
             | Loading => <h1> (ReasonReact.string("Loading")) </h1>
             | _ =>
               <Router
                 watchRoute=(
                   (route, updateRoute) =>
                     switch (result, route) {
                     | (Authorized, Login) => updateRoute(Main)
                     | (Unauthorize, Main) => updateRoute(Login)
                     | _ => ignore()
                     }
                 )>
                 ...(
                      ({route}) =>
                        switch (route) {
                        | Login => <LoginPage />
                        | Main => <MainPage />
                        | _ => ReasonReact.null
                        }
                    )
               </Router>
             }
         )
    </WithAuth>,
};