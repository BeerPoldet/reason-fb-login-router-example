[@bs.module "./FacebookLoginButton"]
external facebookLoginButton : ReasonReact.reactClass = "default";

[@bs.deriving abstract]
type jsProps = {onClick: Js.nullable(ReactEventRe.Mouse.t => unit)};

let make = (~onClick=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=facebookLoginButton,
    ~props=jsProps(~onClick=Js.Nullable.fromOption(onClick)),
    children,
  );