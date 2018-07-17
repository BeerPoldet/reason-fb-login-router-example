module type RouteConfig = {
  type route;

  let toUrl: route => string;

  let toRoute: ReasonReact.Router.url => route;
};