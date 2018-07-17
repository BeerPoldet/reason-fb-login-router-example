let component = ReasonReact.statelessComponent("LoginPage");

let handleFacebookDidConnect = (facebookResponse: FBLogin.facebookResponse) => {
  /* const facebookToken = facebookResponse.authResponse.accessToken
     const graphcoolResponse = await this.props.authenticateUserMutation({
       variables: { facebookToken },
     }) */

  let facebookToken = facebookResponse##authResponse##accessToken;
  Js.log(facebookToken);
};

let make = _children => {
  ...component,
  didMount: _self =>
    FBLogin.initialize(
      ~onResponse=
        facebookResponse => {
          Js.log(facebookResponse);
          handleFacebookDidConnect(facebookResponse);
        },
      (),
    ),
  render: _self =>
    <div>
      <h2> (ReasonReact.string("Login Page")) </h2>
      <FBLoginButton />
      <FacebookLoginButtonWrapper />
    </div>,
};