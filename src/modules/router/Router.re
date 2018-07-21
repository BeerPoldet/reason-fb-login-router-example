open RouteConfig;

module CreateRouter = (RouteConfig: RouteConfig) => {
  type route = RouteConfig.route;
  let toUrl = RouteConfig.toUrl;
  let toRoute = RouteConfig.toRoute;
  type renderProps = {
    updateRoute: route => unit,
    route,
  };
  type state = {route};

  type action =
    | UpdateRoute(route);

  type watchRoute = (route, route => unit) => unit;

  let pushRoute = route => 
    ReasonReact.Router.push(toUrl(route));

  let component = ReasonReact.reducerComponent("Router");

  let make =
      (
        ~watchRoute: option(watchRoute)=?,
        children: renderProps => ReasonReact.reactElement,
      ) => {
    ...component,
    initialState: () => {
      route: toRoute(ReasonReact.Router.dangerouslyGetInitialUrl()),
    },
    didMount: self => {
      let watchId =
        ReasonReact.Router.watchUrl(url =>
          self.send(UpdateRoute(toRoute(url)))
        );
      self.onUnmount(() => ReasonReact.Router.unwatchUrl(watchId));

      switch (watchRoute) {
      | Some(watchRoute) => watchRoute(self.state.route, pushRoute)
      | None => ignore()
      };
    },
    reducer: (action, state) =>
      switch (action) {
      | UpdateRoute(route) =>
        ReasonReact.UpdateWithSideEffects(
          {...state, route},
          (
            self =>
              switch (watchRoute) {
              | Some(watchRoute) =>
                watchRoute(
                  route,
                  route => {
                    Js.log(toUrl(route));
                    ReasonReact.Router.push(toUrl(route));
                  },
                )
              | None => ignore()
              }
          ),
        )
      },
    render: ({state: {route}, send}) =>
      children({updateRoute: route => send(UpdateRoute(route)), route}),
  };
};