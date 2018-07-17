export function initializeFB(facebookLoginStatusDidChange) {
  if (window.FB) {
    init(window.FB, facebookLoginStatusDidChange)
    return
  }

  window.fbAsyncInit = function() {
    init(window.FB, facebookLoginStatusDidChange)
  }
  ;(function(d, s, id) {
    var js,
      fjs = d.getElementsByTagName(s)[0]
    if (d.getElementById(id)) {
      return
    }
    js = d.createElement(s)
    js.id = id
    js.src = 'https://connect.facebook.net/en_US/sdk.js'
    fjs.parentNode.insertBefore(js, fjs)
  })(document, 'script', 'facebook-jssdk')
}

let currentAuthSubscribe

function init(fb, facebookLoginStatusDidChange) {
  if (!fb) return
  fb.init({
    appId: '2154178351277379',
    autoLogAppEvents: true,
    xfbml: true,
    version: 'v3.0',
  })

  if (currentAuthSubscribe)
    fb.Event.unsubscribe('auth.authResponseChange', currentAuthSubscribe)

  currentAuthSubscribe = facebookLoginStatusDidChange
  fb.Event.subscribe('auth.authResponseChange', facebookLoginStatusDidChange)
}
