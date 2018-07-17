import React from 'react'

class FacebookLoginButton extends React.Component {
  // componentDidMount() {
  //   if (window.FB && window.FB.init)
  //     window.FB.init({
  //       appId: '361542997591314',
  //       cookie: true,
  //       xfbml: true,
  //       version: 'v2.11',
  //     })
  // }

  render() {
    return (
      <div
        className="fb-login-button"
        data-max-rows="1"
        data-size="large"
        data-button-type="continue_with"
        data-show-faces="false"
        data-auto-logout-link="false"
        data-use-continue-as="true"
        data-scope="public_profile,email"
      />
    )
  }
}

export default FacebookLoginButton
