module AppRouteConfig = {
  type route =
    | Home
    | Login;

  let toUrl = route =>
    switch (route) {
    | Home => "/"
    | Login => "/login"
    };

  let toRoute = (url: ReasonReact.Router.url) =>
    switch (url.path) {
    | ["login"] => Login
    | _ => Home
    };
};

module Router = Router.CreateRouter(AppRouteConfig);

let component = ReasonReact.statelessComponent("AppRouter");

let make = _children => {
  ...component,
  render: _self =>
    <Router>
      ...(
           ({route}) =>
             switch (route) {
             | Login => <LoginPage />
             | _ => ReasonReact.null
             }
         )
    </Router>,
};