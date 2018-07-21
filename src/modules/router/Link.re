module A = {
  let component = ReasonReact.statelessComponent("A");
  let make = (~href, ~onClick, ~className=?, children) => {
    ...component,
    render: _self =>
      ReasonReact.createDomElement(
        "a",
        ~props={
          "href": href, 
          "onClick": onClick, 
          "className": Js.Nullable.fromOption(className)
        },
        children,
      ),
  };
};

let component = ReasonReact.statelessComponent("Link");

let createOnClick: (string, ReactEventRe.Mouse.t) => unit = (href, e) => {
  ReactEventRe.Mouse.preventDefault(e);
  ReasonReact.Router.push(href);
};

let make = (~route, ~toUrl, ~className=?, children) => {
  ...component,
  render: _self => {
    let href = toUrl(route);
    <A href onClick=createOnClick(href) className> ...children </A>;
  },
};