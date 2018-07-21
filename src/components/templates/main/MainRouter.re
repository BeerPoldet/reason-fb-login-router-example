module MainRouterConfig = {
  type route =
    | Home
    | Detail;
  
  let toUrl = route => {
    switch (route) {
    | Home => "/"
    | Detail => "/detail"
    }
  };

  let toRoute = (url: ReasonReact.Router.url) => {
    switch (url.path) {
    | ["detail"] => Detail
    | _ => Home
    }
  };
}

module Router = Router.CreateRouter(MainRouterConfig);

let component = ReasonReact.statelessComponent("MainRouter");

let make = _children => {
  ...component,
  render: _self => <Router>
    ...(({ route }) => {
      switch(route) {
      | Home => <h1> (ReasonReact.string("Home")) </h1>
      | Detail => <h1> (ReasonReact.string("Detail")) </h1>
      }
    })
  </Router>
};