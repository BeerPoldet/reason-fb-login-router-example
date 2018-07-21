open MainRouter;
open MainRouterConfig;
open ReasonReact;

let component = statelessComponent("MainPage");

let handleLogout: ReactEventRe.Mouse.t => unit =
  e => {
    ReactEventRe.Mouse.preventDefault(e);
    Auth.removeToken();
    Location.reload();
  };

let make = _children => {
  ...component,
  render: _ =>
    <div>
      <MainNavbar>
        
            <div className="navbar-brand">
              <a className="navbar-item">
                <img src="https://bulma.io/images/bulma-logo.png" alt="Bulma: a modern CSS framework based on Flexbox" width="112" height="28" />
              </a>
            </div>
            <div className="navbar-menu">
              <div className="navbar-start">
                <Link className="navbar-item" route=Home toUrl>
                  (string("Home"))
                </Link>
                <Link className="navbar-item" route=Detail toUrl>
                  (string("Detail"))
                </Link>
                <button className="navbar-item" onClick=handleLogout>
                  (string("Logout"))
                </button>
              </div>
            </div>  
      </MainNavbar>
      <MainRouter />
    </div>,
};