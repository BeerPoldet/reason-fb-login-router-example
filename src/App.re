open AppRouter;
open AppRouteConfig;

[%bs.raw {|require('./App.css')|}];

[@bs.module] external logo : string = "./logo.svg";

let component = ReasonReact.statelessComponent("App");

let make = (~message, _children) => {
  ...component,
  render: _self =>
    <div className="App">
      <div className="App-header">
        <img src=logo className="App-logo" alt="logo" />
        <h2> (ReasonReact.string(message)) </h2>
      </div>
      <p className="App-intro">
        (ReasonReact.string("To get started, edit"))
        <code> (ReasonReact.string(" src/App.re ")) </code>
        (ReasonReact.string("and save to reload."))
      </p>
      <div>
        <Link route=Home toUrl>
          <h4> (ReasonReact.string("Home")) </h4>
        </Link>
        <Link route=Login toUrl>
          <h4> (ReasonReact.string("Login")) </h4>
        </Link>
      </div>
      <AppRouter />
    </div>,
};