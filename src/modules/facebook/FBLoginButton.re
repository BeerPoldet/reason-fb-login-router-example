let component = ReasonReact.statelessComponent("FacebookLogin");

let make = _children => {
  ...component,
  render: _self =>
    ReasonReact.cloneElement(
      <div className="fb-login-button" />,
      ~props={
        "data-size": "large",
        "data-max-rows": "1",
        "data-button-type": "continue_with",
        "data-show-faces": "false",
        "data-auto-logout-link": "false",
        "data-use-continue-as": "true",
        "data-scope": "public_profile,email",
      },
      [||],
    ),
};

let jsComponent =
  ReasonReact.wrapReasonForJs(~component, _jsProps => make([||]));