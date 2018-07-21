open ReasonReact;

let component = statelessComponent("MainNavbar");

let make = (children: array(reactElement)) => {
  ...component,
  render: _self => createDomElement(
    "nav",
    ~props={
      "className": "navbar is-fixed-top",
    },
    children
  ),
};