module A = {
  let component = ReasonReact.statelessComponent("A");
  let make = (~href, ~onClick, children) => {
    ...component,
    render: _self =>
      ReasonReact.createDomElement(
        "a",
        ~props={"href": href, "onClick": onClick},
        children,
      ),
  };
};

let component = ReasonReact.statelessComponent("Link");

let createOnClick = (href, e) => {
  ReactEventRe.Mouse.preventDefault(e);
  ReasonReact.Router.push(href);
};

let make = (~route, ~toUrl, children) => {
  ...component,
  render: _self => {
    let href = toUrl(route);
    let onClick = createOnClick(href);

    <A href onClick> ...children </A>;
  },
};