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

  let component = ReasonReact.reducerComponent("Router");

  let make = (children: renderProps => ReasonReact.reactElement) => {
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
    },
    reducer: (action, state) =>
      switch (action) {
      | UpdateRoute(route) => ReasonReact.Update({...state, route})
      },
    render: ({state: {route}, send}) =>
      children({updateRoute: route => send(UpdateRoute(route)), route}),
  };
};