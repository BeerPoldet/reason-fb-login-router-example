let tokenKey = "beru-moment-token";

let getToken = () => LocalStorage.getItem(~key=tokenKey);

let setToken = (token) => LocalStorage.setItem(~key=tokenKey, ~value=token);

let removeToken: unit => unit = () => LocalStorage.removeItem(~key=tokenKey);