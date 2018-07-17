type facebookResponse = {
  .
  "status": string,
  "authResponse": {
    .
    "accessToken": string,
    "expiresIn": int,
    "userID": string,
    "signedRequest": string,
    "reauthorize_required_in": int,
  },
};
type onLoginStatusResponse = facebookResponse => unit;

[@bs.module "./initializeFB"] [@bs.val]
external initializeFB : (~onResponse: onLoginStatusResponse=?, unit) => unit =
  "";

let initialize = initializeFB;